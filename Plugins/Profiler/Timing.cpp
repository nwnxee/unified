#include "Timing.hpp"

#include "API/CExoBase.hpp"
#include "API/CExoBaseInternal.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Services/Metrics/Resamplers.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

namespace Profiler {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

uint8_t FastTimer::s_head = 0;
uint8_t FastTimer::s_depth = 0;

std::array<std::chrono::nanoseconds, FastTimer::MAX_DEPTH> FastTimer::s_debt = {};
std::chrono::nanoseconds FastTimer::s_hookOverhead = std::chrono::nanoseconds(0);

MetricsProxy* FastTimer::g_metricsForCalibration;

static Hooks::Hook s_CheckForCDHook;

void FastTimer::Start()
{
    m_startTime = std::chrono::high_resolution_clock::now();

    if (s_head < s_depth++)
    {
        s_debt[++s_head] = std::chrono::nanoseconds(0);
    }
}

void FastTimer::Stop(MetricsProxy& metrics, std::string&& eventName, MetricData::Tags&& tags)
{
    auto time = ConstructTimestampAndPop();
    tags.push_back(std::make_pair("EventName", std::forward<std::string>(eventName)));
    metrics.Push("TimingEvent", { { "ns", std::to_string(time.count()) } }, std::forward<MetricData::Tags>(tags));
}

void FastTimer::PrepareForCalibration(const std::chrono::nanoseconds val)
{
    s_hookOverhead = val;
}

void FastTimer::Calibrate(const size_t runs, MetricsProxy* metrics)
{
    g_metricsForCalibration = metrics;

    // Set up a discard resampler for this one.
    auto resampler = &Resamplers::Discard;
    metrics->SetResampler("FAST_TIMER_OVERHEAD_CALIBRATION", resampler, std::chrono::seconds(10));

    const auto runTest = [](const size_t targetRuns) -> std::chrono::nanoseconds
    {
        auto total = std::chrono::nanoseconds(0);

        for (size_t i = 0; i < targetRuns; ++i)
        {
            auto before = std::chrono::high_resolution_clock::now();
            Globals::ExoBase()->CheckForCD(0);
            auto after = std::chrono::high_resolution_clock::now();
            total += std::chrono::duration_cast<std::chrono::nanoseconds>(after - before);
        }

        return total / targetRuns;
    };

    std::vector<std::chrono::nanoseconds> hookedResults;
    std::vector<std::chrono::nanoseconds> unhookedResults;

    for (size_t i = 0; i < runs; ++i)
    {
        unhookedResults.emplace_back(runTest(10));
    }

    s_CheckForCDHook = Hooks::HookFunction(&CExoBaseInternal::CheckForCD,
                                   &ProfilerCalibrateHookFuncWithScope, Hooks::Order::Earliest);
    for (size_t i = 0; i < runs; ++i)
    {
        hookedResults.emplace_back(runTest(10));
    }


    for (size_t i = 0; i < runs; ++i)
    {
        if (unhookedResults[i] > hookedResults[i])
        {
            // Probably a context switch. Ignore it.
            continue;
        }

        // Drop about 10% to account for the portion of overhead which the metric has *already* been part of.
        // This includes the "hook landing" overhead plus the first bit of the scope overhead.
        // Most of the time is spent pushing the metric which this timing does not include.
        const auto calculatedOverhead = hookedResults[i] - unhookedResults[i];
        const std::chrono::nanoseconds adjustedOverhead = calculatedOverhead - (calculatedOverhead / 10);

        // Only decrease ... never increase. We want to get the lowest possible reading for our potential overhead.
        s_hookOverhead = std::chrono::nanoseconds(std::min(s_hookOverhead.count(), adjustedOverhead.count()));
    }

    // Clear the dirty things we just did!
    metrics->ClearResampler("FAST_TIMER_OVERHEAD_CALIBRATION");
}

std::chrono::nanoseconds FastTimer::ConstructTimestampAndPop()
{
    --s_depth;

    const bool isRoot = s_depth == 0;
    const bool isApproachingRoot = s_depth == s_head - 1;

    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_startTime);

    if (isRoot || isApproachingRoot)
    {
        // Consume debt.
        const auto debt = s_debt[s_head];

        // It is technically possible for the below calculation to take us into negative.
        // This can occur if the overhead compensation is too aggressive.
        time -= debt;
        s_debt[s_head] = std::chrono::nanoseconds(0);

        if (!isRoot)
        {
            s_debt[--s_head] += debt + time + s_hookOverhead;
        }
    }
    else
    {
        // Accumlate debt.
        s_debt[s_head] += time + s_hookOverhead;
    }

    return time;
}

int32_t FastTimer::ProfilerCalibrateHookFuncWithScope(CExoBase *thisPtr, uint32_t nLanguage)
{
    static FastTimer timer;

    timer.Start();
    auto retVal = s_CheckForCDHook->CallOriginal<int32_t>(thisPtr, nLanguage);
    timer.Stop(*g_metricsForCalibration, "FAST_TIMER_OVERHEAD_CALIBRATION");

    return retVal;
}

FastTimerScope::FastTimerScope(MetricsProxy& metrics, std::string&& eventName, MetricData::Tags&& tags)
    : m_metrics(metrics),
      m_eventName(std::forward<std::string>(eventName)),
      m_tags(std::forward<MetricData::Tags>(tags))
{
    m_time.Start();
}

FastTimerScope::~FastTimerScope()
{
    m_time.Stop(m_metrics, std::move(m_eventName), std::move(m_tags));
}

}
