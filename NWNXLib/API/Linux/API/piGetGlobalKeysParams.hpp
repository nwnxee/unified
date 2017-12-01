#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct piGetGlobalKeysParams
{
    char* nick;
    int32_t num;
    char** keys;
    char** values;
};

}

}
