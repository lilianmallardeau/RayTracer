//
// Created by lilian on 06/01/2021.
//

#include "Material.h"

std::ostream &operator<<(std::ostream & os, const Material & mat) {
    os << "Material(" << mat.color << ", " << mat.shininess << ")";
    return os;
}

json Material::toJSON() {
    return {
        {"color", color.toJSON()},
        {"shininess", shininess},
        {"alpha", alpha},
        {"Ka", Ka},
        {"Kd", Kd},
        {"Ks", Ks}
    };
}
