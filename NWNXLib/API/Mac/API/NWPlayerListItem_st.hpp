#pragma once

#include <cstdint>

#include "CExoLocString.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct NWPlayerListItem_st
{
    CExoString sCommunityName;
    CExoLocString sLocFirstName;
    CExoLocString sLocLastName;
    int32_t bIsPrimaryPlayer;
};

}

}
