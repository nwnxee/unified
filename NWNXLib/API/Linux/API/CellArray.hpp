#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct MemPage;

struct CellArray
{
    int32_t nCell;
    MemPage* pRef;
    uint8_t** apCell;
    uint16_t* szCell;
};

}

}
