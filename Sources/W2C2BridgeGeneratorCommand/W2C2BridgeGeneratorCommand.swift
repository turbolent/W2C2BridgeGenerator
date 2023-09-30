import ArgumentParser
import Foundation
import W2C2BridgeGenerator
import BridgeSupportParser
import SystemPackage

@main
struct W2C2BridgeGeneratorCommand: ParsableCommand {
    static var configuration = CommandConfiguration(
        commandName: "w2c2-bridge-gen",
        abstract: "Generate bindings for w2c2 from a bridgesupport file"
    )

    @ArgumentParser.Option(
        help: "module name"
    )
    var moduleName: String = "env"

    @ArgumentParser.Option(
        name: [.customLong("w2c2-implementation")],
        help: "generate w2c2 implementation file (C/Objective-C)",
        completion: .file(),
        transform: { FilePath($0) }
    )
    var w2c2ImplementationFile: FilePath?

    @ArgumentParser.Option(
        name: .customLong("c-interface"),
        help: "generate C interface file (header)",
        completion: .file(),
        transform: { FilePath($0) }
    )
    var cInterfaceFile: FilePath?

    @ArgumentParser.Argument(
        help: "bridgesupport files",
        completion: .file(extensions: ["bridgesupport"]),
        transform: URL.init(fileURLWithPath:)
    )
    var inputFiles: [URL]

    @ArgumentParser.Flag(
        name: .customLong("comments"),
        inversion: .prefixedNo,
        help: "generate comments"
    )
    var generateComments: Bool = false

    func createFile(_ filePath: FilePath) throws -> FileDescriptor {
        try FileDescriptor.open(
            filePath,
            .writeOnly,
            options: [.create, .truncate],
            permissions: .ownerReadWrite
        )
    }

    mutating func run() throws {
        // Parse all input files
        var definitions: [Definition] = []
        for inputFile in inputFiles {
            print("Parsing \(inputFile.path)")

            let parser = Parser(contentsOf: inputFile)!
            let file = try parser.parse()
            definitions.append(contentsOf: file.definitions)
        }

        // Generate W2C2 implementations for all definitions

        if let w2c2ImplementationFile {
            let w2c2ImplementationFile = try createFile(w2c2ImplementationFile)
            defer {
                try! w2c2ImplementationFile.close()
            }

            var w2c2ImplementationGenerator = W2C2ImplementationGenerator(
                output: w2c2ImplementationFile,
                moduleName: moduleName,
                generateComments: generateComments
            )
            w2c2ImplementationGenerator.generate(definitions: definitions)
        }

        // Generate C interface for all definitions

        if let cInterfaceFile {
            let cInterfaceFile = try createFile(cInterfaceFile)
            defer {
                try! cInterfaceFile.close()
            }

            var cInterfaceGenerator = CInterfaceGenerator(
                output: cInterfaceFile,
                generateComments: generateComments
            )
            cInterfaceGenerator.generate(definitions: definitions)
        }
    }
}
