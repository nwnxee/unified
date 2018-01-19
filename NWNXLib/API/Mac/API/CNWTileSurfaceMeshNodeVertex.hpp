#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

struct CNWTileSurfaceMeshNodeVertex
{
    float fVirtualWasteOfSpace;
    Vector vCoord;
    Vector vTexCoord;
    Vector vNormal;
};

}

}
