#include "HTTP/Client.hpp"

namespace Core {
    extern bool g_CoreShuttingDown;
}

using namespace NWNXLib;

namespace HTTP
{

Client::Client()
{
    Events::RegisterEvent(PLUGIN_NAME, "Client_SendRequest", &SendRequest);
    Events::RegisterEvent(PLUGIN_NAME, "Client_GetRequest", &GetRequest);
    m_clientTimeout = Config::Get<int>("CLIENT_REQUEST_TIMEOUT", 2000);
}

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
    Tasks::QueueOnAsyncThread([cli, client_req]()
    {
        cli->second->set_connection_timeout(0, m_clientTimeout * 1000);
        auto result = GetResult(client_req);

        if (result == nullptr || result->error())
        {
            auto clientError = result != nullptr ? result->error() : httplib::Error::Unknown;
            Tasks::QueueOnMainThread([client_req, clientError]()
            {
                MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"REQUEST_ID", std::to_string(client_req.id)});
                MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"RESPONSE", "Failed to make a client request with server. Is the url/port correct?"});
                MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_HTTP_CLIENT_FAILED", "0"});
                LOG_ERROR("HTTP Client Request to '%s%s' failed, [Error: %d].", client_req.host, client_req.path, clientError);
            });
            return;
        }
        auto response = result->value();
        Tasks::QueueOnMainThread([client_req, response]()
        {
            if (Core::g_CoreShuttingDown)
                return;

            auto moduleOid = "0";

            MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"STATUS", std::to_string(response.status)});
            MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"RESPONSE", response.body});
            MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"REQUEST_ID", std::to_string(client_req.id)});
            if (response.status == 200 || response.status == 201 || response.status == 204 || response.status == 429)
            {
                // Discord sends your rate limit information even on success so you can stagger calls if you want
                // This header also lets us know it's Discord not Slack, important because Discord sends RETRY_AFTER
                // in milliseconds and Slack sends it as seconds.
                if (response.has_header("X-RateLimit-Limit"))
                {
                    MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"RATELIMIT_LIMIT", response.get_header_value("X-RateLimit-Limit")});
                    MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"RATELIMIT_REMAINING", response.get_header_value("X-RateLimit-Remaining")});
                    MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"RATELIMIT_RESET", response.get_header_value("X-RateLimit-Reset")});
                    if (response.has_header("Retry-After"))
                        MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"RETRY_AFTER", response.get_header_value("Retry-After")});
                    else if (response.has_header("Retry-At"))
                    {
                        MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"RETRY_AFTER", response.get_header_value("Retry-At")});
                    }
                }
                // Slack rate limited
                else if (response.has_header("Retry-After"))
                {
                    float fSlackRetry = stof(response.get_header_value("Retry-After")) * 1000.0f;
                    MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA", {"RETRY_AFTER", std::to_string(fSlackRetry)});
                }
                if (response.status != 429)
                {
                    MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_HTTP_CLIENT_SUCCESS", moduleOid});
                    LOG_INFO("HTTP Client Request to '%s%s' succeeded.", client_req.host, client_req.path);
                }
                else
                {
                    MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_HTTP_CLIENT_FAILED", moduleOid});
                    LOG_WARNING("HTTP Client Request to '%s%s' failed, rate limited.", client_req.host, client_req.path);
                }
            }
            else
            {
                MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT", {"NWNX_ON_HTTP_CLIENT_FAILED", moduleOid});
                LOG_WARNING("HTTP Client Request to '%s%s' failed, status code '%d'.", client_req.host, client_req.path, response.status);
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
    clientReq.tag =  Events::ExtractArgument<std::string>(args);
    clientReq.requestMethod = static_cast<HTTP::RequestMethod>(Events::ExtractArgument<int>(args));
    clientReq.host =  Events::ExtractArgument<std::string>(args);
    clientReq.path = Events::ExtractArgument<std::string>(args);
    clientReq.contentType = static_cast<HTTP::ContentType>(Events::ExtractArgument<int>(args));
    clientReq.data = Events::ExtractArgument<std::string>(args);
    clientReq.authType = static_cast<HTTP::AuthenticationType>(Events::ExtractArgument<int>(args));
    clientReq.authUserToken = Events::ExtractArgument<std::string>(args);
    clientReq.authPassword = Events::ExtractArgument<std::string>(args);
    clientReq.port =  Events::ExtractArgument<int>(args);
    if (!clientReq.port) clientReq.port = 443;
    clientReq.headersString = Events::ExtractArgument<std::string>(args);
    clientReq.headers = ParseHeaderString(clientReq.headersString);
    m_clientRequests[clientReq.id] = clientReq;
    PerformRequest(clientReq);

    return Events::Arguments(clientReq.id);
}

Events::ArgumentStack Client::GetRequest(Events::ArgumentStack&& args)
{
    Events::ArgumentStack stack;
    auto requestId = Events::ExtractArgument<int>(args);
    auto req = m_clientRequests.find(requestId);
    ASSERT_OR_THROW(req != std::end(m_clientRequests));
    auto clientReq = req->second;

    Events::InsertArgument(stack, clientReq.headersString);
    Events::InsertArgument(stack, (int32_t)clientReq.port);
    Events::InsertArgument(stack, clientReq.authPassword);
    Events::InsertArgument(stack, clientReq.authUserToken);
    Events::InsertArgument(stack, (int32_t)clientReq.authType);
    Events::InsertArgument(stack, clientReq.data);
    Events::InsertArgument(stack, (int32_t)clientReq.contentType);
    Events::InsertArgument(stack, clientReq.path);
    Events::InsertArgument(stack, clientReq.host);
    Events::InsertArgument(stack, (int32_t)clientReq.requestMethod);
    Events::InsertArgument(stack, clientReq.tag);
    return stack;
}

}
