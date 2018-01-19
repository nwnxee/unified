#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct NWPlayerCharacterListClass_st;

struct CExoArrayListTemplatedNWPlayerCharacterListClass_st
{
    NWPlayerCharacterListClass_st* element;
    int32_t num;
    int32_t array_size;
};

}

}
