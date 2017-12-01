#pragma once

#include <cstdint>

#include "CHATChannelMode.hpp"
#include "chatChannelCallbacks.hpp"
#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct HashImplementation;

struct ciChatChannel
{
    char name[257];
    chatChannelCallbacks callbacks;
    HashImplementation* users;
    CHATChannelMode mode;
    CHATBool gotMode;
    char* password;
    CHATBool joinCallbackCalled;
    char topic[128];
};

}

}
