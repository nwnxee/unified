#include "Platform/Time.hpp"
#include <ctime>

namespace NWNXLib {

namespace Platform {

namespace Time {

Date ConstructDateFromSystemTime()
{
    time_t now = std::time(nullptr);
    tm* timeinfo = std::localtime(&now);

    return
    {
        static_cast<uint32_t>(timeinfo->tm_year),
        static_cast<uint8_t>(timeinfo->tm_mon + 1),
        static_cast<uint8_t>(timeinfo->tm_mday),
        static_cast<uint8_t>(timeinfo->tm_hour),
        static_cast<uint8_t>(timeinfo->tm_min),
        static_cast<uint8_t>(timeinfo->tm_sec)
    };
}

}

}

}
