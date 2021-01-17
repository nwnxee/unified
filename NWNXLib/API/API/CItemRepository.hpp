#pragma once
#include "nwn_api.hpp"

#include "CExoLinkedList.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CItemRepository)
#endif

struct CExoString;
struct CNWSItem;


typedef int BOOL;
typedef CExoLinkedListNode * CExoLinkedListPosition;
typedef uint32_t OBJECT_ID;


struct CItemRepository
{
    uint8_t m_nWidth;
    uint8_t m_nHeight;
    uint32_t m_nBoundary;
    OBJECT_ID m_oidParent;
    BOOL m_bScalable;
    CExoLinkedList<OBJECT_ID> m_oidItems;

    CItemRepository(OBJECT_ID oidParent, uint8_t nWidth, uint8_t nHeight, uint32_t nBoundary, BOOL bScalable = false);
    ~CItemRepository();
    BOOL AddItem(CNWSItem * * pItem, uint8_t x = 0xff, uint8_t y = 0xff, BOOL bAllowEncumbrance = false, BOOL bMergeItem = true);
    uint8_t CalculatePage(uint8_t x, uint8_t y);
    BOOL CheckFit(CNWSItem * pItem, uint8_t x, uint8_t y);
    BOOL CheckItemOverlaps(CNWSItem * pSourceItem, CNWSItem * pDroppingItem, uint8_t x, uint8_t y);
    OBJECT_ID FindItemWithBaseItemId(uint32_t nBaseItemId, int32_t nTh = 0);
    OBJECT_ID FindItemWithTag(CExoString * pTag);
    BOOL FindPosition(CNWSItem * pItem, uint8_t & x, uint8_t & y, BOOL bOriginatingFromScript = false);
    BOOL AddPanel();
    BOOL RemoveItem(CNWSItem * pItem);
    BOOL MoveItem(CNWSItem * pItem, uint8_t x, uint8_t y);
    BOOL GetItemInRepository(CNWSItem * pItem, BOOL bCheckContainers = false);
    OBJECT_ID GetItemInRepository(uint8_t x, uint8_t y);
    CNWSItem * ItemListGetItem(CExoLinkedListPosition pListPosition);
    OBJECT_ID ItemListGetItemObjectID(CExoLinkedListPosition pListPosition);
    int32_t CalculateContentsWeight();


#ifdef NWN_CLASS_EXTENSION_CItemRepository
    NWN_CLASS_EXTENSION_CItemRepository
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CItemRepository)
#endif

