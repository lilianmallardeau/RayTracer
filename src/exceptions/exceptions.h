//
// Created by lilian on 17/01/2021.
//

#ifndef RAYTRACER_EXCEPTIONS_H
#define RAYTRACER_EXCEPTIONS_H

#include <exception>

/**
 * Exception thrown when trying to compute an non-existing intersection between an object and a ray
 */
class NoIntersectionException : public std::exception {
    const char * what() const noexcept override {
        return "Ray does not intersect object";
    }
};


#endif //RAYTRACER_EXCEPTIONS_H
