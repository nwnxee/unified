#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct sqlite3StatType
{
    uint32_t nowValue[10];
    uint32_t mxValue[10];
};

}

}
