#include <iostream>
#include <chrono>
#include <string>
#include <cstdlib>

#include "BMPImage.hpp"
#include "Camera.hpp"
#include "Scene/Scene.hpp"
#include "Scene/Sphere.hpp"
#include "Scene/Plane.hpp"
#include "Scene/Triangle.hpp"

const size_t IMAGE_WIDTH = 1920;
const size_t IMAGE_HEIGHT = 1080;
const char* IMAGE_FILE_NAME = "tmp.bmp";
const size_t SAMPLE_PER_PIXEL = 64;
const size_t MAX_DEPTH = 6;

vec3f trace(const Scene& scene, const Ray& ray, size_t level)
{
    if (level >= MAX_DEPTH) return vec3f(0.);
    Hit hit;
    if (!scene.nearestIntersect(ray, hit))
        return scene.defaultMaterial.color;
    Ray reflect(hit.point, RandomUnitVectorInHemisphereOf(hit.normal));
    return hit.material.color + 0.3 * trace(scene, reflect, level + 1);
}

int main()
{
    auto startTimePoint = std::chrono::high_resolution_clock::now();
    BMPImage oImage(IMAGE_WIDTH, IMAGE_HEIGHT, vec4ub(0, 127, 0, 255));
    Camera camera(vec3f(0, 0, 0), vec3f(0, 1, 0), vec3f(0, 0, 1), 3.1415926 / 3);
    Scene scene;
    scene.defaultMaterial.color = vec3f(.25, .4, .66);
    scene.primitives.push_back(new Sphere(vec3f(0, 0, 2.5), Material(vec3f(.5, .5, .5), .5), 1.));
    scene.primitives.push_back(new Plane(vec3f(0, -.5, 0), vec3f(0., 1., 0.), Material(vec3f(.2, .2, .2), .5)));
    scene.primitives.push_back(new Plane(vec3f(0, -.5, 0), vec3f(1., 1., 0.), Material(vec3f(.2, .32, .2), .5)));
    scene.primitives.push_back(new Triangle(vec3f(-5., 0, 5), vec3f(0., 5., 5), vec3f(5., 0., 5), Material(vec3f(.2, .7, .2), .5)));
    

    for (size_t y = 0; y < IMAGE_HEIGHT; ++y)
    {
        for (size_t x = 0; x < IMAGE_WIDTH; ++x)
        {
            Ray ray = camera.getRay((2. * x) / IMAGE_WIDTH - 1., (2. * y) / IMAGE_HEIGHT - 1.);
            ray.near = 0.1;
            vec3f clr(0.);
            for (size_t i = 0; i < SAMPLE_PER_PIXEL; ++i)
                clr = clr + trace(scene, ray, 0).clamp(0., 1.);
            clr = clr / SAMPLE_PER_PIXEL;
            oImage.setPixel(x, y, vec4ub(clr.x * 255, clr.y * 255, clr.z * 255, 255));
        }
    }

    oImage.changeEndian();
    oImage.SaveBMPImage(IMAGE_FILE_NAME);

    auto endTimePoint = std::chrono::high_resolution_clock::now();
    std::cout << "Time elapsed - " << std::chrono::duration_cast<std::chrono::milliseconds>(endTimePoint - startTimePoint).count() / 1000. << "s." << std::endl;
    system((std::string("explorer ") + IMAGE_FILE_NAME).c_str());

    return 0;
}