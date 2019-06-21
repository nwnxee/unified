#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct SubProgram;
struct Trigger;

struct TriggerPrg
{
    Trigger* pTrigger;
    TriggerPrg* pNext;
    SubProgram* pProgram;
    int32_t orconf;
    uint32_t aColmask[2];
};

}

}
