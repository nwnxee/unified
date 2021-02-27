#include "nwnx.hpp"
#include "API/CNWSModule.hpp"
#include "External/httplib.h"
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace NWNXLib;

namespace Core {
extern bool g_CoreShuttingDown;
}

static std::string escape_json(const std::string &s) {
    std::ostringstream o;
    for (auto c = s.cbegin(); c != s.cend(); c++) {
        if (*c == '"' || *c == '\\' || ('\x00' <= *c && *c <= '\x1f')) {
            o << "\\u"
              << std::hex << std::setw(4) << std::setfill('0') << (int)*c;
        } else {
            o << *c;
        }
    }
    return o.str();
}

NWNX_EXPORT ArgumentStack SendWebHookHTTPS(ArgumentStack&& args)
{
    auto host = args.extract<std::string>();
    auto origPath = args.extract<std::string>();
    auto message = args.extract<std::string>();
    auto username = args.extract<std::string>();
    auto mrkdwn = args.extract<int32_t>();

    // If it's just a simple text string, construct the JSON
    if (message.find("\"text\":") == std::string::npos)
    {
        message = R"({"text": ")" + message + "\"";
        if (!username.empty())
            message = message + R"(, "username": ")" + username + "\"";
        if (!mrkdwn)
            message = message +  R"(, "mrkdwn": false)";
        message = message + "}";
    }

    // For Discord, will wait for a response
    auto path = origPath + "?wait=true";

    message = String::ToUTF8(message);
    escape_json(message);

    static std::unordered_map<std::string, std::unique_ptr<httplib::SSLClient>> s_ClientCache;
    auto cli = s_ClientCache.find(host);

    if (cli == std::end(s_ClientCache))
    {
        LOG_DEBUG("Creating new SSL client for host %s.", host);
        cli = s_ClientCache.insert(std::make_pair(host, std::make_unique<httplib::SSLClient>(host.c_str(), 443))).first;
    }

    if (Core::g_CoreShuttingDown)
    {
        auto res = cli->second->post(path.c_str(), message, "application/json");

        if (res->status == 200)
        {
            LOG_INFO("Sent webhook '%s' to '%s%s'.", message, host, path);
        }
        else
        {
            LOG_WARNING("Failed to send WebHook (HTTPS) message '%s' to '%s%s', status code '%d'.",
                        message.c_str(), host.c_str(), path.c_str(), res->status);
        }
    }
    else
    {
        Tasks::QueueOnAsyncThread([cli, message, host, path, origPath]()
        {
            auto res = cli->second->post(path.c_str(), message, "application/json");
            Tasks::QueueOnMainThread([message, host, path, origPath, res]()
            {
                if (Core::g_CoreShuttingDown)
                    return;

                auto moduleOid = NWNXLib::Utils::ObjectIDToString(Utils::GetModule()->m_idSelf);
                if (res)
                {
                    MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"STATUS", std::to_string(res->status)});
                    MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"MESSAGE", message});
                    MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"HOST", host});
                    MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"PATH", origPath});
                    if (res->status == 200 || res->status == 201 || res->status == 204 || res->status == 429)
                    {
                        // Discord sends your rate limit information even on success so you can stagger calls if you want
                        // This header also lets us know it's Discord not Slack, important because Discord sends RETRY_AFTER
                        // in milliseconds and Slack sends it as seconds.
                        if (!res->get_header_value("X-RateLimit-Limit").empty())
                        {
                            MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"RATELIMIT_LIMIT", res->get_header_value("X-RateLimit-Limit")});
                            MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"RATELIMIT_REMAINING", res->get_header_value("X-RateLimit-Remaining")});
                            MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"RATELIMIT_RESET", res->get_header_value("X-RateLimit-Reset")});
                            if (!res->get_header_value("Retry-After").empty())
                                MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"RETRY_AFTER", res->get_header_value("Retry-After")});
                        }
                            // Slack rate limited
                        else if (!res->get_header_value("Retry-After").empty())
                        {
                            float fSlackRetry = stof(res->get_header_value("Retry-After")) * 1000.0f;
                            MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"RETRY_AFTER", std::to_string(fSlackRetry)});
                        }
                        if (res->status != 429)
                        {
                            MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_WEBHOOK_SUCCESS", moduleOid});
                            LOG_INFO("Sent webhook '%s' to '%s%s'.", message, host, path);
                        }
                        else
                        {
                            MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_WEBHOOK_FAILED", moduleOid});
                            LOG_WARNING("Failed to send WebHook (HTTPS) message '%s' to '%s%s'. Rate Limited.", message, host, path);
                        }
                    }
                    else
                    {
                        MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"FAIL_INFO", res->body});
                        MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_WEBHOOK_FAILED", moduleOid});
                        LOG_WARNING("Failed to send WebHook (HTTPS) message '%s' to '%s%s', status code '%d'.", message, host, path, res->status);
                    }
                }
                else
                {
                    MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"FAIL_INFO", "Failed to post to server. Is the url correct?"});
                    MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_WEBHOOK_FAILED", moduleOid});
                    LOG_WARNING("Failed to send WebHook (HTTPS) to '%s%s'.", host, path);
                }
            });
        });
    }
    return {};
}
