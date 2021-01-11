//
// Created by lilian on 05/01/2021.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "../utils/Vector3D.h"

class Ray {
    public:
        Point3D origin;
        Vector3D direction;

    public:
        Ray(Point3D origin, Vector3D direction) : origin(origin), direction(direction.normalize()) {};
};


#endif //RAYTRACER_RAY_H
