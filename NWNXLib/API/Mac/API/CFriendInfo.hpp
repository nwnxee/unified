#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CFriendInfo
{
    CExoString name;
    uint32_t address;
    uint16_t port;
    uint64_t lobby;

    void Sanitize();
};

void CFriendInfo__Sanitize(CFriendInfo* thisPtr);

}

}
