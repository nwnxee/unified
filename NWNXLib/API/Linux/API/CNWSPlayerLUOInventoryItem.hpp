#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWSPlayerLUOInventoryItem
{
    uint32_t oidObject;
    uint8_t xPos;
    uint8_t yPos;
    uint32_t nStackSize;
    uint32_t nCost;
};

}

}
