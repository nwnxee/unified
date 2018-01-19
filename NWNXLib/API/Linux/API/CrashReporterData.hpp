#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CrashReporterData
{
    const char* m_Target;
    int32_t m_Silent;
    int32_t m_Fulldump;
};

}

}
