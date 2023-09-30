import BridgeSupportParser
import CWriter
import SystemPackage

let argumentListChopThreshold = 48

public struct W2C2ImplementationGenerator<Output: TextOutputStream> {

    public var output: Writer<Output>
    public let escapedModuleName: String
    public let generateComments: Bool
    private var coreFoundationTypeNames: Set<String> = []
    private var structTypes: [String: StructType] = [:]

    private var reportedUnsupportedDefinitionKinds: Set<String> = []

    public init(output: Output, moduleName: String, generateComments: Bool) {
        self.output = Writer(stream: output)
        self.escapedModuleName = Self.convert(name: moduleName)
        self.generateComments = generateComments
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

        for argument in functionType.arguments {
            guard let type = argument.type32 else {
                return nil
            }

            guard let passage = BasicCABI.FunctionPassage(type: type) else {
                continue
            }

            // Indicate indirect/pointer passage in parameter
            var name = argument.name
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
        }

        for definition in definitions {
            if case let .CoreFoundationType(coreFoundationType) = definition {
                coreFoundationTypeNames.insert(coreFoundationType.name)
            }
        }

        for definition in definitions {
            generate(definition: definition)
        }
    }

    public mutating func generate(definition: Definition) {
        switch definition {
            case let .Function(function):
                generate(function: function)

            case let .Struct(`struct`):
                generate(struct: `struct`)

            case let .Class(`class`):
                generate(class: `class`)

            case .CoreFoundationType:
                // Already handled
                break

            case let .Constant(constant):
                generate(constant: constant)

            case .Enum, .Opaque:
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

    public mutating func generate(struct: BridgeSupportParser.Struct) {
        let name = `struct`.name
        guard let type = `struct`.type32 else {
            report("cannot generate struct '\(name)': missing 32-bit type")
            return
        }

        guard isBridgeable(structType: type) else {
            report("cannot generate struct '\(name)': unbridgeable type")
            return
        }

        let typeName = type.name
        guard !typeName.isEmpty else {
            report("cannot generate struct '\(name)': anonymous")
            return
        }
        structTypes[typeName] = type

        // TODO: implementation currently uses host types,
        //   assumes host matches client, i.e. 32-bit little-endian.
        //   Add support for big-endian and 64-bit.
        //   Write structs in WebAssembly/w2c2 memory format:
        //   32-bit, "host-endian", i.e. "negative memory addressing"

    }

    public mutating func generate(class: BridgeSupportParser.Class) {
        let name = `class`.name
        for method in `class`.methods {
            generate(method: method, className: name)
        }
    }

    public mutating func generate(method: Method, className: String) {
        let selector = method.selector
        let isClassMethod = method.isClassMethod
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
        let name = function.name
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

        guard checkBridgeable(
            functionType: originalFunctionType,
            kind: kind,
            coreFoundationTypeNames: coreFoundationTypeNames,
            report: report
        ) else {
            return
        }

        guard let convertedFunctionType = convert(functionType: originalFunctionType) else {
            report("cannot generate \(kind): unsupported function type: \(originalFunctionType)")
            return
        }

        let generatorPrefix = "_"

        // Parameters

        let instanceParameterName = generatorPrefix + "instance"
        let resultParameterName = generatorPrefix + "result"
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

        // Rename parameters to avoid name clashes

        for var parameter in convertedFunctionType.parameters {
            guard var parameterName = parameter.identifier else {
                report("cannot generate \(kind): converted parameter without identifier: \(parameter)")
                return
            }

            if parameterName.starts(with: generatorPrefix) {
                parameterName = generatorPrefix + parameterName
                parameter = Parameter(
                    identifier: parameterName,
                    type: parameter.type
                )
            }

            allParameters.append(parameter)
        }

        // Conversions might access memory and introduce temporaries

        var isMemoryAccessed = false
        var temporaryCount = 0
        var conversionStatements: [String] = []

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

            var argumentType = ""
            // TODO: assumes host matches client, i.e. 32-bit little-endian.
            //  Use generated "client types"
            guard let type = CInterfaceGenerator<Output>.convert(
                type32: argument.type32,
                declaredType: argument.declaredType
            ) else {
                report("cannot generate \(kind): unsupported argument type: \(argument)")
                return
            }
            type.write(identifier: nil, to: &argumentType)

            if passage.direct {
                if argument.type32?.isPointerKinded ?? false {
                    // Direct passage of pointer

                    // TODO: add big-endian support
                    let temp = newTemporary()
                    let isPointer = argument.type32?.isPointer ?? false
                    let isCoreFoundationType = argument.declaredType.map(coreFoundationTypeNames.contains) ?? false
                    var conversionStatement = "\(argumentType) \(temp) = (\(argumentType))"
                    if isPointer && !isCoreFoundationType {
                        conversionStatement.append("(\(parameterName) ? \(newMemoryOffset(parameterName)) : NULL)")
                    } else {
                        conversionStatement.append(parameterName)
                    }
                    conversionStatement.append(";\n")
                    conversionStatements.append(conversionStatement)
                    callArguments.append(temp)

                } else {
                    // Direct passage of non-pointer

                    // Handle single-value struct: construct compound literal
                    if case let .Struct(structType)? = argument.type32,
                        structType.fields.count == 1
                    {
                        callArguments.append("(\(argumentType)){\(parameterName)}")
                    } else {
                        callArguments.append(parameterName)
                    }
                }
            } else {
                // Indirect passage

                // TODO: add big-endian support
                let temp = newTemporary()
                conversionStatements.append("\(argumentType) \(temp) = \(newMemoryDereference(type: argumentType, offset: parameterName));\n")
                callArguments.append(temp)
            }
        }

        // Prepare return type

        var resultType = ""
        if let returnValue = originalFunctionType.returnValue {
            // TODO: assumes host matches client, i.e. 32-bit little-endian.
            //  Use generated "client types"
            guard let type = CInterfaceGenerator<Output>.convert(
                type32: returnValue.type32,
                declaredType: returnValue.declaredType
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
                // TODO: add big-endian support
                returnPrefix = "\(newMemoryDereference(type: resultType, offset: resultParameterName)) = "
            }

        }

        // Write function

        let generateComments = generateComments
        output.write {
            if generateComments {
                LineComment(kind.description)
            }

            CWriter.Function(
                returnType: returnType,
                identifier: identifier,
                parameters: allParameters
            ) {
                if isMemoryAccessed {
                    Raw("wasmMemory* \(memoryVariableName) = W2C2_BRIDGE_MEM(\(instanceParameterName));\n")
                }

                for conversionStatement in conversionStatements {
                    Raw(conversionStatement)
                }

                // Call statement: call function with arguments,
                // and return result if needed
                Concat {
                    if let returnPrefix {
                        Raw(returnPrefix)
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

                    if let returnSuffix {
                        Raw(returnSuffix)
                    }

                    Raw(";\n")
                }
            }

            Newline
        }
    }
}
