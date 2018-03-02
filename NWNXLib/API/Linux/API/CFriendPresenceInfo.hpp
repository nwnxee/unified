#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CExtendedServerInfo.hpp"

namespace NWNXLib {

namespace API {

struct CFriendPresenceInfo
    : CExtendedServerInfo
{
    CExoString m_sFriendName;
    CExoString m_sServerName;
    CExoString m_sServerAddress;

    // The below are auto generated stubs.
    CFriendPresenceInfo() = default;
    CFriendPresenceInfo(const CFriendPresenceInfo&) = default;
    CFriendPresenceInfo& operator=(const CFriendPresenceInfo&) = default;

    ~CFriendPresenceInfo();
    void Decode(CExoString);
    static CExoString Encode(CExtendedServerInfo*);
};

void CFriendPresenceInfo__CFriendPresenceInfoDtor(CFriendPresenceInfo* thisPtr);
void CFriendPresenceInfo__Decode(CFriendPresenceInfo* thisPtr, CExoString);
CExoString CFriendPresenceInfo__Encode(CExtendedServerInfo*);

}

}
