//
// Created by lilian on 05/01/2021.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "../include/utils.h"

/**
 * Class for rays
 */
class Ray {
    public:
        /** Origin of the ray */
        Point3D origin;

        /** Direction of the ray */
        Vector3D direction;

    public:
        Ray(Point3D origin, Vector3D direction) : origin(origin), direction(direction.normalize()) {};

        friend std::ostream & operator<<(std::ostream &, const Ray &);
};


#endif //RAYTRACER_RAY_H
