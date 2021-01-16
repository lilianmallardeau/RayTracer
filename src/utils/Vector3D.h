//
// Created by lilian on 05/01/2021.
//

#ifndef RAYTRACER_VECTOR3D_H
#define RAYTRACER_VECTOR3D_H

#include <iostream>

class Vector3D {
    public:
        float x, y, z;
        static const Vector3D i, j, k;

    public:
        Vector3D(float x, float y, float z) : x(x), y(y), z(z) {};
        Vector3D(float x) : Vector3D(x, x, x) {};
        Vector3D() : Vector3D(0, 0, 0) {};
        Vector3D(const Vector3D & p) : Vector3D(p.x, p.y, p.z) {};
        Vector3D(Vector3D & p1, Vector3D & p2) : Vector3D(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z) {};

        Vector3D operator+(const Vector3D &);
        Vector3D operator-(const Vector3D &);
        Vector3D operator-();
        Vector3D operator+(const float &);
        Vector3D operator-(const float &);
        Vector3D operator*(const float &);
        Vector3D operator/(const float &);
        float operator*(const Vector3D &);
        friend Vector3D operator*(const float &, Vector3D &);
        bool operator==(const Vector3D &);
        bool operator!=(const Vector3D &);
        friend std::ostream& operator<<(std::ostream &, const Vector3D &);

        float norm();
        Vector3D normalize();
        float dist(Vector3D p);
        bool normal(Vector3D p);
        static Vector3D cross(Vector3D, Vector3D);
        //static bool colinear(Vector3D, Vector3D);
        Vector3D cross(Vector3D p);
};


typedef Vector3D Point3D;

#endif //RAYTRACER_VECTOR3D_H
