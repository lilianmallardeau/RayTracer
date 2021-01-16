//
// Created by lilian on 08/01/2021.
//

#include "Quad.h"
#include "Plane.h"

//bool Quad::is_hit(Ray ray) {
//    Vector3D normal = Vector3D::cross(width, height);
//    if (!Plane(origin, normal).is_hit(ray))
//        return false;
//    Point3D intersect = get_intersect(ray);
//    Point3D p1 = origin;
//    Point3D p2 = origin + width;
//    Point3D p3 = origin + height;
//    float x = (intersect-p1)*(p2-p1) / (p2-p1).norm();
//    float y = (intersect-p1)*(p3-p1) / (p3-p1).norm();
//    return x >= 0 && x <= 1 && y >= 0 && y <= 1;
//}

bool Quad::is_hit(Ray ray) {
    Vector3D normal = Vector3D::cross(width, height).normalize();
    // if (normal * ray.direction < 0) normal = -normal;
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
    Vector3D normal = Vector3D::cross(width, height);
    return Plane(origin, normal).get_intersect(ray);
}

Ray Quad::reflect(Ray ray) {
    Vector3D normal = Vector3D::cross(width, height);
    return Plane(origin, normal).reflect(ray);
}

Vector3D Quad::get_normal(Point3D p) {
    return Vector3D::cross(width, height).normalize();
}

float Quad::orient(Vector3D a, Vector3D b, Vector3D c, Vector3D n) {
    return Vector3D::cross(b-a, c-a) * n;
}