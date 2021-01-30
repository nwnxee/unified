#pragma once

#include "nwnx.hpp"
#include "Services/Metrics/MetricData.hpp"

#include <array>
#include <chrono>
#include <numeric>

namespace Profiler {

class FastTimer
{
public:
    static constexpr uint8_t MAX_DEPTH = 32;

    void Start();
    void Stop(NWNXLib::Services::MetricsProxy& metrics, std::string&& eventName,
        NWNXLib::Services::MetricData::Tags&& tags = {});

public: // Calibration
    static void PrepareForCalibration(const std::chrono::nanoseconds val = std::chrono::nanoseconds(std::numeric_limits<int64_t>::max()));

    static void Calibrate(const size_t runs, NWNXLib::Services::MetricsProxy* metrics);

private:
    static uint8_t s_head;
    static uint8_t s_depth;

    static std::array<std::chrono::nanoseconds, MAX_DEPTH> s_debt;
    static std::chrono::nanoseconds s_hookOverhead;
    std::chrono::high_resolution_clock::time_point m_startTime;
    std::chrono::nanoseconds ConstructTimestampAndPop();
    std::chrono::high_resolution_clock::time_point GetCurrentTime();

private: // Calibration
    static NWNXLib::Services::MetricsProxy* g_metricsForCalibration;
    static int32_t ProfilerCalibrateHookFuncWithScope(CExoBase*, uint32_t);
};

class FastTimerScope
{
public:
    FastTimerScope(NWNXLib::Services::MetricsProxy& metrics, std::string&& eventName,
        NWNXLib::Services::MetricData::Tags&& tags = {});
    ~FastTimerScope();

private:
    NWNXLib::Services::MetricsProxy& m_metrics;
    std::string m_eventName;
    NWNXLib::Services::MetricData::Tags m_tags;
    FastTimer m_time;
};

}
