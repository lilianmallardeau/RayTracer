//
// Created by lilian on 05/01/2021.
//

#include <cmath>
#include <iostream>
#include "Vector3D.h"

Vector3D Vector3D::operator+(const Vector3D & v) {
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D Vector3D::operator-(const Vector3D & v) {
    return Vector3D(x - v.x, y - v.y, z - v.z);
}

Vector3D Vector3D::operator*(const float & m) {
    return Vector3D(m*x, m*y, m*z);
}

Vector3D Vector3D::operator/(const float & m) {
    return Vector3D(m/x, m/y, m/z);
}

Vector3D operator*(const float & m, Vector3D & p) {
    return p*m;
}

float Vector3D::operator*(const Vector3D & v) {
    return x*v.x + y*v.y + z*v.z;
}

float Vector3D::norm() {
    return sqrt(*this * *this);
}

Vector3D Vector3D::normalize() {
    return *this / norm();
}

float Vector3D::dist(Vector3D p) {
    return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) + (z-p.z)*(z-p.z));
}

std::ostream& operator<<(std::ostream & os, const Vector3D & v) {
    os << "Vector3D(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}