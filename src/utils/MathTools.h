//
// Created by lilian on 17/01/2021.
//

#ifndef RAYTRACER_MATHTOOLS_H
#define RAYTRACER_MATHTOOLS_H

#include "Vector3D.h"

/**
 * Solves a quadratic equation ax²+bx+c = 0
 * @param a coefficient of degree 2
 * @param b coefficient of degree 1
 * @param c constant
 * @param x0 reference to first solution
 * @param x1 reference to second solution
 * @return true if equation has real solution(s), false otherwise
 */
bool solveQuadratic(const float &a, const float &b, const float &c, float &x0, float &x1);

float orient(Vector3D, Vector3D, Vector3D, Vector3D);

#endif //RAYTRACER_MATHTOOLS_H
