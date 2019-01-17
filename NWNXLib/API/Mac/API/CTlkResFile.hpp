#pragma once

#include <cstdint>

#include "CResHelperTemplatedCResTLK2018u.hpp"
#include "CTlkFile.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResRef;

struct CTlkResFile
    : CResHelperTemplatedCResTLK2018u, CTlkFile
{

    // The below are auto generated stubs.
    CTlkResFile() = default;
    CTlkResFile(const CTlkResFile&) = default;
    CTlkResFile& operator=(const CTlkResFile&) = default;

    CTlkResFile(const CResRef&);
    ~CTlkResFile();
};

void CTlkResFile__CTlkResFileCtor__0(CTlkResFile* thisPtr, const CResRef&);
void CTlkResFile__CTlkResFileDtor__0(CTlkResFile* thisPtr);

}

}
