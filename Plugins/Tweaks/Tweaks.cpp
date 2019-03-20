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

#include "Services/Config/Config.hpp"

#include "API/Version.hpp"
#include "Platform/Assembly.hpp"
#include "Services/Patching/Patching.hpp"

using namespace NWNXLib;

static ViewPtr<Tweaks::Tweaks> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Tweaks",
        "Tweaks the behaviour of NWN.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Tweaks::Tweaks(params);
    return g_plugin;
}

namespace Tweaks {

Tweaks::Tweaks(const Plugin::CreateParams& params)
    : Plugin(params)
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

    if (GetServices()->m_config->Get<bool>("DISABLE_SHADOWS", false))
    {
        LOG_INFO("Sun and moon shadows will be disabled");

        // Temporary workaround for Intel crash in complex areas - disable when a proper fix is implemented.
        // PackAreaIntoMessage

        // m_bMoonShadows
        GetServices()->m_patching->PatchWithInstructions(0x0012EB0C,
            Platform::Assembly::PushImmInstruction(0),
            Platform::Assembly::NoopInstruction(),
            Platform::Assembly::NoopInstruction(),
            Platform::Assembly::NoopInstruction(),
            Platform::Assembly::NoopInstruction()
        ); NWNX_EXPECT_VERSION(8186);

        // m_bSunShadows
        GetServices()->m_patching->PatchWithInstructions(0x0012EB94,
            Platform::Assembly::PushImmInstruction(0),
            Platform::Assembly::NoopInstruction()
        ); NWNX_EXPECT_VERSION(8186);
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
}

Tweaks::~Tweaks()
{
}

}
