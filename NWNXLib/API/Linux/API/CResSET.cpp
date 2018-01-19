#include "CResSET.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "SETSection.hpp"

namespace NWNXLib {

namespace API {

CResSET::CResSET()
{
    CResSET__CResSETCtor(this);
}

CResSET::~CResSET()
{
    CResSET__CResSETDtor__0(this);
}

int32_t CResSET::CopySETData(unsigned char* a0)
{
    return CResSET__CopySETData(this, a0);
}

int32_t CResSET::CreateSectionTable()
{
    return CResSET__CreateSectionTable(this);
}

char* CResSET::GetNextLine(uint32_t a0, uint32_t* a1)
{
    return CResSET__GetNextLine(this, a0, a1);
}

void CResSET::GetSectionEntryValue(char* a0, char* a1, char* a2)
{
    return CResSET__GetSectionEntryValue(this, a0, a1, a2);
}

char* CResSET::GetSETDataPtr()
{
    return CResSET__GetSETDataPtr(this);
}

uint32_t CResSET::GetSETSize()
{
    return CResSET__GetSETSize(this);
}

int32_t CResSET::IsLoaded()
{
    return CResSET__IsLoaded(this);
}

int32_t CResSET::OnResourceFreed()
{
    return CResSET__OnResourceFreed(this);
}

int32_t CResSET::OnResourceServiced()
{
    return CResSET__OnResourceServiced(this);
}

char* CResSET::SkipWhiteSpace(char* a0)
{
    return CResSET__SkipWhiteSpace(this, a0);
}

void CResSET__CResSETCtor(CResSET* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResSET*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResSET__CResSETCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CResSET__CResSETDtor__0(CResSET* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResSET*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResSET__CResSETDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CResSET__CopySETData(CResSET* thisPtr, unsigned char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResSET*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResSET__CopySETData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResSET__CreateSectionTable(CResSET* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResSET*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResSET__CreateSectionTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char* CResSET__GetNextLine(CResSET* thisPtr, uint32_t a0, uint32_t* a1)
{
    using FuncPtrType = char*(__attribute__((cdecl)) *)(CResSET*, uint32_t, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResSET__GetNextLine);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CResSET__GetSectionEntryValue(CResSET* thisPtr, char* a0, char* a1, char* a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResSET*, char*, char*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResSET__GetSectionEntryValue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

char* CResSET__GetSETDataPtr(CResSET* thisPtr)
{
    using FuncPtrType = char*(__attribute__((cdecl)) *)(CResSET*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResSET__GetSETDataPtr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CResSET__GetSETSize(CResSET* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResSET*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResSET__GetSETSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResSET__IsLoaded(CResSET* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResSET*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResSET__IsLoaded);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResSET__OnResourceFreed(CResSET* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResSET*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResSET__OnResourceFreed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResSET__OnResourceServiced(CResSET* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResSET*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResSET__OnResourceServiced);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char* CResSET__SkipWhiteSpace(CResSET* thisPtr, char* a0)
{
    using FuncPtrType = char*(__attribute__((cdecl)) *)(CResSET*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResSET__SkipWhiteSpace);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
