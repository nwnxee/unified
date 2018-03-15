#include "Optimizations/MainLoopSleepOptimization.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CExoLinkedListTemplatedCNWSClient.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"
#include "Services/Patching/Patching.hpp"

#include <algorithm>
#include <chrono>
#include <numeric>
#include <thread>
#include <vector>

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::Services;

static MainLoopSleepOptimization* g_opt = nullptr;

MainLoopSleepOptimization::MainLoopSleepOptimization(
    MainLoopSleepOptimization::Configuration&& config,
    ViewPtr<PatchingProxy> patcher)
    : m_config(std::forward<MainLoopSleepOptimization::Configuration>(config))
{
    ASSERT(g_opt == nullptr);
    g_opt = this;

#ifdef _WIN32
    throw std::runtime_error("MainLoopSleepOptimization is not yet implemented on Windows.");
#else
    patcher->PatchWithCall(0x0804BBEE, 0x0804BBFE - 0x0804BBEE, &SleepTiming); NWNX_EXPECT_VERSION(8109);
#endif
}

void MainLoopSleepOptimization::SleepTiming()
{
    using namespace std::chrono;
    static time_point<high_resolution_clock> s_lastTick;

    const uint32_t playerCount = API::Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->
        m_pNWSPlayerList->m_pcExoLinkedListInternal->m_nCount;

    const Configuration& config = g_opt->m_config;
    const uint8_t target = playerCount >= config.m_lowRateThreshold ? config.m_highRateTarget : config.m_lowRateTarget;

    if (target != 0)
    {
        const nanoseconds deltaTime = duration_cast<nanoseconds>(high_resolution_clock::now() - s_lastTick);
        nanoseconds averageDelta = deltaTime;

        if (config.m_type == OptimizationType::OPTIMIZED)
        {
            // So ... here's how this works.
            // We want to *aim* for 100 ticks per second in this exampleThat equals out to about 10ms per frame.
            // If we just sleep for (last frame time - 10), then we will only ever hit 100 ticks if every frame is PERFECT.
            // We will almost certainly sleep for a little too long.
            // It's fine if we run a few frames per second above 100, but sleeping for no reason isn't cool.
            // We will gather the last ten frames then discard the quickest two in speed.
            // The average of the the remaining eight will be treated as our "last frame time".
            // That way, sometimes we will speed up, but we should almost never speed down.
            // This is HIGHLY important due to how the AI update system works.
            // It will shoot out a quick frame, then two or three long ones, then a quick one.
            // Under load, we DO NOT want to sleep due to that quick frame, ever.
            static std::vector<nanoseconds> s_lastFrameTimes;

            // Add our delta time into the big old vector.
            s_lastFrameTimes.emplace(std::begin(s_lastFrameTimes), deltaTime);

            while (s_lastFrameTimes.size() > 10)
            {
                // Pop the oldest delta times until we're at our target count.
                s_lastFrameTimes.pop_back();
            }

            // Make a copy, so we can sort it.
            std::vector<nanoseconds> deltaTimeCopy = s_lastFrameTimes;

            // Sort by descending.
            std::sort(std::begin(deltaTimeCopy), std::end(deltaTimeCopy),
                [](auto& first, auto& second) { return first > second; });

            while (deltaTimeCopy.size() > 8)
            {
                // Discard the fastest frames until we have 8 left.
                deltaTimeCopy.pop_back();
            }

            // Get the average.
            averageDelta = std::accumulate(std::begin(deltaTimeCopy), std::end(deltaTimeCopy), nanoseconds(0)) / deltaTimeCopy.size();
        }

        const auto targetFrameTime = nanoseconds(1'000'000'000 / target);

        if (deltaTime < targetFrameTime && averageDelta < targetFrameTime)
        {
            const auto sleepDuration = targetFrameTime - deltaTime;

            if (sleepDuration > nanoseconds(0))
            {
                std::this_thread::sleep_for(sleepDuration);
            }
        }
    }

    s_lastTick = high_resolution_clock::now();
}

}
