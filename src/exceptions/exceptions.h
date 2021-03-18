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


/**
 * Exception thrown when trying to build object from JSON which has unknown "object" attribute
 */
 // TODO: UnknownObjectException could take object type name (and update in Object::fromJSON)
class UnknownObjectException : public std::exception {
    const char * what() const noexcept override {
        return "Unknown object type";
    }
};


#endif //RAYTRACER_EXCEPTIONS_H
