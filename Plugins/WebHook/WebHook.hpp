#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace WebHook {

class WebHook : public NWNXLib::Plugin
{
public:
    WebHook(NWNXLib::Services::ProxyServiceList* services);
    virtual ~WebHook();
    static ArgumentStack SendWebHookHTTPS(NWNXLib::Services::Events::ArgumentStack&&);
};

}
