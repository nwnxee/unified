#include "Tweaks.hpp"
#include "Tweaks/HideClassesOnCharList.hpp"
#include "Tweaks/PlayerDyingHitPointLimit.hpp"
#include "Tweaks/DisablePause.hpp"
#include "Tweaks/DisableQuicksave.hpp"
#include "Tweaks/CompareVarsForMerge.hpp"
#include "Tweaks/ParryAllAttacks.hpp"
#include "Tweaks/SneakAttackCritImmunity.hpp"
#include "Tweaks/PreserveDepletedItems.hpp"
#include "Tweaks/HidePlayersOnCharList.hpp"
#include "Tweaks/DisableMonkAbilitiesWhenPolymorphed.hpp"
#include "Tweaks/StringToIntBaseToAuto.hpp"
#include "Tweaks/DeadCreatureFiresOnAreaExit.hpp"
#include "Tweaks/PreserveActionsOnDMPossess.hpp"
#include "Tweaks/FixGreaterSanctuaryBug.hpp"
#include "Tweaks/ItemChargesCost.hpp"
#include "Tweaks/FixDispelEffectLevels.hpp"
#include "Tweaks/AddPrestigeclassCasterLevels.hpp"
#include "Tweaks/FixUnlimitedPotionsBug.hpp"
#include "Tweaks/UnhardcodeShields.hpp"
#include "Tweaks/BlockDMSpawnItem.hpp"
#include "Tweaks/FixArmorDexBonusUnderOne.hpp"
#include "Tweaks/FixItemNullptrInCItemRepository.hpp"
#include "Tweaks/ClearSpellEffectsOnTURDs.hpp"
#include "Tweaks/AlwaysReturnFullDEXStat.hpp"
#include "Tweaks/DisplayNumAttacksOverrideInCharacterSheet.hpp"



using namespace NWNXLib;

static Tweaks::Tweaks* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Tweaks::Tweaks(services);
    return g_plugin;
}

namespace Tweaks {

Tweaks::Tweaks(Services::ProxyServiceList* services)
    : Plugin(services)
{
    if (Config::Get<bool>("HIDE_CLASSES_ON_CHAR_LIST", false))
    {
        LOG_INFO("Hiding the display of classes on the character list.");
        m_HideClassesOnCharlist = std::make_unique<HideClassesOnCharList>();
    }

    int32_t hplimit = Config::Get<int32_t>("PLAYER_DYING_HP_LIMIT", -10);
    if (hplimit != -10)
    {
        LOG_INFO("Setting the player dying HP limit to %d", hplimit);
        m_PlayerDyingHitPointLimit = std::make_unique<PlayerDyingHitPointLimit>(hplimit);
    }

    if (Config::Get<bool>("DISABLE_PAUSE", false))
    {
        LOG_INFO("Disabling pausing of the server");
        m_DisablePause = std::make_unique<DisablePause>();
    }

    if (Config::Get<bool>("DISABLE_QUICKSAVE", false))
    {
        LOG_INFO("Disabling the quicksave option on the server");
        m_DisableQuicksave = std::make_unique<DisableQuicksave>();
    }

    if (Config::Get<bool>("COMPARE_VARIABLES_WHEN_MERGING", false))
    {
        LOG_INFO("Will compare local variables when merging item stacks");
        m_CompareVarsForMerge = std::make_unique<CompareVarsForMerge>();
    }

    if (Config::Get<bool>("PARRY_ALL_ATTACKS", false))
    {
        LOG_INFO("Parry will no longer be limited to one attack per flurry");
        m_ParryAllAttacks = std::make_unique<ParryAllAttacks>();
    }

    if (Config::Get<bool>("SNEAK_ATTACK_IGNORE_CRIT_IMMUNITY", false))
    {
        LOG_INFO("Sneak attacks will now be possible on creatures with immunity to critical hits");
        m_SneakAttackCritImmunity = std::make_unique<SneakAttackCritImmunity>();
    }

    if (Config::Get<bool>("PRESERVE_DEPLETED_ITEMS", false))
    {
        LOG_INFO("Items will no longer be destroyed when they run out of charges");
        m_PreserveDepletedItems = std::make_unique<PreserveDepletedItems>();
    }

    if (Config::Get<bool>("HIDE_DMS_ON_CHAR_LIST", false))
    {
        LOG_INFO("NWNX_TWEAKS_HIDE_DMS_ON_CHAR_LIST has been deprecated, please use NWNX_TWEAKS_HIDE_PLAYERS_ON_CHAR_LIST = 1");
        m_HidePlayersOnCharList = std::make_unique<HidePlayersOnCharList>(1);
    }
    else if (auto mode = Config::Get<int>("HIDE_PLAYERS_ON_CHAR_LIST", 0))
    {
        if (mode == 1)
            LOG_INFO("DMs will not be visible on character list.");
        else if (mode == 2)
            LOG_INFO("PCs will not be visible on character list.");
        else if (mode == 3)
            LOG_INFO("DMs and PCs will not be visible on character list.");
        m_HidePlayersOnCharList = std::make_unique<HidePlayersOnCharList>(mode);
    }

    if (Config::Get<bool>("DISABLE_MONK_ABILITIES_WHEN_POLYMORPHED", false))
    {
        LOG_INFO("Monk abilities (ac, speed, attacks) will be disabled during polymorph");
        m_DisableMonkAbilitiesWhenPolymorphed = std::make_unique<DisableMonkAbilitiesWhenPolymorphed>();
    }

    if (Config::Get<bool>("STRINGTOINT_BASE_TO_AUTO", false))
    {
        LOG_INFO("Setting StringToInt() base to auto to allow for conversion of hex strings to proper values.");
        m_StringToIntBaseToAuto = std::make_unique<StringToIntBaseToAuto>();
    }

    if (Config::Get<bool>("DEAD_CREATURES_TRIGGER_ON_AREA_EXIT", false))
    {
        LOG_INFO("Dead creatures will fire on area exit.");
        m_DeadCreatureFiresOnAreaExit = std::make_unique<DeadCreatureFiresOnAreaExit>();
    }

    if (Config::Get<bool>("PRESERVE_ACTIONS_ON_DM_POSSESS", false))
    {
        LOG_INFO("DMs possessing a creature will no longer clear their actions");
        m_PreserveActionsOnDMPossess = std::make_unique<PreserveActionsOnDMPossess>();
    }

    if (Config::Get<bool>("FIX_GREATER_SANCTUARY_BUG", false))
    {
        LOG_INFO("Greater sanctuary bug fixed.");
        m_FixGreaterSanctuaryBug = std::make_unique<FixGreaterSanctuaryBug>();
    }

    if (auto mode = Config::Get<int>("ITEM_CHARGES_COST_MODE", 0))
    {
        LOG_INFO("Changing cost for items with charges.");
        m_ItemChargesCost = std::make_unique<ItemChargesCost>(mode);
    }

    if (Config::Get<bool>("FIX_DISPEL_EFFECT_LEVELS", false))
    {
        LOG_INFO("Fixing dispel checks vs. effects created by deleted objects.");
        m_FixDispelEffectLevels = std::make_unique<FixDispelEffectLevels>();
    }

    if (Config::Get<bool>("ADD_PRESTIGECLASS_CASTER_LEVELS", false))
    {
        LOG_INFO("Automatically adding prestige class caster levels using (Div|Arc)SpellLvlMod colums in classes.2da");
        m_AddPrestigeclassCasterLevels = std::make_unique<AddPrestigeclassCasterLevels>();
    }

    if (Config::Get<bool>("FIX_UNLIMITED_POTIONS_BUG", false))
    {
        LOG_INFO("Fixing unlimited potion/scroll uses bug");
        m_FixUnlimitedPotionsBug = std::make_unique<FixUnlimitedPotionsBug>();
    }

    if (Config::Get<bool>("UNHARDCODE_SHIELDS", false))
    {
        LOG_INFO("Using baseitems.2da to define shield AC and create shield-like items");
        m_UnhardcodeShields = std::make_unique<UnhardcodeShields>();
    }

    if (Config::Get<bool>("BLOCK_DM_SPAWNITEM", false))
    {
        LOG_INFO("Blocking the dm_spawnitem console command");
        m_BlockDMSpawnItem = std::make_unique<BlockDMSpawnItem>();
    }

    if (Config::Get<bool>("FIX_ARMOR_DEX_BONUS_UNDER_ONE", false))
    {
        LOG_INFO("Allowing armors with max DEX bonus under 1.");
        m_FixArmorDexBonusUnderOne = std::make_unique<FixArmorDexBonusUnderOne>();
    }

    if (Config::Get<bool>("FIX_ITEM_NULLPTR_IN_CITEMREPOSITORY", false))
    {
        LOG_INFO("Will check for invalid items in the CItemRepository List.");
        m_FixItemNullptrInCItemRepository = std::make_unique<FixItemNullptrInCItemRepository>();
    }

    if (Config::Get<bool>("CLEAR_SPELL_EFFECTS_ON_TURDS", false))
    {
        LOG_INFO("Effects on logged out users will be removed when a caster rests.");
        m_ClearSpellEffectsOnTURDs = std::make_unique<ClearSpellEffectsOnTURDs>();
    }

    if (Config::Get<bool>("ALWAYS_RETURN_FULL_DEX_STAT", false))
    {
        LOG_INFO("GetDEXStat() is always returning a creature's full Dexterity Stat.");
        m_AlwaysReturnFullDEXStat = std::make_unique<AlwaysReturnFullDEXStat>();
    }

    if (Config::Get<bool>("DISPLAY_NUM_ATTACKS_OVERRIDE_IN_CHARACTER_SHEET", false))
    {
        LOG_INFO("Number of attacks per round overridden by SetBaseAttackBonus() will show on the character sheet.");
        m_DisplayNumAttacksOverrideInCharacterSheet = std::make_unique<DisplayNumAttacksOverrideInCharacterSheet>();
    }
}

Tweaks::~Tweaks()
{
}

}
