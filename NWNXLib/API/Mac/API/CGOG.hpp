#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoArrayListTemplatedCGOGFriendRichPresencePtr;
struct CGOGInternal;

struct CGOG
{
    CGOGInternal* m_internal;

    // The below are auto generated stubs.
    CGOG(const CGOG&) = default;
    CGOG& operator=(const CGOG&) = default;

    CGOG();
    ~CGOG();
    void ClearAchievement(const CExoString&);
    void ClearPresenceData();
    CExoArrayListTemplatedCGOGFriendRichPresencePtr& GetFriendList();
    CExoString GetLanguage();
    void IncrementAchievement(const CExoString&, uint32_t, uint32_t);
    int32_t IsLoggedOn();
    void RequestFriendsUpdate();
    void SetConnectedToModuleName(const CExoString&);
    void SetConnectedToServerAddress(const CExoString&, int32_t);
    void SetConnectedToServerName(const CExoString&);
    const char* ShowInviteOverlay();
    void UnlockAchievement(const CExoString&);
    void Update(float);
};

void CGOG__CGOGCtor__0(CGOG* thisPtr);
void CGOG__CGOGDtor__0(CGOG* thisPtr);
void CGOG__ClearAchievement(CGOG* thisPtr, const CExoString&);
void CGOG__ClearPresenceData(CGOG* thisPtr);
CExoArrayListTemplatedCGOGFriendRichPresencePtr& CGOG__GetFriendList(CGOG* thisPtr);
CExoString CGOG__GetLanguage(CGOG* thisPtr);
void CGOG__IncrementAchievement(CGOG* thisPtr, const CExoString&, uint32_t, uint32_t);
int32_t CGOG__IsLoggedOn(CGOG* thisPtr);
void CGOG__RequestFriendsUpdate(CGOG* thisPtr);
void CGOG__SetConnectedToModuleName(CGOG* thisPtr, const CExoString&);
void CGOG__SetConnectedToServerAddress(CGOG* thisPtr, const CExoString&, int32_t);
void CGOG__SetConnectedToServerName(CGOG* thisPtr, const CExoString&);
const char* CGOG__ShowInviteOverlay(CGOG* thisPtr);
void CGOG__UnlockAchievement(CGOG* thisPtr, const CExoString&);
void CGOG__Update(CGOG* thisPtr, float);

}

}
