#include "nwnx.hpp"

#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include "API/CGameEffect.hpp"
#include "API/CNWSObject.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWSEffectListHandler.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSSpellScriptData.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWVisibilityNode.hpp"
#include "API/C2DA.hpp"

#include <cstring>
#include <bitset>

using namespace NWNXLib;
using namespace NWNXLib::API;

constexpr int32_t MAX_DAMAGE_TYPES = 32;

constexpr int32_t CRIT_MODE_DONT = 0;
constexpr int32_t CRIT_MODE_ROLL = 1;
constexpr int32_t CRIT_MODE_CRIT = 2;

constexpr int32_t SNEAK_MODE_DONT  = 0;
constexpr int32_t SNEAK_MODE_CHECK = 1;
constexpr int32_t SNEAK_MODE_DO    = 2;

struct DamageData
{
    uint32_t oidDamager;
    int32_t vDamage[MAX_DAMAGE_TYPES];
};

struct AttackData
{
    uint32_t oidTarget;
    int16_t vDamage[MAX_DAMAGE_TYPES];
    uint8_t nAttackNumber;
    uint8_t nAttackResult;
    uint8_t nWeaponAttackType;
    uint8_t nSneakAttack;
    uint8_t bRanged;
    int32_t bKillingBlow;
    uint16_t nAttackType;
    uint8_t nToHitRoll;
    int32_t nToHitModifier;
};

static std::unordered_map<std::string, std::string> s_EventScriptMap;
static DamageData s_DamageData;
static AttackData s_AttackData;

static std::string GetEventScript(CNWSObject*, const std::string&);
static void HandleSignalDamage(CNWSCreature*, CNWSObject*, int32_t);

static Hooks::Hook s_OnApplyDamageHook = Hooks::HookFunction(&CNWSEffectListHandler::OnApplyDamage,
    +[](CNWSEffectListHandler *pThis, CNWSObject *pObject, CGameEffect *pEffect, BOOL bLoadingGame) -> BOOL
    {
        std::string sScript = GetEventScript(pObject, "DAMAGE");

        if (!sScript.empty())
        {
            if (Utils::AsNWSCreature(pObject) || Utils::AsNWSPlaceable(pObject))
            {
                s_DamageData.oidDamager = pEffect->m_oidCreator;
                std::memcpy(s_DamageData.vDamage, pEffect->m_nParamInteger, MAX_DAMAGE_TYPES * sizeof(int32_t));
                Utils::ExecuteScript(sScript, pObject->m_idSelf);
                std::memcpy(pEffect->m_nParamInteger, s_DamageData.vDamage, MAX_DAMAGE_TYPES * sizeof(int32_t));
            }
        }

       return s_OnApplyDamageHook->CallOriginal<BOOL>(pThis, pObject, pEffect, bLoadingGame);
    }, Hooks::Order::Late);

static Hooks::Hook s_SignalMeleeDamageHook = Hooks::HookFunction(&CNWSCreature::SignalMeleeDamage,
    +[](CNWSCreature *pThis, CNWSObject *pTarget, int32_t nAttacks) -> void
    {
        HandleSignalDamage(pThis, pTarget, nAttacks);
        s_SignalMeleeDamageHook->CallOriginal<void>(pThis, pTarget, nAttacks);
    }, Hooks::Order::Late);

static Hooks::Hook s_SignalRangedDamageHook = Hooks::HookFunction(&CNWSCreature::SignalRangedDamage,
    +[](CNWSCreature *pThis, CNWSObject *pTarget, int32_t nAttacks) -> void
    {
        HandleSignalDamage(pThis, pTarget, nAttacks);
        s_SignalRangedDamageHook->CallOriginal<void>(pThis, pTarget, nAttacks);
    }, Hooks::Order::Late);

static std::string GetEventScript(CNWSObject *pObject, const std::string& sEventType)
{
    if (auto posScript = pObject->nwnxGet<std::string>(sEventType + "_EVENT_SCRIPT"))
        return *posScript;
    else
        return s_EventScriptMap[sEventType];
}

static void OnCombatAttack(CNWSCreature *pThis, CNWSObject *pTarget, const std::string& sScript, uint8_t nAttackNumber)
{
    CNWSCombatAttackData *pCombatAttackData = pThis->m_pcCombatRound->GetAttack(nAttackNumber);

    s_AttackData.oidTarget = pTarget->m_idSelf;
    s_AttackData.nAttackNumber = nAttackNumber + 1; // 1-based for backwards compatibility
    s_AttackData.nAttackResult = pCombatAttackData->m_nAttackResult;
    s_AttackData.nWeaponAttackType = pCombatAttackData->m_nWeaponAttackType;
    s_AttackData.nSneakAttack = pCombatAttackData->m_bSneakAttack + (pCombatAttackData->m_bDeathAttack << 1);
    s_AttackData.bKillingBlow = pCombatAttackData->m_bKillingBlow;
    s_AttackData.nAttackType = pCombatAttackData->m_nAttackType;
    s_AttackData.nToHitRoll = pCombatAttackData->m_nToHitRoll;
    s_AttackData.nToHitModifier = pCombatAttackData->m_nToHitMod;

    std::memcpy(s_AttackData.vDamage, pCombatAttackData->m_nDamage, MAX_DAMAGE_TYPES * sizeof(int16_t));
    Utils::ExecuteScript(sScript, pThis->m_idSelf);
    std::memcpy(pCombatAttackData->m_nDamage, s_AttackData.vDamage, MAX_DAMAGE_TYPES * sizeof(int16_t));

    pCombatAttackData->m_nAttackResult = s_AttackData.nAttackResult;
}

static void HandleSignalDamage(CNWSCreature *pThis, CNWSObject *pTarget, int32_t nAttacks)
{
    std::string sScript = GetEventScript(pThis, "ATTACK");
    if (!sScript.empty())
    {
        // m_nCurrentAttack points to the attack *after* this flurry
        uint8_t nAttackNumberOffset = pThis->m_pcCombatRound->m_nCurrentAttack - nAttacks;
        // trigger script once per attack in the flurry
        for (int32_t i = 0; i < nAttacks; i++)
            OnCombatAttack(pThis, pTarget, sScript, nAttackNumberOffset + i);
    }
}

NWNX_EXPORT ArgumentStack SetEventScript(ArgumentStack&& args)
{
    const auto sEvent = Events::ExtractArgument<std::string>(args);
    const auto sScript = Events::ExtractArgument<std::string>(args);
    const auto oidTarget = Events::ExtractArgument<ObjectID>(args);

    if (oidTarget == Constants::OBJECT_INVALID)
    {
        s_EventScriptMap[sEvent] = sScript;
        LOG_INFO("Set Global %s Event Script to %s", sEvent, sScript);
    }
    else
    {
        if (auto pTarget = Utils::GetGameObject(oidTarget))
        {
            if (!sScript.empty())
            {
                pTarget->nwnxSet(sEvent + "_EVENT_SCRIPT", sScript, true);
                LOG_INFO("Set object %s %s Event Script to %s", Utils::ObjectIDToString(oidTarget), sEvent, sScript);
            }
            else
            {
                pTarget->nwnxRemove(sEvent + "_EVENT_SCRIPT");
                LOG_INFO("Clearing %s Event Script for object %s", sEvent, Utils::ObjectIDToString(oidTarget));
            }
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetDamageEventData(ArgumentStack&&)
{
    ArgumentStack stack;

    for (int k = (MAX_DAMAGE_TYPES - 1); k >= 0; k--)
    {
        Events::InsertArgument(stack, s_DamageData.vDamage[k]);
    }
    Events::InsertArgument(stack, s_DamageData.oidDamager);

    return stack;
}

NWNX_EXPORT ArgumentStack SetDamageEventData(ArgumentStack&& args)
{
    for (int &k : s_DamageData.vDamage)
    {
        k = args.extract<int32_t>();
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetAttackEventData(ArgumentStack&&)
{
    ArgumentStack stack;

    Events::InsertArgument(stack, s_AttackData.nToHitModifier);
    Events::InsertArgument(stack, s_AttackData.nToHitRoll);
    Events::InsertArgument(stack, s_AttackData.nAttackType);
    Events::InsertArgument(stack, s_AttackData.bKillingBlow);
    Events::InsertArgument(stack, s_AttackData.nSneakAttack);
    Events::InsertArgument(stack, s_AttackData.nWeaponAttackType);
    Events::InsertArgument(stack, s_AttackData.nAttackResult);
    Events::InsertArgument(stack, s_AttackData.nAttackNumber);
    for (int k = (MAX_DAMAGE_TYPES - 1); k >= 0; k--)
    {
        Events::InsertArgument(stack, s_AttackData.vDamage[k]);
    }
    Events::InsertArgument(stack, s_AttackData.oidTarget);

    return stack;
}

NWNX_EXPORT ArgumentStack SetAttackEventData(ArgumentStack&& args)
{
    for (short & k : s_AttackData.vDamage)
    {
        k = (int16_t)args.extract<int32_t>();
    }
    s_AttackData.nAttackResult = args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack DealDamage(ArgumentStack&& args)
{
    int vDamage[MAX_DAMAGE_TYPES];
    std::bitset<MAX_DAMAGE_TYPES> positive;

    const auto oidSource = Events::ExtractArgument<ObjectID>(args);
    const auto oidTarget = Events::ExtractArgument<ObjectID>(args);

    for (int k = 0; k < MAX_DAMAGE_TYPES; k++)
    {
        vDamage[k] = args.extract<int32_t>();
        // need to distinguish between no damage dealt, and damage reduced to 0
        positive[k] = vDamage[k] > 0;
    }
    const auto damagePower = args.extract<int32_t>();
    const auto rangedDamage = args.extract<int32_t>();

    if (auto *pTarget = Utils::AsNWSObject(Utils::GetGameObject(oidTarget)))
    {
        auto *pSource = Utils::AsNWSCreature(Utils::GetGameObject(oidSource));

        // apply damage immunity and resistance
        for (int k = 0; k < MAX_DAMAGE_TYPES; k++)
        {
            if (k == 12) continue; // Skip Base damage type

            if (vDamage[k] > 0)
                vDamage[k] = pTarget->DoDamageImmunity(pSource, vDamage[k], 1 << k, false, false);
            if (vDamage[k] > 0)
                vDamage[k] = pTarget->DoDamageResistance(pSource, vDamage[k], 1 << k, false, false, false);
        }

        // apply DR (combine physical damage for this)
        vDamage[12] = vDamage[0] + vDamage[1] + vDamage[2];
        positive[12] = positive[0] || positive[1] || positive[2];
        if (vDamage[12] > 0)
            vDamage[12] = pTarget->DoDamageReduction(pSource, vDamage[12], damagePower, false, false);

        auto *pEffect = new CGameEffect(true);
        pEffect->m_nType = 38;
        pEffect->SetCreator(oidSource);
        pEffect->SetNumIntegers(MAX_DAMAGE_TYPES + 7);
        for (int k = 0; k < 3; k++)
            pEffect->SetInteger(k, -1);
        for (int k = 3; k < MAX_DAMAGE_TYPES; k++)
            pEffect->SetInteger(k, positive[k] ? vDamage[k] : -1);
        pEffect->SetInteger(MAX_DAMAGE_TYPES + 1,1000); // Animation Time
        pEffect->SetInteger(MAX_DAMAGE_TYPES + 4, true); // Combat damage
        pEffect->SetInteger(MAX_DAMAGE_TYPES + 5, !!rangedDamage); //Check if ranged (this sets bRangedAttack internally)

        pTarget->ApplyEffect(pEffect, false, true);
    }

    return {};
}

int32_t Log2Int(int32_t nNumber)
{
    auto result = -1;
    while (nNumber != 0)
    {
        result++;
        nNumber = nNumber >> 1;
    }

    return result;
}

BOOL CheckAlignment(CNWSCreature* pCreature, int32_t nAlignment, BOOL bCheckGroup = false)
{
    auto nAlignGE = pCreature->m_pStats->GetSimpleAlignmentGoodEvil();
    auto nAlignLC = pCreature->m_pStats->GetSimpleAlignmentLawChaos();
    if (bCheckGroup)
        return (nAlignment == nAlignGE) || (nAlignment == nAlignLC);
    else
    {
        switch(nAlignment)
        {
            case 0: return (nAlignGE == Constants::Alignment::Good) && (nAlignLC == Constants::Alignment::Lawful);
            case 1: return (nAlignGE == Constants::Alignment::Neutral) && (nAlignLC == Constants::Alignment::Lawful);
            case 2: return (nAlignGE == Constants::Alignment::Evil) && (nAlignLC == Constants::Alignment::Lawful);
            case 3: return (nAlignGE == Constants::Alignment::Good) && (nAlignLC == Constants::Alignment::Neutral);
            case 4: return (nAlignGE == Constants::Alignment::Neutral) && (nAlignLC == Constants::Alignment::Neutral);
            case 5: return (nAlignGE == Constants::Alignment::Evil) && (nAlignLC == Constants::Alignment::Neutral);
            case 6: return (nAlignGE == Constants::Alignment::Good) && (nAlignLC == Constants::Alignment::Chaotic);
            case 7: return (nAlignGE == Constants::Alignment::Neutral) && (nAlignLC == Constants::Alignment::Chaotic);
            case 8: return (nAlignGE == Constants::Alignment::Evil) && (nAlignLC == Constants::Alignment::Chaotic);
        }
    }

    return false;
}

int32_t GetUnarmedWeaponPower(CNWSCreature* pCreature, CNWSItem* pGloves)
{
    auto result = 0;

    auto nMaxKiStrikeFeat = pCreature->m_pStats->GetHighestLevelOfFeat(Constants::Feat::EpicImprovedKiStrike4);
    if (nMaxKiStrikeFeat < 0xFFFF)
        result = nMaxKiStrikeFeat - Constants::Feat::EpicImprovedKiStrike4 + 4;
    else 
    {
        nMaxKiStrikeFeat = pCreature->m_pStats->GetHighestLevelOfFeat(Constants::Feat::KiStrike);
        if (nMaxKiStrikeFeat == Constants::Feat::KiStrike)
            result = 1;
        else if (nMaxKiStrikeFeat < 0xFFFF)
            result = nMaxKiStrikeFeat - Constants::Feat::KiStrike2 + 2;
    }

    CNWItemProperty* pAttackBonusProperty = nullptr;
    if ((pGloves) && (pGloves->GetPropertyByType(&pAttackBonusProperty, Constants::ItemProperty::AttackBonus, 0)))
    {
        result = std::max((int32_t)pAttackBonusProperty->m_nCostTableValue, result);
    }

    return result;
}

CGameEffect* LinkEffects(CGameEffect* pEffect1, CGameEffect* pEffect2)
{
    auto *pLinked = new CGameEffect(true);
    pLinked->m_nType = Constants::EffectTrueType::Link;
    pLinked->SetDurationType(pEffect1->GetDurationType());
    pLinked->m_fDuration = std::max(pEffect1->m_fDuration, pEffect2->m_fDuration);
    pLinked->SetCreator(pEffect1->m_oidCreator);             
    pLinked->SetLinked(pEffect1, pEffect2);

    return pLinked;
}

void CastOnHitSpell(CNWSCreature* pCaster, CNWSObject* pTarget, int32_t nSpellID, int32_t nCasterLevel)
{
    // Ignores projectile delay stuff because we don't know which spell is being cast and if there are any projectiles and which travel time those projectiles have
    // Makes it so that CastOnHit does not work perfectly for every spell. 

    auto* pSpell = Globals::Rules()->m_pSpellArray->GetSpell(nSpellID);

    auto* pSpellScriptData = new CNWSSpellScriptData;
    pSpellScriptData->m_nSpellId = nSpellID;
    pSpellScriptData->m_nFeatId = 0xFFFF;
    pSpellScriptData->m_oidCaster = pCaster->m_idSelf;
    pSpellScriptData->m_oidTarget = pTarget->m_idSelf;
    pSpellScriptData->m_oidItem = Constants::OBJECT_INVALID;
    pSpellScriptData->m_vTargetPosition = pTarget->m_vPosition;
    pSpellScriptData->m_sScript = pSpell->m_sImpactScript;
    pSpellScriptData->m_oidArea = pCaster->m_oidArea;
    pSpellScriptData->m_nItemCastLevel = nCasterLevel;

    Globals::AppManager()->m_pServerExoApp->GetServerAIMaster()->AddEventDeltaTime(0, 0, pCaster->m_idSelf, pCaster->m_idSelf, Constants::AIMasterEvent::ItemOnHitSpellImpact, (void*)pSpellScriptData);
}

void ApplyStateEffect(CNWSCreature* pEffectSource, CNWSObject* pTarget, int32_t nVfxEffect, int32_t nVfxDurationType, int32_t nState, float fDuration, int nEffectInt = -1, BOOL bSupernatural = false)
{
    auto *pOnHitEffect = new CGameEffect(true);
    pOnHitEffect->m_nType = Constants::EffectTrueType::SetState;
    pOnHitEffect->SetDurationType(Constants::EffectDurationType::Temporary);
    pOnHitEffect->m_fDuration = fDuration;
    pOnHitEffect->SetCreator(pEffectSource->m_idSelf);
    pOnHitEffect->SetNumIntegers(1 + (nEffectInt != -1));
    pOnHitEffect->SetInteger(0, nState);
    if (nEffectInt != -1)
        pOnHitEffect->SetInteger(1, nEffectInt);

    auto pCessate = new CGameEffect(true);
    pCessate->m_nType = Constants::EffectTrueType::VisualEffect;
    pCessate->SetDurationType(Constants::EffectDurationType::Temporary);
    pCessate->m_fDuration = fDuration;
    pCessate->SetCreator(pEffectSource->m_idSelf);
    pCessate->SetNumIntegers(3);
    pCessate->SetInteger(0, 207); // VFX_DUR_CESSATE_NEGATIVE
    pCessate->SetInteger(1, 0);
    pCessate->SetInteger(2, 0);
    
    auto* pVis = new CGameEffect(true);
    pVis->m_nType = Constants::EffectTrueType::VisualEffect;
    pVis->SetDurationType(nVfxDurationType);
    if (nVfxDurationType == Constants::EffectDurationType::Temporary)
        pVis->m_fDuration = fDuration;
    pVis->SetCreator(pEffectSource->m_idSelf);
    pVis->SetNumIntegers(3);
    pVis->SetInteger(0, nVfxEffect);
    pVis->SetInteger(1, 0);
    pVis->SetInteger(2, 0);

    auto* pLink = LinkEffects(pOnHitEffect, pCessate);
    if (nVfxDurationType == Constants::EffectDurationType::Temporary)
        pLink = LinkEffects(pLink, pVis);
    else
        pTarget->ApplyEffect(pVis, false, true);

    if (bSupernatural) pLink->SetSubType_Supernatural();
    pTarget->ApplyEffect(pLink, false, true);
}

int32_t RollDamage(int32_t nNumDice, int32_t nDice, int32_t nCritMultiplier, BOOL bRollMaxDamage)
{
    if (nNumDice == 0)
    {
        nNumDice = 1;
        bRollMaxDamage = true;
    }

    if (bRollMaxDamage)
        return (nNumDice * nCritMultiplier) * nDice;
    else
    {
        auto result = 0;
        auto nTotalDice = nNumDice * nCritMultiplier;
        while (nTotalDice > 0)
        {
            result += Globals::Rules()->RollDice(1, nDice);
            nTotalDice--;
        }

        return result;
    }
}

BOOL CheckSneakAttack(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nMode)
{
    if (!pTarget) return false;

    auto bSneak = false;
    if ((nMode) && (!pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::SneakAttack, pAttacker)) &&
        ((!pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::CriticalHit, pAttacker)) || (Config::Get<bool>("SNEAK_ATTACK_IGNORE_CRIT_IMMUNITY", false))))
    {
        bSneak = (nMode == SNEAK_MODE_DO);
        if (nMode == SNEAK_MODE_CHECK)
        {
            // Code stolen from SneakAttackCritImmunity tweak
            auto* pVisNode = pTarget->GetVisibleListElement(pAttacker->m_idSelf);
            if (!pVisNode || !pVisNode->m_bSeen || pTarget->GetFlatFooted())
            {
                bSneak = true;
            }
            else if (pAttacker->GetFlanked(pTarget))
            {
                bSneak = true;
                if (pTarget->m_pStats->HasFeat(Constants::Feat::UncannyDodge2))
                {
                    const uint8_t uncannyClasses[] =
                    {
                        Constants::ClassType::Barbarian,
                        Constants::ClassType::Rogue,
                        Constants::ClassType::Assassin,
                        Constants::ClassType::Shadowdancer
                    };
                    int nAttackerLevels = 0, nDefenderLevels = 0;

                    for (uint8_t i = 0; i < 3; i++)
                    {
                        auto nAttackerClass = pAttacker->m_pStats->GetClass(i);
                        auto nDefenderClass = pTarget->m_pStats->GetClass(i);
                        for (size_t j = 0; j < sizeof(uncannyClasses) / sizeof(uncannyClasses[0]); j++)
                        {
                            nAttackerLevels += (nAttackerClass == uncannyClasses[j]) ? pAttacker->m_pStats->GetClassLevel(i, false) : 0;
                            nDefenderLevels += (nDefenderClass == uncannyClasses[j]) ? pTarget->m_pStats->GetClassLevel(i, false) : 0;
                        }
                    }

                    bSneak = nAttackerLevels - nDefenderLevels >= Globals::Rules()->GetRulesetIntEntry("FLANK_LEVEL_RANGE", 4);
                }
            }
        }
    }

    return bSneak;
}

BOOL CheckCrit(CNWSCreature* pAttacker, CNWSObject* pTarget, int32_t nMode, BOOL bOffhand)
{
    auto* pTargetCreature = Utils::AsNWSCreature(pTarget);

    auto bCrit = false;
    if ((nMode) && ((!pTargetCreature) || (!pTargetCreature->m_pStats->GetEffectImmunity(Constants::ImmunityType::CriticalHit, pAttacker))))
    {
        bCrit = (nMode == CRIT_MODE_CRIT);
        if (nMode == CRIT_MODE_ROLL)
        {
            auto nBaseAttackBonus = pAttacker->m_pStats->GetBaseAttackBonus(false);
            auto nMeleeAttackBonus = pAttacker->m_pStats->GetMeleeAttackBonus(bOffhand, false, false);
            auto nEffectAttackBonus = pAttacker->GetTotalEffectBonus(1, pTarget, false, false, 0, 0, 0xff, 0xff, bOffhand);
            auto nTotalAttackBonus = nBaseAttackBonus + nMeleeAttackBonus + nEffectAttackBonus;

            auto nCritRange = pAttacker->m_pStats->GetCriticalHitRoll(bOffhand);
            
            auto nTargetAC = 0;
            if (pTargetCreature)
                nTargetAC = pTargetCreature->m_pStats->GetArmorClassVersus(pAttacker, false);

            auto nAttackRoll = Globals::Rules()->RollDice(1, 20);
            if (((nAttackRoll == 20) || (nAttackRoll + nTotalAttackBonus >= nTargetAC)) && (nAttackRoll >= nCritRange))
            {
                auto nThreatRoll = Globals::Rules()->RollDice(1, 20);
                bCrit = (nThreatRoll + nTotalAttackBonus) >= nTargetAC;
            }
        }
    }

    return bCrit;
}

CNWSItem* GetAttackWeapon(CNWSCreature* pAttacker, BOOL bOffhand)
{
    CNWSItem* pWeapon = nullptr;
    if (pAttacker->GetUnarmed())
        pWeapon = pAttacker->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::Arms);
    else if (bOffhand)
        pWeapon = pAttacker->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::LeftHand);
    else
        pWeapon = pAttacker->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);

    // Check if actually a weapon
    if (pWeapon)
    {
        auto pWeaponBase = Globals::Rules()->m_pBaseItemArray->GetBaseItem(pWeapon->m_nBaseItem);
        if (!pWeaponBase->m_nWeaponType)
            pWeapon = nullptr;
    }

    return pWeapon;
}

int32_t GetSneakAttackDiceNum(CNWSCreature* pCreature)
{
    int32_t result = 0;

    // Sneak Attack
    auto nSneakAttack11PlusFeat = pCreature->m_pStats->GetHighestLevelOfFeat(Constants::Feat::SneakAttack11);
    if (nSneakAttack11PlusFeat < 0xFFFF)
        result += (nSneakAttack11PlusFeat - Constants::Feat::SneakAttack11) + 11;
    else
    {
        auto nSneakAttack2PlusFeat = pCreature->m_pStats->GetHighestLevelOfFeat(Constants::Feat::SneakAttack2);
        if (nSneakAttack2PlusFeat < 0xFFFF)
            result += (nSneakAttack2PlusFeat - Constants::Feat::SneakAttack2) + 2;
        else
            result += (pCreature->m_pStats->GetHighestLevelOfFeat(Constants::Feat::SneakAttack) != 0xFFFF);
    }

    // DeathAttack (is buggy with GetHighestLevelOfFeat):
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack20)) result += 20; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack19)) result += 19; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack18)) result += 18; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack17)) result += 17; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack16)) result += 16; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack15)) result += 15; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack14)) result += 14; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack13)) result += 13; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack12)) result += 12; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack11)) result += 11; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack10)) result += 10; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack9)) result += 9; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack8)) result += 8; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack7)) result += 7; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack6)) result += 6; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack5)) result += 5; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack4)) result += 4; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack3)) result += 3; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack2)) result += 2; else 
    if (pCreature->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack1)) result += 1;

    // Blackguard sneak attack
    auto nBlackguardSneakAttack4PlusFeat = pCreature->m_pStats->GetHighestLevelOfFeat(Constants::Feat::BlackguardSneakAttack4d6);
    if (nBlackguardSneakAttack4PlusFeat < 0xFFFF)
        result += (nBlackguardSneakAttack4PlusFeat - Constants::Feat::BlackguardSneakAttack4d6) + 4;
    else
    {
        auto nBlackguardSneakAttack1PlusFeat = pCreature->m_pStats->GetHighestLevelOfFeat(Constants::Feat::BlackguardSneakAttack1d6);
        if (nBlackguardSneakAttack1PlusFeat < 0xFFFF)
            result += (nBlackguardSneakAttack1PlusFeat - Constants::Feat::BlackguardSneakAttack1d6) + 1;
    }

    // Improved sneak attack
    auto nImprovedSneakAttack1PlusFeat = pCreature->m_pStats->GetHighestLevelOfFeat(Constants::Feat::EpicImprovedSneakAttack1);
    if (nImprovedSneakAttack1PlusFeat < 0xFFFF)
        result += (nImprovedSneakAttack1PlusFeat - Constants::Feat::EpicImprovedSneakAttack1) + 1;

    return result;
}

void ApplyPhysicalWeaponDamage(CNWSCreature* pAttacker, CNWSItem* pWeapon, CNWSObject* pTarget, BOOL bCrit, BOOL bSneak, int32_t nCritMultiplier, BOOL bRollMaxDamage, C2DA* damageCost2DA, int32_t vDamage[MAX_DAMAGE_TYPES])
{
    auto pWeaponBase = pWeapon ? Globals::Rules()->m_pBaseItemArray->GetBaseItem(pWeapon->m_nBaseItem) : nullptr;

    // Base damage
    auto nPhysDamage = 0;
    if (pAttacker->GetUnarmed())
        nPhysDamage += RollDamage(pAttacker->m_pStats->GetUnarmedDamageDice(), pAttacker->m_pStats->GetUnarmedDamageDie(), nCritMultiplier, bRollMaxDamage);
    else if (pWeapon)
        nPhysDamage += RollDamage(pWeaponBase->m_nNumDice, pWeaponBase->m_nDieToRoll, nCritMultiplier, bRollMaxDamage);
    
    // Bonus damage
    nPhysDamage += pAttacker->GetTotalEffectBonus(2, pTarget) * nCritMultiplier; // NWNX_CREATURE_BONUS_TYPE_DAMAGE
    nPhysDamage += pAttacker->m_pStats->GetAbilityMod(Constants::Ability::Strength) * nCritMultiplier;

    // Crit damage
    if (bCrit)
    {
        CNWItemProperty* pMassiveProperty;
        if ((pWeapon) && (pWeapon->GetPropertyByType(&pMassiveProperty, Constants::ItemProperty::MassiveCriticals, 0)))
        {
            int32_t nDamageNumDice;
            int32_t nDamageDie;
            damageCost2DA->GetINTEntry(pMassiveProperty->m_nCostTableValue, "NumDice", &nDamageNumDice);
            damageCost2DA->GetINTEntry(pMassiveProperty->m_nCostTableValue, "Die", &nDamageDie);

            nPhysDamage += RollDamage(nDamageNumDice, nDamageDie, 1, bRollMaxDamage);
        }

        if (pAttacker->m_pStats->GetEpicWeaponOverwhelmingCritical(pWeapon))
        {
            nPhysDamage += RollDamage(1, 6, nCritMultiplier, bRollMaxDamage);
        }
    }

    // Sneak damage
    if (bSneak)
    {
        auto nSneakDiceNum = GetSneakAttackDiceNum(pAttacker);
        nPhysDamage += RollDamage(nSneakDiceNum, 6, 1, bRollMaxDamage);
    }

    // Set physical damage types
    if (pAttacker->GetUnarmed())
    {
        vDamage[0] = nPhysDamage; // Unarmed damage is Bludgeoning damage
    }
    else
    {
        if ((pWeaponBase->m_nWeaponType == 2) || (pWeaponBase->m_nWeaponType == 5) || (pWeapon->GetPropertyByTypeExists(Constants::ItemProperty::ExtraMeleeDamageType, 0))) // Bludgeoning
            vDamage[0] = nPhysDamage;
        if ((pWeaponBase->m_nWeaponType == 1) || (pWeaponBase->m_nWeaponType == 5) || (pWeapon->GetPropertyByTypeExists(Constants::ItemProperty::ExtraMeleeDamageType, 1))) // Piercing
            vDamage[1] = nPhysDamage;
        if ((pWeaponBase->m_nWeaponType == 3) || (pWeaponBase->m_nWeaponType == 4) || (pWeapon->GetPropertyByTypeExists(Constants::ItemProperty::ExtraMeleeDamageType, 2))) // Slashing
            vDamage[2] = nPhysDamage;
    }
}

void ApplyElementalWeaponDamage(CNWSItem* pWeapon, CNWSCreature* pTarget, int32_t nCritMultiplier, BOOL bRollMaxDamage, C2DA* damageCost2DA, int32_t vDamage[MAX_DAMAGE_TYPES])
{
    if (!pWeapon) return;

    int32_t vDamageRanks[MAX_DAMAGE_TYPES];
    memset(vDamageRanks, 0, sizeof(vDamageRanks));

    int32_t nDamageRank;
    int32_t nDamageDie;
    int32_t nDamageNumDice;
    for (int i = 0; i < pWeapon->m_lstPassiveProperties.num; i++)
    {
        auto pProp = pWeapon->GetPassiveProperty(i);
        if ((pProp->m_nPropertyName == Constants::ItemProperty::DamageBonus) ||
            ((pProp->m_nPropertyName == Constants::ItemProperty::DamageBonusVSAlignmentGroup) && (pTarget != nullptr) && ((pTarget->m_pStats->GetSimpleAlignmentLawChaos() == pProp->m_nSubType) || (pTarget->m_pStats->GetSimpleAlignmentGoodEvil() == pProp->m_nSubType))) || 
            ((pProp->m_nPropertyName == Constants::ItemProperty::DamageBonusVSRacialGroup) && (pTarget != nullptr) && (pTarget->m_pStats->m_nRace == pProp->m_nSubType)) || 
            ((pProp->m_nPropertyName == Constants::ItemProperty::DamageBonusVSSpecificAlignment) && (pTarget != nullptr) && (CheckAlignment(pTarget, pProp->m_nSubType))))
        {
            auto nDamageTypeIndex = pProp->m_nParam1Value - 2;  
            if (pProp->m_nPropertyName == Constants::ItemProperty::DamageBonus)
                nDamageTypeIndex = pProp->m_nSubType - 2;

            if ((nDamageTypeIndex > 2) && (nDamageTypeIndex != 12)) // Skip physical damage
            {
                auto nDamageCostValue = pProp->m_nCostTableValue;
                damageCost2DA->GetINTEntry(nDamageCostValue, "Rank", &nDamageRank);
                if (nDamageRank > vDamageRanks[nDamageTypeIndex])
                {
                    damageCost2DA->GetINTEntry(nDamageCostValue, "NumDice", &nDamageNumDice);
                    damageCost2DA->GetINTEntry(nDamageCostValue, "Die", &nDamageDie);

                    vDamage[nDamageTypeIndex] = RollDamage(nDamageNumDice, nDamageDie, nCritMultiplier, bRollMaxDamage);
                    vDamageRanks[nDamageTypeIndex] = nDamageRank;
                }
            }
        }
    }
}

void AddElementalDamageModifiers(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nCritMultiplier, BOOL bRollMaxDamage, C2DA* damageCost2DA, int32_t vDamage[MAX_DAMAGE_TYPES], int32_t nModifierType)
{
    int32_t nDamageRank;
    int32_t nDamageDie;
    int32_t nDamageNumDice;
    std::unordered_map<int32_t, int32_t> spellDamageTypeRanks;
    for (auto* pEffect : pAttacker->m_appliedEffects)
    {
        auto nEffectRace = pEffect->GetInteger(2);
        auto nEffectAlignLC = pEffect->GetInteger(3);
        auto nEffectAlignGE = pEffect->GetInteger(4);

        if (
            (pEffect->m_nType == nModifierType) && 
            (pEffect->m_nItemPropertySourceId == 0) && // Non-Itemproperty effects
            ((nEffectRace == Constants::RacialType::Invalid) || ((pTarget != nullptr) && (pTarget->m_pStats->m_nRace == nEffectRace))) &&
            ((nEffectAlignLC == Constants::Alignment::All) || ((pTarget != nullptr) && (pTarget->m_pStats->GetSimpleAlignmentLawChaos() == nEffectAlignLC))) &&
            ((nEffectAlignGE == Constants::Alignment::All) || ((pTarget != nullptr) && (pTarget->m_pStats->GetSimpleAlignmentGoodEvil() == nEffectAlignGE)))
            )
        {
            auto nDamageCostValue = pEffect->GetInteger(0);
            auto nDamageTypeIndex = Log2Int(pEffect->GetInteger(1));
            
            if ((nDamageTypeIndex > 2) && (nDamageTypeIndex != 12)) // Skip physical damage
            {
                auto nSpellEffectIndex = (pEffect->m_nSpellId << 5) | nDamageTypeIndex;
                damageCost2DA->GetINTEntry(nDamageCostValue, "Rank", &nDamageRank);

                if ((pEffect->m_nSpellId == 0xFFFFFFFF) || (!spellDamageTypeRanks.count(nSpellEffectIndex)) || (spellDamageTypeRanks[nSpellEffectIndex] < nDamageRank))
                {
                    damageCost2DA->GetINTEntry(nDamageCostValue, "NumDice", &nDamageNumDice);
                    damageCost2DA->GetINTEntry(nDamageCostValue, "Die", &nDamageDie);
                    
                    auto nDamageRoll = RollDamage(nDamageNumDice, nDamageDie, nCritMultiplier, bRollMaxDamage);

                    if (nModifierType == Constants::EffectTrueType::DamageIncrease)
                        vDamage[nDamageTypeIndex] += nDamageRoll + (vDamage[nDamageTypeIndex] < 0);
                    else
                        vDamage[nDamageTypeIndex] = std::max(vDamage[nDamageTypeIndex] - nDamageRoll, 0);

                    if (pEffect->m_nSpellId != 0xFFFFFFFF) 
                        spellDamageTypeRanks[nSpellEffectIndex] = nDamageRank;
                }
            }
        }
    }
}

void ApplyOnHitSleep(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nTriggerChance, int32_t nDC, int32_t nDuration)
{
    if (!pTarget) return;

    auto bDoesTrigger = Globals::Rules()->RollDice(1, 100) <= nTriggerChance;
    if ((bDoesTrigger) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::MindSpells, pAttacker) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Sleep, pAttacker))
    {
        if (!pTarget->SavingThrowRoll(Constants::SavingThrow::Will, nDC, Constants::SavingThrowType::MindSpells, pAttacker->m_idSelf))
            ApplyStateEffect(pAttacker, pTarget, 94, Constants::EffectDurationType::Instant, 9, nDuration, 1);
    }
}

void ApplyOnHitStun(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nTriggerChance, int32_t nDC, int32_t nDuration)
{
    if (!pTarget) return;

    auto bDoesTrigger = Globals::Rules()->RollDice(1, 100) <= nTriggerChance;
    if ((bDoesTrigger) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::MindSpells, pAttacker) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Stun, pAttacker))
    {
        if (!pTarget->SavingThrowRoll(Constants::SavingThrow::Will, nDC, Constants::SavingThrowType::MindSpells, pAttacker->m_idSelf))
            ApplyStateEffect(pAttacker, pTarget, 208, Constants::EffectDurationType::Temporary, 6, nDuration, 0); // CREATURE_STATE_HELD?, VFX_DUR_MIND_AFFECTING_DISABLED 
    }
}

void ApplyOnHitHold(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nTriggerChance, int32_t nDC, int32_t nDuration)
{
    if (!pTarget) return;

    auto bDoesTrigger = Globals::Rules()->RollDice(1, 100) <= nTriggerChance;
    if ((bDoesTrigger) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::MindSpells, pAttacker) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Paralysis, pAttacker))
    {
        if (!pTarget->SavingThrowRoll(Constants::SavingThrow::Will, nDC, Constants::SavingThrowType::None, pAttacker->m_idSelf))
            ApplyStateEffect(pAttacker, pTarget, 82, Constants::EffectDurationType::Temporary, 8, nDuration, 0); // CREATURE_STATE_HELD, VFX_DUR_PARALYZE_HOLD
    }
}

void ApplyOnHitConfusion(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nTriggerChance, int32_t nDC, int32_t nDuration)
{
    if (!pTarget) return;

    auto bDoesTrigger = Globals::Rules()->RollDice(1, 100) <= nTriggerChance;
    if ((bDoesTrigger) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::MindSpells, pAttacker) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Confused, pAttacker))
    {
        if (!pTarget->SavingThrowRoll(Constants::SavingThrow::Will, nDC, Constants::SavingThrowType::MindSpells, pAttacker->m_idSelf))
            ApplyStateEffect(pAttacker, pTarget, 48, Constants::EffectDurationType::Instant, 2, nDuration); // CREATURE_STATE_CONFUSED, VFX_IMP_CONFUSION_S
    }
}

void ApplyOnHitDaze(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nTriggerChance, int32_t nDC, int32_t nDuration)
{
    if (!pTarget) return;

    auto bDoesTrigger = Globals::Rules()->RollDice(1, 100) <= nTriggerChance;
    if ((bDoesTrigger) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::MindSpells, pAttacker) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Dazed, pAttacker))
    {
        if (!pTarget->SavingThrowRoll(Constants::SavingThrow::Will, nDC, Constants::SavingThrowType::MindSpells, pAttacker->m_idSelf))
            ApplyStateEffect(pAttacker, pTarget, 49, Constants::EffectDurationType::Instant, 5, nDuration); // CREATURE_STATE_DAZED, VFX_IMP_DAZED_S
    }
}

void ApplyOnHitDoom(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nTriggerChance, int32_t nDC, int32_t nDuration)
{
    if (!pTarget) return;

    auto bDoesTrigger = Globals::Rules()->RollDice(1, 100) <= nTriggerChance;
    if ((bDoesTrigger) && !pTarget->SavingThrowRoll(Constants::SavingThrow::Will, nDC, Constants::SavingThrowType::None, pAttacker->m_idSelf))
    {
        auto *pSaveDecrease = new CGameEffect(true);
        pSaveDecrease->m_nType = Constants::EffectTrueType::SavingThrowDecrease;
        pSaveDecrease->SetDurationType(Constants::EffectDurationType::Temporary);
        pSaveDecrease->m_fDuration = nDuration;
        pSaveDecrease->SetCreator(pAttacker->m_idSelf);
        pSaveDecrease->SetNumIntegers(6);
        pSaveDecrease->SetInteger(0, 2); // -2
        pSaveDecrease->SetInteger(1, 0); // SAVING_THROW_ALL
        pSaveDecrease->SetInteger(2, 0); // SAVING_THROW_TYPE_ALL
        pSaveDecrease->SetInteger(3, Constants::RacialType::Invalid);
        pSaveDecrease->SetInteger(4, 0);
        pSaveDecrease->SetInteger(5, 0);

        auto *pAttackDecrease = new CGameEffect(true);
        pAttackDecrease->m_nType = Constants::EffectTrueType::AttackDecrease;
        pAttackDecrease->SetDurationType(Constants::EffectDurationType::Temporary);
        pAttackDecrease->m_fDuration = nDuration;
        pAttackDecrease->SetCreator(pAttacker->m_idSelf);
        pAttackDecrease->SetNumIntegers(5);
        pAttackDecrease->SetInteger(0, 2); // -2
        pAttackDecrease->SetInteger(1, 0); // ATTACK_BONUS_MISC 
        pAttackDecrease->SetInteger(2, Constants::RacialType::Invalid); 
        pAttackDecrease->SetInteger(3, 0);
        pAttackDecrease->SetInteger(4, 0);

        auto *pDamageDecrease = new CGameEffect(true);
        pDamageDecrease->m_nType = Constants::EffectTrueType::DamageDecrease;
        pDamageDecrease->SetDurationType(Constants::EffectDurationType::Temporary);
        pDamageDecrease->m_fDuration = nDuration;
        pDamageDecrease->SetCreator(pAttacker->m_idSelf);
        pDamageDecrease->SetNumIntegers(5);
        pDamageDecrease->SetInteger(0, 2); // -2
        pDamageDecrease->SetInteger(1, 8); // DAMAGE_TYPE_MAGICAL 
        pDamageDecrease->SetInteger(2, Constants::RacialType::Invalid); 
        pDamageDecrease->SetInteger(3, 0);
        pDamageDecrease->SetInteger(4, 0);

        auto *pSkillDecrease = new CGameEffect(true);
        pSkillDecrease->m_nType = Constants::EffectTrueType::SkillDecrease;
        pSkillDecrease->SetDurationType(Constants::EffectDurationType::Temporary);
        pSkillDecrease->m_fDuration = nDuration;
        pSkillDecrease->SetCreator(pAttacker->m_idSelf);
        pSkillDecrease->SetNumIntegers(6);
        pSkillDecrease->SetInteger(0, 255); // SKILL_ALL_SKILLS
        pSkillDecrease->SetInteger(1, 2);  
        pSkillDecrease->SetInteger(2, Constants::RacialType::Invalid); 
        pSkillDecrease->SetInteger(3, 0);
        pSkillDecrease->SetInteger(4, 0);
        pSkillDecrease->SetInteger(5, 0);

        auto* pCessate = new CGameEffect(true);
        pCessate->m_nType = Constants::EffectTrueType::VisualEffect;
        pCessate->SetDurationType(Constants::EffectDurationType::Temporary);
        pCessate->m_fDuration = nDuration;
        pCessate->SetCreator(pAttacker->m_idSelf);
        pCessate->SetNumIntegers(3);
        pCessate->SetInteger(0, 207); // VFX_DUR_CESSATE_NEGATIVE
        pCessate->SetInteger(1, 0);
        pCessate->SetInteger(2, 0);

        auto* pLink = LinkEffects(pAttackDecrease,  pDamageDecrease);
        pLink = LinkEffects(pLink, pSaveDecrease);
        pLink = LinkEffects(pLink, pSkillDecrease);
        pLink = LinkEffects(pLink, pCessate);

        auto pVis = new CGameEffect(true);
        pVis->m_nType = Constants::EffectTrueType::VisualEffect;
        pVis->SetDurationType(Constants::EffectDurationType::Instant);
        pVis->SetCreator(pAttacker->m_idSelf);
        pVis->SetNumIntegers(3);
        pVis->SetInteger(0, 57); // VFX_IMP_DOOM
        pVis->SetInteger(1, 0);
        pVis->SetInteger(2, 0);

        pTarget->ApplyEffect(pLink, false, true);
        pTarget->ApplyEffect(pVis, false, true);
    }
}

void ApplyOnHitFear(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nTriggerChance, int32_t nDC, int32_t nDuration)
{
    if (!pTarget) return;

    auto bDoesTrigger = Globals::Rules()->RollDice(1, 100) <= nTriggerChance;
    if ((bDoesTrigger) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::MindSpells, pAttacker) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Fear, pAttacker))
    {
        if (!pTarget->SavingThrowRoll(Constants::SavingThrow::Will, nDC, Constants::SavingThrowType::Fear, pAttacker->m_idSelf))
            ApplyStateEffect(pAttacker, pTarget, 218, Constants::EffectDurationType::Temporary, 3, nDuration); // CREATURE_STATE_FRIGHTENED , VFX_DUR_MIND_AFFECTING_FEAR
    }
}

void ApplyOnHitKnock(CNWSCreature* pAttacker, CNWSPlaceable* pTarget, int32_t nDC)
{
    if ((pTarget->m_bLocked) && (pTarget->m_nOpenLockDC <= nDC))
    {
        CastOnHitSpell(pAttacker, pTarget, 93, 1);
    }
}

void ApplyOnHitSlow(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nTriggerChance, int32_t nDC, int32_t nDuration)
{
    if (!pTarget) return;

    auto bDoesTrigger = Globals::Rules()->RollDice(1, 100) <= nTriggerChance;
    if ((bDoesTrigger) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Slow, pAttacker))
    {
        if (!pTarget->SavingThrowRoll(Constants::SavingThrow::Will, nDC, Constants::SavingThrowType::None, pAttacker->m_idSelf))
        {
            auto *pSlow = new CGameEffect(true);
            pSlow->m_nType = Constants::EffectTrueType::Slow;
            pSlow->SetDurationType(Constants::EffectDurationType::Temporary);
            pSlow->m_fDuration = nDuration;
            pSlow->SetCreator(pAttacker->m_idSelf);

            auto* pVis = new CGameEffect(true);
            pVis->m_nType = Constants::EffectTrueType::VisualEffect;
            pVis->SetDurationType(Constants::EffectDurationType::Instant);
            pVis->SetCreator(pAttacker->m_idSelf);
            pVis->SetNumIntegers(3);
            pVis->SetInteger(0, 95); // VFX_IMP_SLOW
            pVis->SetInteger(1, 0);
            pVis->SetInteger(2, 0);

            pTarget->ApplyEffect(pSlow, false, true);
            pTarget->ApplyEffect(pVis, false, true);
        }
    }
}

void ApplyOnHitSilence(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nTriggerChance, int32_t nDC, int32_t nDuration)
{
    if (!pTarget) return;

    auto bDoesTrigger = Globals::Rules()->RollDice(1, 100) <= nTriggerChance;
    if ((bDoesTrigger) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Silence, pAttacker))
    {
        if (!pTarget->SavingThrowRoll(Constants::SavingThrow::Will, nDC, Constants::SavingThrowType::None, pAttacker->m_idSelf))
        {
            auto *pSilence = new CGameEffect(true);
            pSilence->m_nType = Constants::EffectTrueType::Silence;
            pSilence->SetDurationType(Constants::EffectDurationType::Temporary);
            pSilence->m_fDuration = nDuration;
            pSilence->SetCreator(pAttacker->m_idSelf);

            auto* pCessate = new CGameEffect(true);
            pCessate->m_nType = Constants::EffectTrueType::VisualEffect;
            pCessate->SetDurationType(Constants::EffectDurationType::Temporary);
            pCessate->m_fDuration = nDuration;
            pCessate->SetCreator(pAttacker->m_idSelf);
            pCessate->SetNumIntegers(3);
            pCessate->SetInteger(0, 207); // VFX_DUR_CESSATE_NEGATIVE
            pCessate->SetInteger(1, 0);
            pCessate->SetInteger(2, 0);

            auto pVis = new CGameEffect(true);
            pVis->m_nType = Constants::EffectTrueType::VisualEffect;
            pVis->SetDurationType(Constants::EffectDurationType::Instant);
            pVis->SetCreator(pAttacker->m_idSelf);
            pVis->SetNumIntegers(3);
            pVis->SetInteger(0, 93); // VFX_IMP_SILENCE
            pVis->SetInteger(1, 0);
            pVis->SetInteger(2, 0);

            auto* pLink = LinkEffects(pSilence, pCessate);
            pTarget->ApplyEffect(pLink, false, true);
            pTarget->ApplyEffect(pVis, false, true);
        }
    }
}

void ApplyOnHitDeafness(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nTriggerChance, int32_t nDC, int32_t nDuration)
{
    if (!pTarget) return;

    auto bDoesTrigger = Globals::Rules()->RollDice(1, 100) <= nTriggerChance;
    if ((bDoesTrigger) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Deafness, pAttacker))
    {
        if (!pTarget->SavingThrowRoll(Constants::SavingThrow::Fortitude, nDC, Constants::SavingThrowType::None, pAttacker->m_idSelf))
        {
            auto *pDeafness = new CGameEffect(true);
            pDeafness->m_nType = Constants::EffectTrueType::Deaf;
            pDeafness->SetDurationType(Constants::EffectDurationType::Temporary);
            pDeafness->m_fDuration = nDuration;
            pDeafness->SetCreator(pAttacker->m_idSelf);

            auto pCessate = new CGameEffect(true);
            pCessate->m_nType = Constants::EffectTrueType::VisualEffect;
            pCessate->SetDurationType(Constants::EffectDurationType::Temporary);
            pCessate->m_fDuration = nDuration;
            pCessate->SetCreator(pAttacker->m_idSelf);
            pCessate->SetNumIntegers(3);
            pCessate->SetInteger(0, 207); // VFX_DUR_CESSATE_NEGATIVE
            pCessate->SetInteger(1, 0);
            pCessate->SetInteger(2, 0);

            auto* pVis = new CGameEffect(true);
            pVis->m_nType = Constants::EffectTrueType::VisualEffect;
            pVis->SetDurationType(Constants::EffectDurationType::Instant);
            pVis->SetCreator(pAttacker->m_idSelf);
            pVis->SetNumIntegers(3);
            pVis->SetInteger(0, 46); // VFX_IMP_BLIND_DEAF_M
            pVis->SetInteger(1, 0);
            pVis->SetInteger(2, 0);

            auto* pLink = LinkEffects(pDeafness, pCessate);
            pTarget->ApplyEffect(pLink, false, true);
            pTarget->ApplyEffect(pVis, false, true);
        }
    }
}

void ApplyOnHitBlindness(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nTriggerChance, int32_t nDC, int32_t nDuration)
{
    if (!pTarget) return;

    auto bDoesTrigger = Globals::Rules()->RollDice(1, 100) <= nTriggerChance;
    if ((bDoesTrigger) && !pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Blindness, pAttacker))
    {
        if (!pTarget->SavingThrowRoll(Constants::SavingThrow::Fortitude, nDC, Constants::SavingThrowType::None, pAttacker->m_idSelf))
        {
            auto *pBlindness = new CGameEffect(true);
            pBlindness->m_nType = Constants::EffectTrueType::Blindness;
            pBlindness->SetDurationType(Constants::EffectDurationType::Temporary);
            pBlindness->m_fDuration = nDuration;
            pBlindness->SetCreator(pAttacker->m_idSelf);
            pBlindness->SetNumIntegers(1);
            pBlindness->SetInteger(0, 16); // CREATURE_VISION_TYPE_BLIND

            auto pCessate = new CGameEffect(true);
            pCessate->m_nType = Constants::EffectTrueType::VisualEffect;
            pCessate->SetDurationType(Constants::EffectDurationType::Temporary);
            pCessate->m_fDuration = nDuration;
            pCessate->SetCreator(pAttacker->m_idSelf);
            pCessate->SetNumIntegers(3);
            pCessate->SetInteger(0, 207); // VFX_DUR_CESSATE_NEGATIVE
            pCessate->SetInteger(1, 0);
            pCessate->SetInteger(2, 0);

            auto* pVis = new CGameEffect(true);
            pVis->m_nType = Constants::EffectTrueType::VisualEffect;
            pVis->SetDurationType(Constants::EffectDurationType::Instant);
            pVis->SetCreator(pAttacker->m_idSelf);
            pVis->SetNumIntegers(3);
            pVis->SetInteger(0, 46); // VFX_IMP_BLIND_DEAF_M
            pVis->SetInteger(1, 0);
            pVis->SetInteger(2, 0);            

            auto* pLink = LinkEffects(pBlindness, pCessate);
            pTarget->ApplyEffect(pLink, false, true);
            pTarget->ApplyEffect(pVis, false, true);
        }
    }
}

void ApplyOnHitLevelDrain(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nDC)
{
    if (!pTarget) return;

    if (!pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::NegativeLevel, pAttacker))
    {
        if (!pTarget->SavingThrowRoll(Constants::SavingThrow::Fortitude, nDC, Constants::SavingThrowType::Negative, pAttacker->m_idSelf))
        {
            auto *pLevelDrain = new CGameEffect(true);
            pLevelDrain->m_nType = Constants::EffectTrueType::NegativeLevel;
            pLevelDrain->SetDurationType(Constants::EffectDurationType::Permanent);
            pLevelDrain->SetCreator(pAttacker->m_idSelf);
            pLevelDrain->SetNumIntegers(2);
            pLevelDrain->SetInteger(0, 1); // -1 level
            pLevelDrain->SetInteger(1, 0); 

            auto* pVis = new CGameEffect(true);
            pVis->m_nType = Constants::EffectTrueType::VisualEffect;
            pVis->SetDurationType(Constants::EffectDurationType::Instant);
            pVis->SetCreator(pAttacker->m_idSelf);
            pVis->SetNumIntegers(3);
            pVis->SetInteger(0, 81); // VFX_IMP_NEGATIVE_ENERGY
            pVis->SetInteger(1, 0);
            pVis->SetInteger(2, 0);

            pTarget->ApplyEffect(pLevelDrain, false, true);
            pTarget->ApplyEffect(pVis, false, true);
        }
    }
}

void ApplyOnHitAbilityDrain(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nDC, int32_t nAbility)
{
    if (!pTarget) return;

    if (!pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::AbilityDecrease, pAttacker))
    {
        if (!pTarget->SavingThrowRoll(Constants::SavingThrow::Fortitude, nDC, Constants::SavingThrowType::Negative, pAttacker->m_idSelf))
        {
            auto *pAbilityDrain = new CGameEffect(true);
            pAbilityDrain->m_nType = Constants::EffectTrueType::AbilityDecrease;
            pAbilityDrain->SetDurationType(Constants::EffectDurationType::Permanent);
            pAbilityDrain->SetCreator(pAttacker->m_idSelf);
            pAbilityDrain->SetNumIntegers(2);
            pAbilityDrain->SetInteger(0, nAbility);
            pAbilityDrain->SetInteger(1, 1); 

            auto* pVis = new CGameEffect(true);
            pVis->m_nType = Constants::EffectTrueType::VisualEffect;
            pVis->SetDurationType(Constants::EffectDurationType::Instant);
            pVis->SetCreator(pAttacker->m_idSelf);
            pVis->SetNumIntegers(3);
            pVis->SetInteger(0, 91); // VFX_IMP_REDUCE_ABILITY_SCORE
            pVis->SetInteger(1, 0);
            pVis->SetInteger(2, 0);

            pTarget->ApplyEffect(pAbilityDrain, false, true);
            pTarget->ApplyEffect(pVis, false, true);
        }
    }
}

void ApplyOnHitPoison(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nDC, int32_t nAbility)
{
    if (!pTarget) return;

    if (!pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Poison, pAttacker))
    {
        auto *pPoison = new CGameEffect(true);
        pPoison->m_nType = Constants::EffectTrueType::Poison;
        pPoison->SetDurationType(Constants::EffectDurationType::Permanent);
        pPoison->SetCreator(pAttacker->m_idSelf);
        pPoison->SetNumIntegers(7);
        pPoison->SetInteger(0, -1); // Not a poison.2da poison
        pPoison->SetInteger(1, nAbility);
        pPoison->SetInteger(2, 1);
        pPoison->SetInteger(3, 2);
        pPoison->SetInteger(4, nDC);
        pPoison->SetInteger(5, 0);
        pPoison->SetInteger(6, 0);
        pTarget->ApplyEffect(pPoison, false, true);
    }
}

void ApplyOnHitDisease(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nDisease)
{
    if (!pTarget) return;

    if (!pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Disease, pAttacker))
    {
        auto *pDisease = new CGameEffect(true);
        pDisease->m_nType = Constants::EffectTrueType::Disease;
        pDisease->SetDurationType(Constants::EffectDurationType::Permanent);
        pDisease->SetCreator(pAttacker->m_idSelf);
        pDisease->SetNumIntegers(5);
        pDisease->SetInteger(0, nDisease);
        pDisease->SetInteger(1, 0);
        pDisease->SetInteger(2, 0);
        pDisease->SetInteger(3, 0);
        pDisease->SetInteger(4, 0);
        pTarget->ApplyEffect(pDisease, false, true);
    }
}

void SlayCreature(CNWSCreature* pAttacker, CNWSCreature* pTarget, BOOL bApplyVisualEffect = true)
{
    auto *pSlay = new CGameEffect(true);
    pSlay->m_nType = Constants::EffectTrueType::Death;
    pSlay->SetDurationType(Constants::EffectDurationType::Instant);
    pSlay->SetCreator(pAttacker->m_idSelf);
    pSlay->SetNumIntegers(2);
    pSlay->SetInteger(0, 0);
    pSlay->SetInteger(1, 1);
    pTarget->ApplyEffect(pSlay, false, true);

    if (bApplyVisualEffect)
    {
        auto* pVis = new CGameEffect(true);
        pVis->m_nType = Constants::EffectTrueType::VisualEffect;
        pVis->SetDurationType(Constants::EffectDurationType::Instant);
        pVis->SetCreator(pAttacker->m_idSelf);
        pVis->SetNumIntegers(3);
        pVis->SetInteger(0, 50); // VFX_IMP_DEATH
        pVis->SetInteger(1, 0);
        pVis->SetInteger(2, 0);
        pTarget->ApplyEffect(pVis, false, true);
    }
}

void ApplyOnHitSlayRacialGroup(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nDC, int32_t nRace)
{
    if (!pTarget) return;

    if ((pTarget->m_pStats->m_nRace == nRace) &&
        (!pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Death, pAttacker)) && 
        (!pTarget->SavingThrowRoll(Constants::SavingThrow::Fortitude, nDC, Constants::SavingThrowType::Death, pAttacker->m_idSelf)))
    {
        SlayCreature(pAttacker, pTarget);
    }
}

void ApplyOnHitSlayAlignmentGroup(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nDC, int32_t nAlignmentGroup)
{
    if (!pTarget) return;

    if ((CheckAlignment(pTarget, nAlignmentGroup, true)) &&
        (!pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Death, pAttacker)) && 
        (!pTarget->SavingThrowRoll(Constants::SavingThrow::Fortitude, nDC, Constants::SavingThrowType::Death, pAttacker->m_idSelf)))
    {
        SlayCreature(pAttacker, pTarget);
    }
}

void ApplyOnHitSlayAlignment(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nDC, int32_t nAlignment)
{
    if (!pTarget) return;

    if ((CheckAlignment(pTarget, nAlignment)) &&
        (!pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Death, pAttacker)) && 
        (!pTarget->SavingThrowRoll(Constants::SavingThrow::Fortitude, nDC, Constants::SavingThrowType::Death, pAttacker->m_idSelf)))
    {
        SlayCreature(pAttacker, pTarget);
    }
}

void ApplyOnHitVorpal(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nDC)
{
    if (!pTarget) return;

    if ((!pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::Death, pAttacker)) && (!pTarget->SavingThrowRoll(Constants::SavingThrow::Reflex, nDC, Constants::SavingThrowType::None, pAttacker->m_idSelf)))
    {
        auto *pVorpal = new CGameEffect(true);
        pVorpal->m_nType = Constants::EffectTrueType::Death;
        pVorpal->SetDurationType(Constants::EffectDurationType::Instant);
        pVorpal->SetCreator(pAttacker->m_idSelf);
        pVorpal->SetNumIntegers(2);
        pVorpal->SetInteger(0, 0);
        pVorpal->SetInteger(1, 1);

        pTarget->ApplyEffect(pVorpal, false, true);
    }
}

void ApplyOnHitWounding(CNWSCreature* pAttacker, CNWSCreature* pTarget, int32_t nDC)
{
    if (!pTarget) return;

    if (!pTarget->SavingThrowRoll(Constants::SavingThrow::Fortitude, nDC, Constants::SavingThrowType::None, pAttacker->m_idSelf))
    {
        auto *pWounding = new CGameEffect(true);
        pWounding->m_nType = Constants::EffectTrueType::Wounding;
        pWounding->SetDurationType(Constants::EffectDurationType::Permanent);
        pWounding->SetCreator(pAttacker->m_idSelf);
        pWounding->SetNumIntegers(1);
        pWounding->SetInteger(0, 1);

        pTarget->ApplyEffect(pWounding, false, true);
    }
}

void ApplyOnHitEffects(CNWSCreature* pAttacker, CNWSItem* pWeapon, CNWSObject* pTarget, BOOL bPhysicalDamageApplied, BOOL bCrit, int32_t nMaxOnHitSpellTriggers)
{
    if (!pWeapon) return;

    CNWSCreature* pTargetCreature = nullptr;
    if (pTarget->m_nObjectType == Constants::ObjectType::Creature)
        pTargetCreature = Utils::AsNWSCreature(pTarget);

    C2DA onHitSpell2DA("iprp_onhitspell", true);
    onHitSpell2DA.Load2DArray();

    C2DA onHitCost2DA("iprp_onhitcost", true);
    onHitCost2DA.Load2DArray();

    C2DA onHitDur2DA("iprp_onhitdur", true);
    onHitDur2DA.Load2DArray();

    auto nOnHitSpellsTriggered = 0;
    for (int i = 0; i < pWeapon->m_lstPassiveProperties.num; i++)
    {
        auto pProp = pWeapon->GetPassiveProperty(i);
        if (pProp->m_nPropertyName == Constants::ItemProperty::OnHitCastSpell)
        {
            auto nSpellID = 0;
            if ((onHitSpell2DA.GetINTEntry(pProp->m_nSubType, "SpellIndex", &nSpellID)) && ((nOnHitSpellsTriggered < nMaxOnHitSpellTriggers) || (nMaxOnHitSpellTriggers < 0)))
            {
                CastOnHitSpell(pAttacker, pTarget, nSpellID, pProp->m_nCostTableValue + 1);
                nOnHitSpellsTriggered++;
            }
        }
        else if (pProp->m_nPropertyName == Constants::ItemProperty::OnHitProperties)
        {
            auto nOnHitDC = 0;
            onHitCost2DA.GetINTEntry(pProp->m_nCostTableValue, "Value", &nOnHitDC);

            auto nOnHitChance = 0;
            onHitDur2DA.GetINTEntry(pProp->m_nParam1Value, "EffectChance", &nOnHitChance);

            auto nOnHitDuration = 0.0f;
            onHitDur2DA.GetFLOATEntry(pProp->m_nParam1Value, "DurationRounds", &nOnHitDuration);
            nOnHitDuration = nOnHitDuration * 6.0f;

            switch(pProp->m_nSubType)
            {
                case 0: // Sleep
                    ApplyOnHitSleep(pAttacker, pTargetCreature, nOnHitChance, nOnHitDC, nOnHitDuration);
                    break;
                case 1: // Stun
                    ApplyOnHitStun(pAttacker, pTargetCreature, nOnHitChance, nOnHitDC, nOnHitDuration);
                    break;
                case 2: // Hold
                    ApplyOnHitHold(pAttacker, pTargetCreature, nOnHitChance, nOnHitDC, nOnHitDuration);
                    break;
                case 3: // Confusion
                    ApplyOnHitConfusion(pAttacker, pTargetCreature, nOnHitChance, nOnHitDC, nOnHitDuration);
                    break;
                case 4: // ****
                    break;
                case 5: // Daze
                    ApplyOnHitDaze(pAttacker, pTargetCreature, nOnHitChance, nOnHitDC, nOnHitDuration);
                    break;
                case 6: // Doom
                    ApplyOnHitDoom(pAttacker, pTargetCreature, nOnHitChance, nOnHitDC, nOnHitDuration);
                    break;
                case 7: // Fear
                    ApplyOnHitFear(pAttacker, pTargetCreature, nOnHitChance, nOnHitDC, nOnHitDuration);
                    break;
                case 8: // Knock
                    if ((bPhysicalDamageApplied) && (pTarget->m_nObjectType == Constants::ObjectType::Placeable))
                    {
                        auto pPlaceable = Utils::AsNWSPlaceable(pTarget);
                        ApplyOnHitKnock(pAttacker, pPlaceable, nOnHitDC);
                    }
                    break;
                case 9: // Slow
                    ApplyOnHitSlow(pAttacker, pTargetCreature, nOnHitChance, nOnHitDC, nOnHitDuration);
                    break;
                case 10: // Lesser Dispell
                    CastOnHitSpell(pAttacker, pTarget, 94, nOnHitDC);
                    break;
                case 11: // Dispel Magic
                    CastOnHitSpell(pAttacker, pTarget, 41, nOnHitDC);
                    break;
                case 12: // Greater Dispel
                    CastOnHitSpell(pAttacker, pTarget, 67, nOnHitDC);
                    break;
                case 13: // MordsDisjunction
                    CastOnHitSpell(pAttacker, pTarget, 122, nOnHitDC);
                    break;
                case 14: // Silence
                    ApplyOnHitSilence(pAttacker, pTargetCreature, nOnHitChance, nOnHitDC, nOnHitDuration);
                    break;
                case 15: // Deafness
                    ApplyOnHitDeafness(pAttacker, pTargetCreature, nOnHitChance, nOnHitDC, nOnHitDuration);
                    break;
                case 16: // Blindness
                    ApplyOnHitBlindness(pAttacker, pTargetCreature, nOnHitChance, nOnHitDC, nOnHitDuration);
                    break;
                case 17: // Level Drain
                    ApplyOnHitLevelDrain(pAttacker, pTargetCreature, nOnHitDC);
                    break;
                case 18: // Ability Drain
                    ApplyOnHitAbilityDrain(pAttacker, pTargetCreature, nOnHitDC, pProp->m_nParam1Value);
                    break;
                case 19: // Poison
                    ApplyOnHitPoison(pAttacker, pTargetCreature, nOnHitDC, pProp->m_nParam1Value);
                    break;
                case 20: // Disease
                    ApplyOnHitDisease(pAttacker, pTargetCreature, pProp->m_nParam1Value);
                    break;
                case 21: // Slay racial group
                    ApplyOnHitSlayRacialGroup(pAttacker, pTargetCreature, nOnHitDC, pProp->m_nParam1Value);
                    break;
                case 22: // Slay alignment group
                    ApplyOnHitSlayAlignmentGroup(pAttacker, pTargetCreature, nOnHitDC, pProp->m_nParam1Value);
                    break;
                case 23: // Slay alignment
                    ApplyOnHitSlayAlignment(pAttacker, pTargetCreature, nOnHitDC, pProp->m_nParam1Value);
                    break;
                case 24: // Vorpal
                    if (bCrit && bPhysicalDamageApplied) ApplyOnHitVorpal(pAttacker, pTargetCreature, nOnHitDC);
                    break;
                case 25: // Wounding
                    ApplyOnHitWounding(pAttacker, pTargetCreature, nOnHitDC);
                    break;
            }
        }
    }
}

void DoAllDamageReductions(CNWSCreature* pAttacker, CNWSItem* pWeapon, BOOL bOffhand, CNWSObject* pTarget, int32_t vDamage[MAX_DAMAGE_TYPES])
{
    // Apply immunities/resistances
    for (int i = 0; i < MAX_DAMAGE_TYPES; i++)
    {
        if (i == 12) continue; // Skip Base damage type

        if (vDamage[i] > 0) vDamage[i] = pTarget->DoDamageImmunity(pAttacker, vDamage[i], 1 << i, false, false);
        if (vDamage[i] > 0) vDamage[i] = pTarget->DoDamageResistance(pAttacker, vDamage[i], 1 << i, false, false, false);
    }

    // Get weapon power for damage reduction
    int32_t nWeaponPower;
    if (pAttacker->GetUnarmed()) 
        nWeaponPower = GetUnarmedWeaponPower(pAttacker, pWeapon);
    else
        nWeaponPower = pAttacker->GetWeaponPower(pTarget, bOffhand);

    // Set base damage and do damage reduction
    vDamage[12] = std::max(vDamage[0], std::max(vDamage[1], vDamage[2]));
    vDamage[12] = pTarget->DoDamageReduction(pAttacker, vDamage[12], nWeaponPower, false, false);
}

NWNX_EXPORT ArgumentStack DealMeleeDamage(ArgumentStack&& args)
{
    int32_t result = 0; // something went wrong

    const auto oidTarget = Events::ExtractArgument<ObjectID>(args);
    const auto oidAttacker = Events::ExtractArgument<ObjectID>(args);
    const auto fDamageMultiplier = args.extract<float>();
    const auto bOffhand = args.extract<int32_t>();
    const auto nCritMode = args.extract<int32_t>();
    const auto nSneakMode = args.extract<int32_t>();
    const auto bDoOnHitEffects = args.extract<int32_t>();
    const auto bRollMaxDamage = args.extract<int32_t>();
    const auto nMaxOnHitSpellTriggers = args.extract<int32_t>();
    const auto bSkipDevCritEffect = args.extract<int32_t>();
    
    auto *pAttacker = Utils::AsNWSCreature(Utils::GetGameObject(oidAttacker));
    if (auto *pTarget = Utils::AsNWSObject(Utils::GetGameObject(oidTarget)))
    {
        int32_t vDamage[MAX_DAMAGE_TYPES];
        memset(vDamage, 0xFF, sizeof(vDamage));

        CNWSCreature* pTargetCreature = nullptr;
        if (pTarget->m_nObjectType == Constants::ObjectType::Creature)
            pTargetCreature = Utils::AsNWSCreature(pTarget);

        // Load needed 2DAs
        C2DA damageCost2DA("iprp_damagecost", true);
        damageCost2DA.Load2DArray();

        auto bSneak = CheckSneakAttack(pAttacker, pTargetCreature, nSneakMode);

        // Check for crit
        auto bCrit = CheckCrit(pAttacker, pTarget, nCritMode, bOffhand);
        auto nCritMultiplier = bCrit ? pAttacker->m_pStats->GetCriticalHitMultiplier(bOffhand) : 1;
        
        result = bCrit ? 3 : 1; // Crit or normal hit
        
        // Get attack weapon
        auto pWeapon = GetAttackWeapon(pAttacker, bOffhand);
        
        // Check for devastating crit
        if ((bCrit) && (pTargetCreature) && (pAttacker->m_pStats->GetEpicWeaponDevastatingCritical(pWeapon)))
        {
            auto nDevCritDC = Globals::Rules()->GetRulesetIntEntry("DEVASTATING_CRITICAL_BASE_DC", 10) + (pAttacker->m_pStats->GetLevel(true) / 2) + pAttacker->m_pStats->GetAbilityMod(Constants::Ability::Strength);
            if (!pTargetCreature->SavingThrowRoll(Constants::SavingThrow::Fortitude, nDevCritDC, Constants::SavingThrowType::None, oidAttacker))
            {
                result = 10; // Dev Crit
                if (!bSkipDevCritEffect)
                {
                    SlayCreature(pAttacker, pTargetCreature, false);
                    return result; 
                }
            }
        }

        // Get total physical damage
        ApplyPhysicalWeaponDamage(pAttacker, pWeapon, pTarget, bCrit, bSneak, nCritMultiplier, bRollMaxDamage, &damageCost2DA, vDamage);

        // Elemental weapon damage
        ApplyElementalWeaponDamage(pWeapon, pTargetCreature, nCritMultiplier, bRollMaxDamage, &damageCost2DA, vDamage);
        
        // Elemental effect damage increases/decreases
        AddElementalDamageModifiers(pAttacker, pTargetCreature, nCritMultiplier, bRollMaxDamage, &damageCost2DA, vDamage, Constants::EffectTrueType::DamageIncrease);
        AddElementalDamageModifiers(pAttacker, pTargetCreature, nCritMultiplier, bRollMaxDamage, &damageCost2DA, vDamage, Constants::EffectTrueType::DamageDecrease);

        // Scale damage according to the fDamageMultiplier argument
        for (int i=0; i < MAX_DAMAGE_TYPES; i++)
        {
            if (vDamage[i] > 0)
                vDamage[i] = (int32_t)(fDamageMultiplier * vDamage[i]);
        }

        // Damage resistance, immunity and reductions
        DoAllDamageReductions(pAttacker, pWeapon, bOffhand, pTarget, vDamage);

        // Apply damage
        auto *pEffect = new CGameEffect(true);
        pEffect->m_nType = Constants::EffectTrueType::Damage;
        pEffect->SetCreator(oidAttacker);
        pEffect->SetNumIntegers(MAX_DAMAGE_TYPES + 7);
        for (int k = 0; k < 3; k++)
            pEffect->SetInteger(k, -1);
        for (int k = 3; k < MAX_DAMAGE_TYPES; k++)
            pEffect->SetInteger(k, vDamage[k]);
        pEffect->SetInteger(MAX_DAMAGE_TYPES + 1, 1000); // Animation Time
        pEffect->SetInteger(MAX_DAMAGE_TYPES + 4, true); // Combat damage
        pEffect->SetInteger(MAX_DAMAGE_TYPES + 5, false); // Check if ranged (this sets bRangedAttack internally)
        pTarget->ApplyEffect(pEffect, false, true);

        // Death Attack
        if ((bSneak) && (pTargetCreature) && (pAttacker->m_pStats->HasFeat(Constants::Feat::PrestigeDeathAttack1)))
        {
            auto nAssassinLevel = pAttacker->m_pStats->GetNumLevelsOfClass(Constants::ClassType::Assassin);
            auto nDeathAttackDC = Globals::Rules()->GetRulesetIntEntry("DEATH_ATTACK_BASE_SAVE_DC", 10) + pAttacker->m_pStats->GetAbilityMod(Constants::Ability::Intelligence) + nAssassinLevel;
            if ((!pTargetCreature->m_bCombatState) && (!pTargetCreature->m_pStats->GetEffectImmunity(Constants::ImmunityType::Paralysis, pAttacker)) && 
                (!pTargetCreature->SavingThrowRoll(Constants::SavingThrow::Fortitude, nDeathAttackDC, Constants::SavingThrowType::Paralysis, pAttacker->m_idSelf)))
            {
                ApplyStateEffect(pAttacker, pTarget, 82, Constants::EffectDurationType::Temporary, 8, nAssassinLevel * 6.0f, 1, true);
            }
        }

        // Apply OnHit effects
        if (bDoOnHitEffects)
            ApplyOnHitEffects(pAttacker, pWeapon, pTarget, vDamage[12] > 0, bCrit, nMaxOnHitSpellTriggers);        
    }

    return result;
}
