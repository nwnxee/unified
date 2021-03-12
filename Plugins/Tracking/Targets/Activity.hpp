#pragma once

#include "nwnx.hpp"

namespace Tracking {

class Activity
{
public:
    Activity(NWNXLib::Services::MetricsProxy* metrics);

private:
    static int32_t MainLoopUpdate(CServerExoAppInternal*);
};

}
