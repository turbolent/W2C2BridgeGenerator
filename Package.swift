// swift-tools-version: 5.5

import PackageDescription

let package = Package(
    name: "W2C2BridgeGenerator",
    dependencies: [
        .package(url: "https://github.com/apple/swift-argument-parser.git", from: "1.2.0"),
        .package(url: "https://github.com/apple/swift-system", from: "1.2.0"),
        .package(url: "https://github.com/turbolent/BridgeSupportParser.git", branch: "main"),
        .package(url: "https://github.com/turbolent/CWriter.git", branch: "main"),
        .package(url: "https://github.com/krzysztofzablocki/Difference.git", branch: "master")
    ],
    targets: [
        .target(
           name: "W2C2BridgeGenerator",
           dependencies: [
                "BridgeSupportParser",
                "CWriter",
                "Difference"
           ]
        ),
        .executableTarget(
            name: "W2C2BridgeGeneratorCommand",
            dependencies: [
                .product(name: "ArgumentParser", package: "swift-argument-parser"),
                .product(name: "SystemPackage", package: "swift-system"),
                "W2C2BridgeGenerator"
            ]
        )
    ]
)
