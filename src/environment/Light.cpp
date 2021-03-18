//
// Created by lilian on 13/01/2021.
//

#include "Light.h"

json Light::toJSON() {
    return {
        {"position", position.toJSON()},
        {"intensity", intensity}
    };
}
