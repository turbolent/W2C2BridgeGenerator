import BridgeSupportParser

public struct Framework {
    public let name: String
    public let file: File
    public let subframeworks: [Framework]

    public init(name: String, file: File, subframeworks: [Framework]) {
        self.name = name
        self.file = file
        self.subframeworks = subframeworks
    }
}