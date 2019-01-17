#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct unixShmNode;

struct unixShm
{
    unixShmNode* pShmNode;
    unixShm* pNext;
    uint8_t hasMutex;
    uint8_t id;
    uint16_t sharedMask;
    uint16_t exclMask;
};

}

}
