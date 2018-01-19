#include "CExoCriticalSection.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoCriticalSectionInternal.hpp"

namespace NWNXLib {

namespace API {

CExoCriticalSection::CExoCriticalSection()
{
    CExoCriticalSection__CExoCriticalSectionCtor(this);
}

CExoCriticalSection::~CExoCriticalSection()
{
    CExoCriticalSection__CExoCriticalSectionDtor(this);
}

void CExoCriticalSection::EnterCriticalSection()
{
    return CExoCriticalSection__EnterCriticalSection(this);
}

void CExoCriticalSection::LeaveCriticalSection()
{
    return CExoCriticalSection__LeaveCriticalSection(this);
}

void CExoCriticalSection__CExoCriticalSectionCtor(CExoCriticalSection* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoCriticalSection*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoCriticalSection__CExoCriticalSectionCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoCriticalSection__CExoCriticalSectionDtor(CExoCriticalSection* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoCriticalSection*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoCriticalSection__CExoCriticalSectionDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CExoCriticalSection__EnterCriticalSection(CExoCriticalSection* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoCriticalSection*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoCriticalSection__EnterCriticalSection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoCriticalSection__LeaveCriticalSection(CExoCriticalSection* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoCriticalSection*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoCriticalSection__LeaveCriticalSection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
