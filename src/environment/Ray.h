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
        /** Origin of the ray */
        Point3D origin;

        /** Direction of the ray */
        Vector3D direction;

    public:
        Ray(Point3D origin, Vector3D direction) : origin(origin), direction(direction.normalize()) {};
//        bool hit(Object obj);
//        Point3D intersect(Object obj);

        friend std::ostream & operator<<(std::ostream &, const Ray &);
};


#endif //RAYTRACER_RAY_H
