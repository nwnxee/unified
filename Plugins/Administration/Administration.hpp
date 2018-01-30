#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"

namespace Administration {

class Administration : public NWNXLib::Plugin
{
public:
    Administration(const Plugin::CreateParams& params);
    virtual ~Administration();

    NWNXLib::Services::Events::ArgumentStack OnGetPlayerPassword(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnSetPlayerPassword(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnClearPlayerPassword(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetDMPassword(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnSetDMPassword(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnShutdownServer(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnBootPCWithMessage(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnDeletePlayerCharacter(NWNXLib::Services::Events::ArgumentStack&& args);
};

}
