#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CExoMemHeapWalkInfo
{
    uint32_t m_iSmallestUsed;
    uint32_t m_iLargestUsed;
    uint32_t m_iAverageUsed;
    uint32_t m_iSmallestFree;
    uint32_t m_iLargestFree;
    uint32_t m_iAverageFree;
    int32_t m_iTotalBlocks;
    int32_t m_iFreeBlocks;
    int32_t m_iUsedBlocks;
};

}

}
