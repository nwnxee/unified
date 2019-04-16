#include "Extra2DA.hpp"

#include "Services/Tasks/Tasks.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CNWSScriptVarTable.hpp"
#include "API/C2DA.hpp"

#include <sstream>
#include <iterator>
#include <algorithm>

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Extra2DA::Extra2DA> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Extra2DA",
        "Support for additional 2DA files",
        "Sagil",
        "henning.koehler.nz at gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Extra2DA::Extra2DA(params);
    return g_plugin;
}

namespace Extra2DA {

//--------------------------- Local Stuff ---------------------------

static const uint8_t CLASS_DRAGON_DISCIPLE = 37;
static const StatBonus NO_BONUS = {};

// we store adjustments made to dragon ability bonuses in PerObjectStorage
// this allows us to correctly de-level and verify characters
static const std::string DragonAbilityVariable("DragonAbilities");

// NOT a duplicate of CNWSCreatureStats::GetClassLevel
static uint8_t GetClassLevel(const CNWSCreatureStats& stats, uint8_t classType)
{
    for ( uint8_t multiClass = 0; multiClass < stats.m_nNumMultiClasses; multiClass++ )
    {
        const CNWSCreatureStats_ClassInfo &classInfo = stats.m_ClassInfo[multiClass];
        if ( classInfo.m_nClass == classType )
            return classInfo.m_nLevel;
    }
    return 0;
}

//--------------------------- StatBonus(es) -------------------------

void StatBonus::operator+=(const StatBonus &other)
{
    for ( uint8_t stat = 0; stat < 6; stat++ )
        (*this)[stat] += other[stat];
}

void StatBonus::operator-=(const StatBonus &other)
{
    for ( uint8_t stat = 0; stat < 6; stat++ )
        (*this)[stat] -= other[stat];
}

static const char StatCodes[6] = { 'S', 'D', 'N', 'I', 'W', 'C' };

std::string StatBonuses::encode() const
{
    std::ostringstream oss;
    int counter = 0;
    for ( size_t level = 1; level < size(); level++ )
        for ( uint8_t stat = 0; stat < 6; stat++ )
            if ( (*this)[level][stat] )
            {
                if ( counter++ )
                    oss << ' ';
                oss << level << StatCodes[stat] << (*this)[level][stat];
            }
    return oss.str();
}

StatBonuses StatBonuses::decode(const std::string &s)
{
    StatBonuses result;
    if ( !s.empty() )
    {
        size_t level;
        char statCode;
        int32_t bonus;
        std::istringstream iss(s);
        while ( iss )
        {
            iss >> level >> statCode >> bonus;
            size_t stat = 0;
            while ( stat < 6 && StatCodes[stat] != statCode )
                stat++;
            ASSERT_MSG(stat < 6, "unknown stat code '%c' in '%s'", statCode, s);
            if ( level >= result.size() )
                result.resize(level + 1, NO_BONUS);
            result[level][stat] = bonus;
        }
    }
    return result;
}

//--------------------------- Extra2DA ------------------------------

Extra2DA::Extra2DA(const Plugin::CreateParams& params)
  : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Extra2DA::func, this, std::placeholders::_1))

    REGISTER(GetDragonAbilityDivergence);
    REGISTER(GetDragonAbilityHistory);
    REGISTER(SetDragonAbilityHistory);

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__ComputeFeatBonuses>(&Extra2DA::OnComputeFeatBonuses);
    m_ComputeFeatBonusesHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__ComputeFeatBonuses);

    // can't load 2DAs yet as NWN resource manager won't be ready
    GetServices()->m_tasks->QueueOnMainThread(LoadDragonAbilityBonuses);
}

Extra2DA::~Extra2DA()
{
}

ArgumentStack Extra2DA::GetDragonAbilityDivergence(ArgumentStack&& args)
{
    ArgumentStack stack;

    int32_t result = 0;
    Types::ObjectID oidCreature = Services::Events::ExtractArgument<Types::ObjectID>(args);
    CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(oidCreature);
    if ( pCreature && pCreature->m_bPlayerCharacter )
    {
        // find first dragon disciple level where scores diverge
        const uint8_t dragonLevel = GetClassLevel(*pCreature->m_pStats, CLASS_DRAGON_DISCIPLE);
        const StatBonuses &sb = g_plugin->m_DragonAbilityBonuses;
        const StatBonuses sbHistory = StatBonuses::decode(GetDragonAbilityHistoryInternal(pCreature));
        uint8_t dragonDivergence = 0;
        for ( uint8_t level = 1; level <= dragonLevel; level++ )
        {
            StatBonus awarded = level < sbHistory.size() ? sbHistory[level] : NO_BONUS;
            StatBonus expected = level < sb.size() ? sb[level] : NO_BONUS;
            if ( awarded != expected )
            {
                dragonDivergence = level;
                break;
            }
        }
        // find character level at which diverging dragon disciple level was taken
        if ( dragonDivergence )
        {
            const CExoArrayListTemplatedCNWLevelStatsPtr& levelStats = pCreature->m_pStats->m_lstLevelStats;
            for ( result = 0; result < levelStats.num; result++ )
                if ( levelStats.element[result]->m_nClass == CLASS_DRAGON_DISCIPLE )
                    if ( --dragonDivergence == 0 )
                        break;
            result++; // 0-based indexing vs 1-based levels
        }
    }
    Services::Events::InsertArgument(stack, result);
    return stack;
}

ArgumentStack Extra2DA::GetDragonAbilityHistory(ArgumentStack&& args)
{
    ArgumentStack stack;
    std::string result;

    Types::ObjectID oidCreature = Services::Events::ExtractArgument<Types::ObjectID>(args);
    CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(oidCreature);
    if ( pCreature && pCreature->m_bPlayerCharacter )
        result = GetDragonAbilityHistoryInternal(pCreature);

    Services::Events::InsertArgument(stack, result);
    return stack;
}

ArgumentStack Extra2DA::SetDragonAbilityHistory(ArgumentStack&& args)
{
    ArgumentStack stack;

    Types::ObjectID oidCreature = Services::Events::ExtractArgument<Types::ObjectID>(args);
    std::string sHistory = Services::Events::ExtractArgument<std::string>(args);

    CNWSCreature *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(oidCreature);
    if ( pCreature && pCreature->m_bPlayerCharacter )
        SetDragonAbilityHistoryInternal(pCreature, sHistory);

    return stack;
}

void Extra2DA::LoadDragonAbilityBonuses()
{
    // load new bonuses from 2da file
    C2DA dragon2DA("dragon", false);
    if ( dragon2DA.Load2DArray() )
    {
        if ( dragon2DA.m_nNumRows )
        {
            StatBonuses &sb = g_plugin->m_DragonAbilityBonuses;
            sb.resize(dragon2DA.m_nNumRows, NO_BONUS);
            for ( uint8_t level = 1; level < dragon2DA.m_nNumRows; level++ )
                for ( uint8_t stat = 0; stat < 6; stat++ )
                    if ( !dragon2DA.GetINTEntry(level, stat, &sb[level][stat]) )
                        LOG_WARNING("Failed to get entry for row %d column %d in dragon.2da.", level, stat);
            // subtract original bonuses
            std::vector<uint8_t> statBonusLevels[6] = { {2,4,10,10}, {}, {7}, {9}, {}, {10} };
            for ( uint8_t stat = 0; stat < 6; stat++ )
                for ( uint8_t level : statBonusLevels[stat] )
                    if ( level < sb.size() )
                        sb[level][stat] -= 2;
            LOG_DEBUG("Loaded dragon disciple stat bonuses.");
        }
        else
            LOG_WARNING("dragon.2da is empty");
    }
    else
        LOG_DEBUG("dragon.2da not found");
}

std::string Extra2DA::GetDragonAbilityHistoryInternal(CNWSCreature *pCreature)
{
    Maybe<std::string> msHistory = g_plugin->GetServices()->m_perObjectStorage->Get<std::string>(pCreature, DragonAbilityVariable);
    if ( msHistory )
    {
        LOG_NOTICE("GetDragonAbilityHistory => '%s'", msHistory->c_str());
        return *msHistory;
    }
    else
    {
        LOG_NOTICE("GetDragonAbilityHistory => not found");
        return "";
    }
}

void Extra2DA::SetDragonAbilityHistoryInternal(CNWSCreature *pCreature, const std::string& sHistory)
{
    if ( sHistory.size() )
        g_plugin->GetServices()->m_perObjectStorage->Set(pCreature, DragonAbilityVariable, sHistory);
    else
        g_plugin->GetServices()->m_perObjectStorage->Remove(pCreature, DragonAbilityVariable);
    LOG_NOTICE("SetDragonAbilityHistory('%s')", sHistory.c_str());
}

// update stats for one (current or previous) level
void Extra2DA::OnComputeFeatBonuses(CNWSCreatureStats *pThis, CExoArrayListTemplatedunsignedshort *pFeats, int32_t bSubtractBonuses, int32_t bLevelingDown)
{
    g_plugin->m_ComputeFeatBonusesHook->CallOriginal<void>(pThis, pFeats, bSubtractBonuses, bLevelingDown);
    // fix for new dragon stats
    const StatBonuses &statBonuses = g_plugin->m_DragonAbilityBonuses;
    // level-up works differently for NPCs, so we ignore them to keep things simple
    if ( statBonuses.size() && pThis->m_pBaseCreature->m_bPlayerCharacter )
    {
        StatBonus statBonus = NO_BONUS;
        // remove bonuses bigger than current level
        if ( bSubtractBonuses || bLevelingDown )
        {
            StatBonuses sbHistory = StatBonuses::decode(GetDragonAbilityHistoryInternal(pThis->m_pBaseCreature));
            const size_t dragonLevel = GetClassLevel(*pThis, CLASS_DRAGON_DISCIPLE);
            for ( size_t level = dragonLevel + 1; level < sbHistory.size(); level++ )
                statBonus -= sbHistory[level];
            if ( dragonLevel + 1 < sbHistory.size() )
            {
                sbHistory.resize(dragonLevel + 1);
                SetDragonAbilityHistoryInternal(pThis->m_pBaseCreature, sbHistory.encode());
            }
        }
        else
        {
            CNWSCreatureStats_ClassInfo &classInfo = pThis->m_ClassInfo[pThis->m_nMultiClassLeveledUpIn];
            const size_t dragonLevel = classInfo.m_nClass == CLASS_DRAGON_DISCIPLE ? classInfo.m_nLevel : 0;
            if ( dragonLevel )
            {
                StatBonuses sbHistory = StatBonuses::decode(GetDragonAbilityHistoryInternal(pThis->m_pBaseCreature));
                const StatBonus newBonus = statBonuses.size() > dragonLevel ? statBonuses[dragonLevel] : NO_BONUS;
                if ( dragonLevel < sbHistory.size() )
                {
                    LOG_WARNING("Found oversized dragon ability history. Repairing.");
                    for ( size_t level = dragonLevel; level < sbHistory.size(); level++ )
                        statBonus -= sbHistory[level];
                    sbHistory.resize(dragonLevel + 1);
                    statBonus += sbHistory[dragonLevel] = newBonus;
                    SetDragonAbilityHistoryInternal(pThis->m_pBaseCreature, sbHistory.encode());
                }
                else if ( newBonus != NO_BONUS )
                {
                    sbHistory.resize(dragonLevel + 1, NO_BONUS);
                    statBonus = sbHistory[dragonLevel] = newBonus;
                    SetDragonAbilityHistoryInternal(pThis->m_pBaseCreature, sbHistory.encode());
                }
            }
        }
        // update character
        if ( statBonus[0] ) pThis->SetSTRBase(statBonus[0] + pThis->m_nStrengthBase);
        if ( statBonus[1] ) pThis->SetDEXBase(statBonus[1] + pThis->m_nDexterityBase);
        if ( statBonus[2] ) pThis->SetCONBase(statBonus[2] + pThis->m_nConstitutionBase, false);
        if ( statBonus[3] ) pThis->SetINTBase(statBonus[3] + pThis->m_nIntelligenceBase);
        if ( statBonus[4] ) pThis->SetWISBase(statBonus[4] + pThis->m_nWisdomBase);
        if ( statBonus[5] ) pThis->SetCHABase(statBonus[5] + pThis->m_nCharismaBase);
        // update prePolymorph stats
        CNWSCreature *baseCreature = pThis->m_pBaseCreature;
        if ( baseCreature->m_bIsPolymorphed )
        {
            baseCreature->m_nPrePolymorphSTR += statBonus[0];
            baseCreature->m_nPrePolymorphDEX += statBonus[1];
            baseCreature->m_nPrePolymorphCON += statBonus[2];
        }
        if ( statBonus != NO_BONUS )
            LOG_DEBUG("OnComputeFeatBonuses: modified abilities by %d %d %d %d %d %d",
                      statBonus[0], statBonus[1], statBonus[2], statBonus[3], statBonus[4], statBonus[5]);
    }
}

}
