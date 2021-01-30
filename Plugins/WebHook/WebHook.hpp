#pragma once

#include "Plugin.hpp"
#include "Events.hpp"

using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace WebHook {

class WebHook : public NWNXLib::Plugin
{
public:
    WebHook(NWNXLib::Services::ProxyServiceList* services);
    virtual ~WebHook();
    static ArgumentStack SendWebHookHTTPS(ArgumentStack&&);
};

}
