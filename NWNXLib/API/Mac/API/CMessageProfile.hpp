#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CMessageProfile
{
    uint32_t m_dwTime;
    uint8_t m_byMajor;
    uint8_t m_byMinor;
    uint32_t m_dwSize;
    uint8_t m_bySendReceive;
    uint8_t m_byPadding;
};

}

}
