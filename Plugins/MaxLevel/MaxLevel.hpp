#pragma once

#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"

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

    NWNXLib::Hooking::FunctionHook* m_LevelDownHook;
    NWNXLib::Hooking::FunctionHook* m_SummonAssociateHook;

    static void ReloadAllHook(bool, CNWRules* rules);
    static void LoadSpellGainTableHook(bool, CNWClass* pClass, CExoString *pTable);
    static void LoadSpellKnownTableHook(bool, CNWClass* pClass, CExoString *pTable);
    static uint8_t GetSpellGainHook(CNWClass*, uint8_t, uint8_t);
    static uint8_t GetSpellsKnownPerLevelHook(CNWClass *, uint8_t, uint8_t, uint8_t, uint16_t, uint8_t);
    static int32_t CanLevelUpHook(CNWSCreatureStats*);
    static void SummonAssociateHook(CNWSCreature *, CResRef, CExoString *, uint16_t);
    static void LevelDownHook(CNWSCreatureStats *, CNWLevelStats *);
    static uint32_t GetExpNeededForLevelUpHook(CNWSCreatureStats *);
    static void GetServerInfoFromIniFileHook(bool, CServerExoAppInternal *);
};

}
