#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "compute.h"

Vector3 add(Vector3 a, Vector3 b) {
    return (Vector3) {
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    };
}

Vector3 sub(Vector3 a, Vector3 b) {
    return (Vector3) {
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };
}

float dot(Vector3 a, Vector3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 cross(Vector3 a, Vector3 b) {
    return (Vector3) {
        (a.y * b.z) - (a.z * b.y),
        (a.z * b.x) - (a.x * b.z),
        (a.x * b.y) - (a.y * b.x)
    };
}

Vector3 normalize(Vector3 a) {
    float mod = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
    return (Vector3) {
        a.x / mod,
        a.y / mod,
        a.z / mod
    };
}

Vector3 scale(Vector3 a, float scale) {
    return (Vector3) {
        a.x * scale,
        a.y * scale,
        a.z * scale
    };
}