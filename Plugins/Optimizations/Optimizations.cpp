#include "Optimizations.hpp"
#include "Optimizations/AsyncLogFlush.hpp"
#include "Optimizations/GameObjectLookup.hpp"
#include "Optimizations/ObjectTagLookup.hpp"
#include "Services/Config/Config.hpp"


using namespace NWNXLib;

static Optimizations::Optimizations* g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Optimizations",
        "Optimizations that improve performance of various game elements",
        "mtijanic",
        "sherincall@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Optimizations::Optimizations(params);
    return g_plugin;
}

namespace Optimizations {

Optimizations::Optimizations(const Plugin::CreateParams& params)
        : Plugin(params)
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
