#pragma once

#include <cstdint>

#include "MaterialShaderParam.hpp"

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedMaterialShaderParam
{
    MaterialShaderParam* element;
    int32_t num;
    int32_t array_size;

    void Add(MaterialShaderParam);
    void Allocate(int32_t);
};

void CExoArrayListTemplatedMaterialShaderParam__Add(CExoArrayListTemplatedMaterialShaderParam* thisPtr, MaterialShaderParam);
void CExoArrayListTemplatedMaterialShaderParam__Allocate(CExoArrayListTemplatedMaterialShaderParam* thisPtr, int32_t);

}

}
