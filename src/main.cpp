
#include <iostream>
#include "include/utils.h"
#include "include/objects.h"
#include "include/environment.h"
#include "ui/CommandLineInterface.h"

int main() {
//    CommandLineInterface CLI;
//    CLI.mainLoop();

    Camera cam(Point3D(25, 0, 10), Point3D(0, 0, 5));

    Scene scene(cam,Light(2,2,5));

    Sphere sphere(Point3D(0,0,3), 3);
    sphere.setColor(Color(0,0,255));
    sphere.matter.Ka = 1.7;

    Quad quad(Point3D(0,0,6), Point3D(-0.5, 0, 1), Vector3D(-1, 1, 0));
    quad.setColor(Color(255, 0, 0));

    Plane plane(Point3D(0,0,0), Point3D(0,0,1));
    plane.setColor(Color(100, 200, 200));

    scene.addObject(&sphere);
    scene.addObject(&plane);
    scene.addObject(&quad);

    scene.render(1000, 1000, "test.png");

    return 0;


    /*Camera cam(Point3D(0, 0, 25), Point3D(0), Vector3D::i);
    Light light(Point3D(0, 5, 10));
    Scene scene(cam, light);

    Material m;
    m.shininess = 1;

    Plane plane(Point3D(0), Vector3D::k);
    plane.setColor(Color(100));
    Quad square1(Point3D(-5, -5, 0), Vector3D(0, 10 ,0), Vector3D(0,0,10));
    Quad square2(Point3D(-5, 5 , 0), Vector3D(10, 0 ,0), Vector3D(0,0,10));
    Quad square3(Point3D(5 , 5 , 0), Vector3D(0, -10,0), Vector3D(0,0,10));
    Quad square4(Point3D(5 , -5, 0), Vector3D(-10,0 ,0), Vector3D(0,0,10));
    Quad square5(Point3D(-5, -5, 0), Vector3D(10,0,0), Vector3D(0,10,0));
    Sphere sphere(Point3D(0, 0, 2), 2);
    square1.matter = m;
    square2.matter = m;
    square3.matter = m;
    square4.matter = m;
    square5.matter = m;
    sphere.matter = m;
    sphere.setColor(Color(0,0,255));

    //scene.addObject(&plane);
    scene.addObject(&square1);
    scene.addObject(&square2);
    scene.addObject(&square3);
    scene.addObject(&square4);
    scene.addObject(&square5);
    scene.addObject(&sphere);

    scene.background = Color(100);
    scene.render(1000, 1000, "test.png");

    return 0;*/
}