#pragma once

#include <cstdint>

#include "FILE4St.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct DATA4FILESt;

struct MEMO4FILE
{
    FILE4St file;
    int16_t blockSize;
    DATA4FILESt* data;
    int32_t fileLock;
};

}

}
