//
// Created by lilian on 05/01/2021.
//

#include "Camera.h"

Point3D Camera::getScreenCenter() {
    return position + screen_dist*direction;
}

Point3D Camera::getTopLeftCorner() {
    return getScreenCenter() + (height/2)*up - (width/2)*right;
}

Point3D Camera::getTopRightCorner() {
    return getScreenCenter() + (height/2)*up + (width/2)*right;
}

Point3D Camera::getBottomLeftCorner() {
    return getScreenCenter() - (height/2)*up - (width/2)*right;
}

Point3D Camera::getBottomRightCorner() {
    return getScreenCenter() - (height/2)*up + (width/2)*right;
}

std::ostream & operator<<(std::ostream & os, const Camera & cam) {
    os << "Camera(" << cam.position << ", " << cam.direction << ")";
    return os;
}