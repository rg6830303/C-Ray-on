#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "compute.h"
#include "structs.h"
#include "rendering.h"

int main() {
    int width = 800;
    int height = 800;
    Camera camera = {{0, 0, 1}, {0, 0, -1}};
    Sphere sphere = {{0, 0, -5}, 1}; 
    Vector3 light_direction = {1.0f, -1.0f, -1.0f};
    Color sphere_color = {1.0f, 0.0f, 0.0f};
    render(width, height, camera, sphere, light_direction, sphere_color);
    printf("Rendering complete. Image saved as result.ppm.\n");
    return 0;
}
