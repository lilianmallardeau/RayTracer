//
// Created by lilian on 09/01/2021.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "../include/utils.h"
#include "../include/objects.h"
#include "../include/environment.h"

class Scene : public Serializable {
    public:
        /** The camera in the scene */
        Camera camera;

        /** The list of objects in the scene */
        std::list<Object*> objects;

        /** The light in the scene */
        Light light;

        /** The background color of the scene*/
        Color background;

        /** The brightness of the scene */
        float brightness = 1;

        /** The maximum number of ray reflexions */
        unsigned int depth = 4;

    public:
        Scene(Camera cam, Light light, Color bg) : camera(cam), light(light), background(bg) {};
        Scene(Camera cam, Light light) : Scene(cam, light, Color(100)) {};
        Scene(json j) : Scene(j["camera"], j["light"], j["background"]) {
            for (auto object : j["objects"]) {
                addObject(Object::fromJSON(object));
            }
            brightness = j["brightness"];
            depth = j["depth"];
        };
        Scene(std::string s) : Scene(json::parse(s)) {};

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Scene, camera, /*objects,*/ light, background, brightness, depth);

        /**
         * Render the scene and save the picture
         * @param width width of the picture to be saved
         * @param height height of the picture to be saved
         * @param filename filename of the file to be saved
         */
        void render(int width, int height, std::string filename);

        /**
         * Computes the color of the pixel corresponding to a ray
         * @param ray the ray going threw the camera to the pixel
         * @param depth the current number of reflexions
         * @return the color of the pixel corresponding to `ray`
         */
        Color computePixelColor(Ray ray, unsigned int depth = 1);

        /**
         * Adds object to the scene
         * @param obj pointer to the object to add in the scene
         */
        void addObject(Object * obj);

        virtual json toJSON() override;
};


#endif //RAYTRACER_SCENE_H
