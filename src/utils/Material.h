//
// Created by lilian on 06/01/2021.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "Color.h"

class Material {
    public:
        Color color;
        float shininess;

    public:
        Material(Color color, float shininess) : color(color), shininess(shininess) {};
        Material(unsigned char r, unsigned char g, unsigned char b, float shininess) : color(Color(r, g, b)), shininess(shininess) {};
        Material(unsigned char c, float shininess) : color(Color(c)), shininess(shininess) {};
        Material() : color(Color(0, 0, 0)), shininess(0) {};
};


#endif //RAYTRACER_MATERIAL_H
