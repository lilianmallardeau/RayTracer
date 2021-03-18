//
// Created by lilian on 06/01/2021.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "Serializable.h"
#include "Color.h"

class Material : public Serializable {
    public:
        /** The color of the object */
        Color color;

        /** Shininess of the object: 0 = opaque, 1 = totally shiny */
        float shininess = 0;

        float alpha = 30;
        float Ka = .2, Kd = .4, Ks = .4;

    public:
        Material(Color color, float shininess) : color(color), shininess(std::max(0.0f, std::min(1.0f, shininess))) {};
        Material(Color color) : color(color) {};
        Material(unsigned char r, unsigned char g, unsigned char b, float shininess) : Material(Color(r, g, b), shininess) {};
        Material(unsigned char r, unsigned char g, unsigned char b) : Material(Color(r, g, b)) {};
        Material(unsigned char c, float shininess) : Material(Color(c), shininess) {};
        Material() : Material(Color(255)) {};
        Material(json j) : Material(Color(j["color"]), j["shininess"]) {
            alpha = j["alpha"];
            Ka = j["Ka"];
            Kd = j["Kd"];
            Ks = j["Ks"];
        };
        Material(std::string s) : Material(json::parse(s)) {};

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Material, color, shininess, alpha, Ka, Kd, Ks);

        friend std::ostream & operator<<(std::ostream &, const Material &);

        json toJSON() override;
};


#endif //RAYTRACER_MATERIAL_H
