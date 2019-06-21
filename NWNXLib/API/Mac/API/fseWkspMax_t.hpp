#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct fseWkspMax_t
{
    uint32_t CTable_max[2561];
    uint8_t scratchBuffer[4096];
};

}

}
