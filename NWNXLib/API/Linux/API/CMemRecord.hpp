#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CMemRecord
{
    char* m_pRealBlock;
    char* m_pReturnedPtr;
    uint32_t m_iRealSize;
    uint32_t m_iAllocSize;
    char m_szFile[64];
    int32_t m_iLine;
    int32_t m_iBlockID;
    uint8_t m_byMemTrackingType;
    int32_t m_bValid;
    char m_szComment[128];

    void Clear();
};

void CMemRecord__Clear(CMemRecord* thisPtr);

}

}
