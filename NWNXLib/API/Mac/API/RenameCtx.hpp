#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct RenameToken;
struct Table;

struct RenameCtx
{
    RenameToken* pList;
    int32_t nList;
    int32_t iCol;
    Table* pTab;
    const char* zOld;
};

}

}
