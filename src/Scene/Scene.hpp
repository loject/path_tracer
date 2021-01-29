#pragma once

#include <vector>
#include "Primitives/Primitive.hpp"
#include "math.hpp"
#include "Utils.hpp"

struct Scene
{
    std::vector<std::unique_ptr<Primitive>> primitives;
    Material defaultMaterial;

    bool nearestIntersect(const Ray& ray, Hit& hit) const; 
};

