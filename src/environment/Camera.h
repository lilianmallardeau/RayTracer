//
// Created by lilian on 05/01/2021.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "../utils/Vector3D.h"

class Camera {
    public:
        Point3D position;
        Vector3D direction;

    public:
        Camera(Point3D position, Vector3D direction) : position(position), direction(direction.normalize()) {};
        Camera(Point3D position) : position(position), direction(Vector3D(0, 0, 0)) {};
};


#endif //RAYTRACER_CAMERA_H
