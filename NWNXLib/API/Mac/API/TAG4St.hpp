#pragma once

#include <cstdint>

#include "LIST4.hpp"
#include "l4linkSt.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct INDEX4St;
struct TAG4FILESt;

struct TAG4St
{
    l4linkSt link;
    INDEX4St* index;
    TAG4FILESt* tagFile;
    int16_t errUnique;
    int32_t isValid;
    LIST4 removedKeys;
    int32_t added;
    int32_t removed;
};

}

}
