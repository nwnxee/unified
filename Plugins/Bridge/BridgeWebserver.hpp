#pragma once
#include <string>
#include <thread>

namespace Bridge
{
class Bridge;

class Webserver
{
private:
    static Bridge* s_bridge;
    std::unique_ptr<std::thread> m_thread;

public:
    Webserver(Bridge* bridge, int port, std::string pasword, std::string keypath, std::string certpath);
    ~Webserver() = default;
};

}
