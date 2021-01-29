#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <memory>
#include <cstdlib>

#include "ConcurrencyManager.hpp"

#include "BMPImage.hpp"
#include "Camera.hpp"
#include "Scene/Scene.hpp"
#include "Scene/Primitives/Primitives.hpp"

const size_t IMAGE_WIDTH = 1780;
const size_t IMAGE_HEIGHT = 720;
const std::string IMAGE_FILE_NAME = getCurrentDateTImeStr() + ".bmp";
const size_t SAMPLE_PER_PIXEL = 8;
const size_t MAX_DEPTH = 16;
const size_t TILE_WIDTH = 32;
const size_t TILE_HEIGHT = 32;

vec3f trace(const Scene& scene, const Ray& ray, size_t level);
struct TileRederer
{
    const size_t xStart, xEnd;
    const size_t yStart, yEnd;
    BMPImage& image;
    const Scene& scene;
    const Camera& camera;
    TileRederer(TileRederer&& tr) = default;
    TileRederer(const TileRederer& tr) = default;
    TileRederer(const size_t xStart, const size_t xEnd, const size_t yStart, const size_t yEnd, BMPImage& image, const Scene& scene, const Camera& camera)
        :xStart(xStart), xEnd(xEnd), yStart(yStart), yEnd(yEnd), image(image), scene(scene), camera(camera) {}

    void operator()()
    {
        for (size_t y = yStart; y < yEnd; ++y)
        {
            for (size_t x = xStart; x < xEnd; ++x)
            {
                Ray ray = camera.getRay((2. * x) / IMAGE_WIDTH - 1., (2. * y) / IMAGE_HEIGHT - 1.);
                ray.near = 1e-4;
                vec3f clr(0.);
                for (size_t i = 0; i < SAMPLE_PER_PIXEL; ++i)
                    clr = clr + trace(scene, ray, 0).clamp(0., 1.);
                clr = clr / SAMPLE_PER_PIXEL;
                image.setPixel(x, y, vec4ub(clr.x * 255, clr.y * 255, clr.z * 255, 255));
            }
        }
    }
};

vec3f trace(const Scene& scene, const Ray& ray, size_t level)
{
    Hit hit;
    if (!scene.nearestIntersect(ray, hit))
    {
        return scene.defaultMaterial.color;
    }
    else
    {
        if (level >= MAX_DEPTH) 
        {
            return (vec3f(1) - hit.material.specular) * hit.material.color;
        }
        else
        {
            auto randomVector = RandomUnitVectorInCone((ray.direction + 2 * hit.normal).unit(), hit.material.roughness * 3.1415926 / 2);

            Ray reflect(hit.point, randomVector, ray.near);
            return (vec3f(1) - hit.material.specular) * hit.material.color + hit.material.specular * trace(scene, reflect, level + 1);
        }
    }
}

int main()
{
    auto startTimePoint = std::chrono::high_resolution_clock::now();
    BMPImage oImage(IMAGE_WIDTH, IMAGE_HEIGHT, vec4ub(0, 127, 0, 255));
    Camera camera(vec3f(0, 0, 0), vec3f(0, 1, 0), vec3f(0, 0, 1), 3.1415926 / 5, (double)IMAGE_WIDTH / IMAGE_HEIGHT);
    Scene scene;
    scene.defaultMaterial.color = vec3f(.25, .4, .66);
    scene.primitives.push_back(std::make_unique<Sphere>(vec3f(0, 0, 2.5), Material(vec3f(.5, .5, .5), vec3f(0.1), .5), 1.));
    scene.primitives.push_back(std::make_unique<Sphere>(vec3f(4, 0, 2.5), Material(vec3f(.5, .5, .5), vec3f(0.91), .02), 2.));
    scene.primitives.push_back(std::make_unique<Plane>(vec3f(0, -.5, 0), vec3f(0., 1., 0.), Material(vec3f(.2, .2, .2), vec3f(0.01), 0.95)));
    scene.primitives.push_back(std::make_unique<Plane>(vec3f(0, -.5, 0), vec3f(1., 1., 0.), Material(vec3f(.2, .32, .2), vec3f(0.65), 0.4)));
    scene.primitives.push_back(std::make_unique<Triangle>(vec3f(-5., 0, 5), vec3f(0., 5., 5), vec3f(5., 0., 5), Material(vec3f(.2, .7, .2), vec3f(0.2), .5)));
    scene.primitives.push_back(std::make_unique<Triangle>(vec3f(-1, 1, 2), vec3f(-1, 2.5, 5), vec3f(-1, 1, 3), Material(vec3f(.6, .2, .2), vec3f(0.2), .5)));
    scene.primitives.push_back(std::make_unique<Rectangle>(vec3f(0, 10, 5), vec3f(10, 10, 5), vec3f(10, 1, 5), vec3f(0, 1, 5), Material(vec3f(0, 0, 0), vec3f(0.2), .12)));
    
    ConcurrencyManager cm;
    for (size_t y = 0; y < IMAGE_HEIGHT; y += TILE_HEIGHT)
        for (size_t x = 0; x < IMAGE_WIDTH; x += TILE_WIDTH)
            cm.addTaskToQueue(TileRederer(x, std::min(IMAGE_WIDTH, x + TILE_WIDTH), y, std::min(IMAGE_HEIGHT, y + TILE_HEIGHT), oImage, scene, camera));
    cm.wait();
    
    oImage.changeEndian();
    oImage.SaveBMPImage(IMAGE_FILE_NAME);

    auto endTimePoint = std::chrono::high_resolution_clock::now();
    std::cout << "Time elapsed - " << std::chrono::duration_cast<std::chrono::milliseconds>(endTimePoint - startTimePoint).count() / 1000. << "s." << std::endl;
    system((std::string("explorer ") + IMAGE_FILE_NAME).c_str());

    return 0;
}