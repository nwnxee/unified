#include "HTTP/Client.hpp"

#include "Services/Config/Config.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "Services/Tasks/Tasks.hpp"

namespace Core {
    extern bool g_CoreShuttingDown;
}

using namespace NWNXLib;

namespace HTTP
{

TasksProxy* Client::m_servTasks;
MessagingProxy* Client::m_servMessaging;

Client::Client(ConfigProxy* config, EventsProxy* events, MessagingProxy* messaging, TasksProxy* tasks)
{
    events->RegisterEvent("Client_SendRequest", &SendRequest);
    events->RegisterEvent("Client_GetRequest", &GetRequest);
    m_servTasks = tasks;
    m_servMessaging = messaging;
    m_clientTimeout = config->Get<int>("CLIENT_REQUEST_TIMEOUT", 2000);
}

Client::~Client()
= default;

std::unique_ptr<httplib::Result> Client::GetResult(const Client::Request& client_req)
{
    std::unique_ptr<httplib::Result> result;
    auto cli = m_clientHostCache[client_req.host].get();
    switch(client_req.requestMethod)
    {
        case HTTP::RequestMethod::GET:
            result = std::make_unique<httplib::Result>(cli->Get(client_req.path.c_str(), client_req.headers));
            break;
        case HTTP::RequestMethod::POST:
            result = std::make_unique<httplib::Result>(cli->Post(client_req.path.c_str(), client_req.headers, client_req.data,HTTP::ContentTypeToString(client_req.contentType)));
            break;
        case HTTP::RequestMethod::DELETE:
            result = std::make_unique<httplib::Result>(cli->Delete(client_req.path.c_str(), client_req.headers, client_req.data, HTTP::ContentTypeToString(client_req.contentType)));
            break;
        case HTTP::RequestMethod::PATCH:
            result = std::make_unique<httplib::Result>(cli->Patch(client_req.path.c_str(), client_req.headers, client_req.data, HTTP::ContentTypeToString(client_req.contentType)));
            break;
        case HTTP::RequestMethod::PUT:
            result = std::make_unique<httplib::Result>(cli->Put(client_req.path.c_str(), client_req.headers, client_req.data, HTTP::ContentTypeToString(client_req.contentType)));
            break;
        case  HTTP::RequestMethod::OPTION:
            result = std::make_unique<httplib::Result>(cli->Options(client_req.path.c_str(), client_req.headers));
            break;
        case HTTP::RequestMethod::HEAD:
            result = std::make_unique<httplib::Result>(cli->Head(client_req.path.c_str(), client_req.headers));
            break;
    }

    return result;
}

void Client::PerformRequest(const Client::Request& client_req)
{
    auto cli = m_clientHostCache.find(client_req.host);
    if (cli == std::end(m_clientHostCache))
    {
        LOG_DEBUG("Creating new SSL client for host %s.", client_req.host);
        cli = m_clientHostCache.insert(std::make_pair(client_req.host, std::make_unique<httplib::SSLClient>(client_req.host.c_str(), client_req.port))).first;
    }

    if (client_req.authType == HTTP::AuthenticationType::BASIC)
        cli->second->set_basic_auth(client_req.authUserToken.c_str(), client_req.authPassword.c_str());
    else if (client_req.authType == HTTP::AuthenticationType::DIGEST)
        cli->second->set_digest_auth(client_req.authUserToken.c_str(), client_req.authPassword.c_str());
    else if (client_req.authType == HTTP::AuthenticationType::BEARER_TOKEN)
        cli->second->set_bearer_token_auth(client_req.authUserToken.c_str());

    if (Core::g_CoreShuttingDown)
    {
        // Shorter timeout when shutting down
        cli->second->set_connection_timeout(0, 300000);
        auto result = GetResult(client_req);
        auto res = result->value();

        if (res.status == 200)
            LOG_INFO("Sent webhook '%s' to '%s%s'.", client_req.data, client_req.host, client_req.path);
        else
            LOG_WARNING("HTTP Client Request to '%s%s' failed, status code '%d'.",client_req.data.c_str(), client_req.host.c_str(), client_req.path.c_str(), res.status);
        return;
    }
    m_servTasks->QueueOnAsyncThread([cli, client_req]()
    {
        cli->second->set_connection_timeout(0, m_clientTimeout * 1000);
        auto result = GetResult(client_req);

        auto clientError = result->error();
        if (clientError)
        {
            m_servTasks->QueueOnMainThread([client_req, clientError]()
            {
                auto moduleOid = NWNXLib::Utils::ObjectIDToString(((CGameObject*)Utils::GetModule())->m_idSelf);
                m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"REQUEST_ID", std::to_string(client_req.id)});
                m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"RESPONSE", "Failed to make a client request with server. Is the url/port correct?"});
                m_servMessaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_HTTP_CLIENT_FAILED", moduleOid});
                LOG_ERROR("HTTP Client Request to '%s%s' failed, [Error: %d].", client_req.host, client_req.path, clientError);
            });
            return;
        }
        auto res = result->value();
        m_servTasks->QueueOnMainThread([client_req, res]()
        {
            if (Core::g_CoreShuttingDown)
                return;

            auto moduleOid = Utils::ObjectIDToString(((CGameObject*)Utils::GetModule())->m_idSelf);
            if (res.status)
            {
                m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"STATUS", std::to_string(res.status)});
                m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"RESPONSE", res.body});
                m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"REQUEST_ID", std::to_string(client_req.id)});
                if (res.status == 200 || res.status == 201 || res.status == 204 || res.status == 429)
                {
                    // Discord sends your rate limit information even on success so you can stagger calls if you want
                    // This header also lets us know it's Discord not Slack, important because Discord sends RETRY_AFTER
                    // in milliseconds and Slack sends it as seconds.
                    if (res.has_header("X-RateLimit-Limit"))
                    {
                        m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"RATELIMIT_LIMIT", res.get_header_value("X-RateLimit-Limit")});
                        m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"RATELIMIT_REMAINING", res.get_header_value("X-RateLimit-Remaining")});
                        m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"RATELIMIT_RESET", res.get_header_value("X-RateLimit-Reset")});
                        if (res.has_header("Retry-After"))
                            m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"RETRY_AFTER", res.get_header_value("Retry-After")});
                        else if (res.has_header("Retry-At"))
                        {
                            m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"RETRY_AFTER", res.get_header_value("Retry-At")});
                        }
                    }
                    // Slack rate limited
                    else if (res.has_header("Retry-After"))
                    {
                        float fSlackRetry = stof(res.get_header_value("Retry-After")) * 1000.0f;
                        m_servMessaging->BroadcastMessage("NWNX_EVENT_PUSH_EVENT_DATA", {"RETRY_AFTER", std::to_string(fSlackRetry)});
                    }
                    if (res.status != 429)
                    {
                        m_servMessaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_HTTP_CLIENT_SUCCESS", moduleOid});
                        LOG_INFO("HTTP Client Request to '%s%s' succeeded.", client_req.host, client_req.path);
                    }
                    else
                    {
                        m_servMessaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_HTTP_CLIENT_FAILED", moduleOid});
                        LOG_WARNING("HTTP Client Request to '%s%s' failed, rate limited.", client_req.host, client_req.path);
                    }
                }
                else
                {
                    m_servMessaging->BroadcastMessage("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_HTTP_CLIENT_FAILED", moduleOid});
                    LOG_WARNING("HTTP Client Request to '%s%s' failed, status code '%d'.", client_req.host, client_req.path, res.status);
                }
            }
        });
    });
}

httplib::Headers Client::ParseHeaderString(const std::string& headerStr)
{
    httplib::Headers headers;
    if (!headerStr.empty())
    {
        std::string::size_type key_pos = 0;
        std::string::size_type key_end, val_pos, val_end;
        while((key_end = headerStr.find(':', key_pos)) != std::string::npos)
        {
            if((val_pos = headerStr.find_first_not_of(": ", key_end)) == std::string::npos)
                break;

            val_end = headerStr.find('|', val_pos);
            headers.emplace(headerStr.substr(key_pos, key_end - key_pos), headerStr.substr(val_pos, val_end - val_pos));

            key_pos = val_end;
            if(key_pos != std::string::npos)
                ++key_pos;
        }
    }
    return headers;
}

Events::ArgumentStack Client::SendRequest(Events::ArgumentStack&& args)
{
    auto clientReq = Request();
    clientReq.id = m_clientRequestId++;
    clientReq.oid = Services::Events::ExtractArgument<ObjectID>(args);
    clientReq.tag =  Services::Events::ExtractArgument<std::string>(args);
    clientReq.requestMethod = static_cast<HTTP::RequestMethod>(Services::Events::ExtractArgument<int>(args));
    clientReq.host =  Services::Events::ExtractArgument<std::string>(args);
    clientReq.path = Services::Events::ExtractArgument<std::string>(args);
    clientReq.contentType = static_cast<HTTP::ContentType>(Services::Events::ExtractArgument<int>(args));
    clientReq.data = Services::Events::ExtractArgument<std::string>(args);
    clientReq.authType = static_cast<HTTP::AuthenticationType>(Services::Events::ExtractArgument<int>(args));
    clientReq.authUserToken = Services::Events::ExtractArgument<std::string>(args);
    clientReq.authPassword = Services::Events::ExtractArgument<std::string>(args);
    clientReq.port =  Services::Events::ExtractArgument<int>(args);
    if (!clientReq.port) clientReq.port = 443;
    clientReq.headersString = Services::Events::ExtractArgument<std::string>(args);
    clientReq.headers = ParseHeaderString(clientReq.headersString);
    m_clientRequests[clientReq.id] = clientReq;
    PerformRequest(clientReq);

    return Services::Events::Arguments(clientReq.id);
}

Events::ArgumentStack Client::GetRequest(Events::ArgumentStack&& args)
{
    Events::ArgumentStack stack;
    auto requestId = Services::Events::ExtractArgument<int>(args);
    auto req = m_clientRequests.find(requestId);
    ASSERT_OR_THROW(req != std::end(m_clientRequests));
    auto clientReq = req->second;

    Services::Events::InsertArgument(stack, clientReq.headersString);
    Services::Events::InsertArgument(stack, (int32_t)clientReq.port);
    Services::Events::InsertArgument(stack, clientReq.authPassword);
    Services::Events::InsertArgument(stack, clientReq.authUserToken);
    Services::Events::InsertArgument(stack, (int32_t)clientReq.authType);
    Services::Events::InsertArgument(stack, clientReq.data);
    Services::Events::InsertArgument(stack, (int32_t)clientReq.contentType);
    Services::Events::InsertArgument(stack, clientReq.path);
    Services::Events::InsertArgument(stack, clientReq.host);
    Services::Events::InsertArgument(stack, (int32_t)clientReq.requestMethod);
    Services::Events::InsertArgument(stack, clientReq.tag);
    Services::Events::InsertArgument(stack, (ObjectID)clientReq.oid);
    return stack;
}

}
