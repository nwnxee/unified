#include "nwnx.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWSCombatAttackData.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWCCMessageData.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_InResolveMeleeSpecialAttack;

inline bool GetAttackResultHit(CNWSCombatAttackData *pAttackData)
{
    if (pAttackData->m_nAttackResult == 1 || pAttackData->m_nAttackResult == 3 || pAttackData->m_nAttackResult == 5 ||
        pAttackData->m_nAttackResult == 6 || pAttackData->m_nAttackResult == 7 || pAttackData->m_nAttackResult == 10)
        return true;
    else
        return false;
}

void FixResolveSpecialAttackDamage() __attribute__((constructor));
void FixResolveSpecialAttackDamage()
{
    if (!Config::Get<bool>("FIX_RESOLVE_SPECIAL_ATTACK_DAMAGE", false))
        return;

    LOG_INFO("Special Attacks will not resolve damage on a miss.");

    static Hooks::Hook s_ResolveMeleeSpecialAttackHook =
        Hooks::HookFunction(&CNWSCreature::ResolveMeleeSpecialAttack,
        +[](CNWSCreature *pThis, int32_t nAttackIndex, int32_t nAttacks, CNWSObject *pTarget, int32_t nTimeAnimation) -> void
        {
            s_InResolveMeleeSpecialAttack = true;
            s_ResolveMeleeSpecialAttackHook->CallOriginal<void>(pThis, nAttackIndex, nAttacks, pTarget, nTimeAnimation);
            s_InResolveMeleeSpecialAttack = false;

        }, Hooks::Order::Earliest);

    static Hooks::Hook s_ResolveDamageHook =
        Hooks::HookFunction(&CNWSCreature::ResolveDamage,
        +[](CNWSCreature *pThis, CNWSObject *pTarget) -> void
        {
            if (s_InResolveMeleeSpecialAttack)
            {
                if (!GetAttackResultHit(pThis->m_pcCombatRound->GetAttack(pThis->m_pcCombatRound->m_nCurrentAttack)))
                    return;
            }

            s_ResolveDamageHook->CallOriginal<void>(pThis, pTarget);
        }, Hooks::Order::Early);

    static Hooks::Hook s_ResolvePostMeleeDamageHook =
        Hooks::HookFunction(&CNWSCreature::ResolvePostMeleeDamage,
        +[](CNWSCreature *pThis, CNWSObject *pTarget) -> void
        {
            if (s_InResolveMeleeSpecialAttack)
            {
                if (!GetAttackResultHit(pThis->m_pcCombatRound->GetAttack(pThis->m_pcCombatRound->m_nCurrentAttack)))
                    return;
            }

            s_ResolvePostMeleeDamageHook->CallOriginal<void>(pThis, pTarget);
        }, Hooks::Order::Early);

    static Hooks::Hook s_ResolveRangedSpecialAttackHook =
        Hooks::HookFunction(&CNWSCreature::ResolveRangedSpecialAttack,
        +[](CNWSCreature *pThis, CNWSObject *pTarget, int32_t nTimeAnimation) -> void
        {
            if (!pTarget)
                return;

            CNWSCombatAttackData *pAttackData = pThis->m_pcCombatRound->GetAttack(pThis->m_pcCombatRound->m_nCurrentAttack);

            pThis->ResolveAttackRoll(pTarget);

            if (GetAttackResultHit(pAttackData))
            {
                pThis->ResolveDamage(pTarget);
                pThis->ResolvePostRangedDamage(pTarget);
            }
            else
            {
                pThis->ResolveRangedMiss(pTarget);
            }

            pThis->ResolveRangedAnimations(pTarget, nTimeAnimation);

            switch (pAttackData->m_nAttackType)
            {
                case 65001:
                {
                    if (GetAttackResultHit(pAttackData))
                    {
                        if (pAttackData->GetTotalDamage(true) > 0)
                        {
                            if (auto *pCreature = Utils::AsNWSCreature(pTarget))
                            {
                                if (pCreature->m_bHasArms)
                                {
                                    if (rand() % 20 + 1 + pCreature->m_pStats->GetSkillRank(3, Utils::AsNWSObject(pCreature)) < pAttackData->m_nToHitRoll + pAttackData->m_nToHitMod)
                                    {
                                        auto *pEffect = new CGameEffect();
                                        pEffect->m_nType = Constants::EffectTrueType::AttackDecrease;
                                        pEffect->SetDurationType(Constants::EffectDurationType::Temporary);
                                        pEffect->m_fDuration = Globals::Rules()->GetRulesetFloatEntry(CRULES_HASHEDSTR("CALLED_SHOT_EFFECT_DURATION"), 24.0f);
                                        pEffect->SetCreator(pThis->m_idSelf);
                                        pEffect->SetInteger(0, Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("CALLED_SHOT_ARM_ATTACK_PENALTY"), 2));
                                        pEffect->SetInteger(1, 0);
                                        pEffect->SetInteger(2, 28);

                                        pAttackData->m_alstOnHitGameEffects.Add(pEffect);
                                    }
                                    else
                                        pAttackData->m_nAttackResult = 5;
                                }
                                else
                                {
                                    auto *pMessageData = new CNWCCMessageData;
                                    pMessageData->m_nType = 3;
                                    pMessageData->SetInteger(0, 30);
                                    pAttackData->m_alstPendingFeedback.Add(pMessageData);
                                    pAttackData->m_nAttackResult = 6;
                                }
                            }
                            else
                            {
                                pAttackData->m_nAttackResult = 6;
                            }
                        }
                        else
                        {
                            pAttackData->m_nAttackResult = 6;
                        }
                    }
                    break;
                }

                case 65000:
                {
                    if (GetAttackResultHit(pAttackData))
                    {
                        if (pAttackData->GetTotalDamage(true) > 0)
                        {
                            if (auto *pCreature = Utils::AsNWSCreature(pTarget))
                            {
                                if (pCreature->m_bHasLegs)
                                {
                                    if (rand() % 20 + 1 + pCreature->m_pStats->GetSkillRank(3, Utils::AsNWSObject(pCreature)) < pAttackData->m_nToHitRoll + pAttackData->m_nToHitMod)
                                    {
                                        auto *pEffect1 = new CGameEffect();
                                        pEffect1->m_nType = Constants::EffectTrueType::AbilityDecrease;
                                        pEffect1->SetDurationType(Constants::EffectDurationType::Temporary);
                                        pEffect1->m_fDuration = Globals::Rules()->GetRulesetFloatEntry(CRULES_HASHEDSTR("CALLED_SHOT_EFFECT_DURATION"), 24.0f);
                                        pEffect1->SetCreator(pThis->m_idSelf);
                                        pEffect1->SetInteger(0, 1);
                                        pEffect1->SetInteger(1, Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("CALLED_SHOT_LEG_ABILITY_PENALTY"), 2));
                                        pAttackData->m_alstOnHitGameEffects.Add(pEffect1);

                                        auto *pEffect2 = new CGameEffect();
                                        pEffect2->m_nType = Constants::EffectTrueType::MovementSpeedDecrease;
                                        pEffect2->SetDurationType(Constants::EffectDurationType::Temporary);
                                        pEffect2->m_fDuration = Globals::Rules()->GetRulesetFloatEntry(CRULES_HASHEDSTR("CALLED_SHOT_EFFECT_DURATION"), 24.0f);
                                        pEffect2->SetCreator(pThis->m_idSelf);
                                        pEffect2->SetInteger(0, Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("CALLED_SHOT_LEG_MOVEMENT_PENALTY"), 20));
                                        pAttackData->m_alstOnHitGameEffects.Add(pEffect2);
                                    }
                                    else
                                        pAttackData->m_nAttackResult = 5;
                                }
                                else
                                {
                                    auto *pMessageData = new CNWCCMessageData;
                                    pMessageData->m_nType = 3;
                                    pMessageData->SetInteger(0, 29);
                                    pAttackData->m_alstPendingFeedback.Add(pMessageData);
                                    pAttackData->m_nAttackResult = 6;
                                }
                            }
                            else
                            {
                                pAttackData->m_nAttackResult = 6;
                            }
                        }
                        else
                        {
                            pAttackData->m_nAttackResult = 6;
                        }
                    }
                    break;
                }
            }
        }, Hooks::Order::Final);
}

}
