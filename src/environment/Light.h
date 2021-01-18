//
// Created by lilian on 13/01/2021.
//

#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H

#include "../include/utils.h"

/**
 * Class for light objects
 */
class Light {
    public:
        /** Position of the light */
        Point3D position;

        /** Intensity of the light */
        float intensity = 1;

    public:
        Light(Point3D position) : position(position) {};
        Light(float x, float y, float z) : Light(Point3D(x, y, z)) {}
};


#endif //RAYTRACER_LIGHT_H
