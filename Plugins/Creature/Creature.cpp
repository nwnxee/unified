#include "Creature.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerInfo.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CNWSStats_Spell.hpp"
#include "API/CNWSStats_SpellLikeAbility.hpp"
#include "API/CExoArrayList.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWClass.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "ViewPtr.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Creature::Creature> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Creature",
        "Functions exposing additional creature properties",
        "various / sherincall",
        "sherincall@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Creature::Creature(params);
    return g_plugin;
}


namespace Creature {

Creature::Creature(const Plugin::CreateParams& params)
    : Plugin(params)
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
    REGISTER(SetAlignmentGoodEvil);
    REGISTER(SetAlignmentLawChaos);
    REGISTER(GetClericDomain);
    REGISTER(SetClericDomain);
    REGISTER(GetWizardSpecialization);
    REGISTER(SetWizardSpecialization);
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

#undef REGISTER
}

Creature::~Creature()
{
}

CNWSCreature *Creature::creature(ArgumentStack& args)
{
    const auto creatureId = Services::Events::ExtractArgument<Types::ObjectID>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Creature function called on OBJECT_INVALID");
        return nullptr;
    }

    return Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);
}

ArgumentStack Creature::AddFeat(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

        pCreature->m_pStats->AddFeat(static_cast<uint16_t>(feat));
    }

    return stack;
}

ArgumentStack Creature::AddFeatByLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    return stack;
}

ArgumentStack Creature::RemoveFeat(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

        pCreature->m_pStats->RemoveFeat(static_cast<uint16_t>(feat));

    }
    return stack;
}

ArgumentStack Creature::GetKnowsFeat(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = 0;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

        retVal = pCreature->m_pStats->HasFeat(static_cast<uint16_t>(feat));
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::GetFeatCountByLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::GetFeatByLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::GetFeatCount(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_pStats->m_lstFeats.num;
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::GetFeatByIndex(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);

        if (index < pCreature->m_pStats->m_lstFeats.num)
        {
            retVal = pCreature->m_pStats->m_lstFeats.element[index];
        }
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::GetMeetsFeatRequirements(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}


ArgumentStack Creature::GetSpecialAbility(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, id);
    Services::Events::InsertArgument(stack, ready);
    Services::Events::InsertArgument(stack, level);
    return stack;
}

ArgumentStack Creature::GetSpecialAbilityCount(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::AddSpecialAbility(ArgumentStack&& args)
{
    ArgumentStack stack;
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
                return stack;
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
    return stack;
}

ArgumentStack Creature::RemoveSpecialAbility(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    return stack;
}

ArgumentStack Creature::SetSpecialAbility(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    return stack;
}

ArgumentStack Creature::GetClassByLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetBaseAC(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto ac = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(ac >= -128);
          ASSERT_OR_THROW(ac <= 127);

        pCreature->m_pStats->m_nACNaturalBase = static_cast<int8_t>(ac);
    }
    return stack;
}

ArgumentStack Creature::GetBaseAC(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_pStats->m_nACNaturalBase;
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetRawAbilityScore(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    return stack;
}

ArgumentStack Creature::GetRawAbilityScore(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::ModifyRawAbilityScore(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    return stack;
}

ArgumentStack Creature::GetPrePolymorphAbilityScore(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::GetMemorisedSpell(ArgumentStack&& args)
{
    ArgumentStack stack;
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
                if (auto *pSpell = classInfo.GetMemorizedSpellInSlotDetails(static_cast<unsigned char>(level),
                                                                            static_cast<unsigned char>(index)))
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
    Services::Events::InsertArgument(stack, id);
    Services::Events::InsertArgument(stack, ready);
    Services::Events::InsertArgument(stack, meta);
    Services::Events::InsertArgument(stack, domain);
    return stack;
}

ArgumentStack Creature::GetMemorisedSpellCountByLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
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
                retVal = classInfo.GetNumberMemorizedSpellSlots(static_cast<unsigned char>(level));
                break;
            }
        }
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetMemorisedSpell(ArgumentStack&& args)
{
    ArgumentStack stack;
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
                classInfo.SetMemorizedSpellSlot(static_cast<unsigned char>(level),
                                                static_cast<unsigned char>(index),
                                                static_cast<uint32_t>(id),
                                                domain,
                                                static_cast<unsigned char>(meta));

                classInfo.SetMemorizedSpellInSlotReady(static_cast<unsigned char>(level),
                                                       static_cast<unsigned char>(index),
                                                       ready);

                break;
            }
        }
    }
    return stack;
}

ArgumentStack Creature::GetRemainingSpellSlots(ArgumentStack&& args)
{
    ArgumentStack stack;
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
                retVal = classInfo.GetSpellsPerDayLeft(static_cast<unsigned char>(level));
                break;
            }
        }
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetRemainingSpellSlots(ArgumentStack&& args)
{
    ArgumentStack stack;
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
                classInfo.SetSpellsPerDayLeft(static_cast<unsigned char>(level), static_cast<unsigned char>(slots));
                break;
            }
        }
    }
    return stack;
}

ArgumentStack Creature::GetMaxSpellSlots(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::GetKnownSpell(ArgumentStack&& args)
{
    ArgumentStack stack;
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
                        static_cast<unsigned char>(level),
                        static_cast<unsigned char>(index)));
                break;
            }
        }
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::GetKnownSpellCount(ArgumentStack&& args)
{
    ArgumentStack stack;
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
                retVal = classInfo.GetNumberKnownSpells(static_cast<unsigned char>(level));
                break;
            }
        }
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::RemoveKnownSpell(ArgumentStack&& args)
{
    ArgumentStack stack;
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
                classInfo.RemoveKnownSpell(static_cast<unsigned char>(level), static_cast<uint32_t>(spellId));
                break;
            }
        }
    }
    return stack;
}

ArgumentStack Creature::AddKnownSpell(ArgumentStack&& args)
{
    ArgumentStack stack;
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
                classInfo.AddKnownSpell(static_cast<unsigned char>(level), static_cast<uint32_t>(spellId));
                break;
            }
        }
    }
    return stack;
}

ArgumentStack Creature::ClearMemorisedKnownSpells(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    return stack;
}

ArgumentStack Creature::ClearMemorisedSpell(ArgumentStack&& args)
{
    ArgumentStack stack;
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
                classInfo.ClearMemorizedSpellSlot(static_cast<unsigned char>(level),
                                                  static_cast<unsigned char>(index));

                break;
            }
        }
    }
    return stack;
}

ArgumentStack Creature::GetMaxHitPointsByLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetMaxHitPointsByLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    return stack;
}

ArgumentStack Creature::SetMovementRate(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto rate = Services::Events::ExtractArgument<int32_t>(args);
        pCreature->m_pStats->SetMovementRate(rate);
    }
    return stack;
}

ArgumentStack Creature::GetMovementRateFactor(ArgumentStack&& args)
{
    ArgumentStack stack;
    float retVal = 0;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->GetMovementRateFactor();
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetMovementRateFactor(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const float factor = Services::Events::ExtractArgument<float>(args);
        pCreature->SetMovementRateFactor(factor);
    }
    return stack;
}

ArgumentStack Creature::SetAlignmentGoodEvil(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto value = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(value <= 32767);
          ASSERT_OR_THROW(value >= -32768);
        pCreature->m_pStats->m_nAlignmentGoodEvil = static_cast<int16_t>(value);
    }
    return stack;
}

ArgumentStack Creature::SetAlignmentLawChaos(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto value = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(value <= 32767);
          ASSERT_OR_THROW(value >= -32768);
        pCreature->m_pStats->m_nAlignmentLawChaos = static_cast<int16_t>(value);
    }
    return stack;
}

ArgumentStack Creature::GetClericDomain(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW((index == 1) || (index == 2));

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == Constants::ClassType::Cleric)
            {
                retVal = classInfo.m_nDomain[index - 1];
                break;
            }
        }
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetClericDomain(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(index >= 1);
          ASSERT_OR_THROW(index <= 2);
        const auto domain = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(domain <= 255);
          ASSERT_OR_THROW(domain >= 0);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == Constants::ClassType::Cleric)
            {
                classInfo.m_nDomain[index - 1] = static_cast<uint8_t>(domain);
                break;
            }
        }
    }
    return stack;
}

ArgumentStack Creature::GetWizardSpecialization(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == Constants::ClassType::Wizard)
            {
                retVal = classInfo.m_nSchool;
                break;
            }
        }
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetWizardSpecialization(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto school = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(school <= 255);
          ASSERT_OR_THROW(school >= 0);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == Constants::ClassType::Wizard)
            {
                classInfo.m_nSchool = static_cast<uint8_t>(school);
                break;
            }
        }
    }
    return stack;
}

ArgumentStack Creature::GetSoundset(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_nSoundSet;
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetSoundset(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto soundset = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(soundset >= 0);

        pCreature->m_nSoundSet = static_cast<uint16_t>(soundset);
    }
    return stack;
}

ArgumentStack Creature::SetSkillRank(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    return stack;
}

ArgumentStack Creature::SetClassByPosition(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    return stack;
}

ArgumentStack Creature::SetLevelByPosition(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    return stack;
}

ArgumentStack Creature::SetBaseAttackBonus(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto bab = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(bab >= 0);
          ASSERT_OR_THROW(bab <= 254);

        pCreature->m_pStats->m_nBaseAttackBonus = static_cast<uint8_t>(bab);
    }
    return stack;
}

ArgumentStack Creature::GetAttacksPerRound(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        const auto bBaseAPR = Services::Events::ExtractArgument<int32_t>(args);

        if (bBaseAPR || pCreature->m_pStats->m_nOverrideBaseAttackBonus == 0)
            retVal = pCreature->m_pStats->GetAttacksPerRound();
        else
            retVal = pCreature->m_pStats->m_nOverrideBaseAttackBonus;
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetGender(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto gender = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(gender >= 0);
          ASSERT_OR_THROW(gender <= 255);

        pCreature->m_pStats->m_nGender = gender;
        pCreature->m_cAppearance.m_nGender = gender;
    }
    return stack;
}

ArgumentStack Creature::RestoreFeats(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        pCreature->m_pStats->ResetFeatRemainingUses();
    }
    return stack;
}

ArgumentStack Creature::RestoreSpecialAbilities(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        pCreature->m_pStats->ResetSpellLikeAbilities();
    }
    return stack;
}

ArgumentStack Creature::RestoreSpells(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    return stack;
}

ArgumentStack Creature::RestoreItems(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        pCreature->RestoreItemProperties();
    }
    return stack;
}

ArgumentStack Creature::SetSize(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto size = Services::Events::ExtractArgument<int32_t>(args);

        pCreature->m_nCreatureSize = size;
    }
    return stack;
}

ArgumentStack Creature::GetSkillPointsRemaining(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = -1;
    if (auto *pCreature = creature(args))
    {
        retVal = pCreature->m_pStats->m_nSkillPointsRemaining;
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetSkillPointsRemaining(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto points = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(points >= 0);
          ASSERT_OR_THROW(points <= 65535);

        pCreature->m_pStats->m_nSkillPointsRemaining = static_cast<uint16_t>(points);
    }
    return stack;
}

ArgumentStack Creature::SetRacialType(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto race = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(race >= Constants::RacialType::MIN);
          ASSERT_OR_THROW(race <= Constants::RacialType::MAX);

        pCreature->m_pStats->m_nRace = static_cast<uint16_t>(race);
    }
    return stack;
}

ArgumentStack Creature::GetMovementType(ArgumentStack&& args)
{
    // Mirrored in nwnx_creature.nss
    const int MOVEMENT_TYPE_STATIONARY      = 0;
    const int MOVEMENT_TYPE_WALK            = 1;
    const int MOVEMENT_TYPE_RUN             = 2;
    const int MOVEMENT_TYPE_SIDESTEP        = 3;
    const int MOVEMENT_TYPE_WALK_BACKWARDS  = 4;

    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetWalkRateCap(ArgumentStack&& args)
{
    static NWNXLib::Hooking::FunctionHook* pGetWalkRate_hook;

    if (!pGetWalkRate_hook)
    {
        GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN12CNWSCreature11GetWalkRateEv>(
            +[](CNWSCreature *pThis) -> float
            {
                float fWalkRate = pGetWalkRate_hook->CallOriginal<float>(pThis);

                auto cap = g_plugin->GetServices()->m_perObjectStorage->Get<float>(pThis, "WALK_RATE_CAP");
                return (cap && *cap < fWalkRate) ? *cap : fWalkRate;

            });
        pGetWalkRate_hook = GetServices()->m_hooks->FindHookByAddress(Functions::_ZN12CNWSCreature11GetWalkRateEv);
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
            g_plugin->GetServices()->m_perObjectStorage->Set(pCreature, "WALK_RATE_CAP", fWalkRateCap);
        }
    }

    ArgumentStack stack;
    return stack;
}

ArgumentStack Creature::SetGold(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto gold = Services::Events::ExtractArgument<int32_t>(args);

        pCreature->SetGold(gold);
    }
    return stack;
}

ArgumentStack Creature::SetCorpseDecayTime(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto nDecayTime = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(nDecayTime >= 0);
        pCreature->m_nDecayTime = nDecayTime;
    }
    return stack;
}

ArgumentStack Creature::GetBaseSavingThrow(ArgumentStack&& args)
{
    // NOTE: The misc fields are used for creature save override, and will mess with ELC.
    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetBaseSavingThrow(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    return stack;
}

ArgumentStack Creature::LevelUp(ArgumentStack&& args)
{
    ArgumentStack stack;

    static NWNXLib::Hooking::FunctionHook* pCanLevelUp_hook;
    static NWNXLib::Hooking::FunctionHook* pValidateLevelUp_hook;
    static bool bSkipLevelUpValidation = false;
    if (!pValidateLevelUp_hook)
    {
        try
        {
            GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats10CanLevelUpEv>(
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
            pCanLevelUp_hook = GetServices()->m_hooks->FindHookByAddress(Functions::_ZN17CNWSCreatureStats10CanLevelUpEv);
        }
        catch (...)
        {
            LOG_NOTICE("NWNX_MaxLevel will manage CanLevelUp.");
        }

        GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats15ValidateLevelUpEP13CNWLevelStatshhh>(
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
        pValidateLevelUp_hook = GetServices()->m_hooks->FindHookByAddress(Functions::_ZN17CNWSCreatureStats15ValidateLevelUpEP13CNWLevelStatshhh);
    }

    if (auto *pCreature = creature(args))
    {
        if (pCreature->m_bPlayerCharacter)
        {
            LOG_WARNING("LevelUp() does not work on PCs");
            return stack;
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
    return stack;
}

ArgumentStack Creature::LevelDown(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        if (pCreature->m_bPlayerCharacter)
        {
            LOG_WARNING("LevelDown() does not work on PCs");
            return stack;
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
    return stack;
}

ArgumentStack Creature::SetChallengeRating(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto fCR = Services::Events::ExtractArgument<float>(args);
          ASSERT_OR_THROW(fCR >= 0.0);
        pCreature->m_pStats->m_fChallengeRating = fCR;
    }
    return stack;
}

ArgumentStack Creature::GetAttackBonus(ArgumentStack&& args)
{
    ArgumentStack stack;
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

    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::GetHighestLevelOfFeat(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        retval = pCreature->m_pStats->GetHighestLevelOfFeat(feat);
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::GetFeatRemainingUses(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        retval = pCreature->m_pStats->GetFeatRemainingUses(feat);
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::GetFeatTotalUses(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
          ASSERT_OR_THROW(feat <= Constants::Feat::MAX);
        retval = pCreature->m_pStats->GetFeatTotalUses(feat);
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::SetFeatRemainingUses(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    return stack;
}

ArgumentStack Creature::GetTotalEffectBonus(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = -1;

    if (auto *pCreature = creature(args))
    {
        CNWSObject *versus = NULL;
        const auto bonusType = Services::Events::ExtractArgument<int32_t>(args);
        const auto versus_id = Services::Events::ExtractArgument<Types::ObjectID>(args);
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

    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetOriginalName(ArgumentStack&& args)
{
    ArgumentStack stack;

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

    return stack;
}

ArgumentStack Creature::GetOriginalName(ArgumentStack&& args)
{
    ArgumentStack stack;
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

    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Creature::SetSpellResistance(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto sr = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(sr >= -127);
          ASSERT_OR_THROW(sr <= 128);
        pCreature->m_pStats->SetSpellResistance(static_cast<int8_t>(sr));
    }
    return stack;
}

ArgumentStack Creature::SetAnimalCompanionCreatureType(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto creatureType = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(creatureType >= 0);

        pCreature->m_pStats->m_nAnimalCompanionCreatureType = creatureType;
    }
    return stack;
}

ArgumentStack Creature::SetFamiliarCreatureType(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto creatureType = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(creatureType >= 0);

        pCreature->m_pStats->m_nFamiliarCreatureType = creatureType;
    }
    return stack;
}

ArgumentStack Creature::SetAnimalCompanionName(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto name = Services::Events::ExtractArgument<std::string>(args);

        pCreature->m_pStats->m_sAnimalCompanionName = CExoString(name.c_str());
    }
    return stack;
}

ArgumentStack Creature::SetFamiliarName(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto name = Services::Events::ExtractArgument<std::string>(args);

        pCreature->m_pStats->m_sFamiliarName = CExoString(name.c_str());
    }
    return stack;
}

}
