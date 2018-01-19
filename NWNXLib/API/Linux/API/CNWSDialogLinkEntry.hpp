#pragma once

#include <cstdint>

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

struct CNWSDialogLinkEntry
{
    CResRef m_sActive;
    uint32_t m_nIndex;
};

}

}
