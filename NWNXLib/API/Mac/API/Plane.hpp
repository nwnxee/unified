#pragma once

#include <cstdint>

#include "Quaternion.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

struct Plane
{
    Vector normal;
    float dist;

    void Transform(const Vector&, const Quaternion&);
};

void Plane__Transform(Plane* thisPtr, const Vector&, const Quaternion&);

}

}
