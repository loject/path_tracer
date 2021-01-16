#pragma once

#include "../math.hpp"

struct Material
{
    vec3f color;
    float roughness;

    Material(vec3f color = vec3f(.5, .5, .5), float roughness = 0.5) {}
};

