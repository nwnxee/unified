#include "CExoIni.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoIniInternal.hpp"

namespace NWNXLib {

namespace API {

CExoIni::CExoIni(CExoString a0)
{
    CExoIni__CExoIniCtor__0(this, a0);
}

CExoIni::~CExoIni()
{
    CExoIni__CExoIniDtor__0(this);
}

int32_t CExoIni::ReadIniEntry(CExoString& a0, const int32_t& a1, const CExoString& a2, const CExoString& a3)
{
    return CExoIni__ReadIniEntry(this, a0, a1, a2, a3);
}

int32_t CExoIni::WriteIniEntry(const CExoString& a0, const int32_t& a1, const CExoString& a2, const CExoString& a3)
{
    return CExoIni__WriteIniEntry(this, a0, a1, a2, a3);
}

void CExoIni__CExoIniCtor__0(CExoIni* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoIni*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoIni__CExoIniCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CExoIni__CExoIniDtor__0(CExoIni* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoIni*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoIni__CExoIniDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CExoIni__ReadIniEntry(CExoIni* thisPtr, CExoString& a0, const int32_t& a1, const CExoString& a2, const CExoString& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoIni*, CExoString&, const int32_t&, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoIni__ReadIniEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CExoIni__WriteIniEntry(CExoIni* thisPtr, const CExoString& a0, const int32_t& a1, const CExoString& a2, const CExoString& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoIni*, const CExoString&, const int32_t&, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoIni__WriteIniEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

}

}
