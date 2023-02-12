#pragma once

#include "nwnx.hpp"
#include <bitset>
#include <map>

using ArgumentStack = NWNXLib::ArgumentStack;

namespace SkillRanks {

class SkillRanks : public NWNXLib::Plugin
{
public:
    SkillRanks(NWNXLib::Services::ProxyServiceList* services);
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

    static void LoadRulesetInfoHook(CNWRules*);
    static char GetSkillRankHook(CNWSCreatureStats*, uint8_t, CNWSObject*, int32_t);

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

    std::unordered_map<uint8_t, std::unordered_map<uint16_t, SkillFeats>> m_skillFeatMap;
    std::unordered_map<uint16_t, std::unordered_map<uint8_t, int32_t>> m_skillRaceMod;
};

}
