//
// Created by lilian on 05/01/2021.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "../utils/Vector3D.h"

/**
 * Class for cameras objects
 */
class Camera : public Serializable {
    public:
        /** Position of the camera */
        Point3D position;

        /** Direction of the camera */
        Vector3D direction;

        /** Vector indicating the top of the camera. Should be orthogonal with `direction` */
        Vector3D up;

        /** Vector indicating the right of the camera. Should be orthogonal with `up` and `direction` */
        Vector3D right;

        /** Distance between the screen and the camera */
        float screen_dist = 10;

        /** Width of the screen */
        float width = 10;

        /** Height of the screen */
        float height = 10;

    public:
        Camera(Point3D position, Point3D direction, Vector3D up, Vector3D right) : position(position), direction((direction-position).normalize()), up(up.normalize()), right(right.normalize()) {};
        Camera(Point3D position, Point3D direction, Vector3D up) : Camera(position, direction, up, Vector3D::cross(direction-position, up)) {};
        Camera(Point3D position, Point3D direction) : Camera(position, direction, Vector3D::k) {}
        Camera(json j) : Camera(j["position"], j["direction"], j["up"], j["right"]) {
            screen_dist = j["screen_dist"];
            width = j["width"];
            height = j["height"];
        };
        Camera(std::string s) : Camera(json::parse(s)) {};

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Camera, position, direction, up, right, screen_dist, width, height);

        Point3D getScreenCenter();
        Point3D getTopLeftCorner();
        Point3D getTopRightCorner();
        Point3D getBottomLeftCorner();
        Point3D getBottomRightCorner();

        friend std::ostream & operator<<(std::ostream &, const Camera &);

        json toJSON() override;
};


#endif //RAYTRACER_CAMERA_H
