
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
	  1,
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

#undef REGISTER
   
   GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreatureStats__GetWeaponFocus>(&Weapon::GetWeaponFocus);
   m_GetWeaponFocusHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreatureStats__GetWeaponFocus);

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
   
   if(feat>-1)
   {	
      return 1;
   }
   
   return  plugin.m_GetWeaponFocusHook->CallOriginal<int32_t>(pStats, pWeapon);

}

}
