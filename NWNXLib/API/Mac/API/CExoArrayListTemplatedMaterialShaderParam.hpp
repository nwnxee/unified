#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct MaterialShaderParam;

struct CExoArrayListTemplatedMaterialShaderParam
{
    MaterialShaderParam* element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    CExoArrayListTemplatedMaterialShaderParam() = default;
    CExoArrayListTemplatedMaterialShaderParam(const CExoArrayListTemplatedMaterialShaderParam&) = default;

    ~CExoArrayListTemplatedMaterialShaderParam();
    CExoArrayListTemplatedMaterialShaderParam& operator=(const CExoArrayListTemplatedMaterialShaderParam&);
};

void CExoArrayListTemplatedMaterialShaderParam__CExoArrayListTemplatedMaterialShaderParamDtor(CExoArrayListTemplatedMaterialShaderParam* thisPtr);
CExoArrayListTemplatedMaterialShaderParam& CExoArrayListTemplatedMaterialShaderParam__OperatorAssignment(CExoArrayListTemplatedMaterialShaderParam* thisPtr, const CExoArrayListTemplatedMaterialShaderParam&);

}

}
