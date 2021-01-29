#pragma once

#include "../math.hpp"

struct Material
{
    vec3f color;
    vec3f specular;
    float roughness;

    Material() {}
    Material(vec3f color, vec3f specular, float roughness): color(color), specular(specular), roughness(roughness) {}
};

