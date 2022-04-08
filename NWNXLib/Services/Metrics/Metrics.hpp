#pragma once

#include "Services/Services.hpp"
#include "Services/Metrics/MetricData.hpp"
#include "Services/Metrics/Resamplers.hpp"

#include <chrono>
#include <functional>
#include <unordered_map>
#include <vector>

namespace NWNXLib::Services {

class Metrics
{
public: // Structures
    using MetricDataCallback = std::function<void(const std::vector<MetricData>&)>;
    using CallBackId = uint8_t;

    struct ResamplerData
    {
        Resamplers::ResamplerFunction m_resampler;
        std::vector<MetricData> m_unsampled;
        std::vector<MetricData> m_processing;
        std::chrono::nanoseconds m_interval;
        std::chrono::system_clock::time_point m_lastFlush;
        bool m_isWorkingAsynchronously;
    };

public:
    Metrics();
    ~Metrics();

    // These functions push raw metric data and COMPLETELY BYPASSES RESAMPLERS.
    void Push(MetricData&& data);
    void Push(std::vector<MetricData>&& data);

    // This function pushes metric data, calculates the timestamp automatically, and is subject
    // to the whims of any resampler which has been set.
    void Push(std::string&& name, MetricData::Fields&& fields, MetricData::Tags&& tags = {});

    CallBackId Subscribe(MetricDataCallback&& callback);
    void Unsubscribe(const CallBackId id);

    void SetResampler(std::string&& measurementName, Resamplers::ResamplerFunction&& resampler,
        std::chrono::nanoseconds&& interval);
    void ClearResampler(const std::string& measurementName);

    void Update();

private:
    std::vector<MetricData> m_data;
    std::unordered_map<CallBackId, MetricDataCallback> m_callbacks;
    std::unordered_map<std::string, std::unique_ptr<ResamplerData>> m_resamplers;

    std::chrono::nanoseconds GetTimestamp();
};

class MetricsProxy : public ServiceProxy<Metrics>
{
public:
    MetricsProxy(Metrics& metrics, std::string pluginName);
    ~MetricsProxy();

    void Push(MetricData&& data);
    void Push(const std::string& name, MetricData::Fields&& fields, MetricData::Tags&& tags = {});

    Metrics::CallBackId Subscribe(Metrics::MetricDataCallback&& callback);
    void Unsubscribe(const Metrics::CallBackId id);

    void SetResampler(const std::string& measurementName, Resamplers::ResamplerFunction&& resampler,
        std::chrono::nanoseconds&& interval);
    void ClearResampler(const std::string& measurementName);

private:
    std::string m_pluginName;
    std::vector<Metrics::CallBackId> m_callbacks;
    std::vector<std::string> m_resamplers;

    std::string ConstructName(const std::string& name);
};

}
