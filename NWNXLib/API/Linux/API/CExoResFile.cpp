#include "CExoResFile.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "BiffFileHeader_st.hpp"
#include "BiffFileVarResEntry_st.hpp"

namespace NWNXLib {

namespace API {

CExoResFile::CExoResFile()
{
    CExoResFile__CExoResFileCtor(this);
}

CExoResFile::~CExoResFile()
{
    CExoResFile__CExoResFileDtor__0(this);
}

void CExoResFile::AddAsyncRefCount()
{
    return CExoResFile__AddAsyncRefCount(this);
}

void CExoResFile::AddRefCount()
{
    return CExoResFile__AddRefCount(this);
}

int32_t CExoResFile::CloseAsyncFile()
{
    return CExoResFile__CloseAsyncFile(this);
}

int32_t CExoResFile::CloseFile()
{
    return CExoResFile__CloseFile(this);
}

void CExoResFile::DeleteAsyncRefCount()
{
    return CExoResFile__DeleteAsyncRefCount(this);
}

void CExoResFile::DeleteRefCount()
{
    return CExoResFile__DeleteRefCount(this);
}

uint32_t CExoResFile::GetResourceSize(uint32_t a0)
{
    return CExoResFile__GetResourceSize(this, a0);
}

int32_t CExoResFile::Initialize()
{
    return CExoResFile__Initialize(this);
}

int32_t CExoResFile::LoadHeader(unsigned char a0)
{
    return CExoResFile__LoadHeader(this, a0);
}

int32_t CExoResFile::OpenAsyncFile()
{
    return CExoResFile__OpenAsyncFile(this);
}

int32_t CExoResFile::OpenFile()
{
    return CExoResFile__OpenFile__0(this);
}

int32_t CExoResFile::OpenFile(unsigned char* a0)
{
    return CExoResFile__OpenFile__1(this, a0);
}

uint32_t CExoResFile::ReadResource(uint32_t a0, void* a1, uint32_t a2, uint32_t a3)
{
    return CExoResFile__ReadResource(this, a0, a1, a2, a3);
}

void CExoResFile::ReadResourceAsync(uint32_t a0, void* a1, uint32_t a2, uint32_t a3)
{
    return CExoResFile__ReadResourceAsync(this, a0, a1, a2, a3);
}

int32_t CExoResFile::UnloadHeader()
{
    return CExoResFile__UnloadHeader(this);
}

void CExoResFile__CExoResFileCtor(CExoResFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__CExoResFileCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoResFile__CExoResFileDtor__0(CExoResFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResFile*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__CExoResFileDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CExoResFile__AddAsyncRefCount(CExoResFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__AddAsyncRefCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoResFile__AddRefCount(CExoResFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__AddRefCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoResFile__CloseAsyncFile(CExoResFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__CloseAsyncFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoResFile__CloseFile(CExoResFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__CloseFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoResFile__DeleteAsyncRefCount(CExoResFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__DeleteAsyncRefCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoResFile__DeleteRefCount(CExoResFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__DeleteRefCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CExoResFile__GetResourceSize(CExoResFile* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoResFile*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__GetResourceSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResFile__Initialize(CExoResFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__Initialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoResFile__LoadHeader(CExoResFile* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResFile*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__LoadHeader);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoResFile__OpenAsyncFile(CExoResFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__OpenAsyncFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoResFile__OpenFile__0(CExoResFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__OpenFile__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoResFile__OpenFile__1(CExoResFile* thisPtr, unsigned char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResFile*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__OpenFile__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CExoResFile__ReadResource(CExoResFile* thisPtr, uint32_t a0, void* a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoResFile*, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__ReadResource);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CExoResFile__ReadResourceAsync(CExoResFile* thisPtr, uint32_t a0, void* a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoResFile*, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__ReadResourceAsync);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CExoResFile__UnloadHeader(CExoResFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoResFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoResFile__UnloadHeader);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
