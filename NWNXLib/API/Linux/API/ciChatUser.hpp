#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct ciChatUser
{
    char name[128];
    char user[24];
    char address[64];
    CHATBool gotUserAndAddress;
    int32_t mode;
};

}

}
