#include "MaxLevel.hpp"

#include "Utils.hpp"
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
#include "Services/Events/Events.hpp"
#include "Services/Config/Config.hpp"
#include "ViewPtr.hpp"
#include <regex>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

const int CORE_MAX_LEVEL = 40;
const int MAX_LEVEL_MAX = 60;

static ViewPtr<MaxLevel::MaxLevel> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
            {
                    "MaxLevel",
                    "Support for Levels 41 - 60",
                    "orth",
                    "plenarius@gmail.com",
                    1,
                    true,
                    0,
                    8186
            };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new MaxLevel::MaxLevel(params);
    return g_plugin;
}

namespace MaxLevel {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;


MaxLevel::MaxLevel(const Plugin::CreateParams& params)
        : Plugin(params)
{
    m_maxLevel = GetServices()->m_config->Get<int>("MAX", (uint8_t)CORE_MAX_LEVEL);
    if (m_maxLevel > MAX_LEVEL_MAX)
        m_maxLevel = MAX_LEVEL_MAX;

    if (m_maxLevel > CORE_MAX_LEVEL)
    {
        GetServices()->m_hooks->RequestSharedHook<Functions::CServerExoAppInternal__GetServerInfoFromIniFile, void, CServerExoAppInternal *>(&GetServerInfoFromIniFileHook);
        GetServices()->m_hooks->RequestSharedHook<Functions::CNWRules__ReloadAll, void, CNWRules *>(&ReloadAllHook);
        GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__CanLevelUp>(&CanLevelUpHook);
        GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetExpNeededForLevelUp>(&GetExpNeededForLevelUpHook);
        GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__LevelDown>(&LevelDownHook);
        m_LevelDownHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__LevelDown);
        GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreature__SummonAssociate>(&SummonAssociateHook);
        m_SummonAssociateHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreature__SummonAssociate);
        GetServices()->m_hooks->RequestSharedHook<Functions::CNWClass__LoadSpellGainTable, void, CNWClass *, CExoString *>(&LoadSpellGainTableHook);
        GetServices()->m_hooks->RequestSharedHook<Functions::CNWClass__LoadSpellKnownTable, void, CNWClass *, CExoString *>(&LoadSpellKnownTableHook);
        GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWClass__GetSpellGain>(&GetSpellGainHook);
        GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWClass__GetSpellsKnownPerLevel>( &GetSpellsKnownPerLevelHook);
    }
}

MaxLevel::~MaxLevel()
{
}

void MaxLevel::GetServerInfoFromIniFileHook(Services::Hooks::CallType type, CServerExoAppInternal* pServer)
{
    if (type == Services::Hooks::CallType::AFTER_ORIGINAL)
    {
        pServer->m_pServerInfo->m_JoiningRestrictions.nMaxLevel = g_plugin->m_maxLevel;
    }
}

// After Rules aggregates all its information we add to our custom experience table map
void MaxLevel::ReloadAllHook(Services::Hooks::CallType type, CNWRules* pRules)
{
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL || !pRules)
        return;

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
            return;
        }
        else
        {
            g_plugin->m_nExperienceTableAdded[i] = xpLevel;
        }
    }
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
        g_plugin->m_LevelDownHook->CallOriginal<void>(pStats, pLevelStats);
}

// The resref passed into SummonAssociate has the template utc with the character's level appended to it, just
// swap that level back to 40 if that utc doesn't exist. This is easier than rewriting SummonFamilar and
// SummonAnimalCompanion completely
void MaxLevel::SummonAssociateHook(CNWSCreature *pCreature, CResRef cResRef, CExoString *p_sAssociateName,
                                   uint16_t nAssociateType)
{
    auto cUsedResRef = cResRef;
    std::string sResRef = cResRef.GetResRef();
    if (!Globals::ExoResMan()->Exists(cResRef, 2027, nullptr))
    {
        std::regex re("(.*)[4-9][0-9]");
        std::string sNewResRef = std::regex_replace(sResRef,re,"$0140");
        cUsedResRef = CResRef(sNewResRef.c_str());
    }
    g_plugin->m_SummonAssociateHook->CallOriginal<void>(pCreature, cUsedResRef, p_sAssociateName, nAssociateType);
}

// After the server loads 1-40 we populate our map with the values for 41+
void MaxLevel::LoadSpellGainTableHook(Services::Hooks::CallType type, CNWClass* pClass, CExoString *pTable)
{
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
        return;

    C2DA twoda(pTable->CStr(), true);
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
void MaxLevel::LoadSpellKnownTableHook(Services::Hooks::CallType type, CNWClass* pClass, CExoString *pTable)
{
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
        return;

    C2DA twoda(pTable->CStr(), true);
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
                spellsKnownPreviousSpellLevel = pClass->m_lstSpellKnownTable[CORE_MAX_LEVEL][nSpellLevel - 1];
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
