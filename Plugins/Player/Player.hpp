#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include "API/CNWSPlayer.hpp"
#include "Services/Hooks/Hooks.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Player {

class Player : public NWNXLib::Plugin
{
public:
    Player(const Plugin::CreateParams& params);
    virtual ~Player();

private:
    static void HandlePlayerToServerInputCancelGuiTimingEventHook(NWNXLib::Services::Hooks::CallType type,
        NWNXLib::API::CNWSMessage* pMessage, NWNXLib::API::CNWSPlayer* pPlayer);

    ArgumentStack ForcePlaceableExamineWindow(ArgumentStack&& args);
    ArgumentStack StartGuiTimingBar             (ArgumentStack&& args);
    ArgumentStack StopGuiTimingBar              (ArgumentStack&& args);

    NWNXLib::API::CNWSPlayer *player(ArgumentStack& args);

};

}
