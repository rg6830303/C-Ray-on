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
int intersect_ray_spheres(Ray ray, Sphere* spheres, int sphere_count, float *t, Sphere *output) {
    float result = INFINITY;
    Sphere temp_output;
    for(int i = 0; i < sphere_count; i++) {
        float t1;
        float t2;
        if(intersect_ray_sphere(ray, spheres[i], &t1, &t2)) {
            float temp = t1 < t2 ? t1: t2;
            if(temp < result) {
                result = temp;
                temp_output = spheres[i];
            }
        }
    }
    if(result == INFINITY) return 0;
    *t = result;
    *output = temp_output;
    return 1;
}