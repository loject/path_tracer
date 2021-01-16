#pragma once

#include <cassert>

#include "../math.hpp"
#include "../Utils.hpp"
#include "Primitive.hpp"
#include "Material.hpp"

struct Sphere: public Primitive
{
    vec3f Center;
    float Radius;
    Material material;

    Sphere() {}
    Sphere(vec3f Center = vec3f(0, 0, 0), Material material = Material(vec3f(0.5, 0.5, 0.5), 0.5), float Radius = 1.0f): Center(Center), material(material), Radius(Radius) { assert( Radius > 0); }

    bool intersect(const Ray& ray, Hit& hit) const override; 
};
