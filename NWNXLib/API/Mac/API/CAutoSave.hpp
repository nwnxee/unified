#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CAutoSave
{
    int32_t bAtIntervals;
    int32_t bAtSavePoints;
    int32_t bOnPlayerChange;
    int32_t nInterval;
};

}

}
