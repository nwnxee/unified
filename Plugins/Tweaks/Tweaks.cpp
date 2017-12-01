#include "Tweaks.hpp"
#include "API/Version.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Patching/Patching.hpp"
#include "ViewPtr.hpp"
#include <cstring>

using namespace NWNXLib;

static ViewPtr<Tweaks::Tweaks> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Tweaks",
        "Provides various game tweaks.",
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

}

Tweaks::~Tweaks()
{
}

}
