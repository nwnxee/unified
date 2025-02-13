#include "nwnx.hpp"

#include "API/C2DA.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/CNWClass.hpp"
#include "API/CNWRules.hpp"
#include "API/CExoIni.hpp"
#include "API/CExoResMan.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CServerInfo.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWRace.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include <regex>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;
using namespace NWNXLib::API::Globals;

const int CORE_MAX_LEVEL = 40;
const int MAX_LEVEL_MAX = 60;

static Hooks::Hook s_GetServerInfoFromIniFileHook;
static Hooks::Hook s_LoadModuleStartHook;
static Hooks::Hook s_LevelDownHook;
static Hooks::Hook s_SummonAssociateHook;
static Hooks::Hook s_LoadSpellGainTableHook;
static Hooks::Hook s_LoadSpellKnownTableHook;

// Replaced completely
static Hooks::Hook s_CanLevelUpHook;
static Hooks::Hook s_GetExpNeededForLevelUpHook;
static Hooks::Hook s_GetSpellGainHook;
static Hooks::Hook s_GetSpellsKnownPerLevelHook;
static Hooks::Hook s_SetExperienceHook;

uint8_t s_maxLevel;

std::unordered_map<uint8_t, uint32_t> s_nExperienceTableAdded;
std::unordered_map<uint16_t, std::unordered_map<uint8_t, std::unordered_map<uint8_t, uint8_t>>> s_nSpellGainTableAdded;
std::unordered_map<uint16_t, std::unordered_map<uint8_t, std::unordered_map<uint8_t, uint8_t>>> s_nSpellKnownTableAdded;
std::unordered_map<uint16_t, std::unordered_map<uint8_t, uint8_t>> s_nSpellLevelsPerLevelAdded;

static void GetServerInfoFromIniFileHook(CServerExoAppInternal* pServerExoAppInternal);
static uint32_t LoadModuleStartHook(CNWSModule *pModule, CExoString sModuleName, int32_t bIsSaveGame, int32_t nSourceType, const NWSync::Advertisement* nwsyncModuleSourceAdvert);
static int32_t CanLevelUpHook(CNWSCreatureStats* pStats);
static uint32_t GetExpNeededForLevelUpHook(CNWSCreatureStats *pStats);
static void LevelDownHook(CNWSCreatureStats *pStats, CNWLevelStats *pLevelStats);
static void SummonAssociateHook(CNWSCreature *pCreature, CResRef cResRef, CExoString p_sAssociateName, uint16_t nAssociateType);
static void LoadSpellGainTableHook(CNWClass* pClass, CExoString sTable);
static void LoadSpellKnownTableHook(CNWClass* pClass, CExoString sTable);
static uint8_t GetSpellGainHook(CNWClass *pClass, uint8_t nLevel, uint8_t nSpellLevel);
static uint8_t GetSpellsKnownPerLevelHook(CNWClass *pClass, uint8_t nLevel, uint8_t nSpellLevel, uint8_t nClass, uint16_t nRace, uint8_t nCastingAbilityBase);
static void SetExperienceHook(CNWSCreatureStats *pStats, uint32_t nValue, bool bDoLevel);

void MaxLevel() __attribute__((constructor));
void MaxLevel()
{
    s_maxLevel = static_cast<uint8_t>(std::clamp(Config::Get<int>("MAX", (uint8_t)CORE_MAX_LEVEL), 0, MAX_LEVEL_MAX));
    if (s_maxLevel > CORE_MAX_LEVEL)
    {
        LOG_INFO("Max Level increased to %d.", s_maxLevel);
        s_GetServerInfoFromIniFileHook = Hooks::HookFunction(
            &CServerExoAppInternal::GetServerInfoFromIniFile, &GetServerInfoFromIniFileHook, Hooks::Order::Early);

        s_LoadModuleStartHook = Hooks::HookFunction(
            &CNWSModule::LoadModuleStart,
            (void*)&LoadModuleStartHook, Hooks::Order::Early);

        s_CanLevelUpHook = Hooks::HookFunction(
            &CNWSCreatureStats::CanLevelUp,
            &CanLevelUpHook, Hooks::Order::Final);

        s_GetExpNeededForLevelUpHook = Hooks::HookFunction(
            &CNWSCreatureStats::GetExpNeededForLevelUp,
            &GetExpNeededForLevelUpHook, Hooks::Order::Final);

        s_LevelDownHook = Hooks::HookFunction(
            &CNWSCreatureStats::LevelDown,
            &LevelDownHook, Hooks::Order::Late);

        s_SummonAssociateHook = Hooks::HookFunction(
            &CNWSCreature::SummonAssociate,
            &SummonAssociateHook, Hooks::Order::Late);

        s_LoadSpellGainTableHook = Hooks::HookFunction(
            &CNWClass::LoadSpellGainTable,
            &LoadSpellGainTableHook, Hooks::Order::Early);

        s_LoadSpellKnownTableHook = Hooks::HookFunction(
            &CNWClass::LoadSpellKnownTable,
            &LoadSpellKnownTableHook, Hooks::Order::Early);

        s_GetSpellGainHook = Hooks::HookFunction(
            &CNWClass::GetSpellGain,
            &GetSpellGainHook, Hooks::Order::Final);

        s_GetSpellsKnownPerLevelHook = Hooks::HookFunction(
            &CNWClass::GetSpellsKnownPerLevel,
            &GetSpellsKnownPerLevelHook, Hooks::Order::Final);

        s_SetExperienceHook = Hooks::HookFunction(
            &CNWSCreatureStats::SetExperience,
            &SetExperienceHook, Hooks::Order::Early);
    }
}

static void GetServerInfoFromIniFileHook(CServerExoAppInternal* pServerExoAppInternal)
{
    s_GetServerInfoFromIniFileHook->CallOriginal<void>(pServerExoAppInternal);
    pServerExoAppInternal->m_pServerInfo->m_JoiningRestrictions.nMaxLevel = s_maxLevel;
}

// After Rules aggregates all its information we add to our custom experience table map
static uint32_t LoadModuleStartHook(CNWSModule *pModule, CExoString sModuleName, int32_t bIsSaveGame, int32_t nSourceType, const NWSync::Advertisement* nwsyncModuleSourceAdvert)
{
    auto retVal = s_LoadModuleStartHook->CallOriginal<uint32_t>(pModule, sModuleName, bIsSaveGame, nSourceType, nwsyncModuleSourceAdvert);

    auto *twoda = Globals::Rules()->m_p2DArrays->GetCached2DA("EXPTABLE", true);
    twoda->Load2DArray();
    for (int i = CORE_MAX_LEVEL; i < s_maxLevel; i++)
    {
        int32_t xpLevel = 0;
        twoda->GetINTEntry(i, 1, &xpLevel);
        if (!xpLevel)
        {
            LOG_ERROR("No xp threshold set for level %d!. Max level reverted to 40.", 1 + i);
            s_maxLevel = CORE_MAX_LEVEL;
            return retVal;
        }
        else
        {
            s_nExperienceTableAdded[i] = xpLevel;
        }
    }

    return retVal;
}

// If level is greater than 40 seek the xp_threshold from our custom map
static int32_t CanLevelUpHook(CNWSCreatureStats* pStats)
{
    auto pCreature = pStats->m_pBaseCreature;
    if ((pCreature->m_nAssociateType >= 5 && pCreature->m_nAssociateType <= 8) || pCreature->m_nAssociateType == 3)
        return 0;

    int32_t totalLevels = pStats->GetLevel(false);

    if ((!pStats->m_bIsPC && totalLevels >= MAX_LEVEL_MAX) || (pStats->m_bIsPC && totalLevels >= s_maxLevel))
        return 0;

    if (!pStats->m_bIsPC)
        return 1;

    auto xp = pStats->m_nExperience;
    uint32_t xp_threshold = 0;
    if (totalLevels <= CORE_MAX_LEVEL)
    {
        xp_threshold = Globals::Rules()->m_nExperienceTable[totalLevels];
    }
    else
    {
        xp_threshold = s_nExperienceTableAdded[totalLevels];
    }

    if (xp < xp_threshold)
        return 0;

    return 1;
}

// If the player is at level 39 or lower we get the XP required from the normal array, otherwise we use our map
static uint32_t GetExpNeededForLevelUpHook(CNWSCreatureStats *pStats)
{
    uint32_t xp_threshold = 0;
    int32_t totalLevels = pStats->GetLevel(false);
    if (totalLevels < CORE_MAX_LEVEL)
    {
        xp_threshold = Globals::Rules()->m_nExperienceTable[totalLevels + 1];
    }
    else
    {
        xp_threshold = s_nExperienceTableAdded[totalLevels];
    }
    return xp_threshold;
}

// Instead of rewriting SetExperience we just make sure if the call to LevelDown is not necessary we skip it
// If the player is at level 40 or lower we get the XP required from the normal array, otherwise we use our map
static void LevelDownHook(CNWSCreatureStats *pStats, CNWLevelStats *pLevelStats)
{
    if (!pStats->m_bIsPC)
    {
        s_LevelDownHook->CallOriginal<void>(pStats, pLevelStats);
        return;
    }
    auto nXP = pStats->m_nExperience;
    int32_t totalLevels = pStats->GetLevel(false);
    uint32_t xp_threshold = 0;
    if (totalLevels <= CORE_MAX_LEVEL)
    {
        xp_threshold = Globals::Rules()->m_nExperienceTable[totalLevels - 1];
    }
    else
    {
        xp_threshold = s_nExperienceTableAdded[totalLevels - 1];
    }
    if (nXP < xp_threshold)
        s_LevelDownHook->CallOriginal<void>(pStats, pLevelStats);
}

// The resref passed into SummonAssociate has the template utc with the character's level appended to it, just
// swap that level back to 40 if that utc doesn't exist. This is easier than rewriting SummonFamilar and
// SummonAnimalCompanion completely
static void SummonAssociateHook(CNWSCreature *pCreature, CResRef cResRef, CExoString p_sAssociateName, uint16_t nAssociateType)
{
    auto cUsedResRef = cResRef;
    std::string sResRef = cResRef.GetResRef();
    if (!Globals::ExoResMan()->Exists(cResRef, Constants::ResRefType::UTC, nullptr))
    {
        std::regex re("(.*)[4-9][0-9]");
        std::string sNewResRef = std::regex_replace(sResRef,re,"$0140");
        cUsedResRef = CResRef(sNewResRef.c_str());
    }
    s_SummonAssociateHook->CallOriginal<void>(pCreature, cUsedResRef, p_sAssociateName, nAssociateType);
}

// After the server loads 1-40 we populate our map with the values for 41+
static void LoadSpellGainTableHook(CNWClass* pClass, CExoString sTable)
{
    s_LoadSpellGainTableHook->CallOriginal<void>(pClass, sTable);

    C2DA twoda(sTable, true);
    twoda.Load2DArray();

    for (int i = CORE_MAX_LEVEL; i < s_maxLevel; i++)
    {
        int32_t numSpellLevels = 0;
        uint8_t lastFoundSpellGainLevel = CORE_MAX_LEVEL;
        twoda.GetINTEntry(i, "NumSpellLevels", &numSpellLevels);

        // If they don't have this set then default to the last found level
        if (!numSpellLevels)
        {
            LOG_WARNING("No spell gain row found for Level %d for %s Class. Defaulting to Level %d.",
                    1 + i, pClass->GetNameText(), lastFoundSpellGainLevel);
            twoda.GetINTEntry(lastFoundSpellGainLevel - 1, "NumSpellLevels", &numSpellLevels);
        }
        s_nSpellLevelsPerLevelAdded[pClass->m_nName][i] = numSpellLevels;

        // Now find the spells gained per level for each spell level
        for (int j = 0; j < numSpellLevels; j++)
        {
            int32_t iNumSpells = 0;
            twoda.GetINTEntry(i, 2 + j, &iNumSpells);
            if (!iNumSpells)
            {
                twoda.GetINTEntry(lastFoundSpellGainLevel - 1, 2 + j, &iNumSpells);
            }
            else
            {
                lastFoundSpellGainLevel = 1 + i;
            }
            s_nSpellGainTableAdded[pClass->m_nName][i][j] = iNumSpells;
        }
    }
}

// If the player is at level 40 or lower we get the spell gain for that class from the normal array,
// otherwise we use our map
static uint8_t GetSpellGainHook(CNWClass *pClass, uint8_t nLevel, uint8_t nSpellLevel)
{
    uint8_t result = -1;

    if ( nLevel <= CORE_MAX_LEVEL )
    {
        if ( nSpellLevel < pClass->m_lstSpellLevelsPerLevel[nLevel - 1] )
        {
            result = pClass->m_lstSpellGainTable[nLevel - 1][nSpellLevel];
        }
    }
    else
    {
        if ( nSpellLevel < s_nSpellLevelsPerLevelAdded[pClass->m_nName][nLevel - 1] )
        {
            result = s_nSpellGainTableAdded[pClass->m_nName][nLevel - 1][nSpellLevel];
        }
    }
    return result;
}

// After the server loads 1-40 we populate our map with the values for 41+
static void LoadSpellKnownTableHook(CNWClass* pClass, CExoString sTable)
{
    s_LoadSpellKnownTableHook->CallOriginal<void>(pClass, sTable);

    C2DA twoda(sTable, true);
    twoda.Load2DArray();

    for (int i = CORE_MAX_LEVEL; i < s_maxLevel; i++)
    {
        uint8_t lastFoundSpellKnownLevel = CORE_MAX_LEVEL;

        // Now find the spells known per level for each spell level
        for (int j = 0; j < s_nSpellLevelsPerLevelAdded[pClass->m_nName][i]; j++)
        {
            int32_t iNumSpells = 0;
            twoda.GetINTEntry(i, 1 + j, &iNumSpells);
            if (!iNumSpells)
            {
                twoda.GetINTEntry(lastFoundSpellKnownLevel - 1, 1 + j, &iNumSpells);
            }
            else
            {
                lastFoundSpellKnownLevel = 1 + i;
            }
            s_nSpellKnownTableAdded[pClass->m_nName][i][j] = iNumSpells;
        }
    }
}

// If the player is at class level 40 or lower we get the spell known for that class from the normal array,
// otherwise we use our map
static uint8_t GetSpellsKnownPerLevelHook(CNWClass *pClass, uint8_t nLevel, uint8_t nSpellLevel, uint8_t,
    uint16_t nRace, uint8_t nCastingAbilityBase)
{
    if (nLevel < 1 || nLevel > MAX_LEVEL_MAX) return 0;

    if (!pClass->m_lstSpellKnownTable) return 0;

    int nSpellLevelForLevel = nLevel <= CORE_MAX_LEVEL
        ? pClass->m_lstSpellLevelsPerLevel[nLevel - 1]
        : s_nSpellLevelsPerLevelAdded[pClass->m_nName][nLevel - 1];

    if (nSpellLevel >= nSpellLevelForLevel) return 0;

    auto spellKnownTable = [&](uint8_t idxLevel, uint8_t idxSpellLevel)
    {
        if (nLevel <= CORE_MAX_LEVEL)
            return pClass->m_lstSpellKnownTable[idxLevel][idxSpellLevel];
        else
            return s_nSpellKnownTableAdded[pClass->m_nName][idxLevel][idxSpellLevel];
    };

    if (pClass->m_bSpellbookRestricted && !pClass->m_bCanLearnFromScrolls
        && nSpellLevel > 0
        && spellKnownTable(nLevel - 1, nSpellLevel - 1) == 0)
    {
        int nCastingAbility = nCastingAbilityBase;
        nCastingAbility += Globals::Rules()->m_lstRaces[nRace].GetAbilityAdjust(pClass->m_nSpellcastingAbility);
        nCastingAbility += pClass->GetAbilityGainForLevel(pClass->m_nSpellcastingAbility, nLevel);

        if (nCastingAbility < 10 + nSpellLevel) return 0;
    }

    return spellKnownTable(nLevel - 1, nSpellLevel);
}

static void SetExperienceHook(CNWSCreatureStats *pStats, uint32_t nValue, bool bDoLevel)
{
    int32_t nExpDiff = nValue - pStats->m_nExperience;

    if (!bDoLevel || pStats->GetIsDM() || nExpDiff >= 0)
    {
        s_SetExperienceHook->CallOriginal<void>(pStats, nValue, bDoLevel);
        return;
    }

    auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(pStats->m_pBaseCreature->m_idSelf);

    if ( bDoLevel && pPlayer != NULL )
    {
            auto *pMessageData = new CNWCCMessageData;

            pMessageData->SetInteger(0,nExpDiff * -1);
            pStats->m_pBaseCreature->SendFeedbackMessage(183,pMessageData);
    }

    pStats->m_nExperience = nValue;
    if ( bDoLevel )
    {
        uint8_t currentLevel = pStats->GetLevel();
        while (currentLevel > Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMinLevel &&
            currentLevel > 0 &&
            ((currentLevel <= CORE_MAX_LEVEL && g_pRules->m_nExperienceTable[currentLevel-1] > pStats->m_nExperience) ||
                (currentLevel > CORE_MAX_LEVEL && s_nExperienceTableAdded[currentLevel-1] > pStats->m_nExperience)))
        {
            auto *pLevelStat = pStats->GetLevelStats(--currentLevel);
            if (pLevelStat)
            {
                pStats->LevelDown(pLevelStat);
            }
        }
    }
}
