#pragma once

#include <unordered_map>
#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "API/Types.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSItem.hpp"


using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Weapon {

class Weapon : public NWNXLib::Plugin
{
public:
   Weapon(const Plugin::CreateParams& params);
   virtual ~Weapon();

private:
   ArgumentStack SetWeaponFocusFeat (ArgumentStack&& args);
   
   NWNXLib::Hooking::FunctionHook* m_GetWeaponFocusHook;

   static int32_t GetWeaponFocus(NWNXLib::API::CNWSCreatureStats* thisPtr, NWNXLib::API::CNWSItem* pItem);
      
   std::unordered_map<std::uint32_t, std::uint32_t> m_WeaponFocusMap;
};
 
}
