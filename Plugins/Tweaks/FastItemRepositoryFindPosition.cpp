#include "nwnx.hpp"

#include "API/CItemRepository.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWRules.hpp"
#include "API/CExoLinkedList.hpp"

#include <vector>

// CItemRepository::FindPosition looks for the first free spot by trying every cell in turn, and for
// each cell CheckFit walks every item in the repository. That is roughly (cells tried) x (items) per
// placement, so it grows with the square of the number of items: adding to a store with 300 items
// is about ten times slower than to one with 100. It matters most for stores (the whole stock sits
// in at most five panels) and for big containers filled in a loop.
//
// This tweak marks the cells the other items cover once, then scans the cells for the first one the
// item fits on, in the same order as the original (rows, then columns). A page is a band of rows
// and an item may not straddle two of them, as in CheckFit. If nothing fits, or the call came from a
// script (bOriginatingFromScript), the original runs, which also does its failure handling.
//
// NWNX_TWEAKS_FAST_ITEM_REPOSITORY_FIND_POSITION_VERIFY=true also runs the original on every hit and
// logs an error when it disagrees. It is a test aid and gives back the slowdown.

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_FindPositionHook;
static bool s_bVerify;

static int32_t FindPositionHook(CItemRepository*, CNWSItem*, uint8_t*, uint8_t*, int32_t);

void FastItemRepositoryFindPosition() __attribute__((constructor));
void FastItemRepositoryFindPosition()
{
    if (!Config::Get<bool>("FAST_ITEM_REPOSITORY_FIND_POSITION", false))
        return;

    LOG_INFO("Finding a free spot in an item repository is linear in the number of items instead of quadratic.");
    s_bVerify = Config::Get<bool>("FAST_ITEM_REPOSITORY_FIND_POSITION_VERIFY", false);
    if (s_bVerify)
        LOG_INFO("Every found position is checked against the original.");

    s_FindPositionHook = Hooks::HookFunction(&CItemRepository::FindPosition, &FindPositionHook, Hooks::Order::Final);
}

// The coordinates are references in the game's function, which is a pointer at the ABI level, so
// the hook takes and passes them as pointers.
static int32_t FindPositionHook(CItemRepository *pRepo, CNWSItem *pItem, uint8_t *pX, uint8_t *pY, int32_t bFromScript)
{
    auto CallOriginal = [&](uint8_t *pOutX, uint8_t *pOutY) {
        return s_FindPositionHook->CallOriginal<int32_t>(pRepo, pItem, pOutX, pOutY, bFromScript);
    };

    auto *pBaseItems = Globals::Rules()->m_pBaseItemArray;
    auto *pBase = pItem && pBaseItems ? pBaseItems->GetBaseItem(pItem->m_nBaseItem) : nullptr;
    if (bFromScript || !pBase || !pRepo->m_nWidth || !pRepo->m_nHeight)
        return CallOriginal(pX, pY);

    const int nWidth = pRepo->m_nWidth;
    const int nHeight = pRepo->m_nHeight;
    const int nItemW = pBase->m_nInvSlotWidth;
    const int nItemH = pBase->m_nInvSlotHeight;
    const int nRowsPerPage = (pRepo->m_nBoundary / nWidth) & 0xff;

    // The cells the other items cover.
    std::vector<uint8_t> taken(static_cast<size_t>(nWidth) * nHeight, 0);
    for (auto *pNode = pRepo->m_oidItems.m_pcExoLinkedListInternal->pHead; pNode; pNode = pNode->pNext)
    {
        auto *pOther = pRepo->ItemListGetItem(pNode);
        if (!pOther || pOther == pItem || pOther->m_idSelf == pItem->m_idSelf)
            continue;
        auto *pOtherBase = pBaseItems->GetBaseItem(pOther->m_nBaseItem);
        if (!pOtherBase)
            continue;
        const int x0 = pOther->m_nRepositoryPositionX, y0 = pOther->m_nRepositoryPositionY;
        for (int cy = y0; cy < y0 + pOtherBase->m_nInvSlotHeight && cy < nHeight; cy++)
            for (int cx = x0; cx < x0 + pOtherBase->m_nInvSlotWidth && cx < nWidth; cx++)
                taken[static_cast<size_t>(cy) * nWidth + cx] = 1;
    }

    for (int cy = 0; cy <= nHeight - nItemH; cy++)
    {
        for (int cx = 0; cx <= nWidth - nItemW; cx++)
        {
            // Inside the width, and inside the page the top row is on.
            if (cx + nItemW > nWidth)
                continue;
            const int nPage = pRepo->CalculatePage(cx, cy);
            if (cy + nItemH > (nPage + 1) * nRowsPerPage)
                continue;

            bool bFree = true;
            for (int iy = cy; bFree && iy < cy + nItemH; iy++)
                for (int ix = cx; ix < cx + nItemW; ix++)
                    if (taken[static_cast<size_t>(iy) * nWidth + ix]) { bFree = false; break; }
            if (!bFree)
                continue;

            if (s_bVerify)
            {
                uint8_t ox = 0, oy = 0;
                if (!CallOriginal(&ox, &oy) || ox != cx || oy != cy)
                    LOG_ERROR("FindPosition: fast path chose (%d,%d), original chose (%d,%d)", cx, cy, ox, oy);
            }
            *pX = static_cast<uint8_t>(cx);
            *pY = static_cast<uint8_t>(cy);
            return true;
        }
    }

    return CallOriginal(pX, pY);
}

}
