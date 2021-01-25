#include "Triangle.hpp"

#include "Plane.hpp"

#include <cmath>
#include <iostream>

bool Triangle::intersect(const Ray& ray, Hit& hit) const
{
    Plane trianglePlane(Point0, (Point2 - Point0).cross(Point1 - Point0));
    if (!trianglePlane.intersect(ray, hit)) return false;
    vec3f P0P = (Point0 - hit.point).unit();
    vec3f P1P = (Point1 - hit.point).unit();
    vec3f P2P = (Point2 - hit.point).unit();

    /* sum of angles should be 2PI = 6.28318530718 */
    double a0 = acos(P0P.dot(P1P));
    double a1 = acos(P1P.dot(P2P));
    double a2 = acos(P2P.dot(P0P));

    if (abs(a0 + a1 + a2 - 6.28318530718) > 1e-4) return false;

    hit.material = material;
    
    return true;
} 
