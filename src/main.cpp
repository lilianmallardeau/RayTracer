
#include <iostream>
#include "include/utils.h"
#include "include/objects.h"
#include "include/environment.h"
#include "ui/CommandLineInterface.h"

int main() {
//    CommandLineInterface CLI;
//    CLI.mainLoop();

    Camera cam(Point3D(0, 0, 25), Point3D(0), Point3D(0, 1, 0));
    Light light(Point3D(0, 4.5, 10));
    Scene scene(cam, light);

    Material m;

    Quad square1(Point3D(-5, -5, 0), Vector3D(0, 10 ,0), Vector3D(0,0,10));
    Quad square2(Point3D(-5, 5 , 0), Vector3D(10, 0 ,0), Vector3D(0,0,10));
    Quad square3(Point3D(5 , 5 , 0), Vector3D(0, -10,0), Vector3D(0,0,10));
    Quad square4(Point3D(5 , -5, 0), Vector3D(-10,0 ,0), Vector3D(0,0,10));
    Quad square5(Point3D(-5, -5, 0), Vector3D(10,0,0), Vector3D(0,10,0));
    Sphere sphere(Point3D(2, -2, 2), 2);
    Cube cube(Point3D(-3, 1, 0), Point3D(2.5, 0, 0), Point3D(0, 2.5, 0), Point3D(0, 0, 2.5));

    square1.matter = m;
    square2.matter = m;
    square3.matter = m;
    square4.matter = m;
    square5.matter = m;
    sphere.matter = m;
    cube.matter = m;
    sphere.setColor(Color(0, 0, 255));
    sphere.setShininess(0.5);
    cube.setColor(Color(50, 230, 0));
    cube.setShininess(0.5);

    scene.addObject(&square1);
    scene.addObject(&square2);
    scene.addObject(&square3);
    scene.addObject(&square4);
    scene.addObject(&square5);
    scene.addObject(&sphere);
    scene.addObject(&cube);

    scene.background = Color(100);
    scene.render(1000, 1000, "image.png");

    return 0;
}