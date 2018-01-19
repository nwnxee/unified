#include "CExoIniInternal.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoIniInternal::CExoIniInternal(CExoString a0)
{
    CExoIniInternal__CExoIniInternalCtor__0(this, a0);
}

CExoIniInternal::~CExoIniInternal()
{
    CExoIniInternal__CExoIniInternalDtor__0(this);
}

int32_t CExoIniInternal::ReadIniEntry(CExoString& a0, const int32_t& a1, const CExoString& a2, const CExoString& a3)
{
    return CExoIniInternal__ReadIniEntry(this, a0, a1, a2, a3);
}

int32_t CExoIniInternal::WriteIniEntry(const CExoString& a0, const int32_t& a1, const CExoString& a2, const CExoString& a3)
{
    return CExoIniInternal__WriteIniEntry(this, a0, a1, a2, a3);
}

void CExoIniInternal__CExoIniInternalCtor__0(CExoIniInternal* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoIniInternal*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoIniInternal__CExoIniInternalCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CExoIniInternal__CExoIniInternalDtor__0(CExoIniInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoIniInternal*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoIniInternal__CExoIniInternalDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CExoIniInternal__ReadIniEntry(CExoIniInternal* thisPtr, CExoString& a0, const int32_t& a1, const CExoString& a2, const CExoString& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoIniInternal*, CExoString&, const int32_t&, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoIniInternal__ReadIniEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CExoIniInternal__WriteIniEntry(CExoIniInternal* thisPtr, const CExoString& a0, const int32_t& a1, const CExoString& a2, const CExoString& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoIniInternal*, const CExoString&, const int32_t&, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoIniInternal__WriteIniEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

}

}
