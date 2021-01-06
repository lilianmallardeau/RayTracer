//
// Created by lilian on 05/01/2021.
//

#include "Vector3D.h"

Vector3D Vector3D::operator+(const Vector3D & v) {
    Vector3D vector(x + v.x, y + v.y, z + v.z);
    return vector;
}

Vector3D Vector3D::operator-(const Vector3D & v) {
    Vector3D vector(x - v.x, y - v.y, z - v.z);
    return vector;
}

Vector3D Vector3D::operator*(const float & m) {
    return Vector3D(m*x, m*y, m*z);
}

Vector3D Vector3D::operator/(const float & m) {
    return Vector3D(m/x, m/y, m/z);
}

float Vector3D::operator*(const Vector3D & v) {
    return x*v.x + y*v.y + z*v.z;
}

