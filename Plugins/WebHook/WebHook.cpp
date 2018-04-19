#include "WebHook.hpp"
#include "API/Version.hpp"
#include "External/httplib.h"
#include <memory>
#include <unordered_map>

using namespace NWNXLib;

static ViewPtr<WebHook::WebHook> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "WebHook",
        "Users can send Slack-formatted HTTP/HTTPS webhooks with this plugin.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new WebHook::WebHook(params);
    return g_plugin;
}

using namespace NWNXLib::Services;

namespace WebHook {

WebHook::WebHook(const Plugin::CreateParams& params)
    : Plugin(params)
{
    GetServices()->m_events->RegisterEvent("SEND_WEBHOOK_HTTPS", &OnSendWebhookHTTPS);
}

WebHook::~WebHook()
{ }

Events::ArgumentStack WebHook::OnSendWebhookHTTPS(Events::ArgumentStack&& args)
{
    std::string host = Services::Events::ExtractArgument<std::string>(args);
    std::string path = Services::Events::ExtractArgument<std::string>(args);
    std::string message = Services::Events::ExtractArgument<std::string>(args);

    // Make sure to escape any quotes.
    // There are probably more things we have to escape too.
    size_t pos = 0;
    static const std::string s_Find = "\"";
    static const std::string s_Replace = "\\\"";
    while ((pos = message.find(s_Find, pos)) != std::string::npos)
    {
         message.replace(pos, s_Find.length(), s_Replace);
         pos += s_Replace.length();
    }

    message = "{\"text\":\"" + message + "\"}";

    static std::unordered_map<std::string, std::unique_ptr<httplib::SSLClient>> s_ClientCache;
    auto cli = s_ClientCache.find(host);

    if (cli == std::end(s_ClientCache))
    {
        LOG_DEBUG("Creating new SSL client for host %s.", host.c_str());
        cli = s_ClientCache.insert(std::make_pair(host, std::make_unique<httplib::SSLClient>(host.c_str(), 443))).first;
    }

    auto res = cli->second->post(path.c_str(), message, "application/json");

    if (res)
    {
        if (res->status == 200)
        {
            LOG_INFO("Sent webhook '%s' to '%s%s'.",
                message.c_str(), host.c_str(), path.c_str());
        }
        else
        {
            LOG_WARNING("Failed to send WebHook (HTTPS) message '%s' to '%s%s', status code '%d'.",
                message.c_str(), host.c_str(), path.c_str(), res->status);
        }
    }
    else
    {
        LOG_WARNING("Failed to send WebHook (HTTPS) to '%s%s'.",
            host.c_str(), path.c_str());
    }

    return Events::ArgumentStack();
}

}
