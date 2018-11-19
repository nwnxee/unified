#include "CExoArrayListTemplatedMaterialShaderParam.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "MaterialShaderParam.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedMaterialShaderParam::~CExoArrayListTemplatedMaterialShaderParam()
{
    CExoArrayListTemplatedMaterialShaderParam__CExoArrayListTemplatedMaterialShaderParamDtor(this);
}

CExoArrayListTemplatedMaterialShaderParam& CExoArrayListTemplatedMaterialShaderParam::operator=(const CExoArrayListTemplatedMaterialShaderParam& a0)
{
    return CExoArrayListTemplatedMaterialShaderParam__OperatorAssignment(this, a0);
}

void CExoArrayListTemplatedMaterialShaderParam__CExoArrayListTemplatedMaterialShaderParamDtor(CExoArrayListTemplatedMaterialShaderParam* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedMaterialShaderParam*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedMaterialShaderParam__CExoArrayListTemplatedMaterialShaderParamDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CExoArrayListTemplatedMaterialShaderParam& CExoArrayListTemplatedMaterialShaderParam__OperatorAssignment(CExoArrayListTemplatedMaterialShaderParam* thisPtr, const CExoArrayListTemplatedMaterialShaderParam& a0)
{
    using FuncPtrType = CExoArrayListTemplatedMaterialShaderParam&(__attribute__((cdecl)) *)(CExoArrayListTemplatedMaterialShaderParam*, const CExoArrayListTemplatedMaterialShaderParam&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedMaterialShaderParam__OperatorAssignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
