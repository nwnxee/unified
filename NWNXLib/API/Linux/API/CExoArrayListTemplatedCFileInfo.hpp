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

    // The below are auto generated stubs.
    CExoArrayListTemplatedCFileInfo() = default;
    CExoArrayListTemplatedCFileInfo(const CExoArrayListTemplatedCFileInfo&) = default;
    CExoArrayListTemplatedCFileInfo& operator=(const CExoArrayListTemplatedCFileInfo&) = default;

    ~CExoArrayListTemplatedCFileInfo();
    void Add(CFileInfo);
    void Allocate(int32_t);
};

void CExoArrayListTemplatedCFileInfo__CExoArrayListTemplatedCFileInfoDtor(CExoArrayListTemplatedCFileInfo* thisPtr);
void CExoArrayListTemplatedCFileInfo__Add(CExoArrayListTemplatedCFileInfo* thisPtr, CFileInfo);
void CExoArrayListTemplatedCFileInfo__Allocate(CExoArrayListTemplatedCFileInfo* thisPtr, int32_t);

}

}
