#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWSAreaGridTransTableEntry
{
    int32_t nX;
    int32_t nY;
    int32_t nShortestPath;
    int32_t nStepsExplored;
};

}

}
