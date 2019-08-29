#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class MaxLevel
{
public:
    MaxLevel(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker, uint8_t maxLevel);

private:
    static void ReloadAllHook(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWRules* rules);
    static void LoadSpellGainTableHook(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CNWClass* pClass, NWNXLib::API::CExoString *pTable);
    static uint8_t GetSpellGainHook(NWNXLib::API::CNWClass*, uint8_t, uint8_t);
    static uint8_t GetSpellsKnownPerLevelHook(NWNXLib::API::CNWClass *, uint8_t, uint8_t, uint8_t, uint16_t, uint8_t);
    static int32_t CanLevelUpHook(NWNXLib::API::CNWSCreatureStats*);
    static void SummonAssociateHook(NWNXLib::API::CNWSCreature *, NWNXLib::API::CResRef, NWNXLib::API::CExoString *, uint16_t);
    static void LevelDownHook(NWNXLib::API::CNWSCreatureStats *, NWNXLib::API::CNWLevelStats *);
    static void GetServerInfoFromIniFileHook(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CServerExoAppInternal *);
    static NWNXLib::Hooking::FunctionHook* pCanLevelUpHook;
    static uint8_t m_maxLevel;
    static uint32_t m_nExperienceTableAdded[40];
    static std::unordered_map<uint16_t, std::unordered_map<uint8_t, std::unordered_map<uint8_t, uint8_t>>> m_nSpellGainTableAdded;
    static std::unordered_map<uint16_t, std::unordered_map<uint8_t, uint8_t>> m_nSpellLevelsPerLevelAdded;
};

}
