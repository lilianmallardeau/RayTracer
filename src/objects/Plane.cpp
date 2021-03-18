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

Vector3D Plane::get_normal(Ray ray) {
    return normal * ray.direction <= 0 ? normal : -normal;
}

json Plane::toJSON() {
    json j = Object::toJSON();
    j.merge_patch({
        {"object", "plane"},
        {"point", point.toJSON()},
        {"normal", normal.toJSON()}
    });
    return j;
}
