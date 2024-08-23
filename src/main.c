#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// #include "main.h"
#include "compute.h"
#include "structs.h"
#include "rendering.h"

// Vector3 add(Vector3 a, Vector3 b) {
//     return (Vector3) {
//         a.x + b.x,
//         a.y + b.y,
//         a.z + b.z
//     };
// }

// Vector3 sub(Vector3 a, Vector3 b) {
//     return (Vector3) {
//         a.x - b.x,
//         a.y - b.y,
//         a.z - b.z
//     };
// }

// float dot(Vector3 a, Vector3 b) {
//     return a.x * b.x + a.y * b.y + a.z * b.z;
// }

// Vector3 cross(Vector3 a, Vector3 b) {
//     return (Vector3) {
//         (a.y * b.z) - (a.z * b.y),
//         (a.z * b.x) - (a.x * b.z),
//         (a.x * b.y) - (a.y * b.x)
//     };
// }

// Vector3 normalize(Vector3 a) {
//     float mod = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
//     return (Vector3) {
//         a.x / mod,
//         a.y / mod,
//         a.z / mod
//     };
// }

// Vector3 scale(Vector3 a, float scale) {
//     return (Vector3) {
//         a.x * scale,
//         a.y * scale,
//         a.z * scale
//     };
// }

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


// Color shade(Sphere sphere, Vector3 point, Vector3 normal, Vector3 light_direction, Color value) {
//     Vector3 unit_normal = normalize(normal);
//     Vector3 unit_light_direction = normalize(light_direction);
//     float cosine = dot(unit_normal, unit_light_direction);
//     if(cosine < 0) cosine = 0;
//     Color color = (Color) {
//         value.r * cosine,
//         value.g * cosine,
//         value.b * cosine
//     };
//     color.r = fminf(fmaxf(color.r, 0.0f), 1.0f);
//     color.g = fminf(fmaxf(color.g, 0.0f), 1.0f);
//     color.b = fminf(fmaxf(color.b, 0.0f), 1.0f);
//     return color;
// }

// void render(int width, int height, Camera camera, Sphere sphere, Vector3 light_direction, Color value) {
//     Color *image = malloc(width * height * sizeof(Color));
//     if(image == NULL) {
//         fprintf(stderr, "Memory allocation failed.\n");
//         exit(1);
//     }
//     for(int y = 0; y < height; y++) {
//         for(int x = 0; x < width; x++) {
//             float u = (float)x / (width - 1) * 2.0f - 1.0f;
//             float v = (float)y / (height - 1) * 2.0f - 1.0f;
//             Ray ray;
//             ray.origin = camera.position;
//             ray.direction = normalize((Vector3){u, v, -1.0f});
//             float t1, t2;
//             if(intersect_ray_sphere(ray, sphere, &t1, &t2)) {
//                 float t = t1 < t2 ? t1 : t2;
//                 Vector3 intersection = add(ray.origin, scale(ray.direction, t));
//                 Vector3 normal = normalize(sub(intersection, sphere.center));
//                 Color color = shade(sphere, intersection, normal, light_direction, value);
//                 image[y * width + x] = color;
//             } else {
//                 image[y * width + x] = (Color) {0.5294f, 0.8078f, 0.9216f};
//             }
//         }
//     }
//     save_ppm_format(image, width, height);
// }

// void save_ppm_format(Color *image, int width, int height) {
//     FILE *fptr = fopen("result.ppm", "wb");
//     if(fptr == NULL) {
//         fprintf(stderr, "Failed to open file.\n");
//         exit(2);
//     }
//     fprintf(fptr, "P6\n%d %d\n255\n", width, height);
//     for(int i = 0; i < width * height; i++) {
//         unsigned char r = (unsigned char) (image[i].r * 255);
//         unsigned char g = (unsigned char) (image[i].g * 255);
//         unsigned char b = (unsigned char) (image[i].b * 255);
//         fwrite(&r, 1, 1, fptr);
//         fwrite(&g, 1, 1, fptr);
//         fwrite(&b, 1, 1, fptr);
//     }
//     fclose(fptr);
// }


int main() {
    // Image dimensions
    int width = 800;
    int height = 800;

    // Camera setup
    Camera camera = {{0, 0, 1}, {0, 0, -1}};  // Move camera closer to sphere

    // Sphere setup
    Sphere sphere = {{0, 0, -5}, 1};  // Adjust position as needed

    Vector3 light_direction = sub(camera.position, sphere.center);
    light_direction = normalize(light_direction);

    // Sphere color
    Color sphere_color = {1.0f, 0.0f, 0.0f};

    // Render the image
    render(width, height, camera, sphere, light_direction, sphere_color);

    printf("Rendering complete. Image saved as result.ppm.\n");

    return 0;
}
