#pragma once

#include <cstdint>

#include "unknown_chatEnumJoinedChannelsCallback.hpp"

namespace NWNXLib {

namespace API {

struct ciEnumJoinedChannelsData
{
    void* chat;
    chatEnumJoinedChannelsCallback callback;
    void* param;
    int32_t index;
};

}

}
