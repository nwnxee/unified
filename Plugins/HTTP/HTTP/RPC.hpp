#pragma once
#include "HTTP.hpp"
#include "HTTP/Server.hpp"

namespace HTTP
{

using namespace NWNXLib::Services;

class RPC
{
public:
    explicit RPC();
private:

    static httplib::Server* WaitForWebServer(const std::atomic_bool&);
    void StartRPCServer();

    std::string m_authToken;
    std::string m_rpcURL;
};

}
