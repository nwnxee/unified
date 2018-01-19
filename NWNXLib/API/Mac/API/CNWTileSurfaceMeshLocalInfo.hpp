#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

struct CNWTileSurfaceMeshLocalInfo
{
    int32_t pnEdgeUsed[12];
    Vector pfVertex[3];
    int32_t pnVertexIndex[3];
    int32_t pnTriangleAdjacency[3];
};

}

}
