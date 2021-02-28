#pragma once

#include "nwnx.hpp"
#include "API/CNWSCreature.hpp"

namespace CombatModes {

class CombatModes : public NWNXLib::Plugin
{
public:
    CombatModes(NWNXLib::Services::ProxyServiceList* services);
    virtual ~CombatModes();

private:
    bool m_Skipped;
    bool m_FlurryOfBlows;
    static void SetCombatModeHook(CNWSCreature*, uint8_t, int32_t);
};

}
