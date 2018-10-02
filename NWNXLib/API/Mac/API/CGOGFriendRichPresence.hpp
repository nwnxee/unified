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

    // The below are auto generated stubs.
    CGOGFriendRichPresence(const CGOGFriendRichPresence&) = default;
    CGOGFriendRichPresence& operator=(const CGOGFriendRichPresence&) = default;

    CGOGFriendRichPresence();
    ~CGOGFriendRichPresence();
};

void CGOGFriendRichPresence__CGOGFriendRichPresenceCtor(CGOGFriendRichPresence* thisPtr);
void CGOGFriendRichPresence__CGOGFriendRichPresenceDtor(CGOGFriendRichPresence* thisPtr);

}

}
