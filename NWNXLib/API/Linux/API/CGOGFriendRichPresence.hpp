#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CGOGFriendRichPresence
{
    uint64_t m_galaxyRealId;
    CExoString m_friendName;
    CExoString m_address;
    CExoString m_serverName;
    CExoString m_moduleName;
    int32_t m_passwordRequired;
};

}

}
