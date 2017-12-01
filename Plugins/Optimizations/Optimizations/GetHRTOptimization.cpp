#include "Optimizations/GetHRTOptimization.hpp"

#include "API/CExoBase.hpp"
#include "API/CExoTimers.hpp"
#include "API/CExoTimersInternal.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "Services/Patching/Patching.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooking::FunctionHook* g_hrtHook = nullptr;

static uint64_t g_cachedTime = 0;
static uint32_t g_callsSinceLastCached = 0;
static uint32_t g_flushCount = 0;

GetHRTOptimization::GetHRTOptimization(const uint32_t flushCount, ViewPtr<Services::HooksProxy> hooker, ViewPtr<Services::PatchingProxy> patcher)
{
    g_flushCount = flushCount;
    g_callsSinceLastCached = flushCount;

    hooker->RequestSharedHook<Functions::CServerExoAppInternal__MainLoop, int32_t>(&MainLoopUpdate);
    hooker->RequestExclusiveHook<Functions::CExoTimersInternal__GetHighResolutionTimer,uint64_t, CExoTimersInternal*>(&GetHighResolutionTimer);
    g_hrtHook = hooker->FindHookByAddress(Functions::CExoTimersInternal__GetHighResolutionTimer);

    // There are a number of places that deal with intense time-sliced work.
    // With this optimization, they could potentially take flushCount x longer before aborting.
    // We manually patch the most important areas here to trigger a cache reset every time.

    // CNWSArea::PlotPath
    patcher->PatchWithCall(0x080DAF35, 0x080DAF3A - 0x080DAF35, &GetHighResolutionTimerWithCacheReset); NWNX_EXPECT_VERSION(8109);
    patcher->PatchWithCall(0x080DB3AB, 0x080DB3B0 - 0x080DB3AB, &GetHighResolutionTimerWithCacheReset); NWNX_EXPECT_VERSION(8109);
    patcher->PatchWithCall(0x080DB944, 0x080DB949 - 0x080DB944, &GetHighResolutionTimerWithCacheReset); NWNX_EXPECT_VERSION(8109);

    // CNWSArea::PlotGridPath
    patcher->PatchWithCall(0x080DCBF9, 0x080DCBFE - 0x080DCBF9, &GetHighResolutionTimerWithCacheReset); NWNX_EXPECT_VERSION(8109);
    patcher->PatchWithCall(0x080DD145, 0x080DD14A - 0x080DD145, &GetHighResolutionTimerWithCacheReset); NWNX_EXPECT_VERSION(8109);
    patcher->PatchWithCall(0x080DD2FE, 0x080DD303 - 0x080DD2FE, &GetHighResolutionTimerWithCacheReset); NWNX_EXPECT_VERSION(8109);

    // CNWTileSurfaceMesh::PlotIntraTilePath
    patcher->PatchWithCall(0x08092A1F, 0x08092A24 - 0x08092A1F, &GetHighResolutionTimerWithCacheReset); NWNX_EXPECT_VERSION(8109);
    patcher->PatchWithCall(0x08092CD1, 0x08092CD6 - 0x08092CD1, &GetHighResolutionTimerWithCacheReset); NWNX_EXPECT_VERSION(8109);

    // We patch this call, because sometimes, depending on how AI updates lined up, a timer reset would always land on this
    // timer, which incremented the start time, meaning we were stuck in the UpdateState loop forever.
    patcher->PatchWithNoop(0x08096065, 0x0809606B - 0x08096065); NWNX_EXPECT_VERSION(8109);
}

void GetHRTOptimization::MainLoopUpdate(Services::Hooks::CallType type, CServerExoAppInternal*)
{
    if (type != Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        return;
    }

    g_cachedTime = GetHighResolutionTimerWithCacheReset((*Globals::g_pExoBase)->m_pcExoTimers);
}

uint64_t GetHRTOptimization::GetHighResolutionTimer(CExoTimersInternal* thisPtr)
{
    if (g_callsSinceLastCached++ >= g_flushCount)
    {
        g_cachedTime = g_hrtHook->CallOriginal<uint64_t>(thisPtr);
        g_callsSinceLastCached = 0;
    }

    return g_cachedTime;
}

uint64_t GetHRTOptimization::GetHighResolutionTimerWithCacheReset(CExoTimers* thisPtr)
{
    g_callsSinceLastCached = g_flushCount;
    return GetHighResolutionTimer(thisPtr->m_pcExoTimersInternal);
}

}
