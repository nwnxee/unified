#include "Optimizations.hpp"
#include "Optimizations/AsyncLogFlush.hpp"
#include "Optimizations/GameObjectLookup.hpp"
#include "Optimizations/ObjectTagLookup.hpp"
#include "Services/Config/Config.hpp"


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
    if (GetServices()->m_config->Get<bool>("ASYNC_LOG_FLUSH", false))
    {
        LOG_INFO("Game logs will be flushed asynchronously");
        m_AsyncLogFlush = std::make_unique<AsyncLogFlush>(GetServices()->m_hooks.get(), GetServices()->m_tasks.get());
    }

    if (GetServices()->m_config->Get<bool>("GAME_OBJECT_LOOKUP", false))
    {
        LOG_INFO("Using optimal CGameObjectArray implementation");
        m_GameObjectLookup = std::make_unique<GameObjectLookup>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("OBJECT_TAG_LOOKUP", false))
    {
        LOG_INFO("Optimizing GetObjectByTag() lookup");
        m_ObjectTagLookup = std::make_unique<ObjectTagLookup>(GetServices()->m_hooks.get());
    }
}

Optimizations::~Optimizations()
{
}

}
