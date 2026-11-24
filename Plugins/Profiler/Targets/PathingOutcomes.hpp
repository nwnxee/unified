#pragma once

#include "nwnx.hpp"

#include <chrono>

namespace Profiler {

class PathingOutcomes
{
public:
    // Logging of single requests (see README).
    struct LogSettings
    {
        uint32_t slowMs = 0;          // log a planner call at least this slow (0: off)
        bool failed = false;          // log failed requests...
        int32_t failedMinAILevel = 2; // ...of creatures at this AI level or higher
        std::chrono::seconds interval{60}; // at most one line per creature this often
    };

    PathingOutcomes(NWNXLib::Services::MetricsProxy* metrics, std::chrono::seconds interval, const LogSettings& log);
};

}
