#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

struct CNWTileSurfaceMeshNodeFace
{
    int32_t* pnUselessPointer1;
    int32_t* pnUselessPointer2;
    int32_t* pnUselessPointer3;
    int32_t vertexindices[3];
    int32_t s;
    int32_t matid;
    int32_t neighbors[3];
    Vector normal;
    float dist;
};

}

}
