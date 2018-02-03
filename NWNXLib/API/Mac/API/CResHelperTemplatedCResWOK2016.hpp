#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResRef;

struct CResHelperTemplatedCResWOK2016
{

    // The below are auto generated stubs.
    CResHelperTemplatedCResWOK2016() = default;
    CResHelperTemplatedCResWOK2016(const CResHelperTemplatedCResWOK2016&) = default;
    CResHelperTemplatedCResWOK2016& operator=(const CResHelperTemplatedCResWOK2016&) = default;

    ~CResHelperTemplatedCResWOK2016();
    void SetResRef(const CResRef&, int32_t);
};

void CResHelperTemplatedCResWOK2016__CResHelperTemplatedCResWOK2016Dtor__0(CResHelperTemplatedCResWOK2016* thisPtr);
void CResHelperTemplatedCResWOK2016__SetResRef(CResHelperTemplatedCResWOK2016* thisPtr, const CResRef&, int32_t);

}

}
