//
// Created by lilian on 08/01/2021.
//

#ifndef RAYTRACER_QUAD_H
#define RAYTRACER_QUAD_H

#include "Object.h"

class Quad : public Object {
    public:
        Point3D origin;
        Vector3D width, height;

    public:
        Quad(Point3D origin, Vector3D width, Vector3D height) : origin(origin), width(width), height(height) {};

        bool is_hit(Ray ray) override;
        Point3D get_intersect(Ray ray) override;
        Ray reflect(Ray ray) override;
        Vector3D get_normal(Point3D p) override;

        float orient(Vector3D, Vector3D, Vector3D, Vector3D);
};


#endif //RAYTRACER_QUAD_H
