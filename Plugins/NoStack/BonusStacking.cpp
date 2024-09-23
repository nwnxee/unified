#include "nwnx.hpp"

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

namespace NostackMode
{
typedef enum
{
    Disabled,
    NoStacking,
    AllowOneSpell,
    AllowAllSpells,
    CustomTypes
} TYPE;
}

namespace NostackType
{
typedef enum
{
    Enhancement,
    Circumstance,
    Competence,
    Insight,
    Luck,
    Morale,
    Profane,
    Resistance,
    Sacred,
    Max = 20,
} TYPE;
}

using namespace NWNXLib;
using namespace NWNXLib::API;

static int s_nAbilityStackingMode = NostackMode::Disabled;
static int s_nSkillStackingMode = NostackMode::Disabled;
static int s_nSavingThrowStackingMode = NostackMode::Disabled;
static int s_nAttackBonusStackingMode = NostackMode::Disabled;
static bool s_bAlwaysStackPenalties = false;
static bool s_bSeparateInvalidOidEffects = false;
static bool s_bIgnoreSupernaturalInnate = false;
static std::vector<int32_t> s_nSpellBonusTypes;
static int32_t s_nSpellDefaultType = NostackType::Circumstance;
static int32_t s_nItemDefaultType = NostackType::Enhancement;

static Hooks::Hook s_GetTotalEffectBonusHook = nullptr;

struct EffectData
{
    OBJECT_ID objectId = Constants::OBJECT_INVALID;
    uint32_t spellId = ~0;
    int32_t strength = 0;
    uint32_t subType = 0;
};

constexpr auto MAX_DAMAGE_FLAGS = 13;

static std::vector<EffectData> s_positiveEffects;
static std::vector<EffectData> s_negativeEffects;
static int32_t s_nMaxValues[NostackType::Max + 1];

void CNWSCreatureStats__UpdateCombatInformation(CNWSCreatureStats*);
int32_t CNWSCreature__GetTotalEffectBonus(CNWSCreature*, uint8_t, CNWSObject*, BOOL, BOOL, uint8_t, uint8_t, uint8_t, uint8_t, BOOL);


void BonusStacking() __attribute__((constructor));
void BonusStacking()
{
    s_nAbilityStackingMode = std::clamp(Config::Get<int>("ABILITY", 0), 0, static_cast<int>(NostackMode::CustomTypes));
    s_nSkillStackingMode = std::clamp(Config::Get<int>("SKILL", 0), 0, static_cast<int>(NostackMode::CustomTypes));
    s_nSavingThrowStackingMode = std::clamp(Config::Get<int>("SAVINGTHROW", 0), 0, static_cast<int>(NostackMode::CustomTypes));
    s_nAttackBonusStackingMode = std::clamp(Config::Get<int>("ATTACKBONUS", 0), 0, static_cast<int>(NostackMode::CustomTypes));

    if (s_nAbilityStackingMode || s_nSkillStackingMode || s_nSavingThrowStackingMode || s_nAttackBonusStackingMode)
    {
        LOG_INFO("Property effect stacking modes -- Ability scores: %d | Skill bonuses: %d | Saving throw bonuses: %d"
            " | Attack bonuses: %d", s_nAbilityStackingMode, s_nSkillStackingMode, s_nSavingThrowStackingMode, s_nAttackBonusStackingMode);

        s_nSpellDefaultType = std::clamp(Config::Get<int>("SPELL_DEFAULT_TYPE", NostackType::Circumstance), 0, static_cast<int32_t>(NostackType::Max));
        s_nItemDefaultType = std::clamp(Config::Get<int>("ITEM_DEFAULT_TYPE", NostackType::Enhancement), 0, static_cast<int32_t>(NostackType::Max));
        s_bAlwaysStackPenalties = Config::Get<bool>("ALWAYS_STACK_PENALTIES", false);
        s_bSeparateInvalidOidEffects = Config::Get<bool>("SEPARATE_INVALID_OID_EFFECTS", false);
        s_bIgnoreSupernaturalInnate = Config::Get<bool>("IGNORE_SUPERNATURAL_INNATE", false);

        s_GetTotalEffectBonusHook = Hooks::HookFunction(&CNWSCreature::GetTotalEffectBonus, &CNWSCreature__GetTotalEffectBonus, Hooks::Order::Final);

        s_positiveEffects.reserve(50);
        s_negativeEffects.reserve(50);
    }
}

inline bool CheckRaceAlignment(uint16_t nRace, uint16_t nEffectRace, uint8_t nAlignLaw,
                               uint8_t nEffectAlignLaw, uint8_t nAlignGood, uint8_t nEffectAlignGood);
inline int32_t GetUnstackedBonus(bool negative = false, int mode = 0, bool bSupernaturalInnate = false);

inline bool IsSupernaturalAndInnate(uint32_t subType)
{
    constexpr uint32_t SupernaturalInnateMask = Constants::EffectSubType::Supernatural | Constants::EffectDurationType::Innate;
    return (subType & SupernaturalInnateMask) == SupernaturalInnateMask;
}

void AddEffect(EffectData&& effectData, bool negative)
{
    if (s_bIgnoreSupernaturalInnate && IsSupernaturalAndInnate(effectData.subType))
    {
        auto &effectList = negative ? s_negativeEffects : s_positiveEffects;
        effectList.emplace_back(effectData);
        return;
    }

    auto& effectList = negative ? s_negativeEffects : s_positiveEffects;
    if(effectData.spellId == ~0u)
    {
        if (effectData.objectId == Constants::OBJECT_INVALID && s_bSeparateInvalidOidEffects)
        {
            effectList.emplace_back(EffectData{ effectData.objectId, ~0u, effectData.strength });
        }
        else
        {
            auto effect = std::find_if(effectList.begin(), effectList.end(), [&](EffectData& data) { return data.objectId == effectData.objectId; });
            if (effect != effectList.end())
                effect->strength = std::max(effectData.strength, effect->strength);
            else
                effectList.emplace_back(EffectData{ effectData.objectId, ~0u, effectData.strength });
        }
    }
    else
    {
        auto effect = std::find_if(effectList.begin(), effectList.end(), [&](EffectData& data) { return data.spellId == effectData.spellId; });
        if (effect != effectList.end())
            effect->strength = std::max(effectData.strength, effect->strength);
        else
            effectList.emplace_back(EffectData{ ~0u, effectData.spellId, effectData.strength });
    }
}

int32_t CNWSCreature__GetTotalEffectBonus(CNWSCreature* thisPtr, uint8_t nEffectBonusType, CNWSObject* pObject, BOOL bElementalDamage,
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
    uint32_t nEffectBonus = 0, nEffectPenalty = 0, nSupernaturalInnateBonus = 0, nSupernaturalInnatePenalty = 0;

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

    s_positiveEffects.resize(0);
    s_negativeEffects.resize(0);

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

                    if (nEffectWeaponType == 0 || nEffectBonusType != Constants::EffectBonusType::TouchAttack)
                    {
                        if (pEffect->m_nType == Constants::EffectTrueType::AttackIncrease)
                            AddEffect(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength, pEffect->m_nSubType }, false);
                        else if (pEffect->m_nType == Constants::EffectTrueType::AttackDecrease)
                            AddEffect(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength, pEffect->m_nSubType }, true);
                    }
                }
            }

            {
                nEffectBonus = GetUnstackedBonus(false, s_nAttackBonusStackingMode);
                nEffectPenalty = GetUnstackedBonus(true, s_bAlwaysStackPenalties ? NostackMode::Disabled : s_nAttackBonusStackingMode);

                if (s_bIgnoreSupernaturalInnate)
                {
                    nSupernaturalInnateBonus = GetUnstackedBonus(false, 0, true);
                    nSupernaturalInnatePenalty = GetUnstackedBonus(true, 0, true);
                }

                uint32_t nAttackBonusLimit = Globals::AppManager()->m_pServerExoApp->GetAttackBonusLimit() + nSupernaturalInnateBonus - nSupernaturalInnatePenalty;
                nEffectBonus = std::min(nEffectBonus, nAttackBonusLimit);
                nEffectPenalty = std::min(nEffectPenalty, nAttackBonusLimit);
            }
            return nEffectBonus - nEffectPenalty + nSupernaturalInnateBonus - nSupernaturalInnatePenalty;

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
                        AddEffect(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength, pEffect->m_nSubType }, false);
                    }
                    else if (pEffect->m_nType == Constants::EffectTrueType::SavingThrowDecrease)
                    {
                        AddEffect(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength, pEffect->m_nSubType }, true);
                    }
                }
            }

            nEffectBonus = GetUnstackedBonus(false, s_nSavingThrowStackingMode);
            nEffectPenalty = GetUnstackedBonus(true, s_bAlwaysStackPenalties ? NostackMode::Disabled : s_nSavingThrowStackingMode);

            if (s_bIgnoreSupernaturalInnate)
            {
                nSupernaturalInnateBonus = GetUnstackedBonus(false, 0, true);
                nSupernaturalInnatePenalty = GetUnstackedBonus(true, 0, true);
            }

            {
                uint32_t nSavingThrowBonusLimit = Globals::AppManager()->m_pServerExoApp->GetSavingThrowBonusLimit() + nSupernaturalInnateBonus - nSupernaturalInnatePenalty;
                nEffectBonus = std::min(nEffectBonus, nSavingThrowBonusLimit);
                nEffectPenalty = std::min(nEffectPenalty, nSavingThrowBonusLimit);
            }

            if (thisPtr->m_pStats->HasFeat(Constants::Feat::SacredDefense1))
            {
                int nChampionLevel = thisPtr->m_pStats->GetNumLevelsOfClass(Constants::ClassType::DivineChampion);
                if (nChampionLevel > 1)
                    nEffectBonus += nChampionLevel / 2;
            }

            return nEffectBonus - nEffectPenalty + nSupernaturalInnateBonus - nSupernaturalInnatePenalty;

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
                    AddEffect(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength, pEffect->m_nSubType }, false);
                }
                else if (pEffect->m_nType == Constants::EffectTrueType::AbilityDecrease)
                {
                    AddEffect(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength, pEffect->m_nSubType }, true);
                }
            }

            nEffectBonus = GetUnstackedBonus(false, s_nAbilityStackingMode);
            nEffectPenalty = GetUnstackedBonus(true, s_bAlwaysStackPenalties ? NostackMode::Disabled : s_nAbilityStackingMode);

            if (s_bIgnoreSupernaturalInnate)
            {
                nSupernaturalInnateBonus = GetUnstackedBonus(false, 0, true);
                nSupernaturalInnatePenalty = GetUnstackedBonus(true, 0, true);
            }

            {
                uint32_t nAbilityBonusLimit = Globals::AppManager()->m_pServerExoApp->GetAbilityBonusLimit() + nSupernaturalInnateBonus - nSupernaturalInnatePenalty;
                uint32_t nAbilityPenaltyLimit = Globals::AppManager()->m_pServerExoApp->GetAbilityPenaltyLimit() + nSupernaturalInnateBonus - nSupernaturalInnatePenalty;
                nEffectBonus = std::min(nEffectBonus, nAbilityBonusLimit);
                nEffectPenalty = std::min(nEffectPenalty, nAbilityPenaltyLimit);
            }
            return nEffectBonus - nEffectPenalty + nSupernaturalInnateBonus- nSupernaturalInnatePenalty;

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
                        AddEffect(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength, pEffect->m_nSubType }, false);
                    }
                    else if (pEffect->m_nType == Constants::EffectTrueType::SkillDecrease)
                    {
                        AddEffect(EffectData{ pEffect->m_oidCreator, pEffect->m_nSpellId, nEffectStrength, pEffect->m_nSubType }, true);
                    }
                }
            }

            nEffectBonus =  GetUnstackedBonus(false, s_nSkillStackingMode);
            nEffectPenalty = GetUnstackedBonus(true, s_bAlwaysStackPenalties ? NostackMode::Disabled : s_nSkillStackingMode);

            if (s_bIgnoreSupernaturalInnate)
            {
                nSupernaturalInnateBonus = GetUnstackedBonus(false, 0, true);
                nSupernaturalInnatePenalty = GetUnstackedBonus(true, 0, true);
            }

            {
                uint32_t nSkillBonusLimit = Globals::AppManager()->m_pServerExoApp->GetSkillBonusLimit() + nSupernaturalInnateBonus - nSupernaturalInnatePenalty;
                nEffectBonus = std::min(nEffectBonus, nSkillBonusLimit);
                nEffectPenalty = std::min(nEffectPenalty, nSkillBonusLimit);
            }

            return nEffectBonus - nEffectPenalty + nSupernaturalInnateBonus - nSupernaturalInnatePenalty;
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

inline int32_t GetUnstackedBonus(bool negative, int mode, bool bSupernaturalInnate)
{
    auto &effects = negative ? s_negativeEffects : s_positiveEffects;
    std::vector<EffectData> filteredEffects;

    if (s_bIgnoreSupernaturalInnate)
    {
        std::copy_if(effects.cbegin(), effects.cend(), std::back_inserter(filteredEffects), [bSupernaturalInnate](const EffectData &data)
                     { return bSupernaturalInnate ? IsSupernaturalAndInnate(data.subType) : !IsSupernaturalAndInnate(data.subType); });
        if (bSupernaturalInnate)
        {
            return std::accumulate(filteredEffects.cbegin(), filteredEffects.cend(), 0, [](uint32_t acc, const EffectData &data)
                                   { return acc + data.strength; });
        }
    }
    else
    {
        filteredEffects = effects;
    }

    auto begin = filteredEffects.cbegin();
    auto end = filteredEffects.cend();

    int32_t itemBonus = 0, spellBonus = 0;

    switch (mode)
    {
        default:
        case NostackMode::Disabled:
        {
            return std::accumulate(begin, end, 0, [](uint32_t acc, const EffectData& data) { return acc + data.strength; });
        }
        case NostackMode::NoStacking: //No stacking at all
        {
            int32_t bonus = 0;
            std::for_each(begin, end, [&](const EffectData& data) { bonus = std::max(bonus, data.strength); });
            return bonus;
        }
        case NostackMode::AllowOneSpell: //Allow highest spell bonus to stack with highest item bonus
        {
            std::for_each(begin, end, [&](const EffectData& data)
            {
                if (data.spellId != ~0u)
                    spellBonus = std::max(data.strength, spellBonus);
                else
                    itemBonus = std::max(data.strength, itemBonus);
            });

            return itemBonus + spellBonus;
        }
        case NostackMode::AllowAllSpells: //Allow all spell bonuses to stack with highest item bonus
        {
            std::for_each(begin, end, [&](const EffectData& data)
            {
                if (data.spellId != ~0u)
                    spellBonus += data.strength;
                else
                    itemBonus = std::max(data.strength, itemBonus);
            });

            return itemBonus + spellBonus;
        }
        case NostackMode::CustomTypes: //Use per-spell defined types
        {
            std::fill_n(s_nMaxValues, NostackType::Max + 1, 0);
            std::for_each(begin, end, [&](const EffectData& data)
            {
                int nBonusType = s_nItemDefaultType;
                if (data.spellId != ~0u)
                    nBonusType = data.spellId >= s_nSpellBonusTypes.size() ? s_nSpellDefaultType : s_nSpellBonusTypes[data.spellId];
                if (nBonusType == NostackType::Circumstance)
                    s_nMaxValues[nBonusType] += data.strength;
                else
                    s_nMaxValues[nBonusType] = std::max(s_nMaxValues[nBonusType], data.strength);
            });

            return std::accumulate(s_nMaxValues, s_nMaxValues + NostackType::Max + 1, 0);
        }
    }

    return 0;
}

NWNX_EXPORT ArgumentStack SetSpellBonusType(ArgumentStack&& args)
{
    if (!s_nSpellBonusTypes.size())
        s_nSpellBonusTypes.resize(Globals::Rules()->m_pSpellArray->m_nNumSpells, s_nSpellDefaultType);

    const auto nSpellId = args.extract<int32_t>();
      ASSERT_OR_THROW(nSpellId >= 0);
      ASSERT_OR_THROW(nSpellId < Globals::Rules()->m_pSpellArray->m_nNumSpells);
    const auto nBonusType = args.extract<int32_t>();
      ASSERT_OR_THROW(nBonusType >= 0);
      ASSERT_OR_THROW(nBonusType <= NostackType::Max);

    s_nSpellBonusTypes[nSpellId] = nBonusType;

    return {};
}
