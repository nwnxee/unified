#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct FILE4St;

struct OPT4CMP
{
    FILE4St* file;
    int32_t pos;
};

}

}
