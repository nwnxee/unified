#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"

namespace WebHook {

class WebHook : public NWNXLib::Plugin
{
public:
    WebHook(const Plugin::CreateParams& params);
    virtual ~WebHook();

    static NWNXLib::Services::Events::ArgumentStack OnSendWebhookHTTPS(NWNXLib::Services::Events::ArgumentStack&&);
};

}
