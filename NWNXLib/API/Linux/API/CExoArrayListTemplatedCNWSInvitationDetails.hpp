#pragma once

#include <cstdint>

#include "CNWSInvitationDetails.hpp"

namespace NWNXLib {

namespace API {

struct CExoArrayListTemplatedCNWSInvitationDetails
{
    CNWSInvitationDetails* element;
    int32_t num;
    int32_t array_size;

    void Add(CNWSInvitationDetails);
};

void CExoArrayListTemplatedCNWSInvitationDetails__Add(CExoArrayListTemplatedCNWSInvitationDetails* thisPtr, CNWSInvitationDetails);

}

}
