#include "Tweaks/MaxLevel.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"
#include "API/C2DA.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/CNWClass.hpp"
#include "API/CNWRules.hpp"
#include "API/CAppManager.hpp"
#include "API/CExoResMan.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWRace.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include <regex>

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

uint8_t MaxLevel::m_maxLevel;
uint32_t MaxLevel::m_nExperienceTableAdded[20];
std::unordered_map<uint16_t, std::unordered_map<uint8_t, std::unordered_map<uint8_t, uint8_t>>> MaxLevel::m_nSpellGainTableAdded;
std::unordered_map<uint16_t, std::unordered_map<uint8_t, uint8_t>> MaxLevel::m_nSpellLevelsPerLevelAdded;

static Hooking::FunctionHook* g_SummonAssociateHook = nullptr;
static Hooking::FunctionHook* g_LevelDownHook = nullptr;

MaxLevel::MaxLevel(ViewPtr<Services::HooksProxy> hooker, uint8_t maxLevel)
{
    m_maxLevel = maxLevel;

    hooker->RequestExclusiveHook<Functions::CNWSCreatureStats__LevelDown>(&LevelDownHook);
    g_LevelDownHook = hooker->FindHookByAddress(API::Functions::CNWSCreatureStats__LevelDown);
    hooker->RequestExclusiveHook<Functions::CNWSCreatureStats__CanLevelUp>(&CanLevelUpHook);
    hooker->RequestExclusiveHook<Functions::CNWClass__GetSpellGain>(&GetSpellGainHook);
    hooker->RequestExclusiveHook<Functions::CNWClass__GetSpellsKnownPerLevel>(&GetSpellsKnownPerLevelHook);
    hooker->RequestExclusiveHook<Functions::CNWSCreature__SummonAssociate>(&SummonAssociateHook);
    g_SummonAssociateHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__SummonAssociate);
    hooker->RequestSharedHook<Functions::CNWRules__ReloadAll, void, CNWRules*>(&ReloadAllHook);
    hooker->RequestSharedHook<Functions::CNWClass__LoadSpellGainTable, void, CNWClass*, CExoString*>(&LoadSpellGainTableHook);
}


// Instead of rewriting SetExperience we just make sure if the call from SetExperience to LevelDown is not necessary
// We skip it
void MaxLevel::LevelDownHook(NWNXLib::API::CNWSCreatureStats *pStats, CNWLevelStats *pLevelStats)
{
    auto nXP = pStats->m_nExperience;
    uint8_t levels = 0;
    uint32_t xp_threshold = 0;
    for (int i = 0; i < pStats->m_nNumMultiClasses; i++)
    {
        levels += pStats->m_ClassInfo[i].m_nLevel;
    }
    if (levels <= 40)
    {
        xp_threshold = Globals::Rules()->m_nExperienceTable[levels-1];
    }
    else
    {
        xp_threshold = m_nExperienceTableAdded[levels-41];
    }
    if (nXP < xp_threshold)
        g_LevelDownHook->CallOriginal<void>(pStats, pLevelStats);
}

// The resref passed into SummonAssociate has the template utc with the character's level appended to it, just
// swap that level back to 40 if that utc doesn't exist.
// This is easier than rewriting SummonFamilar and SummonAnimalCompanion completely
void MaxLevel::SummonAssociateHook(NWNXLib::API::CNWSCreature *pCreature, NWNXLib::API::CResRef cResRef,
                                                  NWNXLib::API::CExoString *p_sAssociateName, uint16_t nAssociateType)
{
    std::string sResRef = cResRef.GetResRef();
    auto cUsedResRef = cResRef;
    if (!Globals::ExoResMan()->Exists(cResRef, 2027, nullptr))
    {
        std::regex re("(.*)[4-9][0-9]");
        std::string sNewResRef = std::regex_replace(sResRef,re,"$0140");
        cUsedResRef = CResRef(sNewResRef.c_str());
    }
    g_SummonAssociateHook->CallOriginal<void>(pCreature, cUsedResRef, p_sAssociateName, nAssociateType);
}

uint8_t MaxLevel::GetSpellGainHook(CNWClass *pClass, uint8_t nLevel, uint8_t nSpellLevel)
{
    uint8_t result = -1;

    if ( nLevel <= 40 )
    {
        if ( nSpellLevel < pClass->m_lstSpellLevelsPerLevel[nLevel] )
            result = *pClass->m_lstSpellGainTable[nLevel];
    }
    else
    {
        if ( nSpellLevel < m_nSpellLevelsPerLevelAdded[pClass->m_nName][nLevel - 41] )
            result = m_nSpellGainTableAdded[pClass->m_nName][nLevel - 41][nSpellLevel];
    }
    return result;
}

uint8_t MaxLevel::GetSpellsKnownPerLevelHook(
        CNWClass *pClass, uint8_t nLevel, uint8_t nSpellLevel, uint8_t nClass, uint16_t nRace, uint8_t nCHABase)
{

    uint8_t result = 0;
    if (nLevel <= 60 && (((nLevel <= 40 && nSpellLevel < pClass->m_lstSpellLevelsPerLevel[nLevel]) ||
                          (nSpellLevel < m_nSpellLevelsPerLevelAdded[pClass->m_nName][nLevel - 41])) &&
                         (nClass != API::Constants::ClassType::Bard ||
                          Globals::Rules()->m_lstRaces[nRace].m_nCHAAdjust + nCHABase > nSpellLevel + 10)))
    {
        if (nLevel <= 40)
            result = pClass->m_lstSpellLevelsPerLevel[nLevel];
        else
            result = m_nSpellLevelsPerLevelAdded[pClass->m_nName][nLevel - 41];
    }
    return result;
}

void MaxLevel::LoadSpellGainTableHook(Services::Hooks::CallType type, CNWClass* pClass, CExoString *pTable)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;
    if (before)
        return;

    uint8_t moreLevels = m_maxLevel - 40;
    for (int i = 0; i < moreLevels; i++)
    {
        int32_t numSpellLevels = 0;
        auto *twoda = new C2DA(CResRef(pTable->CStr()), 1);
        twoda->Load2DArray();
        twoda->GetINTEntry(40 + i, "NumSpellLevels", &numSpellLevels);
        m_nSpellLevelsPerLevelAdded[pClass->m_nName][i] = numSpellLevels;
        for (int j = 0; j < numSpellLevels; j++)
        {
            int32_t iNumSpells = 0;
            twoda->GetINTEntry(40 + i, 2 + j, &iNumSpells);
            m_nSpellGainTableAdded[pClass->m_nName][i][j] = iNumSpells;
        }
    }
}

void MaxLevel::ReloadAllHook(Services::Hooks::CallType type, CNWRules* pRules)
{
    const bool before = type == Services::Hooks::CallType::BEFORE_ORIGINAL;
    if (before || !pRules)
        return;

    uint8_t moreLevels = m_maxLevel - 40;
    int32_t xpLevel = 0;
    for (int i = 0; i < moreLevels; i++)
    {
        auto *twoda = Globals::Rules()->m_p2DArrays->GetCached2DA("EXPTABLE", true);
        twoda->Load2DArray();
        twoda->GetINTEntry(40 + i, 1, &xpLevel);
        m_nExperienceTableAdded[i] = xpLevel;
    }
}

int32_t MaxLevel::CanLevelUpHook(CNWSCreatureStats* pStats)
{
    auto pCreature = pStats->m_pBaseCreature;
    if ((pCreature->m_nAssociateType >= 5 && pCreature->m_nAssociateType <= 8) || pCreature->m_nAssociateType == 2)
    {
        return false;
    }
    int32_t totalLevels = 0;
    for (int i = 0; i < pStats->m_nNumMultiClasses; i++)
    {
        totalLevels += pStats->m_ClassInfo[i].m_nLevel;
    }
    if (totalLevels >= m_maxLevel)
        return 0;
    auto xp = pStats->m_nExperience;
    uint32_t xp_threshold = 0;
    if (totalLevels <= 40)
        xp_threshold = Globals::Rules()->m_nExperienceTable[totalLevels-1];
    else
        xp_threshold = m_nExperienceTableAdded[totalLevels-40];

    if (!pStats->m_bIsPC)
        return 1;
    if (xp < xp_threshold)
        return 0;
    return 1;
}

}
