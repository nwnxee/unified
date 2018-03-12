#include "Redis.hpp"
#include "Internal.hpp"

#include "Services/Config/Config.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "ViewPtr.hpp"

#include "API/Functions.hpp"
#include "API/CNWVirtualMachineCommands.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Redis::Redis> g_module;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info {
        "Redis",
        "redis connector with pubsub support",
        "niv",
        "niv@nwnx.io",
        1,
        false
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    return (g_module = new Redis::Redis(params));
}

namespace Redis
{

using namespace NWNXLib::Services;
using namespace NWNXLib::Hooking;

Redis::Redis(const Plugin::CreateParams& params)
    : Plugin(params)
{
    m_internal = new Internal(std::bind(&Redis::PoolMakeFunc, this));

    Reconfigure();

    RegisterWithNWScript();
}

Redis::~Redis()
{
    delete m_internal;
}

}
