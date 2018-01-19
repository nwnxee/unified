#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct Vector4
{
    float x;
    float y;
    float z;
    float w;

    void Normalize();
};

void Vector4__Normalize(Vector4* thisPtr);

}

}
