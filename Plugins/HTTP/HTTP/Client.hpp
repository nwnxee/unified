#pragma once

#include "HTTP.hpp"
#include "Services/Events/Events.hpp"

namespace HTTP
{

using namespace NWNXLib::Services;

class Client
{
    struct Request
    {
        ObjectID oid;
        int id;
        HTTP::RequestMethod requestMethod;
        std::string host;
        int port;
        std::string path;
        HTTP::AuthenticationType authType;
        std::string authUserToken;
        std::string authPassword;
        HTTP::ContentType contentType;
        std::string data;
        std::string headersString;
        httplib::Headers headers;
        std::string tag;

        Request()
        {
            id = -1;
            requestMethod = HTTP::RequestMethod::GET;
            port = 443;
            authType = HTTP::AuthenticationType::NONE;
            contentType = HTTP::ContentType::HTML;
            oid = NWNXLib::API::Constants::OBJECT_INVALID;
        }
    };
public:
    explicit Client(ConfigProxy*, EventsProxy*, MessagingProxy*, TasksProxy*);
    virtual ~Client();
private:
    static TasksProxy* m_servTasks;
    static MessagingProxy* m_servMessaging;

    static Events::ArgumentStack GetRequest(Events::ArgumentStack&&);
    static Events::ArgumentStack SendRequest(Events::ArgumentStack&&);

    static void PerformRequest(const Client::Request&);
    static std::unique_ptr<httplib::Result> GetResult(const Client::Request&);
    static httplib::Headers ParseHeaderString(const std::string&);
    static int m_clientRequestId;
    static int m_clientTimeout;
    static std::unordered_map<std::string, std::unique_ptr<httplib::SSLClient>> m_clientHostCache;
    static std::unordered_map<int, Request> m_clientRequests;
};

}
