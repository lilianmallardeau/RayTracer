//
// Created by lilian on 09/01/2021.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "../include/utils.h"
#include "../include/environment.h"

class Scene {
    public:
        Camera camera;
        Objects[] objects;
        Ray source;

    public:
        render(int width, int height, std::string filename);
};


#endif //RAYTRACER_SCENE_H
