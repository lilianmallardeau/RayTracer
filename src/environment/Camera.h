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
        Vector3D up;
        Vector3D right;
        float screen_dist = 10;
        float width = 10, height = 10;

    public:
        Camera(Point3D position, Point3D direction, Vector3D up, Vector3D right) : position(position), direction((direction-position).normalize()), up(up.normalize()), right(right.normalize()) {};
        Camera(Point3D position, Point3D direction, Vector3D up) : Camera(position, direction, up, Vector3D::cross(direction-position, up)) {};
        Camera(Point3D position, Point3D direction) : Camera(position, direction, Vector3D(0, 0, 1)) {}

        Point3D getScreenCenter();
        Point3D getTopLeftCorner();
        Point3D getTopRightCorner();
        Point3D getBottomLeftCorner();
        Point3D getBottomRightCorner();

        friend std::ostream & operator<<(std::ostream &, const Camera &);
};


#endif //RAYTRACER_CAMERA_H
