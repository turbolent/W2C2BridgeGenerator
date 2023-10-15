import CWriter
import BridgeSupportParser
import SystemPackage

extension Definition {
    var label: String {
        Mirror(reflecting: self).children.first!.label!
    }
}

extension FileDescriptor: TextOutputStream {
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
            guard let fieldType32 = field.type32 else {
                continue
            }
            if case let .Struct(structType) = fieldType32 {
                result.append(structType.name)
                structType.bestEffortStructDependencies32(result: &result)
            }
        }
    }
}

extension ReturnValue: CustomStringConvertible {

    public var description: String {
        var result = ""
        if let declaredType {
            result.append(declaredType)
            if let typeDeclaration = type32?.typeDeclaration {
                var subResult = ""
                typeDeclaration.write(identifier: nil, to: &subResult)
                if subResult != declaredType {
                    result.append(" (\(subResult))")
                }
            }
        } else if let typeDeclaration = type32?.typeDeclaration {
            typeDeclaration.write(identifier: nil, to: &result)
        } else {
            return "missing type"
        }
        return result
    }
}

extension Argument: CustomStringConvertible {

    public var description: String {
        var result = ""
        if let declaredType {
            result.append(declaredType)
            if let typeDeclaration = type32?.typeDeclaration {
                var subResult = ""
                typeDeclaration.write(identifier: nil, to: &subResult)
                if subResult != declaredType {
                    result.append(" (\(subResult))")
                }
            }
        } else if let typeDeclaration = type32?.typeDeclaration {
            typeDeclaration.write(identifier: nil, to: &result)
        } else {
            return "missing type"
        }
        return result
    }
}
