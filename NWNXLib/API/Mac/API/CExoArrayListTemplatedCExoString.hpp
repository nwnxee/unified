#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedCExoString
{
    CExoString* element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    CExoArrayListTemplatedCExoString() = default;
    CExoArrayListTemplatedCExoString(const CExoArrayListTemplatedCExoString&) = default;

    ~CExoArrayListTemplatedCExoString();
    int32_t AddUnique(CExoString);
    void Allocate(int32_t);
    void Insert(CExoString, int32_t);
    CExoArrayListTemplatedCExoString& operator=(const CExoArrayListTemplatedCExoString&);
};

void CExoArrayListTemplatedCExoString__CExoArrayListTemplatedCExoStringDtor(CExoArrayListTemplatedCExoString* thisPtr);
int32_t CExoArrayListTemplatedCExoString__AddUnique(CExoArrayListTemplatedCExoString* thisPtr, CExoString);
void CExoArrayListTemplatedCExoString__Allocate(CExoArrayListTemplatedCExoString* thisPtr, int32_t);
void CExoArrayListTemplatedCExoString__Insert(CExoArrayListTemplatedCExoString* thisPtr, CExoString, int32_t);
CExoArrayListTemplatedCExoString& CExoArrayListTemplatedCExoString__OperatorAssignment(CExoArrayListTemplatedCExoString* thisPtr, const CExoArrayListTemplatedCExoString&);

}

}
