import BridgeSupportParser
import CWriter
import SystemPackage

let argumentListChopThreshold = 48

public struct W2C2ImplementationGenerator<Output: TextOutputStream> {

    public var output: Writer<Output>
    public let escapedModuleName: String
    public let generateComments: Bool
    public let generateBigEndian: Bool

    private var structTypes: [String: StructType] = [:]

    private var reportedUnsupportedDefinitionKinds: Set<String> = []
    private var declaredFunctions: Set<FunctionKind> = []

    public init(
        output: Output,
        moduleName: String,
        generateComments: Bool,
        generateBigEndian: Bool,
        structs: [BridgeSupportParser.Struct]
    ) {
        self.output = Writer(stream: output)
        self.escapedModuleName = Self.convert(name: moduleName)
        self.generateComments = generateComments
        self.generateBigEndian = generateBigEndian

        for `struct` in structs {
            index(struct: `struct`)
        }
    }

    private mutating func index(struct: BridgeSupportParser.Struct) {
        guard let type = `struct`.type32 else {
            report("failed to index struct: missing 32-bit type: \(`struct`)")
            return
        }
        let name = type.name.isEmpty ? `struct`.name : type.name
        guard !name.isEmpty else {
            report("failed to index struct: missing name: \(`struct`)")
            return
        }
        let existing = structTypes[name]
        if let existing, type != existing {
            report("failed to index struct: conflict: \(name)")
            return
        }
        structTypes[name] = type
    }

    private func report(_ message: some StringProtocol) {
        var standardError = FileDescriptor.standardError
        "w2c2 implementation generator: \(message)\n".write(to: &standardError)
    }

    // Escape a name according to w2c2's rules
    public static func convert(name: String) -> String {
        let escapeChar: Character = "X"

        var escaped = ""
        escaped.reserveCapacity(name.count)

        let startIndex = name.startIndex

        for (index, c) in zip(name.indices, name) {
            if c == "_" {
                // Double underscore is reserved for concatenating module name and import name,
                // so produce triple underscore instead.

                let wasUnderscore = index != startIndex && name[name.index(before: index)] == "_"
                if (wasUnderscore) {
                    escaped.append("__")
                } else {
                    escaped.append(c)
                }
            } else if c != escapeChar && (c.isLetter || c.isNumber) {
                escaped.append(c)
            } else {
                for c in [UInt8](c.utf8) {
                    escaped.append(escapeChar)
                    escaped.append(String(format: "%02x", c))
                }
            }
        }

        return escaped
    }

    public func convert(importName: String) -> String {
       let importName = Self.convert(name: importName)
       return "\(escapedModuleName)__\(importName)"
    }

    public struct FunctionType {
        public let returnType: CWriter.`Type`
        public let returnPassage: BasicCABI.FunctionPassage?
        public let parameters: [Parameter]
        public let parameterPassages: [BasicCABI.FunctionPassage]
    }

    // Convert function to WebAssembly C ABI
    public func convert(functionType: BridgeSupportParser.FunctionType) -> FunctionType? {
        // Convert return value

        let returnType: CWriter.`Type`
        let returnPassage: BasicCABI.FunctionPassage?

        if let returnValue = functionType.returnValue {
             guard let type = returnValue.type32 else {
                return nil
            }

            returnPassage = BasicCABI.FunctionPassage(type: type)
            if let returnPassage {
                returnType = returnPassage.type.cWriterType
            } else {
                returnType = .Void
            }
        } else {
            returnType = .Void
            returnPassage = nil
        }

        // Convert arguments

        var parameters: [Parameter] = []
        var parameterPassages: [BasicCABI.FunctionPassage] = []

        for (index, argument) in functionType.arguments.enumerated() {
            guard let type = argument.type32 else {
                return nil
            }

            guard let passage = BasicCABI.FunctionPassage(type: type) else {
                continue
            }

            // Indicate indirect/pointer passage in parameter
            var name = argument.name
            if name.isEmpty {
                name = "p\(index + 1)"
            }
            if passage.direct {
                if argument.type32?.isPointerKinded ?? false {
                    name.append("Pointer")
                }
            } else {
                name.append("Indirect")
            }

            let parameter = Parameter(
                identifier: name,
                type: passage.type.cWriterType
            )

            parameters.append(parameter)
            parameterPassages.append(passage)
        }

        return FunctionType(
            returnType: returnType,
            returnPassage: returnPassage,
            parameters: parameters,
            parameterPassages: parameterPassages
        )
    }

    public mutating func generate(definitions: [Definition]) {
        output.write {
            Include(file: "w2c2_base.h", style: .Quotes)
            Newline

            Raw("extern wasmMemory* w2c2BridgeMemory(void* instance);\n");
            Newline
        }

        for definition in definitions {
            generate(definition: definition)
        }
    }

    public mutating func generate(definition: Definition) {
        switch definition {
            case let .Function(function):
                generate(function: function)

            case let .Class(`class`):
                generate(class: `class`)

            case let .Constant(constant):
                generate(constant: constant)

            case .Enum, .Opaque, .Struct, .CoreFoundationType:
                // NO-OP
                break

            default:
                let kind = definition.label
                if !reportedUnsupportedDefinitionKinds.contains(kind) {
                    reportedUnsupportedDefinitionKinds.insert(kind)
                    report("unsupported definition: \(kind)")
                }
        }
    }

    public mutating func generate(class: BridgeSupportParser.Class) {
        let name = `class`.name
        for method in `class`.methods {
            generate(method: method, className: name)
        }
    }

    public mutating func generate(method: Method, className: String) {
          guard !method.ignore else {
            return
        }

        let selector = method.selector
        let isClassMethod = method.isClassMethod
        let kind = FunctionKind.Method(
            className: className,
            selector: selector,
            isClassMethod: isClassMethod
        )

        guard !declaredFunctions.contains(kind) else {
            return
        }
        declaredFunctions.insert(kind)

        let identifier = convert(
            importName: methodFunctionName(
                forClassName: className,
                selector: selector,
                isClassMethod: isClassMethod
            )
        )

        generateFunction(
            kind: .Method(
                className: className,
                selector: selector,
                isClassMethod: isClassMethod
            ),
            identifier: identifier,
            functionType: method.functionType,
            isVariadic: method.isVariadic
        )
    }

    public mutating func generate(function: BridgeSupportParser.Function) {
        guard !function.ignore else {
            return
        }

        let name = function.name

        let kind = FunctionKind.Function(name: name)

        guard !declaredFunctions.contains(kind) else {
            return
        }
        declaredFunctions.insert(kind)

        let identifier = convert(importName: name)
        generateFunction(
            kind: .Function(name: name),
            identifier: identifier,
            functionType: function.functionType,
            isVariadic: function.isVariadic
        )
    }

    public mutating func generate(constant: Constant) {
        generate(getterForConstant: constant)
        if !constant.isConst {
            generate(setterForConstant: constant)
        }
    }

    public mutating func generate(getterForConstant constant: Constant) {
        let constantName = constant.name
        let identifier = convert(
            importName: getterFunctionName(forConstantName: constantName)
        )

        generateFunction(
            kind: .ConstantGetter(name: constantName),
            identifier: identifier,
            functionType: constantGetterFunctionType(constant),
            isVariadic: false
        )
    }

    public mutating func generate(setterForConstant constant: Constant) {
        let constantName = constant.name
        let identifier = convert(
            importName: setterFunctionName(forConstantName: constantName)
        )

        generateFunction(
            kind: .ConstantSetter(name: constantName),
            identifier: identifier,
            functionType: constantSetterFunctionType(constant),
            isVariadic: false
        )
    }

    private func convertBigEndian(
        type32: BridgeSupportParser.`Type`,
        name: String,
        conversionStatements: inout [String]
    ) {

        func addConversion(type: String) {
            conversionStatements.append("swap_\(type)(&\(name));\n")
        }

        switch type32 {
            case .Void, .ID, .Class, .Selector:
                // NO-OP
                break

            case .Bool, .Char, .UnsignedChar:
                // size = 1. NO-OP
                break

            case .Short:
                addConversion(type: "s")

            case .UnsignedShort:
                addConversion(type: "S")

            case .Int:
                addConversion(type: "i")

            case .UnsignedInt:
                addConversion(type: "I")

            case .Long:
                addConversion(type: "l")

            case .UnsignedLong:
                addConversion(type: "L")

            case .LongLong:
                addConversion(type: "q")

            case .UnsignedLongLong:
                addConversion(type: "Q")

            case .Float:
                addConversion(type: "f")

            case .Double:
                addConversion(type: "d")

            case let .Struct(structType):

                guard let structType = structTypes[structType.name] else {
                    fatalError("unreachable: missing struct type: \(structType.name)")
                }

                for field in structType.fields {
                    guard !field.name.isEmpty else {
                        fatalError("unreachable: struct field without name")
                    }

                    convertBigEndian(
                        type32: field.type32!,
                        name: "\(name).\(field.name)",
                        conversionStatements: &conversionStatements
                    )
                }

            case .Union:
                // TODO: implement (convert first field?), then enable in isBridgeable
                fatalError("unreachable. should be rejected by isBridgeable")

            case .ComplexFloat, .ComplexDouble:
                // TODO: implement, then enable in isBridgeable
                fatalError("unreachable. should be rejected by isBridgeable")

            case .FunctionType, .Unknown:
                fatalError("unreachable. should be rejected by isBridgeable")

            case .Pointer:
                // NO-OP. unable to convert pointer contents to big-endian
                break

            case .Array, .Bitfield:
                // TODO: implement, then enable in isBridgeable
                fatalError("unreachable. should be rejected by isBridgeable")

            case let .Const(type):
                return convertBigEndian(
                    type32: type,
                    name: name,
                    conversionStatements: &conversionStatements
                )
        }
    }

    private mutating func generateFunction(
        kind: FunctionKind,
        identifier: String,
        functionType originalFunctionType: BridgeSupportParser.FunctionType,
        isVariadic: Bool
    ) {

        guard !isVariadic else {
            report("cannot generate \(kind): variadic")
            return
        }

        do {
            try checkBridgeable(
                functionType: originalFunctionType,
                generateBigEndian: generateBigEndian
            )
        } catch let error {
            report("cannot generate \(kind): \(error)")
            return
        }

        guard let convertedFunctionType = convert(functionType: originalFunctionType) else {
            report("cannot generate \(kind): unsupported function type: \(originalFunctionType)")
            return
        }

        let generatorPrefix = "_"

        // Parameters

        let instanceParameterName = generatorPrefix + "instance"
        let resultParameterName = generatorPrefix + "resultIndirect"
        let resultVariableName = generatorPrefix + "result"
        let memoryVariableName = generatorPrefix + "mem"
        let selfParameterName = generatorPrefix + "self"
        let classParameterName = generatorPrefix + "class"

        var allParameters = [
            // All functions get passed the module instance
            Parameter(
                identifier: instanceParameterName,
                type: .Declaration(TypeDeclaration(
                    typeSpecifier: .Name("void"),
                    declarators: [.Pointer(isConst: false)]
                ))
            )
        ]

        // "types can [...] be returned indirectly via a pointer parameter prepended to the parameter list"
        let returnType: CWriter.`Type`
        if let returnPassage = convertedFunctionType.returnPassage,
            !returnPassage.direct
        {
            allParameters.append(Parameter(
                identifier: resultParameterName,
                // TODO: add 64-bit support (wasm64 / memory64)
                type: .U32
            ))
            returnType = .Void
        } else {
            returnType = convertedFunctionType.returnType
        }

        // Instance methods pass self
        if case let .Method(className: _, selector: _, isClassMethod: isClassMethod) = kind {
            let identifier = isClassMethod
                ? classParameterName
                : selfParameterName
            allParameters.append(Parameter(
                identifier: identifier,
                // TODO: add 64-bit support (wasm64 / memory64)
                type: .U32
            ))
        }

        let additionalParameterCount = allParameters.count

        allParameters.append(contentsOf: convertedFunctionType.parameters)

        // Ensure all parameters have identifiers, that are unique
        fixParameterIdentifiers(&allParameters)

        // Conversions might access memory and introduce temporaries

        var isMemoryAccessed = false
        var temporaryCount = 0
        var argumentConversionStatements: [String] = []
        var bigEndianArgumentConversionStatements: [String] = []
        var bigEndianReturnValueConversionStatements: [String] = []

        func newTemporary() -> String {
            temporaryCount += 1
            return "\(generatorPrefix)t\(temporaryCount)"
        }

        func newMemoryOffset(_ offset: String) -> String {
            isMemoryAccessed = true
            return "\(memoryVariableName)->data + \(offset)"
        }

        func newMemoryDereference(type: String, offset: String) -> String {
            return "*(\(type)*)(\(newMemoryOffset(offset)))"
        }

        // Prepare call arguments

        var callArguments: [String] = []
        for (parameterIndex, parameter) in
            allParameters.dropFirst(additionalParameterCount).enumerated()
        {
            guard let parameterName = parameter.identifier else {
                report("cannot generate \(kind): converted parameter without identifier: \(parameter)")
                return
            }

            let argument = originalFunctionType.arguments[parameterIndex]
            let passage = convertedFunctionType.parameterPassages[parameterIndex]

            var argumentType = argument.isConst ? "const " : ""
            // TODO: assumes host matches client, i.e. 32-bit little-endian.
            guard let type = CInterfaceGenerator<Output>.convert(
                type32: argument.type32,
                declaredType: argument.declaredType,
                structTypes: structTypes
            ) else {
                report("cannot generate \(kind): unsupported argument type: \(argument)")
                return
            }
            type.write(identifier: nil, to: &argumentType)

            if passage.direct {
                if argument.type32?.isPointerKinded ?? false {
                    // Direct passage of pointer

                    let temp = newTemporary()
                    argumentConversionStatements.append("\(argumentType) \(temp) = (\(argumentType))\(parameterName);\n")
                    callArguments.append(temp)

                } else {
                    // Direct passage of non-pointer

                    // Handle single-value struct: construct compound literal
                    if case let .Struct(structType)? = argument.type32,
                        structType.fields.count == 1
                    {
                        // TODO: add big-endian support

                        callArguments.append("(\(argumentType)){\(parameterName)}")
                    } else {
                        callArguments.append(parameterName)
                    }
                }
            } else {
                // Indirect passage

                let temp = newTemporary()
                argumentConversionStatements.append("\(argumentType) \(temp) = \(newMemoryDereference(type: argumentType, offset: parameterName));\n")
                if generateBigEndian {
                    convertBigEndian(
                        type32: argument.type32!,
                        name: temp,
                        conversionStatements: &bigEndianArgumentConversionStatements
                    )
                }
                callArguments.append(temp)
            }
        }

        // Prepare return type

        var resultType = ""
        if let returnValue = originalFunctionType.returnValue {
            if returnValue.isConst {
                resultType = "const "
            }

            // TODO: assumes host matches client, i.e. 32-bit little-endian.
            guard let type = CInterfaceGenerator<Output>.convert(
                type32: returnValue.type32,
                declaredType: returnValue.declaredType,
                structTypes: structTypes
            ) else {
                report("cannot generate \(kind): unsupported return value: \(returnValue)")
                return
            }
            type.write(identifier: nil, to: &resultType)
        }

        // Prepare return prefix and suffix

        var returnPrefix: String? = nil
        var returnSuffix: String? = nil

        if let returnPassage = convertedFunctionType.returnPassage {
            if returnPassage.direct {
                if returnType != .Void {
                    var returnTypeString = ""
                    returnType.write(identifier: nil, to: &returnTypeString)

                    returnPrefix = "return (\(returnTypeString))"
                }

                // Handle single-value struct: get field
                if case let .Struct(structType)? = originalFunctionType.returnValue?.type32,
                    structType.fields.count == 1
                {
                    // TODO: add big-endian support

                    guard let structType = structTypes[structType.name] else {
                        report("cannot generate \(kind): directly passed return value for single-field struct of unknown type: \(structType.name)")
                        return
                    }

                    guard let fieldName = structType.fields.first?.name,
                        structType.fields.count == 1
                    else {
                        report("cannot generate \(kind): directly passed return value for supposedly single-field struct, but incorrect field count: \(structType.name)")
                        return
                    }

                    returnSuffix = ".\(fieldName)"
                }

            } else {
                returnPrefix = "\(newMemoryDereference(type: resultType, offset: resultParameterName)) = "
                if generateBigEndian {
                    let returnValue = originalFunctionType.returnValue!
                    convertBigEndian(
                        type32: returnValue.type32!,
                        name: resultVariableName,
                        conversionStatements: &bigEndianReturnValueConversionStatements
                    )
                }
            }
        }

        // Write function

        output.write { [generateComments] in
            if generateComments {
                LineComment(kind.description)
            }

            CWriter.Function(
                returnType: returnType,
                identifier: identifier,
                parameters: allParameters
            ) {
                if isMemoryAccessed {
                    Raw("wasmMemory* \(memoryVariableName) = w2c2BridgeMemory(\(instanceParameterName));\n")
                }

                for conversionStatement in argumentConversionStatements {
                    Raw(conversionStatement)
                }
                if !bigEndianArgumentConversionStatements.isEmpty {
                    Raw("#if WASM_ENDIAN == WASM_BIG_ENDIAN\n")
                    for conversionStatement in bigEndianArgumentConversionStatements {
                        Raw(conversionStatement)
                    }
                    Raw("#endif\n")
                }

                // Call statement: call function with arguments,
                // and return result if needed
                Concat {
                    if returnPrefix != nil {
                        Raw("\(resultType) \(resultVariableName) = (\(resultType))")
                    }

                    switch kind {
                        case let .Function(name):
                            Raw("\(name)(\(callArguments.joined(separator: ", ")))")

                        case let .Method(
                            className: className,
                            selector: selector,
                            isClassMethod: isClassMethod
                        ):

                            Raw("[")
                            if isClassMethod {
                                Raw("(Class)\(classParameterName)")
                            } else if className == "NSObject" {
                                // Some methods are declared on NSObject, but are actually from an (informal) protocol.
                                // Casting to a concrete type like NSObject and returning a non-scalar is invalid.
                                // Cast to id instead.
                                Raw("(id)\(selfParameterName)")
                            } else {
                                Raw("(\(className)*)\(selfParameterName)")
                            }

                            if callArguments.isEmpty {
                                Raw(" \(selector)")
                            } else {
                                let argumentLabels = selector.split(separator: ":")
                                for (argumentLabel, callArgument) in zip(argumentLabels, callArguments) {
                                    Raw(" \(argumentLabel):\(callArgument)")
                                }
                            }

                            Raw("]")

                        case let .ConstantGetter(constantName):
                            Raw(constantName)

                        case let .ConstantSetter(constantName):
                            Raw("\(constantName) = \(callArguments.first!)")
                    }

                    Raw(";\n")
                }

                if !bigEndianReturnValueConversionStatements.isEmpty {
                    Raw("#if WASM_ENDIAN == WASM_BIG_ENDIAN\n")
                    for conversionStatement in bigEndianReturnValueConversionStatements {
                        Raw(conversionStatement)
                    }
                    Raw("#endif\n")
                }

                if let returnPrefix {
                    Concat {
                        Raw("\(returnPrefix)\(resultVariableName)")

                        if let returnSuffix {
                            Raw(returnSuffix)
                        }

                        Raw(";\n")
                    }
                }
            }

            Newline
        }
    }
}
