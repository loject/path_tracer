#include "Plane.hpp"

bool Plane::intersect(vec3f PlanePoint, vec3f Normal, const Ray& ray, Hit& hit)
{
    float denom = Normal.dot(ray.direction);
    if (abs(denom) < 1e-6) return false;

    vec3f PE = PlanePoint - ray.eye; 
    float t = PE.dot(Normal) / denom;
    if (t < ray.near) return false;
    
    hit.point = ray.eye + t * ray.direction;
    hit.normal = signbit(denom) ? Normal : -Normal;

    return true;
} 
