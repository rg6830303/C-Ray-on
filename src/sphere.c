#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "compute.h"
#include "sphere.h"

int intersect_ray_sphere(Ray ray, Sphere sphere, float *t1, float *t2) {
    Vector3 OC = sub(ray.origin, sphere.center);
    float a = dot(ray.direction, ray.direction);
    float b = 2.0f * dot(OC, ray.direction);
    float c = dot(OC, OC) - sphere.radius * sphere.radius;
    float determinant = b * b - 4 * a * c;
    if(determinant < 0) return 0;
    else {
        *t1 = (-b - sqrt(determinant)) / (2.0f * a);
        *t2 = (-b + sqrt(determinant)) / (2.0f * a);
        return 1;
    }
}