#include "Camera.hpp"
#include <cassert>


Ray Camera::getRay(float x, float y) const
{
    assert(-1 <= x && x <= 1);
    assert(-1 <= y && y <= 1);
    Ray res;
    res.eye = m_origin;
    auto right = m_up.cross(m_forward);
    res.direction = m_forward + x * right + y * m_up;
    return res;
}
