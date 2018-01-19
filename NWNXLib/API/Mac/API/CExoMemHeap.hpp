#pragma once

#include <cstdint>

#include "CExoMemHeapStats.hpp"

namespace NWNXLib {

namespace API {

struct CExoMemHeap
{
    void** m_vtable;
    CExoMemHeap* next;
    uint32_t* rawblock;
    uint32_t m_iSize;
    char m_szHeapName[32];
    CExoMemHeapStats stats;
};

}

}
