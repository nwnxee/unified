#include "Layonara.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWFeat.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSJournal.hpp"
#include "API/CExoArrayListTemplatedSJournalEntry.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

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
    REGISTER(ApplyRune)
    REGISTER(CombineRunes)
    REGISTER(GetRuneDescription)

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<API::Functions::CNWSInventory__GetItemInSlot>(&Layonara::GetItemInSlotHook);
    m_GetItemInSlotHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::CNWSInventory__GetItemInSlot);
    m_GemBonuses[Gems::GRE] = {SavingThrowType::Poison, SavingThrow::All, Skill::Listen, DamageType::Positive,
                               Ability::Strength, Ability::Charisma, -1, -1, -1, -1};
    m_GemBonuses[Gems::MAL] = {SavingThrowType::Disease, SavingThrow::All, Skill::Lore, DamageType::Divine,
                               Ability::Constitution, Ability::Wisdom, -1, -1, -1, -1};
    m_GemBonuses[Gems::FIA] = {SavingThrowType::Fire, SavingThrow::All, Skill::Spot, DamageType::Fire,
                               Ability::Constitution, Ability::Charisma, -1, -1, -1, -1};
    m_GemBonuses[Gems::AVE] = {SavingThrowType::Electricity, SavingThrow::All, Skill::Search, DamageType::Electrical,
                               Ability::Strength, Ability::Wisdom, -1, -1, -1, -1};
    m_GemBonuses[Gems::PHE] = {SavingThrowType::Cold, SavingThrow::All, Skill::Taunt, DamageType::Cold,
                               Ability::Dexterity, Ability::Wisdom, -1, -1, -1, -1};
    m_GemBonuses[Gems::AME] = {SavingThrowType::Acid, SavingThrow::All, Skill::Tumble, DamageType::Acid,
                               Ability::Strength, Ability::Constitution, -1, -1, -1, -1};
    m_GemBonuses[Gems::FEL] = {SavingThrowType::Death, SavingThrow::All, Skill::Parry, DamageType::Sonic,
                               Ability::Constitution, Ability::Intelligence, -1, -1, -1, -1};
    m_GemBonuses[Gems::GAR] = {SavingThrowType::MindSpells, SavingThrow::All, Skill::Persuade, DamageType::Negative,
                               Ability::Dexterity, Ability::Constitution, Ability::Wisdom, -1, -1, -1};
    m_GemBonuses[Gems::ALE] = {SavingThrowType::Fear, SavingThrow::All, Skill::Discipline, DamageType::Slashing,
                               Ability::Constitution, Ability::Wisdom, Ability::Charisma, -1, -1, -1};
    m_GemBonuses[Gems::TOP] = {SavingThrowType::Trap, SavingThrow::All, Skill::DisableTrap, DamageType::Piercing,
                               Ability::Strength, Ability::Constitution, Ability::Wisdom, -1, -1, -1};
    m_GemBonuses[Gems::SAP] = {SavingThrowType::Spell, SavingThrow::All, Skill::Spellcraft, DamageType::Magical,
                               Ability::Intelligence, Ability::Wisdom, Ability::Charisma, -1, -1, -1};
    m_GemBonuses[Gems::FIO] = {SavingThrowType::All, SavingThrow::Reflex, Skill::Perform, DamageType::Bludgeoning,
                               Ability::Dexterity, Ability::Constitution, Ability::Charisma, -1, -1, -1};
    m_GemBonuses[Gems::DIA] = {SavingThrowType::All, SavingThrow::Fortitude, Skill::Heal, DamageType::Elemental,
                               Ability::Dexterity, Ability::Constitution, Ability::Intelligence, -1, -1, 1};
    m_GemBonuses[Gems::RUB] = {SavingThrowType::All, SavingThrow::Will, Skill::Concentration, DamageType::Physical,
                               Ability::Strength, Ability::Dexterity, Ability::Constitution, -1, -1, -1};
    m_GemBonuses[Gems::EME] = {SavingThrowType::All, SavingThrow::All, Skill::AllSkills, DamageType::MAX,
                               Ability::Strength, Ability::Dexterity, Ability::Constitution,
                               Ability::Intelligence, Ability::Wisdom, Ability::Charisma};
    m_ElementalDamageTypes.push_back(DamageType::Acid);
    m_ElementalDamageTypes.push_back(DamageType::Cold);
    m_ElementalDamageTypes.push_back(DamageType::Electrical);
    m_ElementalDamageTypes.push_back(DamageType::Fire);
    m_ElementalDamageTypes.push_back(DamageType::Sonic);
    m_PhysicalDamageTypes.push_back(DamageType::Bludgeoning);
    m_PhysicalDamageTypes.push_back(DamageType::Piercing);
    m_PhysicalDamageTypes.push_back(DamageType::Slashing);
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

ArgumentStack Layonara::ApplyRune(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto itemId = Services::Events::ExtractArgument<Types::ObjectID>(args);

    auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);
    if (!pCreature)
    {
        LOG_NOTICE("NWNX_Layonara function called on non creature object");
        return stack;
    }

    auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(itemId);
    auto *pItem = Utils::AsNWSItem(pGameObject);
    if (!pItem)
    {
        LOG_NOTICE("NWNX_Layonara function called on non item object");
        return stack;
    }

    // Gets the item tag and parses it to determine rune, gem and power
    std::string itemTag = pItem->m_sTag.CStr();
    vector<uint8_t> parts;
    std::istringstream ss(itemTag);
    std::string token;

    while (std::getline(ss, token, '_'))
    {
        parts.push_back(std::strtol(token.c_str(), nullptr, 10));
    }

    auto rune = parts[1];
    auto gem = parts[2];
    auto power = parts[3];

    // Determines how many rune types are combined so we can calculate duration
    uint8_t runeCount = 0;
    while (rune)
    {
        runeCount += rune & 1;
        rune >>= 1;
    }
    rune = parts[1];

    float fDuration = (25 - (power * runeCount)) * 60.0f;

    // Remove any existing rune effects if they're applying before the other one has expired
    while (pCreature->HasSpellEffectApplied(489))
        pCreature->RemoveEffectBySpellId(489);

    std::list<CGameEffect *> effects;

    // Visual FX of Concentric Circles (1067 is the id in our 2da before the first rune vfx)
    auto *vfxEff = new API::CGameEffect(true);
    vfxEff->m_nType = EffectTrueType::VisualEffect;
    vfxEff->m_nParamInteger[0] = 1067 + rune;
    effects.push_back(vfxEff);

    // Shadow for Saves
    if ((rune & Runes::SHADOW) == Runes::SHADOW)
    {
        auto *eff = new API::CGameEffect(true);
        eff->m_nType = EffectTrueType::SavingThrowIncrease;
        eff->m_nParamInteger[0] = 2 * power;
        eff->m_nParamInteger[1] = m_GemBonuses[gem][1];
        eff->m_nParamInteger[2] = m_GemBonuses[gem][0];
        eff->m_nParamInteger[3] = RacialType::Invalid;
        effects.push_back(eff);
    }

    // Tidal for Skills
    if ((rune & Runes::TIDAL) == Runes::TIDAL)
    {
        auto *eff = new API::CGameEffect(true);
        eff->m_nType = EffectTrueType::SkillIncrease;
        eff->m_nParamInteger[0] = m_GemBonuses[gem][2];
        eff->m_nParamInteger[1] = 2 * power;
        eff->m_nParamInteger[2] = RacialType::Invalid;
        effects.push_back(eff);
    }

    // Forestal for Damage Immunities
    if ((rune & Runes::FORESTAL) == Runes::FORESTAL)
    {
        // Special Diamond/Ruby/Emerald Damage Immunity needs us to perform loops on the valid damage types and create
        // an effect for each damage type as it doesn't work with a mask
        if (m_GemBonuses[gem][3] == DamageType::MAX) // Emerald
        {
            for (int i = 0; i <= 11; i++)
            {
                auto *eff = new API::CGameEffect(true);
                eff->m_nType = EffectTrueType::DamageImmunityIncrease;
                eff->m_nParamInteger[0] = pow(2, i);
                eff->m_nParamInteger[1] = power * 5;
                effects.push_back(eff);
            }
        }
        else if (m_GemBonuses[gem][3] == DamageType::Elemental) // Diamond
        {
            for (auto &dmg : g_plugin->m_ElementalDamageTypes)
            {
                auto *eff = new API::CGameEffect(true);
                eff->m_nType = EffectTrueType::DamageImmunityIncrease;
                eff->m_nParamInteger[0] = dmg;
                eff->m_nParamInteger[1] = power * 5;
                effects.push_back(eff);
            }
        }
        else if (m_GemBonuses[gem][3] == DamageType::Physical) // Ruby
        {
            for (auto &dmg : g_plugin->m_PhysicalDamageTypes)
            {
                auto *eff = new API::CGameEffect(true);
                eff->m_nType = EffectTrueType::DamageImmunityIncrease;
                eff->m_nParamInteger[0] = dmg;
                eff->m_nParamInteger[1] = power * 5;
                effects.push_back(eff);
            }
        }
        else
        {
            auto *eff = new API::CGameEffect(true);
            eff->m_nType = EffectTrueType::DamageImmunityIncrease;
            eff->m_nParamInteger[0] = m_GemBonuses[gem][3];
            eff->m_nParamInteger[1] = power * 5;
            effects.push_back(eff);
        }
    }

    // Al'noth for Ability bonuses
    if ((rune & Runes::ALNOTH) == Runes::ALNOTH)
    {
        for (int i = 4; i <= 9; i++)
        {
            // Once we reach the first -1 then we have no more ability bonuses
            if (m_GemBonuses[gem][i] == -1)
                break;

            auto *eff = new API::CGameEffect(true);
            eff->m_nType = EffectTrueType::AbilityIncrease;
            eff->m_nParamInteger[0] = m_GemBonuses[gem][i];
            eff->m_nParamInteger[1] = power;
            effects.push_back(eff);
        }
    }

    // Now link them all
    bool first = true;
    CGameEffect *prevFx;
    for(auto iter = effects.begin(); iter != effects.end(); iter++)
    {
        auto &fx = *iter;
        if (first)
        {
            prevFx = fx;
            first = false;
            continue;
        }
        auto *link = new API::CGameEffect(true);
        link->m_oidCreator = pCreature->m_idSelf;
        link->m_nType = EffectTrueType::Link;
        link->m_nSubType = EffectSubType::Extraordinary | EffectDurationType::Temporary;
        link->m_fDuration = fDuration;
        link->m_sCustomTag = "NWNX_Layonara_Rune";
        link->m_nSpellId = 489;
        link->m_bShowIcon = 1;
        link->SetLinked(prevFx, fx);
        link->UpdateLinked();
        prevFx = link;
    }

    pCreature->ApplyEffect(prevFx, false, false);

    return stack;
}

ArgumentStack Layonara::CombineRunes(ArgumentStack&& args)
{
    ArgumentStack stack;
    std::string retVal;
    const auto targetRuneId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto runeId = Services::Events::ExtractArgument<Types::ObjectID>(args);

    auto *pTgtGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(targetRuneId);
    auto *pTgtItem = Utils::AsNWSItem(pTgtGameObject);
    if (!pTgtItem)
    {
        LOG_NOTICE("NWNX_Layonara function called on non item object");
        return stack;
    }

    auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(runeId);
    auto *pItem = Utils::AsNWSItem(pGameObject);
    if (!pItem)
    {
        LOG_NOTICE("NWNX_Layonara function called on non item object");
        return stack;
    }

    std::string itemTag = pItem->m_sTag.CStr();
    vector<uint8_t> parts;
    std::istringstream ss(itemTag);
    std::string token;

    while (std::getline(ss, token, '_'))
    {
        parts.push_back(std::strtol(token.c_str(), nullptr, 10));
    }

    auto rune = parts[1];
    auto gem = parts[2];
    auto power = parts[3];

    std::string tgtItemTag = pTgtItem->m_sTag.CStr();
    vector<uint8_t> tgtParts;
    std::istringstream tgtSs(tgtItemTag);
    std::string tgtToken;

    while (std::getline(tgtSs, tgtToken, '_'))
    {
        tgtParts.push_back(std::strtol(tgtToken.c_str(), nullptr, 10));
    }

    auto tgtRune = tgtParts[1];
    auto tgtGem = tgtParts[2];
    auto tgtPower = tgtParts[3];

    if (rune == tgtRune && gem == tgtGem && (power + tgtPower <= 3))
        retVal = "rune_" + std::to_string(rune) + "_" + std::to_string(gem) + "_" + std::to_string(power + tgtPower);
    else if ((rune & tgtRune) == 0 && power == tgtPower && gem == tgtGem)
        retVal = "rune_" + std::to_string(rune | tgtRune) + "_" + std::to_string(gem) + "_" + std::to_string(power);
    else
        retVal = "";

    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Layonara::GetRuneDescription(ArgumentStack&& args)
{
    ArgumentStack stack;
    std::string retVal;
    const auto runeId = Services::Events::ExtractArgument<Types::ObjectID>(args);

    auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(runeId);
    auto *pItem = Utils::AsNWSItem(pGameObject);
    if (!pItem)
    {
        LOG_NOTICE("NWNX_Layonara function called on non item object");
        return stack;
    }

    std::string itemTag = pItem->m_sTag.CStr();
    vector<uint8_t> parts;
    std::istringstream ss(itemTag);
    std::string token;

    while (std::getline(ss, token, '_'))
    {
        parts.push_back(std::strtol(token.c_str(), nullptr, 10));
    }

    auto rune = parts[1];
    auto gem = parts[2];
    auto power = parts[3];
    uint8_t runeCount = 0;
    while (rune)
    {
        runeCount += rune & 1;
        rune >>= 1;
    }
    rune = parts[1];

    int32_t fDuration = (25 - (power * runeCount)) * 60;

    retVal = "This rune gives the following bonuses:\n";

    // Shadow for Saves
    if ((rune & Runes::SHADOW) == Runes::SHADOW)
    {
        retVal = retVal + "+" + std::to_string(2 * power) + " to ";
        if (m_GemBonuses[gem][1] == SavingThrow::All)
            if (m_GemBonuses[gem][0] == SavingThrowType::All)
                retVal = retVal + "All";
            else
                retVal = retVal + SavingThrowType::ToString(m_GemBonuses[gem][0]);
        else
            retVal = retVal + SavingThrow::ToString(m_GemBonuses[gem][1]);
        retVal = retVal + " Saves\n";
    }

    // Tidal for Skills
    if ((rune & Runes::TIDAL) == Runes::TIDAL)
    {
        retVal = retVal + "+" + std::to_string(2 * power) + " to ";
        if (m_GemBonuses[gem][2] == Skill::AllSkills)
            retVal = retVal + "All Skills";
        else
            retVal = retVal + Skill::ToString(m_GemBonuses[gem][2]);
        retVal = retVal + "\n";
    }

    // Forestal for Damage Immunities
    if ((rune & Runes::FORESTAL) == Runes::FORESTAL)
    {
        // Special Diamond/Ruby/Emerald Damage Immunity needs us to perform loops on the valid damage types and create
        // an effect for each damage type as it doesn't work with a mask
        if (m_GemBonuses[gem][3] == DamageType::MAX) // Emerald
        {
            retVal = retVal + std::to_string(5 * power) + "% Immunity vs All Damage Types\n";
        }
        else if (m_GemBonuses[gem][3] == DamageType::Elemental) // Diamond
        {
            retVal = retVal + std::to_string(5 * power) + "% Immunity vs Elemental Damage Types\n";
        }
        else if (m_GemBonuses[gem][3] == DamageType::Physical) // Ruby
        {
            retVal = retVal + std::to_string(5 * power) + "% Immunity vs Physical Damage Types\n";
        }
        else
        {
            retVal = retVal + std::to_string(5 * power) + "% Immunity vs ";
            retVal = retVal + DamageType::ToString(m_GemBonuses[gem][3]);
            retVal = retVal + " Damage Types\n";
        }
    }

    if ((rune & Runes::ALNOTH) == Runes::ALNOTH)
    {
        for (int i = 4; i <= 9; i++)
        {
            // Once we reach the first -1 then we have no more ability bonuses
            if (m_GemBonuses[gem][i] == -1)
                break;

            retVal += "+" + std::to_string(power) + " to " + Constants::Ability::ToString(m_GemBonuses[gem][i]) + "\n";
        }
    }

    retVal = retVal + "\nThe rune's effects will last for " + std::to_string(fDuration/60) + " minutes.\n";

    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

}
