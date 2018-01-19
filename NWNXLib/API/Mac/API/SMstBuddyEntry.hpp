#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct SMstBuddyEntry
{
    CExoString sBuddyName;
    uint16_t nStatus;
    uint8_t nAddRemoveList;
    uint32_t nIP;
    uint16_t nPort;
};

}

}
