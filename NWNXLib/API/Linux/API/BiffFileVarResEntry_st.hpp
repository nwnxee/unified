#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct BiffFileVarResEntry_st
{
    uint32_t nID;
    uint32_t nOffset;
    uint32_t nSize;
    uint32_t nType;
};

}

}
