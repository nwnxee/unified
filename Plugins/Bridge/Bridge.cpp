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

Bridge::Bridge(const Plugin::CreateParams& params)
    : Plugin(params)
{
    m_isClient = GetServices()->m_config->Get<bool>("CLIENT", true);
    std::string port = GetServices()->m_config->Get<std::string>("PORT", "8888");
    std::string password = GetServices()->m_config->Get<std::string>("PASSWORD", "");
    std::string userDir = NWNXLib::API::Globals::ExoBase()->m_sUserDirectory.CStr();

    if (!m_isClient)
    {
        std::string keypath = GetServices()->m_config->Get<std::string>("KEY_PATH", userDir + "/key.pem");
        std::string certpath = GetServices()->m_config->Get<std::string>("CERT_PATH", userDir + "/cert.pem");
        bool generateCerts = GetServices()->m_config->Get<bool>("SELFSIGN_CERT", false);
        m_bridgeInstance = std::make_unique<BridgeServer>(port, password, keypath, certpath, generateCerts);

        int webport = GetServices()->m_config->Get<int>("WEBSERVER_PORT", 0);
        if (webport > 0)
        {
            std::string webkey = GetServices()->m_config->Get<std::string>("WEBSERVER_KEY_PATH", "");
            std::string webcert = GetServices()->m_config->Get<std::string>("WEBSERVER_CERT_PATH", "");
            m_webserverInstance = std::make_unique<Webserver>(this, webport, password, webkey.empty() ? keypath : webkey, webcert.empty() ? certpath : webcert);
        }
    }
    else
    {
        std::string host = GetServices()->m_config->Get<std::string>("HOST", "localhost");
        m_bridgeInstance = std::make_unique<BridgeClient>(host, port, password);
    }

    Hooks::InitHooks(this, GetServices()->m_hooks.get());
}

bool Bridge::IsConnected()
{
    return m_bridgeInstance && m_bridgeInstance->IsConnected();
}

Bridge::~Bridge()
{}

}