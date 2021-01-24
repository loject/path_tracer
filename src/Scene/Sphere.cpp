#include "Sphere.hpp"

bool Sphere::intersect(const Ray& ray, Hit& hit) const
{
    if (ray.direction.length() == 0) return false;
    vec3f OriginToSphereCenterDir = Center - ray.eye;
    
	float tca  = OriginToSphereCenterDir.dot(ray.direction);
	// if (tca  < 0) return false;
    float d2 = OriginToSphereCenterDir.dot(OriginToSphereCenterDir) - tca * tca;
    if (d2 > Radius * Radius) return false;
    float thc = sqrtf(Radius * Radius - d2);
    float t0 = tca - thc;
    float t1 = tca + thc;
    
    if (t0 > t1)
        std::swap(t0, t1);

    if (t0 < 0)
    {
        t0 = t1;/*if t0 negative use t1*/
        if (t0 < 0)
        {
            return false;/* both t0 and t1 negative */
        }
    }
    
    hit.point = ray.eye + ray.direction * t0;
    hit.normal = (hit.point - Center).unit();
    hit.material = material;
    return true;
}
