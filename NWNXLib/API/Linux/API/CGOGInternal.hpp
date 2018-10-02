#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCGOGFriendRichPresencePtr.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CGOGInternal
{
    void** m_vtable;
    CExoArrayListTemplatedCGOGFriendRichPresencePtr m_friendList;

    // The below are auto generated stubs.
    CGOGInternal() = default;
    CGOGInternal(const CGOGInternal&) = default;
    CGOGInternal& operator=(const CGOGInternal&) = default;

    ~CGOGInternal();
    void ClearPresenceData();
    CExoArrayListTemplatedCGOGFriendRichPresencePtr& GetFriendList();
    CExoString GetLanguage();
    int32_t IsLoggedOn();
    void RequestFriendsUpdate();
    void SetConnectedToModuleName(const CExoString&);
    void SetConnectedToServerAddress(const CExoString&, int32_t);
    void SetConnectedToServerName(const CExoString&);
    const char* ShowInviteOverlay();
    void Update(float);
};

void CGOGInternal__CGOGInternalDtor__0(CGOGInternal* thisPtr);
void CGOGInternal__ClearPresenceData(CGOGInternal* thisPtr);
CExoArrayListTemplatedCGOGFriendRichPresencePtr& CGOGInternal__GetFriendList(CGOGInternal* thisPtr);
CExoString CGOGInternal__GetLanguage(CGOGInternal* thisPtr);
int32_t CGOGInternal__IsLoggedOn(CGOGInternal* thisPtr);
void CGOGInternal__RequestFriendsUpdate(CGOGInternal* thisPtr);
void CGOGInternal__SetConnectedToModuleName(CGOGInternal* thisPtr, const CExoString&);
void CGOGInternal__SetConnectedToServerAddress(CGOGInternal* thisPtr, const CExoString&, int32_t);
void CGOGInternal__SetConnectedToServerName(CGOGInternal* thisPtr, const CExoString&);
const char* CGOGInternal__ShowInviteOverlay(CGOGInternal* thisPtr);
void CGOGInternal__Update(CGOGInternal* thisPtr, float);

}

}
