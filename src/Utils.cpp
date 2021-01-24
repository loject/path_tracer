#include "Utils.hpp"

vec3f RandomUnitVector()
{
    vec3f tmp(rand() - RAND_MAX / 2, rand() - RAND_MAX / 2, rand() - RAND_MAX / 2);
    return tmp.unit();
}

vec3f RandomUnitVectorInHemisphereOf(vec3f dir)
{
    auto rndVec = RandomUnitVector();
    return rndVec.dot(dir) > 0 ? rndVec : -rndVec;
}