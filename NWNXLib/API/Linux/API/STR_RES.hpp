#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

struct STR_RES
{
    CExoString szText;
    CResRef cSoundResRef;
    float fSoundLength;

    // The below are auto generated stubs.
    STR_RES(const STR_RES&) = default;
    STR_RES& operator=(const STR_RES&) = default;

    STR_RES();
};

void STR_RES__STR_RESCtor(STR_RES* thisPtr);

}

}
