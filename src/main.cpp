#include <iostream>
#include <chrono>
#include <cstdlib>

#include "BMPImage.hpp"
#include "Camera.hpp"
#include "Scene/Scene.hpp"
#include "Scene/Sphere.hpp"

const size_t IMAGE_WIDTH = 1920;
const size_t IMAGE_HEIGHT = 1080;

int main()
{
    BMPImage oImage(IMAGE_WIDTH, IMAGE_HEIGHT, vec4ub(0, 127, 0, 255));
    Camera camera(vec3f(0, 0, 0), vec3f(0, 1, 0), vec3f(0, 0, 1));
    Scene scene;
    scene.primitives.push_back(new Sphere(vec3f(0, 0, 2)));
    

    for (size_t y = 0; y < IMAGE_HEIGHT; ++y)
    {
        for (size_t x = 0; x < IMAGE_WIDTH; ++x)
        {
            Ray ray = camera.getRay((2. * x) / IMAGE_WIDTH - 1., (2. * y) / IMAGE_HEIGHT - 1.);
            Hit hit;
            if (scene.nearestIntersect(ray, hit))
            {
                oImage.setPixel(x, y, vec4ub(255, 0, 0, 255));
            }
        }
    }

    oImage.changeEndian();
    oImage.SaveBMPImage("tmp.bmp");
    system("explorer tmp.bmp");

    return 0;
}