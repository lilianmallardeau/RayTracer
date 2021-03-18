//
// Created by lilian on 08/01/2021.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Object.h"

class Sphere : public Object {
    public:
        Point3D center;
        float radius;

    public:
        Sphere(Point3D center, float radius) : center(center), radius(radius) {
            type = ObjectType::SPHERE;
        };
        Sphere(json j) : Sphere(j["center"], j["radius"]) {
            initFromJSON(j);
        };
        Sphere(std::string s) : Sphere(json::parse(s)) {};

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Sphere, name, material, center, radius);

        bool is_hit(Ray ray) override;
        Point3D get_intersect(Ray ray) override;
        Vector3D get_normal(Ray ray) override;

        json toJSON() override;
};


#endif //RAYTRACER_SPHERE_H
