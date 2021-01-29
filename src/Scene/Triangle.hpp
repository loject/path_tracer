#pragma once

#include "Primitive.hpp"

struct Triangle : public Primitive
{
    vec3f Point0;
    vec3f Point1;
    vec3f Point2;
    Material material;

    Triangle() {}
    Triangle(vec3f P0, vec3f P1, vec3f P2, Material material): Point0(P0), Point1(P1), Point2(P2), material(material) { }

    bool intersect(const Ray& ray, Hit& hit) const override { return intersect(Point0, Point1, Point2, ray, hit) ? hit.material = material, true : false; }
    static bool intersect(const vec3f& Point0, const vec3f& Point1, const vec3f& Point2, const Ray& ray, Hit& hit);
};
