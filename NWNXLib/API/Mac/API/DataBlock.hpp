#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct DataBlock
{
    char* m_data;
    uint32_t m_used;
    uint32_t m_allocated;
    int32_t m_owning;
};

}

}
