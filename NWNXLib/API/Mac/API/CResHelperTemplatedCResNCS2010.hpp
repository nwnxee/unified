#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResRef;

struct CResHelperTemplatedCResNCS2010
{

    // The below are auto generated stubs.
    CResHelperTemplatedCResNCS2010() = default;
    CResHelperTemplatedCResNCS2010(const CResHelperTemplatedCResNCS2010&) = default;
    CResHelperTemplatedCResNCS2010& operator=(const CResHelperTemplatedCResNCS2010&) = default;

    ~CResHelperTemplatedCResNCS2010();
    void SetResRef(const CResRef&, int32_t);
};

void CResHelperTemplatedCResNCS2010__CResHelperTemplatedCResNCS2010Dtor__0(CResHelperTemplatedCResNCS2010* thisPtr);
void CResHelperTemplatedCResNCS2010__SetResRef(CResHelperTemplatedCResNCS2010* thisPtr, const CResRef&, int32_t);

}

}
