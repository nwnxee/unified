#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Table;

struct AutoincInfo
{
    AutoincInfo* pNext;
    Table* pTab;
    int32_t iDb;
    int32_t regCtr;
};

}

}
