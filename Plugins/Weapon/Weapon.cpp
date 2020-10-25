#include "Weapon.hpp"
#include "API/Functions.hpp"
#include "API/CAppManager.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWFeat.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWRules.hpp"
#include "Utils.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static Weapon::Weapon* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
   g_plugin = new Weapon::Weapon(services);
   return g_plugin;
}

namespace Weapon {

Weapon::Weapon(Services::ProxyServiceList* services)
  : Plugin(services)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(SetWeaponFocusFeat);
    REGISTER(SetEpicWeaponFocusFeat);
    REGISTER(SetWeaponFinesseSize);
    REGISTER(GetWeaponFinesseSize);
    REGISTER(SetWeaponUnarmed);
    REGISTER(SetWeaponImprovedCriticalFeat);
    REGISTER(SetWeaponSpecializationFeat);
    REGISTER(SetEpicWeaponSpecializationFeat);
    REGISTER(SetEpicWeaponOverwhelmingCriticalFeat);
    REGISTER(SetEpicWeaponDevastatingCriticalFeat);
    REGISTER(SetWeaponOfChoiceFeat);
    REGISTER(SetGreaterWeaponSpecializationFeat);
    REGISTER(SetGreaterWeaponFocusFeat);
    REGISTER(SetWeaponIsMonkWeapon);
    REGISTER(SetOption);
    REGISTER(SetDevastatingCriticalEventScript);
    REGISTER(GetEventData);
    REGISTER(SetEventData);
    REGISTER(SetOneHalfStrength);
    REGISTER(GetOneHalfStrength);

#undef REGISTER

    m_GetWeaponFocusHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats14GetWeaponFocusEP8CNWSItem>(&Weapon::GetWeaponFocus);
    m_GetEpicWeaponFocusHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats18GetEpicWeaponFocusEP8CNWSItem>(&Weapon::GetEpicWeaponFocus);
    GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats16GetWeaponFinesseEP8CNWSItem>(&Weapon::GetWeaponFinesse);

    m_GetWeaponImprovedCriticalHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats25GetWeaponImprovedCriticalEP8CNWSItem>(&Weapon::GetWeaponImprovedCritical);
    m_GetWeaponSpecializationHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats23GetWeaponSpecializationEP8CNWSItem>(&Weapon::GetWeaponSpecialization);
    m_GetEpicWeaponSpecializationHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats27GetEpicWeaponSpecializationEP8CNWSItem>(&Weapon::GetEpicWeaponSpecialization);
    m_GetEpicWeaponOverwhelmingCriticalHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats33GetEpicWeaponOverwhelmingCriticalEP8CNWSItem>(&Weapon::GetEpicWeaponOverwhelmingCritical);
    m_GetEpicWeaponDevastatingCriticalHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats32GetEpicWeaponDevastatingCriticalEP8CNWSItem>(&Weapon::GetEpicWeaponDevastatingCritical);
    m_GetIsWeaponOfChoiceHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats19GetIsWeaponOfChoiceEj>(&Weapon::GetIsWeaponOfChoice);
    m_GetMeleeDamageBonusHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats19GetMeleeDamageBonusEih>(&Weapon::GetMeleeDamageBonus);
    m_GetDamageBonusHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats14GetDamageBonusEP12CNWSCreaturei>(&Weapon::GetDamageBonus);
    m_GetRangedDamageBonusHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats20GetRangedDamageBonusEv>(&Weapon::GetRangedDamageBonus);
    m_GetAttackModifierVersusHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats23GetAttackModifierVersusEP12CNWSCreature>(&Weapon::GetAttackModifierVersus);
    m_GetMeleeAttackBonusHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats19GetMeleeAttackBonusEiii>(&Weapon::GetMeleeAttackBonus);
    m_GetRangedAttackBonusHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats20GetRangedAttackBonusEii>(&Weapon::GetRangedAttackBonus);
    GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats22GetUseMonkAttackTablesEi>(&Weapon::GetUseMonkAttackTables);

    m_WeaponFinesseSizeMap.insert({Constants::BaseItem::Rapier, (uint8_t) Constants::CreatureSize::Medium});

    m_DCScript="";

    m_GASling=GetServices()->m_config->Get<bool>("GOOD_AIM_SLING", false);
}

Weapon::~Weapon()
{
}

ArgumentStack Weapon::SetWeaponFocusFeat(ArgumentStack&& args)
{
    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    CNWFeat *pFeat = Globals::Rules()->GetFeat(feat);
      ASSERT_OR_THROW(pFeat);
    CNWBaseItem *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem);
      ASSERT_OR_THROW(pBaseItem);

    auto w = m_WeaponFocusMap.find(w_bitem);
    if ( w != m_WeaponFocusMap.end())
    {
        w->second.emplace((uint32_t)feat);
    }
    else
    {
        m_WeaponFocusMap.insert({w_bitem, {(uint32_t)feat}});
    }
    auto featName = pFeat->GetNameText();
    auto baseItemName = pBaseItem->GetNameText();
    LOG_INFO("Weapon Focus Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetGreaterWeaponFocusFeat(ArgumentStack&& args)
{
    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    CNWFeat *pFeat = Globals::Rules()->GetFeat(feat);
      ASSERT_OR_THROW(pFeat);
    CNWBaseItem *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem);
      ASSERT_OR_THROW(pBaseItem);

    auto w = m_GreaterWeaponFocusMap.find(w_bitem);
    if ( w != m_GreaterWeaponFocusMap.end())
    {
        w->second.emplace((uint32_t)feat);
    }
    else
    {
        m_GreaterWeaponFocusMap.insert({w_bitem, {(uint32_t)feat}});
    }
    auto featName = pFeat->GetNameText();
    auto baseItemName = pBaseItem->GetNameText();
    LOG_INFO("Greater Weapon Focus Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetEpicWeaponFocusFeat(ArgumentStack&& args)
{
    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    CNWFeat *pFeat = Globals::Rules()->GetFeat(feat);
      ASSERT_OR_THROW(pFeat);
    CNWBaseItem *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem);
      ASSERT_OR_THROW(pBaseItem);

    auto w = m_EpicWeaponFocusMap.find(w_bitem);
    if ( w != m_EpicWeaponFocusMap.end())
    {
        w->second.emplace((uint32_t)feat);
    }
    else
    {
        m_EpicWeaponFocusMap.insert({w_bitem, {(uint32_t)feat}});
    }
    auto featName = pFeat->GetNameText();
    auto baseItemName = pBaseItem->GetNameText();
    LOG_INFO("Epic Weapon Focus Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetWeaponFinesseSize(ArgumentStack&& args)
{
    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto size     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(size > 0);
      ASSERT_OR_THROW(size <= 255);

    CNWBaseItem *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem);
      ASSERT_OR_THROW(pBaseItem);

    m_WeaponFinesseSizeMap.insert({w_bitem, size});
    auto baseItemName = pBaseItem->GetNameText();
    LOG_INFO("Weapon Finesse Size %d added for Base Item Type %d [%s]", size, w_bitem, baseItemName);

    return Services::Events::Arguments();
}

ArgumentStack Weapon::GetWeaponFinesseSize(ArgumentStack&& args)
{
    int32_t retVal = -1;

    const auto baseItem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(baseItem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(baseItem <= Constants::BaseItem::MAX);

    auto search = m_WeaponFinesseSizeMap.find(baseItem);
    if (search != m_WeaponFinesseSizeMap.end())
        retVal = search->second;

    return Services::Events::Arguments(retVal);
}

ArgumentStack Weapon::SetWeaponUnarmed(ArgumentStack&& args)
{
    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);

    CNWBaseItem *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem);
      ASSERT_OR_THROW(pBaseItem);

    m_WeaponUnarmedSet.insert(w_bitem);
    auto baseItemName = pBaseItem->GetNameText();
    LOG_INFO("Base Item Type %d [%s] set as unarmed weapon", w_bitem, baseItemName);

    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetWeaponIsMonkWeapon(ArgumentStack&& args)
{
    static bool bFirstTime = true;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);

    CNWBaseItem *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem);
      ASSERT_OR_THROW(pBaseItem);

    m_MonkWeaponSet.insert(w_bitem);
    auto baseItemName = pBaseItem->GetNameText();
    LOG_INFO("Base Item Type %d [%s] set as monk weapon", w_bitem, baseItemName);

    if (bFirstTime)
    {
        bFirstTime = false;
        // Hooks for flurry of blows
        m_ToggleModeHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN12CNWSCreature10ToggleModeEh>(&ToggleMode);
        g_plugin->GetServices()->m_messaging->BroadcastMessage("NWNX_WEAPON_SIGNAL", {"FLURRY_OF_BLOWS_REQUIRED"});
        LOG_NOTICE("Flurry of blows requires activation of CombatModes plugin");
    }

    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetWeaponImprovedCriticalFeat(ArgumentStack&& args)
{
    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    CNWFeat *pFeat = Globals::Rules()->GetFeat(feat);
      ASSERT_OR_THROW(pFeat);
    CNWBaseItem *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem);
      ASSERT_OR_THROW(pBaseItem);

    auto w = m_WeaponImprovedCriticalMap.find(w_bitem);
    if ( w != m_WeaponImprovedCriticalMap.end())
    {
        w->second.emplace((uint32_t)feat);
    }
    else
    {
        m_WeaponImprovedCriticalMap.insert({w_bitem, {(uint32_t)feat}});
    }
    auto featName = pFeat->GetNameText();
    auto baseItemName = pBaseItem->GetNameText();
    LOG_INFO("Improved Critical Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetWeaponSpecializationFeat(ArgumentStack&& args)
{
    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    CNWFeat *pFeat = Globals::Rules()->GetFeat(feat);
      ASSERT_OR_THROW(pFeat);
    CNWBaseItem *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem);
      ASSERT_OR_THROW(pBaseItem);

    auto w = m_WeaponSpecializationMap.find(w_bitem);
    if ( w != m_WeaponSpecializationMap.end())
    {
        w->second.emplace((uint32_t)feat);
    }
    else
    {
        m_WeaponSpecializationMap.insert({w_bitem, {(uint32_t)feat}});
    }
    auto featName = pFeat->GetNameText();
    auto baseItemName = pBaseItem->GetNameText();
    LOG_INFO("Weapon Specialization Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetGreaterWeaponSpecializationFeat(ArgumentStack&& args)
{
    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    CNWFeat *pFeat = Globals::Rules()->GetFeat(feat);
      ASSERT_OR_THROW(pFeat);
    CNWBaseItem *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem);
      ASSERT_OR_THROW(pBaseItem);

    auto w = m_GreaterWeaponSpecializationMap.find(w_bitem);
    if ( w != m_GreaterWeaponSpecializationMap.end())
    {
        w->second.emplace((uint32_t)feat);
    }
    else
    {
        m_GreaterWeaponSpecializationMap.insert({w_bitem, {(uint32_t)feat}});
    }
    auto featName = pFeat->GetNameText();
    auto baseItemName = pBaseItem->GetNameText();
    LOG_INFO("Greater Weapon Specialization Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetEpicWeaponSpecializationFeat(ArgumentStack&& args)
{
    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    CNWFeat *pFeat = Globals::Rules()->GetFeat(feat);
      ASSERT_OR_THROW(pFeat);
    CNWBaseItem *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem);
      ASSERT_OR_THROW(pBaseItem);

    auto w = m_EpicWeaponSpecializationMap.find(w_bitem);
    if ( w != m_EpicWeaponSpecializationMap.end())
    {
        w->second.emplace((uint32_t)feat);
    }
    else
    {
        m_EpicWeaponSpecializationMap.insert({w_bitem, {(uint32_t)feat}});
    }
    auto featName = pFeat->GetNameText();
    auto baseItemName = pBaseItem->GetNameText();
    LOG_INFO("Epic Weapon Specialization Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetEpicWeaponOverwhelmingCriticalFeat(ArgumentStack&& args)
{
    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    CNWFeat *pFeat = Globals::Rules()->GetFeat(feat);
      ASSERT_OR_THROW(pFeat);
    CNWBaseItem *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem);
      ASSERT_OR_THROW(pBaseItem);

    auto w = m_EpicWeaponOverwhelmingCriticalMap.find(w_bitem);
    if ( w != m_EpicWeaponOverwhelmingCriticalMap.end())
    {
        w->second.emplace((uint32_t)feat);
    }
    else
    {
        m_EpicWeaponOverwhelmingCriticalMap.insert({w_bitem, {(uint32_t)feat}});
    }
    auto featName = pFeat->GetNameText();
    auto baseItemName = pBaseItem->GetNameText();
    LOG_INFO("Overwhelming Critical Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetEpicWeaponDevastatingCriticalFeat(ArgumentStack&& args)
{
    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    CNWFeat *pFeat = Globals::Rules()->GetFeat(feat);
      ASSERT_OR_THROW(pFeat);
    CNWBaseItem *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem);
      ASSERT_OR_THROW(pBaseItem);

    auto w = m_EpicWeaponDevastatingCriticalMap.find(w_bitem);
    if ( w != m_EpicWeaponDevastatingCriticalMap.end())
    {
        w->second.emplace((uint32_t)feat);
    }
    else
    {
        m_EpicWeaponDevastatingCriticalMap.insert({w_bitem, {(uint32_t)feat}});
    }
    auto featName = pFeat->GetNameText();
    auto baseItemName = pBaseItem->GetNameText();
    LOG_INFO("Devastating Critical Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetWeaponOfChoiceFeat(ArgumentStack&& args)
{
    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    CNWFeat *pFeat = Globals::Rules()->GetFeat(feat);
      ASSERT_OR_THROW(pFeat);
    CNWBaseItem *pBaseItem = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem);
      ASSERT_OR_THROW(pBaseItem);

    auto w = m_WeaponOfChoiceMap.find(w_bitem);
    if ( w != m_WeaponOfChoiceMap.end())
    {
        w->second.emplace((uint32_t)feat);
    }
    else
    {
        m_WeaponOfChoiceMap.insert({w_bitem, {(uint32_t)feat}});
    }
    auto featName = pFeat->GetNameText();
    auto baseItemName = pBaseItem->GetNameText();
    LOG_INFO("Weapon of Choice Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetOption(ArgumentStack&& args)
{
    const auto nOption  = Services::Events::ExtractArgument<int32_t>(args);
    const auto nVal     = Services::Events::ExtractArgument<int32_t>(args);

    switch(nOption)
    {
        case NWNX_WEAPON_OPT_GRTFOCUS_AB_BONUS:
            m_GreaterFocusAttackBonus = nVal;
            LOG_INFO("Set NWNX_WEAPON_OPT_GRTFOCUS_AB_BONUS to %d", nVal);
            break;
        case NWNX_WEAPON_OPT_GRTSPEC_DAM_BONUS:
            m_GreaterWeaponSpecializationDamageBonus = nVal;
            LOG_INFO("Set NWNX_WEAPON_OPT_GRTSPEC_DAM_BONUS to %d", nVal);
            break;
    }
    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetDevastatingCriticalEventScript(ArgumentStack&& args)
{
    m_DCScript = Services::Events::ExtractArgument<std::string>(args);
    LOG_INFO("Set Devastating Critical Event Script to %s", m_DCScript);

    return Services::Events::Arguments();
}

ArgumentStack Weapon::GetEventData(ArgumentStack&& args)
{
    const auto nOption  = Services::Events::ExtractArgument<int32_t>(args);

    switch(nOption)
    {
        case NWNX_WEAPON_GETDATA_DC:
            return Services::Events::Arguments(m_DCData.nDamage, m_DCData.oidTarget, m_DCData.oidWeapon);
    }

    return Services::Events::Arguments();
}

ArgumentStack Weapon::SetEventData(ArgumentStack&& args)
{
    const auto nOption  = Services::Events::ExtractArgument<int32_t>(args);
    const auto nVal     = Services::Events::ExtractArgument<int32_t>(args);

    switch(nOption)
    {
        case NWNX_WEAPON_SETDATA_DC_BYPASS:
            LOG_INFO("Set NWNX_WEAPON_SETDATA_DC_BYPASS to %d", nVal);
            m_DCData.bBypass = nVal;
            break;
    }

    return Services::Events::Arguments();
}

int32_t Weapon::GetWeaponFocus(CNWSCreatureStats* pStats, CNWSItem* pWeapon)
{
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;
    Weapon& plugin = *g_plugin;


    auto w = plugin.m_WeaponFocusMap.find(pWeapon == nullptr ? (uint32_t)Constants::BaseItem::Gloves : pWeapon->m_nBaseItem);

    bApplicableFeatExists = w != plugin.m_WeaponFocusMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat) || (feat == Constants::Feat::WeaponFocus_Creature &&
            pStats->HasFeat(Constants::Feat::WeaponFocus_UnarmedStrike)));

            if (bHasApplicableFeat) break;
        }
    }

    return (bApplicableFeatExists && bHasApplicableFeat ? 1 : plugin.m_GetWeaponFocusHook->CallOriginal<int32_t>(pStats, pWeapon));
}

int32_t Weapon::GetEpicWeaponFocus(CNWSCreatureStats* pStats, CNWSItem* pWeapon)
{
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;
    Weapon& plugin = *g_plugin;

    auto w = plugin.m_EpicWeaponFocusMap.find(pWeapon == nullptr ? (uint32_t)Constants::BaseItem::Gloves : pWeapon->m_nBaseItem);

    bApplicableFeatExists = w != plugin.m_EpicWeaponFocusMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat) || (feat == Constants::Feat::EpicWeaponFocus_Creature &&
            pStats->HasFeat(Constants::Feat::EpicWeaponFocus_Unarmed)));

            if (bHasApplicableFeat) break;
        }
    }
    return (bApplicableFeatExists && bHasApplicableFeat ? 1 : plugin.m_GetEpicWeaponFocusHook->CallOriginal<int32_t>(pStats, pWeapon));
}

int32_t Weapon::GetWeaponFinesse(CNWSCreatureStats* pStats, CNWSItem* pWeapon)
{
    Weapon& plugin = *g_plugin;

    if (!pStats->HasFeat(Constants::Feat::WeaponFinesse))
        return 0;

    return plugin.GetIsWeaponLight(pStats, pWeapon, true) ? 1 : 0;
}

int32_t Weapon::GetWeaponImprovedCritical(CNWSCreatureStats* pStats, CNWSItem* pWeapon)
{
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;
    Weapon& plugin = *g_plugin;


    auto w = plugin.m_WeaponImprovedCriticalMap.find(pWeapon == nullptr ? (uint32_t)Constants::BaseItem::Gloves : pWeapon->m_nBaseItem);

    bApplicableFeatExists = w != plugin.m_WeaponImprovedCriticalMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat));

            if (bHasApplicableFeat) break;
        }
    }

    return (bApplicableFeatExists && bHasApplicableFeat ? 1 : plugin.m_GetWeaponImprovedCriticalHook->CallOriginal<int32_t>(pStats, pWeapon));
}

int32_t Weapon::GetWeaponSpecialization(CNWSCreatureStats* pStats, CNWSItem* pWeapon)
{
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;
    Weapon& plugin = *g_plugin;


    auto w = plugin.m_WeaponSpecializationMap.find(pWeapon == nullptr ? (uint32_t)Constants::BaseItem::Gloves : pWeapon->m_nBaseItem);

    bApplicableFeatExists = w != plugin.m_WeaponSpecializationMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat));

            if (bHasApplicableFeat) break;
        }
    }

    return (bApplicableFeatExists && bHasApplicableFeat ? 1 : plugin.m_GetWeaponSpecializationHook->CallOriginal<int32_t>(pStats, pWeapon));
}

int32_t Weapon::GetEpicWeaponSpecialization(CNWSCreatureStats* pStats, CNWSItem* pWeapon)
{
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;
    Weapon& plugin = *g_plugin;


    auto w = plugin.m_EpicWeaponSpecializationMap.find(pWeapon == nullptr ? (uint32_t)Constants::BaseItem::Gloves : pWeapon->m_nBaseItem);

    bApplicableFeatExists = w != plugin.m_EpicWeaponSpecializationMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat));

            if (bHasApplicableFeat) break;
        }
    }

    return (bApplicableFeatExists && bHasApplicableFeat ? 1 : plugin.m_GetEpicWeaponSpecializationHook->CallOriginal<int32_t>(pStats, pWeapon));
}

int32_t Weapon::GetEpicWeaponOverwhelmingCritical(CNWSCreatureStats* pStats, CNWSItem* pWeapon)
{
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;
    Weapon& plugin = *g_plugin;


    auto w = plugin.m_EpicWeaponOverwhelmingCriticalMap.find(pWeapon == nullptr ? (uint32_t)Constants::BaseItem::Gloves : pWeapon->m_nBaseItem);

    bApplicableFeatExists = w != plugin.m_EpicWeaponOverwhelmingCriticalMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat));

            if (bHasApplicableFeat) break;
        }
    }

    return (bApplicableFeatExists && bHasApplicableFeat ? 1 : plugin.m_GetEpicWeaponOverwhelmingCriticalHook->CallOriginal<int32_t>(pStats, pWeapon));
}

int32_t Weapon::GetEpicWeaponDevastatingCritical(CNWSCreatureStats* pStats, CNWSItem* pWeapon)
{
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;
    Weapon& plugin = *g_plugin;


    auto w = plugin.m_EpicWeaponDevastatingCriticalMap.find(pWeapon == nullptr ? (uint32_t)Constants::BaseItem::Gloves : pWeapon->m_nBaseItem);

    bApplicableFeatExists = w != plugin.m_EpicWeaponDevastatingCriticalMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat));

            if (bHasApplicableFeat) break;
        }
    }

    bool bFlag = bApplicableFeatExists && bHasApplicableFeat ? 1 : plugin.m_GetEpicWeaponDevastatingCriticalHook->CallOriginal<int32_t>(pStats, pWeapon);

    if (bFlag && !plugin.m_DCScript.empty())
    {
        CNWSCreature         *pCreature    = pStats->m_pBaseCreature;
        CNWSCombatRound      *pCombatRound = pCreature->m_pcCombatRound;
        CNWSCombatAttackData *pAttackData  = pCombatRound->GetAttack(pCombatRound->m_nCurrentAttack);

        plugin.m_DCData.oidWeapon = pWeapon ? pWeapon->m_idSelf : Constants::OBJECT_INVALID;
        plugin.m_DCData.oidTarget = pCreature->m_oidAttackTarget;
        plugin.m_DCData.nDamage   = pAttackData->GetTotalDamage(1);
        plugin.m_DCData.bBypass   = false;

        Utils::ExecuteScript(plugin.m_DCScript, pCreature->m_idSelf);

        if (plugin.m_DCData.bBypass)
        {
            pAttackData->m_bKillingBlow=0;
            return 0;
        }

    }
    return bFlag;
}

int32_t Weapon::GetIsWeaponOfChoice(CNWSCreatureStats* pStats, uint32_t nBaseItem)
{
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;
    Weapon& plugin = *g_plugin;


    auto w = plugin.m_WeaponOfChoiceMap.find(nBaseItem);

    bApplicableFeatExists = w != plugin.m_WeaponOfChoiceMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat));

            if (bHasApplicableFeat) break;
        }
    }

    return bApplicableFeatExists && bHasApplicableFeat ? 1 : plugin.m_GetIsWeaponOfChoiceHook->CallOriginal<int32_t>(pStats, nBaseItem);
}

//This one is required for correctly update PC sheet
int32_t Weapon::GetMeleeDamageBonus(CNWSCreatureStats* pStats, int32_t bOffHand, uint8_t nCreatureWeaponIndex)
{
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;
    Weapon& plugin = *g_plugin;
    CNWSItem* pWeapon = nullptr;
    uint32_t nBaseItem;

    int nBonus = plugin.m_GetMeleeDamageBonusHook->CallOriginal<int32_t>(pStats, bOffHand, nCreatureWeaponIndex);

    if (nCreatureWeaponIndex==255)
    {
        if (bOffHand)
        {
            pWeapon=pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::LeftHand);

            // Check for two handed
            if (pWeapon == nullptr)
            {
                auto *pMain = pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);
                if (pMain)
                {
                    auto *pBase = Globals::Rules()->m_pBaseItemArray->GetBaseItem(pMain->m_nBaseItem);
                    if (pBase && pBase->m_nWeaponWield == 8)
                    {
                        pWeapon = pMain;
                    }
                }
            }
        }
        else
        {
            pWeapon=pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);
        }
    }

    if (pWeapon == nullptr)
    {
        nBaseItem = Constants::BaseItem::Gloves;
    }
    else
    {
        nBaseItem = pWeapon->m_nBaseItem;
        auto bStr = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pWeapon, "ONE_HALF_STRENGTH");
        if(bStr && bStr.value())
            nBonus += pStats->m_nStrengthModifier/2;
    }


    auto w = plugin.m_GreaterWeaponSpecializationMap.find(nBaseItem);

    bApplicableFeatExists = w != plugin.m_GreaterWeaponSpecializationMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat));

            if (bHasApplicableFeat) break;
        }
    }


    if (bApplicableFeatExists && bHasApplicableFeat)
    {
        return nBonus + plugin.m_GreaterWeaponSpecializationDamageBonus;
    }

    return nBonus;
}

int32_t Weapon::GetDamageBonus(CNWSCreatureStats* pStats, CNWSCreature *pCreature, int32_t bOffHand)
{
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;
    Weapon& plugin = *g_plugin;
    CNWSItem* pWeapon = nullptr;
    uint32_t nBaseItem;

    int nBonus = plugin.m_GetDamageBonusHook->CallOriginal<int32_t>(pStats, pCreature, bOffHand);

    if (bOffHand)
    {
        pWeapon=pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::LeftHand);

        // Check for two handed
        if (pWeapon == nullptr)
        {
            auto *pMain = pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);
            if (pMain)
            {
                auto *pBase = Globals::Rules()->m_pBaseItemArray->GetBaseItem(pMain->m_nBaseItem);
                if (pBase && pBase->m_nWeaponWield == 8)
                {
                    pWeapon = pMain;
                }
            }
        }
    }
    else
    {
        pWeapon=pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);
    }

    if (pWeapon == nullptr)
    {
        nBaseItem = Constants::BaseItem::Gloves;
    }
    else
    {
        nBaseItem = pWeapon->m_nBaseItem;
        auto bStr = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(pWeapon, "ONE_HALF_STRENGTH");
        if(bStr && bStr.value())
            nBonus += pStats->m_nStrengthModifier/2;
    }


    auto w = plugin.m_GreaterWeaponSpecializationMap.find(nBaseItem);

    bApplicableFeatExists = w != plugin.m_GreaterWeaponSpecializationMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat));

            if (bHasApplicableFeat) break;
        }

    }

    if (bApplicableFeatExists && bHasApplicableFeat)
    {
        nBonus += plugin.m_GreaterWeaponSpecializationDamageBonus;

        if (*Globals::EnableCombatDebugging() && pStats->m_bIsPC)
        {
            auto sDebugMsg = CExoString(" + ");
            auto *pCurrentAttack = pStats->m_pBaseCreature->m_pcCombatRound->GetAttack(pStats->m_pBaseCreature->m_pcCombatRound->m_nCurrentAttack);
            if (pCurrentAttack->m_nAttackResult == 3)
            {
                auto nCriticalThreat = pStats->GetCriticalHitMultiplier(bOffHand);
                sDebugMsg = sDebugMsg + CExoString(std::to_string(plugin.m_GreaterWeaponSpecializationDamageBonus * nCriticalThreat)) +
                                        CExoString(" (Greater Weapon Specialization Feat) (Critical x") +
                                        CExoString(std::to_string(nCriticalThreat)) + CExoString(")");
            }
            else
            {
                sDebugMsg = sDebugMsg + CExoString(std::to_string(plugin.m_GreaterWeaponSpecializationDamageBonus)) +
                                        CExoString(" (Greater Weapon Specialization Feat) ");
            }
            auto sDamageDebugText = pCurrentAttack->m_sDamageDebugText;
            pCurrentAttack->m_sDamageDebugText = pCurrentAttack->m_sDamageDebugText + sDebugMsg;
        }
    }

    return nBonus;
}

//This one is required for correctly update PC sheet
int32_t Weapon::GetRangedDamageBonus(CNWSCreatureStats* pStats)
{
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;
    Weapon& plugin = *g_plugin;
    CNWSItem* pWeapon = nullptr;
    uint32_t nBaseItem;

    int nBonus = plugin.m_GetRangedDamageBonusHook->CallOriginal<int32_t>(pStats);

    pWeapon=pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);

    if (pWeapon == nullptr)
    {
        return nBonus;
    }
    else
    {
        nBaseItem = pWeapon->m_nBaseItem;
    }

    auto w = plugin.m_GreaterWeaponSpecializationMap.find(nBaseItem);

    bApplicableFeatExists = w != plugin.m_GreaterWeaponSpecializationMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat));

            if (bHasApplicableFeat) break;
        }
    }

    if (bApplicableFeatExists && bHasApplicableFeat)
    {
        nBonus += plugin.m_GreaterWeaponSpecializationDamageBonus;
    }

    return nBonus;
}

int32_t Weapon::GetAttackModifierVersus(CNWSCreatureStats* pStats, CNWSCreature* pCreature)
{
    Weapon& plugin = *g_plugin;
    CNWSCombatRound* pCombatRound;
    CNWSItem* pWeapon = nullptr;
    uint32_t nBaseItem;
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;

    int nMod = plugin.m_GetAttackModifierVersusHook->CallOriginal<int32_t>(pStats, pCreature);

    pCombatRound = pStats->m_pBaseCreature->m_pcCombatRound;
    if (pCombatRound == nullptr)
    {
        return nMod;
    }

    pWeapon = pCombatRound->GetCurrentAttackWeapon(pCombatRound->GetWeaponAttackType());
    if (pWeapon == nullptr)
    {
        return nMod;
    }
    else
    {
        nBaseItem = pWeapon->m_nBaseItem;
    }

    auto w = plugin.m_GreaterWeaponFocusMap.find(nBaseItem);

    bApplicableFeatExists = w != plugin.m_GreaterWeaponFocusMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat));

            if (bHasApplicableFeat) break;
        }
    }

    if (bApplicableFeatExists && bHasApplicableFeat)
    {
        nMod += plugin.m_GreaterFocusAttackBonus;

        if (*Globals::EnableCombatDebugging() && pStats->m_bIsPC)
        {
            auto sDebugMsg = CExoString(" + ") +
                             CExoString(std::to_string(plugin.m_GreaterFocusAttackBonus)) +
                             CExoString(" (Greater Weapon Focus Feat)") ;
            auto *pCurrentAttack = pStats->m_pBaseCreature->m_pcCombatRound->GetAttack(pStats->m_pBaseCreature->m_pcCombatRound->m_nCurrentAttack);
            pCurrentAttack->m_sAttackDebugText = pCurrentAttack->m_sAttackDebugText + sDebugMsg;
        }
    }

    if(plugin.m_GASling && nBaseItem == Constants::BaseItem::Sling && pStats->m_nRace != Constants::RacialType::Halfling && pStats->HasFeat(Constants::Feat::GoodAim))
    {
        nMod += Globals::Rules()->GetRulesetIntEntry("GOOD_AIM_MODIFIER", 1);

        if (*Globals::EnableCombatDebugging() && pStats->m_bIsPC)
        {
            auto sDebugMsg = CExoString(" + ") +
                             CExoString(std::to_string(Globals::Rules()->GetRulesetIntEntry("GOOD_AIM_MODIFIER", 1))) +
                             CExoString(" (Good Aim Feat)") ;
            auto *pCurrentAttack = pStats->m_pBaseCreature->m_pcCombatRound->GetAttack(pStats->m_pBaseCreature->m_pcCombatRound->m_nCurrentAttack);
            pCurrentAttack->m_sAttackDebugText = pCurrentAttack->m_sAttackDebugText + sDebugMsg;
        }
    }

    return nMod;
}

//This one is required for correctly update PC sheet
int32_t Weapon::GetMeleeAttackBonus(CNWSCreatureStats* pStats, int32_t bOffHand, int32_t bIncludeBase, int32_t bTouchAttack)
{
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;
    Weapon& plugin = *g_plugin;
    CNWSItem* pWeapon = nullptr;
    uint32_t nBaseItem;

    int nBonus = plugin.m_GetMeleeAttackBonusHook->CallOriginal<int32_t>(pStats, bOffHand, bIncludeBase, bTouchAttack);

    if (bTouchAttack)
    {
        return nBonus;
    }

    if (bOffHand)
    {
        pWeapon=pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::LeftHand);

        // Check for two handed
        if (pWeapon == nullptr)
        {
            auto *pMain = pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);
            if (pMain)
            {
                auto *pBase = Globals::Rules()->m_pBaseItemArray->GetBaseItem(pMain->m_nBaseItem);
                if (pBase && pBase->m_nWeaponWield == 8)
                {
                    pWeapon = pMain;
                }
            }
        }
    }
    else
    {
        pWeapon=pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);
    }

    if (pWeapon == nullptr)
    {
        nBaseItem = Constants::BaseItem::Gloves;
    }
    else
    {
        nBaseItem = pWeapon->m_nBaseItem;
    }

    auto w = plugin.m_GreaterWeaponFocusMap.find(nBaseItem);

    bApplicableFeatExists = w != plugin.m_GreaterWeaponFocusMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat));

            if (bHasApplicableFeat) break;
        }
    }

    if (bApplicableFeatExists && bHasApplicableFeat)
    {
        return nBonus + plugin.m_GreaterFocusAttackBonus;
    }

    return nBonus;
}

//This one is required for correctly update PC sheet
int32_t Weapon::GetRangedAttackBonus(CNWSCreatureStats* pStats, int32_t bIncludeBase, int32_t bTouchAttack)
{
    int32_t bApplicableFeatExists = 0;
    int32_t bHasApplicableFeat = 0;
    Weapon& plugin = *g_plugin;
    CNWSItem* pWeapon = nullptr;
    uint32_t nBaseItem;

    int nBonus = plugin.m_GetRangedAttackBonusHook->CallOriginal<int32_t>(pStats, bIncludeBase, bTouchAttack);

    if (bTouchAttack)
    {
        return nBonus;
    }

    pWeapon=pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);

    if (pWeapon == nullptr)
    {
        return nBonus;
    }

    nBaseItem = pWeapon->m_nBaseItem;

    auto w = plugin.m_GreaterWeaponFocusMap.find(nBaseItem);

    bApplicableFeatExists = w != plugin.m_GreaterWeaponFocusMap.end();

    if (bApplicableFeatExists)
    {
        for (auto feat : w->second)
        {
            bHasApplicableFeat = (pStats->HasFeat(feat));

            if (bHasApplicableFeat) break;
        }
    }

    if (bApplicableFeatExists && bHasApplicableFeat)
    {
        nBonus += plugin.m_GreaterFocusAttackBonus;
    }

    if(plugin.m_GASling && nBaseItem == Constants::BaseItem::Sling && pStats->m_nRace != Constants::RacialType::Halfling && pStats->HasFeat(Constants::Feat::GoodAim))
    {
        nBonus += 1;
    }
    return nBonus;
}

int32_t Weapon::ToggleMode(CNWSCreature *pCreature, uint8_t nMode)
{
    Weapon& plugin = *g_plugin;
    if (nMode == Constants::ToggleMode::FlurryOfBlows)
    {
        pCreature->SetCombatMode(Constants::CombatMode::FlurryOfBlows, pCreature->m_nCombatMode != Constants::CombatMode::FlurryOfBlows);
        return 1;
    }

    return plugin.m_ToggleModeHook->CallOriginal<int32_t>(pCreature, nMode);
}

int32_t Weapon::GetUseMonkAttackTables(CNWSCreatureStats* pStats, int32_t bForceUnarmed)
{
    Weapon& plugin = *g_plugin;
    CNWSItem* pWeapon;
    int nMonk = plugin.GetLevelByClass(pStats, Constants::ClassType::Monk);

    if (nMonk < 1 || !pStats->m_pBaseCreature->GetUseMonkAbilities())
    {
        return 0;
    }

    pWeapon=pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::RightHand);

    if (pWeapon == nullptr)
    {
        return 1;
    }

    if (bForceUnarmed)
    {
        return 0;
    }

    auto w = plugin.m_MonkWeaponSet.find(pWeapon->m_nBaseItem);
    if (w == plugin.m_MonkWeaponSet.end() && pWeapon->m_nBaseItem!=Constants::BaseItem::Kama)
    {
        return 0;
    }

    // Right hand weapon is correct, now check left hand
    pWeapon=pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::LeftHand);
    if (pWeapon == nullptr)
    {
        return 1;
    }

    w = plugin.m_MonkWeaponSet.find(pWeapon->m_nBaseItem);
    if (w == plugin.m_MonkWeaponSet.end() &&
        pWeapon->m_nBaseItem != Constants::BaseItem::Kama &&
        pWeapon->m_nBaseItem != Constants::BaseItem::Torch)
    {
        return 0;
    }

    return 1;
}


bool Weapon::GetIsWeaponLight(CNWSCreatureStats* pStats, CNWSItem* pWeapon, bool bFinesse)
{
    Weapon& plugin = *g_plugin;

    if (GetIsUnarmedWeapon(pWeapon))
    {
        return true;
    }

    if (pStats->m_pBaseCreature == nullptr ||
        pStats->m_pBaseCreature->m_nCreatureSize < (int32_t) Constants::CreatureSize::Tiny ||
        pStats->m_pBaseCreature->m_nCreatureSize > (int32_t) Constants::CreatureSize::Huge)
    {
        return false;
    }

    if (bFinesse)
    {
        auto w = plugin.m_WeaponFinesseSizeMap.find(pWeapon->m_nBaseItem);
        int iSize =  (w == plugin.m_WeaponFinesseSizeMap.end()) ? Constants::CreatureSize::Huge + 1 : w->second;

        if (pStats->m_pBaseCreature->m_nCreatureSize >= iSize)
        {
            return true;
        }
    }

    int rel = pStats->m_pBaseCreature->GetRelativeWeaponSize(pWeapon);

    // Ensure small creatures can finesse small weapons
    if (bFinesse &&
        (uint32_t) (pStats->m_pBaseCreature->m_nCreatureSize) <= Constants::CreatureSize::Small)
    {
        return (rel <= 0);
    }

    return (rel < 0);
}

bool Weapon::GetIsUnarmedWeapon(CNWSItem* pWeapon)
{
    Weapon& plugin = *g_plugin;

    if (pWeapon == nullptr)
        return true;

    // In case of standard unarmed weapon return true
    if (pWeapon->m_nBaseItem == Constants::BaseItem::Gloves       ||
        pWeapon->m_nBaseItem == Constants::BaseItem::Bracer       ||
        pWeapon->m_nBaseItem == Constants::BaseItem::CreatureSlashWeapon ||
        pWeapon->m_nBaseItem == Constants::BaseItem::CreaturePierceWeapon ||
        pWeapon->m_nBaseItem == Constants::BaseItem::CreatureBludgeWeapon ||
        pWeapon->m_nBaseItem == Constants::BaseItem::CreatureSlashPierceWeapon)
    {
        return true;
    }

    // Check if weapon should be considered unarmed
    auto w = plugin.m_WeaponUnarmedSet.find(pWeapon->m_nBaseItem);
    return (w == plugin.m_WeaponUnarmedSet.end()) ? false : true;
}

int Weapon::GetLevelByClass(CNWSCreatureStats *pStats, uint32_t nClassType)
{
    for (int i = 0; i < pStats->m_nNumMultiClasses; i++)
    {
        if (pStats->m_ClassInfo[i].m_nClass == nClassType)
            return pStats->m_ClassInfo[i].m_nLevel;
    }

    return 0;
}

ArgumentStack Weapon::SetOneHalfStrength(ArgumentStack&& args)
{
    auto objectId = Services::Events::ExtractArgument<ObjectID>(args);

    if(objectId == Constants::OBJECT_INVALID)
    {
        LOG_INFO("Invalid Object Passed into SetOneHalfStrength");
        return Services::Events::Arguments();
    }

    auto bMulti = Services::Events::ExtractArgument<int32_t>(args);
    bool bPersist = !!Services::Events::ExtractArgument<int32_t>(args);
    if(bMulti)
        g_plugin->GetServices()->m_perObjectStorage->Set(objectId, "ONE_HALF_STRENGTH", 1, bPersist);
    else
        g_plugin->GetServices()->m_perObjectStorage->Remove(objectId, "ONE_HALF_STRENGTH");

    return Services::Events::Arguments();
}

ArgumentStack Weapon::GetOneHalfStrength(ArgumentStack&& args)
{
    auto objectId = Services::Events::ExtractArgument<ObjectID>(args);
    int32_t retVal = 0;
    if(objectId != Constants::OBJECT_INVALID)
    {
        auto exist = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(objectId, "ONE_HALF_STRENGTH");
        if(exist)
            retVal = exist.value();
    }

    return Services::Events::Arguments(retVal);
}

}
