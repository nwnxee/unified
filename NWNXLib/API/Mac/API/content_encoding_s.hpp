#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct content_encoding_s
{
    const char* name;
    const char* alias;
    void** m_funcPtrPlaceholder__0;
    void** m_funcPtrPlaceholder__1;
    void** m_funcPtrPlaceholder__2;
    uint32_t paramsize;
};

}

}
