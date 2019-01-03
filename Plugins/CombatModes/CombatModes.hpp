#pragma once

#include "Plugin.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Types.hpp"

namespace CombatModes {

class CombatModes : public NWNXLib::Plugin
{
public:
    CombatModes(const Plugin::CreateParams& params);
    virtual ~CombatModes();

private:
    bool m_Skipped;
    bool m_FlurryOfBlows;
    static void SetCombatModeHook(NWNXLib::API::CNWSCreature*, uint8_t, int32_t);

};

}