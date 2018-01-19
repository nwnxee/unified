#include "CRes2DA.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "Exo2DAHeader_st.hpp"

namespace NWNXLib {

namespace API {

CRes2DA::CRes2DA()
{
    CRes2DA__CRes2DACtor__0(this);
}

CRes2DA::~CRes2DA()
{
    CRes2DA__CRes2DADtor__0(this);
}

unsigned char* CRes2DA::Get2DADataPtr()
{
    return CRes2DA__Get2DADataPtr(this);
}

Exo2DAHeader_st* CRes2DA::Get2DAHeaderPtr()
{
    return CRes2DA__Get2DAHeaderPtr(this);
}

uint32_t CRes2DA::Get2DASize()
{
    return CRes2DA__Get2DASize(this);
}

int32_t CRes2DA::IsLoaded()
{
    return CRes2DA__IsLoaded(this);
}

int32_t CRes2DA::OnResourceFreed()
{
    return CRes2DA__OnResourceFreed(this);
}

int32_t CRes2DA::OnResourceServiced()
{
    return CRes2DA__OnResourceServiced(this);
}

void CRes2DA__CRes2DACtor__0(CRes2DA* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CRes2DA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes2DA__CRes2DACtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CRes2DA__CRes2DADtor__0(CRes2DA* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CRes2DA*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes2DA__CRes2DADtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

unsigned char* CRes2DA__Get2DADataPtr(CRes2DA* thisPtr)
{
    using FuncPtrType = unsigned char*(__attribute__((cdecl)) *)(CRes2DA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes2DA__Get2DADataPtr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

Exo2DAHeader_st* CRes2DA__Get2DAHeaderPtr(CRes2DA* thisPtr)
{
    using FuncPtrType = Exo2DAHeader_st*(__attribute__((cdecl)) *)(CRes2DA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes2DA__Get2DAHeaderPtr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CRes2DA__Get2DASize(CRes2DA* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CRes2DA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes2DA__Get2DASize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CRes2DA__IsLoaded(CRes2DA* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes2DA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes2DA__IsLoaded);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CRes2DA__OnResourceFreed(CRes2DA* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes2DA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes2DA__OnResourceFreed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CRes2DA__OnResourceServiced(CRes2DA* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CRes2DA*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CRes2DA__OnResourceServiced);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
