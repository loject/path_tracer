#include "Rectangle.hpp"

#include "Triangle.hpp"


bool Rectangle::intersect(const vec3f& Point0, const vec3f& Point1, const vec3f& Point2, const vec3f& Point3, const Ray& ray, Hit& hit)
{
    if (Triangle::intersect(Point0, Point1, Point2, ray, hit) ||
        Triangle::intersect(Point0, Point2, Point3, ray, hit))
    {
        return true;
    }

    return false;
} 
