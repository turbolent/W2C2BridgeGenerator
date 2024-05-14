#include "w2c2_base.h"

extern wasmMemory* w2c2BridgeMemory(void* instance);

void env__MakePoint(void *_instance, U32 _resultIndirect, F32 x, F32 y) {
    wasmMemory* _mem = w2c2BridgeMemory(_instance);
    struct _Point _result = (struct _Point)MakePoint(x, y);
    #if WASM_ENDIAN == WASM_BIG_ENDIAN
    swap_f(&_result.x);
    swap_f(&_result.y);
    #endif
    *(struct _Point*)(_mem->data + _resultIndirect) = _result;
}

U32 env__EqualPoints(void *_instance, U32 aPointIndirect, U32 bPointIndirect) {
    wasmMemory* _mem = w2c2BridgeMemory(_instance);
    struct _Point _t1 = *(struct _Point*)(_mem->data + aPointIndirect);
    struct _Point _t2 = *(struct _Point*)(_mem->data + bPointIndirect);
    #if WASM_ENDIAN == WASM_BIG_ENDIAN
    swap_f(&_t1.x);
    swap_f(&_t1.y);
    swap_f(&_t2.x);
    swap_f(&_t2.y);
    #endif
    _Bool _result = (_Bool)EqualPoints(_t1, _t2);
    return (U32)_result;
}

U32 env__EqualPointValues(void *_instance, U32 aPointPointer, U32 bPointPointer) {
    struct _Point* _t1 = (struct _Point*)aPointPointer;
    struct _Point* _t2 = (struct _Point*)bPointPointer;
    _Bool _result = (_Bool)EqualPointValues(_t1, _t2);
    return (U32)_result;
}

