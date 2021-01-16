#pragma once

#include <vector>
#include "Primitive.hpp"
#include "../math.hpp"
#include "../Utils.hpp"

struct Scene
{
    std::vector<Primitive*> primitives;

    bool nearestIntersect(const Ray& ray, Hit& hit) const; 
};

