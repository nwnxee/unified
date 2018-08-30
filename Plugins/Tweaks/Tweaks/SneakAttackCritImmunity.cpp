#include "Tweaks/SneakAttackCritImmunity.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSCombatAttackData.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWVisibilityNode.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include "API/Version.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNXLib::Hooking::FunctionHook* SneakAttackCritImmunity::pResolveSneakAttack_hook;
NWNXLib::Hooking::FunctionHook* SneakAttackCritImmunity::pResolveDeathAttack_hook;
SneakAttackCritImmunity::SneakAttackCritImmunity(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<Functions::CNWSCreature__ResolveSneakAttack>
                                    (&CNWSCreature__ResolveSneakAttack_hook);
    hooker->RequestExclusiveHook<Functions::CNWSCreature__ResolveDeathAttack>
                                    (&CNWSCreature__ResolveDeathAttack_hook);

    pResolveSneakAttack_hook = hooker->FindHookByAddress(Functions::CNWSCreature__ResolveSneakAttack);
    pResolveDeathAttack_hook = hooker->FindHookByAddress(Functions::CNWSCreature__ResolveDeathAttack);
}


void SneakAttackCritImmunity::CNWSCreature__ResolveSneakAttack_hook(CNWSCreature *pThis, CNWSCreature *pTarget)
{
    static const float SNEAK_ATTACK_DISTANCE = 100.0f;
    if (!pTarget)
        return;

    CNWSCombatAttackData *pAttackData = pThis->m_pcCombatRound->GetAttack(pThis->m_pcCombatRound->m_nCurrentAttack);

    if (pAttackData->m_nAttackType == Constants::FEAT_WHIRLWIND_ATTACK ||
        pAttackData->m_nAttackType == Constants::FEAT_IMPROVED_WHIRLWIND)
    {
        return;
    }

    const uint16_t sneakAttackFeats[] =
    {
        Constants::FEAT_SNEAK_ATTACK,
        Constants::FEAT_SNEAK_ATTACK_2,
        Constants::FEAT_SNEAK_ATTACK_3,
        Constants::FEAT_SNEAK_ATTACK_4,
        Constants::FEAT_SNEAK_ATTACK_5,
        Constants::FEAT_SNEAK_ATTACK_6,
        Constants::FEAT_SNEAK_ATTACK_7,
        Constants::FEAT_SNEAK_ATTACK_8,
        Constants::FEAT_SNEAK_ATTACK_9,
        Constants::FEAT_SNEAK_ATTACK_10,
        Constants::FEAT_SNEAK_ATTACK_11,
        Constants::FEAT_SNEAK_ATTACK_12,
        Constants::FEAT_SNEAK_ATTACK_13,
        Constants::FEAT_SNEAK_ATTACK_14,
        Constants::FEAT_SNEAK_ATTACK_15,
        Constants::FEAT_SNEAK_ATTACK_16,
        Constants::FEAT_SNEAK_ATTACK_17,
        Constants::FEAT_SNEAK_ATTACK_18,
        Constants::FEAT_SNEAK_ATTACK_19,
        Constants::FEAT_SNEAK_ATTACK_20,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_1D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_2D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_3D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_4D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_5D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_6D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_7D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_8D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_9D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_10D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_11D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_12D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_13D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_14D6,
        Constants::FEAT_BLACKGUARD_SNEAK_ATTACK_15D6,
        Constants::FEAT_EPIC_IMPROVED_SNEAK_ATTACK_1,
        Constants::FEAT_EPIC_IMPROVED_SNEAK_ATTACK_2,
        Constants::FEAT_EPIC_IMPROVED_SNEAK_ATTACK_3,
        Constants::FEAT_EPIC_IMPROVED_SNEAK_ATTACK_4,
        Constants::FEAT_EPIC_IMPROVED_SNEAK_ATTACK_5,
        Constants::FEAT_EPIC_IMPROVED_SNEAK_ATTACK_6,
        Constants::FEAT_EPIC_IMPROVED_SNEAK_ATTACK_7,
        Constants::FEAT_EPIC_IMPROVED_SNEAK_ATTACK_8,
        Constants::FEAT_EPIC_IMPROVED_SNEAK_ATTACK_9,
        Constants::FEAT_EPIC_IMPROVED_SNEAK_ATTACK_10
    };
    bool hasSneakAttack = false;
    for (size_t i = 0; i < sizeof(sneakAttackFeats)/sizeof(sneakAttackFeats[0]); i++)
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
        Vector v = pThis->m_vPosition;
        v -= pTarget->m_vPosition;
        fDistance = v.x*v.x + v.y*v.y + v.z*v.z;
    }

    bool isSneakAttack = false;

    auto *pVisNode = pTarget->GetVisibleListElement(pThis->m_idSelf);
    if (!pVisNode || !pVisNode->m_bSeen || pTarget->GetFlatFooted())
    {
        isSneakAttack = (!pAttackData->m_bRangedAttack || fDistance < SNEAK_ATTACK_DISTANCE);
    }
    else if (pTarget->m_pStats->HasFeat(Constants::FEAT_UNCANNY_DODGE_2))
    {
        const uint8_t uncannyClasses[] = 
        {
            Constants::CLASS_TYPE_BARBARIAN,
            Constants::CLASS_TYPE_ROGUE,
            Constants::CLASS_TYPE_ASSASSIN,
            Constants::CLASS_TYPE_SHADOWDANCER
        };
        int attackerLevels = 0, defenderLevels = 0;

        for (uint8_t i = 0; i < 3; i++)
        {
            uint8_t attackerClass = pThis->m_pStats->GetClass(i);
            uint8_t defenderClass = pTarget->m_pStats->GetClass(i);
            for (size_t j = 0; j < sizeof(uncannyClasses)/sizeof(uncannyClasses[0]); j++)
            {
                attackerLevels += (attackerClass == uncannyClasses[j]) ? pThis->m_pStats->GetClassLevel(i, false) : 0;
                defenderLevels += (defenderClass == uncannyClasses[j]) ? pTarget->m_pStats->GetClassLevel(i, false) : 0;
            }
        }
        if (attackerLevels - defenderLevels >= 4)
        {
            if (pThis->GetFlanked(pTarget)) // Bad function name, but this does the correct check
            {
                isSneakAttack = (!pAttackData->m_bRangedAttack || fDistance < SNEAK_ATTACK_DISTANCE);
            }
        }
    }

    if (isSneakAttack)
    {
        if (pTarget->m_pStats->GetEffectImmunity(30 /*backstab*/, pThis, true))
        {
            CNWCCMessageData *pData = new CNWCCMessageData;
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
void SneakAttackCritImmunity::CNWSCreature__ResolveDeathAttack_hook(CNWSCreature *pThis, CNWSCreature *pTarget)
{
    static const float SNEAK_ATTACK_DISTANCE = 100.0f;
    if (!pTarget)
        return;

    CNWSCombatAttackData *pAttackData = pThis->m_pcCombatRound->GetAttack(pThis->m_pcCombatRound->m_nCurrentAttack);

    if (pAttackData->m_nAttackType == Constants::FEAT_WHIRLWIND_ATTACK ||
        pAttackData->m_nAttackType == Constants::FEAT_IMPROVED_WHIRLWIND)
    {
        return;
    }

    const uint16_t deathAttackFeats[] =
    {
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_1,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_2,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_3,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_4,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_5,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_6,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_7,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_8,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_9,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_10,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_11,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_12,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_13,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_14,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_15,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_16,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_17,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_18,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_19,
        Constants::FEAT_PRESTIGE_DEATH_ATTACK_20
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
        Vector v = pThis->m_vPosition;
        v -= pTarget->m_vPosition;
        fDistance = v.x*v.x + v.y*v.y + v.z*v.z;
    }

    bool isDeathAttack = false;

    auto *pVisNode = pTarget->GetVisibleListElement(pThis->m_idSelf);
    if (!pVisNode || !pVisNode->m_bSeen || pTarget->GetFlatFooted())
    {
        isDeathAttack = (!pAttackData->m_bRangedAttack || fDistance < SNEAK_ATTACK_DISTANCE);
    }
    else if (pTarget->m_pStats->HasFeat(Constants::FEAT_UNCANNY_DODGE_2))
    {
        const uint8_t uncannyClasses[] = 
        {
            Constants::CLASS_TYPE_BARBARIAN,
            Constants::CLASS_TYPE_ROGUE,
            Constants::CLASS_TYPE_ASSASSIN,
            Constants::CLASS_TYPE_SHADOWDANCER
        };
        int attackerLevels = 0, defenderLevels = 0;

        for (uint8_t i = 0; i < 3; i++)
        {
            uint8_t attackerClass = pThis->m_pStats->GetClass(i);
            uint8_t defenderClass = pTarget->m_pStats->GetClass(i);
            for (size_t j = 0; j < sizeof(uncannyClasses)/sizeof(uncannyClasses[0]); j++)
            {
                attackerLevels += (attackerClass == uncannyClasses[j]) ? pThis->m_pStats->GetClassLevel(i, false) : 0;
                defenderLevels += (defenderClass == uncannyClasses[j]) ? pTarget->m_pStats->GetClassLevel(i, false) : 0;
            }
        }
        if (attackerLevels - defenderLevels >= 4)
        {
            if (pThis->GetFlanked(pTarget)) // Bad function name, but this does the correct check
            {
                isDeathAttack = (!pAttackData->m_bRangedAttack || fDistance < SNEAK_ATTACK_DISTANCE);
            }
        }
    }

    if (isDeathAttack)
    {
        if (pTarget->m_pStats->GetEffectImmunity(30 /*backstab*/, pThis, true))
        {
            CNWCCMessageData *pData = new CNWCCMessageData;
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
