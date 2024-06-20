#include "HTTP.hpp"
#include "HTTP/Client.hpp"
#include "HTTP/RPC.hpp"
#include "HTTP/Server.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

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
    m_Client = std::make_unique<Client>();
    bool bRPC = Config::Get<bool>("RPC", false);
    if (Config::Get<bool>("SERVER", false) || bRPC)
    {
        m_Server = std::make_unique<Server>();
        if (bRPC)
        {
            m_RPC = std::make_unique<RPC>();
        }
    }
}

HTTP::~HTTP()
= default;

}
