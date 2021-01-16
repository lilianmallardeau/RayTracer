//
// Created by lilian on 13/01/2021.
//

#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H

#include "../include/utils.h"

class Light {
    public:
        Point3D position;

    public:
        Light(Point3D position) : position(position) {};
        Light(float x, float y, float z) : Light(Point3D(x, y, z)) {}
};


#endif //RAYTRACER_LIGHT_H
