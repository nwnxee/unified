#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResRef;

struct CResHelperTemplatedCRes2DA2017
{

    // The below are auto generated stubs.
    CResHelperTemplatedCRes2DA2017(const CResHelperTemplatedCRes2DA2017&) = default;
    CResHelperTemplatedCRes2DA2017& operator=(const CResHelperTemplatedCRes2DA2017&) = default;

    CResHelperTemplatedCRes2DA2017();
    ~CResHelperTemplatedCRes2DA2017();
    void SetResRef(const CResRef&, int32_t);
};

void CResHelperTemplatedCRes2DA2017__CResHelperTemplatedCRes2DA2017Ctor(CResHelperTemplatedCRes2DA2017* thisPtr);
void CResHelperTemplatedCRes2DA2017__CResHelperTemplatedCRes2DA2017Dtor__0(CResHelperTemplatedCRes2DA2017* thisPtr);
void CResHelperTemplatedCRes2DA2017__SetResRef(CResHelperTemplatedCRes2DA2017* thisPtr, const CResRef&, int32_t);

}

}
