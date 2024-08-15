#include "HTTP.hpp"
#include "HTTP/Client.hpp"

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
}

HTTP::~HTTP()
= default;

}
