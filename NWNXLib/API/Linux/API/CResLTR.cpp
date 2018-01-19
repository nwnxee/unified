#include "CResLTR.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "ExoLTRHeader_st.hpp"

namespace NWNXLib {

namespace API {

CResLTR::CResLTR()
{
    CResLTR__CResLTRCtor(this);
}

CResLTR::~CResLTR()
{
    CResLTR__CResLTRDtor__0(this);
}

int32_t CResLTR::OnResourceFreed()
{
    return CResLTR__OnResourceFreed(this);
}

int32_t CResLTR::OnResourceServiced()
{
    return CResLTR__OnResourceServiced(this);
}

void CResLTR__CResLTRCtor(CResLTR* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResLTR*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResLTR__CResLTRCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CResLTR__CResLTRDtor__0(CResLTR* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResLTR*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResLTR__CResLTRDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CResLTR__OnResourceFreed(CResLTR* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResLTR*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResLTR__OnResourceFreed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResLTR__OnResourceServiced(CResLTR* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResLTR*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResLTR__OnResourceServiced);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
