#include "nwnx.hpp"
#include "External/httplib.h"

enum RequestMethod
{
    GET    = 0,
    POST   = 1,
    DEL = 2,
    PATCH  = 3,
    PUT    = 5,
    OPTION = 6,
    HEAD   = 7
};
enum AuthenticationType
{
    NONE         = 0,
    BASIC        = 1,
    DIGEST       = 2,
    BEARER_TOKEN = 3
};
enum ContentType
{
    HTML               = 0,
    PLAINTEXT          = 1,
    JSON               = 2,
    URL_ENCODED        = 3,
    XML                = 4,
};

struct Request
{
    int id;
    RequestMethod requestMethod;
    std::string host;
    int port;
    std::string path;
    AuthenticationType authType;
    std::string authUserToken;
    std::string authPassword;
    ContentType contentType;
    std::string data;
    std::string headersString;
    httplib::Headers headers;
    std::string tag;

    Request()
    {
        id = -1;
        requestMethod = RequestMethod::GET;
        port = 443;
        authType = AuthenticationType::NONE;
        contentType = ContentType::HTML;
    }
};

static constexpr const char* ContentTypeToString(const unsigned value)
{
    constexpr const char* TYPE_STRINGS[] =
    {
        "text/html",
        "text/plain",
        "application/json",
        "application/x-www-form-urlencoded",
        "application/xml"
    };
    return (value > 4) ? "text/html" : TYPE_STRINGS[value];
}

namespace Core {
    extern bool g_CoreShuttingDown;
}

using namespace NWNXLib;
using namespace NWNXLib::API;

static std::unique_ptr<httplib::Result> GetResult(const Request&);
static httplib::Headers ParseHeaderString(const std::string&);
static int s_clientRequestId = 0;
static int s_clientTimeout = Config::Get<int>("CLIENT_REQUEST_TIMEOUT", 2000);
static std::unordered_map<std::string, std::unique_ptr<httplib::SSLClient>> s_clientHostCache;
static std::unordered_map<int, Request> s_clientRequests;


std::unique_ptr<httplib::Result> GetResult(const Request &client_req)
{
    std::unique_ptr<httplib::Result> result;
    auto cli = s_clientHostCache[client_req.host].get();
    switch (client_req.requestMethod)
    {
        case RequestMethod::GET:
            result = std::make_unique<httplib::Result>(cli->Get(client_req.path.c_str(), client_req.headers));
            break;
        case RequestMethod::POST:
            result = std::make_unique<httplib::Result>(
                    cli->Post(client_req.path.c_str(), client_req.headers, client_req.data,
                              ContentTypeToString(client_req.contentType)));
            break;
        case RequestMethod::DEL:
            result = std::make_unique<httplib::Result>(
                    cli->Delete(client_req.path.c_str(), client_req.headers, client_req.data,
                                ContentTypeToString(client_req.contentType)));
            break;
        case RequestMethod::PATCH:
            result = std::make_unique<httplib::Result>(
                    cli->Patch(client_req.path.c_str(), client_req.headers, client_req.data,
                               ContentTypeToString(client_req.contentType)));
            break;
        case RequestMethod::PUT:
            result = std::make_unique<httplib::Result>(
                    cli->Put(client_req.path.c_str(), client_req.headers, client_req.data,
                             ContentTypeToString(client_req.contentType)));
            break;
        case RequestMethod::OPTION:
            result = std::make_unique<httplib::Result>(cli->Options(client_req.path.c_str(), client_req.headers));
            break;
        case RequestMethod::HEAD:
            result = std::make_unique<httplib::Result>(cli->Head(client_req.path.c_str(), client_req.headers));
            break;
    }

    return result;
}

void PerformRequest(const Request &client_req)
{
    auto cli = s_clientHostCache.find(client_req.host);
    if (cli == std::end(s_clientHostCache))
    {
        LOG_DEBUG("Creating new SSL client for host %s.", client_req.host);
        cli = s_clientHostCache.insert(std::make_pair(client_req.host,
                                                      std::make_unique<httplib::SSLClient>(client_req.host.c_str(),
                                                                                           client_req.port))).first;
    }

    if (client_req.authType == AuthenticationType::BASIC)
        cli->second->set_basic_auth(client_req.authUserToken.c_str(), client_req.authPassword.c_str());
    else if (client_req.authType == AuthenticationType::DIGEST)
        cli->second->set_digest_auth(client_req.authUserToken.c_str(), client_req.authPassword.c_str());
    else if (client_req.authType == AuthenticationType::BEARER_TOKEN)
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
            LOG_WARNING("HTTP Client Request to '%s%s' failed, status code '%d'.", client_req.data.c_str(),
                        client_req.host.c_str(), client_req.path.c_str(), res.status);
        return;
    }
    Tasks::QueueOnAsyncThread([cli, client_req]()
                              {
                                  cli->second->set_connection_timeout(0, s_clientTimeout * 1000);
                                  auto result = GetResult(client_req);

                                  if (result == nullptr || result->error() != httplib::Error::Success)
                                  {
                                      auto clientError =
                                              result != nullptr ? result->error() : httplib::Error::Unknown;
                                      Tasks::QueueOnMainThread([client_req, clientError]()
                                                               {
                                                                   MessageBus::Broadcast(
                                                                           "NWNX_EVENT_PUSH_EVENT_DATA",
                                                                           {"REQUEST_ID",
                                                                            std::to_string(client_req.id)});
                                                                   MessageBus::Broadcast(
                                                                           "NWNX_EVENT_PUSH_EVENT_DATA",
                                                                           {"RESPONSE",
                                                                            "Failed to make a client request with server. Is the url/port correct?"});
                                                                   MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT",
                                                                                         {"NWNX_ON_HTTPCLIENT_FAILED",
                                                                                          "0"});
                                                                   LOG_ERROR(
                                                                           "HTTP Client Request to '%s%s' failed, [Error: %d].",
                                                                           client_req.host, client_req.path,
                                                                           clientError);
                                                               });
                                      return;
                                  }
                                  auto response = result->value();
                                  Tasks::QueueOnMainThread([client_req, response]()
                                                           {
                                                               if (Core::g_CoreShuttingDown)
                                                                   return;

                                                               auto moduleOid = "0";

                                                               MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA",
                                                                                     {"STATUS", std::to_string(
                                                                                             response.status)});
                                                               MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA",
                                                                                     {"RESPONSE", String::FromUTF8(response.body)});
                                                               MessageBus::Broadcast("NWNX_EVENT_PUSH_EVENT_DATA",
                                                                                     {"REQUEST_ID", std::to_string(
                                                                                             client_req.id)});
                                                               if (response.status == 200 ||
                                                                   response.status == 201 ||
                                                                   response.status == 204 || response.status == 429)
                                                               {
                                                                   // Discord sends your rate limit information even on success so you can stagger calls if you want
                                                                   // This header also lets us know it's Discord not Slack, important because Discord sends RETRY_AFTER
                                                                   // in milliseconds and Slack sends it as seconds.
                                                                   if (response.has_header("X-RateLimit-Limit"))
                                                                   {
                                                                       MessageBus::Broadcast(
                                                                               "NWNX_EVENT_PUSH_EVENT_DATA",
                                                                               {"RATELIMIT_LIMIT",
                                                                                response.get_header_value(
                                                                                        "X-RateLimit-Limit")});
                                                                       MessageBus::Broadcast(
                                                                               "NWNX_EVENT_PUSH_EVENT_DATA",
                                                                               {"RATELIMIT_REMAINING",
                                                                                response.get_header_value(
                                                                                        "X-RateLimit-Remaining")});
                                                                       MessageBus::Broadcast(
                                                                               "NWNX_EVENT_PUSH_EVENT_DATA",
                                                                               {"RATELIMIT_RESET",
                                                                                response.get_header_value(
                                                                                        "X-RateLimit-Reset")});
                                                                       if (response.has_header("Retry-After"))
                                                                           MessageBus::Broadcast(
                                                                                   "NWNX_EVENT_PUSH_EVENT_DATA",
                                                                                   {"RETRY_AFTER",
                                                                                    response.get_header_value(
                                                                                            "Retry-After")});
                                                                       else if (response.has_header("Retry-At"))
                                                                       {
                                                                           MessageBus::Broadcast(
                                                                                   "NWNX_EVENT_PUSH_EVENT_DATA",
                                                                                   {"RETRY_AFTER",
                                                                                    response.get_header_value(
                                                                                            "Retry-At")});
                                                                       }
                                                                   }
                                                                       // Slack rate limited
                                                                   else if (response.has_header("Retry-After"))
                                                                   {
                                                                       float fSlackRetry =
                                                                               stof(response.get_header_value(
                                                                                       "Retry-After")) * 1000.0f;
                                                                       MessageBus::Broadcast(
                                                                               "NWNX_EVENT_PUSH_EVENT_DATA",
                                                                               {"RETRY_AFTER",
                                                                                std::to_string(fSlackRetry)});
                                                                   }
                                                                   if (response.status != 429)
                                                                   {
                                                                       MessageBus::Broadcast(
                                                                               "NWNX_EVENT_SIGNAL_EVENT",
                                                                               {"NWNX_ON_HTTPCLIENT_SUCCESS",
                                                                                moduleOid});
                                                                       LOG_INFO(
                                                                               "HTTP Client Request to '%s%s' succeeded.",
                                                                               client_req.host, client_req.path);
                                                                   }
                                                                   else
                                                                   {
                                                                       MessageBus::Broadcast(
                                                                               "NWNX_EVENT_SIGNAL_EVENT",
                                                                               {"NWNX_ON_HTTPCLIENT_FAILED",
                                                                                moduleOid});
                                                                       LOG_WARNING(
                                                                               "HTTP Client Request to '%s%s' failed, rate limited.",
                                                                               client_req.host, client_req.path);
                                                                   }
                                                               }
                                                               else
                                                               {
                                                                   MessageBus::Broadcast("NWNX_EVENT_SIGNAL_EVENT",
                                                                                         {"NWNX_ON_HTTPCLIENT_FAILED",
                                                                                          moduleOid});
                                                                   LOG_WARNING(
                                                                           "HTTP Client Request to '%s%s' failed, status code '%d'.",
                                                                           client_req.host, client_req.path,
                                                                           response.status);
                                                               }
                                                           });
                              });
}

httplib::Headers ParseHeaderString(const std::string &headerStr)
{
    httplib::Headers headers;
    if (!headerStr.empty())
    {
        std::string::size_type key_pos = 0;
        std::string::size_type key_end, val_pos, val_end;
        while ((key_end = headerStr.find(':', key_pos)) != std::string::npos)
        {
            if ((val_pos = headerStr.find_first_not_of(": ", key_end)) == std::string::npos)
                break;

            val_end = headerStr.find('|', val_pos);
            headers.emplace(headerStr.substr(key_pos, key_end - key_pos),
                            headerStr.substr(val_pos, val_end - val_pos));

            key_pos = val_end;
            if (key_pos != std::string::npos)
                ++key_pos;
        }
    }
    return headers;
}

NWNX_EXPORT ArgumentStack SendRequest(ArgumentStack &&args)
{
    auto clientReq = Request();
    clientReq.id = s_clientRequestId++;
    clientReq.tag = ScriptAPI::ExtractArgument<std::string>(args);
    clientReq.requestMethod = static_cast<RequestMethod>(ScriptAPI::ExtractArgument<int>(args));
    clientReq.host = ScriptAPI::ExtractArgument<std::string>(args);
    clientReq.path = ScriptAPI::ExtractArgument<std::string>(args);
    clientReq.contentType = static_cast<ContentType>(ScriptAPI::ExtractArgument<int>(args));
    clientReq.data = String::ToUTF8(ScriptAPI::ExtractArgument<std::string>(args));
    clientReq.authType = static_cast<AuthenticationType>(ScriptAPI::ExtractArgument<int>(args));
    clientReq.authUserToken = ScriptAPI::ExtractArgument<std::string>(args);
    clientReq.authPassword = ScriptAPI::ExtractArgument<std::string>(args);
    clientReq.port = ScriptAPI::ExtractArgument<int>(args);
    if (!clientReq.port) clientReq.port = 443;
    clientReq.headersString = ScriptAPI::ExtractArgument<std::string>(args);
    clientReq.headers = ParseHeaderString(clientReq.headersString);
    s_clientRequests[clientReq.id] = clientReq;
    PerformRequest(clientReq);

    return ScriptAPI::Arguments(clientReq.id);
}

NWNX_EXPORT ArgumentStack GetRequest(ArgumentStack &&args)
{
    ScriptAPI::ArgumentStack stack;
    auto requestId = ScriptAPI::ExtractArgument<int>(args);
    auto req = s_clientRequests.find(requestId);
    ASSERT_OR_THROW(req != std::end(s_clientRequests));
    auto clientReq = req->second;

    ScriptAPI::InsertArgument(stack, clientReq.headersString);
    ScriptAPI::InsertArgument(stack, (int32_t) clientReq.port);
    ScriptAPI::InsertArgument(stack, clientReq.authPassword);
    ScriptAPI::InsertArgument(stack, clientReq.authUserToken);
    ScriptAPI::InsertArgument(stack, (int32_t) clientReq.authType);
    ScriptAPI::InsertArgument(stack, clientReq.data);
    ScriptAPI::InsertArgument(stack, (int32_t) clientReq.contentType);
    ScriptAPI::InsertArgument(stack, clientReq.path);
    ScriptAPI::InsertArgument(stack, clientReq.host);
    ScriptAPI::InsertArgument(stack, (int32_t) clientReq.requestMethod);
    ScriptAPI::InsertArgument(stack, clientReq.tag);
    return stack;
}
