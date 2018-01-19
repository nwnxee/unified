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
};

}

}
