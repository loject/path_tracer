#include "Utils.hpp"
#include <cassert>
#include <ctime>
#include <iomanip>
#include <sstream>

vec3f RandomUnitVector()
{
    vec3f tmp(rand() - RAND_MAX / 2, rand() - RAND_MAX / 2, rand() - RAND_MAX / 2);
    return tmp.unit();
}

vec3f RandomUnitVectorInCone(vec3f coneAxis, float angle)
{
    assert(0 <= angle && angle <= 1.57079632679);

    vec3f spherical = vec3f::convertToSpherical(coneAxis);

    auto randTheta = angle * (2 * rand() / (double)RAND_MAX - 1);
    auto randPhi = angle * (2 * rand() / (double)RAND_MAX - 1);

    spherical.theta += randTheta;
    spherical.phi += randPhi;

    return vec3f::convertToDescartes(spherical);
}

vec3f RandomUnitVectorInHemisphereOf(vec3f dir)
{
    auto rndVec = RandomUnitVector();
    return rndVec.dot(dir) > 0 ? rndVec : -rndVec;
}

std::string getCurrentDateTImeStr()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto str = oss.str();
    return str;
}
