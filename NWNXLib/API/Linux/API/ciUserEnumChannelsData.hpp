#pragma once

#include <cstdint>

#include "unknown_ciUserEnumChannelsCallback.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ciChatUser;

struct ciUserEnumChannelsData
{
    void* chat;
    ciChatUser* user;
    ciUserEnumChannelsCallback callback;
    void* param;
};

}

}
