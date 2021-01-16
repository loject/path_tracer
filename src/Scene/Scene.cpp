#include "Scene.hpp"

bool Scene::nearestIntersect(const Ray& ray, Hit& hit) const
{
    for (size_t i = 0; i < primitives.size(); ++i)
        if (primitives[i]->intersect(ray, hit))
            return true;
    return false;
}