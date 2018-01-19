#include "CExoArrayListTemplatedfloat.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedfloat::~CExoArrayListTemplatedfloat()
{
    CExoArrayListTemplatedfloat__CExoArrayListTemplatedfloatDtor(this);
}

void CExoArrayListTemplatedfloat::Add(float a0)
{
    return CExoArrayListTemplatedfloat__Add(this, a0);
}

void CExoArrayListTemplatedfloat::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedfloat__Allocate(this, a0);
}

void CExoArrayListTemplatedfloat::Insert(float a0, int32_t a1)
{
    return CExoArrayListTemplatedfloat__Insert(this, a0, a1);
}

void CExoArrayListTemplatedfloat::SetSize(int32_t a0)
{
    return CExoArrayListTemplatedfloat__SetSize(this, a0);
}

void CExoArrayListTemplatedfloat__CExoArrayListTemplatedfloatDtor(CExoArrayListTemplatedfloat* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedfloat*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedfloat__CExoArrayListTemplatedfloatDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CExoArrayListTemplatedfloat__Add(CExoArrayListTemplatedfloat* thisPtr, float a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedfloat*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedfloat__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoArrayListTemplatedfloat__Allocate(CExoArrayListTemplatedfloat* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedfloat*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedfloat__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoArrayListTemplatedfloat__Insert(CExoArrayListTemplatedfloat* thisPtr, float a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedfloat*, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedfloat__Insert);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CExoArrayListTemplatedfloat__SetSize(CExoArrayListTemplatedfloat* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedfloat*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedfloat__SetSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
