#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct sqlite3_index_orderby
{
    int32_t iColumn;
    uint8_t desc;
};

}

}
