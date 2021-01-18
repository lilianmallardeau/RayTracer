//
// Created by lilian on 17/01/2021.
//

#include "../src/include/utils.h"
#include "../src/include/objects.h"
#include "../src/include/environment.h"

int main() {
    Camera cam(Point3D(8, 0, 1), Point3D(0, 0, 1), Vector3D::k);
    Light light(0, 0, 5);
    light.intensity = 1.5;

    Scene scene(cam, light);
    scene.depth = 6;

    Sphere sphere1(Point3D(0, 1.5, 1), 1);
    sphere1.setColor(Color(0, 0, 200));
    sphere1.setShininess(0.7);

    Sphere sphere2(Point3D(0, -1.5, 1), 1);
    sphere2.setColor(Color(0, 200, 50));
    sphere2.setShininess(0.3);

//    Cube cube(Point3D(0,1.5,0), Vector3D(2,0,0), Vector3D(0,2,0), Vector3D(0,0,2));
//    cube.setColor(150);
//    cube.setShininess(0.5);

    Plane plane(Point3D(0, 0, 0), Point3D(0, 0, 1));
    plane.setColor(Color(100, 200, 200));

    scene.addObject(&sphere1);
    scene.addObject(&sphere2);
    //scene.addObject(&cube);
    scene.addObject(&plane);

    scene.render(1000, 1000, "example1.png");

    return 0;
}