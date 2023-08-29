#pragma once
#include "nwn_api.hpp"

#include "CExoLinkedList.hpp"
#include "CNWSPlayerLUOInventoryItem.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlayerLUOInventory)
#endif

class CNWSItem;


typedef CExoLinkedListNode * CExoLinkedListPosition;
typedef uint32_t OBJECT_ID;


class CNWSPlayerLUOInventory
{
public:
    OBJECT_ID m_oidInventorySlots[18];
    int32_t m_nStackSizes[18];
    CExoLinkedList<CNWSPlayerLUOInventoryItem> m_pOldRepositoryItems;
    OBJECT_ID m_oidContainer;
    CExoLinkedList<CNWSPlayerLUOInventoryItem> m_pOldContainerItems;
    uint8_t m_nOldContainerNumPages;
    CExoLinkedList<CNWSPlayerLUOInventoryItem> m_pOldBarterItems;
    CExoLinkedList<CNWSPlayerLUOInventoryItem> m_pOldStoreItems;
    uint8_t m_nOldStoreNumPages;
    uint8_t m_nOldStoreCurrentPanel;

    CNWSPlayerLUOInventory();
    ~CNWSPlayerLUOInventory();
    void ClearSlots();
    void ClearRepository();
    void ClearContainer();
    void ClearBarter();
    void ClearStore();
    void ItemListSetStart(CExoLinkedListPosition & pListPosition, uint8_t nItemList);
    void ItemListSetEnd(CExoLinkedListPosition & pListPosition, uint8_t nItemList);
    CNWSItem * ItemListGetItem(CExoLinkedListPosition pListPosition, uint8_t nItemList);
    OBJECT_ID ItemListGetItemObjectID(CExoLinkedListPosition pListPosition, uint8_t nItemList);
    CNWSPlayerLUOInventoryItem * ItemListGetUpdateItem(CExoLinkedListPosition pListPosition, uint8_t nItemList);
    void ItemListGetNext(CExoLinkedListPosition & pListPosition, uint8_t nItemList);
    void ItemListGetPrev(CExoLinkedListPosition & pListPosition, uint8_t nItemList);
    void ItemListRemove(CExoLinkedListPosition pListPosition, uint8_t nItemList);
    void ItemListAddHead(OBJECT_ID nID, uint8_t nItemList, uint8_t xPos, uint8_t yPos, uint32_t nStackSize, uint32_t nCost);
    uint32_t ItemListGetNumber(uint8_t nItemList);


#ifdef NWN_CLASS_EXTENSION_CNWSPlayerLUOInventory
    NWN_CLASS_EXTENSION_CNWSPlayerLUOInventory
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlayerLUOInventory)
#endif

