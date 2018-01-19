#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CNWReentrantServerStats
{
    int32_t m_bStallServer;
    uint32_t m_nStallEvent;
    uint32_t m_nCompletedWork;
    uint32_t m_nTotalWork;
    int32_t m_bFirstRenderOfStall;
    int32_t m_bLastRenderOfStall;
    CExoString m_sStallEvent;
    CExoString m_sStallEvent2;
    CExoString m_sStallEvent3;
    uint32_t m_nStallEventDWORD;
    uint32_t m_nStallEventDWORD2;
    uint32_t m_nStallEventError;
};

}

}
