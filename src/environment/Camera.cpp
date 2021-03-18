//
// Created by lilian on 05/01/2021.
//

#include "Camera.h"

/**
 * Computes the center of the screen
 * @return the center of the screen
 */
Point3D Camera::getScreenCenter() {
    return position + screen_dist*direction;
}

/**
 * Computes the top left corner of the screen
 * @return the top left corner of the screen
 */
Point3D Camera::getTopLeftCorner() {
    return getScreenCenter() + (height/2)*up - (width/2)*right;
}

/**
 * Computes the top right corner of the screen
 * @return the top right corner of the screen
 */
Point3D Camera::getTopRightCorner() {
    return getScreenCenter() + (height/2)*up + (width/2)*right;
}

/**
 * Computes the bottom left corner of the screen
 * @return the bottom left corner of the screen
 */
Point3D Camera::getBottomLeftCorner() {
    return getScreenCenter() - (height/2)*up - (width/2)*right;
}

/**
 * Computes the bottom right corner of the screen
 * @return the bottom right corner of the screen
 */
Point3D Camera::getBottomRightCorner() {
    return getScreenCenter() - (height/2)*up + (width/2)*right;
}

std::ostream & operator<<(std::ostream & os, const Camera & cam) {
    os << "Camera(" << cam.position << ", " << cam.direction << ")";
    return os;
}

json Camera::toJSON() {
    return {
        {"position", position.toJSON()},
        {"direction", direction.toJSON()},
        {"up", up.toJSON()},
        {"right", right.toJSON()},
        {"screen_dist", screen_dist},
        {"width", width},
        {"height", height}
    };
}
