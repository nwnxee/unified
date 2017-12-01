#pragma once

#include "Common.hpp"
#include "ViewPtr.hpp"

#include <chrono>

namespace Optimizations {

class MainLoopSleepOptimization
{
public: // Structures
    enum class OptimizationType
    {
        CONSERVATIVE, // Never exceed target.
        OPTIMIZED // Sometimes exceed target.
    };

    struct Configuration
    {
        uint8_t m_lowRateThreshold; // The amount of players needed to transition from low->high. 0 = always high.
        uint8_t m_lowRateTarget; // The target for low rate. 0 = uncapped.
        uint8_t m_highRateTarget; // The target for high rate. 0 = uncapped.
        OptimizationType m_type;
    };

public:
    MainLoopSleepOptimization(Configuration&& config,
        NWNXLib::ViewPtr<NWNXLib::Services::PatchingProxy> patcher);

private:
    Configuration m_config;

    static void SleepTiming();
};

}
