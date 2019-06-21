#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct FSE_CState_t
{
    int32_t value;
    const void* stateTable;
    const void* symbolTT;
    uint32_t stateLog;
};

}

}
