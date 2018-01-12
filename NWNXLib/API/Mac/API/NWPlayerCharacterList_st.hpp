#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedNWPlayerCharacterListClass_st.hpp"
#include "CExoLocString.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

struct NWPlayerCharacterList_st
{
    CExoLocString sLocFirstName;
    CExoLocString sLocLastName;
    uint8_t nType;
    CResRef resFileName;
    uint16_t nPortraitId;
    CResRef resPortrait;
    CExoArrayListTemplatedNWPlayerCharacterListClass_st lstClasses;

    // The below are auto generated stubs.
    NWPlayerCharacterList_st(const NWPlayerCharacterList_st&) = default;
    NWPlayerCharacterList_st& operator=(const NWPlayerCharacterList_st&) = default;

    NWPlayerCharacterList_st();
};

void NWPlayerCharacterList_st__NWPlayerCharacterList_stCtor(NWPlayerCharacterList_st* thisPtr);

}

}
