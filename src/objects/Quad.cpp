//
// Created by lilian on 08/01/2021.
//

#include "Quad.h"
#include "Plane.h"

bool Quad::is_hit(Ray ray) {
    Vector3D normal = get_normal(ray);
    if (!Plane(origin, normal).is_hit(ray))
        return false;
    Point3D intersect = get_intersect(ray);
    Point3D p1 = origin;
    Point3D p2 = origin + width;
    Point3D p3 = origin + width + height;
    Point3D p4 = origin + height;
    bool o1 = std::signbit(orient(intersect, p1, p2, normal));
    bool o2 = std::signbit(orient(intersect, p2, p3, normal));
    bool o3 = std::signbit(orient(intersect, p3, p4, normal));
    bool o4 = std::signbit(orient(intersect, p4, p1, normal));
    return o1 == o2 && o1 == o3 && o1 == o4;
}

Point3D Quad::get_intersect(Ray ray) {
    Vector3D normal = get_normal(ray);
    return Plane(origin, normal).get_intersect(ray);
}

Vector3D Quad::get_normal(Ray ray) {
    Vector3D normal = Vector3D::cross(width, height).normalize();
    return Plane(origin, normal).get_normal(ray);
}

json Quad::toJSON() {
    json j = Object::toJSON();
    j.merge_patch({
        {"object", "quad"},
        {"origin", origin.toJSON()},
        {"width", width.toJSON()},
        {"height", height.toJSON()}
    });
    return j;
}