#include "CNWBaseItem.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWBaseItem::CNWBaseItem()
{
    CNWBaseItem__CNWBaseItemCtor(this);
}

CNWBaseItem::~CNWBaseItem()
{
    CNWBaseItem__CNWBaseItemDtor(this);
}

CResRef CNWBaseItem::GetIconResRef(unsigned char a0, int16_t a1, char a2)
{
    return CNWBaseItem__GetIconResRef(this, a0, a1, a2);
}

CResRef CNWBaseItem::GetModelResRef(unsigned char a0, int16_t a1, char a2)
{
    return CNWBaseItem__GetModelResRef(this, a0, a1, a2);
}

CExoString CNWBaseItem::GetNameText()
{
    return CNWBaseItem__GetNameText(this);
}

uint16_t CNWBaseItem::GetRequiredFeat(unsigned char a0)
{
    return CNWBaseItem__GetRequiredFeat(this, a0);
}

void CNWBaseItem::SetRequiredFeat(unsigned char a0, uint16_t a1)
{
    return CNWBaseItem__SetRequiredFeat(this, a0, a1);
}

void CNWBaseItem::SetRequiredFeatCount(unsigned char a0)
{
    return CNWBaseItem__SetRequiredFeatCount(this, a0);
}

void CNWBaseItem__CNWBaseItemCtor(CNWBaseItem* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWBaseItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWBaseItem__CNWBaseItemCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWBaseItem__CNWBaseItemDtor(CNWBaseItem* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWBaseItem*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWBaseItem__CNWBaseItemDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CResRef CNWBaseItem__GetIconResRef(CNWBaseItem* thisPtr, unsigned char a0, int16_t a1, char a2)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWBaseItem*, unsigned char, int16_t, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWBaseItem__GetIconResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CResRef CNWBaseItem__GetModelResRef(CNWBaseItem* thisPtr, unsigned char a0, int16_t a1, char a2)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWBaseItem*, unsigned char, int16_t, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWBaseItem__GetModelResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CExoString CNWBaseItem__GetNameText(CNWBaseItem* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWBaseItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWBaseItem__GetNameText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint16_t CNWBaseItem__GetRequiredFeat(CNWBaseItem* thisPtr, unsigned char a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWBaseItem*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWBaseItem__GetRequiredFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWBaseItem__SetRequiredFeat(CNWBaseItem* thisPtr, unsigned char a0, uint16_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWBaseItem*, unsigned char, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWBaseItem__SetRequiredFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWBaseItem__SetRequiredFeatCount(CNWBaseItem* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWBaseItem*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWBaseItem__SetRequiredFeatCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
