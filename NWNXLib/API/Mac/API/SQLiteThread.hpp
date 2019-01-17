#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct SQLiteThread
{
    uint32_t tid;
    int32_t done;
    void* pOut;
    void** m_funcPtrPlaceholder__0;
    void* pIn;
};

}

}
