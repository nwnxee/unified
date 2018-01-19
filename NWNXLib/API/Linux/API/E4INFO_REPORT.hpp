#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct DATA4LISTSt;
struct TAG4FILESt;

struct E4INFO_REPORT
{
    DATA4LISTSt* relateDataList;
    TAG4FILESt* tag;
};

}

}
