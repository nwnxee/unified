#pragma once

#include <cstdint>

#include "Vector4.hpp"

namespace NWNXLib {

namespace API {

struct Matrix4x4
{
    Vector4 x;
    Vector4 y;
    Vector4 z;
    Vector4 w;
};

}

}
