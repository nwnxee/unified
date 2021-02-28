#pragma once

#include "nwnx.hpp"
#include <map>
#include <set>
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

struct MaxRangedAttackDistanceOverride
{
    float maxRangedAttackDistance;
    float maxRangedPassiveAttackDistance;
};

using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace Weapon {

class Weapon : public NWNXLib::Plugin
{
public:
    Weapon(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Weapon();

private:
    ArgumentStack SetWeaponFocusFeat                   (ArgumentStack&& args);
    ArgumentStack SetEpicWeaponFocusFeat               (ArgumentStack&& args);
    ArgumentStack SetWeaponFinesseSize                 (ArgumentStack&& args);
    ArgumentStack GetWeaponFinesseSize                 (ArgumentStack&& args);
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
    ArgumentStack SetDevastatingCriticalEventScript    (ArgumentStack&& args);
    ArgumentStack GetEventData                         (ArgumentStack&& args);
    ArgumentStack SetEventData                         (ArgumentStack&& args);
    ArgumentStack SetOneHalfStrength                   (ArgumentStack&& args);
    ArgumentStack GetOneHalfStrength                   (ArgumentStack&& args);
    ArgumentStack SetMaxRangedAttackDistanceOverride   (ArgumentStack&& args);

    NWNXLib::Hooks::Hook m_GetWeaponFocusHook;
    NWNXLib::Hooks::Hook m_GetEpicWeaponFocusHook;
    NWNXLib::Hooks::Hook m_GetWeaponImprovedCriticalHook;
    NWNXLib::Hooks::Hook m_GetEpicWeaponOverwhelmingCriticalHook;
    NWNXLib::Hooks::Hook m_GetEpicWeaponDevastatingCriticalHook;
    NWNXLib::Hooks::Hook m_GetWeaponSpecializationHook;
    NWNXLib::Hooks::Hook m_GetEpicWeaponSpecializationHook;
    NWNXLib::Hooks::Hook m_GetIsWeaponOfChoiceHook;
    NWNXLib::Hooks::Hook m_GetMeleeDamageBonusHook;
    NWNXLib::Hooks::Hook m_GetRangedDamageBonusHook;
    NWNXLib::Hooks::Hook m_GetDamageBonusHook;
    NWNXLib::Hooks::Hook m_GetMeleeAttackBonusHook;
    NWNXLib::Hooks::Hook m_GetRangedAttackBonusHook;
    NWNXLib::Hooks::Hook m_GetAttackModifierVersusHook;
    NWNXLib::Hooks::Hook m_ToggleModeHook;

    static int32_t GetWeaponFocus                   (CNWSCreatureStats *pStats, CNWSItem* pItem);
    static int32_t GetEpicWeaponFocus               (CNWSCreatureStats *pStats, CNWSItem *pItem);
    static int32_t GetWeaponFinesse                 (CNWSCreatureStats *pStats, CNWSItem *pItem);
    static int32_t GetWeaponImprovedCritical        (CNWSCreatureStats *pStats, CNWSItem *pItem);
    static int32_t GetWeaponSpecialization          (CNWSCreatureStats *pStats, CNWSItem *pItem);
    static int32_t GetEpicWeaponSpecialization      (CNWSCreatureStats *pStats, CNWSItem *pItem);
    static int32_t GetEpicWeaponOverwhelmingCritical(CNWSCreatureStats *pStats, CNWSItem *pItem);
    static int32_t GetEpicWeaponDevastatingCritical (CNWSCreatureStats *pStats, CNWSItem *pItem);
    static int32_t GetIsWeaponOfChoice              (CNWSCreatureStats *pStats, uint32_t nBaseItem);
    static int32_t GetMeleeDamageBonus              (CNWSCreatureStats *pStats, int32_t bOffHand, uint8_t nCreatureWeaponIndex);
    static int32_t GetRangedDamageBonus             (CNWSCreatureStats *pStats);
    static int32_t GetDamageBonus                   (CNWSCreatureStats *pStats, CNWSCreature *pCreature, int32_t bOffHand);
    static int32_t GetMeleeAttackBonus              (CNWSCreatureStats *pStats, int32_t bOffHand, int32_t bIncludeBase, int32_t bTouchAttack);
    static int32_t GetRangedAttackBonus             (CNWSCreatureStats *pStats, int32_t bIncludeBase, int32_t bTouchAttack);
    static int32_t GetAttackModifierVersus          (CNWSCreatureStats *pStats, CNWSCreature* pCreature);
    static int32_t GetUseMonkAttackTables           (CNWSCreatureStats *pStats, int32_t bForceUnarmed);
    static int32_t ToggleMode                       (CNWSCreature *pCreature, uint8_t nMode);

    std::map<std::uint32_t, std::set<std::uint32_t>> m_WeaponFocusMap;
    std::map<std::uint32_t, std::set<std::uint32_t>> m_EpicWeaponFocusMap;
    std::map<std::uint32_t, std::uint8_t>  m_WeaponFinesseSizeMap;
    std::map<std::uint32_t, std::set<std::uint32_t>> m_WeaponImprovedCriticalMap;
    std::map<std::uint32_t, std::set<std::uint32_t>> m_WeaponSpecializationMap;
    std::map<std::uint32_t, std::set<std::uint32_t>> m_EpicWeaponSpecializationMap;
    std::map<std::uint32_t, std::set<std::uint32_t>> m_EpicWeaponOverwhelmingCriticalMap;
    std::map<std::uint32_t, std::set<std::uint32_t>> m_EpicWeaponDevastatingCriticalMap;
    std::map<std::uint32_t, std::set<std::uint32_t>> m_WeaponOfChoiceMap;
    std::map<std::uint32_t, std::set<std::uint32_t>> m_GreaterWeaponSpecializationMap;
    std::map<std::uint32_t, std::set<std::uint32_t>> m_GreaterWeaponFocusMap;

    std::set<std::uint32_t>  m_WeaponUnarmedSet;
    std::set<std::uint32_t>  m_MonkWeaponSet;

    bool GetIsWeaponLight  (CNWSCreatureStats* pInfo, CNWSItem* pWeapon, bool bFinesse);
    bool GetIsUnarmedWeapon(CNWSItem* pWeapon);
    int  GetLevelByClass   (CNWSCreatureStats* pStats, uint32_t nClassType);

    // Devastating Critical data
    DevastatingCriticalDataStr m_DCData;
    std::string                m_DCScript;

    int m_GreaterFocusAttackBonus = 1;
    int m_GreaterWeaponSpecializationDamageBonus = 2;
    bool m_GASling = false;

    std::unordered_map<uint32_t, MaxRangedAttackDistanceOverride> m_MaxRangedAttackDistanceOverrideMap;
};
}
