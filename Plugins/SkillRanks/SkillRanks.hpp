#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include <bitset>
#include <map>

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace SkillRanks {

class SkillRanks : public NWNXLib::Plugin
{
public:
    SkillRanks(const Plugin::CreateParams& params);
    virtual ~SkillRanks();

private:
    ArgumentStack GetSkillFeatCountForSkill   (ArgumentStack&& args);
    ArgumentStack GetSkillFeat                (ArgumentStack&& args);
    ArgumentStack GetSkillFeatForSkillByIndex (ArgumentStack&& args);
    ArgumentStack SetSkillFeat                (ArgumentStack&& args);
    ArgumentStack SetSkillFeatFocusModifier   (ArgumentStack&& args);
    ArgumentStack GetBlindnessPenalty         (ArgumentStack&& args);
    ArgumentStack SetBlindnessPenalty         (ArgumentStack&& args);
    ArgumentStack GetAreaModifier             (ArgumentStack&& args);
    ArgumentStack SetAreaModifier             (ArgumentStack&& args);

    static void LoadSkillInfoHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CNWRules*);
    static int32_t GetSkillRankHook(NWNXLib::API::CNWSCreatureStats*, uint8_t, NWNXLib::API::CNWSObject*, int32_t);

    uint8_t m_blindnessMod;

    struct SkillFeats {
        int8_t nModifier;
        uint8_t nFocusFeat;
        std::bitset<255> bitsetClasses;
        float fClassLevelMod;
        uint8_t nAreaFlagsRequired;
        uint8_t nAreaFlagsForbidden;
        uint8_t nDayOrNight;
        bool bBypassArmorCheckPenalty;
        uint16_t nKeyAbilityMask;
    };

    std::vector<std::map<uint32_t, SkillFeats>> m_skillFeatMap;
    std::vector<std::map<uint32_t, uint16_t>> m_skillRaceMod;
};

}
