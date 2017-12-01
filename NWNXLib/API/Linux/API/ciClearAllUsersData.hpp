#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ciChatChannel;

struct ciClearAllUsersData
{
    void* chat;
    ciChatChannel* channel;
};

}

}
