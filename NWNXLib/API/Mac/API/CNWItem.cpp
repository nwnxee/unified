#include "CNWItem.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWItem::CNWItem()
{
    CNWItem__CNWItemCtor__0(this);
}

CNWItem::~CNWItem()
{
    CNWItem__CNWItemDtor__0(this);
}

unsigned char CNWItem::GetLayeredTextureColorPerPart(unsigned char a0, unsigned char a1)
{
    return CNWItem__GetLayeredTextureColorPerPart(this, a0, a1);
}

void CNWItem::SetLayeredTextureColorPerPart(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWItem__SetLayeredTextureColorPerPart(this, a0, a1, a2);
}

void CNWItem__CNWItemCtor__0(CNWItem* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWItem__CNWItemCtor__0);
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

unsigned char CNWItem__GetLayeredTextureColorPerPart(CNWItem* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWItem*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWItem__GetLayeredTextureColorPerPart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWItem__SetLayeredTextureColorPerPart(CNWItem* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWItem*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWItem__SetLayeredTextureColorPerPart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

}

}
