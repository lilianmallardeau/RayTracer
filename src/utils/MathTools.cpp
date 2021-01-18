//
// Created by lilian on 17/01/2021.
//

#include "MathTools.h"
#include <cmath>
#include <utility>


bool solveQuadratic(const float &a, const float &b, const float &c, float &x0, float &x1) {
    float discr = b * b - 4 * a * c;
    if (discr < 0)
        return false;
    else if (discr == 0)
        x0 = x1 = - 0.5 * b / a;
    else {
        float q = (b > 0) ?
            -0.5 * (b + sqrt(discr)) :
            -0.5 * (b - sqrt(discr));
        x0 = q / a;
        x1 = c / q;
    }
    if (x0 > x1) std::swap(x0, x1);

    return true;
}

float orient(Vector3D a, Vector3D b, Vector3D c, Vector3D n) {
    return Vector3D::cross(b-a, c-a) * n;
}