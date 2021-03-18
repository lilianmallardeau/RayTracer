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
        src/environment/Light.cpp
        src/environment/Light.h
        src/objects/Plane.cpp
        src/objects/Plane.h
        src/exceptions/exceptions.h
        src/utils/MathTools.cpp
        src/utils/MathTools.h
        src/objects/Cube.cpp
        src/objects/Cube.h
        src/utils/Serializable.cpp
        src/utils/Serializable.h
        src/main.cpp)

# PNG++ library
find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})

# JSON library
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(src/lib/json)

target_link_libraries(RayTracer ${PNG_LIBRARY} nlohmann_json::nlohmann_json)