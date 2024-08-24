#ifndef RENDERING_H
#define RENDERING_H

#include "structs.h"

Color shade(Sphere sphere, Vector3 point, Vector3 normal, Vector3 light_direction, Color value);
void render(int width, int height, Camera camera, Sphere sphere, Vector3 light_direction, Color value);

#endif