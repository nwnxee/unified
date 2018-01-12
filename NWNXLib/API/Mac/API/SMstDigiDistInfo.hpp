#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct MS_RSAPrivateKey;

struct SMstDigiDistInfo
{
    CExoArrayListTemplatedCExoString lstKeys;
    MS_RSAPrivateKey* pKey;
    uint8_t pbModuleDecryptCipher[41];

    // The below are auto generated stubs.
    SMstDigiDistInfo() = default;
    SMstDigiDistInfo(const SMstDigiDistInfo&) = default;
    SMstDigiDistInfo& operator=(const SMstDigiDistInfo&) = default;

    ~SMstDigiDistInfo();
};

void SMstDigiDistInfo__SMstDigiDistInfoDtor(SMstDigiDistInfo* thisPtr);

}

}
