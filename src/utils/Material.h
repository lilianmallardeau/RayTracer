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
        float Ka = 1, Kd = 1, Ks = 1;

    public:
        Material(Color color, float shininess) : color(color), shininess(shininess) {};
        Material(unsigned char r, unsigned char g, unsigned char b, float shininess) : Material(Color(r, g, b), shininess) {};
        Material(unsigned char c, float shininess) : Material(Color(c), shininess) {};
        Material() : Material(Color(255), 0) {};

        friend std::ostream & operator<<(std::ostream &, const Material &);
};


#endif //RAYTRACER_MATERIAL_H
