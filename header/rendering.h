#ifndef RENDERING_H
#define RENDERING_H

#include "structs.h"

int intersect_ray_sphere(Ray ray, Sphere sphere, float *t1, float *t2);
Color shade(Sphere sphere, Vector3 point, Vector3 normal, Vector3 light_direction, Color value);
void render(int width, int height, Camera camera, Sphere sphere, Vector3 light_direction, Color value);

#endif