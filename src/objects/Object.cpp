//
// Created by lilian on 06/01/2021.
//

#include "Object.h"

Color Object::compute_color(Ray ray, Light light, float brightness, std::list<Object*> objects) {
    Point3D intersect = get_intersect(ray);
    Vector3D light_direction = (light.position - intersect).normalize();
    Vector3D normal = get_normal(intersect);

    bool inShadow = false;
    Ray ray_to_light = Ray(intersect, light_direction);
    for (Object* obj : objects) {
        if (obj->is_hit(ray_to_light) && obj->compute_hit_dist(ray) < intersect.dist(light.position)) {
            inShadow = true;
            break;
        }
    }

    float Ia = matter.Ka * brightness;
    float Id = 0, Is = 0;

    if (!inShadow) {
        Id = (normal * light_direction) * matter.Kd; // * light.intensity
        Vector3D R = (2*(normal*light_direction)*normal) - light_direction;
        Is = matter.Ks * (R*(-ray.direction));
    }
    float I = Ia + Id + Is;
    return I*getColor();
}

float Object::compute_hit_dist(Ray ray) {
    return get_intersect(ray).dist(ray.origin);
}

float Object::getShininess() {
    return matter.shininess;
}

Color Object::getColor() {
    return matter.color;
}

void Object::setShininess(float s) {
    matter.shininess = s;
}

void Object::setColor(Color c) {
    matter.color = c;
}