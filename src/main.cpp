#include <iostream>
#include <chrono>
#include <cstdlib>

#include "BMPImage.hpp"
#include "Camera.hpp"
#include "Scene/Scene.hpp"
#include "Scene/Sphere.hpp"
#include "Scene/Plane.hpp"

const size_t IMAGE_WIDTH = 1280;
const size_t IMAGE_HEIGHT = 720;
const size_t SAMPLE_PER_PIXEL = 16;

int main()
{
    BMPImage oImage(IMAGE_WIDTH, IMAGE_HEIGHT, vec4ub(0, 127, 0, 255));
    Camera camera(vec3f(0, 0, 0), vec3f(0, 1, 0), vec3f(0, 0, 1));
    Scene scene;
    scene.defaultMaterial.color = vec3f(.25, .4, .66);
    scene.primitives.push_back(new Sphere(vec3f(0, 0, 2), Material(vec3f(.5, .5, .5), .5), 1.));
    scene.primitives.push_back(new Plane(vec3f(0, -1.5, 0), Material(vec3f(.2, .2, .2), .5), vec3f(0., 1., 0.)));
    

    for (size_t y = 0; y < IMAGE_HEIGHT; ++y)
    {
        for (size_t x = 0; x < IMAGE_WIDTH; ++x)
        {
            Ray ray = camera.getRay((2. * x) / IMAGE_WIDTH - 1., (2. * y) / IMAGE_HEIGHT - 1.);
            Hit hit;
            scene.nearestIntersect(ray, hit);
            oImage.setPixel(x, y, vec4ub(hit.material.color.x * 255, hit.material.color.y * 255, hit.material.color.z * 255, 255));
        }
    }

    oImage.changeEndian();
    oImage.SaveBMPImage("tmp.bmp");
    system("explorer tmp.bmp");

    return 0;
}