#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace WebHook {

class WebHook : public NWNXLib::Plugin
{
public:
    WebHook(const Plugin::CreateParams& params);
    virtual ~WebHook();

private:
    ArgumentStack OnSendWebHookHTTPS(NWNXLib::Services::Events::ArgumentStack&&);
    ArgumentStack EncodeURL(NWNXLib::Services::Events::ArgumentStack&&);
};

}
