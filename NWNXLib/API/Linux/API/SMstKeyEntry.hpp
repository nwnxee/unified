#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct SMstKeyEntry
{
    CExoString szKey;
    int32_t bDemandAuth;
    int32_t bCollision;
    uint16_t nStatus;
    uint16_t nExpansionPack;
    CExoString sChallenge;
};

}

}
