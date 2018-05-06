#include "Damage.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "API/CGameEffect.hpp"
#include "API/CNWSObject.hpp"
#include "API/Globals.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSCreature.hpp"
#include "Utils.hpp"

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
   
   m_DamageScript = Services::Events::ExtractArgument<std::string>(args);
   LOG_INFO("Set Damage Event Script to %s", m_DamageScript.c_str());
   
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
   CNWSCreature *pCreature;
   uint32_t objID;
   
   if( plugin.m_DamageScript.empty() || pObject==nullptr || pEffect==nullptr || 
      pEffect->m_nParamInteger == nullptr ||(objID=pObject->m_idSelf)==Constants::OBJECT_INVALID)
   {
      return plugin.m_OnApplyDamageHook->CallOriginal<int32_t>(pThis, pObject, pEffect, bLoadingGame);  
   }

   pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(objID);

   if(pCreature==nullptr || pCreature->m_pStats==nullptr)
   {
      return plugin.m_OnApplyDamageHook->CallOriginal<int32_t>(pThis, pObject, pEffect, bLoadingGame);    
   }

   
   // Prepare the data for the nwscript
   plugin.m_DamageData.oidDamager=pEffect->m_oidCreator;
   
   for(int k=0; k<13; k++)
   {
      plugin.m_DamageData.vDamage[k] = pEffect->m_nParamInteger[k];
   }  
   
   // Call the script
   Utils::ExecuteScript(plugin.m_DamageScript, objID); 

   // Change the data
   for(int k=0; k<13; k++)
   {
      pEffect->m_nParamInteger[k] = plugin.m_DamageData.vDamage[k];
   }
   
   return plugin.m_OnApplyDamageHook->CallOriginal<int32_t>(pThis, pObject, pEffect, bLoadingGame);
}

}
