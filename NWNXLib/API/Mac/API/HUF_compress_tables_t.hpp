#pragma once

#include <cstdint>

#include "HUF_CElt_s.hpp"
#include "unknown_nodeElt.hpp"

namespace NWNXLib {

namespace API {

struct HUF_compress_tables_t
{
    uint32_t count[256];
    HUF_CElt_s CTable[256];
    nodeElt nodeTable;
};

}

}
