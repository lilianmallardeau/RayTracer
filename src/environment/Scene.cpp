//
// Created by lilian on 09/01/2021.
//

#include "Scene.h"
#include <png++/png.hpp>

void Scene::render(int width, int height, std::string filename) {
    Point3D TopLeft = camera.getTopLeftCorner();
    Point3D TopRight = camera.getTopRightCorner();
    Point3D BottomLeft = camera.getBottomLeftCorner();
    Point3D BottomRight = camera.getBottomRightCorner();

    png::image<png::rgb_pixel> image(width, height);

    for (int y = 0; y < height; y++) {
        if (!(y % 10)) printf("Processing line %d/%d...\n", y, height);
        for (int x = 0; x < width; x++) {
            float width_ratio = (float) x/width;
            float height_ratio = (float) y/height;
            Point3D top = (1-width_ratio)*TopLeft + width_ratio*TopRight;
            Point3D bottom = (1-width_ratio)*BottomLeft + width_ratio*BottomRight;
            Vector3D direction = ((1-height_ratio)*top + height_ratio*bottom) - camera.position;
            Color c = computePixelColor(Ray(camera.position, direction));
            image[y][x] = png::rgb_pixel(c.r, c.g, c.b);
        }
    }
    image.write(filename);
}

Color Scene::computePixelColor(Ray ray, unsigned int depth) {
    Object* intersected_obj;
    float dist = INFINITY;
    for (auto obj : objects) {
        if (obj->is_hit(ray)) {
            float obj_dist = obj->compute_hit_dist(ray);
            if (obj_dist < dist) {
                dist = obj_dist;
                intersected_obj = obj;
            }
        }
    }
    if (dist == INFINITY)
        return background;
    else
        return intersected_obj->compute_color(ray, *this, depth);
}

void Scene::addObject(Object * obj) {
    objects.push_back(obj);
}