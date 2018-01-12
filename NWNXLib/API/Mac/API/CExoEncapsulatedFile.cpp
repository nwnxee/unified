#include "CExoEncapsulatedFile.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "EncapsulatedHeader_st.hpp"
#include "EncapsulatedResListEntry_st.hpp"

namespace NWNXLib {

namespace API {

CExoEncapsulatedFile::CExoEncapsulatedFile()
{
    CExoEncapsulatedFile__CExoEncapsulatedFileCtor__0(this);
}

CExoEncapsulatedFile::~CExoEncapsulatedFile()
{
    CExoEncapsulatedFile__CExoEncapsulatedFileDtor__0(this);
}

void CExoEncapsulatedFile::AddAsyncRefCount()
{
    return CExoEncapsulatedFile__AddAsyncRefCount(this);
}

void CExoEncapsulatedFile::AddRefCount()
{
    return CExoEncapsulatedFile__AddRefCount(this);
}

int32_t CExoEncapsulatedFile::CloseAsyncFile()
{
    return CExoEncapsulatedFile__CloseAsyncFile(this);
}

int32_t CExoEncapsulatedFile::CloseFile()
{
    return CExoEncapsulatedFile__CloseFile(this);
}

void CExoEncapsulatedFile::DeleteAsyncRefCount()
{
    return CExoEncapsulatedFile__DeleteAsyncRefCount(this);
}

void CExoEncapsulatedFile::DeleteRefCount()
{
    return CExoEncapsulatedFile__DeleteRefCount(this);
}

uint32_t CExoEncapsulatedFile::GetResourceSize(uint32_t a0)
{
    return CExoEncapsulatedFile__GetResourceSize(this, a0);
}

int32_t CExoEncapsulatedFile::Initialize()
{
    return CExoEncapsulatedFile__Initialize(this);
}

int32_t CExoEncapsulatedFile::LoadHeader(unsigned char a0)
{
    return CExoEncapsulatedFile__LoadHeader(this, a0);
}

int32_t CExoEncapsulatedFile::OpenAsyncFile()
{
    return CExoEncapsulatedFile__OpenAsyncFile(this);
}

int32_t CExoEncapsulatedFile::OpenFile()
{
    return CExoEncapsulatedFile__OpenFile__0(this);
}

int32_t CExoEncapsulatedFile::OpenFile(unsigned char* a0)
{
    return CExoEncapsulatedFile__OpenFile__1(this, a0);
}

uint32_t CExoEncapsulatedFile::ReadResource(uint32_t a0, void* a1, uint32_t a2, uint32_t a3)
{
    return CExoEncapsulatedFile__ReadResource(this, a0, a1, a2, a3);
}

void CExoEncapsulatedFile::ReadResourceAsync(uint32_t a0, void* a1, uint32_t a2, uint32_t a3)
{
    return CExoEncapsulatedFile__ReadResourceAsync(this, a0, a1, a2, a3);
}

int32_t CExoEncapsulatedFile::UnloadHeader()
{
    return CExoEncapsulatedFile__UnloadHeader(this);
}

void CExoEncapsulatedFile__CExoEncapsulatedFileCtor__0(CExoEncapsulatedFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoEncapsulatedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__CExoEncapsulatedFileCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoEncapsulatedFile__CExoEncapsulatedFileDtor__0(CExoEncapsulatedFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoEncapsulatedFile*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__CExoEncapsulatedFileDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CExoEncapsulatedFile__AddAsyncRefCount(CExoEncapsulatedFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoEncapsulatedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__AddAsyncRefCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoEncapsulatedFile__AddRefCount(CExoEncapsulatedFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoEncapsulatedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__AddRefCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoEncapsulatedFile__CloseAsyncFile(CExoEncapsulatedFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoEncapsulatedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__CloseAsyncFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoEncapsulatedFile__CloseFile(CExoEncapsulatedFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoEncapsulatedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__CloseFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoEncapsulatedFile__DeleteAsyncRefCount(CExoEncapsulatedFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoEncapsulatedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__DeleteAsyncRefCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoEncapsulatedFile__DeleteRefCount(CExoEncapsulatedFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoEncapsulatedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__DeleteRefCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CExoEncapsulatedFile__GetResourceSize(CExoEncapsulatedFile* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoEncapsulatedFile*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__GetResourceSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoEncapsulatedFile__Initialize(CExoEncapsulatedFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoEncapsulatedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__Initialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoEncapsulatedFile__LoadHeader(CExoEncapsulatedFile* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoEncapsulatedFile*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__LoadHeader);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoEncapsulatedFile__OpenAsyncFile(CExoEncapsulatedFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoEncapsulatedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__OpenAsyncFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoEncapsulatedFile__OpenFile__0(CExoEncapsulatedFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoEncapsulatedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__OpenFile__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoEncapsulatedFile__OpenFile__1(CExoEncapsulatedFile* thisPtr, unsigned char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoEncapsulatedFile*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__OpenFile__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CExoEncapsulatedFile__ReadResource(CExoEncapsulatedFile* thisPtr, uint32_t a0, void* a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoEncapsulatedFile*, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__ReadResource);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CExoEncapsulatedFile__ReadResourceAsync(CExoEncapsulatedFile* thisPtr, uint32_t a0, void* a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoEncapsulatedFile*, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__ReadResourceAsync);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CExoEncapsulatedFile__UnloadHeader(CExoEncapsulatedFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoEncapsulatedFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoEncapsulatedFile__UnloadHeader);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
