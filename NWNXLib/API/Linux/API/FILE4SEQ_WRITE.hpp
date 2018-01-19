#pragma once

#include <cstdint>

#include "FILE4LONG_EXTENDSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct FILE4St;

struct FILE4SEQ_WRITE
{
    FILE4St* file;
    uint32_t pos;
    FILE4LONG_EXTENDSt pad;
    char* buffer;
    uint32_t total;
    uint32_t working;
    uint32_t avail;
};

}

}
