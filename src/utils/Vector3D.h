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
        Vector3D(const Vector3D & p) : x(p.x), y(p.y), z(p.z) {};
        Vector3D(Vector3D & p1, Vector3D & p2) : x(p2.x - p1.x), y(p2.y - p1.y), z(p2.z - p1.z) {};
        Vector3D operator+(const Vector3D &);
        Vector3D operator-(const Vector3D &);
        Vector3D operator*(const float &);
        Vector3D operator/(const float &);
        friend Vector3D operator*(const float &, Vector3D &);
        float operator*(const Vector3D &);
        float norm();
        Vector3D normalize();
        float dist(Vector3D p);
};


typedef Vector3D Point3D;

#endif //RAYTRACER_VECTOR3D_H
