#pragma once

#include <cstdint>

#include "unknown_MessageType.hpp"

namespace NWNXLib {

namespace API {

struct piPlayerMessageParams
{
    char* nick;
    char* message;
    MessageType messageType;
};

}

}
