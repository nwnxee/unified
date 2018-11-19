#include "CGOG.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoArrayListTemplatedCGOGFriendRichPresencePtr.hpp"
#include "CGOGInternal.hpp"

namespace NWNXLib {

namespace API {

CGOG::CGOG()
{
    CGOG__CGOGCtor__0(this);
}

CGOG::~CGOG()
{
    CGOG__CGOGDtor__0(this);
}

void CGOG::ClearAchievement(const CExoString& a0)
{
    return CGOG__ClearAchievement(this, a0);
}

void CGOG::ClearPresenceData()
{
    return CGOG__ClearPresenceData(this);
}

CExoArrayListTemplatedCGOGFriendRichPresencePtr& CGOG::GetFriendList()
{
    return CGOG__GetFriendList(this);
}

CExoString CGOG::GetLanguage()
{
    return CGOG__GetLanguage(this);
}

void CGOG::IncrementAchievement(const CExoString& a0, uint32_t a1, uint32_t a2)
{
    return CGOG__IncrementAchievement(this, a0, a1, a2);
}

int32_t CGOG::IsLoggedOn()
{
    return CGOG__IsLoggedOn(this);
}

void CGOG::RequestFriendsUpdate()
{
    return CGOG__RequestFriendsUpdate(this);
}

void CGOG::SetConnectedToModuleName(const CExoString& a0)
{
    return CGOG__SetConnectedToModuleName(this, a0);
}

void CGOG::SetConnectedToServerAddress(const CExoString& a0, int32_t a1)
{
    return CGOG__SetConnectedToServerAddress(this, a0, a1);
}

void CGOG::SetConnectedToServerName(const CExoString& a0)
{
    return CGOG__SetConnectedToServerName(this, a0);
}

const char* CGOG::ShowInviteOverlay()
{
    return CGOG__ShowInviteOverlay(this);
}

void CGOG::UnlockAchievement(const CExoString& a0)
{
    return CGOG__UnlockAchievement(this, a0);
}

void CGOG::Update(float a0)
{
    return CGOG__Update(this, a0);
}

void CGOG__CGOGCtor__0(CGOG* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOG*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__CGOGCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CGOG__CGOGDtor__0(CGOG* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOG*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__CGOGDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CGOG__ClearAchievement(CGOG* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOG*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__ClearAchievement);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGOG__ClearPresenceData(CGOG* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOG*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__ClearPresenceData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoArrayListTemplatedCGOGFriendRichPresencePtr& CGOG__GetFriendList(CGOG* thisPtr)
{
    using FuncPtrType = CExoArrayListTemplatedCGOGFriendRichPresencePtr&(__attribute__((cdecl)) *)(CGOG*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__GetFriendList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CGOG__GetLanguage(CGOG* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CGOG*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__GetLanguage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGOG__IncrementAchievement(CGOG* thisPtr, const CExoString& a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOG*, const CExoString&, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__IncrementAchievement);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CGOG__IsLoggedOn(CGOG* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CGOG*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__IsLoggedOn);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGOG__RequestFriendsUpdate(CGOG* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOG*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__RequestFriendsUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGOG__SetConnectedToModuleName(CGOG* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOG*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__SetConnectedToModuleName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGOG__SetConnectedToServerAddress(CGOG* thisPtr, const CExoString& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOG*, const CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__SetConnectedToServerAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CGOG__SetConnectedToServerName(CGOG* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOG*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__SetConnectedToServerName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

const char* CGOG__ShowInviteOverlay(CGOG* thisPtr)
{
    using FuncPtrType = const char*(__attribute__((cdecl)) *)(CGOG*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__ShowInviteOverlay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGOG__UnlockAchievement(CGOG* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOG*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__UnlockAchievement);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGOG__Update(CGOG* thisPtr, float a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOG*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOG__Update);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
