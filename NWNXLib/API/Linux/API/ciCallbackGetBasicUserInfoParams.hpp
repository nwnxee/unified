#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackGetBasicUserInfoParams
{
    CHATBool success;
    char* nick;
    char* user;
    char* address;
};

}

}
