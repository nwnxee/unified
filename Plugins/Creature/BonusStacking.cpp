#include "Creature.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Services.hpp"
#include "Utils.hpp"
#include "API/CAppManager.hpp"
#include "API/CNWSAreaOfEffectObject.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CNWSRules.hpp"
#include "API/CExoArrayList.hpp"
#include "API/CServerExoApp.hpp"

namespace Creature
{

using namespace NWNXLib;
using namespace NWNXLib::API;
using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

int BonusStacking::s_nAbilityStackingMode = NostackMode::Disabled;
int BonusStacking::s_nSkillStackingMode = NostackMode::Disabled;
int BonusStacking::s_nSavingThrowStackingMode = NostackMode::Disabled;
int BonusStacking::s_nAttackBonusStackingMode = NostackMode::Disabled;
bool BonusStacking::s_bAlwaysStackPenalties = false;
std::vector<int32_t> g_nSpellBonusTypes;
int32_t g_nSpellDefaultType = NostackType::Circumstance;
int32_t g_nItemDefaultType = NostackType::Enhancement;

NWNXLib::Hooking::FunctionHook* pGetTotalEffectBonusHook;

void BonusStacking::Init(Services::ProxyServiceList* services)
{
    s_nAbilityStackingMode = std::clamp(services->m_config->Get<int>("NOSTACK_ABILITY", 0), 0, static_cast<int>(NostackMode::CustomTypes));
    s_nSkillStackingMode = std::clamp(services->m_config->Get<int>("NOSTACK_SKILL", 0), 0, static_cast<int>(NostackMode::CustomTypes));
    s_nSavingThrowStackingMode = std::clamp(services->m_config->Get<int>("NOSTACK_SAVINGTHROW", 0), 0, static_cast<int>(NostackMode::CustomTypes));
    s_nAttackBonusStackingMode = std::clamp(services->m_config->Get<int>("NOSTACK_ATTACKBONUS", 0), 0, static_cast<int>(NostackMode::CustomTypes));

    if (s_nAbilityStackingMode || s_nSkillStackingMode || s_nSavingThrowStackingMode || s_nAttackBonusStackingMode)
    {
        LOG_INFO("Property effect stacking modes -- Ability scores: %d | Skill bonuses: %d | Saving throw bonuses: %d"
            " | Attack bonuses: %d", s_nAbilityStackingMode, s_nSkillStackingMode, s_nSavingThrowStackingMode, s_nAttackBonusStackingMode);

        g_nSpellDefaultType = std::min(services->m_config->Get<int>("NOSTACK_SPELL_DEFAULT_TYPE", NostackType::Circumstance), 0);
        g_nItemDefaultType = std::min(services->m_config->Get<int>("NOSTACK_ITEM_DEFAULT_TYPE", NostackType::Enhancement), 0);
        s_bAlwaysStackPenalties = services->m_config->Get<bool>("NOSTACK_ALWAYS_STACK_PENALTIES", false);

        services->m_hooks->RequestExclusiveHook<Functions::_ZN12CNWSCreature19GetTotalEffectBonusEhP10CNWSObjectiihhhhi>
            (&GetTotalEffectBonus);
        pGetTotalEffectBonusHook = services->m_hooks->FindHookByAddress(Functions::_ZN12CNWSCreature19GetTotalEffectBonusEhP10CNWSObjectiihhhhi);

        services->m_events->RegisterEvent("SetSpellBonusType", [](ArgumentStack&& args) { return BonusStacking::SetSpellBonusType(std::move(args)); });
    }
}

inline bool CheckRaceAlignment(uint16_t nRace, uint16_t nEffectRace, uint8_t nAlignLaw,
    uint8_t nEffectAlignLaw, uint8_t nAlignGood, uint8_t nEffectAlignGood);
inline void AddPositiveEffect(uint32_t nSpellId, uint32_t nEffectStrength);
inline void AddNegativeEffect(uint32_t nSpellId, uint32_t nEffectStrength);
inline void AddPositiveEffectOID(uint32_t nObjectId, uint32_t nEffectStrength);
inline void AddNegativeEffectOID(uint32_t nObjectId, uint32_t nEffectStrength);
inline uint32_t GetStackedBonus(bool negative = false);
inline uint32_t GetUnstackedBonus(bool negative = false, int mode = 0);

constexpr auto MAX_STACKED_EFFECTS = 50;
constexpr auto MAX_DAMAGE_FLAGS = 13;

uint32_t g_EffectsSpellID[MAX_STACKED_EFFECTS];
uint32_t g_EffectsSpellID2[MAX_STACKED_EFFECTS];
uint32_t g_EffectsStrength[MAX_STACKED_EFFECTS];
uint32_t g_EffectsStrength2[MAX_STACKED_EFFECTS];
uint32_t g_EffectsObjectID[MAX_STACKED_EFFECTS];
uint32_t g_EffectsObjectID2[MAX_STACKED_EFFECTS];
/*uint32_t g_EffectsExtra[MAX_STACKED_EFFECTS];
uint32_t g_EffectsExtra2[MAX_STACKED_EFFECTS];
uint32_t g_EffectsDamageFlags[MAX_DAMAGE_FLAGS];
uint32_t g_EffectsDamageFlags2[MAX_DAMAGE_FLAGS];*/
uint32_t g_nMaxValues[NostackType::Max + 1];

int32_t BonusStacking::GetTotalEffectBonus(CNWSCreature* thisPtr, uint8_t nEffectBonusType, CNWSObject* pObject, BOOL bElementalDamage,
    BOOL bForceMax, uint8_t nSaveType, uint8_t nSpecificType, uint8_t nSkill, uint8_t nAbilityScore, BOOL bOffHand)
{
    if (nEffectBonusType == Constants::EffectBonusType::Damage
        || ((nEffectBonusType == Constants::EffectBonusType::Attack || nEffectBonusType == Constants::EffectBonusType::TouchAttack) && !s_nAttackBonusStackingMode)
        || (nEffectBonusType == Constants::EffectBonusType::SavingThrow && !s_nSavingThrowStackingMode)
        || (nEffectBonusType == Constants::EffectBonusType::Ability && !s_nAbilityStackingMode)
        || (nEffectBonusType == Constants::EffectBonusType::Skill && !s_nSkillStackingMode)
        )
    {
        return pGetTotalEffectBonusHook->CallOriginal<int32_t>(thisPtr, nEffectBonusType, pObject,
            bElementalDamage, bForceMax, nSaveType, nSpecificType, nSkill, nAbilityScore, bOffHand);
    }

    auto* pCurrentAttack = thisPtr->m_pcCombatRound->GetAttack(thisPtr->m_pcCombatRound->m_nCurrentAttack);
    auto nAttackType = pCurrentAttack->m_nWeaponAttackType;
    if (!nAttackType)
    {
        nAttackType = bOffHand ? 2 : 1;
    }

    uint16_t nRace = static_cast<uint16_t>(~0u);
    uint8_t nAlignLaw = static_cast<uint8_t>(~0u), nAlignGood = static_cast<uint8_t>(~0u);
    uint32_t nEffectBonus = 0, nEffectPenalty = 0;

    if (pObject)
    {
        auto* pCreature = Utils::AsNWSCreature(pObject);
        if (!pCreature)
            if (auto* pAoE = Utils::AsNWSAreaOfEffectObject(pObject))
                pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pAoE->m_oidCreator);

        if (pCreature && pCreature->m_pStats)
        {
            nRace = pCreature->m_pStats->m_nRace;
            nAlignLaw = pCreature->m_pStats->GetSimpleAlignmentLawChaos();
            nAlignGood = pCreature->m_pStats->GetSimpleAlignmentGoodEvil();
        }
    }

    for (auto i = 0; i < MAX_STACKED_EFFECTS; i++)
    {
        g_EffectsSpellID[i] = ~0u;
        g_EffectsSpellID2[i] = ~0u;
        g_EffectsStrength[i] = ~0u;
        g_EffectsStrength2[i] = ~0u;
        g_EffectsObjectID[i] = Constants::OBJECT_INVALID;
        g_EffectsObjectID2[i] = Constants::OBJECT_INVALID;
    }

    switch (nEffectBonusType)
    {
        default:
            return 0;
        case Constants::EffectBonusType::Attack:
        case Constants::EffectBonusType::TouchAttack:
            for (auto i = thisPtr->m_pStats->m_nAttackBonusPtr; i < thisPtr->m_appliedEffects.num; i++)
            {
                auto nType = thisPtr->m_appliedEffects.element[i]->m_nType;
                if (nType < Constants::EffectTrueType::AttackIncrease || nType > Constants::EffectTrueType::AttackDecrease)
                    break;

                auto pEffect = thisPtr->m_appliedEffects.element[i];
                auto nEffectWeaponType = pEffect->GetInteger(1);
                bool bValidWeapon = nEffectWeaponType == 0 || nEffectWeaponType == nAttackType;
                if (nAttackType == Constants::WeaponAttackType::AdditionalWeapon)
                    bValidWeapon |= nEffectWeaponType == Constants::WeaponAttackType::MainhandWeapon
                                 || nEffectWeaponType == Constants::WeaponAttackType::CreatureLeftWeapon;
                else if (nAttackType == Constants::WeaponAttackType::AdditionalUnarmed)
                    bValidWeapon |= nEffectWeaponType == Constants::WeaponAttackType::Unarmed;

                if (bValidWeapon
                    && CheckRaceAlignment(nRace, pEffect->GetInteger(2),
                                          nAlignLaw, pEffect->GetInteger(3),
                                          nAlignGood, pEffect->GetInteger(4))
                    )
                {
                    uint32_t nEffectStrength = pEffect->GetInteger(0);

                    if (pEffect->m_nType == Constants::EffectTrueType::AttackIncrease)
                    {
                        if (nEffectWeaponType == 0)
                            AddPositiveEffect(pEffect->m_nSpellId, nEffectStrength);
                        else if (nEffectBonusType != Constants::EffectBonusType::TouchAttack)
                        {
                            if (auto pCreator = Globals::AppManager()->m_pServerExoApp->GetItemByGameObjectID(pEffect->m_oidCreator))
                                AddPositiveEffectOID(pCreator->m_idSelf, nEffectStrength);
                            else
                                AddPositiveEffect(pEffect->m_nSpellId, nEffectStrength);
                        }
                    }
                    else if (pEffect->m_nType == Constants::EffectTrueType::AttackDecrease)
                    {
                        if (nEffectWeaponType == 0)
                            AddNegativeEffect(pEffect->m_nSpellId, nEffectStrength);
                        else
                        {
                            if (auto pCreator = Globals::AppManager()->m_pServerExoApp->GetItemByGameObjectID(pEffect->m_oidCreator))
                                AddNegativeEffectOID(pCreator->m_idSelf, nEffectStrength);
                            else
                                AddNegativeEffect(pEffect->m_nSpellId, nEffectStrength);
                        }
                    }
                }
            }

            {
                nEffectBonus = !s_nAttackBonusStackingMode ? GetStackedBonus(false) : GetUnstackedBonus(false, s_nAttackBonusStackingMode);
                nEffectPenalty = (s_bAlwaysStackPenalties || !s_nAttackBonusStackingMode) ? GetStackedBonus(true) : GetUnstackedBonus(true, s_nAttackBonusStackingMode);

                uint32_t nAttackBonusLimit = Globals::AppManager()->m_pServerExoApp->GetAttackBonusLimit();
                nEffectBonus = std::min(nEffectBonus, nAttackBonusLimit);
                nEffectPenalty = std::min(nEffectPenalty, nAttackBonusLimit);
            }
            return nEffectBonus - nEffectPenalty;

        case Constants::EffectBonusType::Damage:
            //TODO: Damage bonuses can be added if needed by someone
            return 0;

        case Constants::EffectBonusType::SavingThrow:
            for (int i = thisPtr->m_pStats->m_nSavingThrowBonusPtr; i < thisPtr->m_appliedEffects.num; i++)
            {
                auto nType = thisPtr->m_appliedEffects.element[i]->m_nType;
                if (nType < Constants::EffectTrueType::SavingThrowIncrease || nType > Constants::EffectTrueType::SavingThrowDecrease)
                    break;

                auto pEffect = thisPtr->m_appliedEffects.element[i];
                auto nEffectSaveType = pEffect->GetInteger(1);
                auto nEffectSpecificType = pEffect->GetInteger(2);

                if ((nEffectSaveType == 0 || nEffectSaveType == nSaveType)
                    && (nEffectSpecificType == 0 || nEffectSpecificType == nSpecificType)
                    && CheckRaceAlignment(nRace, pEffect->GetInteger(3),
                                          nAlignLaw, pEffect->GetInteger(4),
                                          nAlignGood, pEffect->GetInteger(5))
                    )
                {
                    uint32_t nEffectStrength = pEffect->GetInteger(0);

                    if (pEffect->m_nType == Constants::EffectTrueType::SavingThrowIncrease)
                    {
                        if (auto pCreator = Globals::AppManager()->m_pServerExoApp->GetItemByGameObjectID(pEffect->m_oidCreator))
                            AddPositiveEffectOID(pCreator->m_idSelf, nEffectStrength);
                        else
                            AddPositiveEffect(pEffect->m_nSpellId, nEffectStrength);
                    }
                    else if (pEffect->m_nType == Constants::EffectTrueType::SavingThrowDecrease)
                    {
                        if (auto pCreator = Globals::AppManager()->m_pServerExoApp->GetItemByGameObjectID(pEffect->m_oidCreator))
                            AddNegativeEffectOID(pCreator->m_idSelf, nEffectStrength);
                        else
                            AddNegativeEffect(pEffect->m_nSpellId, nEffectStrength);
                    }
                }
            }

            nEffectBonus = !s_nSavingThrowStackingMode ? GetStackedBonus(false) : GetUnstackedBonus(false, s_nSavingThrowStackingMode);
            nEffectPenalty = (s_bAlwaysStackPenalties || !s_nSavingThrowStackingMode) ? GetStackedBonus(true) : GetUnstackedBonus(true, s_nSavingThrowStackingMode);

            {
                uint32_t nSavingThrowBonusLimit = Globals::AppManager()->m_pServerExoApp->GetSavingThrowBonusLimit();
                nEffectBonus = std::min(nEffectBonus, nSavingThrowBonusLimit);
                nEffectPenalty = std::min(nEffectPenalty, nSavingThrowBonusLimit);
            }

            if (thisPtr->m_pStats->HasFeat(Constants::Feat::SacredDefense1))
            {
                int nChampionLevel = thisPtr->m_pStats->GetNumLevelsOfClass(Constants::ClassType::DivineChampion);
                if (nChampionLevel > 1)
                    nEffectBonus += nChampionLevel / 2;
            }

            return nEffectBonus - nEffectPenalty;

        case Constants::EffectBonusType::Ability:
            for (int i = thisPtr->m_pStats->m_nAbilityPtr; i < thisPtr->m_appliedEffects.num; i++)
            {
                auto nType = thisPtr->m_appliedEffects.element[i]->m_nType;
                if (nType < Constants::EffectTrueType::AbilityIncrease || nType > Constants::EffectTrueType::AbilityDecrease)
                    break;

                auto pEffect = thisPtr->m_appliedEffects.element[i];
                uint8_t nEffectAbility = pEffect->GetInteger(0);

                if (nEffectAbility != nAbilityScore)
                    continue;

                uint32_t nEffectStrength = pEffect->GetInteger(1);

                if (pEffect->m_nType == Constants::EffectTrueType::AbilityIncrease)
                {
                    if (auto pCreator = Globals::AppManager()->m_pServerExoApp->GetItemByGameObjectID(pEffect->m_oidCreator))
                        AddPositiveEffectOID(pCreator->m_idSelf, nEffectStrength);
                    else
                        AddPositiveEffect(pEffect->m_nSpellId, nEffectStrength);
                }
                else if (pEffect->m_nType == Constants::EffectTrueType::AbilityDecrease)
                {
                    if (auto pCreator = Globals::AppManager()->m_pServerExoApp->GetItemByGameObjectID(pEffect->m_oidCreator))
                        AddNegativeEffectOID(pCreator->m_idSelf, nEffectStrength);
                    else
                        AddNegativeEffect(pEffect->m_nSpellId, nEffectStrength);
                }
            }

            nEffectBonus = !s_nAbilityStackingMode ? GetStackedBonus(false) : GetUnstackedBonus(false, s_nAbilityStackingMode);
            nEffectPenalty = (s_bAlwaysStackPenalties || !s_nAbilityStackingMode) ? GetStackedBonus(true) : GetUnstackedBonus(true, s_nAbilityStackingMode);

            {
                uint32_t nAbilityBonusLimit = Globals::AppManager()->m_pServerExoApp->GetAbilityBonusLimit();
                uint32_t nAbilityPenaltyLimit = Globals::AppManager()->m_pServerExoApp->GetAbilityPenaltyLimit();
                nEffectBonus = std::min(nEffectBonus, nAbilityBonusLimit);
                nEffectPenalty = std::min(nEffectPenalty, nAbilityPenaltyLimit);
            }
            return nEffectBonus - nEffectPenalty;

        case Constants::EffectBonusType::Skill:
            for (int i = thisPtr->m_pStats->m_nSkillBonusPtr; i < thisPtr->m_appliedEffects.num; i++)
            {
                auto nType = thisPtr->m_appliedEffects.element[i]->m_nType;
                if (nType < Constants::EffectTrueType::SkillIncrease || nType > Constants::EffectTrueType::SkillDecrease)
                    break;

                auto pEffect = thisPtr->m_appliedEffects.element[i];
                uint8_t nEffectSkill = pEffect->GetInteger(0);

                if ((nEffectSkill == nSkill || nEffectSkill == static_cast<uint8_t>(~0u))
                    && CheckRaceAlignment(nRace, pEffect->GetInteger(2),
                                          nAlignLaw, pEffect->GetInteger(3),
                                          nAlignGood, pEffect->GetInteger(4))
                    )
                {
                    auto nEffectStrength = pEffect->GetInteger(1);

                    if (pEffect->m_nType == Constants::EffectTrueType::SkillIncrease)
                    {
                        if (auto* pItem = Globals::AppManager()->m_pServerExoApp->GetItemByGameObjectID(pEffect->m_oidCreator))
                            AddPositiveEffectOID(pItem->m_idSelf, nEffectStrength);
                        else
                            AddPositiveEffect(pEffect->m_nSpellId, nEffectStrength);
                    }
                    else if (pEffect->m_nType == Constants::EffectTrueType::SkillDecrease)
                    {
                        if (auto* pItem = Globals::AppManager()->m_pServerExoApp->GetItemByGameObjectID(pEffect->m_oidCreator))
                            AddNegativeEffectOID(pItem->m_idSelf, nEffectStrength);
                        else
                            AddNegativeEffect(pEffect->m_nSpellId, nEffectStrength);
                    }
                }
            }

            nEffectBonus = !s_nSkillStackingMode ? GetStackedBonus(false) : GetUnstackedBonus(false, s_nSkillStackingMode);
            nEffectPenalty = (s_bAlwaysStackPenalties || !s_nSkillStackingMode) ? GetStackedBonus(true) : GetUnstackedBonus(true, s_nSkillStackingMode);

            {
                uint32_t nSkillBonusLimit = Globals::AppManager()->m_pServerExoApp->GetSkillBonusLimit();
                nEffectBonus = std::min(nEffectBonus, nSkillBonusLimit);
                nEffectPenalty = std::min(nEffectPenalty, nSkillBonusLimit);
            }

            return nEffectBonus - nEffectPenalty;
    }

    return 0;
}


inline bool CheckRaceAlignment(uint16_t nRace, uint16_t nEffectRace, uint8_t nAlignLaw,
    uint8_t nEffectAlignLaw, uint8_t nAlignGood, uint8_t nEffectAlignGood)
{
    return (nEffectRace == nRace || nEffectRace == Constants::RacialType::All)
        && (nEffectAlignLaw == 0 || nEffectAlignLaw == nAlignLaw)
        && (nEffectAlignGood == 0 || nEffectAlignGood == nAlignGood);
}

void AddPositiveEffect(uint32_t nSpellId, uint32_t nEffectStrength)
{
    if (nSpellId != ~0u)
    {
        int nOffset;
        for (nOffset = 0; nOffset < MAX_STACKED_EFFECTS && g_EffectsStrength[nOffset] != ~0u; nOffset++)
        {
            if (g_EffectsSpellID[nOffset] == nSpellId)
            {
                if (g_EffectsStrength[nOffset] < nEffectStrength)
                    g_EffectsStrength[nOffset] = nEffectStrength;
                return;
            }
        }
        while (nOffset < MAX_STACKED_EFFECTS)
        {
            if (g_EffectsStrength[nOffset] == ~0u)
                break;
            nOffset++;
        }
        if (nOffset >= MAX_STACKED_EFFECTS)
            return;
        g_EffectsSpellID[nOffset] = nSpellId;
        g_EffectsStrength[nOffset] = nEffectStrength;
    }
}

void AddPositiveEffectOID(uint32_t nObjectId, uint32_t nEffectStrength)
{
    if (nObjectId != ~0u)
    {
        int nOffset;
        for (nOffset = 0; nOffset < MAX_STACKED_EFFECTS && g_EffectsStrength[nOffset] != ~0u; nOffset++)
        {
            if (g_EffectsObjectID[nOffset] == nObjectId)
            {
                if (g_EffectsStrength[nOffset] < nEffectStrength)
                    g_EffectsStrength[nOffset] = nEffectStrength;
                return;
            }
        }
        while (nOffset < MAX_STACKED_EFFECTS)
        {
            if (g_EffectsStrength[nOffset] == ~0u)
                break;
            nOffset++;
        }
        if (nOffset >= MAX_STACKED_EFFECTS)
            return;
        g_EffectsObjectID[nOffset] = nObjectId;
        g_EffectsStrength[nOffset] = nEffectStrength;
    }
}

void AddNegativeEffect(uint32_t nSpellId, uint32_t nEffectStrength)
{
    if (nSpellId != ~0u)
    {
        int nOffset;
        for (nOffset = 0; nOffset < MAX_STACKED_EFFECTS && g_EffectsStrength2[nOffset] != ~0u; nOffset++)
        {
            if (g_EffectsSpellID2[nOffset] == nSpellId)
            {
                if (g_EffectsStrength2[nOffset] < nEffectStrength)
                    g_EffectsStrength2[nOffset] = nEffectStrength;
                return;
            }
        }
        while (nOffset < MAX_STACKED_EFFECTS)
        {
            if (g_EffectsStrength2[nOffset] == ~0u)
                break;
            nOffset++;
        }
        if (nOffset >= MAX_STACKED_EFFECTS)
            return;
        g_EffectsSpellID2[nOffset] = nSpellId;
        g_EffectsStrength2[nOffset] = nEffectStrength;
    }
}

void AddNegativeEffectOID(uint32_t nObjectId, uint32_t nEffectStrength)
{
    if (nObjectId != ~0u)
    {
        int nOffset;
        for (nOffset = 0; nOffset < MAX_STACKED_EFFECTS && g_EffectsStrength2[nOffset] != ~0u; nOffset++)
        {
            if (g_EffectsObjectID2[nOffset] == nObjectId)
            {
                if (g_EffectsStrength2[nOffset] < nEffectStrength)
                    g_EffectsStrength2[nOffset] = nEffectStrength;
                return;
            }
        }
        while (nOffset < MAX_STACKED_EFFECTS)
        {
            if (g_EffectsStrength2[nOffset] == ~0u)
                break;
            nOffset++;
        }
        if (nOffset >= MAX_STACKED_EFFECTS)
            return;
        g_EffectsObjectID2[nOffset] = nObjectId;
        g_EffectsStrength2[nOffset] = nEffectStrength;
    }
}

inline uint32_t GetStackedBonus(bool negative)
{
    uint32_t nBonus = 0;
    if (!negative)
        for (int i = 0; i < MAX_STACKED_EFFECTS && g_EffectsStrength[i] != ~0u; i++)
            nBonus += g_EffectsStrength[i];
    else
        for (int i = 0; i < MAX_STACKED_EFFECTS && g_EffectsStrength2[i] != ~0u; i++)
            nBonus += g_EffectsStrength2[i];
    return nBonus;
}

inline uint32_t GetUnstackedBonus(bool negative, int mode)
{
    switch (mode)
    {
        default:
        case NostackMode::NoStacking: //No stacking at all
        {
            uint32_t nMax = 0;
            if (!negative)
                for (int i = 0; i < MAX_STACKED_EFFECTS && g_EffectsStrength[i] != ~0u; i++)
                    nMax = std::max(nMax, g_EffectsStrength[i]);
            else
                for (int i = 0; i < MAX_STACKED_EFFECTS && g_EffectsStrength2[i] != ~0u; i++)
                    nMax = std::max(nMax, g_EffectsStrength2[i]);
            return nMax;
        }
        case NostackMode::AllowOneSpell: //Allow highest spell bonus to stack with highest item bonus
        {
            uint32_t nMaxItemEffect = 0, nMaxSpellEffect = 0;
            if (!negative)
            {
                for (int i = 0; i < MAX_STACKED_EFFECTS && g_EffectsStrength[i] != ~0u; i++)
                    if (g_EffectsSpellID[i] != ~0u)
                        nMaxSpellEffect = std::max(nMaxSpellEffect, g_EffectsStrength[i]);
                    else
                        nMaxItemEffect = std::max(nMaxItemEffect, g_EffectsStrength[i]);
            }
            else
            {
                for (int i = 0; i < MAX_STACKED_EFFECTS && g_EffectsStrength2[i] != ~0u; i++)
                    if (g_EffectsSpellID2[i] != ~0u)
                        nMaxSpellEffect = std::max(nMaxSpellEffect, g_EffectsStrength2[i]);
                    else
                        nMaxItemEffect = std::max(nMaxItemEffect, g_EffectsStrength2[i]);
            }
            return nMaxItemEffect + nMaxSpellEffect;
        }
        case NostackMode::AllowAllSpells: //Allow all spell bonuses to stack with highest item bonus
        {
            uint32_t nMaxItemEffect = 0, nSumSpellEffect = 0;
            if (!negative)
            {

                for (int i = 0; i < MAX_STACKED_EFFECTS && g_EffectsStrength[i] != ~0u; i++)
                    if (g_EffectsSpellID[i] != ~0u)
                        nSumSpellEffect += g_EffectsStrength[i];
                    else
                        nMaxItemEffect = std::max(nMaxItemEffect, g_EffectsStrength[i]);
            }
            else
            {
                for (int i = 0; i < MAX_STACKED_EFFECTS && g_EffectsStrength2[i] != ~0u; i++)
                    if (g_EffectsSpellID2[i] != ~0u)
                        nSumSpellEffect += g_EffectsStrength2[i];
                    else
                        nMaxItemEffect = std::max(nMaxItemEffect, g_EffectsStrength2[i]);
            }
            return nMaxItemEffect + nSumSpellEffect;
        }
        case NostackMode::CustomTypes: //Use per-spell defined types
        {
            std::fill_n(g_nMaxValues, NostackType::Max + 1, 0);

            for (int i = 0; i < MAX_STACKED_EFFECTS; i++)
            {
                uint32_t nEffectValue = negative ? g_EffectsStrength2[i] : g_EffectsStrength[i];
                if (nEffectValue == ~0u)
                    break;
                uint32_t nSpellId = negative ? g_EffectsSpellID2[i] : g_EffectsSpellID[i];
                int nBonusType = g_nItemDefaultType;
                if (nSpellId != ~0u)
                    nBonusType = nSpellId >= g_nSpellBonusTypes.size() ? g_nSpellDefaultType : g_nSpellBonusTypes[nSpellId];
                if (nBonusType == 1)
                    g_nMaxValues[nBonusType] += nEffectValue;
                else
                    g_nMaxValues[nBonusType] = std::max(g_nMaxValues[nBonusType], nEffectValue);
            }

            uint32_t nSum = 0;
            for (int i = 0; i < NostackType::Max + 1; i++)
                nSum += g_nMaxValues[i];
            return nSum;
        }
    }

    return 0;
}

ArgumentStack BonusStacking::SetSpellBonusType(ArgumentStack&& args)
{
    if (!g_nSpellBonusTypes.size())
        g_nSpellBonusTypes.resize(Globals::Rules()->m_pSpellArray->m_nNumSpells, g_nSpellDefaultType);

    const auto nSpellId = Services::Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(nSpellId >= 0);
    ASSERT_OR_THROW(nSpellId < Globals::Rules()->m_pSpellArray->m_nNumSpells);
    const auto nBonusType = Services::Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(nBonusType >= 0);
    ASSERT_OR_THROW(nBonusType <= NostackType::Max);

    g_nSpellBonusTypes[nSpellId] = nBonusType;
    return Services::Events::Arguments();
}

}
