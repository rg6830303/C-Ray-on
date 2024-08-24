#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rendering.h"
#include "compute.h"
#include "output.h"
#include "sphere.h"

// int intersect_ray_sphere(Ray ray, Sphere sphere, float *t1, float *t2) {
//     Vector3 OC = sub(ray.origin, sphere.center);
//     float a = dot(ray.direction, ray.direction);
//     float b = 2.0f * dot(OC, ray.direction);
//     float c = dot(OC, OC) - sphere.radius * sphere.radius;
//     float determinant = b * b - 4 * a * c;
//     if(determinant < 0) return 0;
//     else {
//         *t1 = (-b - sqrt(determinant)) / (2.0f * a);
//         *t2 = (-b + sqrt(determinant)) / (2.0f * a);
//         return 1;
//     }
// }

Color shade(Sphere sphere, Vector3 point, Vector3 normal, Vector3 light_direction, Color value) {
    Vector3 unit_normal = normalize(normal);
    Vector3 unit_light_direction = normalize(light_direction);
    float cosine = dot(unit_normal, unit_light_direction);
    if(cosine < 0) cosine = 0;
    Color color = (Color) {
        value.r * cosine,
        value.g * cosine,
        value.b * cosine
    };
    color.r = fminf(fmaxf(color.r, 0.0f), 1.0f);
    color.g = fminf(fmaxf(color.g, 0.0f), 1.0f);
    color.b = fminf(fmaxf(color.b, 0.0f), 1.0f);
    return color;
}

void render(int width, int height, Camera camera, Sphere sphere, Vector3 light_direction, Color value) {
    Color *image = malloc(width * height * sizeof(Color));
    if(image == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            float u = (float)x / (width - 1) * 2.0f - 1.0f;
            float v = (float)y / (height - 1) * 2.0f - 1.0f;
            Ray ray;
            ray.origin = camera.position;
            ray.direction = normalize((Vector3){u, v, -1.0f});
            float t1, t2;
            if(intersect_ray_sphere(ray, sphere, &t1, &t2)) {
                float t = t1 < t2 ? t1 : t2;
                Vector3 intersection = add(ray.origin, scale(ray.direction, t));
                Vector3 normal = normalize(sub(intersection, sphere.center));
                Color color = shade(sphere, intersection, normal, light_direction, value);
                image[y * width + x] = color;
            } else {
                image[y * width + x] = (Color) {0.5294f, 0.8078f, 0.9216f};
            }
        }
    }
    save_ppm_format(image, width, height);
}