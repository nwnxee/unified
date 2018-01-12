#pragma once

#include <cstdint>

#include "CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListNode;
struct CNWSItem;
struct CNWSPlayerLUOInventoryItem;

struct CNWSPlayerLUOInventory
{
    uint32_t m_oidInventorySlots[18];
    int32_t m_nStackSizes[18];
    CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem m_pOldRepositoryItems;
    uint32_t m_oidContainer;
    CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem m_pOldContainerItems;
    uint8_t m_nOldContainerNumPages;
    CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem m_pOldBarterItems;
    CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem m_pOldStoreItems;
    uint8_t m_nOldStoreNumPages;
    uint8_t m_nOldStoreCurrentPanel;

    // The below are auto generated stubs.
    CNWSPlayerLUOInventory(const CNWSPlayerLUOInventory&) = default;
    CNWSPlayerLUOInventory& operator=(const CNWSPlayerLUOInventory&) = default;

    CNWSPlayerLUOInventory();
    ~CNWSPlayerLUOInventory();
    void ClearBarter();
    void ClearContainer();
    void ClearRepository();
    void ClearSlots();
    void ClearStore();
    void ItemListAddHead(uint32_t, unsigned char, unsigned char, unsigned char, uint32_t, uint32_t);
    CNWSItem* ItemListGetItem(CExoLinkedListNode*, unsigned char);
    uint32_t ItemListGetItemObjectID(CExoLinkedListNode*, unsigned char);
    void ItemListGetNext(CExoLinkedListNode*, unsigned char);
    uint32_t ItemListGetNumber(unsigned char);
    void ItemListGetPrev(CExoLinkedListNode*, unsigned char);
    CNWSPlayerLUOInventoryItem* ItemListGetUpdateItem(CExoLinkedListNode*, unsigned char);
    void ItemListRemove(CExoLinkedListNode*, unsigned char);
    void ItemListSetEnd(CExoLinkedListNode*, unsigned char);
    void ItemListSetStart(CExoLinkedListNode*, unsigned char);
};

void CNWSPlayerLUOInventory__CNWSPlayerLUOInventoryCtor__0(CNWSPlayerLUOInventory* thisPtr);
void CNWSPlayerLUOInventory__CNWSPlayerLUOInventoryDtor__0(CNWSPlayerLUOInventory* thisPtr);
void CNWSPlayerLUOInventory__ClearBarter(CNWSPlayerLUOInventory* thisPtr);
void CNWSPlayerLUOInventory__ClearContainer(CNWSPlayerLUOInventory* thisPtr);
void CNWSPlayerLUOInventory__ClearRepository(CNWSPlayerLUOInventory* thisPtr);
void CNWSPlayerLUOInventory__ClearSlots(CNWSPlayerLUOInventory* thisPtr);
void CNWSPlayerLUOInventory__ClearStore(CNWSPlayerLUOInventory* thisPtr);
void CNWSPlayerLUOInventory__ItemListAddHead(CNWSPlayerLUOInventory* thisPtr, uint32_t, unsigned char, unsigned char, unsigned char, uint32_t, uint32_t);
CNWSItem* CNWSPlayerLUOInventory__ItemListGetItem(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode*, unsigned char);
uint32_t CNWSPlayerLUOInventory__ItemListGetItemObjectID(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode*, unsigned char);
void CNWSPlayerLUOInventory__ItemListGetNext(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode*, unsigned char);
uint32_t CNWSPlayerLUOInventory__ItemListGetNumber(CNWSPlayerLUOInventory* thisPtr, unsigned char);
void CNWSPlayerLUOInventory__ItemListGetPrev(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode*, unsigned char);
CNWSPlayerLUOInventoryItem* CNWSPlayerLUOInventory__ItemListGetUpdateItem(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode*, unsigned char);
void CNWSPlayerLUOInventory__ItemListRemove(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode*, unsigned char);
void CNWSPlayerLUOInventory__ItemListSetEnd(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode*, unsigned char);
void CNWSPlayerLUOInventory__ItemListSetStart(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode*, unsigned char);

}

}
