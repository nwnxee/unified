#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
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

    NWNXLib::API::CNWSEncounter *encounter(ArgumentStack& args);

};

}
