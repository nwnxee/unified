#pragma once

#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace MaxLevel {

class MaxLevel : public NWNXLib::Plugin
{
public:
    MaxLevel(const Plugin::CreateParams& params);
    virtual ~MaxLevel();

private:
    uint8_t m_maxLevel;
    std::unordered_map<uint8_t, uint32_t> m_nExperienceTableAdded;
    std::unordered_map<uint16_t, std::unordered_map<uint8_t, std::unordered_map<uint8_t, uint8_t>>> m_nSpellGainTableAdded;
    std::unordered_map<uint16_t, std::unordered_map<uint8_t, std::unordered_map<uint8_t, uint8_t>>> m_nSpellKnownTableAdded;
    std::unordered_map<uint16_t, std::unordered_map<uint8_t, uint8_t>> m_nSpellLevelsPerLevelAdded;

    NWNXLib::Hooking::FunctionHook* m_LevelDownHook;
    NWNXLib::Hooking::FunctionHook* m_SummonAssociateHook;

    static void ReloadAllHook(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWRules* rules);
    static void LoadSpellGainTableHook(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWClass* pClass, NWNXLib::API::CExoString *pTable);
    static void LoadSpellKnownTableHook(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWClass* pClass, NWNXLib::API::CExoString *pTable);
    static uint8_t GetSpellGainHook(NWNXLib::API::CNWClass*, uint8_t, uint8_t);
    static uint8_t GetSpellsKnownPerLevelHook(NWNXLib::API::CNWClass *, uint8_t, uint8_t, uint8_t, uint16_t, uint8_t);
    static int32_t CanLevelUpHook(NWNXLib::API::CNWSCreatureStats*);
    static void SummonAssociateHook(NWNXLib::API::CNWSCreature *, NWNXLib::API::CResRef, NWNXLib::API::CExoString *, uint16_t);
    static void LevelDownHook(NWNXLib::API::CNWSCreatureStats *, NWNXLib::API::CNWLevelStats *);
    static uint32_t GetExpNeededForLevelUpHook(NWNXLib::API::CNWSCreatureStats *);
    static void GetServerInfoFromIniFileHook(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CServerExoAppInternal *);
};

}
