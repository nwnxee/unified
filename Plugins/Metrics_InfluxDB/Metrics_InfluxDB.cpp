#include "Metrics_InfluxDB.hpp"
#include "InfluxDBClient.hpp"

using namespace NWNXLib;

static Metrics_InfluxDB::Metrics_InfluxDB* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Metrics_InfluxDB::Metrics_InfluxDB(services);
    return g_plugin;
}

namespace Metrics_InfluxDB {

using namespace NWNXLib::Services;

Metrics_InfluxDB::Metrics_InfluxDB(Services::ProxyServiceList* services)
    : Plugin(services)
{
    auto host = *Config::Get<std::string>("HOST");
    auto port = *Config::Get<int32_t>("PORT");
    m_influxDbClient = std::make_unique<InfluxDBClient>(std::move(host), static_cast<uint16_t>(port));
    GetServices()->m_metrics->Subscribe(&OnReceiveData);
}

Metrics_InfluxDB::~Metrics_InfluxDB()
{
}

void Metrics_InfluxDB::OnReceiveData(const std::vector<MetricData>& data)
{
    Tasks::QueueOnAsyncThread(
        [dataCopy = std::vector<MetricData>(data)]() mutable
        {
            g_plugin->PushData(std::move(dataCopy));
        }
    );
}

void Metrics_InfluxDB::PushData(std::vector<MetricData>&& dataVec)
{
    std::lock_guard<std::mutex> scopeLock(m_lock);

    for (MetricData& data : dataVec)
    {
        m_influxDbClient->Send(data);
    }
}

}
