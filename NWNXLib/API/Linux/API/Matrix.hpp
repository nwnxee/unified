#pragma once

#include <cstdint>

#include "Quaternion.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

struct Matrix
{
    Vector x;
    Vector y;
    Vector z;

    Quaternion getquaternion();
};

Quaternion Matrix__getquaternion(Matrix* thisPtr);

}

}
