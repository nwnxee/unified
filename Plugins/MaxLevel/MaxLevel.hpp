#pragma once

#include "nwnx.hpp"

namespace MaxLevel {

class MaxLevel : public NWNXLib::Plugin
{
public:
    MaxLevel(NWNXLib::Services::ProxyServiceList* services);
    virtual ~MaxLevel();

private:
    uint8_t m_maxLevel;
    std::unordered_map<uint8_t, uint32_t> m_nExperienceTableAdded;
    std::unordered_map<uint16_t, std::unordered_map<uint8_t, std::unordered_map<uint8_t, uint8_t>>> m_nSpellGainTableAdded;
    std::unordered_map<uint16_t, std::unordered_map<uint8_t, std::unordered_map<uint8_t, uint8_t>>> m_nSpellKnownTableAdded;
    std::unordered_map<uint16_t, std::unordered_map<uint8_t, uint8_t>> m_nSpellLevelsPerLevelAdded;

    static uint32_t LoadModuleStartHook(CNWSModule*, CExoString, int32_t, int32_t);
    static void LoadSpellGainTableHook(CNWClass*, CExoString);
    static void LoadSpellKnownTableHook(CNWClass*, CExoString);
    static uint8_t GetSpellGainHook(CNWClass*, uint8_t, uint8_t);
    static uint8_t GetSpellsKnownPerLevelHook(CNWClass*, uint8_t, uint8_t, uint8_t, uint16_t, uint8_t);
    static int32_t CanLevelUpHook(CNWSCreatureStats*);
    static void SummonAssociateHook(CNWSCreature*, CResRef, CExoString, uint16_t);
    static void LevelDownHook(CNWSCreatureStats*, CNWLevelStats*);
    static uint32_t GetExpNeededForLevelUpHook(CNWSCreatureStats*);
    static void GetServerInfoFromIniFileHook(CServerExoAppInternal*);
};

}
