import BridgeSupportParser
import CWriter

public func isBridgeable(
    type: BridgeSupportParser.`Type`,
    allowPointer: Bool,
    generateBigEndian: Bool
) -> Bool {
    switch type {
        case .Pointer(let type):
            guard allowPointer else {
                return false
            }

            return isBridgeable(
                type: type,
                allowPointer: false,
                generateBigEndian: generateBigEndian
            )

        case .FunctionType, .Unknown:
            return false

        case .ComplexFloat, .ComplexDouble:
            // TODO:
            return false

        case .Char, .Int, .Short, .Long, .LongLong,
            .UnsignedChar, .UnsignedInt, .UnsignedShort, .UnsignedLong, .UnsignedLongLong,
            .Float, .Double,
            .Bool, .Void,
            // pointers, but allocated on host side
            .ID, .Class, .Selector:

            return true

        case .Bitfield:
            // TODO: add support in convertBigEndian
            return !generateBigEndian

        case .Array(let arrayType):
            // TODO: add support in convertBigEndian
            if generateBigEndian {
                return false
            }

            return isBridgeable(
                type: arrayType.type,
                allowPointer: false,
                generateBigEndian: generateBigEndian
            )

        case .Struct(let structType):
            return isBridgeable(
                structType: structType,
                generateBigEndian: generateBigEndian
            )

        case .Union(let unionType):
            return isBridgeable(
                unionType: unionType,
                generateBigEndian: generateBigEndian
            )

        case .Const(let type):
            return isBridgeable(
                type: type,
                allowPointer: allowPointer,
                generateBigEndian: generateBigEndian
            )
    }
}

public func isBridgeable(
    structType: StructType,
    generateBigEndian: Bool
) -> Bool {
    return structType.fields.allSatisfy { field in
        guard let type = field.type32 else {
            return false
        }
        return isBridgeable(
            type: type,
            allowPointer: false,
            generateBigEndian: generateBigEndian
        )
    }
}

public func isBridgeable(
    unionType: UnionType,
    generateBigEndian: Bool
) -> Bool {
    // TODO: add support in convertBigEndian
    if generateBigEndian {
        return false
    }

    return unionType.fields.allSatisfy { field in
        guard let type = field.type32 else {
            return false
        }
        return isBridgeable(
            type: type,
            allowPointer: false,
            generateBigEndian: generateBigEndian
        )
    }
}

public func isBridgeable(
    returnValue: ReturnValue,
    allowPointer: Bool,
    generateBigEndian: Bool
) -> Bool {
    guard let type32 = returnValue.type32 else {
        return false
    }
    return isBridgeable(
        type: type32,
        allowPointer: allowPointer,
        generateBigEndian: generateBigEndian
    )
}

public func isBridgeable(
    argument: Argument,
    allowPointer: Bool,
    generateBigEndian: Bool
) -> Bool {
    guard let type32 = argument.type32 else {
        return false
    }
    return isBridgeable(
        type: type32,
        allowPointer: allowPointer,
        generateBigEndian: generateBigEndian
    )
}

func checkBridgeable(
    functionType: FunctionType,
    kind: FunctionKind,
    coreFoundationTypeNames: Set<String>,
    generateBigEndian: Bool,
    report: (String) -> Void
) -> Bool {

    func isCoreFoundationType(declaredType: String?) -> Bool {
        guard let declaredType else {
            return false
        }
        return coreFoundationTypeNames.contains(declaredType)
    }

    // Ensure return value is bridgeable

    if let returnValue = functionType.returnValue {

        let allowPointer = isCoreFoundationType(declaredType: returnValue.declaredType)
            || returnValue.type32.map(isVoidPointerType) ?? false

        guard isBridgeable(
            returnValue: returnValue,
            allowPointer: allowPointer,
            generateBigEndian: generateBigEndian
        ) else {
            report("cannot generate \(kind): unbridgeable return value: \(returnValue)")
            return false
        }
    }

    // Ensure all arguments are bridgeable

    // When generating code for little-endian systems, a pointer to any size is acceptable,
    // because the memory of the WebAssembly module is layed out in little-endian already.
    //
    // For big-endian systems, we only allow certain types:
    // Core Foundation types (pointers), void-pointers, and char-pointers

    let allowPointerArguments = !generateBigEndian

    for argument in functionType.arguments {

        let allowPointer = allowPointerArguments
            || isCoreFoundationType(declaredType: argument.declaredType)
            || argument.type32.map {
                    isPointerType($0, inner: isChar)
                        || isVoidPointerType($0)
               } ?? false

        guard isBridgeable(
            argument: argument,
            allowPointer: allowPointer,
            generateBigEndian: generateBigEndian
        ) else {
            report("cannot generate \(kind): unbridgeable argument: \(argument)")
            return false
        }

        // Functions/methods might not be declared variadic,
        // but still are variadic
        if argument.declaredType == "va_list" {
            report("cannot generate \(kind): variadic")
            return false
        }
    }

    return true
}

enum FunctionKind: CustomStringConvertible {
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

extension BridgeSupportParser.`Type` {

    var typeDeclaration: CWriter.TypeDeclaration? {
        switch self {
            // Signed
            case .Char:
                return .Char
            case .Int:
                return .Int
            case .Short:
                return .Short
            case .Long:
                return .Long
            case .LongLong:
                return .LongLong

            // Unsigned
            case .UnsignedChar:
                return .UnsignedChar
            case .UnsignedInt:
                return .UnsignedInt
            case .UnsignedShort:
                return .UnsignedShort
            case .UnsignedLong:
                return .UnsignedLong
            case .UnsignedLongLong:
                return .UnsignedLongLong

            // Floating point
            case .Float:
                return .Float
            case .Double:
                return .Double

            // Other
            case .Bool:
                return ._Bool
            case .Void:
                return .Void
            case .ID:
                return .ID

            case var .Pointer(type):
                if type == .Unknown {
                    type = .Void
                }
                guard var typeDeclaration = type.typeDeclaration else {
                    return nil
                }
                typeDeclaration.declarators.append(.Pointer(isConst: false))
                return typeDeclaration

            case let .Array(arrayType):
                guard var typeDeclaration = arrayType.type.typeDeclaration else {
                    return nil
                }
                typeDeclaration.declarators.append(.Array(size: arrayType.size))
                return typeDeclaration

            case let .Struct(`struct`):
                let name = `struct`.name
                guard !name.isEmpty else {
                    return nil
                }
                return TypeDeclaration(struct: name)

            case .Class:
                return TypeDeclaration(name: "Class")

            case .Selector:
                return TypeDeclaration(name: "SEL")

            default:
                // TODO:
                return nil
        }
    }
}

func isChar(_ type: BridgeSupportParser.`Type`) -> Bool {
    switch type {
        case .UnsignedChar, .Char:
            return true
        default:
            return false
    }
}

func isVoidPointerType(_ type: BridgeSupportParser.`Type`) -> Bool {
    return isPointerType(type) { $0 == .Void }
}

func isPointerType(_ type: BridgeSupportParser.`Type`, inner: (BridgeSupportParser.`Type`) -> Bool) -> Bool {
    switch type {
        case let .Pointer(type),
            let .Const(.Pointer(type)):

            if case let .Const(type) = type {
                return inner(type)
            }
            return inner(type)

        default:
            return false
    }
}
