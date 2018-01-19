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
};

}

}
