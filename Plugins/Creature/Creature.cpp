#include "Creature.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerInfo.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CNWSFaction.hpp"
#include "API/CNWSStats_Spell.hpp"
#include "API/CNWSStats_SpellLikeAbility.hpp"
#include "API/CExoArrayList.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWClass.hpp"
#include "API/CNWSModule.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CFactionManager.hpp"
#include "API/CResStruct.hpp"
#include "API/CResGFF.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/C2DA.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "Encoding.hpp"


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

Creature::Creature(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
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

#undef REGISTER
}

Creature::~Creature()
{
}

CNWSCreature *Creature::creature(ArgumentStack& args)
{
    const auto creatureId = Services::Events::ExtractArgument<ObjectID>(args);

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
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

        pCreature->m_pStats->AddFeat(static_cast<uint16_t>(feat));
    }

    return Services::Events::Arguments();
}

ArgumentStack Creature::AddFeatByLevel(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto feat  = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        const auto level = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::RemoveFeat(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

        pCreature->m_pStats->RemoveFeat(static_cast<uint16_t>(feat));

    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetKnowsFeat(ArgumentStack&& args)
{
    int32_t retVal = 0;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

        retVal = pCreature->m_pStats->HasFeat(static_cast<uint16_t>(feat));
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::GetFeatCountByLevel(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto level = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);

        if (level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);
            retVal = pLevelStats->m_lstFeats.num;
        }
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::GetFeatByLevel(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto level = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);
        const auto index = Services::Events::ExtractArgument<int32_t>(args);

        if (level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);

            if (index < pLevelStats->m_lstFeats.num)
                retVal = pLevelStats->m_lstFeats.element[index];
        }
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::GetFeatGrantLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto* pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
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
                    return Services::Events::Arguments(i + 1);
                }
            }
        }
    }

    return Services::Events::Arguments(0);
}

ArgumentStack Creature::GetFeatCount(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_pStats->m_lstFeats.num;
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::GetFeatByIndex(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);

        if (index < pCreature->m_pStats->m_lstFeats.num)
        {
            retVal = pCreature->m_pStats->m_lstFeats.element[index];
        }
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::GetMeetsFeatRequirements(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        CExoArrayList<uint16_t> unused = {};

        retVal = pCreature->m_pStats->FeatRequirementsMet(static_cast<uint16_t>(feat), &unused);
        free(unused.element);
    }
    return Services::Events::Arguments(retVal);
}


ArgumentStack Creature::GetSpecialAbility(ArgumentStack&& args)
{
    int32_t id = -1, ready = -1, level = -1;
    if (auto *pCreature = creature(args))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT_OR_THROW(pAbilities);
        if (index < pAbilities->num)
        {
            id    = static_cast<int32_t>(pAbilities->element[index].m_nSpellId);
            ready = static_cast<int32_t>(pAbilities->element[index].m_bReadied);
            level = static_cast<int32_t>(pAbilities->element[index].m_nCasterLevel);
        }
    }
    return Services::Events::Arguments(id, ready, level);
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
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::AddSpecialAbility(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto level = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level <= 60);
        const auto ready = Services::Events::ExtractArgument<int32_t>(args);
        const auto id    = Services::Events::ExtractArgument<int32_t>(args);
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
                return Services::Events::Arguments();
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::RemoveSpecialAbility(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT_OR_THROW(pAbilities);
        if (index < pAbilities->num)
        {
            pAbilities->element[index].m_nSpellId = ~0u;
        }
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetSpecialAbility(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);
        const auto level = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level <= 60);
        const auto ready = Services::Events::ExtractArgument<int32_t>(args);
        const auto id    = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetClassByLevel(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto level = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);

            retVal = pLevelStats->m_nClass;
        }
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetBaseAC(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto ac = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(ac >= -128);
          ASSERT_OR_THROW(ac <= 127);

        pCreature->m_pStats->m_nACNaturalBase = static_cast<int8_t>(ac);
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetBaseAC(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_pStats->m_nACNaturalBase;
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetRawAbilityScore(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto ability = Services::Events::ExtractArgument<int32_t>(args);
        const auto value   = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetRawAbilityScore(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pCreature = creature(args))
    {
        const auto ability = Services::Events::ExtractArgument<int32_t>(args);

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
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::ModifyRawAbilityScore(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto ability = Services::Events::ExtractArgument<int32_t>(args);
        const auto offset  = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetPrePolymorphAbilityScore(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pCreature = creature(args))
    {
        const auto ability = Services::Events::ExtractArgument<int32_t>(args);

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
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::GetMemorisedSpell(ArgumentStack&& args)
{
    int32_t id, ready, meta, domain;
    id = ready = meta = domain = -1;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto index   = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments(id, ready, meta, domain);
}

ArgumentStack Creature::GetMemorisedSpellCountByLevel(ArgumentStack&& args)
{
    int32_t retVal = 0;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetMemorisedSpell(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto index   = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(index >= 0);
          ASSERT_OR_THROW(index <= 255);

        const auto domain  = Services::Events::ExtractArgument<int32_t>(args);
        const auto meta    = Services::Events::ExtractArgument<int32_t>(args);
        const auto ready   = Services::Events::ExtractArgument<int32_t>(args);
        const auto id      = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetRemainingSpellSlots(ArgumentStack&& args)
{
    int32_t retVal = 0;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetRemainingSpellSlots(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto slots   = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetMaxSpellSlots(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::GetKnownSpell(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto index   = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::GetKnownSpellCount(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::RemoveKnownSpell(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto spellId = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::AddKnownSpell(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto spellId = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::ClearMemorisedKnownSpells(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto id      = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::ClearMemorisedSpell(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level < 10);
        const auto index   = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetMaxHitPointsByLevel(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto level = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);
        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);

            retVal = pLevelStats->m_nHitDie;
        }
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetMaxHitPointsByLevel(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto level = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(level >= 1);
          ASSERT_OR_THROW(level <= Globals::AppManager()->m_pServerExoApp->GetServerInfo()->m_JoiningRestrictions.nMaxLevel);
        const auto value = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(value >= 0);
          ASSERT_OR_THROW(value <= 255);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT_OR_THROW(pLevelStats);

            pLevelStats->m_nHitDie = static_cast<uint8_t>(value);
        }
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetMovementRate(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto rate = Services::Events::ExtractArgument<int32_t>(args);
        pCreature->m_pStats->SetMovementRate(rate);
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetMovementRateFactor(ArgumentStack&& args)
{
    float retVal = 0;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->GetMovementRateFactor();
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetMovementRateFactor(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const float factor = Services::Events::ExtractArgument<float>(args);
        pCreature->SetMovementRateFactor(factor);
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetMovementRateFactorCap(ArgumentStack&& args)
{
    static NWNXLib::Hooking::FunctionHook* pGetMovementRateFactor_hook;
    static NWNXLib::Hooking::FunctionHook* pSetMovementRateFactor_hook;

    if (!pGetMovementRateFactor_hook)
    {
        GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN12CNWSCreature21GetMovementRateFactorEv>(
            +[](CNWSCreature *pThis) -> float
            {
                auto pRate = g_plugin->GetServices()->m_perObjectStorage->Get<float>(pThis, "MOVEMENT_RATE_FACTOR");
                return pRate ? *pRate : pGetMovementRateFactor_hook->CallOriginal<float>(pThis);
            });

        pGetMovementRateFactor_hook = GetServices()->m_hooks->FindHookByAddress(Functions::_ZN12CNWSCreature21GetMovementRateFactorEv);
    }

    if (!pSetMovementRateFactor_hook)
    {
        GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN12CNWSCreature21SetMovementRateFactorEf>(
            +[](CNWSCreature *pThis, float fRate) -> void
            {
                // Always set the default so it goes back to normal if cap is reset
                pSetMovementRateFactor_hook->CallOriginal<void>(pThis, fRate);

                auto pCap = g_plugin->GetServices()->m_perObjectStorage->Get<float>(pThis, "MOVEMENT_RATE_FACTOR_CAP");
                if (pCap)
                {
                    if (fRate > *pCap) { fRate = *pCap; }
                    g_plugin->GetServices()->m_perObjectStorage->Set(pThis, "MOVEMENT_RATE_FACTOR", fRate);
                }
            });

        pSetMovementRateFactor_hook = GetServices()->m_hooks->FindHookByAddress(Functions::_ZN12CNWSCreature21SetMovementRateFactorEf);
    }

    if (auto *pCreature = creature(args))
    {
        const float fCap = Services::Events::ExtractArgument<float>(args);

        if (fCap < 0.0) // remove the override
        {
            g_plugin->GetServices()->m_perObjectStorage->Remove(pCreature, "MOVEMENT_RATE_FACTOR");
            g_plugin->GetServices()->m_perObjectStorage->Remove(pCreature, "MOVEMENT_RATE_FACTOR_CAP");
        }
        else
        {
            g_plugin->GetServices()->m_perObjectStorage->Set(pCreature, "MOVEMENT_RATE_FACTOR_CAP", fCap, true);
        }
    }

    return Services::Events::Arguments();
}

ArgumentStack Creature::SetAlignmentGoodEvil(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto value = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(value <= 32767);
          ASSERT_OR_THROW(value >= -32768);
        pCreature->m_pStats->m_nAlignmentGoodEvil = static_cast<int16_t>(value);
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetAlignmentLawChaos(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto value = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(value <= 32767);
          ASSERT_OR_THROW(value >= -32768);
        pCreature->m_pStats->m_nAlignmentLawChaos = static_cast<int16_t>(value);
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetDomain(ArgumentStack&& args)
{
    if (auto* pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
        ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto index = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(index >= 1);
        ASSERT_OR_THROW(index <= 2);
        const auto domain = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetSpecialization(ArgumentStack&& args)
{
    if (auto* pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(classId >= Constants::ClassType::MIN);
        ASSERT_OR_THROW(classId <= Constants::ClassType::MAX);
        const auto school = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetSoundset(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_nSoundSet;
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetSoundset(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto soundset = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(soundset >= 0);

        pCreature->m_nSoundSet = static_cast<uint16_t>(soundset);
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetSkillRank(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto skill = Services::Events::ExtractArgument<int32_t>(args);
        const auto rank = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(skill >= Constants::Skill::MIN);
          ASSERT_OR_THROW(skill <= Constants::Skill::MAX);
          ASSERT_OR_THROW(rank >= -127);
          ASSERT_OR_THROW(rank <= 128);

        pCreature->m_pStats->SetSkillRank(static_cast<uint8_t>(skill), static_cast<int8_t>(rank));
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetClassByPosition(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto position = Services::Events::ExtractArgument<int32_t>(args);
        const auto classID = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(position >= 0);
          ASSERT_OR_THROW(position <= 2);
          ASSERT_OR_THROW(classID >= Constants::ClassType::MIN);
          ASSERT_OR_THROW(classID <= Constants::ClassType::MAX);

        pCreature->m_pStats->SetClass(static_cast<uint8_t>(position), static_cast<uint8_t>(classID));
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetLevelByPosition(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto position = Services::Events::ExtractArgument<int32_t>(args);
        const auto level = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(position >= 0);
          ASSERT_OR_THROW(position <= 2);
          ASSERT_OR_THROW(level >= 0);
          ASSERT_OR_THROW(level <= 60);

        pCreature->m_pStats->SetClassLevel(static_cast<uint8_t>(position), static_cast<uint8_t>(level));
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetBaseAttackBonus(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto bab = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(bab >= 0);
          ASSERT_OR_THROW(bab <= 254);

        pCreature->m_pStats->m_nBaseAttackBonus = static_cast<uint8_t>(bab);
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetAttacksPerRound(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto bBaseAPR = Services::Events::ExtractArgument<int32_t>(args);

        if (bBaseAPR || pCreature->m_pStats->m_nOverrideBaseAttackBonus == 0)
            retVal = pCreature->m_pStats->GetAttacksPerRound();
        else
            retVal = pCreature->m_pStats->m_nOverrideBaseAttackBonus;
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetGender(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto gender = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(gender >= 0);
          ASSERT_OR_THROW(gender <= 255);

        pCreature->m_pStats->m_nGender = gender;
        pCreature->m_cAppearance.m_nGender = gender;
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::RestoreFeats(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        pCreature->m_pStats->ResetFeatRemainingUses();
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::RestoreSpecialAbilities(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        pCreature->m_pStats->ResetSpellLikeAbilities();
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::RestoreSpells(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto level = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::RestoreItems(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        pCreature->RestoreItemProperties();
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetSize(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto size = Services::Events::ExtractArgument<int32_t>(args);

        pCreature->m_nCreatureSize = size;
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetSkillPointsRemaining(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_pStats->m_nSkillPointsRemaining;
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetSkillPointsRemaining(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto points = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(points >= 0);
          ASSERT_OR_THROW(points <= 65535);

        pCreature->m_pStats->m_nSkillPointsRemaining = static_cast<uint16_t>(points);
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetRacialType(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto race = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(race >= Constants::RacialType::MIN);
          ASSERT_OR_THROW(race <= Constants::RacialType::MAX);

        pCreature->m_pStats->m_nRace = static_cast<uint16_t>(race);
    }
    return Services::Events::Arguments();
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
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetWalkRateCap(ArgumentStack&& args)
{
    static NWNXLib::Hooking::FunctionHook* pGetWalkRate_hook;

    if (!pGetWalkRate_hook)
    {
        pGetWalkRate_hook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN12CNWSCreature11GetWalkRateEv>(
            +[](CNWSCreature *pThis) -> float
            {
                float fWalkRate = pGetWalkRate_hook->CallOriginal<float>(pThis);

                auto cap = g_plugin->GetServices()->m_perObjectStorage->Get<float>(pThis, "WALK_RATE_CAP");
                return (cap && *cap < fWalkRate) ? *cap : fWalkRate;

            });
    }

    if (auto *pCreature = creature(args))
    {
        const auto fWalkRateCap = Services::Events::ExtractArgument<float>(args);

        if (fWalkRateCap < 0.0) // remove the override
        {
            g_plugin->GetServices()->m_perObjectStorage->Remove(pCreature, "WALK_RATE_CAP");
        }
        else
        {
            g_plugin->GetServices()->m_perObjectStorage->Set(pCreature, "WALK_RATE_CAP", fWalkRateCap, true);
        }
    }

    return Services::Events::Arguments();
}

ArgumentStack Creature::SetGold(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto gold = Services::Events::ExtractArgument<int32_t>(args);

        pCreature->SetGold(gold);
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetCorpseDecayTime(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto nDecayTime = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(nDecayTime >= 0);
        pCreature->m_nDecayTime = nDecayTime;
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetBaseSavingThrow(ArgumentStack&& args)
{
    // NOTE: The misc fields are used for creature save override, and will mess with ELC.
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto which = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetBaseSavingThrow(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto which = Services::Events::ExtractArgument<int32_t>(args);
        const auto value = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::LevelUp(ArgumentStack&& args)
{

    static NWNXLib::Hooking::FunctionHook* pCanLevelUp_hook;
    static NWNXLib::Hooking::FunctionHook* pValidateLevelUp_hook;
    static bool bSkipLevelUpValidation = false;
    if (!pValidateLevelUp_hook)
    {
        try
        {
            pCanLevelUp_hook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats10CanLevelUpEv>(
                    +[](CNWSCreatureStats *pThis) -> int32_t
                    {
                        if (bSkipLevelUpValidation)
                        {
                            // NPCs can have at most 60 levels
                            ASSERT(!pThis->m_bIsPC);
                            return pThis->GetLevel(false) < 60;
                        }
                        return pCanLevelUp_hook->CallOriginal<int32_t>(pThis);
                    });
        }
        catch (...)
        {
            LOG_NOTICE("NWNX_MaxLevel will manage CanLevelUp.");
        }

        pValidateLevelUp_hook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats15ValidateLevelUpEP13CNWLevelStatshhh>(
                +[](CNWSCreatureStats *pThis, CNWLevelStats *pLevelStats, uint8_t nDomain1, uint8_t nDomain2, uint8_t nSchool) -> uint32_t
                {
                    if (bSkipLevelUpValidation)
                    {
                        ASSERT(!pThis->m_bIsPC);
                        pThis->LevelUp(pLevelStats, nDomain1, nDomain2, nSchool, true);
                        pThis->UpdateCombatInformation();
                        return 0;
                    }
                    return pValidateLevelUp_hook->CallOriginal<uint32_t>(pThis, pLevelStats, nDomain1, nDomain2, nSchool);
                });
    }

    if (auto *pCreature = creature(args))
    {
        if (pCreature->m_bPlayerCharacter)
        {
            LOG_WARNING("LevelUp() does not work on PCs");
            return Services::Events::Arguments();
        }

        const auto cls = Services::Events::ExtractArgument<int32_t>(args);
        const auto count = Services::Events::ExtractArgument<int32_t>(args);

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
    return Services::Events::Arguments();
}

ArgumentStack Creature::LevelDown(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        if (pCreature->m_bPlayerCharacter)
        {
            LOG_WARNING("LevelDown() does not work on PCs");
            return Services::Events::Arguments();
        }

        auto count = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetChallengeRating(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto fCR = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fCR >= 0.0);
        pCreature->m_pStats->m_fChallengeRating = fCR;
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetAttackBonus(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pCreature = creature(args))
    {
        const auto isMelee = Services::Events::ExtractArgument<int32_t>(args);
        const auto isTouchAttack = Services::Events::ExtractArgument<int32_t>(args);
        const auto isOffhand = Services::Events::ExtractArgument<int32_t>(args);
        const auto includeBaseAttackBonus = Services::Events::ExtractArgument<int32_t>(args);

        if (isMelee)
        {
            retVal = pCreature->m_pStats->GetMeleeAttackBonus(isOffhand, includeBaseAttackBonus, isTouchAttack);
        }
        else
        {
            retVal = pCreature->m_pStats->GetRangedAttackBonus(includeBaseAttackBonus, isTouchAttack);
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::GetHighestLevelOfFeat(ArgumentStack&& args)
{
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        retval = pCreature->m_pStats->GetHighestLevelOfFeat(feat);
    }
    return Services::Events::Arguments(retval);
}

ArgumentStack Creature::GetFeatRemainingUses(ArgumentStack&& args)
{
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        retval = pCreature->m_pStats->GetFeatRemainingUses(feat);
    }
    return Services::Events::Arguments(retval);
}

ArgumentStack Creature::GetFeatTotalUses(ArgumentStack&& args)
{
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        retval = pCreature->m_pStats->GetFeatTotalUses(feat);
    }
    return Services::Events::Arguments(retval);
}

ArgumentStack Creature::SetFeatRemainingUses(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        const auto uses = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(uses >= 0);
          ASSERT_OR_THROW(uses <= 255);

        pCreature->m_pStats->SetFeatRemainingUses(feat, uses);
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetTotalEffectBonus(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pCreature = creature(args))
    {
        CNWSObject *versus = NULL;
        const auto bonusType = Services::Events::ExtractArgument<int32_t>(args);
        const auto versus_id = Services::Events::ExtractArgument<ObjectID>(args);
        if (versus_id != Constants::OBJECT_INVALID)
        {
            CGameObject *pObject = API::Globals::AppManager()->m_pServerExoApp->GetGameObject(versus_id);
            versus = Utils::AsNWSObject(pObject);
        }

        const auto isElementalDamage = Services::Events::ExtractArgument<int32_t>(args);
        const auto isForceMax = Services::Events::ExtractArgument<int32_t>(args);
        const auto saveType = Services::Events::ExtractArgument<int32_t>(args);
        const auto saveSpecificType = Services::Events::ExtractArgument<int32_t>(args);
        const auto skill = Services::Events::ExtractArgument<int32_t>(args);
        const auto abilityScore = Services::Events::ExtractArgument<int32_t>(args);
        const auto isOffhand = Services::Events::ExtractArgument<int32_t>(args);
        retVal = pCreature->GetTotalEffectBonus(bonusType, versus, isElementalDamage, isForceMax, saveType, saveSpecificType, skill, abilityScore, isOffhand);
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetOriginalName(ArgumentStack&& args)
{

    if (auto *pCreature = creature(args))
    {
        const auto name = Services::Events::ExtractArgument<std::string>(args);
        const auto isLastName = Services::Events::ExtractArgument<int32_t>(args);

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
    }

    return Services::Events::Arguments();
}

ArgumentStack Creature::GetOriginalName(ArgumentStack&& args)
{
    std::string retVal;

    if (auto *pCreature = creature(args))
    {
        const auto isLastName = Services::Events::ExtractArgument<int32_t>(args);

        if (isLastName)
        {
            retVal = Utils::ExtractLocString(pCreature->m_pStats->m_lsLastName);
        }
        else
        {
            retVal = Utils::ExtractLocString(pCreature->m_pStats->m_lsFirstName);
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetSpellResistance(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto sr = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(sr >= -127);
          ASSERT_OR_THROW(sr <= 128);
        pCreature->m_pStats->SetSpellResistance(static_cast<int8_t>(sr));
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetAnimalCompanionCreatureType(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto creatureType = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(creatureType >= 0);

        pCreature->m_pStats->m_nAnimalCompanionCreatureType = creatureType;
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetFamiliarCreatureType(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto creatureType = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(creatureType >= 0);

        pCreature->m_pStats->m_nFamiliarCreatureType = creatureType;
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetAnimalCompanionName(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto name = Services::Events::ExtractArgument<std::string>(args);

        pCreature->m_pStats->m_sAnimalCompanionName = CExoString(name.c_str());
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetFamiliarName(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto name = Services::Events::ExtractArgument<std::string>(args);

        pCreature->m_pStats->m_sFamiliarName = CExoString(name.c_str());
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetDisarmable(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_bDisarmable;
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetDisarmable(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto disarmable = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(disarmable <= 1);
        ASSERT_OR_THROW(disarmable >= 0);

        pCreature->m_bDisarmable = disarmable;
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::SetFaction(ArgumentStack&& args)
{
    if (auto *pCreature = creature(args))
    {
        const auto factionid = Services::Events::ExtractArgument<int32_t>(args);
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
    return Services::Events::Arguments();
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
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::GetFlatFooted(ArgumentStack&& args)
{
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->GetFlatFooted();
    }
    return Services::Events::Arguments(retVal);
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

            retVal = Encoding::ToBase64(std::vector<uint8_t>(pData, pData+dataLength));
            delete[] pData;
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::DeserializeQuickbar(ArgumentStack&& args)
{
    int32_t retVal = false;

    if (auto *pCreature = creature(args))
    {
        const auto serializedB64 = Services::Events::ExtractArgument<std::string>(args);
          ASSERT_OR_THROW(!serializedB64.empty());

        std::vector<uint8_t> serialized = Encoding::FromBase64(serializedB64);

        if (serialized.empty() || serialized.size() < 14*4)
            return Services::Events::Arguments(retVal);

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

    return Services::Events::Arguments(retVal);
}

void Creature::InitCasterLevelHooks()
{
    auto hooker = g_plugin->GetServices()->m_hooks.get();
    hooker->RequestSharedHook<Functions::_ZN17CNWSCreatureStats13GetClassLevelEhi, uint8_t>(&CNWSCreatureStats__GetClassLevel);
    hooker->RequestSharedHook<Functions::_ZN25CNWVirtualMachineCommands28ExecuteCommandGetCasterLevelEii, int32_t>(&CNWVirtualMachineCommands__ExecuteCommandGetCasterLevel);
    hooker->RequestSharedHook<Functions::_ZN25CNWVirtualMachineCommands25ExecuteCommandResistSpellEii, int32_t>(&CNWVirtualMachineCommands__ExecuteCommandResistSpell);
    hooker->RequestSharedHook<Functions::_ZN11CGameEffect10SetCreatorEj, void>(&CGameEffect__SetCreator);

    s_bCasterLevelHooksInitialized = true;
}

ArgumentStack Creature::SetCasterLevelModifier(ArgumentStack&& args)
{
    if (!s_bCasterLevelHooksInitialized)
        InitCasterLevelHooks();

    if (auto* pCreature = creature(args))
    {
        const auto nClass = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(nClass >= 0);
        ASSERT_OR_THROW(nClass <= Constants::ClassType::MAX);
        const auto nModifier = Services::Events::ExtractArgument<int32_t>(args);
        const bool bPersist = !!Services::Events::ExtractArgument<int32_t>(args);

        if (nModifier)
            GetServices()->m_perObjectStorage->Set(pCreature, "CASTERLEVEL_MODIFIER" + std::to_string(nClass), nModifier, bPersist);
        else
            GetServices()->m_perObjectStorage->Remove(pCreature, "CASTERLEVEL_MODIFIER" + std::to_string(nClass));
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetCasterLevelModifier(ArgumentStack&& args)
{
    if (!s_bCasterLevelHooksInitialized)
        InitCasterLevelHooks();

    int32_t retVal = 0;

    if (auto* pCreature = creature(args))
    {
        const auto nClass = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(nClass >= 0);
        ASSERT_OR_THROW(nClass <= Constants::ClassType::MAX);
        auto nModifier = GetServices()->m_perObjectStorage->Get<int>(pCreature, "CASTERLEVEL_MODIFIER" + std::to_string(nClass));
        if (nModifier)
            retVal = nModifier.value();
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetCasterLevelOverride(ArgumentStack&& args)
{
    if (!s_bCasterLevelHooksInitialized)
        InitCasterLevelHooks();

    if (auto* pCreature = creature(args))
    {
        const auto nClass = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(nClass >= 0);
        ASSERT_OR_THROW(nClass <= Constants::ClassType::MAX);
        const auto nLevel = Services::Events::ExtractArgument<int32_t>(args);
        const bool bPersist = !!Services::Events::ExtractArgument<int32_t>(args);

        if (nLevel > 0)
            GetServices()->m_perObjectStorage->Set(pCreature, "CASTERLEVEL_OVERRIDE" + std::to_string(nClass), nLevel, bPersist);
        else
            GetServices()->m_perObjectStorage->Remove(pCreature, "CASTERLEVEL_OVERRIDE" + std::to_string(nClass));
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetCasterLevelOverride(ArgumentStack&& args)
{
    if (!s_bCasterLevelHooksInitialized)
        InitCasterLevelHooks();

    int32_t retVal = -1;

    if (auto* pCreature = creature(args))
    {
        const auto nClass = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(nClass >= 0);
        ASSERT_OR_THROW(nClass <= Constants::ClassType::MAX);
        auto nCasterLevel = GetServices()->m_perObjectStorage->Get<int>(pCreature, "CASTERLEVEL_OVERRIDE" + std::to_string(nClass));
        if (nCasterLevel)
            retVal = nCasterLevel.value();
    }

    return Services::Events::Arguments(retVal);
}

void Creature::CNWSCreatureStats__GetClassLevel(bool before, CNWSCreatureStats* thisPtr, uint8_t nMultiClass, BOOL)
{
    static int32_t nModifier;

    if (!s_bAdjustCasterLevel || nMultiClass >= thisPtr->m_nNumMultiClasses)
        return;

    auto nClass = thisPtr->m_ClassInfo[nMultiClass].m_nClass;
    if (nClass > Constants::ClassType::MAX)
        return;

    if (!before)
    {
        thisPtr->m_ClassInfo[nMultiClass].m_nLevel -= nModifier;
        return;
    }

    nModifier = 0;

    auto nLevelOverride = g_plugin->GetServices()->m_perObjectStorage->Get<int>(thisPtr->m_pBaseCreature, "CASTERLEVEL_OVERRIDE" + std::to_string(nClass));
    if (nLevelOverride)
    {
        auto nLevel = std::max(nLevelOverride.value(), 255);
        nModifier = nLevel - thisPtr->m_ClassInfo[nMultiClass].m_nLevel;
        thisPtr->m_ClassInfo[nMultiClass].m_nLevel += nModifier;
        return;
    }

    auto nLevelModifier = g_plugin->GetServices()->m_perObjectStorage->Get<int>(thisPtr->m_pBaseCreature, "CASTERLEVEL_MODIFIER" + std::to_string(nClass));
    if (nLevelModifier)
        nModifier = nLevelModifier.value();

    //Make sure m_nLevel doesn't over/underflow
    nModifier = std::min(nModifier, 255 - thisPtr->m_ClassInfo[nMultiClass].m_nLevel);
    if (nModifier < 0)
        nModifier = -std::min(-nModifier, static_cast<int32_t>(thisPtr->m_ClassInfo[nMultiClass].m_nLevel));

    thisPtr->m_ClassInfo[nMultiClass].m_nLevel += nModifier;
}

void Creature::CNWVirtualMachineCommands__ExecuteCommandGetCasterLevel(bool before, CNWVirtualMachineCommands*, int32_t, int32_t)
{
    s_bAdjustCasterLevel = before;
}

void Creature::CNWVirtualMachineCommands__ExecuteCommandResistSpell(bool before, CNWVirtualMachineCommands*, int32_t, int32_t)
{
    s_bAdjustCasterLevel = before;
}

void Creature::CGameEffect__SetCreator(bool before, CGameEffect*, OBJECT_ID)
{
    s_bAdjustCasterLevel = before;
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
    return Services::Events::Arguments();
}

void Creature::InitCriticalMultiplierHook()
{
    static NWNXLib::Hooking::FunctionHook* pGetCriticalHitMultiplier_hook;
    if (!pGetCriticalHitMultiplier_hook)
    {
        g_plugin->GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats24GetCriticalHitMultiplierEi>(
            +[](CNWSCreatureStats *pThis, int32_t bOffHand = false) -> int32_t
            {
                int32_t retVal;
                if (!bOffHand) //mainhand
                {
                    if (auto critMultOvr = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_MULTIPLIER_OVERRIDE!1"))
                    {
                        retVal = critMultOvr.value();
                    }
                    else if (auto critMultOvr = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_MULTIPLIER_OVERRIDE!0"))
                    {
                        retVal = critMultOvr.value();
                    }
                    else if (auto critMultMod = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_MULTIPLIER_MODIFIER!1"))
                    {
                        auto critMultOrig = pGetCriticalHitMultiplier_hook->CallOriginal<int32_t>(pThis, bOffHand);
                        retVal = critMultOrig + critMultMod.value();
                    }
                    else if (auto critMultMod = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_MULTIPLIER_MODIFIER!0"))
                    {
                        auto critMultOrig = pGetCriticalHitMultiplier_hook->CallOriginal<int32_t>(pThis, bOffHand);
                        retVal = critMultOrig + critMultMod.value();
                    }
                    else
                    {
                        retVal = pGetCriticalHitMultiplier_hook->CallOriginal<int32_t>(pThis, bOffHand);
                    }
                }
                else //Offhand
                {
                    if (auto critMultOvr = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_MULTIPLIER_OVERRIDE!2"))
                    {
                        retVal = critMultOvr.value();
                    }
                    else if (auto critMultOvr = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_MULTIPLIER_OVERRIDE!0"))
                    {
                        retVal = critMultOvr.value();
                    }
                    else if (auto critMultMod = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_MULTIPLIER_MODIFIER!2"))
                    {
                        auto critMultOrig = pGetCriticalHitMultiplier_hook->CallOriginal<int32_t>(pThis, bOffHand);
                        retVal = critMultOrig + critMultMod.value();
                    }
                    else if (auto critMultMod = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_MULTIPLIER_MODIFIER!0"))
                    {
                        auto critMultOrig = pGetCriticalHitMultiplier_hook->CallOriginal<int32_t>(pThis, bOffHand);
                        retVal = critMultOrig + critMultMod.value();
                    }
                      else
                    {
                        retVal = pGetCriticalHitMultiplier_hook->CallOriginal<int32_t>(pThis, bOffHand);
                    }
                }

                  return retVal > 0 ? retVal : 0;
            });
        pGetCriticalHitMultiplier_hook = g_plugin->GetServices()->m_hooks->FindHookByAddress(Functions::_ZN17CNWSCreatureStats24GetCriticalHitMultiplierEi);
    }
    s_bCriticalMultiplierHooksInitialized = true;
}

ArgumentStack Creature::SetCriticalMultiplierModifier(ArgumentStack&& args)
{
    if (!s_bCriticalMultiplierHooksInitialized)
        InitCriticalMultiplierHook();

    if (auto* pCreature = creature(args))
    {
        const auto nModifier = Services::Events::ExtractArgument<int32_t>(args);
        auto nHand = Services::Events::ExtractArgument<int32_t>(args);
        const bool persist = !!Services::Events::ExtractArgument<int32_t>(args);

        if (nHand < 0 || 2 < nHand)
            nHand = 0;

        if (nModifier)
            g_plugin->GetServices()->m_perObjectStorage->Set(pCreature, "CRITICAL_MULTIPLIER_MODIFIER!" + std::to_string(nHand), nModifier, persist);
        else
            g_plugin->GetServices()->m_perObjectStorage->Remove(pCreature, "CRITICAL_MULTIPLIER_MODIFIER!" + std::to_string(nHand));
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetCriticalMultiplierModifier(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto* pCreature = creature(args))
    {
        auto nHand = Services::Events::ExtractArgument<int32_t>(args);

        if (nHand < 0 || 2 < nHand)
            nHand = 0;

        auto nModifier = GetServices()->m_perObjectStorage->Get<int32_t>(pCreature, "CRITICAL_MULTIPLIER_MODIFIER!" + std::to_string(nHand));
        if (nModifier)
            retVal = nModifier.value();
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetCriticalMultiplierOverride(ArgumentStack&& args)
{
    if (!s_bCriticalMultiplierHooksInitialized)
        InitCriticalMultiplierHook();

    if (auto* pCreature = creature(args))
    {
        const auto nOverride = Services::Events::ExtractArgument<int32_t>(args);
        auto nHand = Services::Events::ExtractArgument<int32_t>(args);
        const bool persist = !!Services::Events::ExtractArgument<int32_t>(args);

        if (nHand < 0 || 2 < nHand)
            nHand = 0;

        if (nOverride >= 0)
            g_plugin->GetServices()->m_perObjectStorage->Set(pCreature, "CRITICAL_MULTIPLIER_OVERRIDE!" + std::to_string(nHand), nOverride, persist);
        else
            g_plugin->GetServices()->m_perObjectStorage->Remove(pCreature, "CRITICAL_MULTIPLIER_OVERRIDE!" + std::to_string(nHand));
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetCriticalMultiplierOverride(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto* pCreature = creature(args))
    {
        auto nHand = Services::Events::ExtractArgument<int32_t>(args);

        if (nHand < 0 || 2 < nHand)
            nHand = 0;

        auto nOverride = GetServices()->m_perObjectStorage->Get<int32_t>(pCreature, "CRITICAL_MULTIPLIER_OVERRIDE!" + std::to_string(nHand));
        if (nOverride)
            retVal = nOverride.value();
    }
    return Services::Events::Arguments(retVal);
}

void Creature::InitCriticalRangeHook()
{
    static NWNXLib::Hooking::FunctionHook* pGetCriticalHitRoll_hook;
    if (!pGetCriticalHitRoll_hook)
    {
        g_plugin->GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats18GetCriticalHitRollEi>(
            +[](CNWSCreatureStats *pThis, int32_t bOffHand = false) -> int32_t
            {
                int32_t retVal;
                if (!bOffHand) //mainhand
                {
                    if (auto critRngOvr = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_RANGE_OVERRIDE!1"))
                    {
                        retVal = critRngOvr.value();
                    }
                    else if (auto critRngOvr = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_RANGE_OVERRIDE!0"))
                    {
                        retVal = critRngOvr.value();
                    }
                    else if (auto critRngMod = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_RANGE_MODIFIER!1"))
                    {
                        auto critRngOrig = pGetCriticalHitRoll_hook->CallOriginal<int32_t>(pThis, bOffHand);
                        retVal = critRngOrig + critRngMod.value();
                    }
                    else if (auto critRngMod = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_RANGE_MODIFIER!0"))
                    {
                        auto critRngOrig = pGetCriticalHitRoll_hook->CallOriginal<int32_t>(pThis, bOffHand);
                        retVal = critRngOrig + critRngMod.value();
                    }
                    else
                    {
                        retVal = pGetCriticalHitRoll_hook->CallOriginal<int32_t>(pThis, bOffHand);
                    }
                }
                else //Offhand
                {
                    if (auto critRngOvr = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_RANGE_OVERRIDE!2"))
                    {
                        retVal = critRngOvr.value();
                    }
                    else if (auto critRngOvr = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_RANGE_OVERRIDE!0"))
                    {
                        retVal = critRngOvr.value();
                    }
                    else if (auto critRngMod = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_RANGE_MODIFIER!2"))
                    {
                        auto critRngOrig = pGetCriticalHitRoll_hook->CallOriginal<int32_t>(pThis, bOffHand);
                        retVal = critRngOrig + critRngMod.value();
                    }
                    else if (auto critRngMod = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pThis->m_pBaseCreature->m_idSelf, "CRITICAL_RANGE_MODIFIER!0"))
                    {
                        auto critRngOrig = pGetCriticalHitRoll_hook->CallOriginal<int32_t>(pThis, bOffHand);
                        retVal = critRngOrig + critRngMod.value();
                    }
                    else
                    {
                        retVal = pGetCriticalHitRoll_hook->CallOriginal<int32_t>(pThis, bOffHand);
                    }
                }
                return std::clamp(retVal, 0, 20);
            });
        pGetCriticalHitRoll_hook = g_plugin->GetServices()->m_hooks->FindHookByAddress(Functions::_ZN17CNWSCreatureStats18GetCriticalHitRollEi);
    }
    s_bCriticalRangeHooksInitialized = true;
}

ArgumentStack Creature::SetCriticalRangeModifier(ArgumentStack&& args)
{
    if (!s_bCriticalRangeHooksInitialized)
        InitCriticalRangeHook();

    if (auto* pCreature = creature(args))
    {
        const auto nModifier = Services::Events::ExtractArgument<int32_t>(args);
        auto nHand = Services::Events::ExtractArgument<int32_t>(args);
        const bool persist = !!Services::Events::ExtractArgument<int32_t>(args);

        if (nHand < 0 || 2 < nHand)
            nHand = 0;

        if (nModifier)
            g_plugin->GetServices()->m_perObjectStorage->Set(pCreature, "CRITICAL_RANGE_MODIFIER!" + std::to_string(nHand), nModifier, persist);
        else
            g_plugin->GetServices()->m_perObjectStorage->Remove(pCreature, "CRITICAL_RANGE_MODIFIER!" + std::to_string(nHand));
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetCriticalRangeModifier(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto* pCreature = creature(args))
    {
        auto nHand = Services::Events::ExtractArgument<int32_t>(args);

        if (nHand < 0 || 2 < nHand)
            nHand = 0;

        auto nModifier = GetServices()->m_perObjectStorage->Get<int32_t>(pCreature, "CRITICAL_RANGE_MODIFIER!" + std::to_string(nHand));
        if (nModifier)
            retVal = nModifier.value();
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::SetCriticalRangeOverride(ArgumentStack&& args)
{
    if (!s_bCriticalRangeHooksInitialized)
        InitCriticalRangeHook();

    if (auto* pCreature = creature(args))
    {
        const auto nOverride = Services::Events::ExtractArgument<int32_t>(args);
        auto nHand = Services::Events::ExtractArgument<int32_t>(args);
        const bool persist = !!Services::Events::ExtractArgument<int32_t>(args);

        if (nHand < 0 || 2 < nHand)
            nHand = 0;

        if (nOverride >= 0)
            g_plugin->GetServices()->m_perObjectStorage->Set(pCreature, "CRITICAL_RANGE_OVERRIDE!" + std::to_string(nHand), nOverride, persist);
        else
            g_plugin->GetServices()->m_perObjectStorage->Remove(pCreature, "CRITICAL_RANGE_OVERRIDE!" + std::to_string(nHand));
    }
    return Services::Events::Arguments();
}

ArgumentStack Creature::GetCriticalRangeOverride(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto* pCreature = creature(args))
    {
        auto nHand = Services::Events::ExtractArgument<int32_t>(args);

        if (nHand < 0 || 2 < nHand)
            nHand = 0;

        auto nOverride = GetServices()->m_perObjectStorage->Get<int32_t>(pCreature, "CRITICAL_RANGE_OVERRIDE!" + std::to_string(nHand));
        if (nOverride)
            retVal = nOverride.value();
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Creature::AddAssociate(ArgumentStack&& args)
{
    if (auto* pCreature = creature(args))
    {
        auto oidAssociate = Services::Events::ExtractArgument<ObjectID>(args);
          ASSERT_OR_THROW(oidAssociate != Constants::OBJECT_INVALID);
        auto associateType = Services::Events::ExtractArgument<int32_t>(args);
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

    return Services::Events::Arguments();
}

}
