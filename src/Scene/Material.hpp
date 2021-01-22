#pragma once

#include "../math.hpp"

struct Material
{
    vec3f color;
    float roughness;

    Material() {}
    Material(vec3f color, float roughness): color(color), roughness(roughness) {}
};

