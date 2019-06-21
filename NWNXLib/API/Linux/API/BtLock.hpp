#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Btree;

struct BtLock
{
    Btree* pBtree;
    uint32_t iTable;
    uint8_t eLock;
    BtLock* pNext;
};

}

}
