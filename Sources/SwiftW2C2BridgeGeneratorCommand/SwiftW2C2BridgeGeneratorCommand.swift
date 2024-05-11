import ArgumentParser
import Foundation
import W2C2BridgeGenerator
import BridgeSupportParser
import SystemPackage

private let indent = "    "
private let generatedDirectoryName = "generated"

@main
struct SwiftW2C2BridgeGeneratorCommand: ParsableCommand {
    static var configuration = CommandConfiguration(
        commandName: "swift-w2c2-bridge-gen",
        abstract: "Generate Swift bindings for w2c2 from framework bridgesupport files"
    )

    @ArgumentParser.Option(
        help: "WebAssembly module name"
    )
    var webAssemblyModuleName: String = "env"

    @ArgumentParser.Option(
        help: "Swift module name"
    )
    var swiftModuleName: String

    @ArgumentParser.Option(
        name: .customLong("output-directory"),
        help: "generate Swift module in output directory",
        completion: .directory,
        transform: { FilePath($0) }
    )
    var outputDirectory: FilePath

    @ArgumentParser.Option(
        name: .customLong("frameworks-directory"),
        help: "frameworks directory",
        completion: .directory,
        transform: { FilePath($0) }
    )
    var frameworksDirectory: FilePath

    @ArgumentParser.Flag(
        name: .customLong("comments"),
        inversion: .prefixedNo,
        help: "generate comments"
    )
    var generateComments: Bool = false

    @ArgumentParser.Flag(
        name: .customLong("symbols-file"),
        inversion: .prefixedNo,
        help: "generate symbols file"
    )
    var generateSymbolsFile: Bool = true

    @ArgumentParser.Flag(
        name: .customLong("big-endian"),
        inversion: .prefixedNo,
        help: "generate implementation for big-endian system"
    )
    var generateBigEndian: Bool = false

    @ArgumentParser.Argument(
        help: "only generate bindings for frameworks with these names"
    )
    var names: [String] = []

    func createFile(_ filePath: FilePath) throws -> FileDescriptor {
        try FileDescriptor.open(
            filePath,
            .writeOnly,
            options: [.create, .truncate],
            permissions: .ownerReadWrite
        )
    }

    private func parseFrameworks(inDirectory frameworksDirectory: FilePath) throws -> [Framework] {
        let frameworkNames = (try? FileManager.default.contentsOfDirectory(atPath: frameworksDirectory.string)) ?? []

        return try frameworkNames.compactMap { frameworkName in
            let frameworkStem = FilePath.Component(frameworkName)?.stem ?? ""

            var frameworkDirectory = frameworksDirectory
            frameworkDirectory.append(frameworkName)

            var versionsDirectory = frameworkDirectory
            versionsDirectory.append("Versions")

            guard let versions = try? FileManager.default.contentsOfDirectory(atPath: versionsDirectory.string) else {
                fatalError("cannot enumerate versions directory: \(versionsDirectory)")
            }

            guard let version = versions.first else {
                fatalError("framework \(frameworkName) has no versions")
            }

            guard versions.count == 1 else {
                fatalError("framework \(frameworkName) has multiple versions")
            }

            var versionDirectory = versionsDirectory
            versionDirectory.append(version)

            var bridgesupportPath = versionDirectory
            bridgesupportPath.append(["Resources", "BridgeSupport"])

            var bridgesupportName = frameworkStem
            bridgesupportName.append(".bridgesupport")

            bridgesupportPath.append(bridgesupportName)


            let file: BridgeSupportParser.File
            if names.isEmpty || names.contains(frameworkStem) {

                print("Parsing bridgesupport file for framework \(frameworkStem) ...")

                let parser = Parser(contentsOf: URL(fileURLWithPath: bridgesupportPath.string))!
                file = try parser.parse()

            } else {
                file = BridgeSupportParser.File()
            }

            var subframeworksDirectory = versionDirectory
            subframeworksDirectory.append("Frameworks")

            let subframeworks = try parseFrameworks(inDirectory: subframeworksDirectory)

            return Framework(
                name: frameworkStem,
                file: file,
                subframeworks: subframeworks
            )
        }
    }

    func writeModulemapFile(frameworks: [Framework], directory: FilePath) throws {
        print("Writing modulemap file ...")

        var modulemapPath = directory
        modulemapPath.append("module.modulemap")

        var modulemapFile = try createFile(modulemapPath)
        defer {
            try! modulemapFile.close()
        }
        modulemapFile.write("module \(swiftModuleName) {\n")
        writeFrameworkModules(
            modulemapFile: &modulemapFile,
            frameworks: frameworks,
            level: 1
        )
        modulemapFile.write("}\n")
    }

    func writeFrameworkModules(
        modulemapFile: inout FileDescriptor,
        frameworks: [Framework],
        level: Int
    ) {
        let currentIndent = String(repeating: indent, count: level)
        for framework in frameworks {
            modulemapFile.write("""
            \(currentIndent)module \(framework.name) {
            \(currentIndent)\(indent)header "\(framework.name).h"
            \(currentIndent)\(indent)export *

            """)
            writeFrameworkModules(
                modulemapFile: &modulemapFile,
                frameworks: framework.subframeworks,
                level: level + 1
            )
            modulemapFile.write("\(currentIndent)}\n")
        }
    }

    func generateHeader(framework: Framework, inDirectory directory: FilePath) throws {
        var headerPath = directory
        headerPath.append("\(framework.name).h")

        // Skip generating the header file if it already exists.
        // This allows extending the default header file with additional content,
        // after the initial generation.

        guard !FileManager.default.fileExists(atPath: headerPath.string) else {
            return
        }

        print("Generating header \(headerPath) ...")

        var headerFile = try createFile(headerPath)
        defer {
            try! headerFile.close()
        }

        headerFile.write("""
            #include "\(generatedDirectoryName)/\(framework.name).h"

            """)

        for subframework in framework.subframeworks {
            try generateHeader(
                framework: subframework,
                inDirectory: directory
            )
        }
    }

    func generateCInterfaceFile(framework: Framework, inDirectory directory: FilePath) throws {
        var cInterfacePath = directory
        cInterfacePath.append("\(framework.name).h")

        var symbolsOutputPath = directory
        symbolsOutputPath.append("\(framework.name).symbols")

        let symbolsOutput = generateSymbolsFile
            ? try createFile(symbolsOutputPath)
            : nil
        defer {
            try! symbolsOutput?.close()
        }

        let messageSuffix = generateSymbolsFile ? " and symbols file \(symbolsOutputPath)" : ""
        print("Generating C interface \(cInterfacePath)\(messageSuffix) ...")

        let cInterfaceFile = try createFile(cInterfacePath)
        defer {
            try! cInterfaceFile.close()
        }

        var cInterfaceGenerator = CInterfaceGenerator(
            headerOutput: cInterfaceFile,
            symbolsOutput: symbolsOutput,
            generateComments: generateComments,
            generateBigEndian: generateBigEndian
        )
        cInterfaceGenerator.generate(definitions: framework.file.definitions)

        for subframework in framework.subframeworks {
            try generateCInterfaceFile(
                framework: subframework,
                inDirectory: directory
            )
        }
    }

    mutating func run() throws {
        let frameworks = try parseFrameworks(inDirectory: frameworksDirectory)

        var cInterfaceDirectory = outputDirectory
        cInterfaceDirectory.append(generatedDirectoryName)

        try FileManager.default.createDirectory(
            atPath: cInterfaceDirectory.string,
            withIntermediateDirectories: true
        )

        try writeModulemapFile(
            frameworks: frameworks,
            directory: outputDirectory
        )

        for framework in frameworks {
            try generateHeader(
                framework: framework,
                inDirectory: outputDirectory
            )
        }

        for framework in frameworks {
            try generateCInterfaceFile(
                framework: framework,
                inDirectory: cInterfaceDirectory
            )
        }
    }
}
