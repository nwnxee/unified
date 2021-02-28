#pragma once

#include "nwnx.hpp"
#include "Services/Metrics/MetricData.hpp"

#include <memory>
#include <mutex>

namespace Metrics_InfluxDB {

class InfluxDBClient;

class Metrics_InfluxDB : public NWNXLib::Plugin
{
public:
    Metrics_InfluxDB(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Metrics_InfluxDB();

    static void OnReceiveData(const std::vector<NWNXLib::Services::MetricData>& data);

    void PushData(std::vector<NWNXLib::Services::MetricData>&& data);

private:
    std::unique_ptr<InfluxDBClient> m_influxDbClient;
    std::mutex m_lock;
};

}
