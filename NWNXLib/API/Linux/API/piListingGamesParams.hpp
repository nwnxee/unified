#pragma once

#include <cstdint>

#include "unknown_PEERBool.hpp"
#include "unknown__SBServer.hpp"

namespace NWNXLib {

namespace API {

struct piListingGamesParams
{
    char* name;
    _SBServer* server;
    PEERBool staging;
    int32_t msg;
    int32_t progress;
};

}

}
