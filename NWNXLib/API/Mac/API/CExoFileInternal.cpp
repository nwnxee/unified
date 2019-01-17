#include "CExoFileInternal.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoFileInternal::CExoFileInternal(const CExoString& a0, const CExoString& a1)
{
    CExoFileInternal__CExoFileInternalCtor__0(this, a0, a1);
}

CExoFileInternal::CExoFileInternal(const void* a0, int32_t a1)
{
    CExoFileInternal__CExoFileInternalCtor__2(this, a0, a1);
}

CExoFileInternal::CExoFileInternal(const CExoString& a0, uint16_t a1, const CExoString& a2)
{
    CExoFileInternal__CExoFileInternalCtor__4(this, a0, a1, a2);
}

CExoFileInternal::~CExoFileInternal()
{
    CExoFileInternal__CExoFileInternalDtor__0(this);
}

int32_t CExoFileInternal::Eof()
{
    return CExoFileInternal__Eof(this);
}

int32_t CExoFileInternal::FileOpened()
{
    return CExoFileInternal__FileOpened(this);
}

int32_t CExoFileInternal::Flush()
{
    return CExoFileInternal__Flush(this);
}

uint32_t CExoFileInternal::GetOffset()
{
    return CExoFileInternal__GetOffset(this);
}

int32_t CExoFileInternal::GetSize()
{
    return CExoFileInternal__GetSize(this);
}

int32_t CExoFileInternal::IsMemoryBacked()
{
    return CExoFileInternal__IsMemoryBacked(this);
}

uint32_t CExoFileInternal::Read(CExoString* a0, uint32_t a1)
{
    return CExoFileInternal__Read__0(this, a0, a1);
}

uint32_t CExoFileInternal::Read(void* a0, uint32_t a1, uint32_t a2)
{
    return CExoFileInternal__Read__1(this, a0, a1, a2);
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

int32_t CExoFileInternal::Seek(int32_t a0, int32_t a1)
{
    return CExoFileInternal__Seek(this, a0, a1);
}

int32_t CExoFileInternal::SeekBeginning()
{
    return CExoFileInternal__SeekBeginning(this);
}

int32_t CExoFileInternal::SeekEnd()
{
    return CExoFileInternal__SeekEnd(this);
}

void CExoFileInternal::SetMemoryBuffer(const void* a0, int32_t a1)
{
    return CExoFileInternal__SetMemoryBuffer(this, a0, a1);
}

uint32_t CExoFileInternal::Write(const char* a0)
{
    return CExoFileInternal__Write(this, a0);
}

void CExoFileInternal__CExoFileInternalCtor__0(CExoFileInternal* thisPtr, const CExoString& a0, const CExoString& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileInternal*, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__CExoFileInternalCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1);
}

void CExoFileInternal__CExoFileInternalCtor__2(CExoFileInternal* thisPtr, const void* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileInternal*, const void*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__CExoFileInternalCtor__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1);
}

void CExoFileInternal__CExoFileInternalCtor__4(CExoFileInternal* thisPtr, const CExoString& a0, uint16_t a1, const CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileInternal*, const CExoString&, uint16_t, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__CExoFileInternalCtor__4);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2);
}

void CExoFileInternal__CExoFileInternalDtor__0(CExoFileInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileInternal*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__CExoFileInternalDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CExoFileInternal__Eof(CExoFileInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFileInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__Eof);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoFileInternal__FileOpened(CExoFileInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFileInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__FileOpened);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoFileInternal__Flush(CExoFileInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFileInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__Flush);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
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

int32_t CExoFileInternal__IsMemoryBacked(CExoFileInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFileInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__IsMemoryBacked);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CExoFileInternal__Read__0(CExoFileInternal* thisPtr, CExoString* a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoFileInternal*, CExoString*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__Read__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CExoFileInternal__Read__1(CExoFileInternal* thisPtr, void* a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoFileInternal*, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__Read__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
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

int32_t CExoFileInternal__Seek(CExoFileInternal* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFileInternal*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__Seek);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoFileInternal__SeekBeginning(CExoFileInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFileInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__SeekBeginning);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoFileInternal__SeekEnd(CExoFileInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoFileInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__SeekEnd);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoFileInternal__SetMemoryBuffer(CExoFileInternal* thisPtr, const void* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoFileInternal*, const void*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__SetMemoryBuffer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CExoFileInternal__Write(CExoFileInternal* thisPtr, const char* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoFileInternal*, const char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoFileInternal__Write);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
