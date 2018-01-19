#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct S4SPOOL
{
    char* ptr;
    uint32_t pos;
    uint32_t len;
    int32_t disk;
    int32_t spoolI;
};

}

}
