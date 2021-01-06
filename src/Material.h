//
// Created by lilian on 06/01/2021.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


class Material {
    public:
        unsigned char r, g, b;
        float shininess;

    public:
        Material(unsigned char r, unsigned char g, unsigned char b, float shininess) : r(r), g(g), b(b), shininess(shininess) {};
};


#endif //RAYTRACER_MATERIAL_H
