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
      ArgumentStack SetWeaponFocusFeat                   (ArgumentStack&& args);
      ArgumentStack SetEpicWeaponFocusFeat               (ArgumentStack&& args);
      ArgumentStack SetWeaponFinesseSize                 (ArgumentStack&& args);
      ArgumentStack SetWeaponUnarmed                     (ArgumentStack&& args);
      ArgumentStack SetWeaponImprovedCriticalFeat        (ArgumentStack&& args);
      ArgumentStack SetEpicWeaponOverwhelmingCriticalFeat(ArgumentStack&& args);
      ArgumentStack SetEpicWeaponDevastatingCriticalFeat (ArgumentStack&& args);
      ArgumentStack SetWeaponSpecializationFeat          (ArgumentStack&& args);      
      ArgumentStack SetEpicWeaponSpecializationFeat      (ArgumentStack&& args);
      ArgumentStack SetWeaponOfChoiceFeat                (ArgumentStack&& args);
      
      NWNXLib::Hooking::FunctionHook* m_GetWeaponFocusHook;
      NWNXLib::Hooking::FunctionHook* m_GetEpicWeaponFocusHook;
      NWNXLib::Hooking::FunctionHook* m_GetWeaponImprovedCriticalHook; 
      NWNXLib::Hooking::FunctionHook* m_GetEpicWeaponOverwhelmingCriticalHook;   
      NWNXLib::Hooking::FunctionHook* m_GetEpicWeaponDevastatingCriticalHook;   
      NWNXLib::Hooking::FunctionHook* m_GetWeaponSpecializationHook;
      NWNXLib::Hooking::FunctionHook* m_GetEpicWeaponSpecializationHook;
      NWNXLib::Hooking::FunctionHook* m_GetIsWeaponOfChoiceHook;

      static int32_t GetWeaponFocus                   (NWNXLib::API::CNWSCreatureStats* thisPtr, NWNXLib::API::CNWSItem* pItem);
      static int32_t GetEpicWeaponFocus               (NWNXLib::API::CNWSCreatureStats* thisPtr, NWNXLib::API::CNWSItem* pItem);
      static int32_t GetWeaponFinesse                 (NWNXLib::API::CNWSCreatureStats* thisPtr, NWNXLib::API::CNWSItem* pItem);
      static int32_t GetWeaponImprovedCritical        (NWNXLib::API::CNWSCreatureStats* thisPtr, NWNXLib::API::CNWSItem* pItem);
      static int32_t GetWeaponSpecialization          (NWNXLib::API::CNWSCreatureStats* thisPtr, NWNXLib::API::CNWSItem* pItem);
      static int32_t GetEpicWeaponSpecialization      (NWNXLib::API::CNWSCreatureStats* thisPtr, NWNXLib::API::CNWSItem* pItem);
      static int32_t GetEpicWeaponOverwhelmingCritical(NWNXLib::API::CNWSCreatureStats* thisPtr, NWNXLib::API::CNWSItem* pItem);
      static int32_t GetEpicWeaponDevastatingCritical (NWNXLib::API::CNWSCreatureStats* thisPtr, NWNXLib::API::CNWSItem* pItem);
      static int32_t GetIsWeaponOfChoice              (NWNXLib::API::CNWSCreatureStats* thisPtr, uint32_t nBaseItem);

      std::map<std::uint32_t, std::uint32_t> m_WeaponFocusMap;
      std::map<std::uint32_t, std::uint32_t> m_EpicWeaponFocusMap;
      std::map<std::uint32_t, std::uint8_t>  m_WeaponFinesseSizeMap;
      std::map<std::uint32_t, std::uint32_t> m_WeaponImprovedCriticalMap;
      std::map<std::uint32_t, std::uint32_t> m_WeaponSpecializationMap; 
      std::map<std::uint32_t, std::uint32_t> m_EpicWeaponSpecializationMap;
      std::map<std::uint32_t, std::uint32_t> m_EpicWeaponOverwhelmingCriticalMap; 
      std::map<std::uint32_t, std::uint32_t> m_EpicWeaponDevastatingCriticalMap; 
      std::map<std::uint32_t, std::uint32_t> m_WeaponOfChoiceMap; 

      std::set<std::uint32_t>  m_WeaponUnarmedSet;

      bool GetIsWeaponLight  (NWNXLib::API::CNWSCreatureStats* pInfo, NWNXLib::API::CNWSItem* pWeapon, bool bFinesse);
      bool GetIsUnarmedWeapon(NWNXLib::API::CNWSItem* pWeapon);

   };
}
