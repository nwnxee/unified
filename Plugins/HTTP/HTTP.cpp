#include "HTTP.hpp"
#include "HTTP/Client.hpp"
#include "HTTP/RPC.hpp"
#include "HTTP/Server.hpp"
#include "Services/Config/Config.hpp"

using namespace NWNXLib;

static HTTP::HTTP* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new HTTP::HTTP(services);
    return g_plugin;
}

namespace HTTP {

HTTP::HTTP(Services::ProxyServiceList* services)
        : Plugin(services)
{
    auto tasks = GetServices()->m_tasks.get();
    auto messaging = GetServices()->m_messaging.get();
    auto events = GetServices()->m_events.get();
    auto config = GetServices()->m_config.get();

    m_Client = std::make_unique<Client>(config, events, messaging, tasks);
    bool bRPC = config->Get<bool>("RPC", false);
    if (config->Get<bool>("SERVER", false) || bRPC)
    {
        m_Server = std::make_unique<Server>(config, events, messaging, tasks);
        if (bRPC)
        {
            m_RPC = std::make_unique<RPC>(config, messaging, tasks);
        }
    }
}

HTTP::~HTTP()
= default;

}
