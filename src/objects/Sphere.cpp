//
// Created by lilian on 08/01/2021.
//

#include "Sphere.h"

bool Sphere::is_hit(Ray ray) {
    float a = ray.direction * ray.direction;
    float b = 2 * ray.direction * (ray.origin - center);
    float c = (ray.origin - center) * (ray.origin - center) - radius*radius;
    float t1, t2;
    if (!solveQuadratic(a, b, c, t1, t2))
        return false;
    else
        return t1 >= 0 || t2 >= 0;
}

Point3D Sphere::get_intersect(Ray ray) {
    float a = ray.direction * ray.direction;
    float b = 2 * ray.direction * (ray.origin - center);
    float c = (ray.origin - center) * (ray.origin - center) - radius*radius;
    float t1, t2;
    if (!solveQuadratic(a, b, c, t1, t2))
        throw NoIntersectionException();
    if (t1 < 0 && t2 < 0)
        throw NoIntersectionException();
    float t = t1 < 0 ? t2 : t1;
    return ray.origin + t*ray.direction;
}

Vector3D Sphere::get_normal(Ray ray) {
    return (get_intersect(ray) - center).normalize();
}

json Sphere::toJSON() {
    json j = Object::toJSON();
    j.merge_patch({
        {"object", "sphere"},
        {"center", center.toJSON()},
        {"radius", radius}
    });
    return j;
}
