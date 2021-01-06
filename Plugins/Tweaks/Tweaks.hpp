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
class HidePlayersOnCharList;
class DisableMonkAbilitiesWhenPolymorphed;
class StringToIntBaseToAuto;
class DeadCreatureFiresOnAreaExit;
class PreserveActionsOnDMPossess;
class FixGreaterSanctuaryBug;
class ItemChargesCost;
class FixDispelEffectLevels;
class AddPrestigeclassCasterLevels;
class FixUnlimitedPotionsBug;
class UnhardcodeShields;
class BlockDMSpawnItem;
class FixArmorDexBonusUnderOne;
class FixItemNullptrInCItemRepository;
class ClearSpellEffectsOnTURDs;
class AlwaysReturnFullDEXStat;
class DisplayNumAttacksOverrideInCharacterSheet;

class Tweaks : public NWNXLib::Plugin
{
public:
    Tweaks(NWNXLib::Services::ProxyServiceList* services);
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
    std::unique_ptr<HidePlayersOnCharList> m_HidePlayersOnCharList;
    std::unique_ptr<DisableMonkAbilitiesWhenPolymorphed> m_DisableMonkAbilitiesWhenPolymorphed;
    std::unique_ptr<StringToIntBaseToAuto> m_StringToIntBaseToAuto;
    std::unique_ptr<DeadCreatureFiresOnAreaExit> m_DeadCreatureFiresOnAreaExit;
    std::unique_ptr<PreserveActionsOnDMPossess> m_PreserveActionsOnDMPossess;
    std::unique_ptr<FixGreaterSanctuaryBug> m_FixGreaterSanctuaryBug;
    std::unique_ptr<ItemChargesCost> m_ItemChargesCost;
    std::unique_ptr<FixDispelEffectLevels> m_FixDispelEffectLevels;
    std::unique_ptr<AddPrestigeclassCasterLevels> m_AddPrestigeclassCasterLevels;
    std::unique_ptr<FixUnlimitedPotionsBug> m_FixUnlimitedPotionsBug;
    std::unique_ptr<UnhardcodeShields> m_UnhardcodeShields;
    std::unique_ptr<BlockDMSpawnItem> m_BlockDMSpawnItem;
    std::unique_ptr<FixArmorDexBonusUnderOne> m_FixArmorDexBonusUnderOne;
    std::unique_ptr<FixItemNullptrInCItemRepository> m_FixItemNullptrInCItemRepository;
    std::unique_ptr<ClearSpellEffectsOnTURDs> m_ClearSpellEffectsOnTURDs;
    std::unique_ptr<AlwaysReturnFullDEXStat> m_AlwaysReturnFullDEXStat;
    std::unique_ptr<DisplayNumAttacksOverrideInCharacterSheet> m_DisplayNumAttacksOverrideInCharacterSheet;
};

}
