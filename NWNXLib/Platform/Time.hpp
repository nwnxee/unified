#pragma once

#include <cstdint>
#include <x86intrin.h>


namespace NWNXLib::Platform::Time {

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
