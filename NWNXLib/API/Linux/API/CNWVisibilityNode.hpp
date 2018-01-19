#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWVisibilityNode
{
    uint32_t m_oidCreature;
    uint8_t m_bSeen : 1;
    uint8_t m_bHeard : 1;
    uint8_t m_nSanctuary : 2;
    uint8_t m_bInvisible : 1;
};

}

}
