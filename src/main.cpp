#include <iostream>
#include "BMPImage.hpp"
#include "Camera.hpp"

const size_t IMAGE_WIDTH = 4;
const size_t IMAGE_HEIGHT = 4;

int main()
{
    BMPImage oImage(IMAGE_WIDTH, IMAGE_HEIGHT, vec4ub(0, 127, 0, 255));
    Camera camera(vec3f(0, 0, 0), vec3f(0, 1, 0), vec3f(0, 0, 1));

    for (size_t y = 0; y < IMAGE_HEIGHT; ++y)
    {
        for (size_t x = 0; x < IMAGE_WIDTH; ++x)
        {
            std::cout << vec2ub(x, y) << " - \t" << camera.getRay((2. * x) / IMAGE_WIDTH - 1., (2. * y) / IMAGE_HEIGHT - 1.).direction << std::endl;
        }
    }

    oImage.changeEndian();
    oImage.SaveBMPImage("tmp.bmp");

    return 0;
}