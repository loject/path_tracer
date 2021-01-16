#pragma once

#include "math.hpp"
#include "Utils.hpp"

class Camera
{
    private:
        vec3f m_origin = vec3f(0, 0, 0);
        vec3f m_up = vec3f(0, 1, 0);
        vec3f m_forward = vec3f(0, 0, 1);
        float m_aspectRatio = 16. / 9.;
        float m_fov = 3.14159265358979323846 / 2;

    public:
        Camera() {}
        Camera(vec3f origin, vec3f up, vec3f forward, float fov = 3.14159265358979323846 / 5, float aspectRatio = 16. / 9.)
            :m_origin(origin), m_up(vec3f::unit(up)), m_forward(vec3f::unit(forward)), m_fov(fov), m_aspectRatio(aspectRatio) {}

        Ray getRay(float x, float y) const;
};
