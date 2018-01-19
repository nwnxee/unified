#include "CExoRandInternal.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoRandInternal::CExoRandInternal()
{
    CExoRandInternal__CExoRandInternalCtor(this);
}

CExoRandInternal::~CExoRandInternal()
{
    CExoRandInternal__CExoRandInternalDtor(this);
}

void CExoRandInternal::Add(unsigned char* a0, int32_t a1)
{
    return CExoRandInternal__Add(this, a0, a1);
}

void CExoRandInternal::GenSeed()
{
    return CExoRandInternal__GenSeed(this);
}

CExoString CExoRandInternal::GetString(uint16_t a0)
{
    return CExoRandInternal__GetString(this, a0);
}

uint32_t CExoRandInternal::Rand()
{
    return CExoRandInternal__Rand(this);
}

void CExoRandInternal::ReSeed(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    return CExoRandInternal__ReSeed(this, a0, a1, a2, a3);
}

void CExoRandInternal::SignalEvent()
{
    return CExoRandInternal__SignalEvent__0(this);
}

void CExoRandInternal::SignalEvent(uint32_t a0)
{
    return CExoRandInternal__SignalEvent__1(this, a0);
}

void CExoRandInternal__CExoRandInternalCtor(CExoRandInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoRandInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoRandInternal__CExoRandInternalCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoRandInternal__CExoRandInternalDtor(CExoRandInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoRandInternal*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoRandInternal__CExoRandInternalDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CExoRandInternal__Add(CExoRandInternal* thisPtr, unsigned char* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoRandInternal*, unsigned char*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoRandInternal__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CExoRandInternal__GenSeed(CExoRandInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoRandInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoRandInternal__GenSeed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CExoRandInternal__GetString(CExoRandInternal* thisPtr, uint16_t a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CExoRandInternal*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoRandInternal__GetString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CExoRandInternal__Rand(CExoRandInternal* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoRandInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoRandInternal__Rand);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoRandInternal__ReSeed(CExoRandInternal* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoRandInternal*, uint32_t, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoRandInternal__ReSeed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CExoRandInternal__SignalEvent__0(CExoRandInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoRandInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoRandInternal__SignalEvent__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoRandInternal__SignalEvent__1(CExoRandInternal* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoRandInternal*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoRandInternal__SignalEvent__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
