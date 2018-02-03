#include "CERFRes.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoFile.hpp"

namespace NWNXLib {

namespace API {

CERFRes::CERFRes()
{
    CERFRes__CERFResCtor__0(this);
}

CERFRes::~CERFRes()
{
    CERFRes__CERFResDtor__0(this);
}

int32_t CERFRes::Read()
{
    return CERFRes__Read(this);
}

int32_t CERFRes::Reset()
{
    return CERFRes__Reset(this);
}

int32_t CERFRes::Write(CExoFile& a0, uint32_t a1)
{
    return CERFRes__Write(this, a0, a1);
}

void CERFRes__CERFResCtor__0(CERFRes* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CERFRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFRes__CERFResCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CERFRes__CERFResDtor__0(CERFRes* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CERFRes*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFRes__CERFResDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CERFRes__Read(CERFRes* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFRes__Read);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CERFRes__Reset(CERFRes* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFRes__Reset);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CERFRes__Write(CERFRes* thisPtr, CExoFile& a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CERFRes*, CExoFile&, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CERFRes__Write);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
