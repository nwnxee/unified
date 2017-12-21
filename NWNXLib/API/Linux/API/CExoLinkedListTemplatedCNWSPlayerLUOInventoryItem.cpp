#include "CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem()
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem(const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem&)
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem& CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::operator=(const CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem&)
{
    return *this; // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem::~CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem()
{
    CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__CExoLinkedListTemplatedCNWSPlayerLUOInventoryItemDtor(this);
}

void CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__CExoLinkedListTemplatedCNWSPlayerLUOInventoryItemDtor(CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem__CExoLinkedListTemplatedCNWSPlayerLUOInventoryItemDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
