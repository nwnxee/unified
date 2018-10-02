#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CGOGFriendRichPresence;

struct CGOGInternalImpl
{

    // The below are auto generated stubs.
    CGOGInternalImpl(const CGOGInternalImpl&) = default;
    CGOGInternalImpl& operator=(const CGOGInternalImpl&) = default;

    CGOGInternalImpl();
    ~CGOGInternalImpl();
    void ClearPresenceData();
    CExoString GetLanguage();
    int32_t IsLoggedOn();
    void OnAuthLost();
    void OnAuthSuccess();
    void OnFriendListRetrieveSuccess();
    void OnNotificationReceived(uint64_t, uint32_t, uint32_t);
    void OnOperationalStateChanged(uint32_t);
    void OnOverlayVisibilityChanged(int32_t);
    void OnRichPresenceChangeSuccess();
    CExoString PackMetadata(const CGOGFriendRichPresence&);
    void RequestFriendsUpdate();
    void SetConnectedToModuleName(const CExoString&);
    void SetConnectedToServerAddress(const CExoString&, int32_t);
    void SetConnectedToServerName(const CExoString&);
    const char* ShowInviteOverlay();
    int32_t UnpackMetadata(const CExoString&, CGOGFriendRichPresence*);
    void Update(float);
};

void CGOGInternalImpl__CGOGInternalImplCtor(CGOGInternalImpl* thisPtr);
void CGOGInternalImpl__CGOGInternalImplDtor__0(CGOGInternalImpl* thisPtr);
void CGOGInternalImpl__ClearPresenceData(CGOGInternalImpl* thisPtr);
CExoString CGOGInternalImpl__GetLanguage(CGOGInternalImpl* thisPtr);
int32_t CGOGInternalImpl__IsLoggedOn(CGOGInternalImpl* thisPtr);
void CGOGInternalImpl__OnAuthLost(CGOGInternalImpl* thisPtr);
void CGOGInternalImpl__OnAuthSuccess(CGOGInternalImpl* thisPtr);
void CGOGInternalImpl__OnFriendListRetrieveSuccess(CGOGInternalImpl* thisPtr);
void CGOGInternalImpl__OnNotificationReceived(CGOGInternalImpl* thisPtr, uint64_t, uint32_t, uint32_t);
void CGOGInternalImpl__OnOperationalStateChanged(CGOGInternalImpl* thisPtr, uint32_t);
void CGOGInternalImpl__OnOverlayVisibilityChanged(CGOGInternalImpl* thisPtr, int32_t);
void CGOGInternalImpl__OnRichPresenceChangeSuccess(CGOGInternalImpl* thisPtr);
CExoString CGOGInternalImpl__PackMetadata(CGOGInternalImpl* thisPtr, const CGOGFriendRichPresence&);
void CGOGInternalImpl__RequestFriendsUpdate(CGOGInternalImpl* thisPtr);
void CGOGInternalImpl__SetConnectedToModuleName(CGOGInternalImpl* thisPtr, const CExoString&);
void CGOGInternalImpl__SetConnectedToServerAddress(CGOGInternalImpl* thisPtr, const CExoString&, int32_t);
void CGOGInternalImpl__SetConnectedToServerName(CGOGInternalImpl* thisPtr, const CExoString&);
const char* CGOGInternalImpl__ShowInviteOverlay(CGOGInternalImpl* thisPtr);
int32_t CGOGInternalImpl__UnpackMetadata(CGOGInternalImpl* thisPtr, const CExoString&, CGOGFriendRichPresence*);
void CGOGInternalImpl__Update(CGOGInternalImpl* thisPtr, float);

}

}
