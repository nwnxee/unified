#include "CExoResMan.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoFile.hpp"
#include "CExoKeyTable.hpp"
#include "CExoStringList.hpp"
#include "CKeyTableEntry.hpp"
#include "CRes.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

CExoResMan::CExoResMan()
{
    CExoResMan__CExoResManCtor__0(this);
}

CExoResMan::~CExoResMan()
{
    CExoResMan__CExoResManDtor__0(this);
}

int32_t CExoResMan::AddEncapsulatedResourceFile(const CExoString& a0)
{
    return CExoResMan__AddEncapsulatedResourceFile(this, a0);
}

int32_t CExoResMan::AddFixedKeyTableFile(const CExoString& a0)
{
    return CExoResMan__AddFixedKeyTableFile(this, a0);
}

int32_t CExoResMan::AddKeyTable(const CExoString& a0, uint32_t a1, unsigned char* a2)
{
    return CExoResMan__AddKeyTable(this, a0, a1, a2);
}

int32_t CExoResMan::AddResourceDirectory(const CExoString& a0)
{
    return CExoResMan__AddResourceDirectory(this, a0);
}

int32_t CExoResMan::AddResourceImageFile(const CExoString& a0, unsigned char* a1)
{
    return CExoResMan__AddResourceImageFile(this, a0, a1);
}

int32_t CExoResMan::CancelRequest(CRes* a0)
{
    return CExoResMan__CancelRequest(this, a0);
}

int32_t CExoResMan::CleanDirectory(CExoString a0, int32_t a1, int32_t a2)
{
    return CExoResMan__CleanDirectory(this, a0, a1, a2);
}

int32_t CExoResMan::CreateDirectory(CExoString a0)
{
    return CExoResMan__CreateDirectory(this, a0);
}

void* CExoResMan::Demand(CRes* a0)
{
    return CExoResMan__Demand(this, a0);
}

void CExoResMan::Dump(CRes* a0, int32_t a1)
{
    return CExoResMan__Dump(this, a0, a1);
}

void CExoResMan::DumpAll()
{
    return CExoResMan__DumpAll(this);
}

int32_t CExoResMan::Exists(const CResRef& a0, uint16_t a1, uint32_t* a2)
{
    return CExoResMan__Exists(this, a0, a1, a2);
}

int32_t CExoResMan::Free(CRes* a0)
{
    return CExoResMan__Free(this, a0);
}

int32_t CExoResMan::FreeChunk()
{
    return CExoResMan__FreeChunk(this);
}

void CExoResMan::FreeResourceData(CRes* a0)
{
    return CExoResMan__FreeResourceData(this, a0);
}

CExoLocString CExoResMan::GetEncapsulatedFileDescription(const CExoString& a0)
{
    return CExoResMan__GetEncapsulatedFileDescription(this, a0);
}

int32_t CExoResMan::GetFreeDiskSpace(const CExoString& a0, uint64_t* a1)
{
    return CExoResMan__GetFreeDiskSpace(this, a0, a1);
}

int32_t CExoResMan::GetIsStaticType(uint16_t a0)
{
    return CExoResMan__GetIsStaticType(this, a0);
}

int32_t CExoResMan::GetKeyEntry(const CResRef& a0, uint16_t a1, CExoKeyTable** a2, CKeyTableEntry** a3)
{
    return CExoResMan__GetKeyEntry(this, a0, a1, a2, a3);
}

int32_t CExoResMan::GetNewResRef(const CResRef& a0, uint16_t a1, CResRef& a2)
{
    return CExoResMan__GetNewResRef(this, a0, a1, a2);
}

uint32_t CExoResMan::GetResID(const CResRef& a0, uint16_t a1)
{
    return CExoResMan__GetResID(this, a0, a1);
}

CRes* CExoResMan::GetResObject(const CResRef& a0, uint16_t a1)
{
    return CExoResMan__GetResObject(this, a0, a1);
}

CExoStringList* CExoResMan::GetResOfType(uint16_t a0, CRes* a1)
{
    return CExoResMan__GetResOfType__0(this, a0, a1);
}

CExoStringList* CExoResMan::GetResOfType(uint16_t a0, int32_t a1)
{
    return CExoResMan__GetResOfType__1(this, a0, a1);
}

void CExoResMan::GetResRefFromFile(CResRef& a0, const CExoString& a1)
{
    return CExoResMan__GetResRefFromFile(this, a0, a1);
}

uint16_t CExoResMan::GetResTypeFromFile(const CExoString& a0)
{
    return CExoResMan__GetResTypeFromFile(this, a0);
}

CExoKeyTable* CExoResMan::GetTable(CRes* a0)
{
    return CExoResMan__GetTable(this, a0);
}

int32_t CExoResMan::GetTableCount(CRes* a0, int32_t a1)
{
    return CExoResMan__GetTableCount(this, a0, a1);
}

uint32_t CExoResMan::GetTotalPhysicalMemory()
{
    return CExoResMan__GetTotalPhysicalMemory(this);
}

int32_t CExoResMan::Malloc(CRes* a0)
{
    return CExoResMan__Malloc(this, a0);
}

int32_t CExoResMan::NukeDirectory(CExoString a0, int32_t a1, int32_t a2)
{
    return CExoResMan__NukeDirectory(this, a0, a1, a2);
}

int32_t CExoResMan::ReadRaw(CRes* a0, int32_t a1, char* a2)
{
    return CExoResMan__ReadRaw(this, a0, a1, a2);
}

int32_t CExoResMan::Release(CRes* a0)
{
    return CExoResMan__Release(this, a0);
}

int32_t CExoResMan::ReleaseResObject(CRes* a0)
{
    return CExoResMan__ReleaseResObject(this, a0);
}

int32_t CExoResMan::RemoveEncapsulatedResourceFile(const CExoString& a0, int32_t a1)
{
    return CExoResMan__RemoveEncapsulatedResourceFile(this, a0, a1);
}

int32_t CExoResMan::RemoveFile(const CExoString& a0, uint16_t a1)
{
    return CExoResMan__RemoveFile(this, a0, a1);
}

int32_t CExoResMan::RemoveFixedKeyTableFile(const CExoString& a0)
{
    return CExoResMan__RemoveFixedKeyTableFile(this, a0);
}

void CExoResMan::RemoveFromToBeFreedList(CRes* a0)
{
    return CExoResMan__RemoveFromToBeFreedList(this, a0);
}

int32_t CExoResMan::RemoveKeyTable(const CExoString& a0, uint32_t a1, int32_t a2)
{
    return CExoResMan__RemoveKeyTable(this, a0, a1, a2);
}

int32_t CExoResMan::RemoveResourceDirectory(const CExoString& a0)
{
    return CExoResMan__RemoveResourceDirectory(this, a0);
}

int32_t CExoResMan::RemoveResourceImageFile(const CExoString& a0)
{
    return CExoResMan__RemoveResourceImageFile(this, a0);
}

int32_t CExoResMan::Request(CRes* a0)
{
    return CExoResMan__Request(this, a0);
}

void CExoResMan::ResumeServicing()
{
    return CExoResMan__ResumeServicing(this);
}

int32_t CExoResMan::ServiceCurrentAsyncRes()
{
    return CExoResMan__ServiceCurrentAsyncRes(this);
}

int32_t CExoResMan::ServiceFromDirectory(CRes* a0, int32_t a1)
{
    return CExoResMan__ServiceFromDirectory(this, a0, a1);
}

int32_t CExoResMan::ServiceFromDirectoryRaw(CRes* a0, int32_t a1, char* a2)
{
    return CExoResMan__ServiceFromDirectoryRaw(this, a0, a1, a2);
}

int32_t CExoResMan::ServiceFromEncapsulated(CRes* a0, int32_t a1)
{
    return CExoResMan__ServiceFromEncapsulated(this, a0, a1);
}

int32_t CExoResMan::ServiceFromEncapsulatedRaw(CRes* a0, int32_t a1, char* a2)
{
    return CExoResMan__ServiceFromEncapsulatedRaw(this, a0, a1, a2);
}

int32_t CExoResMan::ServiceFromImage(CRes* a0, int32_t a1)
{
    return CExoResMan__ServiceFromImage(this, a0, a1);
}

int32_t CExoResMan::ServiceFromImageRaw(CRes* a0, int32_t a1, char* a2)
{
    return CExoResMan__ServiceFromImageRaw(this, a0, a1, a2);
}

int32_t CExoResMan::ServiceFromResFile(CRes* a0, int32_t a1)
{
    return CExoResMan__ServiceFromResFile(this, a0, a1);
}

int32_t CExoResMan::ServiceFromResFileRaw(CRes* a0, int32_t a1, char* a2)
{
    return CExoResMan__ServiceFromResFileRaw(this, a0, a1, a2);
}

void CExoResMan::SetResObject(const CResRef& a0, uint16_t a1, CRes* a2)
{
    return CExoResMan__SetResObject(this, a0, a1, a2);
}

int32_t CExoResMan::SetTotalResourceMemory(int32_t a0)
{
    return CExoResMan__SetTotalResourceMemory(this, a0);
}

void CExoResMan::SuspendServicing()
{
    return CExoResMan__SuspendServicing(this);
}

void CExoResMan::Update(uint32_t a0)
{
    return CExoResMan__Update(this, a0);
}

int32_t CExoResMan::UpdateEncapsulatedResourceFile(const CExoString& a0)
{
    return CExoResMan__UpdateEncapsulatedResourceFile(this, a0);
}

int32_t CExoResMan::UpdateFixedKeyTableFile(const CExoString& a0)
{
    return CExoResMan__UpdateFixedKeyTableFile(this, a0);
}

int32_t CExoResMan::UpdateKeyTable(const CExoString& a0, uint32_t a1)
{
    return CExoResMan__UpdateKeyTable(this, a0, a1);
}

int32_t CExoResMan::UpdateResourceDirectory(const CExoString& a0)
{
    return CExoResMan__UpdateResourceDirectory(this, a0);
}

int32_t CExoResMan::WipeDirectory(CExoString a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4)
{
    return CExoResMan__WipeDirectory(this, a0, a1, a2, a3, a4);
}

void CExoResMan__CExoResManCtor__0(CExoResMan* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResMan*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__CExoResManCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoResMan__CExoResManDtor__0(CExoResMan* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResMan*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__CExoResManDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CExoResMan__AddEncapsulatedResourceFile(CExoResMan* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__AddEncapsulatedResourceFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__AddFixedKeyTableFile(CExoResMan* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__AddFixedKeyTableFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__AddKeyTable(CExoResMan* thisPtr, const CExoString& a0, uint32_t a1, unsigned char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&, uint32_t, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__AddKeyTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CExoResMan__AddResourceDirectory(CExoResMan* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__AddResourceDirectory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__AddResourceImageFile(CExoResMan* thisPtr, const CExoString& a0, unsigned char* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__AddResourceImageFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoResMan__CancelRequest(CExoResMan* thisPtr, CRes* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__CancelRequest);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__CleanDirectory(CExoResMan* thisPtr, CExoString a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CExoString, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__CleanDirectory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CExoResMan__CreateDirectory(CExoResMan* thisPtr, CExoString a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__CreateDirectory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void* CExoResMan__Demand(CExoResMan* thisPtr, CRes* a0)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CExoResMan*, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__Demand);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoResMan__Dump(CExoResMan* thisPtr, CRes* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResMan*, CRes*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__Dump);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CExoResMan__DumpAll(CExoResMan* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResMan*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__DumpAll);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoResMan__Exists(CExoResMan* thisPtr, const CResRef& a0, uint16_t a1, uint32_t* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CResRef&, uint16_t, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__Exists);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CExoResMan__Free(CExoResMan* thisPtr, CRes* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__Free);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__FreeChunk(CExoResMan* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__FreeChunk);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoResMan__FreeResourceData(CExoResMan* thisPtr, CRes* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResMan*, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__FreeResourceData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoLocString CExoResMan__GetEncapsulatedFileDescription(CExoResMan* thisPtr, const CExoString& a0)
{
    using FuncPtrType = CExoLocString(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetEncapsulatedFileDescription);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__GetFreeDiskSpace(CExoResMan* thisPtr, const CExoString& a0, uint64_t* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&, uint64_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetFreeDiskSpace);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoResMan__GetIsStaticType(CExoResMan* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetIsStaticType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__GetKeyEntry(CExoResMan* thisPtr, const CResRef& a0, uint16_t a1, CExoKeyTable** a2, CKeyTableEntry** a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CResRef&, uint16_t, CExoKeyTable**, CKeyTableEntry**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetKeyEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CExoResMan__GetNewResRef(CExoResMan* thisPtr, const CResRef& a0, uint16_t a1, CResRef& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CResRef&, uint16_t, CResRef&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetNewResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CExoResMan__GetResID(CExoResMan* thisPtr, const CResRef& a0, uint16_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoResMan*, const CResRef&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetResID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CRes* CExoResMan__GetResObject(CExoResMan* thisPtr, const CResRef& a0, uint16_t a1)
{
    using FuncPtrType = CRes*(__attribute__((cdecl)) *)(CExoResMan*, const CResRef&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetResObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CExoStringList* CExoResMan__GetResOfType__0(CExoResMan* thisPtr, uint16_t a0, CRes* a1)
{
    using FuncPtrType = CExoStringList*(__attribute__((cdecl)) *)(CExoResMan*, uint16_t, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetResOfType__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CExoStringList* CExoResMan__GetResOfType__1(CExoResMan* thisPtr, uint16_t a0, int32_t a1)
{
    using FuncPtrType = CExoStringList*(__attribute__((cdecl)) *)(CExoResMan*, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetResOfType__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CExoResMan__GetResRefFromFile(CExoResMan* thisPtr, CResRef& a0, const CExoString& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResMan*, CResRef&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetResRefFromFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint16_t CExoResMan__GetResTypeFromFile(CExoResMan* thisPtr, const CExoString& a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetResTypeFromFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoKeyTable* CExoResMan__GetTable(CExoResMan* thisPtr, CRes* a0)
{
    using FuncPtrType = CExoKeyTable*(__attribute__((cdecl)) *)(CExoResMan*, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__GetTableCount(CExoResMan* thisPtr, CRes* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetTableCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CExoResMan__GetTotalPhysicalMemory(CExoResMan* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoResMan*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__GetTotalPhysicalMemory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoResMan__Malloc(CExoResMan* thisPtr, CRes* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__Malloc);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__NukeDirectory(CExoResMan* thisPtr, CExoString a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CExoString, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__NukeDirectory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CExoResMan__ReadRaw(CExoResMan* thisPtr, CRes* a0, int32_t a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*, int32_t, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__ReadRaw);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CExoResMan__Release(CExoResMan* thisPtr, CRes* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__Release);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__ReleaseResObject(CExoResMan* thisPtr, CRes* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__ReleaseResObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__RemoveEncapsulatedResourceFile(CExoResMan* thisPtr, const CExoString& a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__RemoveEncapsulatedResourceFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoResMan__RemoveFile(CExoResMan* thisPtr, const CExoString& a0, uint16_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__RemoveFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoResMan__RemoveFixedKeyTableFile(CExoResMan* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__RemoveFixedKeyTableFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoResMan__RemoveFromToBeFreedList(CExoResMan* thisPtr, CRes* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResMan*, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__RemoveFromToBeFreedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__RemoveKeyTable(CExoResMan* thisPtr, const CExoString& a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__RemoveKeyTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CExoResMan__RemoveResourceDirectory(CExoResMan* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__RemoveResourceDirectory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__RemoveResourceImageFile(CExoResMan* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__RemoveResourceImageFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__Request(CExoResMan* thisPtr, CRes* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__Request);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoResMan__ResumeServicing(CExoResMan* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResMan*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__ResumeServicing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoResMan__ServiceCurrentAsyncRes(CExoResMan* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__ServiceCurrentAsyncRes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoResMan__ServiceFromDirectory(CExoResMan* thisPtr, CRes* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__ServiceFromDirectory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoResMan__ServiceFromDirectoryRaw(CExoResMan* thisPtr, CRes* a0, int32_t a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*, int32_t, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__ServiceFromDirectoryRaw);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CExoResMan__ServiceFromEncapsulated(CExoResMan* thisPtr, CRes* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__ServiceFromEncapsulated);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoResMan__ServiceFromEncapsulatedRaw(CExoResMan* thisPtr, CRes* a0, int32_t a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*, int32_t, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__ServiceFromEncapsulatedRaw);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CExoResMan__ServiceFromImage(CExoResMan* thisPtr, CRes* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__ServiceFromImage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoResMan__ServiceFromImageRaw(CExoResMan* thisPtr, CRes* a0, int32_t a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*, int32_t, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__ServiceFromImageRaw);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CExoResMan__ServiceFromResFile(CExoResMan* thisPtr, CRes* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__ServiceFromResFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoResMan__ServiceFromResFileRaw(CExoResMan* thisPtr, CRes* a0, int32_t a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CRes*, int32_t, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__ServiceFromResFileRaw);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CExoResMan__SetResObject(CExoResMan* thisPtr, const CResRef& a0, uint16_t a1, CRes* a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResMan*, const CResRef&, uint16_t, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__SetResObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CExoResMan__SetTotalResourceMemory(CExoResMan* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__SetTotalResourceMemory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoResMan__SuspendServicing(CExoResMan* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResMan*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__SuspendServicing);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoResMan__Update(CExoResMan* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResMan*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__Update);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__UpdateEncapsulatedResourceFile(CExoResMan* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__UpdateEncapsulatedResourceFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__UpdateFixedKeyTableFile(CExoResMan* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__UpdateFixedKeyTableFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__UpdateKeyTable(CExoResMan* thisPtr, const CExoString& a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__UpdateKeyTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoResMan__UpdateResourceDirectory(CExoResMan* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__UpdateResourceDirectory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResMan__WipeDirectory(CExoResMan* thisPtr, CExoString a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResMan*, CExoString, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResMan__WipeDirectory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

}

}
