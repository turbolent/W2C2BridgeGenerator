import BridgeSupportParser
import CWriter
import SystemPackage

private let genericArgumentRegex = try! Regex(#" *<[^>]*>"#)

private let instanceTypeSelectorRegex = try! Regex(#"^(?:alloc|init|new)($|[A-Z0-9_])"#)

private let typedefDeclaredTypesRegex = try! Regex(#"^([A-Za-z_]\w*)(\*)?$"#)

private let typedefDisallowedDeclaredTypes: [String] = [
    "char", "signed char", "unsigned char",
    "short", "short int", "signed short", "signed short int",
    "unsigned short", "unsigned short int",
    "int", "signed", "signed int", "unsigned", "unsigned int",
    "long", "long int", "signed long", "signed long int",
    "unsigned long", "unsigned long int",
    "long long", "long long int", "signed long long", "signed long long int",
    "unsigned long long", "unsigned long long int",
    "float", "double", "long double",
    "void", "id", "Class", "SEL",
    // Declared as id
    "Protocol*"
]

private let typedefAllowedTypes: [BridgeSupportParser.`Type`] = [
    .Char, .Int, .Short, .Long, .LongLong,
    .UnsignedChar, .UnsignedInt, .UnsignedShort, .UnsignedLong, .UnsignedLongLong,
    .Float, .Double, .ComplexFloat, .ComplexDouble,
    .Bool, .Void, .ID
]

public struct CInterfaceGenerator<Output: TextOutputStream> {

    public var output: Writer<Output>
    public let generateComments: Bool
    public let generateBigEndian: Bool

    private var reportedUnsupportedDefinitionKinds: Set<String> = []
    private var coreFoundationTypeNames: Set<String> = []
    private var declaredTypeTypeDefs: Set<String> = []
    private var declaredClasses: Set<String> = []

    public init(
        output: Output,
        generateComments: Bool,
        generateBigEndian: Bool
    ) {
        self.output = Writer(stream: output)
        self.generateComments = generateComments
        self.generateBigEndian = generateBigEndian
    }

    private func report(_ message: some StringProtocol) {
        var standardError = FileDescriptor.standardError
        "C interface generator: \(message)\n".write(to: &standardError)
    }

    public static func convert(type32: BridgeSupportParser.`Type`?, declaredType: String?) -> CWriter.`Type`? {
        if var declaredType {
            // Filter generic arguments, e.g. `id <NSCopying>` => `id`
            declaredType.replace(genericArgumentRegex, with: "")

            return .Raw(declaredType)
        }

        if let typeDeclaration = type32.flatMap({ $0.typeDeclaration }) {
            return .Declaration(typeDeclaration)
        }

        return nil
    }

    public static func convert(returnValue: ReturnValue) -> CWriter.`Type`? {
        return convert(
            type32: returnValue.type32,
            declaredType: returnValue.declaredType
        )
    }

    public static func convert(argument: Argument, name: String) -> Parameter? {
        guard let parameterType = convert(
            type32: argument.type32,
            declaredType: argument.declaredType
        ) else {
            return nil
        }

        return Parameter(
            identifier: name,
            type: parameterType
        )
    }

    public static func convert(field: BridgeSupportParser.Field) -> CWriter.Field? {
        guard let type = field.type32 else {
            return nil
        }
        guard let typeDeclaration = type.typeDeclaration else {
            return nil
        }
        return CWriter.Field(
            identifier: field.name,
            type: .Declaration(typeDeclaration)
        )
    }

    public static func convert(functionType: FunctionType) -> (returnType: CWriter.`Type`, parameters: [Parameter])? {
        // Convert return type

        let returnType: CWriter.`Type`
        if let returnValue = functionType.returnValue {
            guard let type = convert(returnValue: returnValue) else {
                return nil
            }
            returnType = type
        } else {
            returnType = .Void
        }

        // Convert arguments

        var parameters: [Parameter] = []
        var parameterIdentifiers: [String: Int] = [:]
        for argument in functionType.arguments {

            var name = argument.name
            if var count = parameterIdentifiers[name] {
                count += 1
                parameterIdentifiers[name] = count
                name += "_\(count)"
            }
            parameterIdentifiers[name] = 1

            guard let parameter = convert(argument: argument, name: name) else {
                return nil
            }
            parameters.append(parameter)
        }

        return (
            returnType: returnType,
            parameters: parameters
        )
    }

    /// Return all type definitions (classes, CoreFoundation types, opaque types, and structs),
    /// in proper order: Structs may have dependencies on non-struct types and other structs,
    /// given they have fields. Essentially a topological sort, using depth-first search.
    public func orderedTypeDefinitions(_ definitions: [Definition]) -> [Definition] {

        var stack: [Definition] = []

        var structs: [String: BridgeSupportParser.Struct] = [:]
        var visitedStructs: [String: Bool] = [:]

        for definition in definitions {
            switch definition {
                case .Class, .Opaque, .CoreFoundationType:
                    stack.append(definition)

                case let .Struct(`struct`):
                    guard let type32 = `struct`.type32 else {
                        report("cannot generate struct '\(`struct`.name)': missing 32-bit type")
                        continue
                    }

                    visitedStructs[type32.name] = false
                    structs[type32.name] = `struct`

                default:
                    continue
            }
        }

        func visit(structName: String) {
            let `struct` = structs[structName]!
            let type32 = `struct`.type32!

            var dependencies: [String] = []
            type32.bestEffortStructDependencies32(result: &dependencies)

            for dependency in dependencies {
                if let seen = visitedStructs[dependency], !seen {
                    visit(structName: dependency)
                }
            }

            stack.append(.Struct(`struct`))
            visitedStructs[structName] = true
        }

        for (structName, _) in visitedStructs {
            if let seen = visitedStructs[structName], !seen {
                visit(structName: structName)
            }
        }

        return stack
    }

    public mutating func generateTypeDefinition(declaredType: String, type32: BridgeSupportParser.`Type`) {
        guard typedefAllowedTypes.contains(type32),
            !typedefDisallowedDeclaredTypes.contains(declaredType),
            !declaredTypeTypeDefs.contains(declaredType),

            let match = declaredType.wholeMatch(of: typedefDeclaredTypesRegex),
            let namePrefix = match.output[1].substring
        else {
            return
        }

        declaredTypeTypeDefs.insert(declaredType)

        let name = String(namePrefix)

        let pointerSuffix = match.output[2].substring
        if pointerSuffix != nil {
            // Pointers are only allowed for id declarations, for now

            guard type32 == .ID else {
                return
            }

            declaredClasses.insert(name)

            let generateComments = generateComments
            output.write {
                if generateComments {
                    LineComment("class '\(name)'")
                }
                CWriter.Typedef(
                    identifier: name,
                    type: .init(struct: name)
                )

                Newline
            }

        } else {
            // Non-pointer

            guard let typeDeclaration = type32.typeDeclaration else {
                return
            }

            output.write {
                CWriter.Typedef(
                    identifier: name,
                    type: .Declaration(typeDeclaration)
                )

                Newline
            }
        }
    }

    public mutating func generateTypeDefinition(functionType: FunctionType) {
        for argument in functionType.arguments {
            if let declaredType = argument.declaredType,
                let type32 = argument.type32
            {
                generateTypeDefinition(
                    declaredType: declaredType,
                    type32: type32
                )
            }
        }

        if let returnValue = functionType.returnValue,
            let declaredType = returnValue.declaredType,
            let type32 = returnValue.type32
        {
            generateTypeDefinition(
                declaredType: declaredType,
                type32: type32
            )
        }
    }

    /// Generate typedefs for all declared types in structs (fields), functions, and methods.
    /// This is a best effort approach
    public mutating func generate(declaredTypeDefinitions definitions: [Definition]) {

        for definition in definitions {
            switch definition {
            case let .Class(`class`):
                for method in `class`.methods {
                    generateTypeDefinition(functionType: method.functionType)
                }

            case let .Function(function):
                generateTypeDefinition(functionType: function.functionType)

            // TODO: maybe also consider struct fields

            default:
                break

            }
        }
    }

    public mutating func generate(definitions: [Definition]) {

        // Register all CoreFoundation type names.
        // Pointers to these types are bridgeable, as they are host-allocated

        for definition in definitions {
            if case let .CoreFoundationType(coreFoundationType) = definition {
                coreFoundationTypeNames.insert(coreFoundationType.name)
            }
        }

        // Generate typedefs for all declared types in structs (fields), functions, and methods
        generate(declaredTypeDefinitions: definitions)

        // Generate type definitions

        for definition in orderedTypeDefinitions(definitions) {
            generate(definition: definition)
        }

        // Generate remaining definitions (methods, functions, enums, etc.)

        for definition in definitions {
            switch definition {
            case .CoreFoundationType, .Opaque, .Struct:
                // Already generated
                continue

            case let .Class(`class`):
                // Revisit class, but only generate methods.
                let className = `class`.name
                for method in `class`.methods {
                    generate(method: method, className: className)
                }

            default:
                generate(definition: definition)
            }
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

            case let .CoreFoundationType(coreFoundationType):
                generate(coreFoundationType: coreFoundationType)

            case let .Constant(constant):
                generate(constant: constant)

            case let .Enum(`enum`):
                generate(enum: `enum`)

            case let .Opaque(opaque):
                generate(opaque: opaque)

            default:
                let kind = definition.label
                if !reportedUnsupportedDefinitionKinds.contains(kind) {
                    reportedUnsupportedDefinitionKinds.insert(kind)
                    report("unsupported definition: \(kind)")
                }
        }
    }

    public mutating func generate(struct: BridgeSupportParser.Struct) {
        let typedefName = `struct`.name

        guard let type = `struct`.type32 else {
            report("cannot generate struct '\(typedefName)': missing 32-bit type")
            return
        }

        guard isBridgeable(
            structType: type,
            generateBigEndian: generateBigEndian
        ) else {
            report("cannot generate struct '\(typedefName)': unbridgeable type")
            return
        }

        let structName = type.name

        var fields: [CWriter.Field] = []
        for field in type.fields {
            guard let field = Self.convert(field: field) else {
                report("cannot generate struct '\(typedefName)': unsupported field: \(field)")
                return
            }
            fields.append(field)
        }

        let generateComments = generateComments
        output.write {
            if generateComments {
                LineComment("struct '\(typedefName)'")
            }

            CWriter.Struct(
                identifier: structName,
                body: { fields }
            )

            Typedef(
                identifier: typedefName,
                type: Type(struct: structName)
            )

            Newline
        }
    }

    public mutating func generate(class: BridgeSupportParser.Class) {
        let name = `class`.name

        guard !declaredClasses.contains(name) else {
            return
        }

        let generateComments = generateComments
        output.write {
            if generateComments {
                LineComment("class '\(name)'")
            }

            Typedef(
                identifier: name,
                type: Type(struct: name)
            )

            Newline
        }
    }

    public mutating func generate(coreFoundationType: CoreFoundationType) {
        let name = coreFoundationType.name

        guard let type = coreFoundationType.type32 else {
            report("cannot generate CoreFoundation type '\(name)': missing type")
            return
        }
        guard case let .Pointer(.Struct(structType)) = type else {
            report("cannot generate CoreFoundation type '\(name)': unsupported type: \(type)")
            return
        }
        guard structType.fields.isEmpty else {
            report("cannot generate CoreFoundation type '\(name)': unsupported non-opaque struct type: \(structType)")
            return
        }

        let generateComments = generateComments
        output.write {
            if generateComments {
                LineComment("CoreFoundation type '\(name)'")
            }

            Typedef(
                identifier: name,
                type: .Declaration(TypeDeclaration(
                    typeSpecifier: .Struct(structType.name),
                    declarators: [.Pointer(isConst: false)]
                ))
            )

            Newline
        }
    }

    public mutating func generate(function: BridgeSupportParser.Function) {
        let name = function.name
        let functionType = function.functionType
        let kind = FunctionKind.Function(name: name)

        guard !function.isVariadic else {
            report("cannot generate \(kind): variadic")
            return
        }

        guard checkBridgeable(
            functionType: functionType,
            kind: kind,
            coreFoundationTypeNames: coreFoundationTypeNames,
            generateBigEndian: generateBigEndian,
            report: report
        ) else {
            return
        }

        // Convert function type

        guard case (let returnType, var parameters)? = Self.convert(functionType: functionType) else {
            report("cannot generate \(kind): unsupported function type: \(functionType)")
            return
        }

        // Add void parameter to indicate empty parameter list
        if parameters.isEmpty {
            parameters.append(Parameter(type: .Void))
        }

        // Write function

        let generateComments = generateComments
        output.write {
            if generateComments {
                LineComment(kind.description)
            }

            CWriter.Function(
                returnType: returnType,
                identifier: name,
                parameters: parameters
            )

            Newline
        }
    }

    public mutating func generate(method: Method, className: String) {
        let selector = method.selector
        let functionType = method.functionType
        let isClassMethod = method.isClassMethod
        let kind = FunctionKind.Method(
            className: className,
            selector: selector,
            isClassMethod: isClassMethod
        )

        guard !method.isVariadic else {
            report("cannot generate \(kind): variadic")
            return
        }

        guard checkBridgeable(
            functionType: functionType,
            kind: kind,
            coreFoundationTypeNames: coreFoundationTypeNames,
            generateBigEndian: generateBigEndian,
            report: report
        ) else {
            return
        }

        let name = methodFunctionName(
            forClassName: className,
            selector: selector,
            isClassMethod: isClassMethod
        )

        // Return type

        guard case var (returnType, parameters)? = Self.convert(functionType: functionType) else {
            report("cannot generate \(kind)': unsupported function type: \(functionType)")
            return
        }

        // Change return type of method that start with "alloc", "init", or "new", and return 'id',
        // to returning the instance type (i.e. pointer to class).
        // See https://developer.apple.com/library/archive/releasenotes/ObjectiveC/ModernizationObjC/AdoptingModernObjective-C/AdoptingModernObjective-C.html

        if functionType.returnValue?.type32 == .ID
            && selector.starts(with: instanceTypeSelectorRegex)
        {
            returnType = .Declaration(TypeDeclaration(
                typeSpecifier: .Name(className),
                declarators: [.Pointer(isConst: false)]
            ))
        }

        // Parameters

        // Prefix parameter list with additional class/self parameter for class/instance methods
        let parameter: Parameter
        if isClassMethod {
            parameter = Parameter(
                identifier: "_class",
                type: Type(name: "Class")
            )
        } else {
            parameter = Parameter(
                identifier: "_self",
                type: .Declaration(TypeDeclaration(
                    typeSpecifier: .Name(className),
                    declarators: [.Pointer(isConst: false)]
                ))
            )
        }
        parameters.insert(parameter, at: 0)


        // Write function
        let generateComments = generateComments
        output.write {
            if generateComments {
                LineComment(kind.description)
            }

            CWriter.Function(
                returnType: returnType,
                identifier: name,
                parameters: parameters
            )

            Newline
        }
    }

    public mutating func generate(constant: Constant) {
        generate(getterForConstant: constant)
        if !constant.isConst {
            generate(setterForConstant: constant)
        }
    }

    public mutating func generate(getterForConstant constant: Constant) {
        let name = constant.name
        let kind = FunctionKind.ConstantGetter(name: name)

        let functionType = constantGetterFunctionType(constant)

        guard checkBridgeable(
            functionType: functionType,
            kind: kind,
            coreFoundationTypeNames: coreFoundationTypeNames,
            generateBigEndian: generateBigEndian,
            report: report
        ) else {
            return
        }

        guard case let (returnType, _)? = Self.convert(functionType: functionType) else {
            report("cannot generate \(kind)': unsupported function type: \(functionType)")
            return
        }

        let generateComments = generateComments
        output.write {
            if generateComments {
                LineComment(kind.description)
            }

            CWriter.Function(
                returnType: returnType,
                identifier: getterFunctionName(forConstantName: name),
                // Add void parameter to indicate empty parameter list
                parameters: [Parameter(type: .Void)]
            )

            Newline
        }
    }

    public mutating func generate(setterForConstant constant: Constant) {
        let name = constant.name
        let kind = FunctionKind.ConstantSetter(name: name)

        let functionType = constantSetterFunctionType(constant)

        guard checkBridgeable(
            functionType: functionType,
            kind: kind,
            coreFoundationTypeNames: coreFoundationTypeNames,
            generateBigEndian: generateBigEndian,
            report: report
        ) else {
            return
        }

        guard case let (returnType, parameters)? = Self.convert(functionType: functionType) else {
            report("cannot generate \(kind)': unsupported function type: \(functionType)")
            return
        }

        let generateComments = generateComments
        output.write {
            if generateComments {
                LineComment(kind.description)
            }

            CWriter.Function(
                returnType: returnType,
                identifier: setterFunctionName(forConstantName: name),
                parameters: parameters
            )

            Newline
        }
    }

    public mutating func generate(enum: Enum) {
        let name = `enum`.name

        guard let value = `enum`.value32 ?? `enum`.value64 else {
            report("cannot generate enum '\(name)': missing value")
            return
        }

        output.write {
            if value.contains(".") {
                Raw("#define \(name) \(value)")
            } else {
                Raw("enum { \(name) = \(value) };")
            }
            Newline

            Newline
        }
    }

    public mutating func generate(opaque: Opaque) {
        let name = opaque.name

        guard let type = opaque.type32 else {
            report("cannot generate opaque type '\(name)': missing type")
            return
        }
        guard case let .Pointer(.Struct(structType)) = type else {
            report("cannot generate opaque type '\(name)': unsupported type: \(type)")
            return
        }
        guard structType.fields.isEmpty else {
            report("cannot generate opaque type '\(name)': unsupported non-opaque struct type: \(structType)")
            return
        }

        let generateComments = generateComments
        output.write {
            if generateComments {
                LineComment("opaque '\(name)'")
            }

            Typedef(
                identifier: name,
                type: .Declaration(TypeDeclaration(
                    typeSpecifier: .Struct(structType.name),
                    declarators: [.Pointer(isConst: false)]
                ))
            )

            Newline
        }
    }
}
