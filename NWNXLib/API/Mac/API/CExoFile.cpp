#include "CExoFile.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoFileInternal.hpp"

namespace NWNXLib {

namespace API {

CExoFile::CExoFile(const CExoString& a0, uint16_t a1, const CExoString& a2)
{
    CExoFile__CExoFileCtor__0(this, a0, a1, a2);
}

CExoFile::~CExoFile()
{
    CExoFile__CExoFileDtor__0(this);
}

int32_t CExoFile::Eof()
{
    return CExoFile__Eof(this);
}

int32_t CExoFile::FileOpened()
{
    return CExoFile__FileOpened(this);
}

int32_t CExoFile::Flush()
{
    return CExoFile__Flush(this);
}

uint32_t CExoFile::GetOffset()
{
    return CExoFile__GetOffset(this);
}

int32_t CExoFile::GetSize()
{
    return CExoFile__GetSize(this);
}

uint32_t CExoFile::Read(CExoString& a0, uint32_t a1)
{
    return CExoFile__Read__0(this, a0, a1);
}

uint32_t CExoFile::Read(void* a0, uint32_t a1, uint32_t a2)
{
    return CExoFile__Read__1(this, a0, a1, a2);
}

void CExoFile::ReadAsync(void* a0, uint32_t a1, uint32_t a2)
{
    return CExoFile__ReadAsync(this, a0, a1, a2);
}

uint32_t CExoFile::ReadAsyncBytesRead()
{
    return CExoFile__ReadAsyncBytesRead(this);
}

int32_t CExoFile::ReadAsyncComplete()
{
    return CExoFile__ReadAsyncComplete(this);
}

int32_t CExoFile::ReadStringLineFromBuffer(unsigned char** a0, uint32_t* a1, unsigned char* a2, uint32_t a3)
{
    return CExoFile__ReadStringLineFromBuffer(a0, a1, a2, a3);
}

int32_t CExoFile::Seek(int32_t a0, int32_t a1)
{
    return CExoFile__Seek(this, a0, a1);
}

int32_t CExoFile::SeekBeginning()
{
    return CExoFile__SeekBeginning(this);
}

int32_t CExoFile::SeekEnd()
{
    return CExoFile__SeekEnd(this);
}

uint32_t CExoFile::Write(const CExoString& a0)
{
    return CExoFile__Write__0(this, a0);
}

uint32_t CExoFile::Write(const char* a0)
{
    return CExoFile__Write__1(this, a0);
}

uint32_t CExoFile::Write(const void* a0, uint32_t a1, uint32_t a2)
{
    return CExoFile__Write__2(this, a0, a1, a2);
}

void CExoFile__CExoFileCtor__0(CExoFile* thisPtr, const CExoString& a0, uint16_t a1, const CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFile*, const CExoString&, uint16_t, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__CExoFileCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2);
}

void CExoFile__CExoFileDtor__0(CExoFile* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFile*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__CExoFileDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CExoFile__Eof(CExoFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__Eof);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoFile__FileOpened(CExoFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__FileOpened);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoFile__Flush(CExoFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__Flush);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CExoFile__GetOffset(CExoFile* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__GetOffset);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoFile__GetSize(CExoFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__GetSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CExoFile__Read__0(CExoFile* thisPtr, CExoString& a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoFile*, CExoString&, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__Read__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CExoFile__Read__1(CExoFile* thisPtr, void* a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoFile*, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__Read__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CExoFile__ReadAsync(CExoFile* thisPtr, void* a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFile*, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__ReadAsync);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CExoFile__ReadAsyncBytesRead(CExoFile* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__ReadAsyncBytesRead);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoFile__ReadAsyncComplete(CExoFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__ReadAsyncComplete);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoFile__ReadStringLineFromBuffer(unsigned char** a0, uint32_t* a1, unsigned char* a2, uint32_t a3)
{
    using FuncPtrType = int32_t(*)(unsigned char**, uint32_t*, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__ReadStringLineFromBuffer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0, a1, a2, a3);
}

int32_t CExoFile__Seek(CExoFile* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFile*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__Seek);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoFile__SeekBeginning(CExoFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__SeekBeginning);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoFile__SeekEnd(CExoFile* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__SeekEnd);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CExoFile__Write__0(CExoFile* thisPtr, const CExoString& a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoFile*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__Write__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CExoFile__Write__1(CExoFile* thisPtr, const char* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoFile*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__Write__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CExoFile__Write__2(CExoFile* thisPtr, const void* a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoFile*, const void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFile__Write__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

}

}
