#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedint
{
    int32_t* element;
    int32_t num;
    int32_t array_size;

    void Add(int32_t);
    void Allocate(int32_t);
    void SetSize(int32_t);
};

void CExoArrayListTemplatedint__Add(CExoArrayListTemplatedint* thisPtr, int32_t);
void CExoArrayListTemplatedint__Allocate(CExoArrayListTemplatedint* thisPtr, int32_t);
void CExoArrayListTemplatedint__SetSize(CExoArrayListTemplatedint* thisPtr, int32_t);

}

}
