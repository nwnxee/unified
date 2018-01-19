#pragma once

#include <cstdint>

#include "unknown__BYTE.hpp"

namespace NWNXLib {

namespace API {

struct EncapsulatedKeyListEntry_st
{
    char resRef[1];
    _BYTE gap1[15];
    uint32_t nID;
    uint16_t nType;
    uint16_t unused;
};

}

}
