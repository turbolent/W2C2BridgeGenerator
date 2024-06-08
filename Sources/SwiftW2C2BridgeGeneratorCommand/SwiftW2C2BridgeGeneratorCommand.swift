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
        name: .customLong("swift-module-directory"),
        help: "generate Swift module in directory",
        completion: .directory,
        transform: { FilePath($0) }
    )
    var swiftModuleDirectory: FilePath

    @ArgumentParser.Option(
        name: .customLong("w2c2-implementation-directory"),
        help: "generate w2c2 implementation in directory",
        completion: .directory,
        transform: { FilePath($0) }
    )
    var w2c2ImplementationDirectory: FilePath

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

    @ArgumentParser.Option(
        name: .customLong("exclude"),
        help: "do not generate bindings for frameworks with these names"
    )
    var exclude: [String] = []

    @ArgumentParser.Argument(
        help: "only generate bindings for frameworks with these names"
    )
    var names: [String] = []

    lazy var excludeSet = Set(exclude)
    lazy var namesSet = Set(names)

    func createFile(_ filePath: FilePath) throws -> FileDescriptor {
        try FileDescriptor.open(
            filePath,
            .writeOnly,
            options: [.create, .truncate],
            permissions: .ownerReadWrite
        )
    }

    private mutating func parseFrameworks(inDirectory frameworksDirectory: FilePath) throws -> [Framework] {
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
            if (names.isEmpty || namesSet.contains(frameworkStem))
                && !excludeSet.contains(frameworkStem)
            {
                print("Parsing bridgesupport file for framework \(frameworkStem) ...")

                let parser = Parser(contentsOf: URL(fileURLWithPath: bridgesupportPath.string))!
                file = try parser.parse()

            } else {
                print("Skipping bridgesupport file for framework \(frameworkStem)")

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

    func writeModulemap(frameworks: [Framework], directory: FilePath) throws {
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

    func generateHeader(for framework: Framework, inDirectory directory: FilePath) throws {
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
                for: subframework,
                inDirectory: directory
            )
        }
    }

    func generateCInterface(
        for framework: Framework,
        inDirectory directory: FilePath,
        gatheringStructs structs: inout [Struct]
    ) throws {
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

        let definitions = framework.file.definitions
        cInterfaceGenerator.generate(definitions: definitions)

        for definition in definitions {
            if case let .Struct(`struct`) = definition {
                structs.append(`struct`)
            }
        }

        for subframework in framework.subframeworks {
            try generateCInterface(
                for: subframework,
                inDirectory: directory,
                gatheringStructs: &structs
            )
        }
    }

    func generateImplementation(for framework: Framework, inDirectory directory: FilePath) throws {
        let filename = "\(framework.name).m"

        var implementationPath = directory
        implementationPath.append(filename)

        // Skip generating the implementation file if it already exists.
        // This allows extending the default implementation file with additional content,
        // after the initial generation.

        guard !FileManager.default.fileExists(atPath: implementationPath.string) else {
            return
        }

        print("Generating implementation \(implementationPath) ...")

        var implementationFile = try createFile(implementationPath)
        defer {
            try! implementationFile.close()
        }

        implementationFile.write("""
            #include "\(generatedDirectoryName)/\(filename)"

            """)

        for subframework in framework.subframeworks {
            try generateImplementation(
                for: subframework,
                inDirectory: directory
            )
        }
    }

    func generateW2C2Implementation(
        for framework: Framework,
        inDirectory directory: FilePath,
        structs: [Struct]
    ) throws {
        let filename = "\(framework.name).m"

        var implementationPath = directory
        implementationPath.append(filename)

        print("Generating implementation \(implementationPath) ...")

        let w2c2ImplementationFile = try createFile(implementationPath)
        defer {
            try! w2c2ImplementationFile.close()
        }

        var w2c2ImplementationGenerator = W2C2ImplementationGenerator(
            output: w2c2ImplementationFile,
            moduleName: webAssemblyModuleName,
            generateComments: generateComments,
            generateBigEndian: generateBigEndian,
            structs: structs
        )
        w2c2ImplementationGenerator.generate(definitions: framework.file.definitions)

        for subframework in framework.subframeworks {
            try generateW2C2Implementation(
                for: subframework,
                inDirectory: directory,
                structs: structs
            )
        }
    }

    func generateSymbolsFile(inDirectory directory: FilePath) throws {
        var symbolsOutputPath = directory
        symbolsOutputPath.append("symbols")

        print("Generating symbols file \(symbolsOutputPath) ...")

        let symbolsOutput = try createFile(symbolsOutputPath)
        defer {
            try! symbolsOutput.close()
        }

        let files = try FileManager.default.contentsOfDirectory(atPath: directory.string)
        for symbolsFile in files.filter({ $0.hasSuffix(".symbols") }) {
            let symbolsFilePath = directory.appending(symbolsFile)

            if let data = FileManager.default.contents(atPath: symbolsFilePath.string) {
                _ =  try data.withUnsafeBytes {
                    try symbolsOutput.write($0)
                }
            }
        }
    }

    mutating func run() throws {
        let frameworks = try parseFrameworks(inDirectory: frameworksDirectory)

        var cInterfaceDirectory = swiftModuleDirectory
        cInterfaceDirectory.append(generatedDirectoryName)

        var innerW2c2ImplementationDirectory = w2c2ImplementationDirectory
        innerW2c2ImplementationDirectory.append(generatedDirectoryName)

        for directory in [
            swiftModuleDirectory,
            cInterfaceDirectory,
            w2c2ImplementationDirectory,
            innerW2c2ImplementationDirectory
        ] {
            try FileManager.default.createDirectory(
                atPath: directory.string,
                withIntermediateDirectories: true
            )
        }

        try writeModulemap(
            frameworks: frameworks,
            directory: swiftModuleDirectory
        )

        // Generate headers and C interfaces for all frameworks,
        // gathering all structs.

        var structs: [Struct] = []

        for framework in frameworks {
            try generateHeader(
                for: framework,
                inDirectory: swiftModuleDirectory
            )

            try generateCInterface(
                for: framework,
                inDirectory: cInterfaceDirectory,
                gatheringStructs: &structs
            )
        }

        if generateSymbolsFile {
            try generateSymbolsFile(inDirectory: cInterfaceDirectory)
        }

        // Generate implementation files and w2c2 implementations for all frameworks,
        // using the gathered structs.

        for framework in frameworks {
            try generateImplementation(
                for: framework,
                inDirectory: w2c2ImplementationDirectory
            )

            try generateW2C2Implementation(
                for: framework,
                inDirectory: innerW2c2ImplementationDirectory,
                structs: structs
            )
        }
    }
}
