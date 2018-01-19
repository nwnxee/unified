#pragma once

#include <cstdint>

#include "FILE4LONG_EXTENDSt.hpp"
#include "FILE4St.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4TRANSSt;

struct TRAN4FILESt
{
    int32_t transId;
    int32_t validState;
    uint32_t fileLocks;
    FILE4St file;
    int32_t status;
    uint32_t fileLen;
    FILE4LONG_EXTENDSt pad;
    int32_t needsFlushing;
    CODE4TRANSSt* c4trans;
};

}

}
