#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include "API/CNWSPlayer.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Player {

class Player : public NWNXLib::Plugin
{
public:
    Player(const Plugin::CreateParams& params);
    virtual ~Player();

private:
    ArgumentStack ForcePlaceableExamineWindow(ArgumentStack&& args);

    NWNXLib::API::CNWSPlayer *player(ArgumentStack& args);

};

}
