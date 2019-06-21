#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct SrcList;

struct SrcCount
{
    SrcList* pSrc;
    int32_t nThis;
    int32_t nOther;
};

}

}
