#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWSPVPEntry
{
    uint32_t m_oidPC;
    int32_t m_bILikePlayer;
    int32_t m_bPlayerLikesMe;
};

}

}
