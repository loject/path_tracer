#pragma once

#include <cassert>

#include "math.hpp"
#include "Utils.hpp"
#include "Primitive.hpp"
#include "Scene/Material.hpp"

struct Sphere: public Primitive
{
    vec3f Center;
    float Radius;
    Material material;

    Sphere() {}
    Sphere(vec3f Center, Material material, float Radius): Center(Center), material(material), Radius(Radius) { assert( Radius >= 0); }

    bool intersect(const Ray& ray, Hit& hit) const override { return intersect(Center, Radius, ray, hit) ? hit.material = material, true : false; }
    static bool intersect(const vec3f& Center, float Radius, const Ray& ray, Hit& hit); 
};
