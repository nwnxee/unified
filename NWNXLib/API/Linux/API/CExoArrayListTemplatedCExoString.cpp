#include "CExoArrayListTemplatedCExoString.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedCExoString::~CExoArrayListTemplatedCExoString()
{
    CExoArrayListTemplatedCExoString__CExoArrayListTemplatedCExoStringDtor(this);
}

void CExoArrayListTemplatedCExoString::Add(CExoString a0)
{
    return CExoArrayListTemplatedCExoString__Add(this, a0);
}

int32_t CExoArrayListTemplatedCExoString::AddUnique(CExoString a0)
{
    return CExoArrayListTemplatedCExoString__AddUnique(this, a0);
}

void CExoArrayListTemplatedCExoString::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedCExoString__Allocate(this, a0);
}

void CExoArrayListTemplatedCExoString::Insert(CExoString a0, int32_t a1)
{
    return CExoArrayListTemplatedCExoString__Insert(this, a0, a1);
}

void CExoArrayListTemplatedCExoString::Remove(CExoString a0)
{
    return CExoArrayListTemplatedCExoString__Remove(this, a0);
}

void CExoArrayListTemplatedCExoString::SetSize(int32_t a0)
{
    return CExoArrayListTemplatedCExoString__SetSize(this, a0);
}

void CExoArrayListTemplatedCExoString__CExoArrayListTemplatedCExoStringDtor(CExoArrayListTemplatedCExoString* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCExoString*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCExoString__CExoArrayListTemplatedCExoStringDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CExoArrayListTemplatedCExoString__Add(CExoArrayListTemplatedCExoString* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCExoString*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCExoString__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoArrayListTemplatedCExoString__AddUnique(CExoArrayListTemplatedCExoString* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoArrayListTemplatedCExoString*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCExoString__AddUnique);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoArrayListTemplatedCExoString__Allocate(CExoArrayListTemplatedCExoString* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCExoString*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCExoString__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoArrayListTemplatedCExoString__Insert(CExoArrayListTemplatedCExoString* thisPtr, CExoString a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCExoString*, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCExoString__Insert);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CExoArrayListTemplatedCExoString__Remove(CExoArrayListTemplatedCExoString* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCExoString*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCExoString__Remove);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoArrayListTemplatedCExoString__SetSize(CExoArrayListTemplatedCExoString* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCExoString*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCExoString__SetSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
