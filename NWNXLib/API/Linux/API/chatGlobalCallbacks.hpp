#pragma once

#include <cstdint>

#include "unknown_chatDisconnected.hpp"
#include "unknown_chatInvited.hpp"
#include "unknown_chatPrivateMessage.hpp"
#include "unknown_chatRaw.hpp"

namespace NWNXLib {

namespace API {

struct chatGlobalCallbacks
{
    chatRaw raw;
    chatDisconnected disconnected;
    chatPrivateMessage privateMessage;
    chatInvited invited;
    void* param;
};

}

}
