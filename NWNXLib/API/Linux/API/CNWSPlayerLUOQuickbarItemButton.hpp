#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWSPlayerLUOQuickbarItemButton
{
    uint32_t m_oidItem;
    uint8_t m_nObjectType;
    int32_t m_nINTParam1;
    uint16_t m_nUseCount;
};

}

}
