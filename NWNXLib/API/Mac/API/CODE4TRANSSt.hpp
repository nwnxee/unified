#pragma once

#include <cstdint>

#include "TRAN4St.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;
struct TRAN4FILESt;

struct CODE4TRANSSt
{
    CODE4St* c4;
    int32_t enabled;
    TRAN4FILESt* transFile;
    TRAN4St trans;
};

}

}
