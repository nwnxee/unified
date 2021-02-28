#pragma once

#include "nwnx.hpp"
using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace Time {

class Time : public NWNXLib::Plugin
{
public:
    Time(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Time();

private:
    ArgumentStack GetTimeStamp                        (ArgumentStack&& args);
    ArgumentStack GetHighResTimeStamp                 (ArgumentStack&& args);
    ArgumentStack GetSystemDate                       (ArgumentStack&& args);
    ArgumentStack GetSystemTime                       (ArgumentStack&& args);
};

}
