#include "Creature.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CNWSStats_Spell.hpp"
#include "API/CNWSStats_SpellLikeAbility.hpp"
#include "API/CExoArrayListTemplatedCNWSStats_SpellLikeAbility.hpp"
#include "API/CExoArrayListTemplatedshortunsignedint.hpp"
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
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Creature::func, this, std::placeholders::_1))

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
    REGISTER(GetMaxHitPointsByLevel);
    REGISTER(SetMaxHitPointsByLevel);
    REGISTER(SetMovementRate);
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
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);  ASSERT(feat <= 65535);

        pCreature->m_pStats->AddFeat(static_cast<uint16_t>(feat));
    }

    return stack;
}

ArgumentStack Creature::AddFeatByLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto feat  = Services::Events::ExtractArgument<int32_t>(args);  ASSERT(feat <= 65535);
        const auto level = Services::Events::ExtractArgument<int32_t>(args);  ASSERT(level <= 40);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT(pLevelStats);
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
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);  ASSERT(feat <= 65535);

        pCreature->m_pStats->RemoveFeat(static_cast<uint16_t>(feat));

    }
    return stack;
}

ArgumentStack Creature::GetKnowsFeat(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = 0;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);  ASSERT(feat <= 65535);

        retval = pCreature->m_pStats->HasFeat(static_cast<uint16_t>(feat));
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::GetFeatCountByLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto level = Services::Events::ExtractArgument<int32_t>(args);  ASSERT(level <= 40);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT(pLevelStats);
            retval = pLevelStats->m_lstFeats.num;
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::GetFeatByLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto level = Services::Events::ExtractArgument<int32_t>(args);  ASSERT(level <= 40);
        const auto index = Services::Events::ExtractArgument<int32_t>(args);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT(pLevelStats);

            if (index < pLevelStats->m_lstFeats.num)
                retval = pLevelStats->m_lstFeats.element[index];
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::GetFeatCount(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        retval = pCreature->m_pStats->m_lstFeats.num;
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::GetFeatByIndex(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);

        if (index < pCreature->m_pStats->m_lstFeats.num)
        {
            retval = pCreature->m_pStats->m_lstFeats.element[index];
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::GetMeetsFeatRequirements(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);  ASSERT(feat <= 65535);
        // TODO: Need to clean up these templated arraylist APIs
        CExoArrayListTemplatedshortunsignedint unused = {};

        retval = pCreature->m_pStats->FeatRequirementsMet(static_cast<uint16_t>(feat),
                    reinterpret_cast<CExoArrayListTemplatedunsignedshort*>(&unused));
        free(unused.element);
    }
    Services::Events::InsertArgument(stack, retval);
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
        ASSERT(pAbilities);
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
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT(pAbilities);

        // Need to count them manually, since some might be set to invalid
        retval = 0;
        for (int32_t i = 0; i < pAbilities->num; i++)
            retval += (pAbilities->element[i].m_nSpellId != ~0u);
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::AddSpecialAbility(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto level = Services::Events::ExtractArgument<int32_t>(args);
        const auto ready = Services::Events::ExtractArgument<int32_t>(args);
        const auto id    = Services::Events::ExtractArgument<int32_t>(args);

        ASSERT(level >= 0);
        ASSERT(id >= 0);

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT(pAbilities);

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
        ASSERT(pAbilities->array_size > pAbilities->num);
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
        ASSERT(pAbilities);
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
        const auto ready = Services::Events::ExtractArgument<int32_t>(args);
        const auto id    = Services::Events::ExtractArgument<int32_t>(args);

        ASSERT(level >= 0);
        ASSERT(id >= 0);

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        ASSERT(pAbilities);
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
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto level = Services::Events::ExtractArgument<int32_t>(args);  ASSERT(level <= 40);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT(pLevelStats);

            retval = pLevelStats->m_nClass;
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::SetBaseAC(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto ac = Services::Events::ExtractArgument<int32_t>(args); ASSERT(ac <= 255);

        pCreature->m_pStats->m_nACNaturalBase = static_cast<char>(ac);
    }
    return stack;
}

ArgumentStack Creature::GetBaseAC(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        retval = pCreature->m_pStats->m_nACNaturalBase;
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::SetRawAbilityScore(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto ability = Services::Events::ExtractArgument<int32_t>(args);
        const auto value   = Services::Events::ExtractArgument<int32_t>(args); ASSERT(value <= 255);

        switch (ability)
        {
            case Constants::ABILITY_STRENGTH:
                pCreature->m_pStats->SetSTRBase(static_cast<uint8_t>(value));
                break;
            case Constants::ABILITY_DEXTERITY:
                pCreature->m_pStats->SetDEXBase(static_cast<uint8_t>(value));
                break;
            case Constants::ABILITY_CONSTITUTION:
                pCreature->m_pStats->SetCONBase(static_cast<uint8_t>(value), 1/*bRecalculateHP*/);
                break;
            case Constants::ABILITY_INTELLIGENCE:
                pCreature->m_pStats->SetINTBase(static_cast<uint8_t>(value));
                break;
            case Constants::ABILITY_WISDOM:
                pCreature->m_pStats->SetWISBase(static_cast<uint8_t>(value));
                break;
            case Constants::ABILITY_CHARISMA:
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
    int32_t retval = -1;

    if (auto *pCreature = creature(args))
    {
        const auto ability = Services::Events::ExtractArgument<int32_t>(args);

        switch (ability)
        {
            case Constants::ABILITY_STRENGTH:
                retval = pCreature->m_pStats->m_nStrengthBase;
                break;
            case Constants::ABILITY_DEXTERITY:
                retval = pCreature->m_pStats->m_nDexterityBase;
                break;
            case Constants::ABILITY_CONSTITUTION:
                retval = pCreature->m_pStats->m_nConstitutionBase;
                break;
            case Constants::ABILITY_INTELLIGENCE:
                retval = pCreature->m_pStats->m_nIntelligenceBase;
                break;
            case Constants::ABILITY_WISDOM:
                retval = pCreature->m_pStats->m_nWisdomBase;
                break;
            case Constants::ABILITY_CHARISMA:
                retval = pCreature->m_pStats->m_nCharismaBase;
                break;
            default:
                LOG_NOTICE("Calling NWNX_Creature_GetRawAbilityScore with invalid ability ID:%d", ability);
                ASSERT_FAIL();
                break;
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::ModifyRawAbilityScore(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto ability = Services::Events::ExtractArgument<int32_t>(args);
        const auto offset  = Services::Events::ExtractArgument<int32_t>(args); ASSERT(offset <= 255);

        switch (ability)
        {
            case Constants::ABILITY_STRENGTH:
                pCreature->m_pStats->SetSTRBase(static_cast<uint8_t>(pCreature->m_pStats->m_nStrengthBase + offset));
                break;
            case Constants::ABILITY_DEXTERITY:
                pCreature->m_pStats->SetDEXBase(static_cast<uint8_t>(pCreature->m_pStats->m_nDexterityBase + offset));
                break;
            case Constants::ABILITY_CONSTITUTION:
                pCreature->m_pStats->SetCONBase(static_cast<uint8_t>(pCreature->m_pStats->m_nConstitutionBase + offset), 1/*bRecalculateHP*/);
                break;
            case Constants::ABILITY_INTELLIGENCE:
                pCreature->m_pStats->SetINTBase(static_cast<uint8_t>(pCreature->m_pStats->m_nIntelligenceBase + offset));
                break;
            case Constants::ABILITY_WISDOM:
                pCreature->m_pStats->SetWISBase(static_cast<uint8_t>(pCreature->m_pStats->m_nWisdomBase + offset));
                break;
            case Constants::ABILITY_CHARISMA:
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

ArgumentStack Creature::GetMemorisedSpell(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t id, ready, meta, domain;
    id = ready = meta = domain = -1;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); ASSERT(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); ASSERT(level < 10);
        const auto index   = Services::Events::ExtractArgument<int32_t>(args);

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
    int32_t retval = 0;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); ASSERT(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); ASSERT(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retval = classInfo.GetNumberMemorizedSpellSlots(static_cast<unsigned char>(level));
                break;
            }
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::SetMemorisedSpell(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); ASSERT(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); ASSERT(level < 10);
        const auto index   = Services::Events::ExtractArgument<int32_t>(args);

        const auto domain  = Services::Events::ExtractArgument<int32_t>(args);
        const auto meta    = Services::Events::ExtractArgument<int32_t>(args);
        const auto ready   = Services::Events::ExtractArgument<int32_t>(args);
        const auto id      = Services::Events::ExtractArgument<int32_t>(args);

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
    int32_t retval = 0;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); ASSERT(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); ASSERT(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retval = classInfo.GetSpellsPerDayLeft(static_cast<unsigned char>(level));
                break;
            }
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::SetRemainingSpellSlots(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); ASSERT(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); ASSERT(level < 10);
        const auto slots   = Services::Events::ExtractArgument<int32_t>(args); ASSERT(slots <= 255);

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
    int32_t retval = 0;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); ASSERT(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); ASSERT(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retval = classInfo.GetMaxSpellsPerDayLeft(static_cast<unsigned char>(level));
                break;
            }
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::GetKnownSpell(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); ASSERT(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); ASSERT(level < 10);
        const auto index   = Services::Events::ExtractArgument<int32_t>(args);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retval = static_cast<int32_t>(classInfo.GetKnownSpell(
                        static_cast<unsigned char>(level),
                        static_cast<unsigned char>(index)));
                break;
            }
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::GetKnownSpellCount(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); ASSERT(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); ASSERT(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retval = classInfo.GetNumberKnownSpells(static_cast<unsigned char>(level));
                break;
            }
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::RemoveKnownSpell(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); ASSERT(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); ASSERT(level < 10);
        const auto spellId = Services::Events::ExtractArgument<int32_t>(args);

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
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); ASSERT(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); ASSERT(level < 10);
        const auto spellId = Services::Events::ExtractArgument<int32_t>(args);

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

ArgumentStack Creature::GetMaxHitPointsByLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto level = Services::Events::ExtractArgument<int32_t>(args); ASSERT(level <= 40);
        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT(pLevelStats);

            retval = pLevelStats->m_nHitDie;
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::SetMaxHitPointsByLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto level = Services::Events::ExtractArgument<int32_t>(args); ASSERT(level <= 40);
        const auto value = Services::Events::ExtractArgument<int32_t>(args);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            ASSERT(pLevelStats);

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

ArgumentStack Creature::SetAlignmentGoodEvil(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto value = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT(value <= 32767);
        ASSERT(value >= -32768);
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
        ASSERT(value <= 32767);
        ASSERT(value >= -32768);
        pCreature->m_pStats->m_nAlignmentLawChaos = static_cast<int16_t>(value);
    }
    return stack;
}

ArgumentStack Creature::GetClericDomain(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT(index >= 1);
        ASSERT(index <= 2);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == Constants::CLASS_TYPE_CLERIC)
            {
                retval = classInfo.m_nDomain[index - 1];
                break;
            }
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::SetClericDomain(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT(index >= 1);
        ASSERT(index <= 2);
        const auto domain = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT(domain <= 255);
        ASSERT(domain >= 0);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == Constants::CLASS_TYPE_CLERIC)
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
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == Constants::CLASS_TYPE_WIZARD)
            {
                retval = classInfo.m_nSchool;
                break;
            }
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::SetWizardSpecialization(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto school = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT(school <= 255);
        ASSERT(school >= 0);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == Constants::CLASS_TYPE_WIZARD)
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
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        retval = pCreature->m_nSoundSet;
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::SetSoundset(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto soundset = Services::Events::ExtractArgument<int32_t>(args);
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
        ASSERT(skill >= 0);
        ASSERT(skill <= 255);
        ASSERT(rank >= -127);
        ASSERT(rank <= 128);

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
        ASSERT(position >= 0);
        ASSERT(position <= 2);
        ASSERT(classID >= 0);
        ASSERT(classID <= 255);

        pCreature->m_pStats->SetClass(static_cast<uint8_t>(position), static_cast<uint8_t>(classID));
    }
    return stack;
}

ArgumentStack Creature::SetBaseAttackBonus(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto bab = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT(bab >= 0);
        ASSERT(bab <= 254);

        pCreature->m_pStats->m_nBaseAttackBonus = static_cast<uint8_t>(bab);
    }
    return stack;
}

ArgumentStack Creature::GetAttacksPerRound(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        const auto bBaseAPR = Services::Events::ExtractArgument<int32_t>(args);

        if (bBaseAPR || pCreature->m_pStats->m_nOverrideBaseAttackBonus == 0)
            retval = pCreature->m_pStats->GetAttacksPerRound();
        else
            retval = pCreature->m_pStats->m_nOverrideBaseAttackBonus;
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::SetGender(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto gender = Services::Events::ExtractArgument<int32_t>(args);

        pCreature->m_pStats->m_nGender = gender;
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
    int32_t retval = -1;
    if (auto *pCreature = creature(args))
    {
        retval = pCreature->m_pStats->m_nSkillPointsRemaining;
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::SetSkillPointsRemaining(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto points = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT(points >= 0); ASSERT(points <= 65535);

        pCreature->m_pStats->m_nSkillPointsRemaining = static_cast<uint16_t>(points);
    }
    return stack;
}

ArgumentStack Creature::SetRacialType(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto race = Services::Events::ExtractArgument<int32_t>(args); ASSERT(race <= 65535);

        pCreature->m_pStats->m_nRace = static_cast<uint16_t>(race);
    }
    return stack;
}

ArgumentStack Creature::GetMovementType(ArgumentStack&& args)
{
    const int MOVEMENT_TYPE_STATIONARY      = 0;
    const int MOVEMENT_TYPE_WALK            = 1;
    const int MOVEMENT_TYPE_RUN             = 2;
    const int MOVEMENT_TYPE_SIDESTEP        = 3;
    const int MOVEMENT_TYPE_WALK_BACKWARDS  = 4;

    ArgumentStack stack;
    int retval = MOVEMENT_TYPE_STATIONARY;
    if (auto *pCreature = creature(args))
    {

        switch (pCreature->m_nAnimation)
        {
            case 2:  // walk
            case 84: // walk forward left
            case 85: // walk forward right
                retval = MOVEMENT_TYPE_WALK;
                break;
            case 3:  // walk backwards
                retval = MOVEMENT_TYPE_WALK_BACKWARDS;
                break;
            case 4:  // run
            case 86: // run forward left
            case 87: // run forward right
                retval = MOVEMENT_TYPE_RUN;
                break;
            case 78: // walk left
            case 79: // walk right
                retval = MOVEMENT_TYPE_SIDESTEP;
                break;
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Creature::SetWalkRateCap(ArgumentStack&& args)
{
    static NWNXLib::Hooking::FunctionHook* pGetWalkRate_hook;

    if (!pGetWalkRate_hook)
    {
        GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreature__GetWalkRate>(
            +[](CNWSCreature *pThis) -> float
            {
                float fWalkRate = pGetWalkRate_hook->CallOriginal<float>(pThis);

                auto cap = g_plugin->GetServices()->m_perObjectStorage->Get<float>(pThis, "WALK_RATE_CAP");
                return (cap && *cap < fWalkRate) ? *cap : fWalkRate;

            });
        pGetWalkRate_hook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreature__GetWalkRate);
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

}
