//
// Created by lilian on 05/01/2021.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "../include/utils.h"

/**
 * Class for rays
 */
class Ray : public Serializable {
    public:
        /** Origin of the ray */
        Point3D origin;

        /** Direction of the ray */
        Vector3D direction;

    public:
        Ray(Point3D origin, Vector3D direction) : origin(origin), direction(direction.normalize()) {};
        Ray(json j) : Ray(j["origin"], j["direction"]) {};
        Ray(std::string s) : Ray(json::parse(s)) {};

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Ray, origin, direction);

        friend std::ostream & operator<<(std::ostream &, const Ray &);

        json toJSON() override;
};


#endif //RAYTRACER_RAY_H
