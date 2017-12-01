#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciUserChangedNickData
{
    void* chat;
    const char* oldNick;
    const char* newNick;
};

}

}
