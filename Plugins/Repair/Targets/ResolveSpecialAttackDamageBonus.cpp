#include "Targets/ResolveSpecialAttackDamageBonus.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Version.hpp"
#include "Services/Log/Log.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Patching/Patching.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace Repair {

static ViewPtr<Services::MetricsProxy> g_metrics;
static ViewPtr<Services::LogProxy> g_log;

ResolveSpecialAttackDamageBonus::ResolveSpecialAttackDamageBonus(ViewPtr<Services::MetricsProxy> metrics,
    ViewPtr<Services::PatchingProxy> patcher,
    ViewPtr<Services::LogProxy> log)
{
    g_metrics = metrics;
    g_log = log;

    patcher->PatchWithCall(0x08149371, 0x08149376 - 0x08149371, &ResolveSpecialAttackDamageBonusInlineHook); NWNX_EXPECT_VERSION(8109);
    patcher->PatchWithCall(0x081491F1, 0x081491F6 - 0x081491F1, &ResolveSpecialAttackDamageBonusInlineHook); NWNX_EXPECT_VERSION(8109);
}

int32_t ResolveSpecialAttackDamageBonus::ResolveSpecialAttackDamageBonusInlineHook(NWNXLib::API::CNWSCreatureStats* thisPtr)
{
    if (thisPtr)
    {
        return thisPtr->GetSimpleAlignmentGoodEvil();
    }

    g_log->Info("Prevented the ResolveSpecialAttackDamageBonus crash.");
    g_metrics->Push("Crashes", { { "Count", "1" }, { "Type", "ResolveSpecialAttackDamageBonus" } });

    return 1;
}

}
