//
// Created by lilian on 06/01/2021.
//

#ifndef RAYTRACER_OBJECT_H
#define RAYTRACER_OBJECT_H

#include "../include/utils.h"
#include "../environment/Ray.h"
#include "../environment/Light.h"

class Object {
    public:
        Material matter;
        std::string name;

    public:
        Object() : matter(Material()) {};

        virtual bool is_hit(Ray ray) = 0;
        virtual Point3D get_intersect(Ray ray) = 0;
        float compute_hit_dist(Ray ray);
        virtual Ray reflect(Ray ray) = 0;
        virtual Color compute_color(Ray ray, Light light, float brightness, std::list<Object*>);
        virtual Vector3D get_normal(Point3D p) = 0;

        float getShininess();
        Color getColor();

        void setShininess(float s);
        void setColor(Color c);
};


#endif //RAYTRACER_OBJECT_H
