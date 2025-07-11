#include "Events.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWRules.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooks::Hook s_CalcStatModifierHook;

static char CalcStatModifierHook(CNWSCreatureStats*, uint8_t);

static int s_AbilityMin;

void AbilityEvents() __attribute__((constructor));
void AbilityEvents()
{
    InitOnFirstSubscribe("NWNX_ON_ABILITY_CHANGE_.*", []() {
        s_AbilityMin = Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("CHARGEN_BASE_ABILITY_MIN"), 8);
        s_CalcStatModifierHook = Hooks::HookFunction(&CNWSCreatureStats::CalcStatModifier, &CalcStatModifierHook, Hooks::Order::Earliest);
    });
}

char CalcStatModifierHook(CNWSCreatureStats *thisPtr, uint8_t nValue)
{
    if (!thisPtr->m_bIsPC) return s_CalcStatModifierHook->CallOriginal<char>(thisPtr, nValue);

    // If one of the abilities is below the minimum the creature is still being initialized.
    // It looks like all the abilities of a new creature object start at 3 and are then set higher one by one.
    // Don't send events while initializtion is going on.
    if (thisPtr->GetSTRStat() < s_AbilityMin ||
        thisPtr->GetDEXStat() < s_AbilityMin ||
        thisPtr->GetCONStat() < s_AbilityMin ||
        thisPtr->GetINTStat() < s_AbilityMin ||
        thisPtr->GetWISStat() < s_AbilityMin ||
        thisPtr->GetCHAStat() < s_AbilityMin)
    {
        return s_CalcStatModifierHook->CallOriginal<char>(thisPtr, nValue);
    }

    bool signalEvent = false;
    auto ability = Constants::Ability::None;

    if (!thisPtr->m_pBaseCreature->nwnxGet<int32_t>("STR"))
    {
        // At this point all abilities are set to a real value for the first time for this creature.
        // The last of the abilities has just been raised (from 3) to its real base value.
        // So the initialization of the creature is done. Store all abilities for future comparison.
        // There was still no actual change to care about though. Don't send an event for this.
        thisPtr->m_pBaseCreature->nwnxSet("STR", thisPtr->GetSTRStat());
        thisPtr->m_pBaseCreature->nwnxSet("DEX", thisPtr->GetDEXStat());
        thisPtr->m_pBaseCreature->nwnxSet("CON", thisPtr->GetCONStat());
        thisPtr->m_pBaseCreature->nwnxSet("INT", thisPtr->GetINTStat());
        thisPtr->m_pBaseCreature->nwnxSet("WIS", thisPtr->GetWISStat());
        thisPtr->m_pBaseCreature->nwnxSet("CHA", thisPtr->GetCHAStat());
    }
    else if (thisPtr->m_pBaseCreature->nwnxGet<int32_t>("STR") != thisPtr->GetSTRStat())
    {
        thisPtr->m_pBaseCreature->nwnxSet("STR", thisPtr->GetSTRStat());
        signalEvent = true;
        ability = Constants::Ability::Strength;
    }
    else if (thisPtr->m_pBaseCreature->nwnxGet<int32_t>("DEX") != thisPtr->GetDEXStat())
    {
        thisPtr->m_pBaseCreature->nwnxSet("DEX", thisPtr->GetDEXStat());
        signalEvent = true;
        ability = Constants::Ability::Dexterity;
    }
    else if (thisPtr->m_pBaseCreature->nwnxGet<int32_t>("CON") != thisPtr->GetCONStat())
    {
        thisPtr->m_pBaseCreature->nwnxSet("CON", thisPtr->GetCONStat());
        signalEvent = true;
        ability = Constants::Ability::Constitution;
    }
    else if (thisPtr->m_pBaseCreature->nwnxGet<int32_t>("INT") != thisPtr->GetINTStat())
    {
        thisPtr->m_pBaseCreature->nwnxSet("INT", thisPtr->GetINTStat());
        signalEvent = true;
        ability = Constants::Ability::Intelligence;
    }
    else if (thisPtr->m_pBaseCreature->nwnxGet<int32_t>("WIS") != thisPtr->GetWISStat())
    {
        thisPtr->m_pBaseCreature->nwnxSet("WIS", thisPtr->GetWISStat());
        signalEvent = true;
        ability = Constants::Ability::Wisdom;
    }
    else if (thisPtr->m_pBaseCreature->nwnxGet<int32_t>("CHA") != thisPtr->GetCHAStat())
    {
        thisPtr->m_pBaseCreature->nwnxSet("CHA", thisPtr->GetCHAStat());
        signalEvent = true;
        ability = Constants::Ability::Charisma;
    }

    if (signalEvent)
    {
        PushEventData("ABILITY", std::to_string(ability));
        PushEventData("VALUE", std::to_string(nValue));
        SignalEvent("NWNX_ON_ABILITY_CHANGE_BEFORE", thisPtr->m_pBaseCreature->m_idSelf);
    }
    auto retVal = s_CalcStatModifierHook->CallOriginal<char>(thisPtr, nValue);
    if (signalEvent)
    {
        PushEventData("ABILITY", std::to_string(ability));
        PushEventData("VALUE", std::to_string(nValue));
        PushEventData("MOD", std::to_string(retVal));
        SignalEvent("NWNX_ON_ABILITY_CHANGE_AFTER", thisPtr->m_pBaseCreature->m_idSelf);
    }
    return retVal;
}

}
