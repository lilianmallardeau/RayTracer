//
// Created by lilian on 17/01/2021.
//

#ifndef RAYTRACER_CUBE_H
#define RAYTRACER_CUBE_H

#include <vector>
#include "Object.h"
#include "Quad.h"

class Cube : public Object {
    public:
        Point3D origin;
        Vector3D width, height, length;
    private:
        std::vector<Quad> faces;

    public:
        Cube(Point3D origin, Vector3D width, Vector3D height, Vector3D length);
        Cube(Point3D origin, Vector3D width, Vector3D height) : Cube(origin, width, height, Vector3D::cross(width, height)) {};

        bool is_hit(Ray ray) override;
        Point3D get_intersect(Ray ray) override;
        Vector3D get_normal(Ray ray) override;
        Ray reflect(Ray ray) override;

        Quad get_intersected_face(Ray ray);
};


#endif //RAYTRACER_CUBE_H
