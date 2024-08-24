#ifndef SPHERE_H
#define SPHERE_H

#include "structs.h"
int intersect_ray_sphere(Ray ray, Sphere sphere, float *t1, float *t2);
int intersect_ray_spheres(Ray ray, Sphere* spheres, int sphere_count, float *t, Sphere *output);

#endif