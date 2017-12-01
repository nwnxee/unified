#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct piGetPlayerInfoParams
{
    char* nick;
    uint32_t IP;
    int32_t profileID;
};

}

}
