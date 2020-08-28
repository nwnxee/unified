#include "Tweaks.hpp"
#include "Tweaks/HideClassesOnCharList.hpp"
#include "Tweaks/PlayerDyingHitPointLimit.hpp"
#include "Tweaks/DisablePause.hpp"
#include "Tweaks/DisableQuicksave.hpp"
#include "Tweaks/CompareVarsForMerge.hpp"
#include "Tweaks/ParryAllAttacks.hpp"
#include "Tweaks/SneakAttackCritImmunity.hpp"
#include "Tweaks/PreserveDepletedItems.hpp"
#include "Tweaks/HideDMsOnCharList.hpp"
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

#include "Services/Config/Config.hpp"


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
    if (GetServices()->m_config->Get<bool>("HIDE_CLASSES_ON_CHAR_LIST", false))
    {
        LOG_INFO("Hiding the display of classes on the character list.");
        m_HideClassesOnCharlist = std::make_unique<HideClassesOnCharList>(GetServices()->m_hooks.get());
    }

    int32_t hplimit = GetServices()->m_config->Get<int32_t>("PLAYER_DYING_HP_LIMIT", -10);
    if (hplimit != -10)
    {
        LOG_INFO("Setting the player dying HP limit to %d", hplimit);
        m_PlayerDyingHitPointLimit = std::make_unique<PlayerDyingHitPointLimit>(GetServices()->m_hooks.get(), hplimit);
    }

    if (GetServices()->m_config->Get<bool>("DISABLE_PAUSE", false))
    {
        LOG_INFO("Disabling pausing of the server");
        m_DisablePause = std::make_unique<DisablePause>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("DISABLE_QUICKSAVE", false))
    {
        LOG_INFO("Disabling the quicksave option on the server");
        m_DisableQuicksave = std::make_unique<DisableQuicksave>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("COMPARE_VARIABLES_WHEN_MERGING", false))
    {
        LOG_INFO("Will compare local variables when merging item stacks");
        m_CompareVarsForMerge = std::make_unique<CompareVarsForMerge>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("PARRY_ALL_ATTACKS", false))
    {
        LOG_INFO("Parry will no longer be limited to one attack per flurry");
        m_ParryAllAttacks = std::make_unique<ParryAllAttacks>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("SNEAK_ATTACK_IGNORE_CRIT_IMMUNITY", false))
    {
        LOG_INFO("Sneak attacks will now be possible on creatures with immunity to critical hits");
        m_SneakAttackCritImmunity = std::make_unique<SneakAttackCritImmunity>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("PRESERVE_DEPLETED_ITEMS", false))
    {
        LOG_INFO("Items will no longer be destroyed when they run out of charges");
        m_PreserveDepletedItems = std::make_unique<PreserveDepletedItems>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("HIDE_DMS_ON_CHAR_LIST", false))
    {
        LOG_INFO("DMs will not be visible on character list");
        m_HideDMsOnCharList = std::make_unique<HideDMsOnCharList>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("DISABLE_MONK_ABILITIES_WHEN_POLYMORPHED", false))
    {
        LOG_INFO("Monk abilities (ac, speed, attacks) will be disabled during polymorph");
        m_DisableMonkAbilitiesWhenPolymorphed = std::make_unique<DisableMonkAbilitiesWhenPolymorphed>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("STRINGTOINT_BASE_TO_AUTO", false))
    {
        LOG_INFO("Setting StringToInt() base to auto to allow for conversion of hex strings to proper values.");
        m_StringToIntBaseToAuto = std::make_unique<StringToIntBaseToAuto>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("DEAD_CREATURES_TRIGGER_ON_AREA_EXIT", false))
    {
        LOG_INFO("Dead creatures will fire on area exit.");
        m_DeadCreatureFiresOnAreaExit = std::make_unique<DeadCreatureFiresOnAreaExit>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("PRESERVE_ACTIONS_ON_DM_POSSESS", false))
    {
        LOG_INFO("DMs possessing a creature will no longer clear their actions");
        m_PreserveActionsOnDMPossess = std::make_unique<PreserveActionsOnDMPossess>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("FIX_GREATER_SANCTUARY_BUG", false))
    {
        LOG_INFO("Greater sanctuary bug fixed.");
        m_FixGreaterSanctuaryBug = std::make_unique<FixGreaterSanctuaryBug>(GetServices()->m_hooks.get());
    }

    if (auto mode = GetServices()->m_config->Get<int>("ITEM_CHARGES_COST_MODE", 0))
    {
        LOG_INFO("Changing cost for items with charges.");
        m_ItemChargesCost = std::make_unique<ItemChargesCost>(GetServices()->m_hooks.get(),
            mode);
    }

    if (GetServices()->m_config->Get<bool>("FIX_DISPEL_EFFECT_LEVELS", false))
    {
        LOG_INFO("Fixing dispel checks vs. effects created by deleted objects.");
        m_FixDispelEffectLevels = std::make_unique<FixDispelEffectLevels>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("ADD_PRESTIGECLASS_CASTER_LEVELS", false))
    {
        LOG_INFO("Automatically adding prestige class caster levels using (Div|Arc)SpellLvlMod colums in classes.2da");
        m_AddPrestigeclassCasterLevels = std::make_unique<AddPrestigeclassCasterLevels>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("FIX_UNLIMITED_POTIONS_BUG", false))
    {
        LOG_INFO("Fixing unlimited potion/scroll uses bug");
        m_FixUnlimitedPotionsBug = std::make_unique<FixUnlimitedPotionsBug>(GetServices()->m_hooks.get());
    }

    if (GetServices()->m_config->Get<bool>("UNHARDCODE_SHIELDS", false))
    {
        LOG_INFO("Using baseitems.2da to define shield AC and create shield-like items");
        m_UnhardcodeShields = std::make_unique<UnhardcodeShields>(GetServices()->m_hooks.get());
    }
}

Tweaks::~Tweaks()
{
}

}
