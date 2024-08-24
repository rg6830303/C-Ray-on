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
    Sphere sphere1 = {{0, 0, -5}, 1};
    Sphere sphere2 = {{-3, -1, -5}, 1};
    Sphere sphere3 = {{3, 1, -5}, 1};
    Scene scene = (Scene){
        (Sphere[]){sphere1, sphere2, sphere3}
    };
    Vector3 light_direction = {0.0f, 0.0f, 1.0f};
    Color sphere_color = {1.0f, 0.0f, 0.0f};
    printf("Listing the contents of the scene.\n");
    for(int i = 0; i < 3; i++) {
        printf("(Sphere) Center: %f %f %f, Radius: %f\n", scene.spheres[i].center.x, scene.spheres[i].center.y, scene.spheres[i].center.z, scene.spheres[i].radius);
    }
    printf("Starting rendering...\n");
    render(width, height, camera, scene, 3, light_direction, sphere_color);
    printf("Rendering complete. Image saved as result.ppm.\n");
    return 0;
}
