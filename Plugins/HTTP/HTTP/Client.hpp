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
        }
    };
public:
    explicit Client(ConfigProxy*, EventsProxy*, MessagingProxy*, TasksProxy*);
private:
    static TasksProxy* m_servTasks;
    static MessagingProxy* m_servMessaging;

    static Events::ArgumentStack GetRequest(Events::ArgumentStack&&);
    static Events::ArgumentStack SendRequest(Events::ArgumentStack&&);

    static void PerformRequest(const Client::Request&);
    static std::unique_ptr<httplib::Result> GetResult(const Client::Request&);
    static httplib::Headers ParseHeaderString(const std::string&);
    static inline int m_clientRequestId = 0;
    static inline int m_clientTimeout = 2000;
    static inline std::unordered_map<std::string, std::unique_ptr<httplib::SSLClient>> m_clientHostCache;
    static inline std::unordered_map<int, Request> m_clientRequests;
};

}
