//
// Created by lilian on 09/01/2021.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H


class Color {
    public:
        unsigned char r, g, b;

    public:
        Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {};
        Color(unsigned char c) : r(c), g(c), b(c) {};
        Color() : r(0), g(0), b(0) {};
};


#endif //RAYTRACER_COLOR_H
