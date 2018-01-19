#pragma once

#include <cstdint>

#include "CExoLinkedListTemplatedlongunsignedint.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListNode;
struct CExoString;
struct CNWSItem;

struct CItemRepository
{
    uint8_t m_nWidth;
    uint8_t m_nHeight;
    uint32_t m_nBoundary;
    uint32_t m_oidParent;
    int32_t m_bScalable;
    CExoLinkedListTemplatedlongunsignedint m_oidItems;

    // The below are auto generated stubs.
    CItemRepository() = default;
    CItemRepository(const CItemRepository&) = default;
    CItemRepository& operator=(const CItemRepository&) = default;

    CItemRepository(uint32_t, unsigned char, unsigned char, uint32_t, int32_t);
    ~CItemRepository();
    int32_t AddItem(CNWSItem**, unsigned char, unsigned char, int32_t, int32_t);
    int32_t AddPanel();
    int32_t CalculateContentsWeight();
    unsigned char CalculatePage(unsigned char, unsigned char);
    int32_t CheckFit(CNWSItem*, unsigned char, unsigned char);
    int32_t CheckItemOverlaps(CNWSItem*, CNWSItem*, unsigned char, unsigned char);
    uint32_t FindItemWithBaseItemId(uint32_t, int32_t);
    uint32_t FindItemWithTag(CExoString*);
    int32_t FindPosition(CNWSItem*, unsigned char&, unsigned char&, int32_t);
    int32_t GetItemInRepository(CNWSItem*, int32_t);
    uint32_t GetItemInRepository(unsigned char, unsigned char);
    CNWSItem* ItemListGetItem(CExoLinkedListNode*);
    uint32_t ItemListGetItemObjectID(CExoLinkedListNode*);
    int32_t MoveItem(CNWSItem*, unsigned char, unsigned char);
    int32_t RemoveItem(CNWSItem*);
};

void CItemRepository__CItemRepositoryCtor__0(CItemRepository* thisPtr, uint32_t, unsigned char, unsigned char, uint32_t, int32_t);
void CItemRepository__CItemRepositoryDtor__0(CItemRepository* thisPtr);
int32_t CItemRepository__AddItem(CItemRepository* thisPtr, CNWSItem**, unsigned char, unsigned char, int32_t, int32_t);
int32_t CItemRepository__AddPanel(CItemRepository* thisPtr);
int32_t CItemRepository__CalculateContentsWeight(CItemRepository* thisPtr);
unsigned char CItemRepository__CalculatePage(CItemRepository* thisPtr, unsigned char, unsigned char);
int32_t CItemRepository__CheckFit(CItemRepository* thisPtr, CNWSItem*, unsigned char, unsigned char);
int32_t CItemRepository__CheckItemOverlaps(CItemRepository* thisPtr, CNWSItem*, CNWSItem*, unsigned char, unsigned char);
uint32_t CItemRepository__FindItemWithBaseItemId(CItemRepository* thisPtr, uint32_t, int32_t);
uint32_t CItemRepository__FindItemWithTag(CItemRepository* thisPtr, CExoString*);
int32_t CItemRepository__FindPosition(CItemRepository* thisPtr, CNWSItem*, unsigned char&, unsigned char&, int32_t);
int32_t CItemRepository__GetItemInRepository__0(CItemRepository* thisPtr, CNWSItem*, int32_t);
uint32_t CItemRepository__GetItemInRepository__1(CItemRepository* thisPtr, unsigned char, unsigned char);
CNWSItem* CItemRepository__ItemListGetItem(CItemRepository* thisPtr, CExoLinkedListNode*);
uint32_t CItemRepository__ItemListGetItemObjectID(CItemRepository* thisPtr, CExoLinkedListNode*);
int32_t CItemRepository__MoveItem(CItemRepository* thisPtr, CNWSItem*, unsigned char, unsigned char);
int32_t CItemRepository__RemoveItem(CItemRepository* thisPtr, CNWSItem*);

}

}
