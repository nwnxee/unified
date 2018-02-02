#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResRef;

struct CResHelperTemplatedCResIFO2014
{

    // The below are auto generated stubs.
    CResHelperTemplatedCResIFO2014() = default;
    CResHelperTemplatedCResIFO2014(const CResHelperTemplatedCResIFO2014&) = default;
    CResHelperTemplatedCResIFO2014& operator=(const CResHelperTemplatedCResIFO2014&) = default;

    ~CResHelperTemplatedCResIFO2014();
    void SetResRef(const CResRef&, int32_t);
};

void CResHelperTemplatedCResIFO2014__CResHelperTemplatedCResIFO2014Dtor__0(CResHelperTemplatedCResIFO2014* thisPtr);
void CResHelperTemplatedCResIFO2014__SetResRef(CResHelperTemplatedCResIFO2014* thisPtr, const CResRef&, int32_t);

}

}
