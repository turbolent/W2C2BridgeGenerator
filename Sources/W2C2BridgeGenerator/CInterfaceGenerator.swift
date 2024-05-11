import BridgeSupportParser
import CWriter
import SystemPackage
import Difference

private let instanceTypeSelectorRegex = try! Regex(#"^(?:alloc|init|new)($|[A-Z0-9_])"#)

private enum TypeDefinition {
    case Class(BridgeSupportParser.Class)
    case CoreFoundationType(BridgeSupportParser.CoreFoundationType)
    case Opaque(BridgeSupportParser.Opaque)
    case Struct(BridgeSupportParser.Struct)
}

public struct CInterfaceGenerator<Output: TextOutputStream> {

    public var headerOutput: Writer<Output>
    public var symbolsOutput: Output?
    public let generateComments: Bool
    public let generateBigEndian: Bool

    private var reportedUnsupportedDefinitionKinds: Set<String> = []
    private var declaredClasses: Set<String> = []
    private var declaredFunctions: Set<FunctionKind> = []

    public init(
        headerOutput: Output,
        symbolsOutput: Output? = nil,
        generateComments: Bool,
        generateBigEndian: Bool
    ) {
        self.headerOutput = Writer(stream: headerOutput)
        self.symbolsOutput = symbolsOutput
        self.generateComments = generateComments
        self.generateBigEndian = generateBigEndian
    }

    private func report(_ message: some StringProtocol) {
        var standardError = FileDescriptor.standardError
        "C interface generator: \(message)\n".write(to: &standardError)
    }

    public static func convert(
        type32: BridgeSupportParser.`Type`?,
        isConst: Bool
    ) -> CWriter.`Type`? {
        guard let typeDeclaration = type32.flatMap({
            $0.typeDeclaration(isConst: isConst)
        }) else {
            return nil
        }
        return .Declaration(typeDeclaration)
    }

    private func isPointerToClass(declaredType: String) -> Bool {
        return declaredType.last == "*"
            && declaredClasses.contains(String(declaredType.dropLast()))
    }

    private func convert(returnValue: ReturnValue) -> CWriter.`Type`? {
        // Prefer declared type if pointer to class
        if let declaredType = returnValue.declaredType,
            isPointerToClass(declaredType: declaredType)
        {
            return .Raw(declaredType)
        }

        return Self.convert(
            type32: returnValue.type32,
            isConst: returnValue.isConst
        )
    }

    private func convert(argument: Argument, name: String) -> Parameter? {

        // Prefer declared type if pointer to class, or va_list
        if let declaredType = argument.declaredType,
            isPointerToClass(declaredType: declaredType)
                || declaredType == "va_list"
        {
            return Parameter(
                identifier: name,
                type: .Raw(declaredType)
            )
        }

        guard let parameterType = Self.convert(
            type32: argument.type32,
            isConst: argument.isConst
        ) else {
            return nil
        }

        return Parameter(
            identifier: name,
            type: parameterType
        )
    }

    private static func convert(field: BridgeSupportParser.Field) -> CWriter.Field? {
        guard let type32 = field.type32 else {
            return nil
        }
        guard let typeDeclaration = type32.typeDeclaration(isConst: false) else {
            return nil
        }
        return CWriter.Field(
            identifier: field.name,
            type: .Declaration(typeDeclaration)
        )
    }

    private func convert(functionType: FunctionType) -> (returnType: CWriter.`Type`, parameters: [Parameter])? {
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
        for argument in functionType.arguments {
            guard let parameter = convert(
                argument: argument,
                name: argument.name
            ) else {
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
    private func orderedTypeDefinitions(_ definitions: [Definition]) -> [TypeDefinition] {

        var stack: [TypeDefinition] = []

        var structs: [String: BridgeSupportParser.Struct] = [:]
        var visitedStructs: [String: Bool] = [:]

        for definition in definitions {
            switch definition {
                case let .Class(`class`):
                    stack.append(.Class(`class`))

                case let .Opaque(opaque):
                    stack.append(.Opaque(opaque))

                case let .CoreFoundationType(coreFoundationType):
                    stack.append(.CoreFoundationType(coreFoundationType))

                case let .Struct(`struct`):
                    guard let type32 = `struct`.type32 else {
                        report("cannot generate struct definition '\(`struct`.name)': missing type")
                        continue
                    }

                    let name = type32.name

                    visitedStructs[name] = false

                    if let existing = structs[name] {
                        if type32 != existing.type32 {
                            report("different types for struct '\(name)': \(diff(existing.type32, type32))")
                        }
                        continue
                    }
                    structs[name] = `struct`

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
                if dependency != structName, let seen = visitedStructs[dependency], !seen {
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

    public mutating func generate(definitions: [Definition]) {

        headerOutput.write {
            LineComment("Generated by W2C2BridgeGenerator")

            Include(file: "stdarg.h", style: .AngularBrackets)

            Newline
        }

        // Generate type definitions

        for definition in orderedTypeDefinitions(definitions) {
            generate(typeDefinition: definition)
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

            case let .Enum(`enum`):
                generate(enum: `enum`)

            case let .Function(function):
                generate(function: function)

            case let .Constant(constant):
                generate(constant: constant)

            default:
                let kind = definition.label
                if !reportedUnsupportedDefinitionKinds.contains(kind) {
                    reportedUnsupportedDefinitionKinds.insert(kind)
                    report("unsupported definition: \(kind)")
                }
            }
        }
    }

    private mutating func generate(typeDefinition: TypeDefinition) {
        switch typeDefinition {
            case let .Struct(`struct`):
                generate(struct: `struct`)

            case let .Class(`class`):
                generate(class: `class`)

            case let .CoreFoundationType(coreFoundationType):
                generate(coreFoundationType: coreFoundationType)

            case let .Opaque(opaque):
                generate(opaque: opaque)
        }
    }

    private mutating func generate(struct: BridgeSupportParser.Struct) {
        guard let type32 = `struct`.type32 else {
            report("cannot generate struct definition '\(`struct`.name)': missing type")
            return
        }

        let name = type32.name

        do {
            try checkBridgeable(
                structType: type32,
                generateBigEndian: generateBigEndian
            )
        } catch let error {
            report("cannot generate struct '\(name)': \(error)")
            return
        }

        var fields: [CWriter.Field] = []
        for field in type32.fields {
            guard let field = Self.convert(field: field) else {
                report("cannot generate struct '\(name)': unsupported field: \(field)")
                return
            }
            fields.append(field)
        }

        let generateComments = generateComments
        headerOutput.write {
            if generateComments {
                LineComment("struct '\(name)'")
            }

            CWriter.Struct(
                identifier: name,
                body: { fields }
            )

            Newline
        }
    }

    private mutating func generate(class: BridgeSupportParser.Class) {
        let name = `class`.name

        guard !declaredClasses.contains(name) else {
            return
        }
        declaredClasses.insert(name)

        let generateComments = generateComments
        headerOutput.write {
            if generateComments {
                LineComment("class '\(name)'")
            }

            CWriter.Typedef(
                identifier: name,
                type: Type(struct: "objc_object")
            )

            Newline
        }
    }

    private mutating func generate(coreFoundationType: CoreFoundationType) {
        let name = coreFoundationType.name

        guard let type32 = coreFoundationType.type32 else {
            report("cannot generate CoreFoundation type '\(name)': missing type")
            return
        }
        guard case let .Pointer(innerType) = type32 else {
            report("cannot generate CoreFoundation type '\(name)': unsupported non-pointer type: \(type32)")
            return
        }

        let typeSpecifier: TypeDeclaration.TypeSpecifier
        switch innerType {
            case let .Struct(structType):
                guard structType.fields.isEmpty else {
                    report("cannot generate CoreFoundation type '\(name)': unsupported non-opaque struct type: \(structType)")
                    return
                }
                typeSpecifier = .Struct(structType.name)

            case .Void:
                typeSpecifier = .Name("void")

            default:
                report("cannot generate CoreFoundation type '\(name)': unsupported type: \(type32)")
                return
        }

        let generateComments = generateComments
        headerOutput.write {
            if generateComments {
                LineComment("CoreFoundation type '\(name)'")
            }

            CWriter.Typedef(
                identifier: name,
                type: .Declaration(TypeDeclaration(
                    typeSpecifier: typeSpecifier,
                    declarators: [.Pointer(isConst: false)]
                ))
            )

            Newline
        }
    }

    private mutating func generate(function: BridgeSupportParser.Function) {
        let name = function.name
        let functionType = function.functionType
        let kind = FunctionKind.Function(name: name)

        guard !declaredFunctions.contains(kind) else {
            return
        }
        declaredFunctions.insert(kind)

        guard !function.isVariadic else {
            report("cannot generate \(kind): variadic")
            return
        }

        do {
            try checkBridgeable(
                functionType: functionType,
                generateBigEndian: generateBigEndian
            )
        } catch let error {
            report("cannot generate \(kind): \(error)")
            return
        }

        // Convert function type

        guard case (let returnType, var parameters)? = convert(functionType: functionType) else {
            report("cannot generate \(kind): unsupported function type: \(functionType)")
            return
        }

        // Add void parameter to indicate empty parameter list
        if parameters.isEmpty {
            parameters.append(Parameter(type: .Void))
        }

        // Write function

        let generateComments = generateComments
        headerOutput.write {
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

        // Write symbol

        symbolsOutput?.write("\(name)\n")
    }

    private mutating func generate(method: Method, className: String) {
        let selector = method.selector
        let functionType = method.functionType
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

        guard !method.isVariadic else {
            report("cannot generate \(kind): variadic")
            return
        }

        do {
            try checkBridgeable(
                functionType: functionType,
                generateBigEndian: generateBigEndian
            )
        } catch let error {
            report("cannot generate \(kind): \(error)")
            return
        }

        let name = methodFunctionName(
            forClassName: className,
            selector: selector,
            isClassMethod: isClassMethod
        )

        // Return type

        guard case var (returnType, parameters)? = convert(functionType: functionType) else {
            report("cannot generate \(kind): unsupported function type: \(functionType)")
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
        headerOutput.write {
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

        // Write symbol

        symbolsOutput?.write("\(name)\n")
    }

    private mutating func generate(constant: Constant) {
        generate(getterForConstant: constant)
        if !constant.isConst {
            generate(setterForConstant: constant)
        }
    }

    private mutating func generate(getterForConstant constant: Constant) {
        let name = constant.name
        let kind = FunctionKind.ConstantGetter(name: name)

        let functionType = constantGetterFunctionType(constant)

        do {
            try checkBridgeable(
                functionType: functionType,
                generateBigEndian: generateBigEndian
            )
        } catch let error {
            report("cannot generate \(kind): \(error)")
            return
        }

        guard case let (returnType, _)? = convert(functionType: functionType) else {
            report("cannot generate \(kind): unsupported function type: \(functionType)")
            return
        }

        let generateComments = generateComments
        headerOutput.write {
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

    private mutating func generate(setterForConstant constant: Constant) {
        let name = constant.name
        let kind = FunctionKind.ConstantSetter(name: name)

        let functionType = constantSetterFunctionType(constant)

        do {
            try checkBridgeable(
                functionType: functionType,
                generateBigEndian: generateBigEndian
            )
        } catch let error {
            report("cannot generate \(kind): \(error)")
            return
        }

        guard case let (returnType, parameters)? = convert(functionType: functionType) else {
            report("cannot generate \(kind): unsupported function type: \(functionType)")
            return
        }

        let generateComments = generateComments
        headerOutput.write {
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

    private mutating func generate(enum: Enum) {
        let name = `enum`.name

        guard let value = `enum`.value32 ?? `enum`.value64 else {
            report("cannot generate enum '\(name)': missing value")
            return
        }

        headerOutput.write {
            if value.contains(".") {
                Raw("#define \(name) \(value)")
            } else {
                Raw("enum { \(name) = \(value) };")
            }
            Newline

            Newline
        }
    }

    private mutating func generate(opaque: Opaque) {
        let name = opaque.name

        guard let type32 = opaque.type32 else {
            report("cannot generate opaque type '\(name)': missing type")
            return
        }
        guard case let .Pointer(.Struct(structType)) = type32 else {
            report("cannot generate opaque type '\(name)': unsupported type: \(type32)")
            return
        }
        guard structType.fields.isEmpty else {
            report("cannot generate opaque type '\(name)': unsupported non-opaque struct type: \(structType)")
            return
        }

        let generateComments = generateComments
        headerOutput.write {
            if generateComments {
                LineComment("opaque '\(name)'")
            }

            CWriter.Typedef(
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
