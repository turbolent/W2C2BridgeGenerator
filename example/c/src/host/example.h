#ifndef example_H
#define example_H

#ifdef __cplusplus
extern "C" {
#endif

#include "w2c2_base.h"

typedef struct exampleInstance {
wasmModuleInstance common;
wasmMemory* m0;
wasmTable t0;
U32 g0;
U32 g1;
} exampleInstance;

void env__MakePoint(void*,U32,F32,F32);

U32 env__EqualPoints(void*,U32,U32);

U32 env__w2c2BridgeMemoryOffset(void*,U32);

U32 env__EqualPointValues(void*,U32,U32);

U32 wasi_snapshot_preview1__fd_close(void*,U32);

U32 wasi_snapshot_preview1__fd_fdstat_get(void*,U32,U32);

U32 wasi_snapshot_preview1__fd_seek(void*,U32,U64,U32,U32);

U32 wasi_snapshot_preview1__fd_write(void*,U32,U32,U32,U32);

void wasi_snapshot_preview1__proc_exit(void*,U32);

void f9(exampleInstance*);

void f10(exampleInstance*);

U32 f11(exampleInstance*);

U32 f12(exampleInstance*,U32);

U32 f13(exampleInstance*,U32,U32);

U32 f14(exampleInstance*,U32,U64,U32,U32);

U32 f15(exampleInstance*,U32,U32,U32,U32);

void f16(exampleInstance*,U32);

void f17(exampleInstance*);

void f18(exampleInstance*);

U32 f19(exampleInstance*,U32,U32);

void f20(exampleInstance*);

U32 f21(exampleInstance*,U32);

U32 f22(exampleInstance*,U32);

U32 f23(exampleInstance*,U32,U32,U32);

U32 f24(exampleInstance*,U32,U32,U32);

U32 f25(exampleInstance*,U32);

U32 f26(exampleInstance*,U32,U32,U32);

U64 f27(exampleInstance*,U32,U64,U32);

U64 f28(exampleInstance*,U32,U64,U32);

U32 f29(exampleInstance*);

void f30(exampleInstance*);

U32 f31(exampleInstance*,U32);

U32 f32(exampleInstance*,U32,U32,U32);

U32 f33(exampleInstance*,U32,U32,U32,U32);

U32 f34(exampleInstance*,U32,U32);

U32 f35(exampleInstance*,U32,U32);

U32 f36(exampleInstance*,U32);

U32 f37(exampleInstance*,U32,U32,U32);

U32 f38(exampleInstance*,U32,U32);

F64 f39(exampleInstance*,F64,U32);

U32 f40(exampleInstance*,U32,U32);

void f41(exampleInstance*);

U32 f42(exampleInstance*,U32,U32,U32);

U32 f43(exampleInstance*,U32,U32,U32,U32,U32);

void f44(exampleInstance*,U32,U32,U32);

void f45(exampleInstance*,U32,U32,U32,U32,U32);

void f46(exampleInstance*);

U32 f47(exampleInstance*,U32,U32,U32);

U32 f48(exampleInstance*,U32,U32,U32);

U32 f49(exampleInstance*,U32);

U32 f50(exampleInstance*,U32,U32,U32);

U32 f51(exampleInstance*,U32,U32);

wasmMemory*example_memory(exampleInstance* i);

void example__start(exampleInstance*i);

void exampleInstantiate(exampleInstance* instance, void* resolve(const char* module, const char* name));

void exampleFreeInstance(exampleInstance* instance);

#ifdef __cplusplus
}
#endif

#endif /* example_H */

