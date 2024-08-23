#include<stdio.h>
#include<math.h>

#define ALBEDO 0.6f
#define INTENSITY 1.0f

typedef struct {
    float x, y, z;
} Vector3;

typedef struct {
    Vector3 origin;
    Vector3 direction;
} Ray;

typedef struct {
    Vector3 center;
    float radius;
} Sphere;

typedef struct {
    float r, g, b;
} Color;

typedef struct {
    Vector3 position;
    Vector3 direction;
} Camera;

Color defaultColor = (Color) {
    0.0, 0.0, 1.0
};

Vector3 add(Vector3 a, Vector3 b) {
    return (Vector3) {
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    };
}

Vector3 sub(Vector3 a, Vector3 b) {
    return (Vector3) {
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };
}

float dot(Vector3 a, Vector3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 cross(Vector3 a, Vector3 b) {
    return (Vector3) {
        (a.y * b.z) - (a.z * b.y),
        (a.z * b.x) - (a.x * b.z),
        (a.x * b.y) - (a.y * b.x)
    };
}

int intersect_ray_sphere(Ray ray, Sphere sphere, float *intersection_point) {
    Vector3 OC = sub(ray.origin, sphere.center);
    float a = dot(ray.direction, ray.direction);
    float b = 2.0f * dot(OC, ray.direction);
    float c = dot(OC, OC) - sphere.radius * sphere.radius;
    float determinant = b * b - 4 * a * c;
    if(determinant < 0) return 0;
    else {
        *intersection_point = (-b - sqrt(determinant)) / (2.0f * a);
        return 1;
    }
}


Color shade(Sphere sphere, Vector3 point, Vector3 normal, Vector3 light_direction) {
    int mod_normal = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
    Vector3 unit_normal = (Vector3) {
        normal.x / mod_normal,
        normal.y / mod_normal,
        normal.z / mod_normal
    }
    int mod_light_direction = sqrt(light_direction.x * light_direction.x + light_direction.y * light_direction.y + light_direction.z * light_direction.z);
    Vector3 unit_light_direction = (Vector3) {
        light_direction.x / mod_light_direction,
        light_direction.y / mod_light_direction,
        light_direction.z / mod_light_direction
    };
    float cosine = dot(unit_normal, unit_light_direction);
}


int main () {
    Ray ray = {{0, 0, 0}, {0, 0, -1}};
    Sphere sphere = {{0, 0, -5}, 1};
    float point;
    if(intersect_ray_sphere(ray, sphere, &point) != 1) {
        printf("Ray and Sphere don't intersect.");
    } else {
        printf("Ray and Sphere intersect.");
    }
    return 0;
}
