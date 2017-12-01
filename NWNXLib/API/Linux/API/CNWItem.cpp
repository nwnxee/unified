#include "CNWItem.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWItem::CNWItem(const CNWItem&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CNWItem& CNWItem::operator=(const CNWItem&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CNWItem::CNWItem()
{
    CNWItem__CNWItemCtor(this);
}

CNWItem::~CNWItem()
{
    CNWItem__CNWItemDtor__0(this);
}

void CNWItem__CNWItemCtor(CNWItem* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWItem__CNWItemCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWItem__CNWItemDtor__0(CNWItem* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWItem*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWItem__CNWItemDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
