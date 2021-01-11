cmake_minimum_required(VERSION 3.17)
project(RayTracer)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/environment)
include_directories(src/include)
include_directories(src/objects)
include_directories(src/ui)
include_directories(src/utils)

add_executable(RayTracer
        src/environment/Camera.cpp
        src/environment/Camera.h
        src/environment/Ray.cpp
        src/environment/Ray.h
        src/environment/Scene.cpp
        src/environment/Scene.h
        src/include/environment.h
        src/include/objects.h
        src/include/utils.h
        src/objects/Object.cpp
        src/objects/Object.h
        src/objects/Quad.cpp
        src/objects/Quad.h
        src/objects/Sphere.cpp
        src/objects/Sphere.h
        src/ui/CommandLineInterface.cpp
        src/ui/CommandLineInterface.h
        src/utils/Color.cpp
        src/utils/Color.h
        src/utils/Material.cpp
        src/utils/Material.h
        src/utils/Vector3D.cpp
        src/utils/Vector3D.h
        src/main.cpp)