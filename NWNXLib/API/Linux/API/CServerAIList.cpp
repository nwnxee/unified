#include "CServerAIList.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSObject.hpp"

namespace NWNXLib {

namespace API {

CServerAIList::CServerAIList()
{
    CServerAIList__CServerAIListCtor(this);
}

CServerAIList::~CServerAIList()
{
    CServerAIList__CServerAIListDtor(this);
}

int32_t CServerAIList::AddObject(uint32_t a0)
{
    return CServerAIList__AddObject(this, a0);
}

CNWSObject* CServerAIList::GetNextObject()
{
    return CServerAIList__GetNextObject(this);
}

int32_t CServerAIList::RemoveObject(uint32_t a0)
{
    return CServerAIList__RemoveObject(this, a0);
}

void CServerAIList__CServerAIListCtor(CServerAIList* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerAIList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIList__CServerAIListCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CServerAIList__CServerAIListDtor(CServerAIList* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerAIList*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIList__CServerAIListDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CServerAIList__AddObject(CServerAIList* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIList*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIList__AddObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSObject* CServerAIList__GetNextObject(CServerAIList* thisPtr)
{
    using FuncPtrType = CNWSObject*(__attribute__((cdecl)) *)(CServerAIList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIList__GetNextObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerAIList__RemoveObject(CServerAIList* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIList*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIList__RemoveObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
