#pragma once

#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

struct DamageDataStr
{
   uint32_t oidDamager;
   int32_t  vDamage[13];
};

namespace Damage {

class Damage : public NWNXLib::Plugin
{
      public:
      Damage(const Plugin::CreateParams& params);
         virtual ~Damage();

      private:      
         ArgumentStack SetDamageEventScript(ArgumentStack&& args);
         ArgumentStack GetEventData(ArgumentStack&& args);
         ArgumentStack SetEventData(ArgumentStack&& args);

         NWNXLib::Hooking::FunctionHook* m_OnApplyDamageHook;

         static int32_t OnApplyDamage(NWNXLib::API::CNWSEffectListHandler *pThis, NWNXLib::API::CNWSObject *pObject, NWNXLib::API::CGameEffect *pEffect, bool bLoadingGame);
      
         std::string m_DamageScript; 
         DamageDataStr m_DamageData;
};

}
