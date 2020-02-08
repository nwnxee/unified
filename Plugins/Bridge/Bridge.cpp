#include "Bridge.hpp"
#include "BridgeHooks.hpp"

#include "Services/Config/Config.hpp"
#include "API/Globals.hpp"
#include "API/API/CExoBase.hpp"

using namespace NWNXLib;

static Bridge::Bridge* g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Bridge",
        "WIP",
        "GoLoT",
        "golot@golot.es",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Bridge::Bridge(params);
    return g_plugin;
}

namespace Bridge
{

enum BridgeModules
{
    PLAYER_LIST,
    CHAT_BRIDGE
} BridgeModules;

Bridge::Bridge(const Plugin::CreateParams& params)
    : Plugin(params)
{
    m_isClient = GetServices()->m_config->Get<bool>("CLIENT", 1);
    std::string port = GetServices()->m_config->Get<std::string>("PORT", "8888");
    std::string password = GetServices()->m_config->Get<std::string>("PASSWORD", "");
    std::string userDir = NWNXLib::API::Globals::ExoBase()->m_sUserDirectory.CStr();

    if (!m_isClient)
    {
        std::string keypath = GetServices()->m_config->Get<std::string>("KEY_PATH", userDir + "/key.pem");
        std::string certpath = GetServices()->m_config->Get<std::string>("CERT_PATH", userDir + "/cert.pem");
        instance = std::make_unique<BridgeServer>(port, password, keypath, certpath);
    }
    else
    {
        std::string host = GetServices()->m_config->Get<std::string>("HOST", "localhost");
        instance = std::make_unique<BridgeClient>(host, port, password);
    }
    //instance->Start();

    Hooks::InitHooks(this, GetServices()->m_hooks.get());

    instance->Run();
}

Bridge::~Bridge()
{}

}