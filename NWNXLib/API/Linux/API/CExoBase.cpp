#include "CExoBase.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoAliasList.hpp"
#include "CExoArrayListTemplatedCExoString.hpp"
#include "CExoArrayListTemplatedCFileInfo.hpp"
#include "CExoBaseInternal.hpp"
#include "CExoDebug.hpp"
#include "CExoIni.hpp"
#include "CExoRand.hpp"
#include "CExoTimers.hpp"

namespace NWNXLib {

namespace API {

CExoBase::CExoBase(CExoString a0)
{
    CExoBase__CExoBaseCtor(this, a0);
}

CExoBase::~CExoBase()
{
    CExoBase__CExoBaseDtor(this);
}

int32_t CExoBase::CheckForCD(uint32_t a0)
{
    return CExoBase__CheckForCD(this, a0);
}

int32_t CExoBase::GetAugmentedDirectoryList(CExoArrayListTemplatedCFileInfo* a0, CExoString a1, uint16_t a2, int32_t a3)
{
    return CExoBase__GetAugmentedDirectoryList(this, a0, a1, a2, a3);
}

int32_t CExoBase::GetDirectoryAndWorkshopList(CExoArrayListTemplatedCExoString* a0, CExoString a1, uint16_t a2, int32_t a3, int32_t a4)
{
    return CExoBase__GetDirectoryAndWorkshopList(this, a0, a1, a2, a3, a4);
}

int32_t CExoBase::GetDirectoryList(CExoArrayListTemplatedCExoString* a0, CExoString a1, uint16_t a2, int32_t a3, int32_t a4)
{
    return CExoBase__GetDirectoryList(this, a0, a1, a2, a3, a4);
}

const CExoString& CExoBase::GetResourceExtension(uint16_t a0)
{
    return CExoBase__GetResourceExtension(this, a0);
}

uint16_t CExoBase::GetResTypeFromExtension(const CExoString& a0)
{
    return CExoBase__GetResTypeFromExtension(this, a0);
}

void CExoBase::LoadAliases(int32_t a0)
{
    return CExoBase__LoadAliases(this, a0);
}

void CExoBase::ShutDown()
{
    return CExoBase__ShutDown(this);
}

void CExoBase::SpawnExternalApplication(const CExoString& a0, const CExoString& a1, int32_t a2)
{
    return CExoBase__SpawnExternalApplication(this, a0, a1, a2);
}

void CExoBase__CExoBaseCtor(CExoBase* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoBase*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoBase__CExoBaseCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CExoBase__CExoBaseDtor(CExoBase* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoBase*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoBase__CExoBaseDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CExoBase__CheckForCD(CExoBase* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoBase*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoBase__CheckForCD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoBase__GetAugmentedDirectoryList(CExoBase* thisPtr, CExoArrayListTemplatedCFileInfo* a0, CExoString a1, uint16_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoBase*, CExoArrayListTemplatedCFileInfo*, CExoString, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoBase__GetAugmentedDirectoryList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CExoBase__GetDirectoryAndWorkshopList(CExoBase* thisPtr, CExoArrayListTemplatedCExoString* a0, CExoString a1, uint16_t a2, int32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoBase*, CExoArrayListTemplatedCExoString*, CExoString, uint16_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoBase__GetDirectoryAndWorkshopList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CExoBase__GetDirectoryList(CExoBase* thisPtr, CExoArrayListTemplatedCExoString* a0, CExoString a1, uint16_t a2, int32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoBase*, CExoArrayListTemplatedCExoString*, CExoString, uint16_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoBase__GetDirectoryList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

const CExoString& CExoBase__GetResourceExtension(CExoBase* thisPtr, uint16_t a0)
{
    using FuncPtrType = const CExoString&(__attribute__((cdecl)) *)(CExoBase*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoBase__GetResourceExtension);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint16_t CExoBase__GetResTypeFromExtension(CExoBase* thisPtr, const CExoString& a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CExoBase*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoBase__GetResTypeFromExtension);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoBase__LoadAliases(CExoBase* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoBase*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoBase__LoadAliases);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoBase__ShutDown(CExoBase* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoBase*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoBase__ShutDown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoBase__SpawnExternalApplication(CExoBase* thisPtr, const CExoString& a0, const CExoString& a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoBase*, const CExoString&, const CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoBase__SpawnExternalApplication);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

}

}
