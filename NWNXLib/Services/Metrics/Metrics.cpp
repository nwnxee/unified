#include "nwnx.hpp"
#include "Services/Metrics/Metrics.hpp"

#include <algorithm>
#include <thread>

namespace NWNXLib::Services {

Metrics::Metrics()
{
}

Metrics::~Metrics()
{
}

void Metrics::Push(MetricData&& data)
{
    m_data.emplace_back(std::forward<MetricData>(data));
}

void Metrics::Push(std::vector<MetricData>&& data)
{
    m_data.insert(std::end(m_data),
        std::make_move_iterator(std::begin(data)),
        std::make_move_iterator(std::end(data)));
}

void Metrics::Push(std::string&& name, MetricData::Fields&& fields, MetricData::Tags&& tags)
{
    MetricData data =
    {
        {},
        std::forward<std::string>(name),
        std::forward<MetricData::Fields>(fields),
        std::forward<MetricData::Tags>(tags)
    };

    auto resampler = m_resamplers.find(data.m_name);

    if (resampler == std::end(m_resamplers))
    {
        using namespace std::chrono;
#if !WIN32
        data.m_timestamp = std::chrono::system_clock::now();
#endif
        m_data.emplace_back(std::forward<MetricData>(data));
    }
    else
    {
        // Don't calculate the timestamp as this will be calculated automatically later on based on the interval.
        resampler->second->m_unsampled.emplace_back(std::forward<MetricData>(data));
    }
}

Metrics::CallBackId Metrics::Subscribe(Metrics::MetricDataCallback&& callback)
{
    static uint8_t s_nextCbId = 0;
    uint8_t nextId = s_nextCbId++;
    m_callbacks.insert(std::make_pair(nextId, std::forward<MetricDataCallback>(callback)));
    return nextId;
}

void Metrics::Unsubscribe(const CallBackId id)
{
    auto cb = m_callbacks.find(id);

    if (cb == std::end(m_callbacks))
    {
        throw std::runtime_error("Tried to unsubscribe with a callback that was not subscribed.");
    }

    m_callbacks.erase(cb);
}

void Metrics::SetResampler(std::string&& measurementName, Resamplers::ResamplerFunction&& resampler,
    std::chrono::nanoseconds&& interval)
{
    auto existingResampler = m_resamplers.find(measurementName);

    if (existingResampler != std::end(m_resamplers))
    {
        throw std::runtime_error("Tried to register a resampler for a measurement that was already registered.");
    }

    ResamplerData data =
    {
        std::forward<Resamplers::ResamplerFunction>(resampler),
        std::vector<MetricData>(),
        std::vector<MetricData>(),
        std::forward<std::chrono::nanoseconds>(interval),
        std::chrono::system_clock::time_point(),
        false
    };

    m_resamplers.insert(std::make_pair(
        std::forward<std::string>(measurementName),
        std::make_unique<ResamplerData>(std::move(data))
    ));
}

void Metrics::ClearResampler(const std::string& measurementName)
{
    auto existingResampler = m_resamplers.find(measurementName);

    if (existingResampler == std::end(m_resamplers))
    {
        throw std::runtime_error("Tried to clear a resampler from a measurement which had no resampler applied.");
    }

    while (existingResampler->second->m_isWorkingAsynchronously)
    {
        // Don't free the resampler until it has finished its work on the async thread.
        std::this_thread::yield();
    }

    m_resamplers.erase(existingResampler);
}

void Metrics::Update()
{
    for (auto& resampler : m_resamplers)
    {
        ResamplerData* data = resampler.second.get();

        if (data->m_isWorkingAsynchronously)
        {
            continue;
        }

        using namespace std::chrono;
        system_clock::time_point now = system_clock::now();
        const auto passed = duration_cast<nanoseconds>(now - data->m_lastFlush);

        if (passed >= data->m_interval)
        {
            std::swap(data->m_unsampled, data->m_processing);
            data->m_isWorkingAsynchronously = true;

            Tasks::QueueOnAsyncThread(
                [this, data, now]
                {
                    auto targetTimepoint = now;

                    if (data->m_interval != seconds(0))
                    {
                        // With a target interval of 1000ms, if we pushed at 1200ms, this would set the last flush to be 1000ms.
                        const auto lastFlushAsNs = duration_cast<nanoseconds>(now.time_since_epoch());
                        const auto targetTimestamp = (lastFlushAsNs / data->m_interval) * data->m_interval;
#if !WIN32
                        targetTimepoint -= lastFlushAsNs - targetTimestamp;
#endif
                    }

                    auto resampledData = data->m_resampler(std::move(data->m_processing));

                    for (auto& entry : resampledData)
                    {
#if !WIN32
                        entry.m_timestamp = targetTimepoint;
#endif
                    }

                    data->m_lastFlush = targetTimepoint;
                    data->m_processing.clear();

                    Tasks::QueueOnMainThread(
                        [this, resampledData = std::move(resampledData)]() mutable
                        {
                            this->Push(std::move(resampledData));
                        }
                    );

                    data->m_isWorkingAsynchronously = false;
                }
            );
        }
    }

    for (const auto& callback : m_callbacks)
    {
        callback.second(m_data);
    }

    m_data.clear();
}

MetricsProxy::MetricsProxy(Metrics& metrics, std::string pluginName)
    : ServiceProxy<Metrics>(metrics), m_pluginName(std::move(pluginName))
{
}

MetricsProxy::~MetricsProxy()
{
    for (auto& cb : m_callbacks)
    {
        m_proxyBase.Unsubscribe(std::move(cb));
    }

    for (auto& resampler : m_resamplers)
    {
        m_proxyBase.ClearResampler(std::move(resampler));
    }

    m_callbacks.clear();
    m_resamplers.clear();
}

void MetricsProxy::Push(MetricData&& data)
{
    data.m_name = ConstructName(data.m_name);
    m_proxyBase.Push(std::forward<MetricData>(data));
}

void MetricsProxy::Push(const std::string& name, MetricData::Fields&& fields,
    MetricData::Tags&& tags)
{
    m_proxyBase.Push(ConstructName(name),
        std::forward<MetricData::Fields>(fields),
        std::forward<MetricData::Tags>(tags));
}

Metrics::CallBackId MetricsProxy::Subscribe(Metrics::MetricDataCallback&& callback)
{
    const Metrics::CallBackId id = m_proxyBase.Subscribe(std::forward<Metrics::MetricDataCallback>(callback));
    m_callbacks.emplace_back(id);
    return id;
}

void MetricsProxy::Unsubscribe(const Metrics::CallBackId id)
{
    auto cb = std::find(std::begin(m_callbacks), std::end(m_callbacks), id);

    if (cb == std::end(m_callbacks))
    {
        throw std::runtime_error("Tried to unsubscribe with a callback that was not subscribed.");
    }

    m_proxyBase.Unsubscribe(id);
    m_callbacks.erase(cb);
}

void MetricsProxy::SetResampler(const std::string& measurementName, Resamplers::ResamplerFunction&& resampler,
    std::chrono::nanoseconds&& interval)
{
    std::string name = ConstructName(measurementName);
    m_resamplers.emplace_back(name);
    m_proxyBase.SetResampler(std::move(name), std::forward<Resamplers::ResamplerFunction>(resampler),
        std::forward<std::chrono::nanoseconds>(interval));
}

void MetricsProxy::ClearResampler(const std::string& measurementName)
{
    const std::string name = ConstructName(measurementName);
    auto resampler = std::find(std::begin(m_resamplers), std::end(m_resamplers), name);

    if (resampler == std::end(m_resamplers))
    {
        throw std::runtime_error("Tried to clear a resampler from a measurement which had no resampler applied.");
    }

    m_proxyBase.ClearResampler(name);
    m_resamplers.erase(resampler);
}

std::string MetricsProxy::ConstructName(const std::string& name)
{
    return name[0] == '.' ? m_pluginName + name : m_pluginName + "." + name;
}

}
