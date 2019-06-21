#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct TabResult
{
    char** azResult;
    char* zErrMsg;
    uint32_t nAlloc;
    uint32_t nRow;
    uint32_t nColumn;
    uint32_t nData;
    int32_t rc;
};

}

}
