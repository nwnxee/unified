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

const int NWNX_WEAPON_OPT_GRTFOCUS_AB_BONUS = 0;
const int NWNX_WEAPON_OPT_GRTSPEC_DAM_BONUS = 1;

const int NWNX_WEAPON_GETDATA_DC = 0;

const int NWNX_WEAPON_SETDATA_DC_BYPASS = 0;

struct DevastatingCriticalDataStr
{
   uint32_t oidWeapon;
   uint32_t oidTarget;
   int32_t  nDamage;
   bool     bBypass;
};

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
      ArgumentStack SetGreaterWeaponSpecializationFeat   (ArgumentStack&& args);
      ArgumentStack SetGreaterWeaponFocusFeat            (ArgumentStack&& args);
      ArgumentStack SetWeaponIsMonkWeapon                (ArgumentStack&& args);
      ArgumentStack SetOption                            (ArgumentStack&& args);
      ArgumentStack SetDevastatingCritalEventScript      (ArgumentStack&& args);
      ArgumentStack GetEventData                         (ArgumentStack&& args);
      ArgumentStack SetEventData                         (ArgumentStack&& args);
      
      NWNXLib::Hooking::FunctionHook* m_GetWeaponFocusHook;
      NWNXLib::Hooking::FunctionHook* m_GetEpicWeaponFocusHook;
      NWNXLib::Hooking::FunctionHook* m_GetWeaponImprovedCriticalHook; 
      NWNXLib::Hooking::FunctionHook* m_GetEpicWeaponOverwhelmingCriticalHook;   
      NWNXLib::Hooking::FunctionHook* m_GetEpicWeaponDevastatingCriticalHook;   
      NWNXLib::Hooking::FunctionHook* m_GetWeaponSpecializationHook;
      NWNXLib::Hooking::FunctionHook* m_GetEpicWeaponSpecializationHook;
      NWNXLib::Hooking::FunctionHook* m_GetIsWeaponOfChoiceHook;
      NWNXLib::Hooking::FunctionHook* m_GetMeleeDamageBonusHook;
      NWNXLib::Hooking::FunctionHook* m_GetRangedDamageBonusHook;
      NWNXLib::Hooking::FunctionHook* m_GetDamageBonusHook;
      NWNXLib::Hooking::FunctionHook* m_GetMeleeAttackBonusHook;
      NWNXLib::Hooking::FunctionHook* m_GetRangedAttackBonusHook;
      NWNXLib::Hooking::FunctionHook* m_GetAttackModifierVersusHook;

      static int32_t GetWeaponFocus                   (NWNXLib::API::CNWSCreatureStats *pStats, NWNXLib::API::CNWSItem *pItem);
      static int32_t GetEpicWeaponFocus               (NWNXLib::API::CNWSCreatureStats *pStats, NWNXLib::API::CNWSItem *pItem);
      static int32_t GetWeaponFinesse                 (NWNXLib::API::CNWSCreatureStats *pStats, NWNXLib::API::CNWSItem *pItem);
      static int32_t GetWeaponImprovedCritical        (NWNXLib::API::CNWSCreatureStats *pStats, NWNXLib::API::CNWSItem *pItem);
      static int32_t GetWeaponSpecialization          (NWNXLib::API::CNWSCreatureStats *pStats, NWNXLib::API::CNWSItem *pItem);
      static int32_t GetEpicWeaponSpecialization      (NWNXLib::API::CNWSCreatureStats *pStats, NWNXLib::API::CNWSItem *pItem);
      static int32_t GetEpicWeaponOverwhelmingCritical(NWNXLib::API::CNWSCreatureStats *pStats, NWNXLib::API::CNWSItem *pItem);
      static int32_t GetEpicWeaponDevastatingCritical (NWNXLib::API::CNWSCreatureStats *pStats, NWNXLib::API::CNWSItem *pItem);
      static int32_t GetIsWeaponOfChoice              (NWNXLib::API::CNWSCreatureStats *pStats, uint32_t nBaseItem);
      static int32_t GetMeleeDamageBonus              (NWNXLib::API::CNWSCreatureStats *pStats, int32_t bOffHand, uint8_t nCreatureWeaponIndex);
      static int32_t GetRangedDamageBonus             (NWNXLib::API::CNWSCreatureStats *pStats);
      static int32_t GetDamageBonus                   (NWNXLib::API::CNWSCreatureStats *pStats, NWNXLib::API::CNWSCreature *pCreature, int32_t bOffHand);
      static int32_t GetMeleeAttackBonus              (NWNXLib::API::CNWSCreatureStats *pStats, bool bOffHand, bool bIncludeBase, bool bTouchAttack);
      static int32_t GetRangedAttackBonus             (NWNXLib::API::CNWSCreatureStats *pStats, bool bIncludeBase, bool bTouchAttack);
      static int32_t GetAttackModifierVersus          (NWNXLib::API::CNWSCreatureStats *pStats, NWNXLib::API::CNWSCreature* pCreature);
      static int32_t GetUseMonkAttackTables           (NWNXLib::API::CNWSCreatureStats *pStats, bool bForceUnarmed);

      
      std::map<std::uint32_t, std::uint32_t> m_WeaponFocusMap;
      std::map<std::uint32_t, std::uint32_t> m_EpicWeaponFocusMap;
      std::map<std::uint32_t, std::uint8_t>  m_WeaponFinesseSizeMap;
      std::map<std::uint32_t, std::uint32_t> m_WeaponImprovedCriticalMap;
      std::map<std::uint32_t, std::uint32_t> m_WeaponSpecializationMap; 
      std::map<std::uint32_t, std::uint32_t> m_EpicWeaponSpecializationMap;
      std::map<std::uint32_t, std::uint32_t> m_EpicWeaponOverwhelmingCriticalMap; 
      std::map<std::uint32_t, std::uint32_t> m_EpicWeaponDevastatingCriticalMap; 
      std::map<std::uint32_t, std::uint32_t> m_WeaponOfChoiceMap; 
      std::map<std::uint32_t, std::uint32_t> m_GreaterWeaponSpecializationMap;
      std::map<std::uint32_t, std::uint32_t> m_GreaterWeaponFocusMap;

      std::set<std::uint32_t>  m_WeaponUnarmedSet;
      std::set<std::uint32_t>  m_MonkWeaponSet;

      bool GetIsWeaponLight  (NWNXLib::API::CNWSCreatureStats* pInfo, NWNXLib::API::CNWSItem* pWeapon, bool bFinesse);
      bool GetIsUnarmedWeapon(NWNXLib::API::CNWSItem* pWeapon);
      int  GetLevelByClass   (NWNXLib::API::CNWSCreatureStats* pStats, uint32_t nClassType);

      // Devastating Critical data
      DevastatingCriticalDataStr m_DCData;
      std::string                m_DCScript;

      int m_GreaterFocusAttackBonus=1;
      int m_GreaterWeaponSpecializationDamageBonus=2;
   };
}
