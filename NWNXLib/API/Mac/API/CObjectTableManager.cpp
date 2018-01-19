#include "CObjectTableManager.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CObjectLookupTable.hpp"

namespace NWNXLib {

namespace API {

CObjectTableManager::CObjectTableManager()
{
    CObjectTableManager__CObjectTableManagerCtor__0(this);
}

CObjectTableManager::~CObjectTableManager()
{
    CObjectTableManager__CObjectTableManagerDtor__0(this);
}

int32_t CObjectTableManager::AddID(uint32_t a0, uint32_t* a1, uint32_t a2)
{
    return CObjectTableManager__AddID(this, a0, a1, a2);
}

void CObjectTableManager::ClearAll()
{
    return CObjectTableManager__ClearAll(this);
}

int32_t CObjectTableManager::CreateNewPlayer(uint32_t a0)
{
    return CObjectTableManager__CreateNewPlayer(this, a0);
}

uint32_t CObjectTableManager::GetIDFromIndex(uint32_t a0, uint32_t a1)
{
    return CObjectTableManager__GetIDFromIndex(this, a0, a1);
}

uint32_t CObjectTableManager::GetIndexFromID(uint32_t a0, uint32_t a1)
{
    return CObjectTableManager__GetIndexFromID(this, a0, a1);
}

int32_t CObjectTableManager::RemovePlayer(uint32_t a0)
{
    return CObjectTableManager__RemovePlayer(this, a0);
}

int32_t CObjectTableManager::Touch(uint32_t a0, uint32_t a1)
{
    return CObjectTableManager__Touch(this, a0, a1);
}

void CObjectTableManager__CObjectTableManagerCtor__0(CObjectTableManager* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CObjectTableManager*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectTableManager__CObjectTableManagerCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CObjectTableManager__CObjectTableManagerDtor__0(CObjectTableManager* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CObjectTableManager*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectTableManager__CObjectTableManagerDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CObjectTableManager__AddID(CObjectTableManager* thisPtr, uint32_t a0, uint32_t* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CObjectTableManager*, uint32_t, uint32_t*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectTableManager__AddID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CObjectTableManager__ClearAll(CObjectTableManager* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CObjectTableManager*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectTableManager__ClearAll);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CObjectTableManager__CreateNewPlayer(CObjectTableManager* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CObjectTableManager*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectTableManager__CreateNewPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CObjectTableManager__GetIDFromIndex(CObjectTableManager* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CObjectTableManager*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectTableManager__GetIDFromIndex);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CObjectTableManager__GetIndexFromID(CObjectTableManager* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CObjectTableManager*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectTableManager__GetIndexFromID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CObjectTableManager__RemovePlayer(CObjectTableManager* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CObjectTableManager*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectTableManager__RemovePlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CObjectTableManager__Touch(CObjectTableManager* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CObjectTableManager*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CObjectTableManager__Touch);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
