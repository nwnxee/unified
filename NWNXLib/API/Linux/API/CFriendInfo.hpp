#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CFriendInfo
{
    CExoString name;
    int32_t address;
    int32_t port;

    void Sanitize();
};

void CFriendInfo__Sanitize(CFriendInfo* thisPtr);

}

}
