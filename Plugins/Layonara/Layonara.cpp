#include "Layonara.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CScriptEvent.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CWorldTimer.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWFeat.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSTrigger.hpp"
#include "API/CNWSJournal.hpp"
#include "API/CExoArrayList.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include <cmath>

using namespace NWNXLib;
using namespace NWNXLib::Services;
using namespace NWNXLib::API;
using namespace Constants;

static Layonara::Layonara* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Layonara::Layonara(services);
    return g_plugin;
}


namespace Layonara {

Layonara::Layonara(Services::ProxyServiceList* services)
  : Plugin(services)
{
#define REGISTER(func)              \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })
    REGISTER(SetEquippableSlots);
    REGISTER(SetHostileFeat);
    REGISTER(SetDuelistCannyDefense);
    REGISTER(SetDuelistGrace);
    REGISTER(SetDuelistElaborateParry);
    REGISTER(SetSubraceDayEffects);
    REGISTER(ApplyRune);
    REGISTER(CombineRunes);
    REGISTER(GetRuneDescription);
    REGISTER(SetQuiver);
    REGISTER(SetQuiverArrows);
    REGISTER(CreateVFXAtTransitionCentroid);
    REGISTER(ClearSurfaceMaterial);

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<API::Functions::_ZN13CNWSInventory13GetItemInSlotEj>(
            &Layonara::GetItemInSlotHook);
    GetServices()->m_hooks->RequestSharedHook<API::Functions::_ZN10CNWSObject11SetPositionE6Vectori, void,
            CNWSObject*, Vector, int32_t>(&SetPositionHook);
    m_GetItemInSlotHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::_ZN13CNWSInventory13GetItemInSlotEj);
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

    m_SurfaceMaterialSpeeds[SurfaceMaterials::DIRT] = 33;
    m_SurfaceMaterialSpeeds[SurfaceMaterials::DIRTPATH] = 33;
    m_SurfaceMaterialSpeeds[SurfaceMaterials::STONEPATH] = 33;
    m_SurfaceMaterialSpeeds[SurfaceMaterials::WATER] = -25;
    m_SurfaceMaterialSpeeds[SurfaceMaterials::MUD] = -20;
    m_SurfaceMaterialSpeeds[SurfaceMaterials::SWAMP] = -20;
    m_SurfaceMaterialSpeeds[SurfaceMaterials::SNOW] = -5;
    m_SurfaceMaterialSpeeds[SurfaceMaterials::SAND] = -5;
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

void Layonara::RemoveEffectByTag(CNWSCreature *pCreature, std::string sCustomTag)
{
    std::vector<uint64_t> remove(128);
    for (int i = 0; i < pCreature->m_appliedEffects.num; i++)
    {
        auto eff = (CGameEffect*)pCreature->m_appliedEffects.element[i];
        if (eff->m_sCustomTag == sCustomTag)
        {
            remove.push_back(eff->m_nID);
        }
    }
    for (auto id: remove)
        pCreature->RemoveEffectById(id);
}

void Layonara::SetArrowsEffect(CNWSCreature *pCreature, bool bOff)
{
    RemoveEffectByTag(pCreature, "NWNX_Layonara_QuiverArrows");
    if (bOff)
        return;

    auto pItem = pCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::Arrows);

    if (!pItem || pItem->m_nBaseItem == Constants::BaseItem::Bolt)
        pItem = pCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::Bolts);

    if (!pItem)
        return;

    if (pItem->GetPropertyByTypeExists(Constants::ItemProperty::OnHitCastSpell, 124))
        return;

    uint8_t iPropOffset = 3;
    const uint16_t arrowFXStart = 1204;
    auto racialType = pCreature->m_pStats->m_nRace;
    auto raceOffset = racialType;
    if (racialType == 4 || racialType == 6)
        raceOffset = 5;
    else if (racialType == 5)
        raceOffset = 4;

    if (pItem->GetPropertyByTypeExists(Constants::ItemProperty::DamageBonus, 8))
        iPropOffset = 9;
    else if (pItem->GetPropertyByTypeExists(Constants::ItemProperty::DamageBonus, 10))
        iPropOffset = 7;
    else if (pItem->GetPropertyByTypeExists(Constants::ItemProperty::DamageBonus, 9))
        iPropOffset = 2;
    else if (pItem->GetPropertyByTypeExists(Constants::ItemProperty::DamageBonus, 7))
        iPropOffset = 8;
    else if (pItem->GetPropertyByTypeExists(Constants::ItemProperty::DamageBonus, 6))
        iPropOffset = 4;
    else if (pItem->GetPropertyByTypeExists(Constants::ItemProperty::DamageBonusVSRacialGroup, 24))
        iPropOffset = 1;
    else if (pItem->GetPropertyByTypeExists(Constants::ItemProperty::DamageBonusVSRacialGroup, 0))
        iPropOffset = 6;

    auto *eff = new CGameEffect(true);
    eff->m_oidCreator         = 0;
    eff->m_nType              = EffectTrueType::VisualEffect;
    eff->m_nSubType           = EffectSubType::Supernatural;
    eff->m_bShowIcon          = 0;
    eff->m_bExpose            = true;
    eff->m_nParamInteger[0]   = arrowFXStart + (iPropOffset * 12) + (raceOffset * 2) + pCreature->m_pStats->m_nGender;
    eff->m_nSubType |= EffectDurationType::Permanent;
    eff->m_sCustomTag = "NWNX_Layonara_QuiverArrows";
    eff->m_nSpellId = 1201;

    pCreature->ApplyEffect(eff, false, true);
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
    const auto creatureId = Services::Events::ExtractArgument<ObjectID>(args);
    const auto nBonus = Services::Events::ExtractArgument<int32_t>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Layonara function called on OBJECT_INVALID");
        return stack;
    }

    auto pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);

    RemoveEffectByTag(pCreature, "NWNX_Layonara_DuelistCannyDefense");

    if (nBonus > 0)
    {
        auto *eff = new CGameEffect(true);
        eff->m_oidCreator         = 0;
        eff->m_nType              = EffectTrueType::ACIncrease;
        eff->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
        eff->m_bShowIcon          = 0;
        eff->m_nParamInteger[0]   = ACBonus::Natural;
        eff->m_nParamInteger[1]   = nBonus;
        eff->m_nParamInteger[2]   = RacialType::Invalid;
        eff->m_nParamInteger[3]   = 0;
        eff->m_nParamInteger[4]   = 0;
        eff->m_nParamInteger[5]   = 4103;
        eff->m_sCustomTag         = "NWNX_Layonara_DuelistCannyDefense";
        pCreature->ApplyEffect(eff);
    }

    return stack;
}

ArgumentStack Layonara::SetDuelistGrace(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<ObjectID>(args);
    const auto nBonus = Services::Events::ExtractArgument<int32_t>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Layonara function called on OBJECT_INVALID");
        return stack;
    }

    auto pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);

    RemoveEffectByTag(pCreature, "NWNX_Layonara_DuelistGrace");

    if (nBonus > 0)
    {
        auto *eff = new CGameEffect(true);
        eff->m_oidCreator         = 0;
        eff->m_nType              = EffectTrueType::SavingThrowIncrease;
        eff->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
        eff->m_bShowIcon          = 0;
        eff->m_nParamInteger[0]   = nBonus;
        eff->m_nParamInteger[1]   = SavingThrow::Reflex;
        eff->m_nParamInteger[2]   = SavingThrowType::All;
        eff->m_nParamInteger[3]   = RacialType::Invalid;
        eff->m_sCustomTag         = "NWNX_Layonara_DuelistGrace";
        pCreature->ApplyEffect(eff);
    }

    return stack;
}

ArgumentStack Layonara::SetDuelistElaborateParry(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<ObjectID>(args);
    const auto nBonus = Services::Events::ExtractArgument<int32_t>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Layonara function called on OBJECT_INVALID");
        return stack;
    }

    auto pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);

    RemoveEffectByTag(pCreature, "NWNX_Layonara_DuelistElaborateParry");

    if (nBonus > 0)
    {
        auto *eff = new CGameEffect(true);
        eff->m_oidCreator         = 0;
        eff->m_nType              = EffectTrueType::SkillIncrease;
        eff->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
        eff->m_bShowIcon          = 0;
        eff->m_nParamInteger[0]   = Skill::Parry;
        eff->m_nParamInteger[1]   = nBonus;
        eff->m_nParamInteger[2]   = RacialType::Invalid;
        eff->m_sCustomTag         = "NWNX_Layonara_DuelistElaborateParry";
        pCreature->ApplyEffect(eff);
    }

    return stack;
}

ArgumentStack Layonara::SetSubraceDayEffects(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<ObjectID>(args);
    const auto nActive = Services::Events::ExtractArgument<int32_t>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Layonara function called on OBJECT_INVALID");
        return stack;
    }

    auto pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);

    RemoveEffectByTag(pCreature, "NWNX_Layonara_SubraceDayEffects");

    if (nActive)
    {
        auto *eff = new CGameEffect(true);
        eff->m_oidCreator         = 0;
        eff->m_nType              = EffectTrueType::AttackDecrease;
        eff->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
        eff->m_bShowIcon          = 1;
        eff->m_nParamInteger[0]   = 2;
        eff->m_nParamInteger[1]   = 0;
        eff->m_nParamInteger[2]   = RacialType::Invalid;
        eff->m_sCustomTag         = "NWNX_Layonara_SubraceDayEffects";
        pCreature->ApplyEffect(eff);

        auto *eff2 = new CGameEffect(true);
        eff2->m_oidCreator         = 0;
        eff2->m_nType              = EffectTrueType::SavingThrowDecrease;
        eff2->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
        eff2->m_bShowIcon          = 1;
        eff2->m_nParamInteger[0]   = 2;
        eff2->m_nParamInteger[1]   = SavingThrow::All;
        eff2->m_nParamInteger[2]   = SavingThrowType::All;
        eff2->m_nParamInteger[3]   = RacialType::Invalid;
        eff2->m_sCustomTag         = "NWNX_Layonara_SubraceDayEffects";
        pCreature->ApplyEffect(eff2, true, true);
    }

    return stack;
}

ArgumentStack Layonara::ApplyRune(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<ObjectID>(args);
    const auto itemId = Services::Events::ExtractArgument<ObjectID>(args);

    auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);
    if (!pCreature)
    {
        LOG_NOTICE("NWNX_Layonara function called on non creature object");
        return stack;
    }

    auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(itemId);
    auto *pItem = pGameObject->AsNWSItem();
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
    auto *vfxEff = new CGameEffect(true);
    vfxEff->m_nType = EffectTrueType::VisualEffect;
    vfxEff->m_nParamInteger[0] = 1067 + rune;
    effects.push_back(vfxEff);

    // Shadow for Saves
    if ((rune & Runes::SHADOW) == Runes::SHADOW)
    {
        auto *eff = new CGameEffect(true);
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
        auto *eff = new CGameEffect(true);
        eff->m_nType = EffectTrueType::SkillIncrease;
        eff->m_nParamInteger[0] = m_GemBonuses[gem][2];
        eff->m_nParamInteger[1] = 2 * power;
        eff->m_nParamInteger[2] = RacialType::Invalid;
        effects.push_back(eff);
        if (m_GemBonuses[gem][2] == Skill::DisableTrap)
        {
            auto *eff = new CGameEffect(true);
            eff->m_nType = EffectTrueType::SkillIncrease;
            eff->m_nParamInteger[0] = Skill::SetTrap;
            eff->m_nParamInteger[1] = 2 * power;
            eff->m_nParamInteger[2] = RacialType::Invalid;
            effects.push_back(eff);
        }
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
                auto *eff = new CGameEffect(true);
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
                auto *eff = new CGameEffect(true);
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
                auto *eff = new CGameEffect(true);
                eff->m_nType = EffectTrueType::DamageImmunityIncrease;
                eff->m_nParamInteger[0] = dmg;
                eff->m_nParamInteger[1] = power * 5;
                effects.push_back(eff);
            }
        }
        else
        {
            auto *eff = new CGameEffect(true);
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

            auto *eff = new CGameEffect(true);
            eff->m_nType = EffectTrueType::AbilityIncrease;
            eff->m_nParamInteger[0] = m_GemBonuses[gem][i];
            eff->m_nParamInteger[1] = power;
            effects.push_back(eff);
        }
    }
    if (!effects.empty())
    {
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
            auto *link = new CGameEffect(true);
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

    }

    return stack;
}

ArgumentStack Layonara::CombineRunes(ArgumentStack&& args)
{
    ArgumentStack stack;
    std::string retVal;
    const auto targetRuneId = Services::Events::ExtractArgument<ObjectID>(args);
    const auto runeId = Services::Events::ExtractArgument<ObjectID>(args);

    auto *pTgtGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(targetRuneId);
    auto *pTgtItem = pTgtGameObject->AsNWSItem();
    if (!pTgtItem)
    {
        LOG_NOTICE("NWNX_Layonara function called on non item object");
        return stack;
    }

    auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(runeId);
    auto *pItem = pGameObject->AsNWSItem();
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
    const auto runeId = Services::Events::ExtractArgument<ObjectID>(args);

    auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(runeId);
    auto *pItem = pGameObject->AsNWSItem();
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
        else if (m_GemBonuses[gem][2] == Skill::DisableTrap)
            retVal = retVal + "Disable/Set Trap";
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

ArgumentStack Layonara::SetQuiver(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<ObjectID>(args);
    const auto nColor = Services::Events::ExtractArgument<int32_t>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Layonara function called on OBJECT_INVALID");
        return stack;
    }

    auto pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);

    RemoveEffectByTag(pCreature, "NWNX_Layonara_Quiver");
    RemoveEffectByTag(pCreature, "NWNX_Layonara_QuiverArrows");

    if (nColor == -1)
    {
        SetArrowsEffect(pCreature, true);
        return stack;
    }

    const uint16_t quiverFXStart = 1084;
    auto racialType = pCreature->m_pStats->m_nRace;
    auto raceOffset = racialType;
    if (racialType == 4 || racialType == 6)
        raceOffset = 5;
    else if (racialType == 5)
        raceOffset = 4;

    auto *eff = new CGameEffect(true);
    eff->m_oidCreator         = 0;
    eff->m_nType              = EffectTrueType::VisualEffect;
    eff->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
    eff->m_bShowIcon          = 0;
    eff->m_nParamInteger[0]   = quiverFXStart + (nColor * 12) + (raceOffset * 2) + pCreature->m_pStats->m_nGender;
    eff->m_sCustomTag         = "NWNX_Layonara_Quiver";
    eff->m_bExpose            = true;
    pCreature->ApplyEffect(eff, true, true);

    SetArrowsEffect(pCreature);

    return stack;
}

ArgumentStack Layonara::SetQuiverArrows(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<ObjectID>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Layonara function called on OBJECT_INVALID");
        return stack;
    }

    auto pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(creatureId);
    SetArrowsEffect(pCreature);

    return stack;
}

Vector compute2DPolygonCentroid(const Vector* vertices, int vertexCount)
{
    Vector centroid = {0, 0, vertices[0].z};
    float signedArea = 0.0;
    float x0, y0, x1, y1, a;

    int i=0;
    for (i=0; i<vertexCount-1; ++i)
    {
        x0 = vertices[i].x;
        y0 = vertices[i].y;
        x1 = vertices[i+1].x;
        y1 = vertices[i+1].y;
        a = x0*y1 - x1*y0;
        signedArea += a;
        centroid.x += (x0 + x1)*a;
        centroid.y += (y0 + y1)*a;
    }

    x0 = vertices[i].x;
    y0 = vertices[i].y;
    x1 = vertices[0].x;
    y1 = vertices[0].y;
    a = x0*y1 - x1*y0;
    signedArea += a;
    centroid.x += (x0 + x1)*a;
    centroid.y += (y0 + y1)*a;

    signedArea *= 0.5;
    centroid.x /= 6.0 * signedArea;
    centroid.y /= 6.0 * signedArea;

    return centroid;
}

ArgumentStack Layonara::CreateVFXAtTransitionCentroid(ArgumentStack &&)
{
    ArgumentStack stack;

    auto pModule = Utils::GetModule();
    auto areaList = pModule->m_lstModuleAreaID;
    for (int i = 0; i < areaList.num; i++)
    {
        std::vector<std::pair<Vector, CExoString>> transitions;
        auto pArea = Utils::GetGameObject(areaList.element[i])->AsNWSArea();
        uint32_t oid;
        // Find all our transitions and build our pairs
        if (pArea->GetFirstObjectInArea(oid))
        {
            while (oid != Constants::OBJECT_INVALID)
            {
                auto pTrigger = Utils::GetGameObject(oid)->AsNWSTrigger();
                if (pTrigger != nullptr && pTrigger->m_pTransition.LookupTarget() != nullptr)
                {
                    Vector centroid = compute2DPolygonCentroid(pTrigger->m_pvVertices, pTrigger->m_nVertices);
                    transitions.emplace_back(centroid, CExoString("AT_") + pTrigger->m_pTransition.m_sTransitionTarget);
                }
                if (!pArea->GetNextObjectInArea(oid))
                    break;
            }
        }
        // Add the transitions after we loop through the objects
        for(auto const& AT: transitions)
        {
            auto vPos = AT.first;
            auto sTag = AT.second;
            auto *placeable = new CNWSPlaceable(API::Constants::OBJECT_INVALID);
            placeable->LoadFromTemplate(CResRef("at_vfx"), &sTag);
            placeable->SetPosition(vPos, 0);
            placeable->AddToArea(pArea, vPos.x, vPos.y, pArea->ComputeHeight(vPos), false);
            pArea->m_aGameObjects.Add(placeable->m_idSelf);
        }
    }
    return stack;
}

void Layonara::SetPositionHook(bool before, CNWSObject* thisPtr, Vector vPos, int32_t)
{
    if (!before)
        return;

    if (thisPtr->m_nObjectType == API::Constants::ObjectType::Creature)
    {
        auto pServer = Globals::AppManager()->m_pServerExoApp;
        auto pCreature = pServer->GetCreatureByGameObjectID(thisPtr->m_idSelf);
        auto pMaster = pServer->GetCreatureByGameObjectID(pCreature->m_oidMaster);
        if ((pMaster != nullptr && !pMaster->m_bPlayerCharacter) || pCreature->m_pStats->GetIsDM() || pCreature->m_nAssociateType == 7 || pCreature->m_nAssociateType == 8 ||
            !pCreature->m_bPlayerCharacter)
        {
            return;
        }
        auto pArea = pServer->GetAreaByGameObjectID(thisPtr->m_oidArea);
        if (pArea == nullptr || pArea->m_refTileSet == "ttu01")
            return;
        auto iMat = pArea->GetSurfaceMaterial(vPos);
        if (!g_plugin->m_objectCurrentMaterial.count(thisPtr->m_idSelf) ||
             g_plugin->m_objectCurrentMaterial[thisPtr->m_idSelf] != iMat)
        {
            auto *pAIMaster = pServer->GetServerAIMaster();
            auto nDelayDays = pServer->GetWorldTimer()->GetCalendarDayFromSeconds(0.0f);
            auto nDelayTime = pServer->GetWorldTimer()->GetTimeOfDayFromSeconds(0.0f);
            for (int i = 0; i < thisPtr->m_appliedEffects.num; i++)
            {
                auto eff = (CGameEffect*)thisPtr->m_appliedEffects.element[i];
                if (eff->m_sCustomTag == "NWNX_Layonara_SurfMatMovement")
                {
                    pAIMaster->AddEventDeltaTime(nDelayDays, nDelayTime, 0, pCreature->m_idSelf, Event::RemoveEffect, eff);
                }
            }

            auto nCurrentMovement = pCreature->GetMovementRateFactor();
            int32_t nSpeed = g_plugin->m_SurfaceMaterialSpeeds[iMat];
            int32_t effectChange = (2.0 - nCurrentMovement) * nSpeed;
            auto bHasStride = pCreature->m_pStats->HasFeat(Constants::Feat::WoodlandStride);
            auto bSlowImmune = pCreature->m_pStats->GetEffectImmunity(Constants::ImmunityType::Slow, nullptr, true);
            if (effectChange > 0 || (effectChange < 0 && !bHasStride && !bSlowImmune))
            {
                auto *eff = new CGameEffect(true);
                eff->m_oidCreator = 0;
                eff->m_nType = EffectTrueType::MovementSpeedIncrease;
                eff->m_nSubType = EffectSubType::Supernatural | EffectDurationType::Permanent;
                eff->m_nParamInteger[0] = effectChange;
                eff->m_bShowIcon = 0;
                eff->m_bExpose = true;

                auto *iconEff = new CGameEffect(true);
                iconEff->m_oidCreator = 0;
                iconEff->m_nType = EffectTrueType::Icon;
                iconEff->m_nSubType = EffectSubType::Supernatural | EffectDurationType::Permanent;
                iconEff->SetNumIntegers(1);
                iconEff->m_nParamInteger[0] = effectChange < 0 ? 38 : 37;
                iconEff->m_bExpose = true;

                auto *link = new CGameEffect(true);
                link->m_oidCreator = 0;
                link->m_nType = EffectTrueType::Link;
                link->m_nSubType = EffectSubType::Supernatural | EffectDurationType::Permanent;
                link->m_sCustomTag = "NWNX_Layonara_SurfMatMovement";
                link->SetLinked(eff, iconEff);
                link->UpdateLinked();
                pAIMaster->AddEventDeltaTime(nDelayDays, nDelayTime, 0, pCreature->m_idSelf, Event::ApplyEffect, link);
            }
            g_plugin->m_objectCurrentMaterial[thisPtr->m_idSelf] = iMat;
        }
    }
}

ArgumentStack Layonara::ClearSurfaceMaterial(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto creatureId = Services::Events::ExtractArgument<ObjectID>(args);

    if (creatureId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Layonara function called on OBJECT_INVALID");
        return stack;
    }

    g_plugin->m_objectCurrentMaterial.erase(creatureId);

    return stack;
}

void Layonara::SendMessageToCombatLog(CNWSCreature* target, const std::string& msg)
{
    if (!target->m_pStats->m_bIsPC)
        return;
    CNWCCMessageData* pMessageData = new CNWCCMessageData();
    CExoString message(msg);
    pMessageData->SetString(0, message);
    target->SendFeedbackMessage(0xCC, pMessageData, 0);
}

}
