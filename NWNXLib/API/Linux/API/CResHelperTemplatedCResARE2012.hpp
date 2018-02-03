#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResRef;

struct CResHelperTemplatedCResARE2012
{

    // The below are auto generated stubs.
    CResHelperTemplatedCResARE2012() = default;
    CResHelperTemplatedCResARE2012(const CResHelperTemplatedCResARE2012&) = default;
    CResHelperTemplatedCResARE2012& operator=(const CResHelperTemplatedCResARE2012&) = default;

    ~CResHelperTemplatedCResARE2012();
    void SetResRef(const CResRef&, int32_t);
};

void CResHelperTemplatedCResARE2012__CResHelperTemplatedCResARE2012Dtor__0(CResHelperTemplatedCResARE2012* thisPtr);
void CResHelperTemplatedCResARE2012__SetResRef(CResHelperTemplatedCResARE2012* thisPtr, const CResRef&, int32_t);

}

}
