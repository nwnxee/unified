#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CFileInfo
{
    CExoString sFileName;
    uint16_t nYear;
    uint16_t nMonth;
    uint16_t nDay;
    uint16_t nHour;
    uint16_t nMinute;
    uint16_t nSecond;
};

}

}
