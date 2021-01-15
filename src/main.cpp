#include <iostream>
#include "BMPImage.hpp"

const size_t IMAGE_WIDTH = 1920;
const size_t IMAGE_HEIGHT = 1080;

int main()
{
    BMPImage oImage(IMAGE_WIDTH, IMAGE_HEIGHT, vec4ub(0, 127, 0, 255));

    for (size_t y = 0; y < IMAGE_HEIGHT; ++y)
    {
        for (size_t x = 0; x < IMAGE_WIDTH; ++x)
        {

        }
    }

    oImage.changeEndian();
    oImage.SaveBMPImage("tmp.bmp");

    return 0;
}