#pragma once

#include "Common.hpp"
#include "ViewPtr.hpp"

#include <sys/socket.h>

namespace Repair {

class DDoS
{
public:
    DDoS(bool netMetrics,
        bool ddosMetrics,
        NWNXLib::ViewPtr<NWNXLib::Services::MetricsProxy> metrics,
        NWNXLib::ViewPtr<NWNXLib::Services::PatchingProxy> patcher,
        NWNXLib::ViewPtr<NWNXLib::Services::TasksProxy> tasks,
        NWNXLib::ViewPtr<NWNXLib::Services::LogProxy> log);

private:
    static ssize_t RecvFromPatch(int, void*, size_t, int, sockaddr*, socklen_t*);
};

}
