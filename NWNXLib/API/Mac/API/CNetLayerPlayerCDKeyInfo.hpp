#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CNetLayerPlayerCDKeyInfo
{
    CExoString sPublic;
    CExoString sResponse;
    int32_t bValidated;
    uint32_t nExpansionPack;
};

}

}
