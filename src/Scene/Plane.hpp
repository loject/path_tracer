#pragma once

#include <cassert>

#include "../math.hpp"
#include "../Utils.hpp"
#include "Primitive.hpp"
#include "Material.hpp"

struct Plane: public Primitive
{
    vec3f PlanePoint;
    vec3f Normal;
    Material material;

    Plane() {}
    Plane(vec3f PlanePoint, Material material, vec3f Normal)
        :PlanePoint(PlanePoint), material(material), Normal(Normal.unit()) { }

    bool intersect(const Ray& ray, Hit& hit) const override; 
};
