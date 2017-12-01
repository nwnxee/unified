#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ciServerMessageFilter
{
    int32_t type;
    uint32_t timeout;
    char* name;
    char* name2;
    void* callback;
    void* callback2;
    void* param;
    void* data;
    int32_t ID;
    ciServerMessageFilter* pnext;
};

}

}
