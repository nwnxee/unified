#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;

struct F4FLAG
{
    CODE4St* codeBase;
    uint8_t* flags;
    uint32_t numFlags;
    uint8_t isFlip;
};

}

}
