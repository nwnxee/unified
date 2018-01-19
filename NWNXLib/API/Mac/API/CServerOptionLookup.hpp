#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CServerOptionLookup
{
    const char* szCategory;
    const char* szOptionName;
    int32_t* pData;
    int32_t nType;
};

}

}
