#pragma once

#include <cstdint>

#include "unknown_TLS_362B7BE5B64CD6E81F2AEFF9FAF6DA88.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Parse;
struct Select;
struct SrcList;

struct NameContext
{
    Parse* pParse;
    SrcList* pSrcList;
    TLS_362B7BE5B64CD6E81F2AEFF9FAF6DA88 uNC;
    NameContext* pNext;
    int32_t nRef;
    int32_t nErr;
    uint16_t ncFlags;
    Select* pWinSelect;
};

}

}
