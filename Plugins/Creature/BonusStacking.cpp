#include "Creature.hpp"
#include "Utils.hpp"
#include "API/CAppManager.hpp"
#include "API/CCombatInformation.hpp"
#include "API/CCombatInformationNode.hpp"
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

#include <algorithm>
#include <numeric>

namespace Creature
{

using namespace NWNXLib;
using namespace NWNXLib::API;

int BonusStacking::s_nAbilityStackingMode = NostackMode::Disabled;
int BonusStacking::s_nSkillStackingMode = NostackMode::Disabled;
int BonusStacking::s_nSavingThrowStackingMode = NostackMode::Disabled;
int BonusStacking::s_nAttackBonusStackingMode = NostackMode::Disabled;
bool BonusStacking::s_bAlwaysStackPenalties = false;
static std::vector<int32_t> g_nSpellBonusTypes;
static int32_t g_nSpellDefaultType = NostackType::Circumstance;
static int32_t g_nItemDefaultType = NostackType::Enhancement;

static Hooks::Hook s_GetTotalEffectBonusHook = nullptr;
static Hooks::Hook s_UpdateCombatInformation = nullptr;

struct EffectData
{
    OBJECT_ID objectId = Constants::OBJECT_INVALID;
    uint32_t spellId = ~0;
    int32_t strength = 0;
    int32_t operator+(const int32_t& rhs)
    {
        return strength + rhs;
    }
};

constexpr auto MAX_DAMAGE_FLAGS = 13;

static std::vector<EffectData> g_positiveEffects;
static std::vector<EffectData> g_negativeEffects;
static int32_t g_nMaxValues[NostackType::Max + 1];

void BonusStacking::Init(Services::ProxyServiceList*)
{
    s_nAbilityStackingMode = std::clamp(Config::Get<int>("NOSTACK_ABILITY", 0), 0, static_cast<int>(NostackMode::CustomTypes));
    s_nSkillStackingMode = std::clamp(Config::Get<int>("NOSTACK_SKILL", 0), 0, static_cast<int>(NostackMode::CustomTypes));
    s_nSavingThrowStackingMode = std::clamp(Config::Get<int>("NOSTACK_SAVINGTHROW", 0), 0, static_cast<int>(NostackMode::CustomTypes));
    s_nAttackBonusStackingMode = std::clamp(Config::Get<int>("NOSTACK_ATTACKBONUS", 0), 0, static_cast<int>(NostackMode::CustomTypes));

    if (s_nAbilityStackingMode || s_nSkillStackingMode || s_nSavingThrowStackingMode || s_nAttackBonusStackingMode)
    {
        LOG_INFO("Property effect stacking modes -- Ability scores: %d | Skill bonuses: %d | Saving throw bonuses: %d"
            " | Attack bonuses: %d", s_nAbilityStackingMode, s_nSkillStackingMode, s_nSavingThrowStackingMode, s_nAttackBonusStackingMode);

        g_nSpellDefaultType = std::clamp(Config::Get<int>("NOSTACK_SPELL_DEFAULT_TYPE", NostackType::Circumstance), 0, static_cast<int32_t>(NostackType::Max));
        g_nItemDefaultType = std::clamp(Config::Get<int>("NOSTACK_ITEM_DEFAULT_TYPE", NostackType::Enhancement), 0, static_cast<int32_t>(NostackType::Max));
        s_bAlwaysStackPenalties = Config::Get<bool>("NOSTACK_ALWAYS_STACK_PENALTIES", false);

        s_GetTotalEffectBonusHook = Hooks::HookFunction(Functions::_ZN12CNWSCreature19GetTotalEffectBonusEhP10CNWSObjectiihhhhi, (void*)&CNWSCreature__GetTotalEffectBonus, Hooks::Order::Final);
        //s_UpdateCombatInformation = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats23UpdateCombatInformationEv, (void*)&CNWSCreatureStats__UpdateCombatInformation, Hooks::Order::SharedHook);

        Events::RegisterEvent(PLUGIN_NAME, "SetSpellBonusType", [](ArgumentStack&& args) { return BonusStacking::SetSpellBonusType(std::move(args)); });
    }

    g_positiveEffects.reserve(50);
    g_negativeEffects.reserve(50);
}

inline bool CheckRaceAlignment(uint16_t nRace, uint16_t nEffectRace, uint8_t nAlignLaw,
                               uint8_t nEffectAlignLaw, uint8_t nAlignGood, uint8_t nEffectAlignGood);
inline int32_t GetUnstackedBonus(bool negative = false, int mode = 0);

int32_t BonusStacking::CNWSCreature__GetTotalEffectBonus(CNWSCreature* thisPtr, uint8_t nEffectBonusType, CNWSObject* pObject, BOOL bElementalDamage,
    BOOL bForceMax, uint8_t nSaveType, uint8_t nSpecificType, uint8_t nSkill, uint8_t nAbilityScore, BOOL bOffHand)
{
    if (nEffectBonusType == Constants::EffectBonusType::Damage
        || ((nEffectBonusType == Constants::EffectBonusType::Attack || nEffectBonusType == Constants::EffectBonusType::TouchAttack) && !s_nAttackBonusStackingMode)
        || (nEffectBonusType == Constants::EffectBonusType::SavingThrow && !s_nSavingThrowStackingMode)
        || (nEffectBonusType == Constants::EffectBonusType::Ability && !s_nAbilityStackingMode)
        || (nEffectBonusType == Constants::EffectBonusType::Skill && !s_nSkillStackingMode)
        )
    {
        return s_GetTotalEffectBonusHook->CallOriginal<int32_t>(thisPtr, nEffectBonusType, pObject,
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

    g_positiveEffects.resize(0);
    g_negativeEffects.resize(0);

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
                    int32_t nEffectStrength = pEffect->GetInteger(0);

                    if (pEffect->m_nType == Constants::EffectTrueType::AttackIncrease)
                    {
                        if (nEffectWeaponType == 0 || nEffectBonusType != Constants::EffectBonusType::TouchAttack)
                        {
                            g_positiveEffects.emplace_back(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength });
                        }
                    }
                    else if (pEffect->m_nType == Constants::EffectTrueType::AttackDecrease)
                    {
                        if (nEffectWeaponType == 0 || nEffectBonusType != Constants::EffectBonusType::TouchAttack)
                        {
                            g_negativeEffects.emplace_back(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength });
                        }
                    }
                }
            }

            {
                nEffectBonus = GetUnstackedBonus(false, s_nAttackBonusStackingMode);
                nEffectPenalty = GetUnstackedBonus(true, s_bAlwaysStackPenalties ? NostackMode::Disabled : s_nAttackBonusStackingMode);

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
                    int32_t nEffectStrength = pEffect->GetInteger(0);

                    if (pEffect->m_nType == Constants::EffectTrueType::SavingThrowIncrease)
                    {
                        g_positiveEffects.emplace_back(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength });
                    }
                    else if (pEffect->m_nType == Constants::EffectTrueType::SavingThrowDecrease)
                    {
                        g_negativeEffects.emplace_back(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength });
                    }
                }
            }

            nEffectBonus = GetUnstackedBonus(false, s_nSavingThrowStackingMode);
            nEffectPenalty = GetUnstackedBonus(true, s_bAlwaysStackPenalties ? NostackMode::Disabled : s_nSavingThrowStackingMode);

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

                int32_t nEffectStrength = pEffect->GetInteger(1);

                if (pEffect->m_nType == Constants::EffectTrueType::AbilityIncrease)
                {
                    g_positiveEffects.emplace_back(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength });
                }
                else if (pEffect->m_nType == Constants::EffectTrueType::AbilityDecrease)
                {
                    g_negativeEffects.emplace_back(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength });
                }
            }

            nEffectBonus = GetUnstackedBonus(false, s_nAbilityStackingMode);
            nEffectPenalty = GetUnstackedBonus(true, s_bAlwaysStackPenalties ? NostackMode::Disabled : s_nAbilityStackingMode);

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
                        g_positiveEffects.emplace_back(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength });
                    }
                    else if (pEffect->m_nType == Constants::EffectTrueType::SkillDecrease)
                    {
                        g_negativeEffects.emplace_back(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength });
                    }
                }
            }

            nEffectBonus =  GetUnstackedBonus(false, s_nSkillStackingMode);
            nEffectPenalty = GetUnstackedBonus(true, s_bAlwaysStackPenalties ? NostackMode::Disabled : s_nSkillStackingMode);

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

inline int32_t GetUnstackedBonus(bool negative, int mode)
{
    switch (mode)
    {
        default:
        case NostackMode::Disabled:
        {
            uint32_t bonus = 0;
            if (!negative)
                std::for_each(g_positiveEffects.cbegin(), g_positiveEffects.cend(), [&bonus](const EffectData& data) { bonus += data.strength; });
            else
                std::for_each(g_negativeEffects.cbegin(), g_negativeEffects.cend(), [&bonus](const EffectData& data) { bonus += data.strength; });
            return bonus;
        }
        case NostackMode::NoStacking: //No stacking at all
        {
            int32_t bonus = 0;

            auto getMaxEffects = [&](const EffectData& data) { bonus += data.strength; };

            if (!negative)
                std::for_each(g_positiveEffects.cbegin(), g_positiveEffects.cend(), getMaxEffects);
            else
                std::for_each(g_negativeEffects.cbegin(), g_negativeEffects.cend(), getMaxEffects);

            return bonus;
        }
        case NostackMode::AllowOneSpell: //Allow highest spell bonus to stack with highest item bonus
        {
            int32_t nMaxItemEffect = 0, nMaxSpellEffect = 0;
            auto getMaxEffects = [&](const EffectData& data)
            {
                if (data.spellId != ~0u)
                    nMaxSpellEffect = std::max(data.strength, nMaxSpellEffect);
                else
                    nMaxItemEffect = std::max(data.strength, nMaxItemEffect);
            };

            if (!negative)
                std::for_each(g_positiveEffects.cbegin(), g_positiveEffects.cend(), getMaxEffects);
            else
                std::for_each(g_negativeEffects.cbegin(), g_negativeEffects.cend(), getMaxEffects);

            return nMaxItemEffect + nMaxSpellEffect;
        }
        case NostackMode::AllowAllSpells: //Allow all spell bonuses to stack with highest item bonus
        {
            int32_t nMaxItemEffect = 0, nSumSpellEffect = 0;
            auto getEffectBonuses = [&](const EffectData& data)
            {
                if (data.spellId != ~0u)
                    nSumSpellEffect += data.strength;
                else
                    nMaxItemEffect = std::max(data.strength, nMaxItemEffect);
            };

            if (!negative)
                std::for_each(g_positiveEffects.cbegin(), g_positiveEffects.cend(), getEffectBonuses);
            else
                std::for_each(g_negativeEffects.cbegin(), g_negativeEffects.cend(), getEffectBonuses);

            return nMaxItemEffect + nSumSpellEffect;
        }
        case NostackMode::CustomTypes: //Use per-spell defined types
        {
            std::fill_n(g_nMaxValues, NostackType::Max + 1, 0);
            auto getEffectBonuses = [&](const EffectData& data)
            {
                int nBonusType = g_nItemDefaultType;
                if (data.spellId != ~0u)
                    nBonusType = data.spellId >= g_nSpellBonusTypes.size() ? g_nSpellDefaultType : g_nSpellBonusTypes[data.spellId];
                if (nBonusType == 1)
                    g_nMaxValues[nBonusType] += data.strength;
                else
                    g_nMaxValues[nBonusType] = std::max(g_nMaxValues[nBonusType], data.strength);
            };

            if (!negative)
                std::for_each(g_positiveEffects.cbegin(), g_positiveEffects.cend(), getEffectBonuses);
            else
                std::for_each(g_negativeEffects.cbegin(), g_negativeEffects.cend(), getEffectBonuses);

            return std::accumulate(g_nMaxValues, g_nMaxValues + NostackType::Max + 1, 0);
        }
    }

    return 0;
}

ArgumentStack BonusStacking::SetSpellBonusType(ArgumentStack&& args)
{
    if (!g_nSpellBonusTypes.size())
        g_nSpellBonusTypes.resize(Globals::Rules()->m_pSpellArray->m_nNumSpells, g_nSpellDefaultType);

    const auto nSpellId = Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(nSpellId >= 0);
    ASSERT_OR_THROW(nSpellId < Globals::Rules()->m_pSpellArray->m_nNumSpells);
    const auto nBonusType = Events::ExtractArgument<int32_t>(args);
    ASSERT_OR_THROW(nBonusType >= 0);
    ASSERT_OR_THROW(nBonusType <= NostackType::Max);

    g_nSpellBonusTypes[nSpellId] = nBonusType;
    return Events::Arguments();
}

void BonusStacking::CNWSCreatureStats__UpdateCombatInformation(CNWSCreatureStats* thisPtr)
{
    s_UpdateCombatInformation->CallOriginal<void>(thisPtr);

    if (!thisPtr->m_pCombatInformation || thisPtr->m_pCombatInformation->m_pAttackList.num < 2)
        return;

    auto* pCurrentAttack = thisPtr->m_pBaseCreature->m_pcCombatRound->GetAttack(thisPtr->m_pBaseCreature->m_pcCombatRound->m_nCurrentAttack);
    //auto nSavedAttackType = pCurrentAttack->m_nWeaponAttackType;
    auto nAttackType = 0;

    while (thisPtr->m_pCombatInformation->m_pAttackList.num < 6)
        thisPtr->m_pCombatInformation->m_pAttackList.Add(new CCombatInformationNode());

    for (int i = 1; i < 3; i++)
    {
        nAttackType = i;
        if (i > 5)
            nAttackType++;
        pCurrentAttack->m_nWeaponAttackType = nAttackType;

        thisPtr->m_pCombatInformation->m_pAttackList.element[i]->m_nModifier = thisPtr->m_pBaseCreature->GetTotalEffectBonus(1, nullptr, 0, 0, 0, 0, 0, 0, 0);
        thisPtr->m_pCombatInformation->m_pAttackList.element[i]->m_nVersusRace = Constants::RacialType::All;
        thisPtr->m_pCombatInformation->m_pAttackList.element[i]->m_nVersusAlignGoodEvil = 0;
        thisPtr->m_pCombatInformation->m_pAttackList.element[i]->m_nVersusAlignLawChaos = 0;
        thisPtr->m_pCombatInformation->m_pAttackList.element[i]->m_nWeaponWield = nAttackType;
        thisPtr->m_pCombatInformation->m_pAttackList.element[i]->m_nModifierType = Constants::EffectTrueType::AttackIncrease;

        thisPtr->m_pCombatInformation->m_pAttackList.num = i;
    }

}

}
