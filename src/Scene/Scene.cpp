#include "Scene.hpp"
#include "../math.hpp"

bool Scene::nearestIntersect(const Ray& ray, Hit& hit) const
{
    float neareastDistance = INFINITY;
    bool found = false;

    Hit currentHit;
    hit.material = defaultMaterial;
    for (size_t i = 0; i < primitives.size(); ++i)
    {
        if (primitives[i]->intersect(ray, currentHit))
        {
            double dist = ray.eye.distance(currentHit.point);
            if (dist < neareastDistance && dist > ray.near)
            {
                found = true;
                neareastDistance = dist;
                hit = currentHit;
            }
        }
    }
    return found;
}