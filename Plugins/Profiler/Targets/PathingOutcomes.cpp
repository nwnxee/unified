#include "Targets/PathingOutcomes.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSModule.hpp"
#include "API/CPathfindInformation.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/Constants.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/CNWSObject.hpp"

#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

namespace Profiler {

using namespace NWNXLib;
using namespace NWNXLib::API;

// CNWSObject::ACTION_* values returned by the planner.
static constexpr uint32_t ACTION_COMPLETE = 2;
static constexpr uint32_t ACTION_FAILED   = 3;

// A complete path ending further than this beyond the requested range is really partial.
static constexpr float PARTIAL_SLACK = 1.0f;

enum Outcome : uint8_t { OUTCOME_COMPLETE, OUTCOME_PARTIAL, OUTCOME_FAILED };
static const char* const s_outcomeNames[] = { "Complete", "Partial", "Failed" };

static Services::MetricsProxy* g_metrics;
static std::chrono::seconds g_interval;
static std::chrono::steady_clock::time_point g_nextFlush;

// Requests may be left unfinished when their creature is destroyed; past this we drop the bookkeeping.
static constexpr size_t MAX_TRACKED_REQUESTS = 4096;

static CPathfindInformation* g_currentRequest;
static std::unordered_set<CPathfindInformation*> g_noRoute;

static std::unordered_map<uint64_t, uint32_t> g_counts;

// A request is time sliced over several planner calls; only tracked when failed requests are logged.
struct RequestTime { int64_t totalNs = 0; int64_t maxNs = 0; };
static std::unordered_map<CPathfindInformation*, RequestTime> g_times;

// Time spent in the current CNWSModule::PlotPath call, only tracked when slow calls are logged.
static int64_t g_callInterAreaNs;
static int64_t g_callInAreaNs;

static PathingOutcomes::LogSettings g_log;
using LogTimes = std::unordered_map<ObjectID, std::chrono::steady_clock::time_point>;
static LogTimes g_nextLog;
static LogTimes g_nextSlowLog;

static Hooks::Hook s_PlotPathHook;
static Hooks::Hook s_ComputeInterAreaPathHook;
static Hooks::Hook s_PlotPathInAreaHook;
static Hooks::Hook s_GenerateInterTilePathHook;
static Hooks::Hook s_MainLoopHook;

// AI level -1 (default) to 4, stored as 0 to 5.
static uint8_t AILevelBits(int32_t aiLevel)
{
    return uint8_t(std::clamp(aiLevel + 1, 0, 7));
}

static uint64_t MakeKey(ObjectID oidArea, uint8_t aiBits, Outcome outcome, bool bPC, bool bGrid, bool bNoRoute)
{
    return (uint64_t(oidArea) << 8) | (aiBits << 5) | (outcome << 3) | (bPC << 2) | (bGrid << 1) | uint64_t(bNoRoute);
}

static int64_t ElapsedNs(std::chrono::steady_clock::time_point since)
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - since).count();
}

static bool MayLog(LogTimes& times, ObjectID oid)
{
    const auto now = std::chrono::steady_clock::now();
    auto& next = times[oid];
    if (now < next)
        return false;
    next = now + g_log.interval;
    return true;
}

static std::string AreaName(ObjectID oidArea)
{
    if (oidArea == Constants::OBJECT_INVALID || oidArea == 0)
        return "-";

    if (CNWSArea* pArea = Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(oidArea))
    {
        const char* resRef = pArea->m_cResRef.GetResRefStr();
        return std::string(resRef, strnlen(resRef, 16));
    }

    return "(unknown)";
}

static bool IsPC(const CPathfindInformation* pf)
{
    return pf->m_oidSelf != Constants::OBJECT_INVALID &&
        Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(pf->m_oidSelf);
}

static void LogRequest(const CPathfindInformation* pf, CNWSObject* self, const char* what, bool bPC,
                       bool bNoRoute, const RequestTime& t)
{
    if (!MayLog(g_nextLog, pf->m_oidSelf))
        return;

    const std::string area = AreaName(pf->m_oidNewPointStartArea);

    LOG_INFO("Pathing %s: area %s, %s '%s' (%s, %x), AI level %d, from (%.2f, %.2f) to (%.2f, %.2f), range %.2f, "
             "%d calls, %.1f ms (slowest call %.1f ms), grid search %d, no tile route %d",
             what, area.c_str(), bPC ? "PC" : "NPC",
             self ? self->m_sTag.CStr() : "", self ? self->m_sTemplate.CStr() : "", pf->m_oidSelf,
             self ? self->m_nAILevel : -1,
             pf->m_fNewPointStartX, pf->m_fNewPointStartY, pf->m_fNewPointEndX, pf->m_fNewPointEndY,
             pf->m_fPointTolerance, pf->m_nCallsToPlotPath, t.totalNs / 1e6, t.maxNs / 1e6,
             pf->m_bUsePlotGridPath ? 1 : 0, bNoRoute ? 1 : 0);
}

static Outcome ClassifyComplete(const CPathfindInformation* pf)
{
    if (pf->m_nWayPoints < 2 || !pf->m_pfWayPoints)
        return OUTCOME_COMPLETE;

    const float dx = pf->m_pfWayPoints[pf->m_nWayPoints - 2] - pf->m_fNewPointEndX;
    const float dy = pf->m_pfWayPoints[pf->m_nWayPoints - 1] - pf->m_fNewPointEndY;
    const float reach = pf->m_fPointTolerance + PARTIAL_SLACK;

    return dx * dx + dy * dy > reach * reach ? OUTCOME_PARTIAL : OUTCOME_COMPLETE;
}

static const char* ResultName(uint32_t ret)
{
    return ret == ACTION_COMPLETE ? "complete" : ret == ACTION_FAILED ? "failed" : "in progress";
}

// The planner rewrites the start, goal and areas while it works, so the slow-call line keeps them as they entered.
struct EntrySnapshot
{
    ObjectID oidStartArea, oidGoalArea, oidTempGoalArea, oidMovingTo;
    float startX, startY, goalX, goalY, tolerance;
    int32_t calls, interAreas;
    bool bTempPoints, bNewPoints, bResolved, bInProgress;
};

static EntrySnapshot Snapshot(const CPathfindInformation* pf)
{
    return {
        pf->m_oidNewPointStartArea, pf->m_oidNewPointEndArea, pf->m_oidTempPointEndArea, pf->m_oidMovingTo,
        pf->m_fNewPointStartX, pf->m_fNewPointStartY, pf->m_fNewPointEndX, pf->m_fNewPointEndY, pf->m_fPointTolerance,
        pf->m_nCallsToPlotPath, pf->m_nInterAreas,
        pf->m_bTempPoints != 0, pf->m_bNewPoints != 0, pf->m_bInterAreaPathResolved != 0, pf->m_bInterAreaPathInProgress != 0,
    };
}

static std::string MovingToName(ObjectID oid)
{
    if (oid == Constants::OBJECT_INVALID || oid == 0)
        return "-";

    CNWSObject* obj = Utils::AsNWSObject(Utils::GetGameObject(oid));
    if (!obj)
        return "(gone)";

    return std::string("'") + obj->m_sTag.CStr() + "' (" + AreaName(obj->m_oidArea) + ")";
}

static void LogSlowCall(const CPathfindInformation* pf, const EntrySnapshot& in, uint32_t ret, int64_t totalNs)
{
    if (!MayLog(g_nextSlowLog, pf->m_oidSelf))
        return;

    CNWSObject* self = Utils::AsNWSObject(Utils::GetGameObject(pf->m_oidSelf));
    const std::string start = AreaName(pf->m_oidNewPointStartArea);
    const std::string leg = AreaName(pf->m_oidNewPointEndArea);
    const std::string goal = AreaName(pf->m_oidTempPointEndArea);
    const int64_t otherNs = totalNs - g_callInterAreaNs - g_callInAreaNs;

    const std::string inStart = AreaName(in.oidStartArea);
    const std::string inGoal = AreaName(in.oidGoalArea);
    const std::string inTemp = AreaName(in.oidTempGoalArea);
    const std::string movingTo = MovingToName(in.oidMovingTo);
    const std::string creatureArea = self ? AreaName(self->m_oidArea) : "-";

    LOG_INFO("Pathing slow call: %s '%s' (%s, %x), AI level %d, in area %s, "
             "at entry: from (%.2f, %.2f) in %s to (%.2f, %.2f) in %s, temp goal area %s, moving to %s, "
             "range %.2f, route areas %d (resolved %d, in progress %d, new points %d, temp points %d), "
             "after: area %s, leg goal area %s, final goal area %s, route areas %d (resolved %d, in progress %d), "
             "call %d, %s, %.2f ms: inter-area search %.2f, in-area planner %.2f, other %.2f",
             IsPC(pf) ? "PC" : "NPC",
             self ? self->m_sTag.CStr() : "", self ? self->m_sTemplate.CStr() : "", pf->m_oidSelf,
             self ? self->m_nAILevel : -1, creatureArea.c_str(),
             in.startX, in.startY, inStart.c_str(), in.goalX, in.goalY, inGoal.c_str(), inTemp.c_str(), movingTo.c_str(),
             in.tolerance, in.interAreas, in.bResolved ? 1 : 0, in.bInProgress ? 1 : 0, in.bNewPoints ? 1 : 0, in.bTempPoints ? 1 : 0,
             start.c_str(), leg.c_str(), goal.c_str(),
             pf->m_nInterAreas, pf->m_bInterAreaPathResolved ? 1 : 0, pf->m_bInterAreaPathInProgress ? 1 : 0,
             pf->m_nCallsToPlotPath, ResultName(ret), totalNs / 1e6,
             g_callInterAreaNs / 1e6, g_callInAreaNs / 1e6, otherNs / 1e6);
}

// Only hooked when slow calls are logged; times the whole call, which can be slow outside PlotPathInArea.
static uint32_t PlotPathHook(CNWSModule* pThis, CPathfindInformation* pf, uint32_t nTimeSlice)
{
    if (!pf)
        return s_PlotPathHook->CallOriginal<uint32_t>(pThis, pf, nTimeSlice);

    g_callInterAreaNs = 0;
    g_callInAreaNs = 0;
    const EntrySnapshot entry = Snapshot(pf);

    const auto start = std::chrono::steady_clock::now();
    const uint32_t ret = s_PlotPathHook->CallOriginal<uint32_t>(pThis, pf, nTimeSlice);
    const int64_t ns = ElapsedNs(start);

    if (ns >= int64_t(g_log.slowMs) * 1000000)
        LogSlowCall(pf, entry, ret, ns);

    return ret;
}

static int32_t ComputeInterAreaPathHook(CNWSModule* pThis, CPathfindInformation* pf)
{
    const auto start = std::chrono::steady_clock::now();
    const int32_t ret = s_ComputeInterAreaPathHook->CallOriginal<int32_t>(pThis, pf);
    g_callInterAreaNs += ElapsedNs(start);
    return ret;
}

static uint32_t PlotPathInAreaHook(CNWSModule* pThis, CPathfindInformation* pf, uint32_t nTimeSlice)
{
    // The engine counts calls per request from zero, so this is a fresh request (the pointer may be reused).
    if (pf->m_nCallsToPlotPath == 0)
    {
        g_noRoute.erase(pf);
        if (g_log.failed)
            g_times.erase(pf);
    }

    const bool bTime = g_log.failed || g_log.slowMs > 0;
    const auto start = bTime ? std::chrono::steady_clock::now() : std::chrono::steady_clock::time_point{};

    g_currentRequest = pf;
    const uint32_t ret = s_PlotPathInAreaHook->CallOriginal<uint32_t>(pThis, pf, nTimeSlice);
    g_currentRequest = nullptr;

    const int64_t ns = bTime ? ElapsedNs(start) : 0;
    g_callInAreaNs += ns;

    RequestTime* t = nullptr;
    if (g_log.failed)
    {
        t = &g_times[pf];
        t->totalNs += ns;
        t->maxNs = std::max(t->maxNs, ns);
    }

    if (ret != ACTION_COMPLETE && ret != ACTION_FAILED)
        return ret;

    const Outcome outcome = ret == ACTION_FAILED ? OUTCOME_FAILED : ClassifyComplete(pf);
    const bool bPC = IsPC(pf);
    const bool bNoRoute = g_noRoute.erase(pf) > 0;
    CNWSObject* self = Utils::AsNWSObject(Utils::GetGameObject(pf->m_oidSelf));
    const int32_t aiLevel = self ? self->m_nAILevel : -1;

    g_counts[MakeKey(pf->m_oidNewPointStartArea, AILevelBits(aiLevel), outcome, bPC, pf->m_bUsePlotGridPath, bNoRoute)]++;

    if (t)
    {
        const RequestTime time = *t;
        g_times.erase(pf);

        if (outcome == OUTCOME_FAILED && aiLevel >= g_log.failedMinAILevel)
            LogRequest(pf, self, "failed", bPC, bNoRoute, time);
    }

    return ret;
}

static int32_t GenerateInterTilePathHook(CNWSArea* pThis, int32_t* nStartDepth, int32_t nTileX, int32_t nTileY, int32_t nRegion)
{
    const int32_t ret = s_GenerateInterTilePathHook->CallOriginal<int32_t>(pThis, nStartDepth, nTileX, nTileY, nRegion);

    if (ret == 0 && g_currentRequest)
        g_noRoute.insert(g_currentRequest);

    return ret;
}

static void Flush()
{
    CServerExoApp* server = Globals::AppManager()->m_pServerExoApp;

    for (const auto& [key, count] : g_counts)
    {
        const ObjectID oidArea = ObjectID(key >> 8);
        std::string areaName = "(unknown)";

        if (CNWSArea* area = server->GetAreaByGameObjectID(oidArea))
        {
            const char* resRef = area->m_cResRef.GetResRefStr();
            areaName.assign(resRef, strnlen(resRef, 16));
        }

        g_metrics->Push("PathingOutcome",
            { { "Count", std::to_string(count) } },
            {
                { "Area", std::move(areaName) },
                { "AILevel", std::to_string(int((key >> 5) & 0x7) - 1) },
                { "Outcome", s_outcomeNames[(key >> 3) & 0x3] },
                { "Controller", (key & 0x4) ? "PC" : "NPC" },
                { "GridSearch", (key & 0x2) ? "true" : "false" },
                { "NoTileRoute", (key & 0x1) ? "true" : "false" },
            });
    }

    g_counts.clear();

    const auto now = std::chrono::steady_clock::now();
    for (LogTimes* times : { &g_nextLog, &g_nextSlowLog })
        for (auto it = times->begin(); it != times->end();)
            it = it->second <= now ? times->erase(it) : std::next(it);
    if (g_times.size() > MAX_TRACKED_REQUESTS)
        g_times.clear();
    if (g_noRoute.size() > MAX_TRACKED_REQUESTS)
        g_noRoute.clear();
}

static int32_t MainLoopHook(CServerExoAppInternal* pThis)
{
    const auto now = std::chrono::steady_clock::now();

    if (now >= g_nextFlush)
    {
        g_nextFlush = now + g_interval;
        Flush();
    }

    return s_MainLoopHook->CallOriginal<int32_t>(pThis);
}

PathingOutcomes::PathingOutcomes(Services::MetricsProxy* metrics, std::chrono::seconds interval, const LogSettings& log)
{
    g_metrics = metrics;
    g_interval = interval;
    g_log = log;
    g_nextFlush = std::chrono::steady_clock::now() + interval;

    // Earliest, so this sees the final result even if another plugin replaces the planner.
    if (g_log.slowMs > 0)
    {
        s_PlotPathHook = Hooks::HookFunction(&CNWSModule::PlotPath, &PlotPathHook, Hooks::Order::Earliest);
        s_ComputeInterAreaPathHook = Hooks::HookFunction(&CNWSModule::ComputeInterAreaPath, &ComputeInterAreaPathHook, Hooks::Order::Earliest);
    }
    s_PlotPathInAreaHook = Hooks::HookFunction(&CNWSModule::PlotPathInArea, &PlotPathInAreaHook, Hooks::Order::Earliest);
    s_GenerateInterTilePathHook = Hooks::HookFunction(&CNWSArea::GenerateInterTilePath, &GenerateInterTilePathHook, Hooks::Order::Earliest);
    s_MainLoopHook = Hooks::HookFunction(&CServerExoAppInternal::MainLoop, &MainLoopHook, Hooks::Order::Late);
}

}
