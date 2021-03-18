//
// Created by lilian on 13/01/2021.
//

#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H

#include "../include/utils.h"

/**
 * Class for light objects
 */
class Light : public Serializable {
    public:
        /** Position of the light */
        Point3D position;

        /** Intensity of the light */
        float intensity = 1;

    public:
        Light(Point3D position) : position(position) {};
        Light(Point3D position, float intensity) : position(position), intensity(intensity) {};
        Light(float x, float y, float z) : Light(Point3D(x, y, z)) {}
        Light(json j) : Light(j["position"], j["intensity"]) {};
        Light(std::string s) : Light(json::parse(s)) {};

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Light, position, intensity);

        json toJSON() override;
};


#endif //RAYTRACER_LIGHT_H
