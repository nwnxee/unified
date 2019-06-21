#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoString;

struct CExoArrayListTemplatedCExoStringPtr
{
    CExoString** element;
    int32_t num;
    int32_t array_size;

    // The below are auto generated stubs.
    CExoArrayListTemplatedCExoStringPtr() = default;
    CExoArrayListTemplatedCExoStringPtr(const CExoArrayListTemplatedCExoStringPtr&) = default;
    CExoArrayListTemplatedCExoStringPtr& operator=(const CExoArrayListTemplatedCExoStringPtr&) = default;

    ~CExoArrayListTemplatedCExoStringPtr();
};

void CExoArrayListTemplatedCExoStringPtr__CExoArrayListTemplatedCExoStringPtrDtor(CExoArrayListTemplatedCExoStringPtr* thisPtr);

}

}
