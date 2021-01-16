//
// Created by lilian on 09/01/2021.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "../include/utils.h"
#include "../include/objects.h"
#include "../include/environment.h"

class Scene {
    public:
        Camera camera;
        std::list<Object*> objects;
        Light light;
        float brightness = 1;
        Color background;

    public:
        Scene(Camera cam, Light light, Color bg) : camera(cam), light(light), background(bg) {};
        Scene(Camera cam, Light light) : Scene(cam, light, Color(100)) {};
        void render(int width, int height, std::string filename);
        Color computePixelColor(Ray ray);
        void addObject(Object * obj);
};


#endif //RAYTRACER_SCENE_H
