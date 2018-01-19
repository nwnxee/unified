#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

struct NWModuleEntryInfo_st
{
    CResRef refArea;
    float nX;
    float nY;
    float nZ;
    float fDirX;
    float fDirY;
};

}

}
