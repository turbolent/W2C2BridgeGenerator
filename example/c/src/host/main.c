#include "w2c2_base.h"
#include "wasi.h"
#include <stdio.h>

#include "example.h"

struct _Point {
    float x;
    float y;
};
typedef struct _Point Point;

Point MakePoint(float x, float y) {
    return (Point){.x = x, .y = y};
}

bool EqualPoints(Point aPoint, Point bPoint) {
    return aPoint.x == bPoint.x && aPoint.y == bPoint.y;
}

bool EqualPointValues(Point* aPoint, Point* bPoint) {
    return aPoint && bPoint && aPoint->x == bPoint->x && aPoint->y == bPoint->y;
}

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