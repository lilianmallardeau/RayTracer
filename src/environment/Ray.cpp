//
// Created by lilian on 05/01/2021.
//

#include "Ray.h"

//bool Ray::hit(Object obj) {
//    return obj.is_hit(*this);
//}
//
//Point3D Ray::intersect(Object obj) {
//    return obj.get_intersect(*this);
//}

std::ostream & operator<<(std::ostream & os, const Ray & ray) {
    os << "Ray(" << ray.origin << ", " << ray.direction << ")";
    return os;
}

json Ray::toJSON() {
    return {
        {"origin", origin.toJSON()},
        {"direction", direction.toJSON()}
    };
}
