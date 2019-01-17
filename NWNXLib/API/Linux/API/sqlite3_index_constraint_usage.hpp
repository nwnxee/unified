#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct sqlite3_index_constraint_usage
{
    int32_t argvIndex;
    uint8_t omit;
};

}

}
