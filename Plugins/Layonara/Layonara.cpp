#include "Layonara.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWFeat.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSJournal.hpp"
#include "API/CExoArrayListTemplatedSJournalEntry.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static ViewPtr<Layonara::Layonara> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
  return new Plugin::Info
  {
    "Layonara",
    "Functions specific to Layonara",
    "orth",
    "orth@layonara.com",
    1,
    true
  };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Layonara::Layonara(params);
    return g_plugin;
}


namespace Layonara {

Layonara::Layonara(const Plugin::CreateParams& params)
  : Plugin(params)
{
#define REGISTER(func)              \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Layonara::func, this, std::placeholders::_1));

    REGISTER(SetEquippableSlots)
    REGISTER(SetHostileFeat)
    REGISTER(SetDuelistCannyDefense)
    REGISTER(SetDuelistGrace)
    REGISTER(SetDuelistElaborateParry)
    REGISTER(SetSpellswordIgnoreSpellFailure)
    REGISTER(SetUndeadSlayerImmunity)
    REGISTER(SetSubraceDayEffects)
    REGISTER(GetQuestCompleted)

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<API::Functions::CNWSInventory__GetItemInSlot>(&Layonara::GetItemInSlotHook);
    m_GetItemInSlotHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::CNWSInventory__GetItemInSlot);

}

Layonara::~Layonara()
{
}

CNWSItem *Layonara::GetItemInSlotHook(CNWSInventory *pThis, uint32_t nSlot)
{
    // Arrow
    if (nSlot == 0x03800)
        nSlot = 0x00800;
    // Bolt
    else if (nSlot == 0x1f800)
        nSlot = 0x02000;
    // Bullet
    else if (nSlot == 0x23800)
        nSlot = 0x01000;
    return g_plugin->m_GetItemInSlotHook->CallOriginal<CNWSItem*>(pThis, nSlot);
}

ArgumentStack Layonara::SetEquippableSlots(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto baseItemId =  Services::Events::ExtractArgument<int32_t>(args);
    auto slots =  Services::Events::ExtractArgument<int32_t>(args);
    Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseItemId)->m_nEquipableSlots = slots;
    return stack;
}

ArgumentStack Layonara::SetHostileFeat(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto featId =  Services::Events::ExtractArgument<int32_t>(args);
    auto hostile =  Services::Events::ExtractArgument<int32_t>(args);
    auto feat = Globals::Rules()->GetFeat(featId);
    feat->m_bHostileFeat = hostile;
    return stack;
}

ArgumentStack Layonara::SetDuelistCannyDefense(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto nBonus = Services::Events::ExtractArgument<int32_t>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Layonara function called on OBJECT_INVALID");
        return stack;
    }

    auto pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);

    for (int i = 0; i < pCreature->m_appliedEffects.num; i++)
    {
        auto eff = (CGameEffect*)pCreature->m_appliedEffects.element[i];
        if (eff->m_sCustomTag == "DuelistCannyDefense")
        {
            pCreature->RemoveEffect(eff);
        }
    }

    if (nBonus != -1)
    {
        auto *eff = new API::CGameEffect(true);
        eff->m_oidCreator         = 0;
        eff->m_nType              = EffectTrueType::ACIncrease;
        eff->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
        eff->m_bShowIcon          = 0;
        eff->m_nParamInteger[0]   = ACBonus::Dodge;
        eff->m_nParamInteger[1]   = nBonus;
        eff->m_nParamInteger[2]   = RacialType::Invalid;
        eff->m_nParamInteger[3]   = 0;
        eff->m_nParamInteger[4]   = 0;
        eff->m_nParamInteger[5]   = 4103;
        eff->m_sCustomTag         = "DuelistCannyDefense";
        pCreature->ApplyEffect(eff, true, true);
    }

    return stack;
}

ArgumentStack Layonara::SetDuelistGrace(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto nBonus = Services::Events::ExtractArgument<int32_t>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Layonara function called on OBJECT_INVALID");
        return stack;
    }

    auto pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);

    for (int i = 0; i < pCreature->m_appliedEffects.num; i++)
    {
        auto eff = (CGameEffect*)pCreature->m_appliedEffects.element[i];
        if (eff->m_sCustomTag == "DuelistGrace")
        {
            pCreature->RemoveEffect(eff);
        }
    }

    if (nBonus != -1)
    {
        auto *eff = new API::CGameEffect(true);
        eff->m_oidCreator         = 0;
        eff->m_nType              = EffectTrueType::SavingThrowIncrease;
        eff->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
        eff->m_bShowIcon          = 0;
        eff->m_nParamInteger[0]   = nBonus;
        eff->m_nParamInteger[1]   = SavingThrow::Reflex;
        eff->m_nParamInteger[2]   = SavingThrowType::All;
        eff->m_nParamInteger[3]   = RacialType::Invalid;
        eff->m_sCustomTag         = "DuelistGrace";
        pCreature->ApplyEffect(eff, true, true);
    }

    return stack;
}

ArgumentStack Layonara::SetDuelistElaborateParry(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto nBonus = Services::Events::ExtractArgument<int32_t>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Layonara function called on OBJECT_INVALID");
        return stack;
    }

    auto pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);

    for (int i = 0; i < pCreature->m_appliedEffects.num; i++)
    {
        auto eff = (CGameEffect*)pCreature->m_appliedEffects.element[i];
        if (eff->m_sCustomTag == "DuelistElaborateParry")
        {
            pCreature->RemoveEffect(eff);
        }
    }

    if (nBonus != -1)
    {
        auto *eff = new API::CGameEffect(true);
        eff->m_oidCreator         = 0;
        eff->m_nType              = EffectTrueType::SkillIncrease;
        eff->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
        eff->m_bShowIcon          = 0;
        eff->m_nParamInteger[0]   = Skill::Parry;
        eff->m_nParamInteger[1]   = nBonus;
        eff->m_nParamInteger[2]   = RacialType::Invalid;
        eff->m_sCustomTag         = "DuelistElaborateParry";
        pCreature->ApplyEffect(eff, true, true);
    }

    return stack;
}

ArgumentStack Layonara::SetSpellswordIgnoreSpellFailure(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto nBonus = Services::Events::ExtractArgument<int32_t>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Layonara function called on OBJECT_INVALID");
        return stack;
    }

    auto pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);

    for (int i = 0; i < pCreature->m_appliedEffects.num; i++)
    {
        auto eff = (CGameEffect*)pCreature->m_appliedEffects.element[i];
        if (eff->m_sCustomTag == "SpellswordIgnoreSpellFailure")
        {
            pCreature->RemoveEffect(eff);
        }
    }

    if (nBonus != -1)
    {
        auto *eff = new API::CGameEffect(true);
        eff->m_oidCreator         = 0;
        eff->m_nType              = EffectTrueType::ArcaneSpellFailure;
        eff->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
        eff->m_bShowIcon          = 0;
        eff->m_nParamInteger[0]   = nBonus;
        eff->m_sCustomTag         = "SpellswordIgnoreSpellFailure";
        pCreature->ApplyEffect(eff, true, true);
    }

    return stack;
}

ArgumentStack Layonara::SetUndeadSlayerImmunity(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto nImmunity = Services::Events::ExtractArgument<int32_t>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Layonara function called on OBJECT_INVALID");
        return stack;
    }

    auto pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);

    auto *eff = new API::CGameEffect(true);
    eff->m_oidCreator         = 0;
    eff->m_nType              = EffectTrueType::Immunity;
    eff->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
    eff->m_bShowIcon          = 0;
    eff->m_nParamInteger[0]   = nImmunity;
    eff->m_nParamInteger[1]   = RacialType::Invalid;
    pCreature->ApplyEffect(eff, true, true);

    return stack;
}

ArgumentStack Layonara::SetSubraceDayEffects(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto nActive = Services::Events::ExtractArgument<int32_t>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Layonara function called on OBJECT_INVALID");
        return stack;
    }

    auto pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);

    for (int i = 0; i < pCreature->m_appliedEffects.num; i++)
    {
        auto eff = (CGameEffect*)pCreature->m_appliedEffects.element[i];
        if (eff->m_sCustomTag == "SubraceDayEffects")
        {
            pCreature->RemoveEffectById(eff->m_nID);
        }
    }

    if (nActive)
    {
        auto *eff = new API::CGameEffect(true);
        eff->m_oidCreator         = 0;
        eff->m_nType              = EffectTrueType::AttackDecrease;
        eff->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
        eff->m_bShowIcon          = 1;
        eff->m_nParamInteger[0]   = 2;
        eff->m_nParamInteger[1]   = 0;
        eff->m_nParamInteger[2]   = RacialType::Invalid;
        eff->m_sCustomTag         = "SubraceDayEffects";
        pCreature->ApplyEffect(eff, true, true);

        auto *eff2 = new API::CGameEffect(true);
        eff2->m_oidCreator         = 0;
        eff2->m_nType              = EffectTrueType::SavingThrowDecrease;
        eff2->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
        eff2->m_bShowIcon          = 1;
        eff2->m_nParamInteger[0]   = 2;
        eff2->m_nParamInteger[1]   = SavingThrow::All;
        eff2->m_nParamInteger[2]   = SavingThrowType::All;
        eff2->m_nParamInteger[3]   = RacialType::Invalid;
        eff2->m_sCustomTag         = "SubraceDayEffects";
        pCreature->ApplyEffect(eff2, true, true);
    }

    return stack;
}

ArgumentStack Layonara::GetQuestCompleted(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;

    const auto creatureId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto questTag = Services::Events::ExtractArgument<std::string>(args);

    auto pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);
    if (pCreature && pCreature->m_pJournal)
    {
        auto entries = pCreature->m_pJournal->m_lstEntries;
        if (entries.num > 0)
        {
            auto pEntry = entries.element;
            for (int i = 0; i < entries.num; i++, pEntry++)
            {
                if (pEntry->szPlot_Id.CStr() == questTag)
                {
                    retval = pEntry->bQuestCompleted;
                    break;
                }
            }
        }
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

}
