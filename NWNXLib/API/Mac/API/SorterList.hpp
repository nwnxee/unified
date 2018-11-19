#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct SorterRecord;

struct SorterList
{
    SorterRecord* pList;
    uint8_t* aMemory;
    int32_t szPMA;
};

}

}
