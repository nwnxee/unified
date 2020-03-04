#include "Experimental.hpp"
#include "Experimentals/SuppressPlayerLoginInfo.hpp"

#include "Services/Config/Config.hpp"


using namespace NWNXLib;

static Experimental::Experimental* g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Experimental",
        "Adds experimental functionality that's not really useful for the general user.",
        "Daz",
        "daztek@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Experimental::Experimental(params);
    return g_plugin;
}

namespace Experimental {

Experimental::Experimental(const Plugin::CreateParams& params)
        : Plugin(params)
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
