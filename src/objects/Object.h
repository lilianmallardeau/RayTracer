//
// Created by lilian on 06/01/2021.
//

#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H

#include "../Material.h"
#include "../Ray.h"

class Object {
    public:
        Material matter;
    public:
        virtual bool is_hit(Ray ray) = 0;
        virtual Ray reflect(Ray ray) = 0;
};


#endif //RAYTRACER_OBJECT_H
