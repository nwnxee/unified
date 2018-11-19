#pragma once

#include <cstdint>

#include "unknown_blockType_e.hpp"

namespace NWNXLib {

namespace API {

struct blockProperties_t
{
    blockType_e blockType;
    uint32_t lastBlock;
    uint32_t origSize;
};

}

}
