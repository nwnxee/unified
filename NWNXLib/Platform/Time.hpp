#pragma once

#include <cstdint>

#ifdef _WIN32
    #include <intrin.h>
#else
    #include <x86intrin.h>
#endif

namespace NWNXLib {

namespace Platform {

namespace Time {

struct Date
{
    uint32_t m_year;
    uint8_t m_month;
    uint8_t m_day;
    uint8_t m_hour;
    uint8_t m_minute;
    uint8_t m_second;
};

Date ConstructDateFromSystemTime();
inline uint64_t GetFastTimestamp();

#include "Time.inl"

}

}

}
