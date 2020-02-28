#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSCreature.hpp"
using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Factions {

class Factions : public NWNXLib::Plugin
{
public:
    Factions(const Plugin::CreateParams& params);
    virtual ~Factions();

private:
    ArgumentStack SetFaction               (ArgumentStack&& args);
    ArgumentStack GetFaction               (ArgumentStack&& args);
    static CNWSCreature *Creature          (ArgumentStack& args);
    static OBJECT_ID *Object               (ArgumentStack& args);

    
};

}
