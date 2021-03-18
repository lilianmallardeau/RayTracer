//
// Created by lilian on 02/03/2021.
//

#ifndef RAYTRACER_SERIALIZABLE_H
#define RAYTRACER_SERIALIZABLE_H

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Serializable {
    public:
        virtual json toJSON() = 0;

        virtual std::string serialize() {
            return toJSON().dump();
        }

        void serializeToFile(std::string filename);
};


#endif //RAYTRACER_SERIALIZABLE_H
