#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct seqDef_s;

struct seqStore_t
{
    seqDef_s* sequencesStart;
    seqDef_s* sequences;
    uint8_t* litStart;
    uint8_t* lit;
    uint8_t* llCode;
    uint8_t* mlCode;
    uint8_t* ofCode;
    uint32_t longLengthID;
    uint32_t longLengthPos;
};

}

}
