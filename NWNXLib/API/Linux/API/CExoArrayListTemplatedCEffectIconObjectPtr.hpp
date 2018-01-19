#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CEffectIconObject;

struct CExoArrayListTemplatedCEffectIconObjectPtr
{
    CEffectIconObject** element;
    int32_t num;
    int32_t array_size;
};

}

}
