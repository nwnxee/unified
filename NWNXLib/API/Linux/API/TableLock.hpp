#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct TableLock
{
    int32_t iDb;
    int32_t iTab;
    uint8_t isWriteLock;
    const char* zLockName;
};

}

}
