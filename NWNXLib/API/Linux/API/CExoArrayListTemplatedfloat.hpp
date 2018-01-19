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
    void Add(float);
    void Allocate(int32_t);
    void Insert(float, int32_t);
    void SetSize(int32_t);
};

void CExoArrayListTemplatedfloat__CExoArrayListTemplatedfloatDtor(CExoArrayListTemplatedfloat* thisPtr);
void CExoArrayListTemplatedfloat__Add(CExoArrayListTemplatedfloat* thisPtr, float);
void CExoArrayListTemplatedfloat__Allocate(CExoArrayListTemplatedfloat* thisPtr, int32_t);
void CExoArrayListTemplatedfloat__Insert(CExoArrayListTemplatedfloat* thisPtr, float, int32_t);
void CExoArrayListTemplatedfloat__SetSize(CExoArrayListTemplatedfloat* thisPtr, int32_t);

}

}
