import BridgeSupportParser
import CWriter

public enum UnbridgeableError: Swift.Error {
    case UnsupportedType(BridgeSupportParser.`Type`)
    case UnsupportedDeclaredType(String)
    case MissingType32InField(BridgeSupportParser.Field)
    case MissingType32InReturnValue(BridgeSupportParser.ReturnValue)
    case MissingType32InArgument(BridgeSupportParser.Argument)
}

public func checkBridgeable(
    type: BridgeSupportParser.`Type`,
    generateBigEndian: Bool
) throws {
    switch type {
        case .Pointer(let type):
            try checkBridgeable(
                type: type,
                generateBigEndian: generateBigEndian
            )

        case .FunctionType, .Unknown:
            throw UnbridgeableError.UnsupportedType(type)

        case .ComplexFloat, .ComplexDouble:
            // TODO:
            throw UnbridgeableError.UnsupportedType(type)

        case .Char, .Int, .Short, .Long, .LongLong,
            .UnsignedChar, .UnsignedInt, .UnsignedShort, .UnsignedLong, .UnsignedLongLong,
            .Float, .Double,
            .Bool, .Void,
            .ID, .Class, .Selector:

            break

        case .Bitfield:
            // TODO: add support in convertBigEndian
            guard !generateBigEndian else {
                throw UnbridgeableError.UnsupportedType(type)
            }

        case .Array(let arrayType):
            // TODO: add support in convertBigEndian
            guard !generateBigEndian else {
                throw UnbridgeableError.UnsupportedType(type)
            }

            try checkBridgeable(
                type: arrayType.type,
                generateBigEndian: generateBigEndian
            )

        case .Struct(let structType):
            try checkBridgeable(
                structType: structType,
                generateBigEndian: generateBigEndian
            )

        case .Union(let unionType):
            try checkBridgeable(
                unionType: unionType,
                generateBigEndian: generateBigEndian
            )

        case .Const(let type):
            try checkBridgeable(
                type: type,
                generateBigEndian: generateBigEndian
            )
    }
}

public func checkBridgeable(
    field: BridgeSupportParser.Field,
    generateBigEndian: Bool
) throws {

    guard let type32 = field.type32 else {
        throw UnbridgeableError.MissingType32InField(field)
    }

    try checkBridgeable(
        type: type32,
        generateBigEndian: generateBigEndian
    )
}

public func checkBridgeable(
    structType: StructType,
    generateBigEndian: Bool
) throws {
    for field in structType.fields {
        try checkBridgeable(
            field: field,
            generateBigEndian: generateBigEndian
        )
    }
}

public func checkBridgeable(
    unionType: UnionType,
    generateBigEndian: Bool
) throws {
    // TODO: add support in convertBigEndian
    guard !generateBigEndian else {
        throw UnbridgeableError.UnsupportedType(.Union(unionType))
    }

    for field in unionType.fields {
        try checkBridgeable(
            field: field,
            generateBigEndian: generateBigEndian
        )
    }
}

public func checkBridgeable(
    returnValue: ReturnValue,
    generateBigEndian: Bool
) throws {
    guard let type32 = returnValue.type32 else {
        throw UnbridgeableError.MissingType32InReturnValue(returnValue)
    }
    try checkBridgeable(
        type: type32,
        generateBigEndian: generateBigEndian
    )
}

public func checkBridgeable(
    argument: Argument,
    generateBigEndian: Bool
) throws {
    guard let type32 = argument.type32 else {
        throw UnbridgeableError.MissingType32InArgument(argument)
    }
    try checkBridgeable(
        type: type32,
        generateBigEndian: generateBigEndian
    )
}

func checkBridgeable(
    functionType: FunctionType,
    generateBigEndian: Bool
) throws {

    // Ensure return value is bridgeable

    if let returnValue = functionType.returnValue {
        try checkBridgeable(
            returnValue: returnValue,
            generateBigEndian: generateBigEndian
        )
    }

    // Ensure all arguments are bridgeable

    for argument in functionType.arguments {

        try checkBridgeable(
            argument: argument,
            generateBigEndian: generateBigEndian
        )

        // TODO: https://github.com/apple/swift/issues/72398
        if argument.declaredType == "va_list" {
            throw UnbridgeableError.UnsupportedDeclaredType("va_list")
        }
    }
}

enum FunctionKind: CustomStringConvertible, Hashable {
    case Function(name: String)
    case Method(
        className: String,
        selector: String,
        isClassMethod: Bool
    )
    case ConstantGetter(name: String)
    case ConstantSetter(name: String)

    var description: String {
        switch self {
            case let .Function(name):
                return "function '\(name)'"
            case let .Method(
                className: className,
                selector: selector,
                isClassMethod: isClassMethod
            ):
                return "method '\(isClassMethod ? "+" : "-")[\(className) \(selector)]'"
            case let .ConstantGetter(name):
                return "getter for constant '\(name)'"
            case let .ConstantSetter(name):
                return "setter for constant '\(name)'"
        }
    }
}

public func methodFunctionName(forClassName className: String, selector: String, isClassMethod: Bool) -> String {
    let prefix = isClassMethod ? "C" : "I"
    let className = className
        .replacingOccurrences(of: "_", with: "__")
    let selector = selector
        .replacingOccurrences(of: "_", with: "__")
        .replacingOccurrences(of: ":", with: "_C")
    return "_\(prefix)M_\(className)_\(selector)"
}

public func getterFunctionName(forConstantName constantName: String) -> String {
    return "_get_\(constantName)"
}

public func setterFunctionName(forConstantName constantName: String) -> String {
    return "_set_\(constantName)"
}


public func constantGetterFunctionType(_ constant: Constant) -> FunctionType {
    return FunctionType(
        returnValue: ReturnValue(
            type32: constant.type32,
            type64: constant.type64,
            declaredType: constant.declaredType
        )
    )
}

public func constantSetterFunctionType(_ constant: Constant) -> FunctionType {
    return FunctionType(
        arguments: [
            Argument(
                name: "value",
                type32: constant.type32,
                type64: constant.type64,
                declaredType: constant.declaredType
            )
        ]
    )
}

extension TypeDeclaration.TypeSpecifier {
    fileprivate static let empty = Self.Name("")
}

extension TypeDeclaration {

    fileprivate mutating func build(name: String, isConst: Bool) throws {
        guard typeSpecifier == .empty else {
            throw TypeDeclarationError.InvalidState
        }
        typeSpecifier = .Name(name)

        if isConst {
            guard typeQualifers.isEmpty else {
                throw TypeDeclarationError.InvalidState
            }
            typeQualifers.append(.Const)
        }
    }

    fileprivate mutating func build(struct: String) throws {
        guard typeSpecifier == .empty else {
            throw TypeDeclarationError.InvalidState
        }
        typeSpecifier = .Struct(`struct`)
    }
}

enum TypeDeclarationError: Swift.Error {
    case InvalidState
    case UnsupportedType(BridgeSupportParser.`Type`)
    case MissingStructName(StructType)
}

extension BridgeSupportParser.`Type` {

    func typeDeclaration(isConst: Bool) -> TypeDeclaration? {
        do {
            var result = TypeDeclaration(typeSpecifier: .empty)
            try buildTypeDeclaration(result: &result, isConst: isConst)
            return result
        } catch {
            // TODO: return error
            return nil
        }
    }

    private func buildTypeDeclaration(result: inout TypeDeclaration, isConst: Bool) throws {
        switch self {
            // Signed
            case .Char:
                try result.build(name: "char", isConst: isConst)
            case .Int:
                try result.build(name: "int", isConst: isConst)
            case .Short:
                try result.build(name: "short", isConst: isConst)
            case .Long:
                try result.build(name: "long", isConst: isConst)
            case .LongLong:
                try result.build(name: "long long", isConst: isConst)

            // Unsigned
            case .UnsignedChar:
                try result.build(name: "unsigned char", isConst: isConst)
            case .UnsignedInt:
                try result.build(name: "unsigned int", isConst: isConst)
            case .UnsignedShort:
                try result.build(name: "unsigned short", isConst: isConst)
            case .UnsignedLong:
                try result.build(name: "unsigned long", isConst: isConst)
            case .UnsignedLongLong:
                try result.build(name: "unsigned long long", isConst: isConst)

            // Floating point
            case .Float:
                try result.build(name: "float", isConst: isConst)
            case .Double:
                try result.build(name: "double", isConst: isConst)

            // Other
            case .Bool:
                try result.build(name: "_Bool", isConst: isConst)
            case .Void:
                try result.build(name: "void", isConst: isConst)
            case .ID:
                try result.build(name: "id", isConst: isConst)

            case var .Pointer(type):
                if type == .Unknown {
                    type = .Void
                }
                result.declarators.append(.Pointer(isConst: isConst))
                try type.buildTypeDeclaration(
                    result: &result,
                    isConst: false
                )

            case let .Array(arrayType):
                result.declarators.append(.Array(size: arrayType.size))
                try arrayType.type.buildTypeDeclaration(
                    result: &result,
                    isConst: isConst
                )

            case let .Struct(`struct`):
                let name = `struct`.name
                guard !name.isEmpty else {
                    throw TypeDeclarationError.MissingStructName(`struct`)
                }
                result.typeSpecifier = .Struct(name)

            case .Class:
                try result.build(name: "Class", isConst: isConst)

            case .Selector:
                try result.build(name: "SEL", isConst: isConst)

            case let .Const(type):
                try type.buildTypeDeclaration(
                    result: &result,
                    isConst: true
                )

            default:
                throw TypeDeclarationError.UnsupportedType(self)
        }
    }
}
