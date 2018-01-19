#pragma once

#include <cstdint>

#include "unknown__BYTE.hpp"

namespace NWNXLib {

namespace API {

struct KeyFileKeyEntry_st
{
    char resRef[1];
    _BYTE gap1[15];
    uint16_t nType;
    uint32_t nID;
};

}

}
