#include "MaxLevel.hpp"

#include "API/C2DA.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/CNWClass.hpp"
#include "API/CNWRules.hpp"
#include "API/CExoIni.hpp"
#include "API/CExoResMan.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CServerInfo.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWRace.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include <regex>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

const int CORE_MAX_LEVEL = 40;
const int MAX_LEVEL_MAX = 60;

static MaxLevel::MaxLevel* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new MaxLevel::MaxLevel(services);
    return g_plugin;
}

namespace MaxLevel {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

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



MaxLevel::MaxLevel(Services::ProxyServiceList* services)
        : Plugin(services)
{
    m_maxLevel = Config::Get<int>("MAX", (uint8_t)CORE_MAX_LEVEL);
    if (m_maxLevel > MAX_LEVEL_MAX)
        m_maxLevel = MAX_LEVEL_MAX;

    if (m_maxLevel > CORE_MAX_LEVEL)
    {
        s_GetServerInfoFromIniFileHook  = Hooks::HookFunction(Functions::_ZN21CServerExoAppInternal24GetServerInfoFromIniFileEv,
                                                              (void*)&GetServerInfoFromIniFileHook, Hooks::Order::Early);
        s_LoadModuleStartHook           = Hooks::HookFunction(Functions::_ZN10CNWSModule15LoadModuleStartE10CExoStringiiRKN6NWSync13AdvertisementE,
                                                              (void*)&LoadModuleStartHook, Hooks::Order::Early);
        s_CanLevelUpHook                = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats10CanLevelUpEv,
                                                              (void*)&CanLevelUpHook, Hooks::Order::Final);
        s_GetExpNeededForLevelUpHook    = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats22GetExpNeededForLevelUpEv,
                                                              (void*)&GetExpNeededForLevelUpHook, Hooks::Order::Final);
        s_LevelDownHook                 = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats9LevelDownEP13CNWLevelStats,
                                                              (void*)&LevelDownHook, Hooks::Order::Late);
        s_SummonAssociateHook           = Hooks::HookFunction(Functions::_ZN12CNWSCreature15SummonAssociateE7CResRef10CExoStringt,
                                                              (void*)&SummonAssociateHook, Hooks::Order::Late);
        s_LoadSpellGainTableHook        = Hooks::HookFunction(Functions::_ZN8CNWClass18LoadSpellGainTableE10CExoString,
                                                              (void*)&LoadSpellGainTableHook, Hooks::Order::Early);
        s_LoadSpellKnownTableHook       = Hooks::HookFunction(Functions::_ZN8CNWClass19LoadSpellKnownTableE10CExoString,
                                                              (void*)&LoadSpellKnownTableHook, Hooks::Order::Early);
        s_GetSpellGainHook              = Hooks::HookFunction(Functions::_ZN8CNWClass12GetSpellGainEhh,
                                                              (void*)&GetSpellGainHook, Hooks::Order::Final);
        s_GetSpellsKnownPerLevelHook    = Hooks::HookFunction(Functions::_ZN8CNWClass22GetSpellsKnownPerLevelEhhhth,
                                                              (void*)&GetSpellsKnownPerLevelHook, Hooks::Order::Final);
    }
}

MaxLevel::~MaxLevel()
{
}

void MaxLevel::GetServerInfoFromIniFileHook(CServerExoAppInternal* pServerExoAppInternal)
{
    s_GetServerInfoFromIniFileHook->CallOriginal<void>(pServerExoAppInternal);
    pServerExoAppInternal->m_pServerInfo->m_JoiningRestrictions.nMaxLevel = g_plugin->m_maxLevel;
}

// After Rules aggregates all its information we add to our custom experience table map
uint32_t MaxLevel::LoadModuleStartHook(CNWSModule *pModule, CExoString sModuleName, int32_t bIsSaveGame, int32_t nSourceType, const NWSync::Advertisement* nwsyncModuleSourceAdvert)
{
    auto retVal = s_LoadModuleStartHook->CallOriginal<uint32_t>(pModule, sModuleName, bIsSaveGame, nSourceType, nwsyncModuleSourceAdvert);

    auto *twoda = Globals::Rules()->m_p2DArrays->GetCached2DA("EXPTABLE", true);
    twoda->Load2DArray();
    for (int i = CORE_MAX_LEVEL; i < g_plugin->m_maxLevel; i++)
    {
        int32_t xpLevel = 0;
        twoda->GetINTEntry(i, 1, &xpLevel);
        if (!xpLevel)
        {
            LOG_ERROR("No xp threshold set for level %d!. Max level reverted to 40.", 1 + i);
            g_plugin->m_maxLevel = CORE_MAX_LEVEL;
            return retVal;
        }
        else
        {
            g_plugin->m_nExperienceTableAdded[i] = xpLevel;
        }
    }
    if (g_plugin->m_maxLevel > CORE_MAX_LEVEL)
        LOG_INFO("Max Level increased to %d.", g_plugin->m_maxLevel);

    return retVal;
}

// If level is greater than 40 seek the xp_threshold from our custom map
int32_t MaxLevel::CanLevelUpHook(CNWSCreatureStats* pStats)
{
    auto pCreature = pStats->m_pBaseCreature;
    if ((pCreature->m_nAssociateType >= 5 && pCreature->m_nAssociateType <= 8) || pCreature->m_nAssociateType == 3)
        return 0;

    int32_t totalLevels = pStats->GetLevel(false);

    if ((!pStats->m_bIsPC && totalLevels >= MAX_LEVEL_MAX) || (pStats->m_bIsPC && totalLevels >= g_plugin->m_maxLevel))
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
        xp_threshold = g_plugin->m_nExperienceTableAdded[totalLevels];
    }

    if (xp < xp_threshold)
        return 0;

    return 1;
}

// If the player is at level 39 or lower we get the XP required from the normal array, otherwise we use our map
uint32_t MaxLevel::GetExpNeededForLevelUpHook(CNWSCreatureStats *pStats)
{
    uint32_t xp_threshold = 0;
    int32_t totalLevels = pStats->GetLevel(false);
    if (totalLevels < CORE_MAX_LEVEL)
    {
        xp_threshold = Globals::Rules()->m_nExperienceTable[totalLevels + 1];
    }
    else
    {
        xp_threshold = g_plugin->m_nExperienceTableAdded[totalLevels];
    }
    return xp_threshold;
}

// Instead of rewriting SetExperience we just make sure if the call to LevelDown is not necessary we skip it
// If the player is at level 40 or lower we get the XP required from the normal array, otherwise we use our map
void MaxLevel::LevelDownHook(CNWSCreatureStats *pStats, CNWLevelStats *pLevelStats)
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
        xp_threshold = g_plugin->m_nExperienceTableAdded[totalLevels - 1];
    }
    if (nXP < xp_threshold)
        s_LevelDownHook->CallOriginal<void>(pStats, pLevelStats);
}

// The resref passed into SummonAssociate has the template utc with the character's level appended to it, just
// swap that level back to 40 if that utc doesn't exist. This is easier than rewriting SummonFamilar and
// SummonAnimalCompanion completely
void MaxLevel::SummonAssociateHook(CNWSCreature *pCreature, CResRef cResRef, CExoString p_sAssociateName, uint16_t nAssociateType)
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
void MaxLevel::LoadSpellGainTableHook(CNWClass* pClass, CExoString sTable)
{
    s_LoadSpellGainTableHook->CallOriginal<void>(pClass, sTable);

    C2DA twoda(sTable, true);
    twoda.Load2DArray();

    for (int i = CORE_MAX_LEVEL; i < g_plugin->m_maxLevel; i++)
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
        g_plugin->m_nSpellLevelsPerLevelAdded[pClass->m_nName][i] = numSpellLevels;

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
            g_plugin->m_nSpellGainTableAdded[pClass->m_nName][i][j] = iNumSpells;
        }
    }
}

// If the player is at level 40 or lower we get the spell gain for that class from the normal array,
// otherwise we use our map
uint8_t MaxLevel::GetSpellGainHook(CNWClass *pClass, uint8_t nLevel, uint8_t nSpellLevel)
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
        if ( nSpellLevel < g_plugin->m_nSpellLevelsPerLevelAdded[pClass->m_nName][nLevel - 1] )
        {
            result = g_plugin->m_nSpellGainTableAdded[pClass->m_nName][nLevel - 1][nSpellLevel];
        }
    }
    return result;
}

// After the server loads 1-40 we populate our map with the values for 41+
void MaxLevel::LoadSpellKnownTableHook(CNWClass* pClass, CExoString sTable)
{
    s_LoadSpellKnownTableHook->CallOriginal<void>(pClass, sTable);

    C2DA twoda(sTable, true);
    twoda.Load2DArray();

    for (int i = CORE_MAX_LEVEL; i < g_plugin->m_maxLevel; i++)
    {
        uint8_t lastFoundSpellKnownLevel = CORE_MAX_LEVEL;

        // Now find the spells known per level for each spell level
        for (int j = 0; j < g_plugin->m_nSpellLevelsPerLevelAdded[pClass->m_nName][i]; j++)
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
            g_plugin->m_nSpellKnownTableAdded[pClass->m_nName][i][j] = iNumSpells;
        }
    }
}

// If the player is at level 40 or lower we get the spell known for that class from the normal array,
// otherwise we use our map
uint8_t MaxLevel::GetSpellsKnownPerLevelHook(CNWClass *pClass, uint8_t nLevel, uint8_t nSpellLevel, uint8_t nClass,
                                             uint16_t nRace, uint8_t nCHABase)
{
    uint8_t result = 0;
    uint8_t spellLevelsPerLevel = 0;
    uint8_t spellsKnownPerSpellLevel = 0;
    uint8_t spellsKnownPreviousSpellLevel = 0;

    if (pClass->m_lstSpellKnownTable)
    {
        if (nLevel <= CORE_MAX_LEVEL)
        {
            spellLevelsPerLevel = pClass->m_lstSpellLevelsPerLevel[nLevel - 1];
            spellsKnownPerSpellLevel = pClass->m_lstSpellKnownTable[nLevel - 1][nSpellLevel];
            spellsKnownPreviousSpellLevel = pClass->m_lstSpellKnownTable[nLevel - 1][nSpellLevel - 1];
        }
        else
        {
            spellLevelsPerLevel = g_plugin->m_nSpellLevelsPerLevelAdded[pClass->m_nName][nLevel - 1];
            spellsKnownPerSpellLevel = g_plugin->m_nSpellKnownTableAdded[pClass->m_nName][nLevel - 1][nSpellLevel];
            if (nLevel == CORE_MAX_LEVEL + 1)
                spellsKnownPreviousSpellLevel = pClass->m_lstSpellKnownTable[CORE_MAX_LEVEL - 1][nSpellLevel - 1];
            else
                spellsKnownPreviousSpellLevel = g_plugin->m_nSpellKnownTableAdded[pClass->m_nName][nLevel - 1][nSpellLevel - 1];
        }
    }

    if (nSpellLevel < spellLevelsPerLevel
        && (nClass != API::Constants::ClassType::Bard
            || spellsKnownPreviousSpellLevel
            || Globals::Rules()->m_lstRaces[nRace].m_nCHAAdjust + nCHABase > nSpellLevel + 10))
    {
        result = spellsKnownPerSpellLevel;
    }
    return result;
}

}
