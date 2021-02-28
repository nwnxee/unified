#include "Redis.hpp"
#include "Internal.hpp"

#include "API/Functions.hpp"
#include "API/CNWVirtualMachineCommands.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static Redis::Redis* g_module;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    return (g_module = new Redis::Redis(services));
}

namespace Redis
{

using namespace NWNXLib::Services;

Redis::Redis(Services::ProxyServiceList* services)
    : Plugin(services)
{
    m_ClearStackHook = Hooks::HookFunction(Functions::_ZN20CVirtualMachineStack10ClearStackEv, (void*)&CleanState, Hooks::Order::Early);

    m_internal = new Internal(std::bind(&Redis::PoolMakeFunc, this));

    Reconfigure();

    RegisterWithNWScript();
}

Redis::~Redis()
{
    delete m_internal;
}

}
