//
// Created by lilian on 09/01/2021.
//

#include "Color.h"

Color Color::operator+(const Color & c) {
    return Color(r+c.r, g+c.g, b+c.b);
}

Color Color::operator*(float m) {
    float max = (float) 255 / std::max(r, std::max(g, b));
    m = m < 0 ? 0 : m;
    m = m > max ? max : m;
    return Color(m*r, m*g, m*b);
}

Color operator*(float m, Color c) {
    return c*m;
}

std::ostream & operator<<(std::ostream & os, const Color & c) {
    os << "Color(" << c.r << ", " << c.g << ", " << c.b << ")";
    return os;
}

json Color::toJSON() {
    return {{"r", r}, {"g", g}, {"b", b}};
}