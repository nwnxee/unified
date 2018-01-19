#include "CObjectLookupTable.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CObjectLookupTable::CObjectLookupTable()
{
    CObjectLookupTable__CObjectLookupTableCtor(this);
}

CObjectLookupTable::~CObjectLookupTable()
{
    CObjectLookupTable__CObjectLookupTableDtor(this);
}

uint32_t CObjectLookupTable::AddID(uint32_t a0)
{
    return CObjectLookupTable__AddID(this, a0);
}

uint32_t CObjectLookupTable::GetIDFromIndex(uint32_t a0)
{
    return CObjectLookupTable__GetIDFromIndex(this, a0);
}

uint32_t CObjectLookupTable::GetIndexFromID(uint32_t a0)
{
    return CObjectLookupTable__GetIndexFromID(this, a0);
}

void CObjectLookupTable::GetUpdate(void* a0, uint32_t* a1)
{
    return CObjectLookupTable__GetUpdate(this, a0, a1);
}

void CObjectLookupTable::Touch(uint32_t a0)
{
    return CObjectLookupTable__Touch(this, a0);
}

void CObjectLookupTable::Update(void* a0, uint32_t a1)
{
    return CObjectLookupTable__Update(this, a0, a1);
}

void CObjectLookupTable__CObjectLookupTableCtor(CObjectLookupTable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CObjectLookupTable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectLookupTable__CObjectLookupTableCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CObjectLookupTable__CObjectLookupTableDtor(CObjectLookupTable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CObjectLookupTable*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectLookupTable__CObjectLookupTableDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

uint32_t CObjectLookupTable__AddID(CObjectLookupTable* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CObjectLookupTable*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectLookupTable__AddID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CObjectLookupTable__GetIDFromIndex(CObjectLookupTable* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CObjectLookupTable*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectLookupTable__GetIDFromIndex);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CObjectLookupTable__GetIndexFromID(CObjectLookupTable* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CObjectLookupTable*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectLookupTable__GetIndexFromID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CObjectLookupTable__GetUpdate(CObjectLookupTable* thisPtr, void* a0, uint32_t* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CObjectLookupTable*, void*, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectLookupTable__GetUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CObjectLookupTable__Touch(CObjectLookupTable* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CObjectLookupTable*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectLookupTable__Touch);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CObjectLookupTable__Update(CObjectLookupTable* thisPtr, void* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CObjectLookupTable*, void*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectLookupTable__Update);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
