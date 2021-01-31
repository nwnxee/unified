#include "Creature.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerInfo.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CNWSFaction.hpp"
#include "API/CNWSStats_Spell.hpp"
#include "API/CNWSStats_SpellLikeAbility.hpp"
#include "API/CExoArrayList.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWClass.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWSModule.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CFactionManager.hpp"
#include "API/CResStruct.hpp"
#include "API/CResGFF.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/C2DA.hpp"
#include "API/CNWSBarter.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CEffectIconObject.hpp"
#include "API/CNWSArea.hpp"
#include "API/CPathfindInformation.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static Creature::Creature* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Creature::Creature(services);
    return g_plugin;
}


namespace Creature {

bool Creature::s_bAdjustCasterLevel = false;
bool Creature::s_bCasterLevelHooksInitialized = false;
bool Creature::s_bCriticalMultiplierHooksInitialized = false;
bool Creature::s_bCriticalRangeHooksInitialized = false;
bool Creature::s_bResolveAttackRollHookInitialized = false;
static Hooks::Hook s_GetClassLevelHook = nullptr;

Creature::Creature(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    Events::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(AddFeat);
    REGISTER(AddFeatByLevel);
    REGISTER(RemoveFeat);
    REGISTER(GetKnowsFeat);
    REGISTER(GetFeatCountByLevel);
    REGISTER(GetFeatByLevel);
    REGISTER(GetFeatGrantLevel);
    REGISTER(GetFeatCount);
    REGISTER(GetFeatByIndex);
    REGISTER(GetMeetsFeatRequirements);
    REGISTER(GetSpecialAbility);
    REGISTER(GetSpecialAbilityCount);
    REGISTER(AddSpecialAbility);
    REGISTER(RemoveSpecialAbility);
    REGISTER(SetSpecialAbility);
    REGISTER(GetClassByLevel);
    REGISTER(SetBaseAC);
    REGISTER(GetBaseAC);
    REGISTER(SetRawAbilityScore);
    REGISTER(GetRawAbilityScore);
    REGISTER(ModifyRawAbilityScore);
    REGISTER(GetPrePolymorphAbilityScore);
    REGISTER(GetMemorisedSpell);
    REGISTER(GetMemorisedSpellCountByLevel);
    REGISTER(SetMemorisedSpell);
    REGISTER(GetRemainingSpellSlots);
    REGISTER(SetRemainingSpellSlots);
    REGISTER(GetMaxSpellSlots);
    REGISTER(GetKnownSpell);
    REGISTER(GetKnownSpellCount);
    REGISTER(RemoveKnownSpell);
    REGISTER(AddKnownSpell);
    REGISTER(ClearMemorisedKnownSpells);
    REGISTER(ClearMemorisedSpell);
    REGISTER(GetMaxHitPointsByLevel);
    REGISTER(SetMaxHitPointsByLevel);
    REGISTER(SetMovementRate);
    REGISTER(GetMovementRateFactor);
    REGISTER(SetMovementRateFactor);
    REGISTER(SetMovementRateFactorCap);
    REGISTER(SetAlignmentGoodEvil);
    REGISTER(SetAlignmentLawChaos);
    REGISTER(SetDomain);
    REGISTER(SetSpecialization);
    REGISTER(GetSoundset);
    REGISTER(SetSoundset);
    REGISTER(SetSkillRank);
    REGISTER(SetClassByPosition);
    REGISTER(SetLevelByPosition);
    REGISTER(SetBaseAttackBonus);
    REGISTER(GetAttacksPerRound);
    REGISTER(SetGender);
    REGISTER(RestoreFeats);
    REGISTER(RestoreSpecialAbilities);
    REGISTER(RestoreSpells);
    REGISTER(RestoreItems);
    REGISTER(SetSize);
    REGISTER(GetSkillPointsRemaining);
    REGISTER(SetSkillPointsRemaining);
    REGISTER(SetRacialType);
    REGISTER(GetMovementType);
    REGISTER(SetWalkRateCap);
    REGISTER(SetGold);
    REGISTER(SetCorpseDecayTime);
    REGISTER(GetBaseSavingThrow);
    REGISTER(SetBaseSavingThrow);
    REGISTER(LevelUp);
    REGISTER(LevelDown);
    REGISTER(SetChallengeRating);
    REGISTER(GetAttackBonus);
    REGISTER(GetHighestLevelOfFeat);
    REGISTER(GetFeatRemainingUses);
    REGISTER(GetFeatTotalUses);
    REGISTER(SetFeatRemainingUses);
    REGISTER(GetTotalEffectBonus);
    REGISTER(SetOriginalName);
    REGISTER(GetOriginalName);
    REGISTER(SetSpellResistance);
    REGISTER(SetAnimalCompanionCreatureType);
    REGISTER(SetFamiliarCreatureType);
    REGISTER(SetAnimalCompanionName);
    REGISTER(SetFamiliarName);
    REGISTER(GetDisarmable);
    REGISTER(SetDisarmable);
    REGISTER(SetFaction);
    REGISTER(GetFaction);
    REGISTER(GetFlatFooted);
    REGISTER(SerializeQuickbar);
    REGISTER(DeserializeQuickbar);
    REGISTER(SetCasterLevelModifier);
    REGISTER(GetCasterLevelModifier);
    REGISTER(SetCasterLevelOverride);
    REGISTER(GetCasterLevelOverride);
    REGISTER(JumpToLimbo);
    REGISTER(SetCriticalMultiplierModifier);
    REGISTER(GetCriticalMultiplierModifier);
    REGISTER(SetCriticalMultiplierOverride);
    REGISTER(GetCriticalMultiplierOverride);
    REGISTER(SetCriticalRangeModifier);
    REGISTER(GetCriticalRangeModifier);
    REGISTER(SetCriticalRangeOverride);
    REGISTER(GetCriticalRangeOverride);
    REGISTER(AddAssociate);
    REGISTER(SetLastItemCasterLevel);
    REGISTER(GetLastItemCasterLevel);
    REGISTER(GetArmorClassVersus);
    REGISTER(SetEffectIconFlashing);
    REGISTER(OverrideDamageLevel);
    REGISTER(SetEncounter);
    REGISTER(GetEncounter);
    REGISTER(GetIsBartering);
    REGISTER(GetWalkAnimation);
    REGISTER(SetWalkAnimation);
    REGISTER(SetAttackRollOverride);
    REGISTER(SetParryAllAttacks);
    REGISTER(GetNoPermanentDeath);
    REGISTER(SetNoPermanentDeath);
    REGISTER(ComputeSafeLocation);
    REGISTER(DoPerceptionUpdateOnCreature);
    REGISTER(GetPersonalSpace);
    REGISTER(SetPersonalSpace);
    REGISTER(GetCreaturePersonalSpace);
    REGISTER(SetCreaturePersonalSpace);
    REGISTER(GetHeight);
    REGISTER(SetHeight);
    REGISTER(GetHitDistance);
    REGISTER(SetHitDistance);
    REGISTER(GetPreferredAttackDistance);
    REGISTER(SetPreferredAttackDistance);

#undef REGISTER
}

Creature::~Creature()
{
}

CNWSCreature *Creature::creature(ArgumentStack& args)
{
    const auto creatureId = Events::ExtractArgument<ObjectID>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Creature function called on OBJECT_INVALID");
        return nullptr;
    }

    return Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);
}

ArgumentStack Creature::AddFeat(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto feat = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

        pCreature->m_pStats->AddFeat(static_cast<uint16_t>(feat));
    }

    return Events::Arguments();
}

ArgumentStack Creature::AddFeatByLevel(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto feat  = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        const auto level = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);
            pLevelStats->AddFeat(static_cast<uint16_t>(feat));
            pCreature->m_pStats->AddFeat(static_cast<uint16_t>(feat));
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::RemoveFeat(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto feat = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

        pCreature->m_pStats->RemoveFeat(static_cast<uint16_t>(feat));

    }
    return Events::Arguments();
}

ArgumentStack Creature::GetKnowsFeat(ArgumentStack&& args)
{
    int32_t retVal = 0;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

        retVal = pCreature->m_pStats->HasFeat(static_cast<uint16_t>(feat));
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetFeatCountByLevel(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto level = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);

        if (level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);
            retVal = pLevelStats->m_lstFeats.num;
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetFeatByLevel(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto level = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);
        const auto index = Events::ExtractArgument<int32_t>(args);

        if (level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);

            if (index < pLevelStats->m_lstFeats.num)
                retVal = pLevelStats->m_lstFeats.element[index];
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetFeatGrantLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto* pCreature = creature(args))
    {
        const auto feat = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
        ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        const auto uFeat = static_cast<uint16_t>(feat);

        for (int32_t i = 0; i < pCreature->m_pStats->GetLevel(); i++)
        {
            auto* pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[i];
            ASSERT_OR_THROW(pLevelStats);

            for (int32_t j = 0; j < pLevelStats->m_lstFeats.num; j++)
            {
                if (pLevelStats->m_lstFeats.element[j] == uFeat)
                {
                    return Events::Arguments(i + 1);
                }
            }
        }
    }

    return Events::Arguments(0);
}

ArgumentStack Creature::GetFeatCount(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_pStats->m_lstFeats.num;
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetFeatByIndex(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto index = Events::ExtractArgument<int32_t>(args);

        if (index < pCreature->m_pStats->m_lstFeats.num)
        {
            retVal = pCreature->m_pStats->m_lstFeats.element[index];
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetMeetsFeatRequirements(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        CExoArrayList<uint16_t> unused = {};

        retVal = pCreature->m_pStats->FeatRequirementsMet(static_cast<uint16_t>(feat), &unused);
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetSpecialAbility(ArgumentStack&& args)
{
    int32_t id = -1, ready = -1, level = -1;
    if (auto *pCreature = creature(args))
    {
        const auto index = Events::ExtractArgument<int32_t>(args);

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT_OR_THROW(pAbilities);
        if (index < pAbilities->num)
        {
            id    = static_cast<int32_t>(pAbilities->element[index].m_nSpellId);
            ready = static_cast<int32_t>(pAbilities->element[index].m_bReadied);
            level = static_cast<int32_t>(pAbilities->element[index].m_nCasterLevel);
        }
    }
    return Events::Arguments(id, ready, level);
}

ArgumentStack Creature::GetSpecialAbilityCount(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT_OR_THROW(pAbilities);

        // Need to count them manually, since some might be set to invalid
        retVal = 0;
        for (int32_t i = 0; i < pAbilities->num; i++)
            retVal += (pAbilities->element[i].m_nSpellId != ~0u);
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::AddSpecialAbility(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto level = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level <= 60);
        const auto ready = Events::ExtractArgument<int32_t>(args);
        const auto id    = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(id >= 0);

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT_OR_THROW(pAbilities);

        // Check for an empty slot somewhere first
        for (int32_t i = 0; i < pAbilities->num; i++)
        {
            if (pAbilities->element[i].m_nSpellId == ~0u)
            {
                pAbilities->element[i].m_nSpellId     = static_cast<uint32_t>(id);
                pAbilities->element[i].m_bReadied     = ready;
                pAbilities->element[i].m_nCasterLevel = static_cast<uint8_t>(level);
                return Events::Arguments();
            }
        }

        if (pAbilities->array_size == pAbilities->num)
        {
            pAbilities->Allocate(pAbilities->array_size + 1);
        }
        ASSERT_OR_THROW(pAbilities->array_size > pAbilities->num);
        pAbilities->element[pAbilities->num].m_nSpellId     = static_cast<uint32_t>(id);
        pAbilities->element[pAbilities->num].m_bReadied     = ready;
        pAbilities->element[pAbilities->num].m_nCasterLevel = static_cast<uint8_t>(level);
        pAbilities->num++;
    }
    return Events::Arguments();
}

ArgumentStack Creature::RemoveSpecialAbility(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto index = Events::ExtractArgument<int32_t>(args);

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT_OR_THROW(pAbilities);
        if (index < pAbilities->num)
        {
            pAbilities->element[index].m_nSpellId = ~0u;
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetSpecialAbility(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto index = Events::ExtractArgument<int32_t>(args);
        const auto level = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level <= 60);
        const auto ready = Events::ExtractArgument<int32_t>(args);
        const auto id    = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(id >= 0);

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT_OR_THROW(pAbilities);
        if (index < pAbilities->num)
        {
            pAbilities->element[index].m_nSpellId     = static_cast<uint32_t>(id);
            pAbilities->element[index].m_bReadied     = ready;
            pAbilities->element[index].m_nCasterLevel = static_cast<uint8_t>(level);
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetClassByLevel(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto level = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);

            retVal = pLevelStats->m_nClass;
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetBaseAC(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto ac = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(ac >= -128);
          ASSERT_OR_THROW(ac <= 127);

        pCreature->m_pStats->m_nACNaturalBase = static_cast<int8_t>(ac);
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetBaseAC(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_pStats->m_nACNaturalBase;
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetRawAbilityScore(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto ability = Events::ExtractArgument<int32_t>(args);
        const auto value   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(value >= 0);
          ASSERT_OR_THROW(value <= 255);

        switch (ability)
        {
            case Constants::Ability::Strength:
                pCreature->m_pStats->SetSTRBase(static_cast<uint8_t>(value));
                break;
            case Constants::Ability::Dexterity:
                pCreature->m_pStats->SetDEXBase(static_cast<uint8_t>(value));
                break;
            case Constants::Ability::Constitution:
                pCreature->m_pStats->SetCONBase(static_cast<uint8_t>(value), true/*bRecalculateHP*/);
                break;
            case Constants::Ability::Intelligence:
                pCreature->m_pStats->SetINTBase(static_cast<uint8_t>(value));
                break;
            case Constants::Ability::Wisdom:
                pCreature->m_pStats->SetWISBase(static_cast<uint8_t>(value));
                break;
            case Constants::Ability::Charisma:
                pCreature->m_pStats->SetCHABase(static_cast<uint8_t>(value));
                break;
            default:
                LOG_NOTICE("Calling NWNX_Creature_SetRawAbilityScore with invalid ability ID:%d", ability);
                ASSERT_FAIL();
                break;
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetRawAbilityScore(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pCreature = creature(args))
    {
        const auto ability = Events::ExtractArgument<int32_t>(args);

        switch (ability)
        {
            case Constants::Ability::Strength:
                retVal = pCreature->m_pStats->m_nStrengthBase;
                break;
            case Constants::Ability::Dexterity:
                retVal = pCreature->m_pStats->m_nDexterityBase;
                break;
            case Constants::Ability::Constitution:
                retVal = pCreature->m_pStats->m_nConstitutionBase;
                break;
            case Constants::Ability::Intelligence:
                retVal = pCreature->m_pStats->m_nIntelligenceBase;
                break;
            case Constants::Ability::Wisdom:
                retVal = pCreature->m_pStats->m_nWisdomBase;
                break;
            case Constants::Ability::Charisma:
                retVal = pCreature->m_pStats->m_nCharismaBase;
                break;
            default:
                LOG_NOTICE("Calling NWNX_Creature_GetRawAbilityScore with invalid ability ID:%d", ability);
                ASSERT_FAIL();
                break;
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::ModifyRawAbilityScore(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto ability = Events::ExtractArgument<int32_t>(args);
        const auto offset  = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(offset >= -255);
          ASSERT_OR_THROW(offset <= 255);

        switch (ability)
        {
            case Constants::Ability::Strength:
                pCreature->m_pStats->SetSTRBase(static_cast<uint8_t>(pCreature->m_pStats->m_nStrengthBase + offset));
                break;
            case Constants::Ability::Dexterity:
                pCreature->m_pStats->SetDEXBase(static_cast<uint8_t>(pCreature->m_pStats->m_nDexterityBase + offset));
                break;
            case Constants::Ability::Constitution:
                pCreature->m_pStats->SetCONBase(static_cast<uint8_t>(pCreature->m_pStats->m_nConstitutionBase + offset), true/*bRecalculateHP*/);
                break;
            case Constants::Ability::Intelligence:
                pCreature->m_pStats->SetINTBase(static_cast<uint8_t>(pCreature->m_pStats->m_nIntelligenceBase + offset));
                break;
            case Constants::Ability::Wisdom:
                pCreature->m_pStats->SetWISBase(static_cast<uint8_t>(pCreature->m_pStats->m_nWisdomBase + offset));
                break;
            case Constants::Ability::Charisma:
                pCreature->m_pStats->SetCHABase(static_cast<uint8_t>(pCreature->m_pStats->m_nCharismaBase + offset));
                break;
            default:
                LOG_NOTICE("Calling NWNX_Creature_ModifyRawAbilityScore with invalid ability ID:%d", ability);
                ASSERT_FAIL();
                break;
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetPrePolymorphAbilityScore(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pCreature = creature(args))
    {
        const auto ability = Events::ExtractArgument<int32_t>(args);

        switch (ability)
        {
            case Constants::Ability::Strength:
                retVal = pCreature->m_nPrePolymorphSTR;
                break;
            case Constants::Ability::Dexterity:
                retVal = pCreature->m_nPrePolymorphDEX;
                break;
            case Constants::Ability::Constitution:
                retVal = pCreature->m_nPrePolymorphCON;
                break;
            default:
                LOG_NOTICE("Calling NWNX_Creature_GetPrePolymorphAbilityScore with invalid ability ID: %d", ability);
                ASSERT_FAIL();
                break;
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetMemorisedSpell(ArgumentStack&& args)
{
    int32_t id, ready, meta, domain;
    id = ready = meta = domain = -1;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto index   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(index >= 0);
          ASSERT_OR_THROW(index <= 255);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                if (auto *pSpell = classInfo.GetMemorizedSpellInSlotDetails(static_cast<uint8_t>(level),
                                                                            static_cast<uint8_t>(index)))
                {
                    id     = static_cast<int32_t>(pSpell->m_nSpellId);
                    ready  = pSpell->m_bReadied;
                    meta   = pSpell->m_nMetaType;
                    domain = pSpell->m_bDomainSpell;
                }
                break;
            }
        }
    }
    return Events::Arguments(id, ready, meta, domain);
}

ArgumentStack Creature::GetMemorisedSpellCountByLevel(ArgumentStack&& args)
{
    int32_t retVal = 0;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retVal = classInfo.GetNumberMemorizedSpellSlots(static_cast<uint8_t>(level));
                break;
            }
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetMemorisedSpell(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto index   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(index >= 0);
          ASSERT_OR_THROW(index <= 255);

        const auto domain  = Events::ExtractArgument<int32_t>(args);
        const auto meta    = Events::ExtractArgument<int32_t>(args);
        const auto ready   = Events::ExtractArgument<int32_t>(args);
        const auto id      = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(id >= 0);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.SetMemorizedSpellSlot(static_cast<uint8_t>(level),
                                                static_cast<uint8_t>(index),
                                                static_cast<uint32_t>(id),
                                                domain,
                                                static_cast<uint8_t>(meta));

                classInfo.SetMemorizedSpellInSlotReady(static_cast<uint8_t>(level),
                                                       static_cast<uint8_t>(index),
                                                       ready);

                break;
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetRemainingSpellSlots(ArgumentStack&& args)
{
    int32_t retVal = 0;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retVal = classInfo.GetSpellsPerDayLeft(static_cast<uint8_t>(level));
                break;
            }
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetRemainingSpellSlots(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto slots   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(slots >= 0);
          ASSERT_OR_THROW(slots <= 255);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.SetSpellsPerDayLeft(static_cast<uint8_t>(level), static_cast<uint8_t>(slots));
                break;
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetMaxSpellSlots(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retVal = pCreature->m_pStats->GetSpellGainWithBonus(i, level) + classInfo.m_nBonusSpellsList[level];
                break;
            }
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetKnownSpell(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto index   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(index >= 0);
          ASSERT_OR_THROW(index <= 255);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retVal = static_cast<int32_t>(classInfo.GetKnownSpell(
                        static_cast<uint8_t>(level),
                        static_cast<uint8_t>(index)));
                break;
            }
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetKnownSpellCount(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retVal = classInfo.GetNumberKnownSpells(static_cast<uint8_t>(level));
                break;
            }
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::RemoveKnownSpell(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto spellId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(spellId >= 0);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.RemoveKnownSpell(static_cast<uint8_t>(level), static_cast<uint32_t>(spellId));
                break;
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::AddKnownSpell(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto spellId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(spellId >= 0);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.AddKnownSpell(static_cast<uint8_t>(level), static_cast<uint32_t>(spellId));
                break;
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::ClearMemorisedKnownSpells(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto id      = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(id >= 0);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.ClearMemorizedKnownSpells(static_cast<uint32_t>(id));
                break;
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::ClearMemorisedSpell(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto index   = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(index >= 0);
          ASSERT_OR_THROW(index <= 255);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.ClearMemorizedSpellSlot(static_cast<uint8_t>(level),
                                                  static_cast<uint8_t>(index));

                break;
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetMaxHitPointsByLevel(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto level = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);
        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);

            retVal = pLevelStats->m_nHitDie;
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetMaxHitPointsByLevel(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto level = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);
        const auto value = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(value >= 0);
          ASSERT_OR_THROW(value <= 255);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);

            pLevelStats->m_nHitDie = static_cast<uint8_t>(value);
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetMovementRate(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto rate = Events::ExtractArgument<int32_t>(args);

        if (pCreature->m_pStats->m_nMovementRate == Constants::MovementRate::Immobile)
        {
            pCreature->m_nAIState |= Constants::AIState::CanUseLegs;
        }

        pCreature->m_pStats->SetMovementRate(rate);
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetMovementRateFactor(ArgumentStack&& args)
{
    float retVal = 0;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->GetMovementRateFactor();
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetMovementRateFactor(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const float factor = Events::ExtractArgument<float>(args);
        pCreature->SetMovementRateFactor(factor);
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetMovementRateFactorCap(ArgumentStack&& args)
{
    static Hooks::Hook pGetMovementRateFactor_hook =
        Hooks::HookFunction(Functions::_ZN12CNWSCreature21GetMovementRateFactorEv,
        (void*)+[](CNWSCreature *pThis) -> float
        {
            auto pRate = pThis->nwnxGet<float>("MOVEMENT_RATE_FACTOR");
            return pRate ? *pRate : pGetMovementRateFactor_hook->CallOriginal<float>(pThis);
        }, Hooks::Order::Late);

    static Hooks::Hook pSetMovementRateFactor_hook =
        Hooks::HookFunction(Functions::_ZN12CNWSCreature21SetMovementRateFactorEf,
        (void*)+[](CNWSCreature *pThis, float fRate) -> void
        {
            // Always set the default so it goes back to normal if cap is reset
            pSetMovementRateFactor_hook->CallOriginal<void>(pThis, fRate);

            auto pCap = pThis->nwnxGet<float>("MOVEMENT_RATE_FACTOR_CAP");
            if (pCap)
            {
                if (fRate > *pCap) { fRate = *pCap; }
                pThis->nwnxSet("MOVEMENT_RATE_FACTOR", fRate);
            }
        }, Hooks::Order::Late);

    if (auto *pCreature = creature(args))
    {
        const float fCap = Events::ExtractArgument<float>(args);

        if (fCap < 0.0) // remove the override
        {
            pCreature->nwnxRemove("MOVEMENT_RATE_FACTOR");
            pCreature->nwnxRemove("MOVEMENT_RATE_FACTOR_CAP");
        }
        else
        {
            pCreature->nwnxSet("MOVEMENT_RATE_FACTOR_CAP", fCap, true);
        }
    }

    return Events::Arguments();
}

ArgumentStack Creature::SetAlignmentGoodEvil(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto value = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(value <= 32767);
          ASSERT_OR_THROW(value >= -32768);
        pCreature->m_pStats->m_nAlignmentGoodEvil = static_cast<int16_t>(value);
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetAlignmentLawChaos(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto value = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(value <= 32767);
          ASSERT_OR_THROW(value >= -32768);
        pCreature->m_pStats->m_nAlignmentLawChaos = static_cast<int16_t>(value);
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetDomain(ArgumentStack&& args)
{
    if (auto* pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
        ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto index = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(index >= 1);
        ASSERT_OR_THROW(index <= 2);
        const auto domain = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(domain <= 255);
        ASSERT_OR_THROW(domain >= 0);

        CNWClass* pClass = classId < Globals::Rules()->m_nNumClasses ? &Globals::Rules()->m_lstClasses[classId] : nullptr;
        ASSERT_OR_THROW(pClass != nullptr);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.m_nDomain[index - 1] = static_cast<uint8_t>(domain);
                break;
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetSpecialization(ArgumentStack&& args)
{
    if (auto* pCreature = creature(args))
    {
        const auto classId = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
        ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto school = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(school <= 255);
        ASSERT_OR_THROW(school >= 0);

        CNWClass* pClass = classId < Globals::Rules()->m_nNumClasses ? &Globals::Rules()->m_lstClasses[classId] : nullptr;
        ASSERT_OR_THROW(pClass != nullptr);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.m_nSchool = static_cast<uint8_t>(school);
                break;
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetSoundset(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_nSoundSet;
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetSoundset(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto soundset = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(soundset >= 0);

        pCreature->m_nSoundSet = static_cast<uint16_t>(soundset);
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetSkillRank(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto skill = Events::ExtractArgument<int32_t>(args);
        const auto rank = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(skill >= Constants::Skill::MIN);
          ASSERT_OR_THROW(skill <= Constants::Skill::MAX);
          ASSERT_OR_THROW(rank >= -127);
          ASSERT_OR_THROW(rank <= 128);

        pCreature->m_pStats->SetSkillRank(static_cast<uint8_t>(skill), static_cast<int8_t>(rank));
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetClassByPosition(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto position = Events::ExtractArgument<int32_t>(args);
        const auto classID = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(position >= 0);
          ASSERT_OR_THROW(position <= 2);
          ASSERT_OR_THROW(classID >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classID <= Constants::ClassType::MAX);

        pCreature->m_pStats->SetClass(static_cast<uint8_t>(position), static_cast<uint8_t>(classID));
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetLevelByPosition(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto position = Events::ExtractArgument<int32_t>(args);
        const auto level = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(position >= 0);
          ASSERT_OR_THROW(position <= 2);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level <= 60);

        pCreature->m_pStats->SetClassLevel(static_cast<uint8_t>(position), static_cast<uint8_t>(level));
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetBaseAttackBonus(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto bab = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(bab >= 0);
          ASSERT_OR_THROW(bab <= 254);

        pCreature->m_pStats->m_nBaseAttackBonus = static_cast<uint8_t>(bab);
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetAttacksPerRound(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto bBaseAPR = Events::ExtractArgument<int32_t>(args);

        if (bBaseAPR || pCreature->m_pStats->m_nOverrideBaseAttackBonus == 0)
            retVal = pCreature->m_pStats->GetAttacksPerRound();
        else
            retVal = pCreature->m_pStats->m_nOverrideBaseAttackBonus;
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetGender(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto gender = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(gender >= 0);
          ASSERT_OR_THROW(gender <= 255);

        pCreature->m_pStats->m_nGender = gender;
        pCreature->m_cAppearance.m_nGender = gender;
    }
    return Events::Arguments();
}

ArgumentStack Creature::RestoreFeats(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        pCreature->m_pStats->ResetFeatRemainingUses();
    }
    return Events::Arguments();
}

ArgumentStack Creature::RestoreSpecialAbilities(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        pCreature->m_pStats->ResetSpellLikeAbilities();
    }
    return Events::Arguments();
}

ArgumentStack Creature::RestoreSpells(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto level = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= -1);
          ASSERT_OR_THROW(level <= 9);

        if (level >= 0 && level <= 9)
        {
            pCreature->m_pStats->ReadySpellLevel(level);
        }
        else
        {
            for (int i = 0; i <= 9; i++)
               pCreature->m_pStats->ReadySpellLevel(i);
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::RestoreItems(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        pCreature->RestoreItemProperties();
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetSize(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto size = Events::ExtractArgument<int32_t>(args);

        pCreature->m_nCreatureSize = size;
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetSkillPointsRemaining(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_pStats->m_nSkillPointsRemaining;
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetSkillPointsRemaining(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto points = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(points >= 0);
          ASSERT_OR_THROW(points <= 65535);

        pCreature->m_pStats->m_nSkillPointsRemaining = static_cast<uint16_t>(points);
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetRacialType(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto race = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(race >= Constants::RacialType::MIN);
          ASSERT_OR_THROW(race <= Constants::RacialType::MAX);

        pCreature->m_pStats->m_nRace = static_cast<uint16_t>(race);
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetMovementType(ArgumentStack&& args)
{
    // Mirrored in nwnx_creature.nss
    const int MOVEMENT_TYPE_STATIONARY      = 0;
    const int MOVEMENT_TYPE_WALK            = 1;
    const int MOVEMENT_TYPE_RUN             = 2;
    const int MOVEMENT_TYPE_SIDESTEP        = 3;
    const int MOVEMENT_TYPE_WALK_BACKWARDS  = 4;

    int retVal = MOVEMENT_TYPE_STATIONARY;
    if (auto *pCreature = creature(args))
    {

        switch (pCreature->m_nAnimation)
        {
            case Constants::Animation::Walking:
            case Constants::Animation::WalkingForwardLeft:
            case Constants::Animation::WalkingForwardRight:
                retVal = MOVEMENT_TYPE_WALK;
                break;
            case Constants::Animation::WalkingBackwards:
                retVal = MOVEMENT_TYPE_WALK_BACKWARDS;
                break;
            case Constants::Animation::Running:
            case Constants::Animation::RunningForwardLeft:
            case Constants::Animation::RunningForwardRight:
                retVal = MOVEMENT_TYPE_RUN;
                break;
            case Constants::Animation::WalkingLeft:
            case Constants::Animation::WalkingRight:
                retVal = MOVEMENT_TYPE_SIDESTEP;
                break;
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetWalkRateCap(ArgumentStack&& args)
{
    static Hooks::Hook pGetWalkRate_hook =
        Hooks::HookFunction(Functions::_ZN12CNWSCreature11GetWalkRateEv,
        (void*)+[](CNWSCreature *pThis) -> float
        {
            float fWalkRate = pGetWalkRate_hook->CallOriginal<float>(pThis);

            auto cap = pThis->nwnxGet<float>("WALK_RATE_CAP");
            return (cap && *cap < fWalkRate) ? *cap : fWalkRate;

        }, Hooks::Order::Late);

    if (auto *pCreature = creature(args))
    {
        const auto fWalkRateCap = Events::ExtractArgument<float>(args);

        if (fWalkRateCap < 0.0) // remove the override
        {
            pCreature->nwnxRemove("WALK_RATE_CAP");
        }
        else
        {
            pCreature->nwnxSet("WALK_RATE_CAP", fWalkRateCap, true);
        }
    }

    return Events::Arguments();
}

ArgumentStack Creature::SetGold(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto gold = Events::ExtractArgument<int32_t>(args);

        pCreature->SetGold(gold);
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetCorpseDecayTime(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto nDecayTime = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(nDecayTime >= 0);
        pCreature->m_nDecayTime = nDecayTime;
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetBaseSavingThrow(ArgumentStack&& args)
{
    // NOTE: The misc fields are used for creature save override, and will mess with ELC.
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto which = Events::ExtractArgument<int32_t>(args);
        switch (which)
        {
            case Constants::SavingThrow::Reflex:
                retVal = pCreature->m_pStats->m_nReflexSavingThrowMisc + pCreature->m_pStats->GetBaseReflexSavingThrow();
                break;
            case Constants::SavingThrow::Fortitude:
                retVal = pCreature->m_pStats->m_nFortSavingThrowMisc + pCreature->m_pStats->GetBaseFortSavingThrow();
                break;
            case Constants::SavingThrow::Will:
                retVal = pCreature->m_pStats->m_nWillSavingThrowMisc + pCreature->m_pStats->GetBaseWillSavingThrow();
                break;
            default:
                LOG_WARNING("GetBaseSavingThrow() called for bad save constant %d", which);
                break;
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetBaseSavingThrow(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto which = Events::ExtractArgument<int32_t>(args);
        const auto value = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(value >= -128);
          ASSERT_OR_THROW(value <= 127);
        int8_t base;
        switch (which)
        {
            case Constants::SavingThrow::Reflex:
                base = pCreature->m_pStats->GetBaseReflexSavingThrow();
                pCreature->m_pStats->m_nReflexSavingThrowMisc = value - base;
                break;
            case Constants::SavingThrow::Fortitude:
                base = pCreature->m_pStats->GetBaseFortSavingThrow();
                pCreature->m_pStats->m_nFortSavingThrowMisc = value - base;
                break;
            case Constants::SavingThrow::Will:
                base = pCreature->m_pStats->GetBaseWillSavingThrow();
                pCreature->m_pStats->m_nWillSavingThrowMisc = value - base;
                break;
            default:
                LOG_WARNING("SetBaseSavingThrow() called for bad save constant %d", which);
                break;
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::LevelUp(ArgumentStack&& args)
{
    static bool bSkipLevelUpValidation = false;

    static Hooks::Hook pCanLevelUp_hook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats10CanLevelUpEv,
        (void*)+[](CNWSCreatureStats *pThis) -> int32_t
        {
            if (bSkipLevelUpValidation && !pThis->m_bIsPC)
            {
                return pThis->GetLevel(false) < 60;
            }
            return pCanLevelUp_hook->CallOriginal<int32_t>(pThis);
        }, Hooks::Order::Late);

    static Hooks::Hook pValidateLevelUp_hook =
        Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats15ValidateLevelUpEP13CNWLevelStatshhh,
        (void*)+[](CNWSCreatureStats *pThis, CNWLevelStats *pLevelStats, uint8_t nDomain1, uint8_t nDomain2, uint8_t nSchool) -> uint32_t
        {
            if (bSkipLevelUpValidation)
            {
                ASSERT(!pThis->m_bIsPC);
                pThis->LevelUp(pLevelStats, nDomain1, nDomain2, nSchool, true);
                pThis->UpdateCombatInformation();
                return 0;
            }
            return pValidateLevelUp_hook->CallOriginal<uint32_t>(pThis, pLevelStats, nDomain1, nDomain2, nSchool);
        }, Hooks::Order::Late);

    if (auto *pCreature = creature(args))
    {
        if (pCreature->m_bPlayerCharacter)
        {
            LOG_WARNING("LevelUp() does not work on PCs");
            return Events::Arguments();
        }

        const auto cls = Events::ExtractArgument<int32_t>(args);
        const auto count = Events::ExtractArgument<int32_t>(args);

        // Allow leveling outside of regular rules
        bSkipLevelUpValidation = true;
        for (int32_t i = 0; i < count; i++)
        {
            if (!pCreature->m_pStats->LevelUpAutomatic(cls, true, Constants::ClassType::Invalid))
            {
                LOG_WARNING("Failed to add level of class %d, aborting", cls);
                break;
            }
        }
        // Restore leveling restrictions
        bSkipLevelUpValidation = false;
    }
    return Events::Arguments();
}

ArgumentStack Creature::LevelDown(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        if (pCreature->m_bPlayerCharacter)
        {
            LOG_WARNING("LevelDown() does not work on PCs");
            return Events::Arguments();
        }

        auto count = Events::ExtractArgument<int32_t>(args);
        auto level = pCreature->m_pStats->GetLevel(false);
        if (count >= level)
            count = level - 1;

        for (int32_t i = 1; i <= count; i++)
        {
            if (auto *pLevelStats = pCreature->m_pStats->GetLevelStats(level - i))
            {
                pCreature->m_pStats->LevelDown(pLevelStats);
            }
            else
            {
                //
                // Creature wasn't leveled up properly, so just decrement the level count.
                // Assume that it first got all levels in first class, then second, then third.
                //
                if (pCreature->m_pStats->m_ClassInfo[2].m_nClass != Constants::ClassType::Invalid)
                {
                    if (--pCreature->m_pStats->m_ClassInfo[2].m_nLevel == 0)
                    {
                        pCreature->m_pStats->m_ClassInfo[2].m_nClass = Constants::ClassType::Invalid;
                        pCreature->m_pStats->m_nNumMultiClasses = 2;
                    }
                }
                else if (pCreature->m_pStats->m_ClassInfo[1].m_nClass != Constants::ClassType::Invalid)
                {
                    if (--pCreature->m_pStats->m_ClassInfo[1].m_nLevel == 0)
                    {
                        pCreature->m_pStats->m_ClassInfo[1].m_nClass = Constants::ClassType::Invalid;
                        pCreature->m_pStats->m_nNumMultiClasses = 1;
                    }
                }
                else
                {
                    if (--pCreature->m_pStats->m_ClassInfo[0].m_nLevel == 0)
                    {
                        LOG_WARNING("Creature out of levels to level down.");
                        pCreature->m_pStats->m_ClassInfo[0].m_nLevel = 1;
                        pCreature->m_pStats->m_nNumMultiClasses = 1;
                    }
                }

                pCreature->m_pStats->m_nMultiClassLeveledUpIn = pCreature->m_pStats->m_nNumMultiClasses - 1;
            }
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetChallengeRating(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto fCR = Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fCR >= 0.0);
        pCreature->m_pStats->m_fChallengeRating = fCR;
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetAttackBonus(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pCreature = creature(args))
    {
        const auto isMelee = Events::ExtractArgument<int32_t>(args);
        const auto isTouchAttack = Events::ExtractArgument<int32_t>(args);
        const auto isOffhand = Events::ExtractArgument<int32_t>(args);
        const auto includeBaseAttackBonus = Events::ExtractArgument<int32_t>(args);

        if (isMelee)
        {
            retVal = pCreature->m_pStats->GetMeleeAttackBonus(isOffhand, includeBaseAttackBonus, isTouchAttack);
        }
        else
        {
            retVal = pCreature->m_pStats->GetRangedAttackBonus(includeBaseAttackBonus, isTouchAttack);
        }
    }

    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetHighestLevelOfFeat(ArgumentStack&& args)
{
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        retval = pCreature->m_pStats->GetHighestLevelOfFeat(feat);
    }
    return Events::Arguments(retval);
}

ArgumentStack Creature::GetFeatRemainingUses(ArgumentStack&& args)
{
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        retval = pCreature->m_pStats->GetFeatRemainingUses(feat);
    }
    return Events::Arguments(retval);
}

ArgumentStack Creature::GetFeatTotalUses(ArgumentStack&& args)
{
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        retval = pCreature->m_pStats->GetFeatTotalUses(feat);
    }
    return Events::Arguments(retval);
}

ArgumentStack Creature::SetFeatRemainingUses(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto feat = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        const auto uses = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(uses >= 0);
          ASSERT_OR_THROW(uses <= 255);

        pCreature->m_pStats->SetFeatRemainingUses(feat, uses);
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetTotalEffectBonus(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pCreature = creature(args))
    {
        CNWSObject *versus = NULL;
        const auto bonusType = Events::ExtractArgument<int32_t>(args);
        const auto versus_id = Events::ExtractArgument<ObjectID>(args);
        if (versus_id != Constants::OBJECT_INVALID)
        {
            CGameObject *pObject = API::Globals::AppManager()->m_pServerExoApp->GetGameObject(versus_id);
            versus = Utils::AsNWSObject(pObject);
        }

        const auto isElementalDamage = Events::ExtractArgument<int32_t>(args);
        const auto isForceMax = Events::ExtractArgument<int32_t>(args);
        const auto saveType = Events::ExtractArgument<int32_t>(args);
        const auto saveSpecificType = Events::ExtractArgument<int32_t>(args);
        const auto skill = Events::ExtractArgument<int32_t>(args);
        const auto abilityScore = Events::ExtractArgument<int32_t>(args);
        const auto isOffhand = Events::ExtractArgument<int32_t>(args);
        retVal = pCreature->GetTotalEffectBonus(bonusType, versus, isElementalDamage, isForceMax, saveType, saveSpecificType, skill, abilityScore, isOffhand);
    }

    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetOriginalName(ArgumentStack&& args)
{

    if (auto *pCreature = creature(args))
    {
        const auto name = Events::ExtractArgument<std::string>(args);
        const auto isLastName = Events::ExtractArgument<int32_t>(args);

        CExoLocString locName;
        locName.AddString(0, CExoString(name.c_str()), 0);

        if (isLastName)
        {
            pCreature->m_pStats->m_lsLastName = locName;
        }
        else
        {
            ASSERT_OR_THROW(!name.empty());
            pCreature->m_pStats->m_lsFirstName = locName;
        }

        if (pCreature->m_bPlayerCharacter || pCreature->m_pStats->m_bIsPC || pCreature->m_pStats->m_bIsDMCharacterFile)
        {
            MessageBus::Broadcast("NWNX_CREATURE_ORIGINALNAME_SIGNAL",
                                         {NWNXLib::Utils::ObjectIDToString(pCreature->m_idSelf)});
        }
    }

    return Events::Arguments();
}

ArgumentStack Creature::GetOriginalName(ArgumentStack&& args)
{
    std::string retVal;

    if (auto *pCreature = creature(args))
    {
        const auto isLastName = Events::ExtractArgument<int32_t>(args);

        if (isLastName)
        {
            retVal = Utils::ExtractLocString(pCreature->m_pStats->m_lsLastName);
        }
        else
        {
            retVal = Utils::ExtractLocString(pCreature->m_pStats->m_lsFirstName);
        }
    }

    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetSpellResistance(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto sr = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(sr >= -127);
          ASSERT_OR_THROW(sr <= 128);
        pCreature->m_pStats->SetSpellResistance(static_cast<int8_t>(sr));
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetAnimalCompanionCreatureType(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto creatureType = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(creatureType >= 0);

        pCreature->m_pStats->m_nAnimalCompanionCreatureType = creatureType;
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetFamiliarCreatureType(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto creatureType = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(creatureType >= 0);

        pCreature->m_pStats->m_nFamiliarCreatureType = creatureType;
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetAnimalCompanionName(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto name = Events::ExtractArgument<std::string>(args);

        pCreature->m_pStats->m_sAnimalCompanionName = CExoString(name.c_str());
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetFamiliarName(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto name = Events::ExtractArgument<std::string>(args);

        pCreature->m_pStats->m_sFamiliarName = CExoString(name.c_str());
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetDisarmable(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_bDisarmable;
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetDisarmable(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto disarmable = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(disarmable <= 1);
        ASSERT_OR_THROW(disarmable >= 0);

        pCreature->m_bDisarmable = disarmable;
    }
    return Events::Arguments();
}

ArgumentStack Creature::SetFaction(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto factionid = Events::ExtractArgument<int32_t>(args);
        auto* pFaction = Globals::AppManager()->m_pServerExoApp->m_pcExoAppInternal->m_pFactionManager->GetFaction(factionid);
        if (pFaction)
        {
            pFaction->AddMember(pCreature->m_idSelf);
        }
        else
        {
            LOG_NOTICE("NWNX_Creature_SetFaction called with invalid faction id");
        }
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetFaction(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        if (auto *pFaction = pCreature->GetFaction())
        {
            retVal = pFaction->m_nFactionId;
        }
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetFlatFooted(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->GetFlatFooted();
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SerializeQuickbar(ArgumentStack&& args)
{
    std::string retVal;

    if (auto *pCreature = creature(args))
    {
        uint8_t *pData = nullptr;
        int32_t dataLength = 0;

        CResGFF    resGff;
        CResStruct resStruct{};

        if (resGff.CreateGFFFile(&resStruct, "GFF ", "V2.0"))
        {
            pCreature->SaveQuickButtons(&resGff, &resStruct);
            resGff.WriteGFFToPointer((void**)&pData, /*ref*/dataLength);

            retVal = String::ToBase64(std::vector<uint8_t>(pData, pData+dataLength));
            delete[] pData;
        }
    }

    return Events::Arguments(retVal);
}

ArgumentStack Creature::DeserializeQuickbar(ArgumentStack&& args)
{
    int32_t retVal = false;

    if (auto *pCreature = creature(args))
    {
        const auto serializedB64 = Events::ExtractArgument<std::string>(args);
          ASSERT_OR_THROW(!serializedB64.empty());

        std::vector<uint8_t> serialized = String::FromBase64(serializedB64);

        if (serialized.empty() || serialized.size() < 14*4)
            return Events::Arguments(retVal);

        CResGFF resGff;
        CResStruct resStruct{};

        // resGff/resman will claim ownership of this pointer and free it in resGff destructor,
        // so need a copy for them to play with since the vector can't relinquish its own.
        auto *data = new uint8_t[serialized.size()];
        memcpy(data, serialized.data(), serialized.size());
        if (resGff.GetDataFromPointer((void *) data, (int32_t) serialized.size()))
        {
            resGff.InitializeForWriting();

            if (resGff.GetTopLevelStruct(&resStruct))
            {
                CExoString sFileType, sFileVersion;
                resGff.GetGFFFileInfo(&sFileType, &sFileVersion);

                if (sFileType == "GFF ")
                {
                    pCreature->LoadQuickButtons(&resGff, &resStruct);

                    if (auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(pCreature->m_idSelf))
                    {
                        if (auto *pMessage = static_cast<CNWSMessage *>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage()))
                        {
                            pMessage->SendServerToPlayerGuiQuickbar_SetButton(pPlayer, 0, true);
                        }
                    }

                    retVal = true;
                }
            }
        }
    }

    return Events::Arguments(retVal);
}

void Creature::InitCasterLevelHooks()
{
    s_GetClassLevelHook = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats13GetClassLevelEhi,
                                       (void*)&CNWSCreatureStats__GetClassLevel, Hooks::Order::Early);

    static Hooks::Hook s_ExecuteCommandGetCasterLevelHook =
            Hooks::HookFunction(Functions::_ZN25CNWVirtualMachineCommands28ExecuteCommandGetCasterLevelEii,
                (void*)+[](CNWVirtualMachineCommands *thisPtr, int32_t nCommandId, int32_t nParameters)
                {
                    s_bAdjustCasterLevel = true;
                    auto retVal = s_ExecuteCommandGetCasterLevelHook->CallOriginal<int32_t>(thisPtr, nCommandId, nParameters);
                    s_bAdjustCasterLevel = false;
                    return retVal;
                }, Hooks::Order::Early);
    static Hooks::Hook s_ExecuteCommandResistSpellHook =
            Hooks::HookFunction(Functions::_ZN25CNWVirtualMachineCommands25ExecuteCommandResistSpellEii,
                (void*)+[](CNWVirtualMachineCommands *thisPtr, int32_t nCommandId, int32_t nParameters)
                {
                    s_bAdjustCasterLevel = true;
                    auto retVal = s_ExecuteCommandResistSpellHook->CallOriginal<int32_t>(thisPtr, nCommandId, nParameters);
                    s_bAdjustCasterLevel = false;
                    return retVal;
                }, Hooks::Order::Early);
    static Hooks::Hook s_SetCreatorHook =
            Hooks::HookFunction(Functions::_ZN11CGameEffect10SetCreatorEj,
        (void*)+[](CGameEffect *thisPtr, ObjectID oidCreator)
                {
                    s_bAdjustCasterLevel = true;
                    s_SetCreatorHook->CallOriginal<void>(thisPtr, oidCreator);
                    s_bAdjustCasterLevel = false;
                }, Hooks::Order::Early);

    s_bCasterLevelHooksInitialized = true;
}

ArgumentStack Creature::SetCasterLevelModifier(ArgumentStack&& args)
{
    if (!s_bCasterLevelHooksInitialized)
        InitCasterLevelHooks();

    if (auto* pCreature = creature(args))
    {
        const auto nClass = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(nClass >= 0);
        ASSERT_OR_THROW(nClass <= Constants::ClassType::MAX);
        const auto nModifier = Events::ExtractArgument<int32_t>(args);
        const bool bPersist = !!Events::ExtractArgument<int32_t>(args);

        if (nModifier)
            pCreature->nwnxSet("CASTERLEVEL_MODIFIER" + std::to_string(nClass), nModifier, bPersist);
        else
            pCreature->nwnxRemove("CASTERLEVEL_MODIFIER" + std::to_string(nClass));
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetCasterLevelModifier(ArgumentStack&& args)
{
    if (!s_bCasterLevelHooksInitialized)
        InitCasterLevelHooks();

    int32_t retVal = 0;

    if (auto* pCreature = creature(args))
    {
        const auto nClass = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(nClass >= 0);
        ASSERT_OR_THROW(nClass <= Constants::ClassType::MAX);
        auto nModifier = pCreature->nwnxGet<int>("CASTERLEVEL_MODIFIER" + std::to_string(nClass));
        if (nModifier)
            retVal = nModifier.value();
    }

    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetCasterLevelOverride(ArgumentStack&& args)
{
    if (!s_bCasterLevelHooksInitialized)
        InitCasterLevelHooks();

    if (auto* pCreature = creature(args))
    {
        const auto nClass = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(nClass >= 0);
        ASSERT_OR_THROW(nClass <= Constants::ClassType::MAX);
        const auto nLevel = Events::ExtractArgument<int32_t>(args);
        const bool bPersist = !!Events::ExtractArgument<int32_t>(args);

        if (nLevel > 0)
            pCreature->nwnxSet("CASTERLEVEL_OVERRIDE" + std::to_string(nClass), nLevel, bPersist);
        else
            pCreature->nwnxRemove("CASTERLEVEL_OVERRIDE" + std::to_string(nClass));
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetCasterLevelOverride(ArgumentStack&& args)
{
    if (!s_bCasterLevelHooksInitialized)
        InitCasterLevelHooks();

    int32_t retVal = -1;

    if (auto* pCreature = creature(args))
    {
        const auto nClass = Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(nClass >= 0);
        ASSERT_OR_THROW(nClass <= Constants::ClassType::MAX);
        auto nCasterLevel = pCreature->nwnxGet<int>("CASTERLEVEL_OVERRIDE" + std::to_string(nClass));
        if (nCasterLevel)
            retVal = nCasterLevel.value();
    }

    return Events::Arguments(retVal);
}

uint8_t Creature::CNWSCreatureStats__GetClassLevel(CNWSCreatureStats* thisPtr, uint8_t nMultiClass, BOOL bUseNegativeLevel)
{
    auto retVal = s_GetClassLevelHook->CallOriginal<uint8_t>(thisPtr, nMultiClass, bUseNegativeLevel);

    if (s_bAdjustCasterLevel || nMultiClass < thisPtr->m_nNumMultiClasses)
    {
        auto nClass = thisPtr->m_ClassInfo[nMultiClass].m_nClass;

        if (nClass != Constants::ClassType::Invalid)
        {
            int32_t nModifier = 0;
            auto nLevelOverride = thisPtr->m_pBaseCreature->nwnxGet<int>("CASTERLEVEL_OVERRIDE" + std::to_string(nClass));
            if (nLevelOverride)
            {
                auto nLevel = std::max(nLevelOverride.value(), 255);
                nModifier = nLevel - thisPtr->m_ClassInfo[nMultiClass].m_nLevel;
            }

            auto nLevelModifier = thisPtr->m_pBaseCreature->nwnxGet<int>("CASTERLEVEL_MODIFIER" + std::to_string(nClass));
            if (nLevelModifier)
                nModifier = nLevelModifier.value();

            //Make sure m_nLevel doesn't over/underflow
            nModifier = std::min(nModifier, 255 - thisPtr->m_ClassInfo[nMultiClass].m_nLevel);
            if (nModifier < 0)
                nModifier = -std::min(-nModifier, static_cast<int32_t>(thisPtr->m_ClassInfo[nMultiClass].m_nLevel));

            retVal += nModifier;
        }
    }

    return retVal;
}

ArgumentStack Creature::JumpToLimbo(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        if (!pCreature->m_bPlayerCharacter && !pCreature->m_pStats->m_bIsPC && !pCreature->m_pStats->m_bIsDMCharacterFile)
        {
            pCreature->RemoveFromArea();
            Utils::GetModule()->AddObjectToLimbo(pCreature->m_idSelf);
        }
    }
    return Events::Arguments();
}

void Creature::InitCriticalMultiplierHook()
{
    static Hooks::Hook pGetCriticalHitMultiplier_hook =
        Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats24GetCriticalHitMultiplierEi,
        (void*)+[](CNWSCreatureStats *pThis, int32_t bOffHand = false) -> int32_t
        {
            int32_t retVal;
            if (!bOffHand) //mainhand
            {
                auto pItem = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);
                std::string BaseItemID;
                if (!pItem)
                    BaseItemID = std::to_string(Constants::BaseItem::Gloves);
                else
                    BaseItemID = std::to_string(pItem->m_nBaseItem);

                if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!1!BI" + BaseItemID))
                    retVal = critMultOvr.value();
                else if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!0!BI" + BaseItemID))
                    retVal = critMultOvr.value();
                else if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!1"))
                    retVal = critMultOvr.value();
                else if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!0"))
                    retVal = critMultOvr.value();
                else
                    retVal = pGetCriticalHitMultiplier_hook->CallOriginal<int32_t>(pThis, bOffHand);

                //Override-Modifier gap
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!1!BI" + BaseItemID))
                    retVal = retVal + critMultMod.value();
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!0!BI" + BaseItemID))
                    retVal = retVal + critMultMod.value();
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!1"))
                    retVal = retVal + critMultMod.value();
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!0"))
                    retVal = retVal + critMultMod.value();
            }
            else //Offhand
            {
                auto pItem = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::LeftHand);
                if (!pItem) // Could be a double-sided weapon
                    pItem = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);

                std::string BaseItemID;
                if (!pItem)
                    BaseItemID = std::to_string(Constants::BaseItem::Gloves);
                else
                    BaseItemID = std::to_string(pItem->m_nBaseItem);

                if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!2!BI" + BaseItemID))
                    retVal = critMultOvr.value();
                else if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!0!BI" + BaseItemID))
                    retVal = critMultOvr.value();
                else if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!2"))
                    retVal = critMultOvr.value();
                else if (auto critMultOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_OVERRIDE!0"))
                    retVal = critMultOvr.value();
                else
                    retVal = pGetCriticalHitMultiplier_hook->CallOriginal<int32_t>(pThis, bOffHand);

                //Override-Modifier gap
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!2!BI" + BaseItemID))
                    retVal = retVal + critMultMod.value();
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!0!BI" + BaseItemID))
                    retVal = retVal + critMultMod.value();
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!2"))
                    retVal = retVal + critMultMod.value();
                if (auto critMultMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_MULTIPLIER_MODIFIER!0"))
                    retVal = retVal + critMultMod.value();
            }

            return retVal > 0 ? retVal : 0;
        }, Hooks::Order::Late);

    s_bCriticalMultiplierHooksInitialized = true;
}

ArgumentStack Creature::SetCriticalMultiplierModifier(ArgumentStack&& args)
{
    if (!s_bCriticalMultiplierHooksInitialized)
        InitCriticalMultiplierHook();

    if (auto* pCreature = creature(args))
    {
        const auto Modifier = Events::ExtractArgument<int32_t>(args);
        auto Hand = Events::ExtractArgument<int32_t>(args);
        const bool persist = !!Events::ExtractArgument<int32_t>(args);
        auto BaseItemID = Events::ExtractArgument<int32_t>(args);

        if (Hand < 0 || 2 < Hand)
            Hand = 0;
        if (BaseItemID < -1)
            BaseItemID = -1;

        auto POSVar = "CRITICAL_MULTIPLIER_MODIFIER!" + std::to_string(Hand);
        if (BaseItemID != -1)
            POSVar = POSVar + "!BI" + std::to_string(BaseItemID);

        if (Modifier)
            pCreature->nwnxSet(POSVar, Modifier, persist);
        else
            pCreature->nwnxRemove(POSVar);
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetCriticalMultiplierModifier(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto* pCreature = creature(args))
    {
        auto Hand = Events::ExtractArgument<int32_t>(args);
        auto BaseItemID = Events::ExtractArgument<int32_t>(args);

        if (Hand < 0 || 2 < Hand)
            Hand = 0;
        if (BaseItemID < -1)
            BaseItemID = -1;

        auto POSVar = "CRITICAL_MULTIPLIER_MODIFIER!" + std::to_string(Hand);
        if (BaseItemID != -1)
            POSVar = POSVar + "!BI" + std::to_string(BaseItemID);

        auto Modifier = pCreature->nwnxGet<int32_t>(POSVar);
        if (Modifier)
            retVal = Modifier.value();
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetCriticalMultiplierOverride(ArgumentStack&& args)
{
    if (!s_bCriticalMultiplierHooksInitialized)
        InitCriticalMultiplierHook();

    if (auto* pCreature = creature(args))
    {
        const auto Override = Events::ExtractArgument<int32_t>(args);
        auto Hand = Events::ExtractArgument<int32_t>(args);
        const bool persist = !!Events::ExtractArgument<int32_t>(args);
        auto BaseItemID = Events::ExtractArgument<int32_t>(args);

        if (Hand < 0 || 2 < Hand)
            Hand = 0;
        if (BaseItemID < -1)
            BaseItemID = -1;

        auto POSVar = "CRITICAL_MULTIPLIER_OVERRIDE!" + std::to_string(Hand);
        if (BaseItemID != -1)
            POSVar = POSVar + "!BI" + std::to_string(BaseItemID);

        if (Override >= 0)
            pCreature->nwnxSet(POSVar, Override, persist);
        else
            pCreature->nwnxRemove(POSVar);
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetCriticalMultiplierOverride(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto* pCreature = creature(args))
    {
        auto Hand = Events::ExtractArgument<int32_t>(args);
        auto BaseItemID = Events::ExtractArgument<int32_t>(args);

        if (Hand < 0 || 2 < Hand)
            Hand = 0;
        if (BaseItemID < -1)
            BaseItemID = -1;

        auto POSVar = "CRITICAL_MULTIPLIER_OVERRIDE!" + std::to_string(Hand);
        if (BaseItemID != -1)
            POSVar = POSVar + "!BI" + std::to_string(BaseItemID);

        auto Override = pCreature->nwnxGet<int32_t>(POSVar);
        if (Override)
            retVal = Override.value();
    }
    return Events::Arguments(retVal);
}

void Creature::InitCriticalRangeHook()
{
    static NWNXLib::Hooks::Hook pGetCriticalHitRoll_hook =
        Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats18GetCriticalHitRollEi,
        (void*)+[](CNWSCreatureStats *pThis, int32_t bOffHand = false) -> int32_t
        {
            int32_t retVal;
            if (!bOffHand) //mainhand
            {
                auto pItem = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);
                std::string BaseItemID;
                if (!pItem)
                    BaseItemID = std::to_string(Constants::BaseItem::Gloves);
                else
                    BaseItemID = std::to_string(pItem->m_nBaseItem);

                if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!1!BI" + BaseItemID))
                    retVal = critRngOvr.value();
                else if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!0!BI" + BaseItemID))
                    retVal = critRngOvr.value();
                else if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!1"))
                    retVal = critRngOvr.value();
                else if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!0"))
                    retVal = critRngOvr.value();
                else
                    retVal = pGetCriticalHitRoll_hook->CallOriginal<int32_t>(pThis, bOffHand);

                //Override-Modifier gap
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!1!BI" + BaseItemID))
                    retVal = retVal + critRngMod.value();
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!0!BI" + BaseItemID))
                    retVal = retVal + critRngMod.value();
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!1"))
                    retVal = retVal + critRngMod.value();
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!0"))
                    retVal = retVal + critRngMod.value();
            }
            else //Offhand
            {
                auto pItem = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::LeftHand);
                if (!pItem) // Could be a double-sided weapon
                    pItem = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);

                std::string BaseItemID;
                if (!pItem)
                    BaseItemID = std::to_string(Constants::BaseItem::Gloves);
                else
                    BaseItemID = std::to_string(pItem->m_nBaseItem);

                if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!2!BI" + BaseItemID))
                    retVal = critRngOvr.value();
                else if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!0!BI" + BaseItemID))
                    retVal = critRngOvr.value();
                else if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!2"))
                    retVal = critRngOvr.value();
                else if (auto critRngOvr = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_OVERRIDE!0"))
                    retVal = critRngOvr.value();
                else
                    retVal = pGetCriticalHitRoll_hook->CallOriginal<int32_t>(pThis, bOffHand);

                //Override-Modifier gap
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!2!BI" + BaseItemID))
                    retVal = retVal + critRngMod.value();
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!0!BI" + BaseItemID))
                    retVal = retVal + critRngMod.value();
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!2"))
                    retVal = retVal + critRngMod.value();
                if (auto critRngMod = pThis->m_pBaseCreature->nwnxGet<int32_t>("CRITICAL_RANGE_MODIFIER!0"))
                    retVal = retVal + critRngMod.value();
            }
            return std::clamp(retVal, 0, 20);
        });

    s_bCriticalRangeHooksInitialized = true;
}

ArgumentStack Creature::SetCriticalRangeModifier(ArgumentStack&& args)
{
    if (!s_bCriticalRangeHooksInitialized)
        InitCriticalRangeHook();

    if (auto* pCreature = creature(args))
    {
        const auto Modifier = Events::ExtractArgument<int32_t>(args);
        auto Hand = Events::ExtractArgument<int32_t>(args);
        const bool persist = !!Events::ExtractArgument<int32_t>(args);
        auto BaseItemID = Events::ExtractArgument<int32_t>(args);

        if (Hand < 0 || 2 < Hand)
            Hand = 0;
        if (BaseItemID < -1)
            BaseItemID = -1;

        auto POSVar = "CRITICAL_RANGE_MODIFIER!" + std::to_string(Hand);
        if (BaseItemID != -1)
            POSVar = POSVar + "!BI" + std::to_string(BaseItemID);

        if (Modifier)
            pCreature->nwnxSet(POSVar, Modifier, persist);
        else
            pCreature->nwnxRemove(POSVar);
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetCriticalRangeModifier(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto* pCreature = creature(args))
    {
        auto Hand = Events::ExtractArgument<int32_t>(args);
        auto BaseItemID = Events::ExtractArgument<int32_t>(args);

        if (Hand < 0 || 2 < Hand)
            Hand = 0;
        if (BaseItemID < -1)
            BaseItemID = -1;

        auto POSVar = "CRITICAL_RANGE_MODIFIER!" + std::to_string(Hand);
        if (BaseItemID != -1)
            POSVar = POSVar + "!BI" + std::to_string(BaseItemID);

        auto Modifier = pCreature->nwnxGet<int32_t>(POSVar);
        if (Modifier)
            retVal = Modifier.value();
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetCriticalRangeOverride(ArgumentStack&& args)
{
    if (!s_bCriticalRangeHooksInitialized)
        InitCriticalRangeHook();

    if (auto* pCreature = creature(args))
    {
        const auto Override = Events::ExtractArgument<int32_t>(args);
        auto Hand = Events::ExtractArgument<int32_t>(args);
        const bool persist = !!Events::ExtractArgument<int32_t>(args);
        auto BaseItemID = Events::ExtractArgument<int32_t>(args);

        if (Hand < 0 || 2 < Hand)
            Hand = 0;
        if (BaseItemID < -1)
            BaseItemID = -1;

        auto POSVar = "CRITICAL_RANGE_OVERRIDE!" + std::to_string(Hand);
        if (BaseItemID != -1)
            POSVar = POSVar + "!BI" + std::to_string(BaseItemID);

        if (Override >= 0)
            pCreature->nwnxSet(POSVar, Override, persist);
        else
            pCreature->nwnxRemove(POSVar);
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetCriticalRangeOverride(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto* pCreature = creature(args))
    {
        auto Hand = Events::ExtractArgument<int32_t>(args);
        auto BaseItemID = Events::ExtractArgument<int32_t>(args);

        if (Hand < 0 || 2 < Hand)
            Hand = 0;
        if (BaseItemID < -1)
            BaseItemID = -1;

        auto POSVar = "CRITICAL_RANGE_OVERRIDE!" + std::to_string(Hand);
        if (BaseItemID != -1)
            POSVar = POSVar + "!BI" + std::to_string(BaseItemID);

        auto Override = pCreature->nwnxGet<int32_t>(POSVar);
        if (Override)
            retVal = Override.value();
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::AddAssociate(ArgumentStack&& args)
{
    if (auto* pCreature = creature(args))
    {
        auto oidAssociate = Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidAssociate != Constants::OBJECT_INVALID);
        auto associateType = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(associateType > Constants::AssociateType::None);
          ASSERT_OR_THROW(associateType <= Constants::AssociateType::Dominated);

        if (auto *pAssociate = Utils::AsNWSCreature(Utils::GetGameObject(oidAssociate)))
        {
            if (!pAssociate->m_bPlayerCharacter)
                pCreature->AddAssociate(oidAssociate, associateType);
            else
                LOG_WARNING("AddAssociate: Cannot add PCs as associate");
        }
    }

    return Events::Arguments();
}

ArgumentStack Creature::SetEffectIconFlashing(ArgumentStack&& args)
{
    if (auto* pCreature = creature(args))
    {
        auto iconId = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(iconId >= 0);
          ASSERT_OR_THROW(iconId <= 255);
        auto flashing = !!Events::ExtractArgument<int32_t>(args);

        for (auto* effectIconObject : pCreature->m_aEffectIcons)
        {
            if (effectIconObject->m_nIcon == iconId && effectIconObject->m_nPlayerBar)
            {
                effectIconObject->m_bFlashing = flashing;
            }
        }
    }

    return Events::Arguments();
}

ArgumentStack Creature::OverrideDamageLevel(ArgumentStack&& args)
{
    static Hooks::Hook pGetDamageLevelHook = Hooks::HookFunction(Functions::_ZN10CNWSObject14GetDamageLevelEv,
        (void*)+[](CNWSObject *thisPtr) -> uint8_t
        {
            auto damageLevel = thisPtr->nwnxGet<int>("CREATURE_DAMAGE_LEVEL_OVERRIDE");
            return damageLevel ? *damageLevel : pGetDamageLevelHook->CallOriginal<uint8_t>(thisPtr);
        }, Hooks::Order::Late);

    if (auto* pCreature = creature(args))
    {
        auto damageLevel = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(damageLevel <= 255);

        if (damageLevel < 0)
            pCreature->nwnxRemove("CREATURE_DAMAGE_LEVEL_OVERRIDE");
        else
            pCreature->nwnxSet("CREATURE_DAMAGE_LEVEL_OVERRIDE", damageLevel);
    }

    return Events::Arguments();
}

ArgumentStack Creature::SetEncounter(ArgumentStack&& args)
{
    if (auto* pCreature = creature(args))
    {
        auto encounterId = Events::ExtractArgument<ObjectID>(args);

        if (encounterId == Constants::OBJECT_INVALID || (Globals::AppManager()->m_pServerExoApp->GetEncounterByGameObjectID(encounterId)))
        {
            pCreature->m_oidEncounter = encounterId;
        }
    }

    return Events::Arguments();
}

ArgumentStack Creature::GetEncounter(ArgumentStack&& args)
{
    ObjectID retVal = Constants::OBJECT_INVALID;

    if (auto* pCreature = creature(args))
    {
        retVal = pCreature->m_oidEncounter;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetIsBartering(ArgumentStack&& args)
{
    int32_t retVal = false;

    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_pBarterInfo != nullptr && pCreature->m_pBarterInfo->m_bWindowOpen;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetLastItemCasterLevel(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        auto casterLvl = Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(casterLvl >= 0);
        pCreature->m_nLastItemCastSpellLevel = casterLvl;
    }
    return Events::Arguments();
}

ArgumentStack Creature::GetLastItemCasterLevel(ArgumentStack&& args)
{
    int32_t retVal = 0;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_nLastItemCastSpellLevel;
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetArmorClassVersus(ArgumentStack&& args)
{
    int32_t retVal = -255;
    if (auto *pCreature = creature(args))
    {
        auto *pVersus = creature(args);
        auto bTouchAttack = Events::ExtractArgument<int32_t>(args);
        retVal = pCreature->m_pStats->GetArmorClassVersus(pVersus, bTouchAttack);
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::GetWalkAnimation(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_nWalkAnimation;
    }
    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetWalkAnimation(ArgumentStack&& args)
{
    if (auto* pCreature = creature(args))
    {
        auto animation = Events::ExtractArgument<int32_t>(args);

        if (animation >= 0)
        {
            pCreature->m_nWalkAnimation = animation;
        }
    }

    return Events::Arguments();
}

void Creature::DoResolveAttackHook(CNWSCreature* thisPtr, CNWSObject* pTarget)
{
    auto nDiceRoll = Globals::Rules()->RollDice(1, 20);
    auto pAttackData = thisPtr->m_pcCombatRound->GetAttack(thisPtr->m_pcCombatRound->m_nCurrentAttack);
    auto nAttackMod = 0;
    auto nAutoFailOnOne = true;
    auto nAutoSucceedOnTwenty = true;
    auto rollIter = g_plugin->m_RollModifier.find(nDiceRoll);
    if (rollIter != g_plugin->m_RollModifier.end())
    {
        auto modIterCreature = rollIter->second.find(thisPtr->m_idSelf);
        if (modIterCreature != rollIter->second.end())
        {
            nAttackMod += modIterCreature->second;
            if (nDiceRoll == 1)
                nAutoFailOnOne = false;
            else if (nDiceRoll == 20)
                nAutoSucceedOnTwenty = false;
        }
        else
        {
            auto modIterAll = rollIter->second.find(Constants::OBJECT_INVALID);
            if (modIterAll != rollIter->second.end())
            {
                nAttackMod += modIterAll->second;
                if (nDiceRoll == 1)
                    nAutoFailOnOne = false;
                else if (nDiceRoll == 20)
                    nAutoSucceedOnTwenty = false;
            }
        }
    }

    CNWSCreatureStats *pThisStats = thisPtr->m_pStats;
    CNWSCreature *pTargetCreature = Utils::AsNWSCreature(pTarget);

    if (pTargetCreature)
    {
        //Test Sneak
        thisPtr->ResolveSneakAttack(pTargetCreature);
        thisPtr->ResolveDeathAttack(pTargetCreature);
    }

    //Coup de grace
    if (pAttackData->m_bCoupDeGrace)
    {
        pAttackData->m_nToHitRoll = 20;
        pAttackData->m_nAttackResult = 7;
        pAttackData->m_nToHitMod = pThisStats->GetAttackModifierVersus(pTargetCreature);
        return;
    }

    if (*Globals::EnableCombatDebugging())
    {
        auto sInfo = pThisStats->GetFullName() + CExoString(" Attack Roll: ") +
                     CExoString(std::to_string(nDiceRoll));
        if (nAttackMod < 0)
            sInfo = sInfo + CExoString(" - ") + CExoString(std::to_string(nAttackMod * -1)) +
                    CExoString(" (Roll Modifier)");
        else if (nAttackMod > 0)
            sInfo = sInfo + CExoString(" + ") + CExoString(std::to_string(nAttackMod)) +
                    CExoString(" (Roll Modifier)");
        pAttackData->m_sAttackDebugText = sInfo;
    }

    //Update rolls
    pAttackData->m_nToHitMod = pThisStats->GetAttackModifierVersus(pTargetCreature);
    pAttackData->m_nToHitRoll = nDiceRoll;
    pAttackData->m_nToHitMod += nAttackMod;

    auto nModifiedRoll = pAttackData->m_nToHitRoll + pAttackData->m_nToHitMod;
    auto nAC = !pTargetCreature ? 0 : pTargetCreature->m_pStats->GetArmorClassVersus(thisPtr, 0);
    bool bHit = nModifiedRoll >= nAC;

    //Test parry/deflect/concealment
    if (thisPtr->ResolveDefensiveEffects(pTarget, bHit))
    {
        return;
    }

    //Parry
    if (pTargetCreature && pAttackData->m_nToHitRoll != 20 &&
        pTargetCreature->m_nCombatMode == 1 &&
        pTargetCreature->m_pcCombatRound->m_nParryActions &&
        !pTargetCreature->m_pcCombatRound->m_bRoundPaused &&
        pTargetCreature->m_nState != 6 && !pAttackData->m_bRangedAttack &&
        !(pTargetCreature->GetRangeWeaponEquipped()))
    {

        auto nParrySkill = pTargetCreature->m_pStats->GetSkillRank(Constants::Skill::Parry, thisPtr,
                                                                   0);
        auto nParryCheck = Globals::Rules()->RollDice(1, 20) + nParrySkill - nModifiedRoll;
        pTargetCreature->m_pcCombatRound->m_nParryActions--;

        if (nParryCheck >= 0)
        {
            pAttackData->m_nAttackResult = 2;
            if (nParryCheck >= Globals::Rules()->GetRulesetIntEntry("PARRY_RIPOSTE_DIFFERENCE", 10))
                pTargetCreature->m_pcCombatRound->AddParryAttack(thisPtr->m_idSelf);
            return;
        }

        pTargetCreature->m_pcCombatRound->AddParryIndex();
    }

    if (pAttackData->m_nToHitRoll == 1 && nAutoFailOnOne)
    {
        pAttackData->m_nAttackResult = 4;
        pAttackData->m_nMissedBy = 1;
        return;
    }
    else if ((pAttackData->m_nToHitRoll != 20 || !nAutoSucceedOnTwenty) && nModifiedRoll < nAC)
    {
        pAttackData->m_nAttackResult = 4;
        pAttackData->m_nMissedBy = static_cast<char>(nModifiedRoll - nAC);
        if (pAttackData->m_nMissedBy < 0)
            pAttackData->m_nMissedBy = static_cast<char>(-pAttackData->m_nMissedBy);
        return;
    }

    //If attack connects
    auto nCritThreat = pThisStats->GetCriticalHitRoll(thisPtr->m_pcCombatRound->GetOffHandAttack());

    //Critical hit check
    if (nCritThreat <= pAttackData->m_nToHitRoll)
    {
        pAttackData->m_nThreatRoll = Globals::Rules()->RollDice(1, 20);
        pAttackData->m_bCriticalThreat = 1;
        //Crit confirmed
        if (pAttackData->m_nThreatRoll + pAttackData->m_nToHitMod >= nAC)
        {
            if (!pTargetCreature)
            {
                pAttackData->m_nAttackResult = 3;
                return;
            }
            auto nDifficultySetting = Globals::AppManager()->m_pServerExoApp->GetDifficultyOption(
                    0);
            //Checking very easy difficulty, monster attack on PC or controlled familiar
            if (nDifficultySetting == 1 && !thisPtr->m_bPlayerCharacter &&
                (pTargetCreature->m_bPlayerCharacter || pTargetCreature->GetIsPossessedFamiliar())
                && !thisPtr->GetIsPossessedFamiliar())
            {
                pAttackData->m_nAttackResult = 1;
                return;
            }

            if (!pTargetCreature->m_pStats->GetEffectImmunity(Constants::ImmunityType::CriticalHit,
                                                              thisPtr, 1))
            {
                pAttackData->m_nAttackResult = 3;
                return;
            }
            auto pMessage = new CNWCCMessageData();
            pMessage->SetObjectID(0, pTarget->m_idSelf);
            pMessage->SetInteger(0, 126);
            pAttackData->m_alstPendingFeedback.Add(pMessage);
        }
    }

    //Regular hit
    pAttackData->m_nAttackResult = 1;
}

void Creature::InitResolveAttackRollHook()
{
    static auto s_ResolveAttackRoll = Hooks::HookFunction(Functions::_ZN12CNWSCreature17ResolveAttackRollEP10CNWSObject,
    (void*)+[](CNWSCreature *thisPtr, CNWSObject *pTarget) -> void
    {
        auto pTargetCreature = Utils::AsNWSCreature(pTarget);
        int32_t bRoundPaused = false;
        if (g_plugin->m_ParryAllAttacks[thisPtr->m_idSelf] ||
        g_plugin->m_ParryAllAttacks[Constants::OBJECT_INVALID])
        {
            if (auto *pCreature = pTargetCreature)
            {
                if (pCreature->m_nCombatMode == Constants::CombatMode::Parry &&
                    pCreature->m_pcCombatRound->m_nParryActions > 0 &&
                    !pCreature->GetRangeWeaponEquipped())
                {
                    bRoundPaused = pCreature->m_pcCombatRound->m_bRoundPaused;
                    pCreature->m_pcCombatRound->m_bRoundPaused = false;
                }
            }
        }

        DoResolveAttackHook(thisPtr, pTarget);

        if (g_plugin->m_ParryAllAttacks[pTarget->m_idSelf] ||
            g_plugin->m_ParryAllAttacks[Constants::OBJECT_INVALID])
        {
            if (bRoundPaused)
                pTargetCreature->m_pcCombatRound->m_bRoundPaused = true;
        }
    }, Hooks::Order::Final);

    s_bResolveAttackRollHookInitialized = true;
}

ArgumentStack Creature::SetAttackRollOverride(ArgumentStack&& args)
{
    if (!s_bResolveAttackRollHookInitialized)
        InitResolveAttackRollHook();

    const auto creatureId = Events::ExtractArgument<ObjectID>(args);
    auto nDie = Events::ExtractArgument<int32_t>(args);
    const auto nModifier = Events::ExtractArgument<int32_t>(args);

    if (nDie < 1 || 20 < nDie)
    {
        LOG_ERROR("Dice roll must be set between 1 and 20!");
    }
    else
    {
        if (creatureId == Constants::OBJECT_INVALID)
        {
            g_plugin->m_RollModifier[nDie][Constants::OBJECT_INVALID] = nModifier;
        }
        else
        {
            g_plugin->m_RollModifier[nDie][Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId)->m_idSelf] = nModifier;
        }
    }

    return Events::Arguments();
}

ArgumentStack Creature::SetParryAllAttacks(ArgumentStack&& args)
{
    if (!s_bResolveAttackRollHookInitialized)
        InitResolveAttackRollHook();

    const auto creatureId = Events::ExtractArgument<ObjectID>(args);
    const auto bParry = !!Events::ExtractArgument<int32_t>(args);
    if (creatureId == Constants::OBJECT_INVALID)
    {
        g_plugin->m_ParryAllAttacks[Constants::OBJECT_INVALID] = bParry;
    }
    else
    {
        g_plugin->m_ParryAllAttacks[Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId)->m_idSelf] = bParry;
    }

    return Events::Arguments();
}

ArgumentStack Creature::GetNoPermanentDeath(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_bNoPermDeath;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetNoPermanentDeath(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto noPermanentDeath = !!Events::ExtractArgument<int32_t>(args);

        pCreature->m_bNoPermDeath = noPermanentDeath;
    }

    return Events::Arguments();
}

ArgumentStack Creature::ComputeSafeLocation(ArgumentStack&& args)
{
    Vector vNewPosition = {0.0, 0.0, 0.0};

    if (auto *pCreature = creature(args))
    {
        Vector vCurrentPosition{};
        vCurrentPosition.z = Events::ExtractArgument<float>(args);
        vCurrentPosition.y = Events::ExtractArgument<float>(args);
        vCurrentPosition.x = Events::ExtractArgument<float>(args);
        const auto fSearchRadius = Events::ExtractArgument<float>(args);
        const auto bWalkStraightLineRequired = !!Events::ExtractArgument<int32_t>(args);

        int32_t bPositionFound = false;

        if (auto *pArea = Utils::AsNWSArea(Utils::GetGameObject(pCreature->m_oidArea)))
        {
            bPositionFound = pArea->ComputeSafeLocation(vCurrentPosition, fSearchRadius, pCreature->m_pcPathfindInformation, bWalkStraightLineRequired, &vNewPosition);
        }

        if (!bPositionFound)
            vNewPosition = vCurrentPosition;
    }

    return Events::Arguments(vNewPosition.x, vNewPosition.y, vNewPosition.z);
}

ArgumentStack Creature::DoPerceptionUpdateOnCreature(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        if (auto *pTargetCreature = creature(args))
        {
            pCreature->DoPerceptionUpdateOnCreature(pTargetCreature);
        }
    }

    return Events::Arguments();
}

ArgumentStack Creature::GetPersonalSpace(ArgumentStack&& args)
{
    float retVal = 0;
    if (auto *pCreature = creature(args))
    {
        if (pCreature->m_pcPathfindInformation)
        {
            retVal = pCreature->m_pcPathfindInformation->m_fPersonalSpace;
        }
    }

    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetPersonalSpace(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto fPerspace = Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(fPerspace >= 0);
        if (pCreature->m_pcPathfindInformation)
        {
            pCreature->m_pcPathfindInformation->m_fPersonalSpace = fPerspace;
            pCreature->m_pcPathfindInformation->ComputeStepTolerance();
        }
    }

    return Events::Arguments();
}

ArgumentStack Creature::GetCreaturePersonalSpace(ArgumentStack&& args)
{
    float retVal = 0;
    if (auto *pCreature = creature(args))
    {
        if (pCreature->m_pcPathfindInformation)
        {
            retVal = pCreature->m_pcPathfindInformation->m_fCreaturePersonalSpace;
        }
    }

    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetCreaturePersonalSpace(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto fCrePerspace = Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(fCrePerspace >= 0);
        if (pCreature->m_pcPathfindInformation)
        {
            pCreature->m_pcPathfindInformation->m_fCreaturePersonalSpace = fCrePerspace;
        }
    }

    return Events::Arguments();
}

ArgumentStack Creature::GetHeight(ArgumentStack&& args)
{
    float retVal = 0;
    if (auto *pCreature = creature(args))
    {
        if (pCreature->m_pcPathfindInformation)
        {
            retVal = pCreature->m_pcPathfindInformation->m_fHeight;
        }
    }

    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetHeight(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto fHeight = Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(fHeight >= 0);
        if (pCreature->m_pcPathfindInformation)
        {
            pCreature->m_pcPathfindInformation->m_fHeight = fHeight;
        }
    }

    return Events::Arguments();
}

ArgumentStack Creature::GetHitDistance(ArgumentStack&& args)
{
    float retVal = 0;
    if (auto *pCreature = creature(args))
    {
        if (pCreature->m_pcPathfindInformation)
        {
            retVal = pCreature->m_pcPathfindInformation->m_fHitDistance;
        }
    }

    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetHitDistance(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto fHitDist = Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(fHitDist >= 0);
        if (pCreature->m_pcPathfindInformation)
        {
            pCreature->m_pcPathfindInformation->m_fHitDistance = fHitDist;
        }
    }

    return Events::Arguments();
}

ArgumentStack Creature::GetPreferredAttackDistance(ArgumentStack&& args)
{
    float retVal = 0;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_fPreferredAttackDistance;
    }

    return Events::Arguments(retVal);
}

ArgumentStack Creature::SetPreferredAttackDistance(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto fPrefAtckDist = Events::ExtractArgument<float>(args);
        ASSERT_OR_THROW(fPrefAtckDist >= 0);
        pCreature->m_fPreferredAttackDistance = fPrefAtckDist;
    }

    return Events::Arguments();
}

}
