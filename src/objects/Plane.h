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
        Plane(Point3D point, Vector3D normal) : point(point), normal(normal.normalize()) {
            type = ObjectType::PLANE;
        };
        Plane(json j) : Plane(j["point"], j["normal"]) {
            initFromJSON(j);
        };
        Plane(std::string s) : Plane(json::parse(s)) {};

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Plane, name, material, point, normal);

        bool is_hit(Ray ray) override;
        Point3D get_intersect(Ray ray) override;
        Vector3D get_normal(Ray ray) override;

        json toJSON() override;
};



#endif //RAYTRACER_PLANE_H
