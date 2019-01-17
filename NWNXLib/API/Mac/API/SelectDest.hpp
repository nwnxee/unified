#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ExprList;

struct SelectDest
{
    uint8_t eDest;
    int32_t iSDParm;
    int32_t iSdst;
    int32_t nSdst;
    char* zAffSdst;
    ExprList* pOrderBy;
};

}

}
