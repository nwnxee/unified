#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct tagDBTIMESTAMP
{
    int16_t year;
    uint16_t month;
    uint16_t day;
    uint16_t hour;
    uint16_t minute;
    uint16_t second;
    uint32_t fraction;
};

}

}
