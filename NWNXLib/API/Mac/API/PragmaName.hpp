#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct PragmaName
{
    const char* const zName;
    uint8_t ePragTyp;
    uint8_t mPragFlg;
    uint8_t iPragCName;
    uint8_t nPragCName;
    uint32_t iArg;
};

}

}
