#pragma once

#include <cstdint>

#include "CFileInfo.hpp"

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedCFileInfo
{
    CFileInfo* element;
    int32_t num;
    int32_t array_size;

    void Allocate(int32_t);
    void Insert(CFileInfo, int32_t);
};

void CExoArrayListTemplatedCFileInfo__Allocate(CExoArrayListTemplatedCFileInfo* thisPtr, int32_t);
void CExoArrayListTemplatedCFileInfo__Insert(CExoArrayListTemplatedCFileInfo* thisPtr, CFileInfo, int32_t);

}

}
