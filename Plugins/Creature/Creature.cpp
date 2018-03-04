
// Log currently generates warnings when no arguments are given to format string
// TODO: Should really clean up the log so it doesn't warn in these cases
#pragma GCC diagnostic ignored "-Wformat-security"

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
#include "Services/Events/Events.hpp"
#include "Services/Log/Log.hpp"
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
    REGISTER(SetAbilityScore);
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
    REGISTER(GetWizardSpecialization);
    REGISTER(SetWizardSpecialization);
    REGISTER(GetSoundset);
    REGISTER(SetSoundset);
    REGISTER(SetSkillRank);
    REGISTER(SetClassByPosition);

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
        GetServices()->m_log->Notice("NWNX_Creature function called on OBJECT_INVALID");
        return 0;
    }

    return Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);
}

ArgumentStack Creature::AddFeat(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);  assert(feat <= 65535);

        pCreature->m_pStats->AddFeat(static_cast<uint16_t>(feat));
    }

    return stack;
}

ArgumentStack Creature::AddFeatByLevel(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto feat  = Services::Events::ExtractArgument<int32_t>(args);  assert(feat <= 65535);
        const auto level = Services::Events::ExtractArgument<int32_t>(args);  assert(level <= 40);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            assert(pLevelStats);
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
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);  assert(feat <= 65535);

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
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);  assert(feat <= 65535);

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
        const auto level = Services::Events::ExtractArgument<int32_t>(args);  assert(level <= 40);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            assert(pLevelStats);
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
        const auto level = Services::Events::ExtractArgument<int32_t>(args);  assert(level <= 40);
        const auto index = Services::Events::ExtractArgument<int32_t>(args);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            assert(pLevelStats);

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
        const auto feat = Services::Events::ExtractArgument<int32_t>(args);  assert(feat <= 65535);
        // TODO: Need to clean up these templated arraylist APIs
        CExoArrayListTemplatedshortunsignedint unused = {0};

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
        assert(pAbilities);
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
        assert(pAbilities);

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

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        assert(pAbilities);

        // Check for an empty slot somewhere first
        for (int32_t i = 0; i < pAbilities->num; i++)
        {
            if (pAbilities->element[i].m_nSpellId == ~0u)
            {
                pAbilities->element[i].m_nSpellId     = id;
                pAbilities->element[i].m_bReadied     = ready;
                pAbilities->element[i].m_nCasterLevel = level;
                return stack;
            }
        }

        if (pAbilities->array_size == pAbilities->num)
        {
            pAbilities->Allocate(pAbilities->array_size + 1);
        }
        assert(pAbilities->array_size > pAbilities->num);
        pAbilities->element[pAbilities->num].m_nSpellId     = id;
        pAbilities->element[pAbilities->num].m_bReadied     = ready;
        pAbilities->element[pAbilities->num].m_nCasterLevel = level;
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
        assert(pAbilities);
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

        auto *pAbilities = pCreature->m_pStats->m_pSpellLikeAbilityList;
        assert(pAbilities);
        if (index < pAbilities->num)
        {
            pAbilities->element[index].m_nSpellId     = id;
            pAbilities->element[index].m_bReadied     = ready;
            pAbilities->element[index].m_nCasterLevel = level;
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
        const auto level = Services::Events::ExtractArgument<int32_t>(args);  assert(level <= 40);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            assert(pLevelStats);

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
        const auto ac = Services::Events::ExtractArgument<int32_t>(args); assert(ac <= 255);

        pCreature->m_pStats->m_nACNaturalBase = static_cast<uint8_t>(ac);
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

ArgumentStack Creature::SetAbilityScore(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto ability = Services::Events::ExtractArgument<int32_t>(args);
        const auto value   = Services::Events::ExtractArgument<int32_t>(args); assert(value <= 255);

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
                GetServices()->m_log->Notice("Calling NWNX_Creature_SetAbilityScore with invalid ability ID:%d", ability);
                assert(0);
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
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); assert(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); assert(level < 10);
        const auto index   = Services::Events::ExtractArgument<int32_t>(args);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                if (auto *pSpell = classInfo.GetMemorizedSpellInSlotDetails(level, index))
                {
                    id     = pSpell->m_nSpellId;
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
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); assert(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); assert(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retval = classInfo.GetNumberMemorizedSpellSlots(level);
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
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); assert(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); assert(level < 10);
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
                classInfo.SetMemorizedSpellSlot(level, index, id, domain, meta);
                classInfo.SetMemorizedSpellInSlotReady(level, index, ready);
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
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); assert(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); assert(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retval = classInfo.GetSpellsPerDayLeft(level);
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
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); assert(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); assert(level < 10);
        const auto slots   = Services::Events::ExtractArgument<int32_t>(args); assert(slots <= 255);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.SetSpellsPerDayLeft(level, slots);
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
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); assert(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); assert(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retval = classInfo.GetMaxSpellsPerDayLeft(level);
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
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); assert(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); assert(level < 10);
        const auto index   = Services::Events::ExtractArgument<int32_t>(args);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retval = classInfo.GetKnownSpell(level, index);
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
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); assert(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); assert(level < 10);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                retval = classInfo.GetNumberKnownSpells(level);
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
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); assert(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); assert(level < 10);
        const auto spellId = Services::Events::ExtractArgument<int32_t>(args);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.RemoveKnownSpell(level, spellId);
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
        const auto classId = Services::Events::ExtractArgument<int32_t>(args); assert(classId >= 0 && classId <= 255);
        const auto level   = Services::Events::ExtractArgument<int32_t>(args); assert(level < 10);
        const auto spellId = Services::Events::ExtractArgument<int32_t>(args);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == classId)
            {
                classInfo.AddKnownSpell(level, spellId);
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
        const auto level = Services::Events::ExtractArgument<int32_t>(args); assert(level <= 40);
        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            assert(pLevelStats);

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
        const auto level = Services::Events::ExtractArgument<int32_t>(args); assert(level <= 40);
        const auto value = Services::Events::ExtractArgument<int32_t>(args);

        if (level > 0 && level <= pCreature->m_pStats->m_lstLevelStats.num)
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[level-1];
            assert(pLevelStats);

            pLevelStats->m_nHitDie = value;
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
        assert(value <= 32767);
        assert(value >= -32768);
        pCreature->m_pStats->m_nAlignmentGoodEvil = value;
    }
    return stack;
}

ArgumentStack Creature::SetAlignmentLawChaos(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pCreature = creature(args))
    {
        const auto value = Services::Events::ExtractArgument<int32_t>(args);
        assert(value <= 32767);
        assert(value >= -32768);
        pCreature->m_pStats->m_nAlignmentLawChaos = value;
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
        assert(school <= 255);
        assert(school >= 0);

        for (int32_t i = 0; i < 3; i++)
        {
            auto& classInfo = pCreature->m_pStats->m_ClassInfo[i];
            if (classInfo.m_nClass == Constants::CLASS_TYPE_WIZARD)
            {
                classInfo.m_nSchool = school;
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
        pCreature->m_nSoundSet = soundset;
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
        assert(skill >= 0);
        assert(skill <= 255);
        assert(rank >= -127);
        assert(rank <= 128);

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
        assert(skill >= 0);
        assert(skill <= 2);
        assert(classID >= 0);
        assert(classID <= 255);

        pCreature->m_pStats->SetClass(static_cast<uint8_t>(position), static_cast<uint8_t>(classID));
    }
    return stack;
}
}
