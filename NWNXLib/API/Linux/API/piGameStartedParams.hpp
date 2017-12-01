#pragma once

#include <cstdint>

#include "unknown__SBServer.hpp"

namespace NWNXLib {

namespace API {

struct piGameStartedParams
{
    _SBServer* server;
    char* message;
};

}

}
