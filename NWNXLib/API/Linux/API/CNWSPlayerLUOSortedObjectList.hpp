#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWSPlayerLUOSortedObjectList
{
    uint32_t oidObject;
    float fDistanceToPlayer;
    uint32_t nCategory;
};

}

}
