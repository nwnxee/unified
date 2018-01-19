#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct DATA4St;
struct FIELD4St;
struct TAG4St;

struct SCodeBaseData
{
    CExoString sDatabaseName;
    DATA4St* dataFile;
    FIELD4St* varName;
    FIELD4St* playerId;
    FIELD4St* timeStamp;
    FIELD4St* varType;
    FIELD4St* varNum1;
    FIELD4St* varNum2;
    FIELD4St* varNum3;
    FIELD4St* varNum4;
    FIELD4St* varNum5;
    FIELD4St* varNum6;
    FIELD4St* varInt;
    FIELD4St* varData;
    TAG4St* tag;
};

}

}
