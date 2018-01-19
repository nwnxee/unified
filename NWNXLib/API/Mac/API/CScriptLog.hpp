#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CScriptLog
{
    CExoString m_sScriptName;
    int32_t m_nTimesRun;
    uint32_t m_nTotalTime;
};

}

}
