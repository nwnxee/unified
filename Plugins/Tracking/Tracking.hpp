#pragma once

#include "Plugin.hpp"
#include <memory>

namespace Tracking {

class Activity;

class Tracking : public NWNXLib::Plugin
{
public:
    Tracking(const Plugin::CreateParams& params);
    virtual ~Tracking();

private:
    std::unique_ptr<Activity> m_activityTarget;
};

}
