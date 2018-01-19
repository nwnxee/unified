#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWSPersonalReputation
{
    uint32_t m_nDay;
    uint32_t m_nTime;
    int32_t m_bValueDecays;
    int32_t m_nDurationInSeconds;
    uint32_t m_oidCreature;
    int32_t m_nAmount;
};

}

}
