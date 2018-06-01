#include "CExoArrayListTemplatedMaterialShaderParam.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedMaterialShaderParam::Add(MaterialShaderParam a0)
{
    return CExoArrayListTemplatedMaterialShaderParam__Add(this, a0);
}

void CExoArrayListTemplatedMaterialShaderParam::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedMaterialShaderParam__Allocate(this, a0);
}

void CExoArrayListTemplatedMaterialShaderParam__Add(CExoArrayListTemplatedMaterialShaderParam* thisPtr, MaterialShaderParam a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedMaterialShaderParam*, MaterialShaderParam);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedMaterialShaderParam__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoArrayListTemplatedMaterialShaderParam__Allocate(CExoArrayListTemplatedMaterialShaderParam* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedMaterialShaderParam*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedMaterialShaderParam__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
