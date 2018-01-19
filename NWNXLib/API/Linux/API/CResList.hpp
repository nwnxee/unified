#pragma once

#include <cstdint>

#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

struct CResList
    : CResStruct
{
    char m_pLabel[16];
};

}

}
