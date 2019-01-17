#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct BusyHandler
{
    void** m_funcPtrPlaceholder__0;
    void* pBusyArg;
    int32_t nBusy;
    uint8_t bExtraFileArg;
};

}

}
