#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/CNWSEncounter.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Encounter {

class Encounter : public NWNXLib::Plugin
{
public:
    Encounter(const Plugin::CreateParams& params);
    virtual ~Encounter();

private:
    ArgumentStack GetNumberOfCreaturesInEncounterList       (ArgumentStack&& args);
    ArgumentStack GetEncounterCreatureByIndex               (ArgumentStack&& args);
    ArgumentStack SetEncounterCreatureByIndex               (ArgumentStack&& args);
    ArgumentStack GetFactionId                              (ArgumentStack&& args);
    ArgumentStack SetFactionId                              (ArgumentStack&& args);
    ArgumentStack GetPlayerTriggeredOnly                    (ArgumentStack&& args);
    ArgumentStack SetPlayerTriggeredOnly                    (ArgumentStack&& args);
    ArgumentStack GetResetTime                              (ArgumentStack&& args);
    ArgumentStack SetResetTime                              (ArgumentStack&& args);

    CNWSEncounter *encounter(ArgumentStack& args);

};

}
