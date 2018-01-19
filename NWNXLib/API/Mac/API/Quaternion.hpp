#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct Quaternion
{
    float w;
    float x;
    float y;
    float z;

    Quaternion& operator*=(float);
};

Quaternion& Quaternion__OperatorMultiplicationAssignment(Quaternion* thisPtr, float);

}

}
