#pragma once

#include <map>
#include <set>
#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "API/Types.hpp"
#include "API/CNWSCreature.hpp"
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
      ArgumentStack SetWeaponFocusFeat  (ArgumentStack&& args);
      ArgumentStack SetWeaponFinesseSize(ArgumentStack&& args);
      ArgumentStack SetWeaponUnarmed    (ArgumentStack&& args);

      NWNXLib::Hooking::FunctionHook* m_GetWeaponFocusHook;
      NWNXLib::Hooking::FunctionHook* m_GetWeaponFinesseHook;


      static int32_t GetWeaponFocus  (NWNXLib::API::CNWSCreatureStats* thisPtr, NWNXLib::API::CNWSItem* pItem);
      static int32_t GetWeaponFinesse(NWNXLib::API::CNWSCreatureStats* thisPtr, NWNXLib::API::CNWSItem* pItem);

      std::map<std::uint32_t, std::uint32_t> m_WeaponFocusMap;
      std::map<std::uint32_t, std::uint8_t>  m_WeaponFinesseSizeMap;
      
      std::set<std::uint32_t>  m_WeaponUnarmedSet;

      bool GetIsWeaponLight  (NWNXLib::API::CNWSCreatureStats* pInfo, NWNXLib::API::CNWSItem* pWeapon, bool bFinesse);
      bool GetIsUnarmedWeapon(NWNXLib::API::CNWSItem* pWeapon);

   };
}
