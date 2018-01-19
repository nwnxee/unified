#include "CExoLinkedListTemplatedCNWSPlayerLUOInventoryItem.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

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
