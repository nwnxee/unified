#include "nwnx.hpp"

#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSCombatAttackData.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWVisibilityNode.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWRules.hpp"

#include <cmath>


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


static void ResolveSneakAttackHook(CNWSCreature*, CNWSCreature*);
static void ResolveDeathAttackHook(CNWSCreature*, CNWSCreature*);

void SneakAttackCritImmunity() __attribute__((constructor));
void SneakAttackCritImmunity()
{
    if (!Config::Get<bool>("SNEAK_ATTACK_IGNORE_CRIT_IMMUNITY", false))
        return;

    LOG_INFO("Sneak attacks will now be possible on creatures with immunity to critical hits");

    static Hooks::Hook s_ResolveSneakAttackHook =
            Hooks::HookFunction(&CNWSCreature::ResolveSneakAttack,
            &ResolveSneakAttackHook, Hooks::Order::Final);
    static Hooks::Hook s_ResolveDeathAttackHook =
            Hooks::HookFunction(&CNWSCreature::ResolveDeathAttack,
            &ResolveDeathAttackHook, Hooks::Order::Final);
}

static void ResolveSneakAttackHook(CNWSCreature *pThis, CNWSCreature *pTarget)
{
    static const float SNEAK_ATTACK_DISTANCE = std::pow(
        Globals::Rules()->GetRulesetFloatEntry(CRULES_HASHEDSTR("MAX_RANGED_SNEAK_ATTACK_DISTANCE"), 10.0f), 2);
    if (!pTarget)
        return;

    CNWSCombatAttackData* pAttackData = pThis->m_pcCombatRound->GetAttack(pThis->m_pcCombatRound->m_nCurrentAttack);

    if (pAttackData->m_nAttackType == Constants::Feat::WhirlwindAttack ||
        pAttackData->m_nAttackType == Constants::Feat::ImprovedWhirlwind)
    {
        return;
    }

    const uint16_t sneakAttackFeats[] =
    {
        Constants::Feat::SneakAttack,
        Constants::Feat::SneakAttack2,
        Constants::Feat::SneakAttack3,
        Constants::Feat::SneakAttack4,
        Constants::Feat::SneakAttack5,
        Constants::Feat::SneakAttack6,
        Constants::Feat::SneakAttack7,
        Constants::Feat::SneakAttack8,
        Constants::Feat::SneakAttack9,
        Constants::Feat::SneakAttack10,
        Constants::Feat::SneakAttack11,
        Constants::Feat::SneakAttack12,
        Constants::Feat::SneakAttack13,
        Constants::Feat::SneakAttack14,
        Constants::Feat::SneakAttack15,
        Constants::Feat::SneakAttack16,
        Constants::Feat::SneakAttack17,
        Constants::Feat::SneakAttack18,
        Constants::Feat::SneakAttack19,
        Constants::Feat::SneakAttack20,
        Constants::Feat::BlackguardSneakAttack1d6,
        Constants::Feat::BlackguardSneakAttack2d6,
        Constants::Feat::BlackguardSneakAttack3d6,
        Constants::Feat::BlackguardSneakAttack4d6,
        Constants::Feat::BlackguardSneakAttack5d6,
        Constants::Feat::BlackguardSneakAttack6d6,
        Constants::Feat::BlackguardSneakAttack7d6,
        Constants::Feat::BlackguardSneakAttack8d6,
        Constants::Feat::BlackguardSneakAttack9d6,
        Constants::Feat::BlackguardSneakAttack10d6,
        Constants::Feat::BlackguardSneakAttack11d6,
        Constants::Feat::BlackguardSneakAttack12d6,
        Constants::Feat::BlackguardSneakAttack13d6,
        Constants::Feat::BlackguardSneakAttack14d6,
        Constants::Feat::BlackguardSneakAttack15d6,
        Constants::Feat::EpicImprovedSneakAttack1,
        Constants::Feat::EpicImprovedSneakAttack2,
        Constants::Feat::EpicImprovedSneakAttack3,
        Constants::Feat::EpicImprovedSneakAttack4,
        Constants::Feat::EpicImprovedSneakAttack5,
        Constants::Feat::EpicImprovedSneakAttack6,
        Constants::Feat::EpicImprovedSneakAttack7,
        Constants::Feat::EpicImprovedSneakAttack8,
        Constants::Feat::EpicImprovedSneakAttack9,
        Constants::Feat::EpicImprovedSneakAttack10
    };
    bool hasSneakAttack = false;
    for (size_t i = 0; i < sizeof(sneakAttackFeats) / sizeof(sneakAttackFeats[0]); i++)
    {
        if (pThis->m_pStats->HasFeat(sneakAttackFeats[i]))
        {
            hasSneakAttack = true;
            break;
        }
    }
    if (!hasSneakAttack)
        return;


    float fDistance = 0.0;
    if (pAttackData->m_bRangedAttack)
    {
        fDistance = Vector::MagnitudeSquared(pThis->m_vPosition - pTarget->m_vPosition);
        if (fDistance >= SNEAK_ATTACK_DISTANCE)
            return;
    }

    bool isSneakAttack = false;

    auto* pVisNode = pTarget->GetVisibleListElement(pThis->m_idSelf);
    if (!pVisNode || !pVisNode->m_bSeen || pTarget->GetFlatFooted())
    {
        isSneakAttack = true;
    }
    else if (pThis->GetFlanked(pTarget))
    {
        isSneakAttack = true;

        if (pTarget->m_pStats->HasFeat(Constants::Feat::UncannyDodge2))
        {
            const uint8_t uncannyClasses[] =
            {
                Constants::ClassType::Barbarian,
                Constants::ClassType::Rogue,
                Constants::ClassType::Assassin,
                Constants::ClassType::Shadowdancer
            };
            int attackerLevels = 0, defenderLevels = 0;

            for (uint8_t i = 0; i < 3; i++)
            {
                uint8_t attackerClass = pThis->m_pStats->GetClass(i);
                uint8_t defenderClass = pTarget->m_pStats->GetClass(i);
                for (size_t j = 0; j < sizeof(uncannyClasses) / sizeof(uncannyClasses[0]); j++)
                {
                    attackerLevels += (attackerClass == uncannyClasses[j]) ? pThis->m_pStats->GetClassLevel(i, false) : 0;
                    defenderLevels += (defenderClass == uncannyClasses[j]) ? pTarget->m_pStats->GetClassLevel(i, false) : 0;
                }
            }

            isSneakAttack = attackerLevels - defenderLevels >= Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("FLANK_LEVEL_RANGE"), 4);
        }
    }

    if (isSneakAttack)
    {
        if (pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::SneakAttack, pThis, true))
        {
            CNWCCMessageData* pData = new CNWCCMessageData;
            pData->SetObjectID(0, pTarget->m_idSelf);
            pData->SetInteger(0, 134);
            pAttackData->m_alstPendingFeedback.Add(pData);
        }
        else
        {
            pAttackData->m_bSneakAttack = 1;
        }
    }
}

// I refuse to take responsibility for the duplicated code, as NWN does it too!
static void ResolveDeathAttackHook(CNWSCreature *pThis, CNWSCreature *pTarget)
{
    static const float SNEAK_ATTACK_DISTANCE = std::pow(
            Globals::Rules()->GetRulesetFloatEntry(CRULES_HASHEDSTR("MAX_RANGED_SNEAK_ATTACK_DISTANCE"), 10.0f), 2);
    if (!pTarget)
        return;

    CNWSCombatAttackData *pAttackData = pThis->m_pcCombatRound->GetAttack(pThis->m_pcCombatRound->m_nCurrentAttack);

    if (pAttackData->m_nAttackType == Constants::Feat::WhirlwindAttack ||
        pAttackData->m_nAttackType == Constants::Feat::ImprovedWhirlwind)
    {
        return;
    }

    const uint16_t deathAttackFeats[] =
    {
        Constants::Feat::PrestigeDeathAttack1,
        Constants::Feat::PrestigeDeathAttack2,
        Constants::Feat::PrestigeDeathAttack3,
        Constants::Feat::PrestigeDeathAttack4,
        Constants::Feat::PrestigeDeathAttack5,
        Constants::Feat::PrestigeDeathAttack6,
        Constants::Feat::PrestigeDeathAttack7,
        Constants::Feat::PrestigeDeathAttack8,
        Constants::Feat::PrestigeDeathAttack9,
        Constants::Feat::PrestigeDeathAttack10,
        Constants::Feat::PrestigeDeathAttack11,
        Constants::Feat::PrestigeDeathAttack12,
        Constants::Feat::PrestigeDeathAttack13,
        Constants::Feat::PrestigeDeathAttack14,
        Constants::Feat::PrestigeDeathAttack15,
        Constants::Feat::PrestigeDeathAttack16,
        Constants::Feat::PrestigeDeathAttack17,
        Constants::Feat::PrestigeDeathAttack18,
        Constants::Feat::PrestigeDeathAttack19,
        Constants::Feat::PrestigeDeathAttack20
    };
    bool hasDeathAttack = false;
    for (size_t i = 0; i < sizeof(deathAttackFeats)/sizeof(deathAttackFeats[0]); i++)
    {
        if (pThis->m_pStats->HasFeat(deathAttackFeats[i]))
        {
            hasDeathAttack = true;
            break;
        }
    }
    if (!hasDeathAttack)
        return;


    float fDistance = 0.0;
    if (pAttackData->m_bRangedAttack)
    {
        fDistance = Vector::MagnitudeSquared(pThis->m_vPosition - pTarget->m_vPosition);
        if (fDistance >= SNEAK_ATTACK_DISTANCE)
            return;
    }

    bool isDeathAttack = false;

    auto* pVisNode = pTarget->GetVisibleListElement(pThis->m_idSelf);
    if (!pVisNode || !pVisNode->m_bSeen || pTarget->GetFlatFooted())
    {
        isDeathAttack = true;
    }
    else if (pThis->GetFlanked(pTarget))
    {
        isDeathAttack = true;

        if (pTarget->m_pStats->HasFeat(Constants::Feat::UncannyDodge2))
        {
            const uint8_t uncannyClasses[] =
            {
                Constants::ClassType::Barbarian,
                Constants::ClassType::Rogue,
                Constants::ClassType::Assassin,
                Constants::ClassType::Shadowdancer
            };
            int attackerLevels = 0, defenderLevels = 0;

            for (uint8_t i = 0; i < 3; i++)
            {
                uint8_t attackerClass = pThis->m_pStats->GetClass(i);
                uint8_t defenderClass = pTarget->m_pStats->GetClass(i);
                for (size_t j = 0; j < sizeof(uncannyClasses) / sizeof(uncannyClasses[0]); j++)
                {
                    attackerLevels += (attackerClass == uncannyClasses[j]) ? pThis->m_pStats->GetClassLevel(i, false) : 0;
                    defenderLevels += (defenderClass == uncannyClasses[j]) ? pTarget->m_pStats->GetClassLevel(i, false) : 0;
                }
            }

            isDeathAttack = attackerLevels - defenderLevels >= Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("FLANK_LEVEL_RANGE"), 4);
        }
    }

    if (isDeathAttack)
    {
        if (pTarget->m_pStats->GetEffectImmunity(Constants::ImmunityType::SneakAttack, pThis, true))
        {
            CNWCCMessageData* pData = new CNWCCMessageData;
            pData->SetObjectID(0, pTarget->m_idSelf);
            pData->SetInteger(0, 134);
            pAttackData->m_alstPendingFeedback.Add(pData);
        }
        else
        {
            pAttackData->m_bDeathAttack = 1;
        }
    }
}

}
