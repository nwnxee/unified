
// Log currently generates warnings when no arguments are given to format string
// TODO: Should really clean up the log so it doesn't warn in these cases
#pragma GCC diagnostic ignored "-Wformat-security"

#include "Weapon.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "API/Functions.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWFeat.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWRules.hpp"
#include "Utils.hpp"
#include "Services/Messaging/Messaging.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Weapon::Weapon> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Weapon",
        "Weapons related functions",
        "Bhaal",
        "marca.argentea at gmail.com",
        2,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
   g_plugin = new Weapon::Weapon(params);
   return g_plugin;
}

namespace Weapon {

Weapon::Weapon(const Plugin::CreateParams& params)
  : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(SetWeaponFocusFeat);
    REGISTER(SetEpicWeaponFocusFeat);
    REGISTER(SetWeaponFinesseSize);
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

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetWeaponFocus>(&Weapon::GetWeaponFocus);
    m_GetWeaponFocusHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetWeaponFocus);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetEpicWeaponFocus>(&Weapon::GetEpicWeaponFocus);
    m_GetEpicWeaponFocusHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetEpicWeaponFocus);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetWeaponFinesse>(&Weapon::GetWeaponFinesse);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetWeaponImprovedCritical>(&Weapon::GetWeaponImprovedCritical);
    m_GetWeaponImprovedCriticalHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetWeaponImprovedCritical);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetWeaponSpecialization>(&Weapon::GetWeaponSpecialization);
    m_GetWeaponSpecializationHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetWeaponSpecialization);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetEpicWeaponSpecialization>(&Weapon::GetEpicWeaponSpecialization);
    m_GetEpicWeaponSpecializationHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetEpicWeaponSpecialization);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetEpicWeaponOverwhelmingCritical>(&Weapon::GetEpicWeaponOverwhelmingCritical);
    m_GetEpicWeaponOverwhelmingCriticalHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetEpicWeaponOverwhelmingCritical);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetEpicWeaponDevastatingCritical>(&Weapon::GetEpicWeaponDevastatingCritical);
    m_GetEpicWeaponDevastatingCriticalHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetEpicWeaponDevastatingCritical);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetIsWeaponOfChoice>(&Weapon::GetIsWeaponOfChoice);
    m_GetIsWeaponOfChoiceHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetIsWeaponOfChoice);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetMeleeDamageBonus>(&Weapon::GetMeleeDamageBonus);
    m_GetMeleeDamageBonusHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetMeleeDamageBonus);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetDamageBonus>(&Weapon::GetDamageBonus);
    m_GetDamageBonusHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetDamageBonus);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetRangedDamageBonus>(&Weapon::GetRangedDamageBonus);
    m_GetRangedDamageBonusHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetRangedDamageBonus);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetAttackModifierVersus>(&Weapon::GetAttackModifierVersus);
    m_GetAttackModifierVersusHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetAttackModifierVersus);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetMeleeAttackBonus>(&Weapon::GetMeleeAttackBonus);
    m_GetMeleeAttackBonusHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetMeleeAttackBonus);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetRangedAttackBonus>(&Weapon::GetRangedAttackBonus);
    m_GetRangedAttackBonusHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetRangedAttackBonus);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetUseMonkAttackTables>(&Weapon::GetUseMonkAttackTables);

    m_WeaponFinesseSizeMap.insert({Constants::BaseItem::Rapier, (uint8_t) Constants::CreatureSize::Medium});

    m_DCScript="";
}

Weapon::~Weapon()
{
}

ArgumentStack Weapon::SetWeaponFocusFeat(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    m_WeaponFocusMap.insert({w_bitem, feat});
    auto featName = Globals::Rules()->GetFeat(feat)->GetNameText();
    auto baseItemName = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem)->GetNameText();
    LOG_INFO("Weapon Focus Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return stack;
}

ArgumentStack Weapon::SetGreaterWeaponFocusFeat(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    m_GreaterWeaponFocusMap.insert({w_bitem, feat});
    auto featName = Globals::Rules()->GetFeat(feat)->GetNameText();
    auto baseItemName = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem)->GetNameText();
    LOG_INFO("Greater Weapon Focus Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return stack;
}

ArgumentStack Weapon::SetEpicWeaponFocusFeat(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    m_EpicWeaponFocusMap.insert({w_bitem, feat});
    auto featName = Globals::Rules()->GetFeat(feat)->GetNameText();
    auto baseItemName = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem)->GetNameText();
    LOG_INFO("Epic Weapon Focus Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return stack;
}

ArgumentStack Weapon::SetWeaponFinesseSize(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto size     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(size > 0);
      ASSERT_OR_THROW(size <= 255);

    m_WeaponFinesseSizeMap.insert({w_bitem, size});
    auto baseItemName = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem)->GetNameText();
    LOG_INFO("Weapon Finesse Size %d added for Base Item Type %d [%s]", size, w_bitem, baseItemName);

    return stack;
}

ArgumentStack Weapon::SetWeaponUnarmed(ArgumentStack&& args)
{
   ArgumentStack stack;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);

    m_WeaponUnarmedSet.insert(w_bitem);
    auto baseItemName = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem)->GetNameText();
    LOG_INFO("Base Item Type %d [%s] set as unarmed weapon", w_bitem, baseItemName);

   return stack;
}

ArgumentStack Weapon::SetWeaponIsMonkWeapon(ArgumentStack&& args)
{
    ArgumentStack stack;
    static bool bFirstTime = true;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);

    m_MonkWeaponSet.insert(w_bitem);
    auto baseItemName = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem)->GetNameText();
    LOG_INFO("Base Item Type %d [%s] set as monk weapon", w_bitem, baseItemName);

    if (bFirstTime)
    {
        bFirstTime = false;
        // Hooks for flurry of blows
        GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreature__ToggleMode>(&ToggleMode);
        m_ToggleModeHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreature__ToggleMode);
        g_plugin->GetServices()->m_messaging->BroadcastMessage("NWNX_WEAPON_SIGNAL", {"FLURRY_OF_BLOWS_REQUIRED"});
        LOG_NOTICE("Flurry of blows requires activation of CombatModes plugin");
    }

    return stack;
}

ArgumentStack Weapon::SetWeaponImprovedCriticalFeat(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    m_WeaponImprovedCriticalMap.insert({w_bitem, feat});
    auto featName = Globals::Rules()->GetFeat(feat)->GetNameText();
    auto baseItemName = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem)->GetNameText();
    LOG_INFO("Improved Critical Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return stack;
}

ArgumentStack Weapon::SetWeaponSpecializationFeat(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    m_WeaponSpecializationMap.insert({w_bitem, feat});
    auto featName = Globals::Rules()->GetFeat(feat)->GetNameText();
    auto baseItemName = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem)->GetNameText();
    LOG_INFO("Weapon Specialization Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return stack;
}

ArgumentStack Weapon::SetGreaterWeaponSpecializationFeat(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    m_GreaterWeaponSpecializationMap.insert({w_bitem, feat});
    auto featName = Globals::Rules()->GetFeat(feat)->GetNameText();
    auto baseItemName = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem)->GetNameText();
    LOG_INFO("Greater Weapon Specialization Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return stack;
}

ArgumentStack Weapon::SetEpicWeaponSpecializationFeat(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    m_EpicWeaponSpecializationMap.insert({w_bitem, feat});
    auto featName = Globals::Rules()->GetFeat(feat)->GetNameText();
    auto baseItemName = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem)->GetNameText();
    LOG_INFO("Epic Weapon Specialization Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return stack;
}

ArgumentStack Weapon::SetEpicWeaponOverwhelmingCriticalFeat(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    m_EpicWeaponOverwhelmingCriticalMap.insert({w_bitem, feat});
    auto featName = Globals::Rules()->GetFeat(feat)->GetNameText();
    auto baseItemName = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem)->GetNameText();
    LOG_INFO("Overwhelming Critical Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return stack;
}

ArgumentStack Weapon::SetEpicWeaponDevastatingCriticalFeat(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    m_EpicWeaponDevastatingCriticalMap.insert({w_bitem, feat});
    auto featName = Globals::Rules()->GetFeat(feat)->GetNameText();
    auto baseItemName = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem)->GetNameText();
    LOG_INFO("Devastating Critical Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return stack;
}

ArgumentStack Weapon::SetWeaponOfChoiceFeat(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(w_bitem >= Constants::BaseItem::MIN);
      ASSERT_OR_THROW(w_bitem <= Constants::BaseItem::MAX);
    const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(feat >= Constants::Feat::MIN);
      ASSERT_OR_THROW(feat <= Constants::Feat::MAX);

    m_WeaponOfChoiceMap.insert({w_bitem, feat});
    auto featName = Globals::Rules()->GetFeat(feat)->GetNameText();
    auto baseItemName = Globals::Rules()->m_pBaseItemArray->GetBaseItem(w_bitem)->GetNameText();
    LOG_INFO("Weapon of Choice Feat %d [%s] added for Base Item Type %d [%s]", feat, featName, w_bitem, baseItemName);

    return stack;
}

ArgumentStack Weapon::SetOption(ArgumentStack&& args)
{
    ArgumentStack stack;

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
    return stack;
}

ArgumentStack Weapon::SetDevastatingCriticalEventScript(ArgumentStack&& args)
{
    ArgumentStack stack;

    m_DCScript = Services::Events::ExtractArgument<std::string>(args);
    LOG_INFO("Set Devastating Critical Event Script to %s", m_DCScript);

    return stack;
}

ArgumentStack Weapon::GetEventData(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto nOption  = Services::Events::ExtractArgument<int32_t>(args);

    switch(nOption)
    {
        case NWNX_WEAPON_GETDATA_DC:
            Services::Events::InsertArgument(stack, m_DCData.nDamage);
            Services::Events::InsertArgument(stack, m_DCData.oidTarget);
            Services::Events::InsertArgument(stack, m_DCData.oidWeapon);
            break;
    }

    return stack;
}

ArgumentStack Weapon::SetEventData(ArgumentStack&& args)
{
    ArgumentStack stack;
    const auto nOption  = Services::Events::ExtractArgument<int32_t>(args);
    const auto nVal     = Services::Events::ExtractArgument<int32_t>(args);

    switch(nOption)
    {
        case NWNX_WEAPON_SETDATA_DC_BYPASS:
            LOG_INFO("Set NWNX_WEAPON_SETDATA_DC_BYPASS to %d", nVal);
            m_DCData.bBypass = nVal;
            break;
    }

    return stack;
}


int32_t Weapon::GetWeaponFocus(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
    int32_t feat = -1;
    Weapon& plugin = *g_plugin;

    if (pWeapon == nullptr)
    {
        auto w = plugin.m_WeaponFocusMap.find(Constants::BaseItem::Gloves);
        feat = (w == plugin.m_WeaponFocusMap.end()) ? -1 : w->second;
    }
    else
    {
        auto w = plugin.m_WeaponFocusMap.find(pWeapon->m_nBaseItem);
        feat = (w == plugin.m_WeaponFocusMap.end()) ? -1 : w->second;
    }

    if (feat == Constants::Feat::WeaponFocus_Creature &&
       pStats->HasFeat(Constants::Feat::WeaponFocus_UnarmedStrike))
    {
        return 1;
    }
    return (feat > -1 ? pStats->HasFeat(feat) : plugin.m_GetWeaponFocusHook->CallOriginal<int32_t>(pStats, pWeapon));
}

int32_t Weapon::GetEpicWeaponFocus(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
    int32_t feat = -1;
    Weapon& plugin = *g_plugin;

    if (pWeapon == nullptr)
    {
        auto w = plugin.m_EpicWeaponFocusMap.find(Constants::BaseItem::Gloves);
        feat = (w == plugin.m_EpicWeaponFocusMap.end()) ? -1 : w->second;
    }
    else
    {
        auto w = plugin.m_EpicWeaponFocusMap.find(pWeapon->m_nBaseItem);
        feat = (w == plugin.m_EpicWeaponFocusMap.end()) ? -1 : w->second;
    }

    if (feat == Constants::Feat::EpicWeaponFocus_Creature &&
       pStats->HasFeat(Constants::Feat::EpicWeaponFocus_Unarmed))
    {
        return 1;
    }
    return (feat > -1 ? pStats->HasFeat(feat) : plugin.m_GetEpicWeaponFocusHook->CallOriginal<int32_t>(pStats, pWeapon));
}

int32_t Weapon::GetWeaponFinesse(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
    Weapon& plugin = *g_plugin;

    if (!pStats->HasFeat(Constants::Feat::WeaponFinesse))
        return 0;

    return plugin.GetIsWeaponLight(pStats, pWeapon, true) ? 1 : 0;
}

int32_t Weapon::GetWeaponImprovedCritical(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
    int32_t feat = -1;
    Weapon& plugin = *g_plugin;

    if (pWeapon == nullptr)
    {
        auto w = plugin.m_WeaponImprovedCriticalMap.find(Constants::BaseItem::Gloves);
        feat = (w == plugin.m_WeaponImprovedCriticalMap.end()) ? -1 : w->second;
    }
    else
    {
        auto w = plugin.m_WeaponImprovedCriticalMap.find(pWeapon->m_nBaseItem);
        feat = (w == plugin.m_WeaponImprovedCriticalMap.end()) ? -1 : w->second;
    }

    return (feat > -1 ? pStats->HasFeat(feat) : plugin.m_GetWeaponImprovedCriticalHook->CallOriginal<int32_t>(pStats, pWeapon));
}

int32_t Weapon::GetWeaponSpecialization(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
    int32_t feat = -1;
    Weapon& plugin = *g_plugin;

    if (pWeapon == nullptr)
    {
        auto w = plugin.m_WeaponSpecializationMap.find(Constants::BaseItem::Gloves);
        feat = (w == plugin.m_WeaponSpecializationMap.end()) ? -1 : w->second;
    }
    else
    {
        auto w = plugin.m_WeaponSpecializationMap.find(pWeapon->m_nBaseItem);
        feat = (w == plugin.m_WeaponSpecializationMap.end()) ? -1 : w->second;
    }

    return (feat > -1 ? pStats->HasFeat(feat) : plugin.m_GetWeaponSpecializationHook->CallOriginal<int32_t>(pStats, pWeapon));
}

int32_t Weapon::GetEpicWeaponSpecialization(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
    int32_t feat = -1;
    Weapon& plugin = *g_plugin;

    if (pWeapon == nullptr)
    {
        auto w = plugin.m_EpicWeaponSpecializationMap.find(Constants::BaseItem::Gloves);
        feat = (w == plugin.m_EpicWeaponSpecializationMap.end()) ? -1 : w->second;
    }
    else
    {
        auto w = plugin.m_EpicWeaponSpecializationMap.find(pWeapon->m_nBaseItem);
        feat = (w == plugin.m_EpicWeaponSpecializationMap.end()) ? -1 : w->second;
    }

    return (feat > -1 ? pStats->HasFeat(feat) : plugin.m_GetEpicWeaponSpecializationHook->CallOriginal<int32_t>(pStats, pWeapon));
}

int32_t Weapon::GetEpicWeaponOverwhelmingCritical(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
    int32_t feat = -1;
    Weapon& plugin = *g_plugin;

    if (pWeapon == nullptr)
    {
        auto w = plugin.m_EpicWeaponOverwhelmingCriticalMap.find(Constants::BaseItem::Gloves);
        feat = (w == plugin.m_EpicWeaponOverwhelmingCriticalMap.end()) ? -1 : w->second;
    }
    else
    {
        auto w = plugin.m_EpicWeaponOverwhelmingCriticalMap.find(pWeapon->m_nBaseItem);
        feat = (w == plugin.m_EpicWeaponOverwhelmingCriticalMap.end()) ? -1 : w->second;
    }

    return (feat > -1 ? pStats->HasFeat(feat) : plugin.m_GetEpicWeaponOverwhelmingCriticalHook->CallOriginal<int32_t>(pStats, pWeapon));
}

int32_t Weapon::GetEpicWeaponDevastatingCritical(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
    int32_t feat = -1;
    Weapon& plugin = *g_plugin;
    bool bFlag = false;

    if (pWeapon == nullptr)
    {
        auto w = plugin.m_EpicWeaponDevastatingCriticalMap.find(Constants::BaseItem::Gloves);
        feat = (w == plugin.m_EpicWeaponDevastatingCriticalMap.end()) ? -1 : w->second;
    }
    else
    {
        auto w = plugin.m_EpicWeaponDevastatingCriticalMap.find(pWeapon->m_nBaseItem);
        feat = (w == plugin.m_EpicWeaponDevastatingCriticalMap.end()) ? -1 : w->second;
    }
    bFlag = feat > -1 ? pStats->HasFeat(feat) : plugin.m_GetEpicWeaponDevastatingCriticalHook->CallOriginal<int32_t>(pStats, pWeapon);

    if (bFlag && !plugin.m_DCScript.empty())
    {
        NWNXLib::API::CNWSCreature         *pCreature    = pStats->m_pBaseCreature;
        NWNXLib::API::CNWSCombatRound      *pCombatRound = pCreature->m_pcCombatRound;
        NWNXLib::API::CNWSCombatAttackData *pAttackData  = pCombatRound->GetAttack(pCombatRound->m_nCurrentAttack);

        plugin.m_DCData.oidWeapon = pWeapon->m_idSelf;
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

int32_t Weapon::GetIsWeaponOfChoice(NWNXLib::API::CNWSCreatureStats* pStats, uint32_t nBaseItem)
{
    int32_t feat = -1;
    Weapon& plugin = *g_plugin;

    auto w = plugin.m_WeaponOfChoiceMap.find(nBaseItem);
    feat = (w == plugin.m_WeaponOfChoiceMap.end()) ? -1 : w->second;

    return (feat > -1) ? pStats->HasFeat(feat) : plugin.m_GetIsWeaponOfChoiceHook->CallOriginal<int32_t>(pStats, nBaseItem);
}

//This one is required for correctly update PC sheet
int32_t Weapon::GetMeleeDamageBonus(NWNXLib::API::CNWSCreatureStats* pStats, int32_t bOffHand, uint8_t nCreatureWeaponIndex)
{
    int32_t feat = -1;
    Weapon& plugin = *g_plugin;
    NWNXLib::API::CNWSItem* pWeapon = nullptr;
    uint32_t nBaseItem;

    int nBonus = plugin.m_GetMeleeDamageBonusHook->CallOriginal<int32_t>(pStats, bOffHand, nCreatureWeaponIndex);

    if (nCreatureWeaponIndex==255)
    {
        if (bOffHand)
        {
            pWeapon=pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::LeftHand);
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
    }

    auto w = plugin.m_GreaterWeaponSpecializationMap.find(nBaseItem);
    feat = (w == plugin.m_GreaterWeaponSpecializationMap.end()) ? -1 : w->second;

    if (feat > -1 && pStats->HasFeat(feat))
    {
        return nBonus + plugin.m_GreaterWeaponSpecializationDamageBonus;
    }

    return nBonus;
}

int32_t Weapon::GetDamageBonus(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSCreature *pCreature, int32_t bOffHand)
{
    int32_t feat = -1;
    Weapon& plugin = *g_plugin;
    NWNXLib::API::CNWSItem* pWeapon = nullptr;
    uint32_t nBaseItem;

    int nBonus = plugin.m_GetDamageBonusHook->CallOriginal<int32_t>(pStats, pCreature, bOffHand);

    if (bOffHand)
    {
        pWeapon=pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::LeftHand);
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

    auto w = plugin.m_GreaterWeaponSpecializationMap.find(nBaseItem);
    feat = (w == plugin.m_GreaterWeaponSpecializationMap.end()) ? -1 : w->second;

    if (feat > -1 && pStats->HasFeat(feat))
    {
        return nBonus+=plugin.m_GreaterWeaponSpecializationDamageBonus;
    }

    return nBonus;
}

//This one is required for correctly update PC sheet
int32_t Weapon::GetRangedDamageBonus(NWNXLib::API::CNWSCreatureStats* pStats)
{
    int32_t feat = -1;
    Weapon& plugin = *g_plugin;
    NWNXLib::API::CNWSItem* pWeapon = nullptr;
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
    feat = (w == plugin.m_GreaterWeaponSpecializationMap.end()) ? -1 : w->second;

    if (feat > -1 && pStats->HasFeat(feat))
    {
        return nBonus+=plugin.m_GreaterWeaponSpecializationDamageBonus;
    }

    return nBonus;
}


int32_t Weapon::GetAttackModifierVersus(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSCreature* pCreature)
{
    Weapon& plugin = *g_plugin;
    CNWSCombatRound* pCombatRound;
    NWNXLib::API::CNWSItem* pWeapon = nullptr;
    uint32_t nBaseItem;
    int32_t feat = -1;

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
    feat = (w == plugin.m_GreaterWeaponFocusMap.end()) ? -1 : w->second;

    if (feat > -1 && pStats->HasFeat(feat))
    {
        return nMod+=plugin.m_GreaterFocusAttackBonus;
    }

    return nMod;
}

//This one is required for correctly update PC sheet
int32_t Weapon::GetMeleeAttackBonus(NWNXLib::API::CNWSCreatureStats* pStats, bool bOffHand, bool bIncludeBase, bool bTouchAttack)
{
    int32_t feat = -1;
    Weapon& plugin = *g_plugin;
    NWNXLib::API::CNWSItem* pWeapon = nullptr;
    uint32_t nBaseItem;

    int nBonus = plugin.m_GetMeleeAttackBonusHook->CallOriginal<int32_t>(pStats, bOffHand, bIncludeBase, bTouchAttack);

    if (bTouchAttack)
    {
        return nBonus;
    }

    if (bOffHand)
    {
        pWeapon=pStats->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::LeftHand);
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
    feat = (w == plugin.m_GreaterWeaponFocusMap.end()) ? -1 : w->second;

    if (feat > -1 && pStats->HasFeat(feat))
    {
        return nBonus+=plugin.m_GreaterFocusAttackBonus;
    }

    return nBonus;
}

//This one is required for correctly update PC sheet
int32_t Weapon::GetRangedAttackBonus(NWNXLib::API::CNWSCreatureStats* pStats, bool bIncludeBase, bool bTouchAttack)
{
    int32_t feat = -1;
    Weapon& plugin = *g_plugin;
    NWNXLib::API::CNWSItem* pWeapon = nullptr;
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
    feat = (w == plugin.m_GreaterWeaponFocusMap.end()) ? -1 : w->second;

    if (feat > -1 && pStats->HasFeat(feat))
    {
        return nBonus+=plugin.m_GreaterFocusAttackBonus;
    }

    return nBonus;
}

int32_t Weapon::ToggleMode(CNWSCreature *pCreature, unsigned char nMode)
{
    Weapon& plugin = *g_plugin;
    if (nMode == Constants::ToggleMode::FlurryOfBlows)
    {
        pCreature->SetCombatMode(Constants::CombatMode::FlurryOfBlows, pCreature->m_nCombatMode != Constants::CombatMode::FlurryOfBlows);
        return 1;
    }

    return plugin.m_ToggleModeHook->CallOriginal<int32_t>(pCreature, nMode);
}

int32_t Weapon::GetUseMonkAttackTables(NWNXLib::API::CNWSCreatureStats* pStats, bool bForceUnarmed)
{
    Weapon& plugin = *g_plugin;
    NWNXLib::API::CNWSItem* pWeapon;
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


bool Weapon::GetIsWeaponLight(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon, bool bFinesse)
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

bool Weapon::GetIsUnarmedWeapon(NWNXLib::API::CNWSItem* pWeapon)
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

int Weapon::GetLevelByClass(NWNXLib::API::CNWSCreatureStats *pStats, uint32_t nClassType)
{
    for (int i = 0; i < pStats->m_nNumMultiClasses; i++)
    {
        if (pStats->m_ClassInfo[i].m_nClass == nClassType)
            return pStats->m_ClassInfo[i].m_nLevel;
    }

    return 0;
}


}
