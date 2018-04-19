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

    static std::string iso_8859_1_to_utf8(std::string &str);

    bool m_bIso_8859_1;
};

}
