#include "w2c2_base.h"

extern wasmMemory* w2c2BridgeMemory(void* instance);

void env__MakePoint(void *_instance, U32 _resultIndirect, F32 x, F32 y) {
    wasmMemory* _mem = w2c2BridgeMemory(_instance);
    Point _result = (Point)MakePoint(x, y);
    #if WASM_ENDIAN == WASM_BIG_ENDIAN
    swap_f(&_result.x);
    swap_f(&_result.y);
    #endif
    *(Point*)(_mem->data + _resultIndirect) = _result;
}

U32 env__EqualPoints(void *_instance, U32 aPointIndirect, U32 bPointIndirect) {
    wasmMemory* _mem = w2c2BridgeMemory(_instance);
    Point _t1 = *(Point*)(_mem->data + aPointIndirect);
    Point _t2 = *(Point*)(_mem->data + bPointIndirect);
    #if WASM_ENDIAN == WASM_BIG_ENDIAN
    swap_f(&_t1.x);
    swap_f(&_t1.y);
    swap_f(&_t2.x);
    swap_f(&_t2.y);
    #endif
    bool _result = (bool)EqualPoints(_t1, _t2);
    return (U32)_result;
}

U32 env__EqualPointValues(void *_instance, U32 aPointPointer, U32 bPointPointer) {
    Point* _t1 = (Point*)aPointPointer;
    Point* _t2 = (Point*)bPointPointer;
    bool _result = (bool)EqualPointValues(_t1, _t2);
    return (U32)_result;
}

