# W2C2BridgeGenerator

A tool for generating bridging code for [w2c2](https://github.com/turbolent/w2c2) from [`bridgesupport` files ("Framework Metadata")](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/RubyPythonCocoa/Articles/GenerateFrameworkMetadata.html).

W2C2BridgeGenerator generates:
- C interface code that can be used in a WebAssembly module
- C/Objective-C code implementing the interface, bridging passed arguments to the host and bridging the result back to the WebAssembly module

At the moment, only hosts that match the WebAssembly architecture are supported, i.e., 32-bit little-endian systems.

## Compilation

```sh
swift build -c release
cp .build/release/W2C2BridgeGeneratorCommand w2c2-bridge-gen
```

## Usage

Example:

```sh
./w2c2-bridge-gen --c-interface Foundation.h --w2c2-implementation Foundation.m --comments FoundationFull.bridgesupport
```

Help:

```
OVERVIEW: Generate bindings for w2c2 from a bridgesupport file

USAGE: w2c2-bridge-gen [--module-name <module-name>] [--w2c2-implementation <w2c2-implementation>] [--c-interface <c-interface>] <input-files> ... [--comments] [--no-comments]

ARGUMENTS:
  <input-files>           bridgesupport files

OPTIONS:
  --module-name <module-name>
                          module name (default: env)
  --w2c2-implementation <w2c2-implementation>
                          generate w2c2 implementation file (C/Objective-C)
  --c-interface <c-interface>
                          generate C interface file (header)
  --comments/--no-comments
                          generate comments (default: --no-comments)
  -h, --help              Show help information.
```
