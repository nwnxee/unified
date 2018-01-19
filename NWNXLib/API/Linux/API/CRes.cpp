#include "CRes.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListNode.hpp"
#include "CKeyTableEntry.hpp"

namespace NWNXLib {

namespace API {

CRes::CRes()
{
    CRes__CResCtor__0(this);
}

CRes::CRes(uint32_t a0)
{
    CRes__CResCtor__1(this, a0);
}

CRes::~CRes()
{
    CRes__CResDtor__0(this);
}

int32_t CRes::CancelRequest()
{
    return CRes__CancelRequest(this);
}

void* CRes::Demand()
{
    return CRes__Demand(this);
}

void CRes::Dump(int32_t a0)
{
    return CRes__Dump(this, a0);
}

void* CRes::GetData()
{
    return CRes__GetData(this);
}

int32_t CRes::GetDemands()
{
    return CRes__GetDemands(this);
}

int32_t CRes::GetFixedResourceDataOffset()
{
    return CRes__GetFixedResourceDataOffset(this);
}

int32_t CRes::GetFixedResourceSize()
{
    return CRes__GetFixedResourceSize(this);
}

int32_t CRes::GetID()
{
    return CRes__GetID(this);
}

int32_t CRes::GetRequests()
{
    return CRes__GetRequests(this);
}

int32_t CRes::GetSize()
{
    return CRes__GetSize(this);
}

int32_t CRes::OnResourceFreed()
{
    return CRes__OnResourceFreed(this);
}

int32_t CRes::OnResourceServiced()
{
    return CRes__OnResourceServiced(this);
}

int32_t CRes::ReadRaw(int32_t a0, char* a1)
{
    return CRes__ReadRaw(this, a0, a1);
}

int32_t CRes::Release()
{
    return CRes__Release(this);
}

int32_t CRes::Request()
{
    return CRes__Request(this);
}

void CRes::SetID(uint32_t a0)
{
    return CRes__SetID(this, a0);
}

void CRes__CResCtor__0(CRes* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__CResCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CRes__CResCtor__1(CRes* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CRes*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__CResCtor__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CRes__CResDtor__0(CRes* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CRes*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__CResDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CRes__CancelRequest(CRes* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__CancelRequest);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void* CRes__Demand(CRes* thisPtr)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__Demand);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CRes__Dump(CRes* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CRes*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__Dump);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void* CRes__GetData(CRes* thisPtr)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__GetData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CRes__GetDemands(CRes* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__GetDemands);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CRes__GetFixedResourceDataOffset(CRes* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__GetFixedResourceDataOffset);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CRes__GetFixedResourceSize(CRes* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__GetFixedResourceSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CRes__GetID(CRes* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__GetID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CRes__GetRequests(CRes* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__GetRequests);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CRes__GetSize(CRes* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__GetSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CRes__OnResourceFreed(CRes* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__OnResourceFreed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CRes__OnResourceServiced(CRes* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__OnResourceServiced);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CRes__ReadRaw(CRes* thisPtr, int32_t a0, char* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes*, int32_t, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__ReadRaw);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CRes__Release(CRes* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__Release);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CRes__Request(CRes* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__Request);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CRes__SetID(CRes* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CRes*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes__SetID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
