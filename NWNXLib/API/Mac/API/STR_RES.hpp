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
};

}

}
