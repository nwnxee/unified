#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct SSubNetProfile
{
    uint32_t nPlayerID;
    CExoString sPlayerName;
    CExoString sCDPublicKey;
    uint64_t nStartTime;
    uint64_t nTotalBytesSent;
    uint64_t nTotalBytesReceived;
};

}

}
