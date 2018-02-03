#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Quaternion;

struct Plane
{
    Vector normal;
    float dist;

    void Transform(const Vector&, const Quaternion&);
};

void Plane__Transform(Plane* thisPtr, const Vector&, const Quaternion&);

}

}
