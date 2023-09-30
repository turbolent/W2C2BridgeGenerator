import BridgeSupportParser
import CWriter

public enum WebAssemblyType {
    case I32
    case I64
    case F32
    case F64

    var cWriterType: CWriter.`Type` {
        switch self {
            case .I32:
                return .U32

            case .I64:
                return .U64

            case .F32:
                return .F32

            case .F64:
                return .F64
        }
    }
}


// "Basic" C ABI for WebAssembly.
// See https://github.com/WebAssembly/tool-conventions/blob/main/BasicCABI.md
//
public struct BasicCABI {

    // See https://github.com/WebAssembly/tool-conventions/blob/main/BasicCABI.md#function-signatures
    public struct FunctionPassage: Equatable {

        // TODO: add 64-bit support (wasm64 / memory64)
        public static let Indirect = FunctionPassage(type: .I32, direct: false)

        public let type: WebAssemblyType
        public let direct: Bool

        public init(type: WebAssemblyType, direct: Bool) {
            self.type = type
            self.direct = direct
        }

        public init?(structOrUnionFields fields: [BridgeSupportParser.Field]) {
            guard let field = fields.first else {
                return nil
            }

            if fields.count == 1 {
                guard let fieldType = field.type32 else {
                    return nil
                }
                guard let functionPassage = Self(type: fieldType) else {
                    return nil
                }
                self = functionPassage
            } else {
                self = .Indirect
            }
        }

        public init?(type: BridgeSupportParser.`Type`) {
            // See https://github.com/WebAssembly/tool-conventions/blob/main/BasicCABI.md#data-representation

            switch type {
                case .Void:
                    return nil

                case .Bool, .Bitfield,
                    .Char, .UnsignedChar,
                    .Short, .UnsignedShort,
                    .Int, .UnsignedInt,
                    .Long, .UnsignedLong:

                    self = FunctionPassage(type: .I32, direct: true)

                case .Pointer, .FunctionType, .ID, .Class, .Selector, .Unknown:
                    // TODO: add 64-bit support (wasm64 / memory64)
                    self = FunctionPassage(type: .I32, direct: true)

                case .LongLong, .UnsignedLongLong:
                    self = FunctionPassage(type: .I64, direct: true)

                case .Float:
                    self = FunctionPassage(type: .F32, direct: true)

                case .Double:
                    self = FunctionPassage(type: .F64, direct: true)

                case .ComplexFloat, .ComplexDouble:
                    // TODO:
                    self = .Indirect

                case .Array:
                    // TODO: verify that even empty arrays are passed indirectly
                    self = .Indirect

                case let .Struct(structType):
                    guard let functionPassage = Self(structOrUnionFields: structType.fields) else {
                        return nil
                    }
                    self = functionPassage

                case let .Union(unionType):
                    guard let functionPassage = Self(structOrUnionFields: unionType.fields) else {
                        return nil
                    }
                    self = functionPassage

                case let .Const(type):
                    guard let functionPassage = Self(type: type) else {
                        return nil
                    }
                    self = functionPassage
            }
        }
    }
}
