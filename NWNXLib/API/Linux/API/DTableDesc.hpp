#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct DTableDesc
{
    uint8_t maxTableLog;
    uint8_t tableType;
    uint8_t tableLog;
    uint8_t reserved;
};

}

}
