#include "CERFFile.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CERFRes.hpp"
#include "CERFString.hpp"
#include "CExoFile.hpp"
#include "CExoString.hpp"
#include "CRes.hpp"

namespace NWNXLib {

namespace API {

CERFFile::CERFFile()
{
    CERFFile__CERFFileCtor__0(this);
}

CERFFile::~CERFFile()
{
    CERFFile__CERFFileDtor__0(this);
}

int32_t CERFFile::AddResource(CExoString& a0)
{
    return CERFFile__AddResource__0(this, a0);
}

int32_t CERFFile::AddResource(char* a0, uint16_t a1, CRes* a2)
{
    return CERFFile__AddResource__1(this, a0, a1, a2);
}

int32_t CERFFile::AddString(CERFString* a0)
{
    return CERFFile__AddString(this, a0);
}

int32_t CERFFile::Create(CExoString& a0)
{
    return CERFFile__Create(this, a0);
}

int32_t CERFFile::Finish()
{
    return CERFFile__Finish(this);
}

int32_t CERFFile::Read()
{
    return CERFFile__Read(this);
}

int32_t CERFFile::ReadModuleDescription(const CExoString& a0, uint16_t a1, uint32_t* a2, CExoString* a3)
{
    return CERFFile__ReadModuleDescription(a0, a1, a2, a3);
}

void CERFFile::RecalculateOffsets()
{
    return CERFFile__RecalculateOffsets(this);
}

int32_t CERFFile::RemoveResource(CERFRes* a0)
{
    return CERFFile__RemoveResource__0(this, a0);
}

int32_t CERFFile::RemoveResource(CExoString& a0, uint16_t a1)
{
    return CERFFile__RemoveResource__1(this, a0, a1);
}

int32_t CERFFile::Reset()
{
    return CERFFile__Reset(this);
}

int32_t CERFFile::SetNumEntries(uint32_t a0)
{
    return CERFFile__SetNumEntries(this, a0);
}

void CERFFile::SetVersion(char* a0)
{
    return CERFFile__SetVersion(this, a0);
}

int32_t CERFFile::Write(CExoString& a0)
{
    return CERFFile__Write(this, a0);
}

int32_t CERFFile::WriteHeader()
{
    return CERFFile__WriteHeader(this);
}

int32_t CERFFile::WriteResource(char* a0, uint16_t a1, CRes* a2, int32_t a3)
{
    return CERFFile__WriteResource(this, a0, a1, a2, a3);
}

int32_t CERFFile::WriteStringTable()
{
    return CERFFile__WriteStringTable(this);
}

void CERFFile__CERFFileCtor__0(CERFFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CERFFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__CERFFileCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CERFFile__CERFFileDtor__0(CERFFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CERFFile*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__CERFFileDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CERFFile__AddResource__0(CERFFile* thisPtr, CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__AddResource__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CERFFile__AddResource__1(CERFFile* thisPtr, char* a0, uint16_t a1, CRes* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*, char*, uint16_t, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__AddResource__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CERFFile__AddString(CERFFile* thisPtr, CERFString* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*, CERFString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__AddString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CERFFile__Create(CERFFile* thisPtr, CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__Create);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CERFFile__Finish(CERFFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__Finish);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CERFFile__Read(CERFFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__Read);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CERFFile__ReadModuleDescription(const CExoString& a0, uint16_t a1, uint32_t* a2, CExoString* a3)
{
    using FuncPtrType = int32_t(*)(const CExoString&, uint16_t, uint32_t*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__ReadModuleDescription);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0, a1, a2, a3);
}

void CERFFile__RecalculateOffsets(CERFFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CERFFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__RecalculateOffsets);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CERFFile__RemoveResource__0(CERFFile* thisPtr, CERFRes* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*, CERFRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__RemoveResource__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CERFFile__RemoveResource__1(CERFFile* thisPtr, CExoString& a0, uint16_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*, CExoString&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__RemoveResource__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CERFFile__Reset(CERFFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__Reset);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CERFFile__SetNumEntries(CERFFile* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__SetNumEntries);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CERFFile__SetVersion(CERFFile* thisPtr, char* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CERFFile*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__SetVersion);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CERFFile__Write(CERFFile* thisPtr, CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__Write);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CERFFile__WriteHeader(CERFFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__WriteHeader);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CERFFile__WriteResource(CERFFile* thisPtr, char* a0, uint16_t a1, CRes* a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*, char*, uint16_t, CRes*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__WriteResource);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CERFFile__WriteStringTable(CERFFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFFile__WriteStringTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
