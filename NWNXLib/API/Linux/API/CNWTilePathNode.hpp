#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWTilePathNode
{
    int32_t m_nRegionNodes;
    int32_t m_nTileExits;
    float* m_pfRegionNodes;
    float* m_pfTileExits;
    int32_t* m_pnTileExitRegion;
};

}

}
