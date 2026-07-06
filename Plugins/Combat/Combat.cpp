#include "Combat.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWFeat.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSRules.hpp"
#include "Utils.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

static Combat::Combat* g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Combat",
        "Combat related functions",
        "GoLoT",
        "golot@golot.es",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Combat::Combat(params);
    return g_plugin;
}

namespace Combat
{

NWNXLib::Hooking::FunctionHook* s_useFeatHook = nullptr;
NWNXLib::Hooking::FunctionHook* s_resolveSpecialAttackDamageBonus = nullptr;
NWNXLib::Hooking::FunctionHook* s_resolveSpecialAttackAttackBonus = nullptr;
int32_t g_nLastReturnValue;
int32_t g_nFeat;
int32_t g_nScriptType;
OBJECT_ID g_oidTarget;
std::unordered_map<uint16_t, SpecialAttackInfo> s_specialAttackMap;

Combat::Combat(const Plugin::CreateParams& params)
    : Plugin(params)
{

#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(SetSpecialAttackInfo);
    REGISTER(SetReturnValue);
    REGISTER(GetScriptType);
    REGISTER(GetCurrentFeat);
    REGISTER(GetFeatTarget);

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN12CNWSCreature7UseFeatEttjjP6Vector>(&CNWSCreature__UseFeat);
    s_useFeatHook = GetServices()->m_hooks->FindHookByAddress(Functions::_ZN12CNWSCreature7UseFeatEttjjP6Vector);
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN12CNWSCreature25ResolveMeleeSpecialAttackEiiP10CNWSObjecti, void>(&CNWSCreature__ResolveMeleeSpecialAttack);
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN12CNWSCreature26ResolveRangedSpecialAttackEP10CNWSObjecti, void>(&CNWSCreature__ResolveRangedSpecialAttack);
    GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats31ResolveSpecialAttackDamageBonusEP12CNWSCreature>(&CNWSCreatureStats__ResolveSpecialAttackDamageBonus);
    s_resolveSpecialAttackDamageBonus = GetServices()->m_hooks->FindHookByAddress(Functions::_ZN17CNWSCreatureStats31ResolveSpecialAttackDamageBonusEP12CNWSCreature);
    GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats31ResolveSpecialAttackAttackBonusEP12CNWSCreature>(&CNWSCreatureStats__ResolveSpecialAttackAttackBonus);
    s_resolveSpecialAttackAttackBonus = GetServices()->m_hooks->FindHookByAddress(Functions::_ZN17CNWSCreatureStats31ResolveSpecialAttackAttackBonusEP12CNWSCreature);
}

Combat::~Combat()
{}

bool CheckAttackResultHit(uint8_t nAttackResult)
{
    return nAttackResult == 1 || nAttackResult == 3 || nAttackResult == 5 ||
        nAttackResult == 6 || nAttackResult == 7 || nAttackResult == 10;
}

BOOL Combat::CNWSCreature__UseFeat(CNWSCreature* thisPtr, uint16_t nFeat, uint16_t nSubFeat, OBJECT_ID oidTarget, OBJECT_ID oidArea, Vector* pvTarget)
{
    if (!thisPtr)
        return false;

    nFeat = thisPtr->m_pStats->GetHighestLevelOfFeat(nFeat);
    if (!thisPtr->m_pStats->HasFeat(nFeat))
        return false;

    auto attackInfoEntry = s_specialAttackMap.find(nFeat);
    if (attackInfoEntry == s_specialAttackMap.end())
        return s_useFeatHook->CallOriginal<BOOL>(thisPtr, nFeat, nSubFeat, oidTarget, oidArea, pvTarget);
    auto& attackInfo = attackInfoEntry->second;

    if (thisPtr->m_nState == 5)
    {
        thisPtr->SendFeedbackMessage(7, nullptr, nullptr);
        return false;
    }

    auto* pTarget = Utils::GetGameObject(oidTarget);
    auto* pFeat = Globals::Rules()->GetFeat(nFeat);
    if (oidTarget != Constants::OBJECT_INVALID && pTarget && Utils::AsNWSCreature(pTarget)
        && pFeat->m_bHostileFeat && thisPtr->GetAIStateReaction(oidTarget) == 1)
    {
        thisPtr->SendFeedbackMessage(0xbb, nullptr, nullptr);
        return false;
    }

    if (!thisPtr->m_pStats->GetFeatRemainingUses(nFeat))
    {
        thisPtr->SendFeedbackMessage(199, nullptr, nullptr);
        return false;
    }

    thisPtr->AddAttackActions(oidTarget, 0, 0, 0);

    bool bRangedWeapon = thisPtr->GetRangeWeaponEquipped();
    if ((attackInfo.nAttackRangeType == SpecialAttackRangeType::Melee && bRangedWeapon)
        || (attackInfo.nAttackRangeType == SpecialAttackRangeType::Ranged && !bRangedWeapon))
        return false;

    bool bAllowed = true;

    if (!attackInfo.sTestRequirementsScript.empty())
    {
        //TODO: Add params
        g_nLastReturnValue = bAllowed;
        g_nScriptType = ScriptType::RequirementsScript;
        g_nFeat = attackInfo.nFeatId;
        g_oidTarget = pTarget->m_idSelf;
        Utils::ExecuteScript(attackInfo.sTestRequirementsScript, thisPtr->m_idSelf);
        bAllowed = !!g_nLastReturnValue;
    }

    if (bAllowed)
        thisPtr->m_pcCombatRound->AddSpecialAttack(nFeat);

    return bAllowed;
}

void Combat::CNWSCreature__ResolveMeleeSpecialAttack(bool before, CNWSCreature* thisPtr, int32_t, int32_t, CNWSObject* pTarget, int32_t)
{
    if (before || !pTarget)
        return;

    auto pCombatRound = thisPtr->m_pcCombatRound;
    auto nCurrentAttack = pCombatRound->m_nCurrentAttack;
    auto pAttack = pCombatRound->GetAttack(nCurrentAttack);

    auto nFeat = pAttack->m_nAttackType;

    if (!nFeat || !CheckAttackResultHit(pAttack->m_nAttackResult))
        return;

    auto attackInfoEntry = s_specialAttackMap.find(nFeat);
    if (attackInfoEntry == s_specialAttackMap.end())
        return;

    auto& attackInfo = attackInfoEntry->second;
    if (attackInfo.sPostDamageScript.empty())
        return;

    auto nDamage = pAttack->GetTotalDamage(1);
    if (nDamage > 0)
    {
        //TODO: Add params
        g_nScriptType = ScriptType::PostDamageScript;
        g_nFeat = attackInfo.nFeatId;
        g_oidTarget = pTarget->m_idSelf;
        Utils::ExecuteScript(attackInfo.sPostDamageScript, thisPtr->m_idSelf);
    }
}

void Combat::CNWSCreature__ResolveRangedSpecialAttack(bool before, CNWSCreature* thisPtr, CNWSObject* pTarget, int32_t)
{
    if (before || !pTarget)
        return;

    auto pCombatRound = thisPtr->m_pcCombatRound;
    auto nCurrentAttack = pCombatRound->m_nCurrentAttack;
    auto pAttack = pCombatRound->GetAttack(nCurrentAttack);

    auto nFeat = pAttack->m_nAttackType;

    if (!nFeat || !CheckAttackResultHit(pAttack->m_nAttackResult))
        return;

    auto attackInfoEntry = s_specialAttackMap.find(nFeat);
    if (attackInfoEntry == s_specialAttackMap.end())
        return;

    auto& attackInfo = attackInfoEntry->second;
    if (attackInfo.sPostDamageScript.empty())
        return;

    auto nDamage = pAttack->GetTotalDamage(1);
    if (nDamage > 0)
    {
        //TODO: Add params
        g_nScriptType = ScriptType::PostDamageScript;
        g_nFeat = attackInfo.nFeatId;
        g_oidTarget = pTarget->m_idSelf;
        Utils::ExecuteScript(attackInfo.sPostDamageScript, thisPtr->m_idSelf);
    }
}

int32_t Combat::CNWSCreatureStats__ResolveSpecialAttackDamageBonus(CNWSCreatureStats* thisPtr, CNWSCreature* pTarget)
{
    auto pCombatData = thisPtr->m_pBaseCreature->m_pcCombatRound;
    auto pAttackData = pCombatData->GetAttack(pCombatData->m_nCurrentAttack);

    auto nFeat = pAttackData->m_nAttackType;
    auto attackInfoEntry = s_specialAttackMap.find(nFeat);
    if (attackInfoEntry == s_specialAttackMap.end())
        return s_resolveSpecialAttackDamageBonus->CallOriginal<int32_t>(thisPtr, pTarget);

    auto& attackInfo = attackInfoEntry->second;

    int32_t nScriptModifier = 0;
    if (!attackInfo.sDamageModScript.empty())
    {
        //TODO: Add params
        g_nLastReturnValue = nScriptModifier;
        g_nScriptType = ScriptType::DamageModifierScript;
        g_nFeat = attackInfo.nFeatId;
        g_oidTarget = pTarget->m_idSelf;
        Utils::ExecuteScript(attackInfo.sDamageModScript, thisPtr->m_pBaseCreature->m_idSelf);
        nScriptModifier = g_nLastReturnValue;
    }

    return attackInfo.nDamageModifier + nScriptModifier;
}

int32_t Combat::CNWSCreatureStats__ResolveSpecialAttackAttackBonus(CNWSCreatureStats* thisPtr, CNWSCreature* pTarget)
{
    auto pCombatData = thisPtr->m_pBaseCreature->m_pcCombatRound;
    auto pAttackData = pCombatData->GetAttack(pCombatData->m_nCurrentAttack);

    auto nFeat = pAttackData->m_nAttackType;
    auto attackInfoEntry = s_specialAttackMap.find(nFeat);
    if (attackInfoEntry == s_specialAttackMap.end())
        return s_resolveSpecialAttackDamageBonus->CallOriginal<int32_t>(thisPtr, pTarget);

    auto& attackInfo = attackInfoEntry->second;

    int32_t nScriptModifier = 0;
    if (!attackInfo.sAttackModScript.empty())
    {
        //TODO: Add params
        g_nLastReturnValue = nScriptModifier;
        g_nScriptType = ScriptType::AttackModifierScript;
        g_nFeat = attackInfo.nFeatId;
        g_oidTarget = pTarget->m_idSelf;
        Utils::ExecuteScript(attackInfo.sAttackModScript, thisPtr->m_pBaseCreature->m_idSelf);
        nScriptModifier = g_nLastReturnValue;
    }

    return attackInfo.nAttackModifier + nScriptModifier;
}

ArgumentStack Combat::SetSpecialAttackInfo(ArgumentStack&& args)
{
    ArgumentStack stack;

    auto nFeat = Services::Events::ExtractArgument<int32_t>(args);
    auto nAttackRangeType = Services::Events::ExtractArgument<int32_t>(args);
    auto nDamageModifier = Services::Events::ExtractArgument<int32_t>(args);
    auto nAttackModifier = Services::Events::ExtractArgument<int32_t>(args);
    auto sTestRequirementsScript = Services::Events::ExtractArgument<std::string>(args);
    auto sAttackModScript = Services::Events::ExtractArgument<std::string>(args);
    auto sDamageModScript = Services::Events::ExtractArgument<std::string>(args);
    auto sPostDamageScript = Services::Events::ExtractArgument<std::string>(args);

    ASSERT_OR_THROW(nFeat > 0);
    ASSERT_OR_THROW(nFeat < Globals::Rules()->m_nNumFeats);
    ASSERT_OR_THROW(nAttackRangeType >= SpecialAttackRangeType::Any);
    ASSERT_OR_THROW(nAttackRangeType <= SpecialAttackRangeType::Ranged);

    auto& attackInfo = s_specialAttackMap[nFeat];

    attackInfo.nFeatId = nFeat;
    attackInfo.nAttackRangeType = static_cast<SpecialAttackRangeType::TYPE>(nAttackRangeType);
    attackInfo.nDamageModifier = nDamageModifier;
    attackInfo.nAttackModifier = nAttackModifier;
    attackInfo.sTestRequirementsScript = sTestRequirementsScript;
    attackInfo.sAttackModScript = sAttackModScript;
    attackInfo.sDamageModScript = sDamageModScript;
    attackInfo.sPostDamageScript = sPostDamageScript;

    return stack;
}

ArgumentStack Combat::SetReturnValue(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto nRet = Services::Events::ExtractArgument<int32_t>(args);
    g_nLastReturnValue = nRet;
    return stack;
}

ArgumentStack Combat::GetScriptType(ArgumentStack&&)
{
    ArgumentStack stack;
    Services::Events::InsertArgument(stack, g_nScriptType);
    return stack;
}

ArgumentStack Combat::GetCurrentFeat(ArgumentStack&&)
{
    ArgumentStack stack;
    Services::Events::InsertArgument(stack, g_nFeat);
    return stack;
}

ArgumentStack Combat::GetFeatTarget(ArgumentStack&&)
{
    ArgumentStack stack;
    Services::Events::InsertArgument(stack, g_oidTarget);
    return stack;
}

}
