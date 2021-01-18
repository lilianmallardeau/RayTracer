//
// Created by lilian on 06/01/2021.
//

#include "Object.h"
#include "Scene.h"

Color Object::compute_color(Ray ray, Scene & scene, unsigned int depth = 1) {
    Point3D intersect = get_intersect(ray);
    Vector3D light_direction = (scene.light.position - intersect).normalize();
    Vector3D normal = get_normal(ray);

    bool inShadow = false;
    Ray ray_to_light = Ray(intersect + 1e-6*normal, light_direction);
    for (Object* obj : scene.objects) {
//        if (obj != this)
        if (obj->is_hit(ray_to_light) && obj->compute_hit_dist(ray_to_light) < ray_to_light.origin.dist(scene.light.position)) {
            inShadow = true;
            break;
        }
    }

    float Ia = matter.Ka * scene.brightness;
    float Id = 0, Is = 0;

    if (!inShadow) {
        Id = (normal * light_direction) * matter.Kd * scene.light.intensity;
        Vector3D R = (2*(normal*light_direction)*normal) - light_direction; //R = reflect(-ray_to_light);
        Is = matter.Ks * (R*(-ray.direction)) * scene.light.intensity; // TODO check signs here
    }
    float I = Ia + Id + Is;
    if (matter.shininess > 0 && depth < scene.depth) {
        return (1-matter.shininess)*I*getColor() + matter.shininess * scene.computePixelColor(reflect(ray), depth+1);
    } else {
        return I*getColor();
    }
}

float Object::compute_hit_dist(Ray ray) {
    return get_intersect(ray).dist(ray.origin);
}

Ray Object::reflect(Ray ray) {
    Vector3D normal = get_normal(ray);
    Vector3D direction = ray.direction - 2*(normal*ray.direction)*normal;
    return Ray(get_intersect(ray), direction);
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
