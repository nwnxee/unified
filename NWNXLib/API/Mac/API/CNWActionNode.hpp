#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

struct CNWActionNode
{
    uint16_t nGroupId;
    uint16_t nActionId;
    uint16_t nSpecialAttackId;
    uint32_t nSpellId;
    Vector vTargetPos;
    uint32_t oidTarget;
};

}

}
