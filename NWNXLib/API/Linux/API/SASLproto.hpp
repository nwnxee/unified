#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct SASLproto
{
    const char* service;
    int32_t contcode;
    int32_t finalcode;
    uint32_t maxirlen;
    void** m_funcPtrPlaceholder__0;
    void** m_funcPtrPlaceholder__1;
    void** m_funcPtrPlaceholder__2;
};

}

}
