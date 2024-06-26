#include "w2c2_base.h"
#include "wasi.h"

#include <stdio.h>
#include <objc/runtime.h>

#include "example.h"

// A simple String class, which does not use NSObject,
// so that we can avoid the need to link against Foundation
// (which requires dependencies on non-macOS platforms).

@interface String {
    id isa;
    const char* _raw;
}
+ (id) alloc;
- (id) initWithCString:(const char*)raw;
- (_Bool) isEqualToString:(String*)aString;
- (void) log;
@end

@implementation String

+ (void) initialize
{
    printf("host: +[String initialize]\n");
}

+ (id) alloc
{
    printf("host: +[String alloc]\n");
    return class_createInstance(self, 0);
}

- (id) initWithCString:(const char*)raw
{
    self->_raw = raw;
    printf("host: -[String initWithCString:]: %p, %s\n", self, raw);
    return self;
}

- (_Bool) isEqualToString:(String*)aString
{
    printf("host: -[String isEqualToString:]: %p, %p\n", self, aString);
    return strcmp(self->_raw, aString->_raw) == 0;
}

- (void) log
{
    printf("host: -[String log]: %p, %s\n", self, self->_raw);
}

@end

#include "../bridge/example.c"

wasmMemory* w2c2BridgeMemory(void* instance) {
    return example_memory((exampleInstance*)instance);
}

U32 env__w2c2BridgeMemoryOffset(void *_instance, U32 pointer) {
    if (!pointer) {
        return 0;
    }
    wasmMemory* _mem = w2c2BridgeMemory(_instance);
    return (U32)(_mem->data + pointer);
}

void
trap(
    Trap trap
) {
    fprintf(stderr, "TRAP: %s\n", trapDescription(trap));
    abort();
}

wasmMemory*
wasiMemory(
    void* instance
) {
    return example_memory((exampleInstance*)instance);
}

extern char** environ;

int main(int argc, char* argv[]) {
    exampleInstance instance;

    exampleInstantiate(&instance, NULL);

     if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
        return 1;
    }

    example__start(&instance);

    return 0;
}