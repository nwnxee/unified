#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct sqlite3_index_constraint
{
    int32_t iColumn;
    uint8_t op;
    uint8_t usable;
    int32_t iTermOffset;
};

}

}
