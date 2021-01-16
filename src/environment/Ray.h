//
// Created by lilian on 05/01/2021.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "../include/utils.h"
//#include "../include/objects.h"
//class Object;

class Ray {
    public:
        Point3D origin;
        Vector3D direction;

    public:
        //TODO
        Ray(Point3D origin, Vector3D direction) : origin(origin), direction(direction.normalize()) {};
//        bool hit(Object obj);
//        Point3D intersect(Object obj);

        friend std::ostream & operator<<(std::ostream &, const Ray &);
};


#endif //RAYTRACER_RAY_H
