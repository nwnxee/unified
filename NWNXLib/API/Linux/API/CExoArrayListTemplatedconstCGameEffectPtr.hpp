#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CGameEffect;

struct CExoArrayListTemplatedconstCGameEffectPtr
{
    const CGameEffect** element;
    int32_t num;
    int32_t array_size;
};

}

}
