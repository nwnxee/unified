#include "CExoFileInternal.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoFileInternal::CExoFileInternal(const CExoString& a0, uint16_t a1, const CExoString& a2)
{
    CExoFileInternal__CExoFileInternalCtor(this, a0, a1, a2);
}

CExoFileInternal::~CExoFileInternal()
{
    CExoFileInternal__CExoFileInternalDtor(this);
}

uint32_t CExoFileInternal::GetOffset()
{
    return CExoFileInternal__GetOffset(this);
}

int32_t CExoFileInternal::GetSize()
{
    return CExoFileInternal__GetSize(this);
}

void CExoFileInternal::Read(CExoString* a0, uint32_t a1)
{
    return CExoFileInternal__Read(this, a0, a1);
}

void CExoFileInternal::ReadAsync(void* a0, uint32_t a1, uint32_t a2)
{
    return CExoFileInternal__ReadAsync(this, a0, a1, a2);
}

uint32_t CExoFileInternal::ReadAsyncBytesRead()
{
    return CExoFileInternal__ReadAsyncBytesRead(this);
}

int32_t CExoFileInternal::ReadAsyncComplete()
{
    return CExoFileInternal__ReadAsyncComplete(this);
}

void CExoFileInternal::Write(const char* a0)
{
    return CExoFileInternal__Write(this, a0);
}

void CExoFileInternal__CExoFileInternalCtor(CExoFileInternal* thisPtr, const CExoString& a0, uint16_t a1, const CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileInternal*, const CExoString&, uint16_t, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__CExoFileInternalCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2);
}

void CExoFileInternal__CExoFileInternalDtor(CExoFileInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileInternal*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__CExoFileInternalDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

uint32_t CExoFileInternal__GetOffset(CExoFileInternal* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoFileInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__GetOffset);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoFileInternal__GetSize(CExoFileInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFileInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__GetSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoFileInternal__Read(CExoFileInternal* thisPtr, CExoString* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileInternal*, CExoString*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__Read);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1);
}

void CExoFileInternal__ReadAsync(CExoFileInternal* thisPtr, void* a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileInternal*, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__ReadAsync);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CExoFileInternal__ReadAsyncBytesRead(CExoFileInternal* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoFileInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__ReadAsyncBytesRead);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoFileInternal__ReadAsyncComplete(CExoFileInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFileInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__ReadAsyncComplete);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoFileInternal__Write(CExoFileInternal* thisPtr, const char* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileInternal*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__Write);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

}

}
