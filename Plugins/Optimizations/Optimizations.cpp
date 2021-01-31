#include "Optimizations.hpp"
#include "Optimizations/AsyncLogFlush.hpp"
#include "Optimizations/GameObjectLookup.hpp"


using namespace NWNXLib;

static Optimizations::Optimizations* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Optimizations::Optimizations(services);
    return g_plugin;
}

namespace Optimizations {

Optimizations::Optimizations(Services::ProxyServiceList* services)
        : Plugin(services)
{
    if (Config::Get<bool>("ASYNC_LOG_FLUSH", false))
    {
        LOG_INFO("Game logs will be flushed asynchronously");
        m_AsyncLogFlush = std::make_unique<AsyncLogFlush>();
    }

    if (Config::Get<bool>("GAME_OBJECT_LOOKUP", false))
    {
        LOG_INFO("Using optimal CGameObjectArray implementation");
        m_GameObjectLookup = std::make_unique<GameObjectLookup>();
    }
}

Optimizations::~Optimizations()
{
}

}
