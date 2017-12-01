#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct HashImplementation;

struct piRemoveExistingKeysData
{
    int32_t num;
    const char** keys;
    HashImplementation* watchKeys;
};

}

}
