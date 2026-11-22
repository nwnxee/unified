//
// This fixes a heap overflow in the grid pathfinder (CNWSArea::PlotGridPath).
//
// The grid search marks every point it visits in CPathfindInformation::m_bGridPointsSearchedArray,
// a byte array PlotGridPath allocates for a grid of (2 * offset + 1) columns, and that many rows
// plus the mover's distance from its destination in grid steps. SetGridPointSearched and
// GetGridPointSearched index it as (x + offsetX) + (y + offsetY) * columns, and check nothing.
//
// Single steps stay inside that grid by the search's own step limit. A jump does not:
// CNWSArea::GridSearchPathInDirection aims it at the point m_nGridStepTolerance steps from the
// destination, on the mover's side. When the tolerance is larger than the mover's distance that
// point lies behind the mover, and past the last row once the difference exceeds the grid's
// margin (the offset). Its mark then lands outside the array: one byte, up to kilobytes past the
// end or before the start, in whatever the heap holds there. The server dies later, elsewhere.
//
// It takes a move whose range is larger than the horizontal distance left and that the engine
// still makes, because the full distance is out of range: a spell cast at a location well below
// or above the caster. Seen on 2026-11-11: a short range ability used on a spot 3.6 m away and
// 15 m down - tolerance 88 steps, distance 36, a jump to row 87 of a grid that ends at row 80,
// marked 578 bytes past the array, in the size field of the next heap chunk.
//
// This keeps both functions inside the array. A point outside the grid is never marked, and it
// reads as already searched, so the search does not walk on from it. Nothing changes for a point
// inside the grid.
//
// Pathfinding runs on the main thread only, so the log limiter needs no locking.
//

#include "nwnx.hpp"

#include <chrono>

#include "API/CPathfindInformation.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_SetGridPointSearchedHook;
static Hooks::Hook s_GetGridPointSearchedHook;

// A mover that keeps asking for such a path must not flood the log: at most LogBurst warnings
// a minute; the rest are counted, and the count is logged with the next one after the minute.
static constexpr int LogBurst = 10;
static std::chrono::steady_clock::time_point s_logWindowStart;
static int s_logged = 0;
static int s_suppressed = 0;

// Whether the point is in the grid the array was allocated for. PlotGridPath sets the offsets
// and the target step distance when it allocates the array, and nothing changes them after.
static bool IsInGrid(const CPathfindInformation* pInfo, int32_t nX, int32_t nY)
{
    const int64_t columns = 2 * static_cast<int64_t>(pInfo->m_nGridPointsSearchedOffsetX) + 1;
    const int64_t rows = columns + pInfo->m_nGridSearchTargetStepDistance;
    const int64_t column = static_cast<int64_t>(nX) + pInfo->m_nGridPointsSearchedOffsetX;
    const int64_t row = static_cast<int64_t>(nY) + pInfo->m_nGridPointsSearchedOffsetY;
    return column >= 0 && column < columns && row >= 0 && row < rows;
}

static void LogSkippedMark(const CPathfindInformation* pInfo, int32_t nX, int32_t nY)
{
    const auto now = std::chrono::steady_clock::now();
    if (now - s_logWindowStart >= std::chrono::minutes(1))
    {
        if (s_suppressed > 0)
            LOG_WARNING("Skipped %d more such grid search marks after the last one logged, without logging them.", s_suppressed);
        s_logWindowStart = now;
        s_logged = 0;
        s_suppressed = 0;
    }

    if (s_logged >= LogBurst)
    {
        ++s_suppressed;
        return;
    }

    ++s_logged;
    const int32_t columns = 2 * pInfo->m_nGridPointsSearchedOffsetX + 1;
    LOG_WARNING("Skipped a grid search mark that would have been written outside its array: point (%d, %d), grid of %d columns x %d rows with offsets (%d, %d). Object %x moving to within %d steps of a point %d steps away.",
        nX, nY,
        columns, columns + pInfo->m_nGridSearchTargetStepDistance,
        pInfo->m_nGridPointsSearchedOffsetX, pInfo->m_nGridPointsSearchedOffsetY,
        pInfo->m_oidSelf,
        pInfo->m_nGridStepTolerance,
        pInfo->m_nGridSearchTargetStepDistance);
}

static void SetGridPointSearchedHook(CPathfindInformation* pThis, int32_t nX, int32_t nY, bool bSet)
{
    if (pThis->m_bGridPointsSearchedArray && !IsInGrid(pThis, nX, nY))
    {
        LogSkippedMark(pThis, nX, nY);
        return;
    }

    s_SetGridPointSearchedHook->CallOriginal<void>(pThis, nX, nY, bSet);
}

static bool GetGridPointSearchedHook(CPathfindInformation* pThis, int32_t nX, int32_t nY)
{
    if (pThis->m_bGridPointsSearchedArray && !IsInGrid(pThis, nX, nY))
        return true;

    return s_GetGridPointSearchedHook->CallOriginal<bool>(pThis, nX, nY);
}

void FixGridSearchOutOfBounds() __attribute__((constructor));
void FixGridSearchOutOfBounds()
{
    if (!Config::Get<bool>("FIX_GRID_SEARCH_OUT_OF_BOUNDS", false))
        return;

    LOG_INFO("The grid pathfinder will not mark a searched point outside its array.");

    s_SetGridPointSearchedHook = Hooks::HookFunction(&CPathfindInformation::SetGridPointSearched,
        &SetGridPointSearchedHook, Hooks::Order::Earliest);
    s_GetGridPointSearchedHook = Hooks::HookFunction(&CPathfindInformation::GetGridPointSearched,
        &GetGridPointSearchedHook, Hooks::Order::Earliest);
}

}
