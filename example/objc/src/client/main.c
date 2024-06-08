#include <stdbool.h>
#include <stdio.h>

typedef struct objc_object *id;
typedef struct objc_class *Class;
struct objc_object {
    Class isa;
};

typedef signed char BOOL;

#include "../bridge/example.h"

extern void* w2c2BridgeMemoryOffset(void*);

int main() {

    Class StringClass = (Class)objc_getClass(w2c2BridgeMemoryOffset("String"));

    String *string = (String *)_IM_String_initWithCString_C(
        _CM_String_alloc(StringClass),
        w2c2BridgeMemoryOffset("Hello, world!")
    );

    _IM_String_log(string);
    printf("client: equal: %d\n", _IM_String_isEqualToString_C(string, string));
}
