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

    CExoArrayListTemplatedMaterialShaderParam& operator=(const CExoArrayListTemplatedMaterialShaderParam&);
};

CExoArrayListTemplatedMaterialShaderParam& CExoArrayListTemplatedMaterialShaderParam__OperatorAssignment(CExoArrayListTemplatedMaterialShaderParam* thisPtr, const CExoArrayListTemplatedMaterialShaderParam&);

}

}
