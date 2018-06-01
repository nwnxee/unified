#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

struct ObjectVisualTransformData
{
    Vector m_scale;
    Vector m_rotate;
    Vector m_translate;
    float m_animationSpeed;
};

}

}
