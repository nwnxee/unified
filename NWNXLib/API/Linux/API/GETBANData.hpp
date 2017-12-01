#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct GETBANData
{
    int32_t numBans;
    char** bans;
};

}

}
