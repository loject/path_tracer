#pragma once

#include <cassert>

#include "math.hpp"
#include "Utils.hpp"
#include "Primitive.hpp"
#include "Scene/Material.hpp"

struct Plane: public Primitive
{
    vec3f PlanePoint;
    vec3f Normal;
    Material material;

    Plane() {}
    Plane(vec3f PlanePoint, vec3f Normal) :PlanePoint(PlanePoint), Normal(Normal.unit()) { }
    Plane(vec3f PlanePoint, vec3f Normal, Material material) :PlanePoint(PlanePoint), Normal(Normal.unit()), material(material) { }

    bool intersect(const Ray& ray, Hit& hit) const override { return intersect(PlanePoint, Normal, ray, hit) ? hit.material = material, true : false; }
    static bool intersect(vec3f PlanePoint, vec3f Normal, const Ray& ray, Hit& hit);
};
