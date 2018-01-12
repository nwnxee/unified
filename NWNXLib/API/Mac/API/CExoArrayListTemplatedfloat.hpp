#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedfloat
{
    float* element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    CExoArrayListTemplatedfloat() = default;
    CExoArrayListTemplatedfloat(const CExoArrayListTemplatedfloat&) = default;
    CExoArrayListTemplatedfloat& operator=(const CExoArrayListTemplatedfloat&) = default;

    ~CExoArrayListTemplatedfloat();
};

void CExoArrayListTemplatedfloat__CExoArrayListTemplatedfloatDtor(CExoArrayListTemplatedfloat* thisPtr);

}

}
