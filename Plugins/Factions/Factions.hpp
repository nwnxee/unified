#pragma once

#include "Plugin.hpp"
#include <map>
#include <bitset>

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Factions {

class Factions : public NWNXLib::Plugin
{
public:
    Factions(const Plugin::CreateParams& params);
    virtual ~Factions();

private:
    

    

    

    ArgumentStack GetFactionId (ArgumentStack&& args);
    ArgumentStack SetFaction (ArgumentStack&& args);
};

}
