#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct FSE_DTableHeader
{
    uint16_t tableLog;
    uint16_t fastMode;
};

}

}
