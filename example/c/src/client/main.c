#include <stdbool.h>
#include <stdio.h>

#include "../bridge/example.h"

extern void* w2c2BridgeMemoryOffset(void*);

int main() {
    struct _Point point1 = MakePoint(1.0, 2.0);
    struct _Point point2 = MakePoint(3.0, 4.0);
    struct _Point point3 = MakePoint(1.0, 2.0);

    printf("client: point1: %f %f\n", point1.x, point1.y);
    printf("client: point2: %f %f\n", point2.x, point2.y);
    printf("client: point3: %f %f\n", point3.x, point3.y);

    printf("client: EqualPoints(point1, point2): %d\n", EqualPoints(point1, point2));
    printf("client: EqualPoints(point2, point3): %d\n", EqualPoints(point2, point3));
    printf("client: EqualPoints(point1, point3): %d\n", EqualPoints(point1, point3));

    printf("client: EqualPointValues(point1, point2): %d\n", EqualPointValues(w2c2BridgeMemoryOffset(&point1), w2c2BridgeMemoryOffset(&point2)));
    printf("client: EqualPointValues(point2, point3): %d\n", EqualPointValues(w2c2BridgeMemoryOffset(&point2), w2c2BridgeMemoryOffset(&point3)));
    printf("client: EqualPointValues(point1, point3): %d\n", EqualPointValues(w2c2BridgeMemoryOffset(&point1), w2c2BridgeMemoryOffset(&point3)));

    printf("client: EqualPointValues(point1, NULL): %d\n", EqualPointValues(w2c2BridgeMemoryOffset(&point1), NULL));
    printf("client: EqualPointValues(NULL, point2): %d\n", EqualPointValues(NULL, w2c2BridgeMemoryOffset(&point2)));
    printf("client: EqualPointValues(NULL, NULL): %d\n", EqualPointValues(NULL, NULL));
}
