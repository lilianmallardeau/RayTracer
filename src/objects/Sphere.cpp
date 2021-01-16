//
// Created by lilian on 08/01/2021.
//

#include "Sphere.h"
#include <cmath>

bool Sphere::is_hit(Ray ray) {
    float a = ray.direction * ray.direction;
    float b = 2 * ray.direction * (ray.origin - center);
    float c = (ray.origin - center) * (ray.origin - center) - radius*radius;
    float delta = b*b - 4*a*c;
    if (delta < 0)
        return false;
    else {
        float t1 = (-b - sqrt(delta)) / (2*a);
        float t2 = (-b + sqrt(delta)) / (2*a);
        return t1 >= 0 || t2 >= 0;
    }
}

Point3D Sphere::get_intersect(Ray ray) {
    float a = ray.direction * ray.direction;
    float b = 2 * ray.direction * (ray.origin - center);
    float c = (ray.origin - center) * (ray.origin - center) - radius*radius;
    float delta = b*b - 4*a*c;
    float t1 = (-b - sqrt(delta)) / (2*a);
    float t2 = (-b + sqrt(delta)) / (2*a);
    if (t1 < 0 && t2 < 0)
        throw "Ray does not intersect sphere";
    float t = t1 < 0 ? t2 : t1;
    return ray.origin + t*ray.direction;
}

Ray Sphere::reflect(Ray ray) {
    if (!is_hit(ray))
        throw "Ray does not intersect sphere";
    Point3D intersect = get_intersect(ray);
    Vector3D normal = Vector3D(center, intersect).normalize();
    return Ray(intersect, 2*(normal*ray.direction)*normal - ray.direction);
}

Vector3D Sphere::get_normal(Point3D p) {
    return (p - center).normalize();
}