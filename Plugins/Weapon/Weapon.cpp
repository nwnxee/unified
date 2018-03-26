
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
   GetServices()->m_events->RegisterEvent(#func, std::bind(&Weapon::func, this, std::placeholders::_1))

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

}

Weapon::~Weapon()
{
}

ArgumentStack Weapon::SetWeaponFocusFeat(ArgumentStack&& args)
{
   ArgumentStack stack;
   
   const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
   const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
   
   if(w_bitem>0 && feat >0)
   {
      m_WeaponFocusMap.insert({w_bitem, feat});
   }
   
   return stack;   
}

ArgumentStack Weapon::SetEpicWeaponFocusFeat(ArgumentStack&& args)
{
   ArgumentStack stack;
   
   const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
   const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
   
   if(w_bitem>0 && feat >0)
   {
      m_EpicWeaponFocusMap.insert({w_bitem, feat});
   }
   
   return stack;   
}

ArgumentStack Weapon::SetWeaponFinesseSize(ArgumentStack&& args)
{
   ArgumentStack stack;
   
   const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
   const auto size     = Services::Events::ExtractArgument<int32_t>(args);
   
   if(w_bitem>0 && size >0 && size <= 255)
   {
      m_WeaponFinesseSizeMap.insert({w_bitem, size});
   }
   
   return stack;
}

ArgumentStack Weapon::SetWeaponUnarmed(ArgumentStack&& args)
{
   ArgumentStack stack;
   
   const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
   
   if(w_bitem>0)
   {
      m_WeaponUnarmedSet.insert(w_bitem);
   }
   
   return stack;
}

ArgumentStack Weapon::SetWeaponImprovedCriticalFeat(ArgumentStack&& args)
{
   ArgumentStack stack;
   
   const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
   const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
   
   if(w_bitem>0 && feat >0)
   {
      m_WeaponImprovedCriticalMap.insert({w_bitem, feat});
   }
   
   return stack;   
}

ArgumentStack Weapon::SetWeaponSpecializationFeat(ArgumentStack&& args)
{
   ArgumentStack stack;
   
   const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
   const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
   
   if(w_bitem>0 && feat >0)
   {
      m_WeaponSpecializationMap.insert({w_bitem, feat});
   }
   
   return stack;   
}

ArgumentStack Weapon::SetEpicWeaponSpecializationFeat(ArgumentStack&& args)
{
   ArgumentStack stack;
   
   const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
   const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
   
   if(w_bitem>0 && feat >0)
   {
      m_EpicWeaponSpecializationMap.insert({w_bitem, feat});
   }
   
   return stack;   
}

ArgumentStack Weapon::SetEpicWeaponOverwhelmingCriticalFeat(ArgumentStack&& args)
{
   ArgumentStack stack;
   
   const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
   const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
   
   if(w_bitem>0 && feat >0)
   {
      m_EpicWeaponOverwhelmingCriticalMap.insert({w_bitem, feat});
   }
   
   return stack;   
}

ArgumentStack Weapon::SetEpicWeaponDevastatingCriticalFeat(ArgumentStack&& args)
{
   ArgumentStack stack;
   
   const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
   const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
   
   if(w_bitem>0 && feat >0)
   {
      m_EpicWeaponDevastatingCriticalMap.insert({w_bitem, feat});
   }
   
   return stack;   
}

ArgumentStack Weapon::SetWeaponOfChoiceFeat(ArgumentStack&& args)
{
   ArgumentStack stack;
   
   const auto w_bitem  = Services::Events::ExtractArgument<int32_t>(args);
   const auto feat     = Services::Events::ExtractArgument<int32_t>(args);
   
   if(w_bitem>0 && feat >0)
   {
      m_WeaponOfChoiceMap.insert({w_bitem, feat});
   }
   
   return stack;   
}

int32_t Weapon::GetWeaponFocus(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
   int32_t feat=-1;
   Weapon& plugin = *g_plugin;   
   
   if(pWeapon==nullptr) 
   {
      auto w = plugin.m_WeaponFocusMap.find(Constants::BASE_ITEM_GLOVES);
      feat =  (w == plugin.m_WeaponFocusMap.end()) ? -1 : w->second;
   }
   else
   {
      auto w = plugin.m_WeaponFocusMap.find(pWeapon->m_nBaseItem);
      feat =  (w == plugin.m_WeaponFocusMap.end()) ? -1 : w->second;
   }
   
   if (feat == Constants::FEAT_WEAPON_FOCUS_CREATURE && 
       pStats->HasFeat(Constants::FEAT_WEAPON_FOCUS_UNARMED_STRIKE))
   {
      return 1;
   }   
   return (feat>-1 ? pStats->HasFeat(feat) : plugin.m_GetWeaponFocusHook->CallOriginal<int32_t>(pStats, pWeapon)); 
}

int32_t Weapon::GetEpicWeaponFocus(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
   int32_t feat=-1;
   Weapon& plugin = *g_plugin;   
   
   if(pWeapon==nullptr) 
   {
      auto w = plugin.m_EpicWeaponFocusMap.find(Constants::BASE_ITEM_GLOVES);
      feat =  (w == plugin.m_EpicWeaponFocusMap.end()) ? -1 : w->second;
   }
   else
   {
      auto w = plugin.m_EpicWeaponFocusMap.find(pWeapon->m_nBaseItem);
      feat =  (w == plugin.m_EpicWeaponFocusMap.end()) ? -1 : w->second;
   }
   
   if (feat == Constants::FEAT_EPIC_WEAPON_FOCUS_CREATURE && 
       pStats->HasFeat(Constants::FEAT_EPIC_WEAPON_FOCUS_UNARMED))
   {
      return 1;
   }   
   return (feat>-1 ? pStats->HasFeat(feat) : plugin.m_GetEpicWeaponFocusHook->CallOriginal<int32_t>(pStats, pWeapon)); 
}

int32_t Weapon::GetWeaponFinesse(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
   Weapon& plugin = *g_plugin;

   if(!pStats->HasFeat(Constants::FEAT_WEAPON_FINESSE))
      return 0;

   return plugin.GetIsWeaponLight(pStats, pWeapon, true) ? 1 : 0;
}

int32_t Weapon::GetWeaponImprovedCritical(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
   int32_t feat=-1;
   Weapon& plugin = *g_plugin;   
   
   if(pWeapon==nullptr) 
   {
      auto w = plugin.m_WeaponImprovedCriticalMap.find(Constants::BASE_ITEM_GLOVES);
      feat =  (w == plugin.m_WeaponImprovedCriticalMap.end()) ? -1 : w->second;
   }
   else
   {
      auto w = plugin.m_WeaponImprovedCriticalMap.find(pWeapon->m_nBaseItem);
      feat =  (w == plugin.m_WeaponImprovedCriticalMap.end()) ? -1 : w->second;
   }
    
   return (feat>-1 ? pStats->HasFeat(feat) : plugin.m_GetWeaponImprovedCriticalHook->CallOriginal<int32_t>(pStats, pWeapon)); 
}

int32_t Weapon::GetWeaponSpecialization(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
   int32_t feat=-1;
   Weapon& plugin = *g_plugin;   
   
   if(pWeapon==nullptr) 
   {
      auto w = plugin.m_WeaponSpecializationMap.find(Constants::BASE_ITEM_GLOVES);
      feat =  (w == plugin.m_WeaponSpecializationMap.end()) ? -1 : w->second;
   }
   else
   {
      auto w = plugin.m_WeaponSpecializationMap.find(pWeapon->m_nBaseItem);
      feat =  (w == plugin.m_WeaponSpecializationMap.end()) ? -1 : w->second;
   }
    
   return (feat>-1 ? pStats->HasFeat(feat) : plugin.m_GetWeaponSpecializationHook->CallOriginal<int32_t>(pStats, pWeapon)); 
}

int32_t Weapon::GetEpicWeaponSpecialization(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
   int32_t feat=-1;
   Weapon& plugin = *g_plugin;   
   
   if(pWeapon==nullptr) 
   {
      auto w = plugin.m_EpicWeaponSpecializationMap.find(Constants::BASE_ITEM_GLOVES);
      feat =  (w == plugin.m_EpicWeaponSpecializationMap.end()) ? -1 : w->second;
   }
   else
   {
      auto w = plugin.m_EpicWeaponSpecializationMap.find(pWeapon->m_nBaseItem);
      feat =  (w == plugin.m_EpicWeaponSpecializationMap.end()) ? -1 : w->second;
   }
    
   return (feat>-1 ? pStats->HasFeat(feat) : plugin.m_GetEpicWeaponSpecializationHook->CallOriginal<int32_t>(pStats, pWeapon)); 
}

int32_t Weapon::GetEpicWeaponOverwhelmingCritical(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
   int32_t feat=-1;
   Weapon& plugin = *g_plugin;   
   
   if(pWeapon==nullptr) 
   {
      auto w = plugin.m_EpicWeaponOverwhelmingCriticalMap.find(Constants::BASE_ITEM_GLOVES);
      feat =  (w == plugin.m_EpicWeaponOverwhelmingCriticalMap.end()) ? -1 : w->second;
   }
   else
   {
      auto w = plugin.m_EpicWeaponOverwhelmingCriticalMap.find(pWeapon->m_nBaseItem);
      feat =  (w == plugin.m_EpicWeaponOverwhelmingCriticalMap.end()) ? -1 : w->second;
   }
    
   return (feat>-1 ? pStats->HasFeat(feat) : plugin.m_GetEpicWeaponOverwhelmingCriticalHook->CallOriginal<int32_t>(pStats, pWeapon)); 
}

int32_t Weapon::GetEpicWeaponDevastatingCritical(NWNXLib::API::CNWSCreatureStats* pStats, NWNXLib::API::CNWSItem* pWeapon)
{
   int32_t feat=-1;
   Weapon& plugin = *g_plugin;   
   
   if(pWeapon==nullptr) 
   {
      auto w = plugin.m_EpicWeaponDevastatingCriticalMap.find(Constants::BASE_ITEM_GLOVES);
      feat =  (w == plugin.m_EpicWeaponDevastatingCriticalMap.end()) ? -1 : w->second;
   }
   else
   {
      auto w = plugin.m_EpicWeaponDevastatingCriticalMap.find(pWeapon->m_nBaseItem);
      feat =  (w == plugin.m_EpicWeaponDevastatingCriticalMap.end()) ? -1 : w->second;
   }
    
   return (feat>-1 ? pStats->HasFeat(feat) : plugin.m_GetEpicWeaponDevastatingCriticalHook->CallOriginal<int32_t>(pStats, pWeapon)); 
}

int32_t Weapon::GetIsWeaponOfChoice(NWNXLib::API::CNWSCreatureStats* pStats, uint32_t nBaseItem)
{
   int32_t feat=-1;
   Weapon& plugin = *g_plugin;   
   
   auto w = plugin.m_WeaponOfChoiceMap.find(nBaseItem);
   feat =  (w == plugin.m_WeaponOfChoiceMap.end()) ? -1 : w->second;
      
   return (feat>-1 ? pStats->HasFeat(feat) : plugin.m_GetIsWeaponOfChoiceHook->CallOriginal<int32_t>(pStats, nBaseItem)); 
}

bool Weapon::GetIsWeaponLight(NWNXLib::API::CNWSCreatureStats* pInfo, NWNXLib::API::CNWSItem* pWeapon, bool bFinesse)
{
   Weapon& plugin = *g_plugin;

   if (GetIsUnarmedWeapon(pWeapon))
   {
      return true;
   }

   if (pInfo->m_pBaseCreature == nullptr ||
      pInfo->m_pBaseCreature->m_nCreatureSize < (int32_t) Constants::CREATURE_SIZE_TINY ||
      pInfo->m_pBaseCreature->m_nCreatureSize > (int32_t) Constants::CREATURE_SIZE_HUGE)
   {
      return false;
   }

   if (bFinesse)
   {
      auto w = plugin.m_WeaponFinesseSizeMap.find(pWeapon->m_nBaseItem);
      int iSize =  (w == plugin.m_WeaponFinesseSizeMap.end()) ? Constants::CREATURE_SIZE_HUGE + 1 : w->second;
      
      if(pInfo->m_pBaseCreature->m_nCreatureSize >= iSize) 
      {
         return true;
      }
   }

   int rel =  pInfo->m_pBaseCreature->GetRelativeWeaponSize(pWeapon); 

   // Ensure small creatures can finesse small weapons
   if (bFinesse && 
      (uint32_t) (pInfo->m_pBaseCreature->m_nCreatureSize) <= Constants::CREATURE_SIZE_SMALL)
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
   if(pWeapon->m_nBaseItem == Constants::BASE_ITEM_GLOVES       ||
      pWeapon->m_nBaseItem == Constants::BASE_ITEM_BRACER       ||
      pWeapon->m_nBaseItem == Constants::BASE_ITEM_CSLASHWEAPON ||
      pWeapon->m_nBaseItem == Constants::BASE_ITEM_CPIERCWEAPON ||
      pWeapon->m_nBaseItem == Constants::BASE_ITEM_CBLUDGWEAPON ||
      pWeapon->m_nBaseItem == Constants::BASE_ITEM_CSLSHPRCWEAP)
   {
      return true;
   }

   // Check if weapon should be considered unarmed
   auto w = plugin.m_WeaponUnarmedSet.find(pWeapon->m_nBaseItem);
   return (w == plugin.m_WeaponUnarmedSet.end()) ? false : true;
}

}
