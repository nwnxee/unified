#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Administration {

class Administration : public NWNXLib::Plugin
{
public:
    Administration(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Administration();

    ArgumentStack GetPlayerPassword         (ArgumentStack&& args);
    ArgumentStack SetPlayerPassword         (ArgumentStack&& args);
    ArgumentStack ClearPlayerPassword       (ArgumentStack&& args);
    ArgumentStack GetDMPassword             (ArgumentStack&& args);
    ArgumentStack SetDMPassword             (ArgumentStack&& args);
    ArgumentStack ShutdownServer            (ArgumentStack&& args);
    ArgumentStack DeletePlayerCharacter     (ArgumentStack&& args);
    ArgumentStack AddBannedIP               (ArgumentStack&& args);
    ArgumentStack RemoveBannedIP            (ArgumentStack&& args);
    ArgumentStack AddBannedCDKey            (ArgumentStack&& args);
    ArgumentStack RemoveBannedCDKey         (ArgumentStack&& args);
    ArgumentStack AddBannedPlayerName       (ArgumentStack&& args);
    ArgumentStack RemoveBannedPlayerName    (ArgumentStack&& args);
    ArgumentStack GetBannedList             (ArgumentStack&& args);
    ArgumentStack SetModuleName             (ArgumentStack&& args);
    ArgumentStack SetServerName             (ArgumentStack&& args);
    ArgumentStack GetServerName             (ArgumentStack&& args);
    ArgumentStack GetPlayOption             (ArgumentStack&& args);
    ArgumentStack SetPlayOption             (ArgumentStack&& args);
    ArgumentStack DeleteTURD                (ArgumentStack&& args);
    ArgumentStack GetDebugValue             (ArgumentStack&& args);
    ArgumentStack SetDebugValue             (ArgumentStack&& args);
    ArgumentStack ReloadRules               (ArgumentStack&& args);
};

}
