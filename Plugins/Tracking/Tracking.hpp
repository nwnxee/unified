#pragma once

#include "nwnx.hpp"
#include <memory>

namespace Tracking {

class Activity;

class Tracking : public NWNXLib::Plugin
{
public:
    Tracking(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Tracking();

private:
    std::unique_ptr<Activity> m_activityTarget;
};

}
