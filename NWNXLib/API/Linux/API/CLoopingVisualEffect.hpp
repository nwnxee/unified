#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CLoopingVisualEffect
{
    uint16_t m_nId;
    uint32_t m_oOriginator;
    uint8_t m_nBodyPart;

    int32_t GetIsBeam();
};

int32_t CLoopingVisualEffect__GetIsBeam(CLoopingVisualEffect* thisPtr);

}

}
