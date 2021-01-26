#pragma once

#include "math.hpp"
#include "Scene/Material.hpp"

struct Ray
{
    vec3f eye;
    vec3f direction;
    float near;

    Ray() {}
    Ray(vec3f origin, vec3f direction, float near = 1e-4):eye(origin), direction(direction), near(near) {}
};

struct Hit
{
    vec3f point;
    vec3f normal;
    Material material;

    Hit() {}
    Hit(vec3f point, vec3f normal, Material material): point(point), normal(normal), material(material) {}
};


vec3f RandomUnitVector();
vec3f RandomUnitVectorInCone(vec3f coneAxis, float angle);
vec3f RandomUnitVectorInHemisphereOf(vec3f dir);