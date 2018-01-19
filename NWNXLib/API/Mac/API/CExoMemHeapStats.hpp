#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CExoMemHeapStats
{
    int32_t m_iTotalBlocks;
    int32_t m_iFreeBlocks;
    int32_t m_iUsedBlocks;
    int32_t m_iHeapSize;
    int32_t m_iHeapUsed;
    int32_t m_iHeapFree;
    char m_szName[256];
};

}

}
