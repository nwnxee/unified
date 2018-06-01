#include "CExoArrayListTemplatedMaterialShaderParam.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "MaterialShaderParam.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedMaterialShaderParam& CExoArrayListTemplatedMaterialShaderParam::operator=(const CExoArrayListTemplatedMaterialShaderParam& a0)
{
    return CExoArrayListTemplatedMaterialShaderParam__OperatorAssignment(this, a0);
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
