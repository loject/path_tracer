#pragma once

#include "Primitive.hpp"

struct Rectangle : public Primitive
{
    vec3f Point0;
    vec3f Point1;
    vec3f Point2;
    vec3f Point3;
    Material material;

    Rectangle() {}
    Rectangle(const vec3f& P0, const vec3f& P1, const vec3f& P2, const vec3f& P3, const Material& material)
        :Point0(P0), Point1(P1), Point2(P2), Point3(P3), material(material) { }

    bool intersect(const Ray& ray, Hit& hit) const override { return intersect(Point0, Point1, Point2, Point3, ray, hit) ? hit.material = material, true : false; }
    static bool intersect(const vec3f& Point0, const vec3f& Point1, const vec3f& Point2, const vec3f& Point3, const Ray& ray, Hit& hit);
};