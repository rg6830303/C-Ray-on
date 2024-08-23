#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "compute.h"
#include "structs.h"
#include "rendering.h"

int main() {
    // Image dimensions
    int width = 800;
    int height = 800;

    // Camera setup
    Camera camera = {{0, 0, 1}, {0, 0, -1}};  // Move camera closer to sphere

    // Sphere setup
    Sphere sphere = {{0, 0, -5}, 1};  // Adjust position as needed

    Vector3 light_direction = {1.0f, -1.0f, -1.0f};

    // Sphere color
    Color sphere_color = {1.0f, 0.0f, 0.0f};

    // Render the image
    render(width, height, camera, sphere, light_direction, sphere_color);

    printf("Rendering complete. Image saved as result.ppm.\n");

    return 0;
}
