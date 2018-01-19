#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CScriptLog;

struct CExoArrayListTemplatedCScriptLogPtr
{
    CScriptLog** element;
    int32_t num;
    int32_t array_size;
};

}

}
