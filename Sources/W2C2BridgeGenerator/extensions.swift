import CWriter
import BridgeSupportParser
import SystemPackage

extension Definition {
    var label: String {
        Mirror(reflecting: self).children.first!.label!
    }
}

extension FileDescriptor: @retroactive TextOutputStream {
    public mutating func write(_ string: String) {
        try! writeAll(string.utf8)
    }
}

extension CWriter.`Type` {

    static let U32 = Self(name: "U32")
    static let U64 = Self(name: "U64")
    static let F32 = Self(name: "F32")
    static let F64 = Self(name: "F64")
}

extension StructType {

    func bestEffortStructDependencies32(result: inout [String]) {
        for field in fields {
            guard var fieldType32 = field.type32 else {
                continue
            }

            // TODO: handle unions and functions

            loop:
            while true {
                switch fieldType32 {
                case .Pointer(let innerType):
                    fieldType32 = innerType
                case .Array(let arrayType):
                    fieldType32 = arrayType.type
                default:
                    break loop
                }
            }

            if case let .Struct(structType) = fieldType32 {
                result.append(structType.name)
                structType.bestEffortStructDependencies32(result: &result)
            }
        }
    }
}

extension ReturnValue: @retroactive CustomStringConvertible {

    public var description: String {
        var result = ""
        if let declaredType {
            result.append(declaredType)
            if let typeDeclaration = type32?.typeDeclaration(isConst: isConst) {
                var subResult = ""
                typeDeclaration.write(identifier: nil, to: &subResult)
                if subResult != declaredType {
                    result.append(" (\(subResult))")
                }
            }
        } else if let typeDeclaration = type32?.typeDeclaration(isConst: isConst) {
            typeDeclaration.write(identifier: nil, to: &result)
        } else {
            return "missing type"
        }
        return result
    }
}

extension Argument: @retroactive CustomStringConvertible {

    public var description: String {
        var result = ""
        if let declaredType {
            result.append(declaredType)
            if let typeDeclaration = type32?.typeDeclaration(isConst: isConst) {
                var subResult = ""
                typeDeclaration.write(identifier: nil, to: &subResult)
                if subResult != declaredType {
                    result.append(" (\(subResult))")
                }
            }
        } else if let typeDeclaration = type32?.typeDeclaration(isConst: isConst) {
            typeDeclaration.write(identifier: nil, to: &result)
        } else {
            return "missing type"
        }
        return result
    }
}
