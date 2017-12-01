#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackGetGlobalKeysParams
{
    CHATBool success;
    char* user;
    int32_t num;
    char** keys;
    char** values;
};

}

}
