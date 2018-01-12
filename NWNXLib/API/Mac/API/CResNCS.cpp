#include "CResNCS.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CResNCS::CResNCS()
{
    CResNCS__CResNCSCtor__0(this);
}

CResNCS::~CResNCS()
{
    CResNCS__CResNCSDtor__0(this);
}

unsigned char* CResNCS::GetNCSDataPtr()
{
    return CResNCS__GetNCSDataPtr(this);
}

uint32_t CResNCS::GetNCSSize()
{
    return CResNCS__GetNCSSize(this);
}

int32_t CResNCS::IsLoaded()
{
    return CResNCS__IsLoaded(this);
}

int32_t CResNCS::OnResourceFreed()
{
    return CResNCS__OnResourceFreed(this);
}

int32_t CResNCS::OnResourceServiced()
{
    return CResNCS__OnResourceServiced(this);
}

void CResNCS__CResNCSCtor__0(CResNCS* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResNCS*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNCS__CResNCSCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CResNCS__CResNCSDtor__0(CResNCS* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResNCS*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNCS__CResNCSDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

unsigned char* CResNCS__GetNCSDataPtr(CResNCS* thisPtr)
{
    using FuncPtrType = unsigned char*(__attribute__((cdecl)) *)(CResNCS*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNCS__GetNCSDataPtr);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CResNCS__GetNCSSize(CResNCS* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResNCS*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNCS__GetNCSSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResNCS__IsLoaded(CResNCS* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResNCS*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNCS__IsLoaded);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResNCS__OnResourceFreed(CResNCS* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResNCS*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNCS__OnResourceFreed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResNCS__OnResourceServiced(CResNCS* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResNCS*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResNCS__OnResourceServiced);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
