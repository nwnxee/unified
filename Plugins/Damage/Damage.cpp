#include "Damage.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "API/CGameEffect.hpp"
#include "API/CNWSObject.hpp"
#include "API/Globals.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSCreature.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "Utils.hpp"

#include <cstring>

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Damage::Damage> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
   return new Plugin::Info
   {
      "Damage",
      "Damage related functions",
      "Bhaal (original nwnx2 plugin from Baaleos)",
      "marca.argentea at gmail.com",
      1,
      true
   };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
   g_plugin = new Damage::Damage(params);
   return g_plugin;
}

namespace Damage {

Damage::Damage(const Plugin::CreateParams& params)
  : Plugin(params)
{

#define REGISTER(func) \
      GetServices()->m_events->RegisterEvent(#func, std::bind(&Damage::func, this, std::placeholders::_1))

      REGISTER(SetDamageEventScript);
      REGISTER(GetEventData);
      REGISTER(SetEventData);

#undef REGISTER

   GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSEffectListHandler__OnApplyDamage>(&Damage::OnApplyDamage);
   m_OnApplyDamageHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSEffectListHandler__OnApplyDamage);

   m_DamageScript="";
}

Damage::~Damage()
{
}

ArgumentStack Damage::SetDamageEventScript(ArgumentStack&& args)
{
   ArgumentStack stack;
   Types::ObjectID oidOwner = Constants::OBJECT_INVALID;
   std::string script = Services::Events::ExtractArgument<std::string>(args);

   // If compiled with old NSS, they won't be pushing the object after the script, so need to handle that.
   try
   {
      oidOwner = Services::Events::ExtractArgument<Types::ObjectID>(args);
   }
   catch(std::runtime_error e)
   {
      LOG_WARNING("Please update nwnx_damage.nss and recompile your scripts");
   }

   if (oidOwner == Constants::OBJECT_INVALID)
   {
      m_DamageScript = script;
      LOG_INFO("Set Global Damage Event Script to %s", m_DamageScript.c_str());
   }
   else
   {
      if (script != "")
      {
         g_plugin->GetServices()->m_perObjectStorage->Set(oidOwner, "DAMAGE_EVENT_SCRIPT", script);
         LOG_INFO("Set object 0x%08x Damage Event Script to %s", oidOwner, script.c_str());
      }
      else
      {
         g_plugin->GetServices()->m_perObjectStorage->Remove(oidOwner, "DAMAGE_EVENT_SCRIPT");
         LOG_INFO("Clearing Damage Event Script for object 0x%08x", oidOwner);
      }
   }

   return stack;
}

ArgumentStack Damage::GetEventData(ArgumentStack&&)
{
   ArgumentStack stack;
   
   for(int k=12; k>=0; k--)
   {
      Services::Events::InsertArgument(stack, m_DamageData.vDamage[k]);
   }   
   Services::Events::InsertArgument(stack, m_DamageData.oidDamager);
   
   return stack;   
}

ArgumentStack Damage::SetEventData(ArgumentStack&& args)
{
   ArgumentStack stack;
    
   for(int k=0; k<13; k++)
   {
      m_DamageData.vDamage[k] = Services::Events::ExtractArgument<int32_t>(args);
   }      
   
   return stack;   
}


int32_t Damage::OnApplyDamage(NWNXLib::API::CNWSEffectListHandler *pThis, NWNXLib::API::CNWSObject *pObject, NWNXLib::API::CGameEffect *pEffect, bool bLoadingGame)
{
   Damage& plugin = *g_plugin;
   auto posScript = plugin.GetServices()->m_perObjectStorage->Get<std::string>(pObject, "DAMAGE_EVENT_SCRIPT");
   std::string script = posScript ? *posScript : plugin.m_DamageScript;

   if (!script.empty())
   {
      // We only run the OnDamage event for creatures.
      if (Utils::AsNWSCreature(pObject))
      {
         // Prepare the data for the nwscript
         plugin.m_DamageData.oidDamager = pEffect->m_oidCreator;

         std::memcpy(plugin.m_DamageData.vDamage, pEffect->m_nParamInteger, sizeof(plugin.m_DamageData.vDamage));
         Utils::ExecuteScript(script, pObject->m_idSelf);
         std::memcpy(pEffect->m_nParamInteger, plugin.m_DamageData.vDamage, sizeof(plugin.m_DamageData.vDamage));
      }
   }

   return plugin.m_OnApplyDamageHook->CallOriginal<int32_t>(pThis, pObject, pEffect, bLoadingGame);
}

}
