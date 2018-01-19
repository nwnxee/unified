#pragma once

#include <cstdint>

#include "unknown_S4OPERATOR.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct FIELD4St;

struct E4INFOSt
{
    int16_t fieldNo;
    FIELD4St* fieldPtr;
    int32_t localData;
    char* p1;
    int32_t len;
    int32_t numEntries;
    int32_t numParms;
    int32_t resultPos;
    int32_t i1;
    int32_t functionI;
    S4OPERATOR* function;
};

}

}
