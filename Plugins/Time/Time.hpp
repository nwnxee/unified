#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Time {

class Time : public NWNXLib::Plugin
{
public:
    Time(const Plugin::CreateParams& params);
    virtual ~Time();

private:
    ArgumentStack GetTimeStamp                       (ArgumentStack&& args);
    ArgumentStack GetSystemDate                       (ArgumentStack&& args);
    ArgumentStack GetSystemTime                       (ArgumentStack&& args);
};

}
