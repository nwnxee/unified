#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CResetOption
{
    int32_t bOnVacant;
    int32_t bOnVictory;
    int32_t bOnFailure;
    int32_t bOnDeath;
    int32_t bOnPartyDeath;
};

}

}
