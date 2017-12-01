#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ciChatUser;

struct ciGetUserBasicInfoData
{
    CHATBool found;
    ciChatUser* chatUser;
    char* user;
    char* address;
};

}

}
