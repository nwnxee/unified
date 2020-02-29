#pragma once

#include "Plugin.hpp"

namespace Tweaks {

class HideClassesOnCharList;
class PlayerDyingHitPointLimit;
class DisablePause;
class DisableQuicksave;
class FixMasterServerDNS;
class CompareVarsForMerge;
class ParryAllAttacks;
class SneakAttackCritImmunity;
class PreserveDepletedItems;
class HideDMsOnCharList;
class DisableMonkAbilitiesWhenPolymorphed;
class StringToIntBaseToAuto;
class DeadCreatureFiresOnAreaExit;
class PreserveActionsOnDMPossess;
class FixGreaterSanctuaryBug;
class ItemChargesCost;

class Tweaks : public NWNXLib::Plugin
{
public:
    Tweaks(const Plugin::CreateParams& params);
    virtual ~Tweaks();

private:
    std::unique_ptr<HideClassesOnCharList> m_HideClassesOnCharlist;
    std::unique_ptr<PlayerDyingHitPointLimit> m_PlayerDyingHitPointLimit;
    std::unique_ptr<DisablePause> m_DisablePause;
    std::unique_ptr<DisableQuicksave> m_DisableQuicksave;
    std::unique_ptr<CompareVarsForMerge> m_CompareVarsForMerge;
    std::unique_ptr<ParryAllAttacks> m_ParryAllAttacks;
    std::unique_ptr<SneakAttackCritImmunity> m_SneakAttackCritImmunity;
    std::unique_ptr<PreserveDepletedItems> m_PreserveDepletedItems;
    std::unique_ptr<HideDMsOnCharList> m_HideDMsOnCharList;
    std::unique_ptr<DisableMonkAbilitiesWhenPolymorphed> m_DisableMonkAbilitiesWhenPolymorphed;
    std::unique_ptr<StringToIntBaseToAuto> m_StringToIntBaseToAuto;
    std::unique_ptr<DeadCreatureFiresOnAreaExit> m_DeadCreatureFiresOnAreaExit;
    std::unique_ptr<PreserveActionsOnDMPossess> m_PreserveActionsOnDMPossess;
    std::unique_ptr<FixGreaterSanctuaryBug> m_FixGreaterSanctuaryBug;
    std::unique_ptr<ItemChargesCost> m_ItemChargesCost;
};

}
