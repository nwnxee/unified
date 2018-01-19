#pragma once

#include <cstdint>

#include "NWPlayerCharacterListClass_st.hpp"

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedNWPlayerCharacterListClass_st
{
    NWPlayerCharacterListClass_st* element;
    int32_t num;
    int32_t array_size;

    void Add(NWPlayerCharacterListClass_st);
};

void CExoArrayListTemplatedNWPlayerCharacterListClass_st__Add(CExoArrayListTemplatedNWPlayerCharacterListClass_st* thisPtr, NWPlayerCharacterListClass_st);

}

}
