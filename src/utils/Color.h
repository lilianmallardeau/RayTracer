//
// Created by lilian on 09/01/2021.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include <ostream>

/**
 * Class for colors
 */
class Color {
    public:
        unsigned char r, g, b;

    public:
        Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {};
        Color(unsigned char c) : Color(c, c, c) {};
        Color() : Color(0) {};

        Color operator+(const Color &);
        Color operator*(float);
        friend Color operator*(float, Color);
        friend std::ostream & operator<<(std::ostream &, const Color &);
};


#endif //RAYTRACER_COLOR_H
