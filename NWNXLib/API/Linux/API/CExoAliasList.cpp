#include "CExoAliasList.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoAliasListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoAliasList::CExoAliasList()
{
    CExoAliasList__CExoAliasListCtor(this);
}

CExoAliasList::~CExoAliasList()
{
    CExoAliasList__CExoAliasListDtor(this);
}

void CExoAliasList::Add(CExoString a0, CExoString a1)
{
    return CExoAliasList__Add(this, a0, a1);
}

void CExoAliasList::Clear()
{
    return CExoAliasList__Clear(this);
}

void CExoAliasList::Delete(CExoString a0)
{
    return CExoAliasList__Delete(this, a0);
}

const CExoString& CExoAliasList::GetAliasPath(const CExoString& a0, int32_t a1)
{
    return CExoAliasList__GetAliasPath(this, a0, a1);
}

CExoString CExoAliasList::ResolveFileName(const CExoString& a0, uint16_t a1)
{
    return CExoAliasList__ResolveFileName(this, a0, a1);
}

void CExoAliasList__CExoAliasListCtor(CExoAliasList* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoAliasList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoAliasList__CExoAliasListCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoAliasList__CExoAliasListDtor(CExoAliasList* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoAliasList*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoAliasList__CExoAliasListDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CExoAliasList__Add(CExoAliasList* thisPtr, CExoString a0, CExoString a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoAliasList*, CExoString, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoAliasList__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CExoAliasList__Clear(CExoAliasList* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoAliasList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoAliasList__Clear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoAliasList__Delete(CExoAliasList* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoAliasList*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoAliasList__Delete);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

const CExoString& CExoAliasList__GetAliasPath(CExoAliasList* thisPtr, const CExoString& a0, int32_t a1)
{
    using FuncPtrType = const CExoString&(__attribute__((cdecl)) *)(CExoAliasList*, const CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoAliasList__GetAliasPath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CExoString CExoAliasList__ResolveFileName(CExoAliasList* thisPtr, const CExoString& a0, uint16_t a1)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CExoAliasList*, const CExoString&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoAliasList__ResolveFileName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
