//
// Created by lilian on 05/01/2021.
//

#ifndef RAYTRACER_VECTOR3D_H
#define RAYTRACER_VECTOR3D_H

#include "Serializable.h"

/**
 * Class for vectors used in the ray tracer
 */
class Vector3D : public Serializable {
    public:
        /** Coordinates of the vector */
        float x, y, z;

        /** Base unit vectors of the 3D space */
        static const Vector3D i, j, k;

    public:
        Vector3D(float x, float y, float z) : x(x), y(y), z(z) {};
        Vector3D(float x) : Vector3D(x, x, x) {};
        Vector3D() : Vector3D(0, 0, 0) {};
        Vector3D(const Vector3D & p) : Vector3D(p.x, p.y, p.z) {};
        Vector3D(Vector3D & p1, Vector3D & p2) : Vector3D(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z) {};
        Vector3D(json j) : Vector3D(j["x"], j["y"], j["z"]) {};
        Vector3D(std::string s) : Vector3D(json::parse(s)) {};

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Vector3D, x, y, z);

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

        /**
         * Computes the norm of a vector
         * @return the norm of the vector
         */
        float norm();

        /**
         * Normalizes the vector
         * @return the vector divided by its norm
         */
        Vector3D normalize();

        /**
         * Computes the distance between 2 vectors
         * @param p the vector to compute the distance from
         * @return the distance between the vector and p
         */
        float dist(Vector3D p);

        /**
         * Checks if 2 vectors are orthogonal
         * @param p vector to check if it is orthogonal with *this
         * @return true if the 2 vectors are orthogonal, false otherwise
         */
        bool normal(Vector3D p);

        /**
         * Computes the cross product between two vectors
         * @param p1 first vector
         * @param p2 second vector
         * @return the cross product p1 x p2
         */
        static Vector3D cross(Vector3D p1, Vector3D p2);

        /**
         * Computes the cross product between two vectors
         * @param p vector to cross product with
         * @return the cross product *this x p
         */
        Vector3D cross(Vector3D p);

        //static bool colinear(Vector3D, Vector3D);

        json toJSON() override;
};


typedef Vector3D Point3D;

#endif //RAYTRACER_VECTOR3D_H
