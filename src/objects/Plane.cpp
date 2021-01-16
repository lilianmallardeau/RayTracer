//
// Created by lilian on 14/01/2021.
//

#include "Plane.h"

bool Plane::is_hit(Ray ray) {
    if (ray.direction * normal == 0)
        return false;
    float t = ((point-ray.origin)*normal)/(ray.direction*normal);
    return t >= 0;
}

Point3D Plane::get_intersect(Ray ray) {
    float t = ((point-ray.origin)*normal)/(ray.direction*normal);
    return ray.origin + t*ray.direction;
}

Ray Plane::reflect(Ray ray) {
    return Ray(get_intersect(ray), ray.direction + 2 * (ray.direction*normal) * normal / pow(normal.norm(), 2));
}

Vector3D Plane::get_normal(Point3D p) {
    return normal;
}