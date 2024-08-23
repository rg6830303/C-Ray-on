#ifndef COMPUTE_H
#define COMPUTE_H

#include "structs.h"

Vector3 add(Vector3 a, Vector3 b);
Vector3 sub(Vector3 a, Vector3 b);
float dot(Vector3 a, Vector3 b);
Vector3 cross(Vector3 a, Vector3 b);
Vector3 normalize(Vector3 a);
Vector3 scale(Vector3 a, float scale);

#endif