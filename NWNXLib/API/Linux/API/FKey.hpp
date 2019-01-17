#pragma once

#include <cstdint>

#include "sColMap.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Table;
struct Trigger;

struct FKey
{
    Table* pFrom;
    FKey* pNextFrom;
    char* zTo;
    FKey* pNextTo;
    FKey* pPrevTo;
    int32_t nCol;
    uint8_t isDeferred;
    uint8_t aAction[2];
    Trigger* apTrigger[2];
    sColMap aCol[1];
};

}

}
