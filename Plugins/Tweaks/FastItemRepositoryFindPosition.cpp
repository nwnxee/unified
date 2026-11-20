#include "nwnx.hpp"

#include "API/CItemRepository.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWRules.hpp"

#include <vector>

// FindPosition tries every cell and CheckFit walks every item for each, which is quadratic in the number of items.
// This marks the occupied cells once and scans for the first free one in the same order as the original.

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_FindPositionHook;

static int32_t FindPositionHook(CItemRepository*, CNWSItem*, uint8_t*, uint8_t*, int32_t);

void FastItemRepositoryFindPosition() __attribute__((constructor));
void FastItemRepositoryFindPosition()
{
    if (!Config::Get<bool>("FAST_ITEM_REPOSITORY_FIND_POSITION", false))
        return;

    LOG_INFO("Finding a free spot in an item repository is linear in the number of items instead of quadratic.");

    s_FindPositionHook = Hooks::HookFunction(&CItemRepository::FindPosition, &FindPositionHook, Hooks::Order::Final);
}

// x and y are references in the game's function, i.e. pointers in the ABI.
static int32_t FindPositionHook(CItemRepository *pRepo, CNWSItem *pItem, uint8_t *pX, uint8_t *pY, int32_t bFromScript)
{
    auto *pBaseItems = Globals::Rules()->m_pBaseItemArray;
    auto *pBase = pItem && pBaseItems ? pBaseItems->GetBaseItem(pItem->m_nBaseItem) : nullptr;

    // Anything we don't handle, including a full repository and its Lost Items handling, is left to the original.
    if (bFromScript || !pBase || !pRepo->m_nWidth || !pRepo->m_nHeight)
        return s_FindPositionHook->CallOriginal<int32_t>(pRepo, pItem, pX, pY, bFromScript);

    const int nWidth = pRepo->m_nWidth;
    const int nHeight = pRepo->m_nHeight;
    const int nItemW = pBase->m_nInvSlotWidth;
    const int nItemH = pBase->m_nInvSlotHeight;
    const int nRowsPerPage = (pRepo->m_nBoundary / nWidth) & 0xff;

    std::vector<uint8_t> taken(static_cast<size_t>(nWidth) * nHeight, 0);
    for (auto *pNode = pRepo->m_oidItems.m_pcExoLinkedListInternal->pHead; pNode; pNode = pNode->pNext)
    {
        auto *pOther = pRepo->ItemListGetItem(pNode);
        if (!pOther || pOther->m_idSelf == pItem->m_idSelf)
            continue;
        auto *pOtherBase = pBaseItems->GetBaseItem(pOther->m_nBaseItem);
        if (!pOtherBase)
            continue;
        const int x0 = pOther->m_nRepositoryPositionX;
        const int y0 = pOther->m_nRepositoryPositionY;
        for (int cy = y0; cy < y0 + pOtherBase->m_nInvSlotHeight && cy < nHeight; cy++)
            for (int cx = x0; cx < x0 + pOtherBase->m_nInvSlotWidth && cx < nWidth; cx++)
                taken[static_cast<size_t>(cy) * nWidth + cx] = 1;
    }

    for (int cy = 0; cy <= nHeight - nItemH; cy++)
    {
        for (int cx = 0; cx <= nWidth - nItemW; cx++)
        {
            // The item must not straddle two pages.
            if (cy + nItemH > (pRepo->CalculatePage(cx, cy) + 1) * nRowsPerPage)
                continue;

            bool bFree = true;
            for (int iy = cy; bFree && iy < cy + nItemH; iy++)
                for (int ix = cx; ix < cx + nItemW; ix++)
                    if (taken[static_cast<size_t>(iy) * nWidth + ix]) { bFree = false; break; }

            if (bFree)
            {
                *pX = cx;
                *pY = cy;
                return true;
            }
        }
    }

    return s_FindPositionHook->CallOriginal<int32_t>(pRepo, pItem, pX, pY, bFromScript);
}

}
