#include "w2c2_base.h"

extern wasmMemory* w2c2BridgeMemory(void* instance);

U32 env__objc_getClass(void *_instance, U32 namePointer) {
    const char* _t1 = (const char*)namePointer;
    id _result = (id)objc_getClass(_t1);
    return (U32)_result;
}

U32 env___CM_String_alloc(void *_instance, U32 _class) {
    id _result = (id)[(Class)_class alloc];
    return (U32)_result;
}

U32 env___IM_String_initWithCString_C(void *_instance, U32 _self, U32 rawPointer) {
    const char* _t1 = (const char*)rawPointer;
    id _result = (id)[(String*)_self initWithCString:_t1];
    return (U32)_result;
}

U32 env___IM_String_isEqualToString_C(void *_instance, U32 _self, U32 aStringPointer) {
    id _t1 = (id)aStringPointer;
    _Bool _result = (_Bool)[(String*)_self isEqualToString:_t1];
    return (U32)_result;
}

void env___IM_String_log(void *_instance, U32 _self) {
    [(String*)_self log];
}

