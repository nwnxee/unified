#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

struct CNWSDialogLinkReply
{
    CResRef m_sActive;
    uint32_t m_nIndex;
    int32_t m_bDisplayInactive;
};

}

}
