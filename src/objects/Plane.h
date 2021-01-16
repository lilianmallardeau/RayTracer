//
// Created by lilian on 14/01/2021.
//

#ifndef RAYTRACER_PLANE_H
#define RAYTRACER_PLANE_H

#include "Object.h"

class Plane : public Object {
    public:
        Point3D point;
    private:
        Vector3D normal;

    public:
        Plane(Point3D point, Vector3D normal) : point(point), normal(normal.normalize()) {};

        bool is_hit(Ray ray) override;
        Point3D get_intersect(Ray ray) override;
        Ray reflect(Ray ray) override;
        Vector3D get_normal(Point3D p) override;
};



#endif //RAYTRACER_PLANE_H
