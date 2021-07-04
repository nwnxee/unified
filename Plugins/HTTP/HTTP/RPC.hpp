#pragma once
#include "HTTP.hpp"
#include "HTTP/Server.hpp"

namespace HTTP
{

using namespace NWNXLib::Services;

class RPC
{
public:
    explicit RPC(ConfigProxy*, MessagingProxy*, TasksProxy*);
private:
    static TasksProxy* m_servTasks;
    static MessagingProxy* m_servMessaging;

    static httplib::Server* WaitForWebServer(const std::atomic_bool&);
    void StartRPCServer();

    std::string m_authToken;
    std::string m_rpcURL;
};

}
