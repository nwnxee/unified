#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/CNWSEncounter.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Encounter {

class Encounter : public NWNXLib::Plugin
{
public:
    Encounter(NWNXLib::Services::ProxyServiceList* services);
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
    ArgumentStack GetNumberOfSpawnPoints                    (ArgumentStack&& args);
    ArgumentStack GetSpawnPointByIndex                      (ArgumentStack&& args);
    ArgumentStack GetMinNumSpawned                          (ArgumentStack&& args);
    ArgumentStack GetMaxNumSpawned                          (ArgumentStack&& args);
    ArgumentStack GetCurrentNumSpawned                      (ArgumentStack&& args);
    ArgumentStack GetGeometry                               (ArgumentStack&& args);
    ArgumentStack SetGeometry                               (ArgumentStack&& args);

    CNWSEncounter *encounter(ArgumentStack& args);

};

}
