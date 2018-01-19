#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct DATA4St;
struct F4MEMOSt;

struct FIELD4St
{
    char name[11];
    uint16_t len;
    uint16_t dec;
    int16_t type;
    uint32_t offset;
    DATA4St* data;
    char null;
    uint16_t nullBit;
    char binary;
    F4MEMOSt* memo;
};

}

}
