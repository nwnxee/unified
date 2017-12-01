#pragma once

#include "Plugin.hpp"
#include "API/Types.hpp"

namespace AOO {

class AOO : public NWNXLib::Plugin
{
public:
    AOO(const Plugin::CreateParams& params);
    virtual ~AOO();

private:
    // Maps from attacker -> bitfield.
    std::unordered_map<NWNXLib::API::Types::ObjectID, uint8_t> m_AOOMap;
    static void PerformAOO(NWNXLib::API::CNWSCreature* target, NWNXLib::API::CNWSCreature* attacker);
};

}
