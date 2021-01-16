#pragma once

#include "../math.hpp"
#include "../Utils.hpp"

class Primitive
{
    public:
        virtual ~Primitive() = default;

        virtual bool intersect(const Ray& ray, Hit& hit) const = 0; 
};

