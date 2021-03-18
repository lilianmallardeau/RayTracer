//
// Created by lilian on 06/01/2021.
//

#include "Object.h"
#include "../environment/Scene.h"

Color Object::compute_color(Ray ray, Scene & scene, unsigned int depth = 1) {
    Point3D intersect = get_intersect(ray);
    Vector3D light_direction = (scene.light.position - intersect).normalize();
    Vector3D normal = get_normal(ray);

    bool inShadow = false;
    Ray ray_to_light = Ray(intersect + 1e-4*normal, light_direction);
    for (Object* obj : scene.objects) {
        if (obj->is_hit(ray_to_light) && obj->compute_hit_dist(ray_to_light) < intersect.dist(scene.light.position)) {
            inShadow = true;
            break;
        }
    }

    float Ia = material.Ka * scene.brightness;
    float Id = 0, Is = 0;

    if (!inShadow) {
        //Id = material.Kd * scene.light.intensity * std::max(0.0f, normal * light_direction);
        Id = material.Kd * scene.light.intensity * (normal * light_direction);

        // Phong calculation
        Vector3D R = (2*(normal*light_direction)*normal) - light_direction; //R = reflect(-ray_to_light);
        Is = material.Ks * scene.light.intensity * pow(R * (-ray.direction), material.alpha);

        // Blinn-Phong calculation
        //Vector3D h = (light_direction - ray.direction).normalize();
        //Is = material.Ks * scene.light.intensity * std::max(0.0f, normal * h);
    }
    float I = Ia + Id + Is;
    if (material.shininess > 0 && depth < scene.depth) {
        return (1 - material.shininess) * I * getColor() + material.shininess * scene.computePixelColor(reflect(ray), depth + 1);
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
    return Ray(get_intersect(ray) + 1e-4*normal, direction);
}

float Object::getShininess() {
    return material.shininess;
}

Color Object::getColor() {
    return material.color;
}

void Object::setShininess(float s) {
    material.shininess = s;
}

void Object::setColor(Color c) {
    material.color = c;
}

Object* Object::fromJSON(json obj) {
    if (!obj.contains("object"))
        throw UnknownObjectException();
    if (obj["object"] == "sphere")
        return new Sphere(obj);
    else if (obj["object"] == "quad")
        return new Quad(obj);
    else if (obj["object"] == "plane")
        return new Plane(obj);
    else if (obj["object"] == "cube")
        return new Cube(obj);
    else
        throw UnknownObjectException();
}

json Object::toJSON() {
    return {
        {"name", name},
        {"material", material.toJSON()}
    };
}

void Object::initFromJSON(json j) {
    name = j["name"];
    material = j["material"];
}