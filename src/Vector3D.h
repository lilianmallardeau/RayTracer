//
// Created by lilian on 05/01/2021.
//

#ifndef RAYTRACER_VECTOR3D_H
#define RAYTRACER_VECTOR3D_H


class Vector3D {
    public:
        float x, y, z;

    public:
        Vector3D(float x, float y, float z) : x(x), y(y), z(z) {};
        Vector3D() : Vector3D(0, 0, 0) {};
        Vector3D operator+(const Vector3D &);
        Vector3D operator-(const Vector3D &);
        Vector3D operator*(const float &);
        Vector3D operator/(const float &);
        float operator*(const Vector3D &);
};


typedef Vector3D Point3D;

#endif //RAYTRACER_VECTOR3D_H
