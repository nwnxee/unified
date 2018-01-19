#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct LOCK4ID
{
    int32_t recNum;
    int32_t clientId;
    int32_t serverId;
    int16_t type;
    char blank[2];
};

}

}
