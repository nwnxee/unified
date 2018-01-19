#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct SMstNameEntry
{
    CExoString szPlayerName;
    uint16_t nStatus;
    uint8_t* pPublicKey;
};

}

}
