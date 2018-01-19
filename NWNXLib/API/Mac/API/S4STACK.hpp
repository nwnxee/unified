#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CODE4St;

struct S4STACK
{
    char* ptr;
    uint32_t pos;
    uint32_t len;
    int32_t doExtend;
    CODE4St* codeBase;
};

}

}
