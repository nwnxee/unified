#pragma once

#include <cstdint>

#include "unknown_CHATBool.hpp"

namespace NWNXLib {

namespace API {

struct CHATChannelMode
{
    CHATBool InviteOnly;
    CHATBool Private;
    CHATBool Secret;
    CHATBool Moderated;
    CHATBool NoExternalMessages;
    CHATBool OnlyOpsChangeTopic;
    int32_t Limit;
};

}

}
