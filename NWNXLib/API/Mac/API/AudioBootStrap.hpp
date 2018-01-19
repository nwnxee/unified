#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct AudioBootStrap
{
    const char* name;
    const char* desc;
    void** m_funcPtrPlaceholder__0;
    int32_t demand_only;
};

}

}
