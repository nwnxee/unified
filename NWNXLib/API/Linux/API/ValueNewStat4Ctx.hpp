#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Index;
struct Parse;
struct UnpackedRecord;

struct ValueNewStat4Ctx
{
    Parse* pParse;
    Index* pIdx;
    UnpackedRecord** ppRec;
    int32_t iVal;
};

}

}
