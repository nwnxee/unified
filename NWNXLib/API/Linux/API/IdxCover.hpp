#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Index;

struct IdxCover
{
    Index* pIdx;
    int32_t iCur;
};

}

}
