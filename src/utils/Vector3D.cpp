//
// Created by lilian on 05/01/2021.
//

#include <cmath>
#include <iostream>
#include "Vector3D.h"

const Vector3D Vector3D::i(1, 0, 0);
const Vector3D Vector3D::j(0, 1, 0);
const Vector3D Vector3D::k(0, 0, 1);

Vector3D Vector3D::operator+(const Vector3D & v) {
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D Vector3D::operator-(const Vector3D & v) {
    return Vector3D(x - v.x, y - v.y, z - v.z);
}

Vector3D Vector3D::operator-() {
    return Vector3D(-x, -y, -z);
}

Vector3D Vector3D::operator+(const float & m) {
    return *this + Vector3D(m, m, m);
}

Vector3D Vector3D::operator-(const float & m) {
    return *this + (-m);
}

Vector3D Vector3D::operator*(const float & m) {
    return Vector3D(m*x, m*y, m*z);
}

Vector3D Vector3D::operator/(const float & m) {
    return Vector3D(x/m, y/m, z/m);
}

Vector3D operator*(const float & m, Vector3D & p) {
    return p*m;
}

float Vector3D::operator*(const Vector3D & v) {
    return x*v.x + y*v.y + z*v.z;
}

bool Vector3D::operator==(const Vector3D & v) {
    return v.x == x && v.y == y && v.z == z;
}

bool Vector3D::operator!=(const Vector3D & v) {
    return !(*this == v);
}

std::ostream& operator<<(std::ostream & os, const Vector3D & v) {
    os << "Vector3D(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

float Vector3D::norm() {
    return sqrt((*this) * (*this));
}

Vector3D Vector3D::normalize() {
    return (*this) / norm();
}

float Vector3D::dist(Vector3D p) {
    // return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) + (z-p.z)*(z-p.z));
    return (*this - p).norm();
}

bool Vector3D::normal(Vector3D p) {
    return *this * p == 0;
}

Vector3D Vector3D::cross(Vector3D p1, Vector3D p2) {
    return Vector3D(p1.y*p2.z - p1.z*p2.y, p1.z*p2.x - p1.x*p2.z, p1.x*p2.y - p1.y*p2.x);
}

Vector3D Vector3D::cross(Vector3D p) {
    return Vector3D::cross(*this, p);
}