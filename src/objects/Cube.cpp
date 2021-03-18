//
// Created by lilian on 17/01/2021.
//

#include "Cube.h"

Cube::Cube(Point3D origin, Vector3D width, Vector3D height, Vector3D length) : origin(origin), width(width), height(height), length(length) {
    faces.push_back(Quad(origin, width, height));
    faces.push_back(Quad(origin, width, length));
    faces.push_back(Quad(origin, height, length));
    Point3D s = origin + width + height + length;
    faces.push_back(Quad(s, -width, -height));
    faces.push_back(Quad(s, -width, -length));
    faces.push_back(Quad(s, -height, -length));
}

bool Cube::is_hit(Ray ray) {
    for (Quad face : faces) {
        if (face.is_hit(ray))
            return true;
    }
    return false;
}

Point3D Cube::get_intersect(Ray ray) {
    return get_intersected_face(ray).get_intersect(ray);
}

Vector3D Cube::get_normal(Ray ray) {
    return get_intersected_face(ray).get_normal(ray);
}

Ray Cube::reflect(Ray ray) {
    return get_intersected_face(ray).reflect(ray);
}

Quad Cube::get_intersected_face(Ray ray) {
    float dist = INFINITY;
    Quad *intersected_face = nullptr;
    for (Quad face : faces) {
        if (face.is_hit(ray)) {
            float d = face.compute_hit_dist(ray);
            if (d < dist) {
                dist = d;
                intersected_face = &face;
            }
        }
    }
    if (intersected_face == nullptr)
        //throw "Ray does not intersect Cube";
        throw NoIntersectionException();
    return *intersected_face;
}

json Cube::toJSON() {
    json j = Object::toJSON();
    j.merge_patch({
        {"object", "cube"},
        {"origin", origin.toJSON()},
        {"width", width.toJSON()},
        {"height", height.toJSON()},
        {"length", length.toJSON()}
    });
    return j;
}
