#pragma once

#include <cstdint>

#include "unknown_TLS_0011F833B5AB5798611DCAD3DABD4CBD.hpp"

namespace NWNXLib {

namespace API {

struct FuncDef
{
    char nArg;
    uint32_t funcFlags;
    void* pUserData;
    FuncDef* pNext;
    void** m_funcPtrPlaceholder__0;
    void** m_funcPtrPlaceholder__1;
    void** m_funcPtrPlaceholder__2;
    void** m_funcPtrPlaceholder__3;
    const char* zName;
    TLS_0011F833B5AB5798611DCAD3DABD4CBD u;
};

}

}
