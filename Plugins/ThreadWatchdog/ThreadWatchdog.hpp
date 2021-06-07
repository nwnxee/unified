#pragma once

#include "nwnx.hpp"
#include <memory>
#include <thread>

namespace ThreadWatchdog {

class ThreadWatchdog : public NWNXLib::Plugin
{
public:
    ThreadWatchdog(NWNXLib::Services::ProxyServiceList* services);
    virtual ~ThreadWatchdog();

private:
    static int32_t MainLoopUpdate(CServerExoAppInternal*);
    std::unique_ptr<std::thread> m_watchdog;
};

}
