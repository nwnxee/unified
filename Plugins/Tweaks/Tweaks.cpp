#include "Tweaks.hpp"
#include "Tweaks/HideClassesOnCharList.hpp"

#include "Services/Config/Config.hpp"

using namespace NWNXLib;

static ViewPtr<Tweaks::Tweaks> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Tweaks",
        "Tweaks the behaviour of NWN.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Tweaks::Tweaks(params);
    return g_plugin;
}

namespace Tweaks {

Tweaks::Tweaks(const Plugin::CreateParams& params)
    : Plugin(params)
{
    if (GetServices()->m_config->Get<bool>("HIDE_CLASSES_ON_CHAR_LIST", false))
    {
        LOG_INFO("Hiding the display of classes on the character list.");
        m_HideClassesOnCharlist = std::make_unique<HideClassesOnCharList>(GetServices()->m_hooks.get());
    }
}

Tweaks::~Tweaks()
{
}

}
