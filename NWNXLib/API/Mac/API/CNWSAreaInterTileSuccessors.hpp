#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWSAreaInterTileSuccessors
{
    int32_t nTileGridX;
    int32_t nTileGridY;
    int32_t nTileRegion;
    float fTileExitX;
    float fTileExitY;
    float fDotProduct;
};

}

}
