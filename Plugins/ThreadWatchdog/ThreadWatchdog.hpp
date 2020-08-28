#pragma once

#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"
#include <memory>
#include <thread>

namespace ThreadWatchdog {

class ThreadWatchdog : public NWNXLib::Plugin
{
public:
    ThreadWatchdog(NWNXLib::Services::ProxyServiceList* services);
    virtual ~ThreadWatchdog();

private:
    static void MainLoopUpdate(bool, CServerExoAppInternal*);
    std::unique_ptr<std::thread> m_watchdog;
};

}
