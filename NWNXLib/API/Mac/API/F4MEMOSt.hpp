#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct FIELD4St;

struct F4MEMOSt
{
    int32_t isChanged;
    int32_t status;
    char* contents;
    uint32_t len;
    uint32_t lenMax;
    FIELD4St* field;
};

}

}
