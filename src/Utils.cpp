#include "Utils.hpp"
#include <cassert>

vec3f RandomUnitVector()
{
    vec3f tmp(rand() - RAND_MAX / 2, rand() - RAND_MAX / 2, rand() - RAND_MAX / 2);
    return tmp.unit();
}

vec3f RandomUnitVectorInCone(vec3f coneAxis, float angle)
{
    const double PI = 3.14159265359;

    assert(0 < angle && angle < 3.14159265359);

    auto theta = angle * (2 * rand() / (double)RAND_MAX - 1);
    auto phi = angle * (2 * rand() / (double)RAND_MAX - 1);

    vec3f perpendicular0 = (coneAxis.x != 0 ? vec3f(coneAxis.y, -coneAxis.x, coneAxis.z) :
                            coneAxis.y != 0 ? vec3f(-coneAxis.y, -coneAxis.z, coneAxis.z) :
                            vec3f(coneAxis.x, -coneAxis.z, coneAxis.y));
    vec3f perpendicular1 = coneAxis.cross(perpendicular0);
    vec4f res = mat4<float>::rotateMatrix(perpendicular0, theta) * vec4f(coneAxis, 1.0); 
    res = mat4<float>::rotateMatrix(perpendicular1, phi) * res;
    return vec3f(res.x, res.y, res.z).unit();
}

vec3f RandomUnitVectorInHemisphereOf(vec3f dir)
{
    auto rndVec = RandomUnitVector();
    return rndVec.dot(dir) > 0 ? rndVec : -rndVec;
}