#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciCallbackEnumUsersParams
{
    CHATBool success;
    char* channel;
    int32_t numUsers;
    char** users;
    int32_t* modes;
};

}

}
