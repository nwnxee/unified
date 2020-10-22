#include "Experimental.hpp"
#include "Experimentals/SuppressPlayerLoginInfo.hpp"

#include "Services/Config/Config.hpp"


using namespace NWNXLib;

static Experimental::Experimental* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Experimental::Experimental(services);
    return g_plugin;
}

namespace Experimental {

Experimental::Experimental(Services::ProxyServiceList* services)
        : Plugin(services)
{
    if (GetServices()->m_config->Get<bool>("SUPPRESS_PLAYER_LOGIN_INFO", false))
    {
        LOG_INFO("EXPERIMENTAL: Suppressing playerlist and player login/logout messages for non DMs.");
        m_SuppressPlayerLoginInfo = std::make_unique<SuppressPlayerLoginInfo>(GetServices()->m_hooks.get());
    }
}

Experimental::~Experimental()
{
}

}
