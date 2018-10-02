#include "CGOGInternalImpl.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CGOGFriendRichPresence.hpp"

namespace NWNXLib {

namespace API {

CGOGInternalImpl::CGOGInternalImpl()
{
    CGOGInternalImpl__CGOGInternalImplCtor(this);
}

CGOGInternalImpl::~CGOGInternalImpl()
{
    CGOGInternalImpl__CGOGInternalImplDtor__0(this);
}

void CGOGInternalImpl::ClearPresenceData()
{
    return CGOGInternalImpl__ClearPresenceData(this);
}

CExoString CGOGInternalImpl::GetLanguage()
{
    return CGOGInternalImpl__GetLanguage(this);
}

int32_t CGOGInternalImpl::IsLoggedOn()
{
    return CGOGInternalImpl__IsLoggedOn(this);
}

void CGOGInternalImpl::OnAuthLost()
{
    return CGOGInternalImpl__OnAuthLost(this);
}

void CGOGInternalImpl::OnAuthSuccess()
{
    return CGOGInternalImpl__OnAuthSuccess(this);
}

void CGOGInternalImpl::OnFriendListRetrieveSuccess()
{
    return CGOGInternalImpl__OnFriendListRetrieveSuccess(this);
}

void CGOGInternalImpl::OnNotificationReceived(uint64_t a0, uint32_t a1, uint32_t a2)
{
    return CGOGInternalImpl__OnNotificationReceived(this, a0, a1, a2);
}

void CGOGInternalImpl::OnOperationalStateChanged(uint32_t a0)
{
    return CGOGInternalImpl__OnOperationalStateChanged(this, a0);
}

void CGOGInternalImpl::OnOverlayVisibilityChanged(int32_t a0)
{
    return CGOGInternalImpl__OnOverlayVisibilityChanged(this, a0);
}

void CGOGInternalImpl::OnRichPresenceChangeSuccess()
{
    return CGOGInternalImpl__OnRichPresenceChangeSuccess(this);
}

CExoString CGOGInternalImpl::PackMetadata(const CGOGFriendRichPresence& a0)
{
    return CGOGInternalImpl__PackMetadata(this, a0);
}

void CGOGInternalImpl::RequestFriendsUpdate()
{
    return CGOGInternalImpl__RequestFriendsUpdate(this);
}

void CGOGInternalImpl::SetConnectedToModuleName(const CExoString& a0)
{
    return CGOGInternalImpl__SetConnectedToModuleName(this, a0);
}

void CGOGInternalImpl::SetConnectedToServerAddress(const CExoString& a0, int32_t a1)
{
    return CGOGInternalImpl__SetConnectedToServerAddress(this, a0, a1);
}

void CGOGInternalImpl::SetConnectedToServerName(const CExoString& a0)
{
    return CGOGInternalImpl__SetConnectedToServerName(this, a0);
}

const char* CGOGInternalImpl::ShowInviteOverlay()
{
    return CGOGInternalImpl__ShowInviteOverlay(this);
}

int32_t CGOGInternalImpl::UnpackMetadata(const CExoString& a0, CGOGFriendRichPresence* a1)
{
    return CGOGInternalImpl__UnpackMetadata(this, a0, a1);
}

void CGOGInternalImpl::Update(float a0)
{
    return CGOGInternalImpl__Update(this, a0);
}

void CGOGInternalImpl__CGOGInternalImplCtor(CGOGInternalImpl* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__CGOGInternalImplCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CGOGInternalImpl__CGOGInternalImplDtor__0(CGOGInternalImpl* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__CGOGInternalImplDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CGOGInternalImpl__ClearPresenceData(CGOGInternalImpl* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__ClearPresenceData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CGOGInternalImpl__GetLanguage(CGOGInternalImpl* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CGOGInternalImpl*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__GetLanguage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CGOGInternalImpl__IsLoggedOn(CGOGInternalImpl* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CGOGInternalImpl*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__IsLoggedOn);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGOGInternalImpl__OnAuthLost(CGOGInternalImpl* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__OnAuthLost);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGOGInternalImpl__OnAuthSuccess(CGOGInternalImpl* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__OnAuthSuccess);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGOGInternalImpl__OnFriendListRetrieveSuccess(CGOGInternalImpl* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__OnFriendListRetrieveSuccess);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGOGInternalImpl__OnNotificationReceived(CGOGInternalImpl* thisPtr, uint64_t a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*, uint64_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__OnNotificationReceived);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CGOGInternalImpl__OnOperationalStateChanged(CGOGInternalImpl* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__OnOperationalStateChanged);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGOGInternalImpl__OnOverlayVisibilityChanged(CGOGInternalImpl* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__OnOverlayVisibilityChanged);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGOGInternalImpl__OnRichPresenceChangeSuccess(CGOGInternalImpl* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__OnRichPresenceChangeSuccess);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CGOGInternalImpl__PackMetadata(CGOGInternalImpl* thisPtr, const CGOGFriendRichPresence& a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CGOGInternalImpl*, const CGOGFriendRichPresence&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__PackMetadata);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGOGInternalImpl__RequestFriendsUpdate(CGOGInternalImpl* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__RequestFriendsUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGOGInternalImpl__SetConnectedToModuleName(CGOGInternalImpl* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__SetConnectedToModuleName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGOGInternalImpl__SetConnectedToServerAddress(CGOGInternalImpl* thisPtr, const CExoString& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*, const CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__SetConnectedToServerAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CGOGInternalImpl__SetConnectedToServerName(CGOGInternalImpl* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__SetConnectedToServerName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

const char* CGOGInternalImpl__ShowInviteOverlay(CGOGInternalImpl* thisPtr)
{
    using FuncPtrType = const char*(__attribute__((cdecl)) *)(CGOGInternalImpl*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__ShowInviteOverlay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CGOGInternalImpl__UnpackMetadata(CGOGInternalImpl* thisPtr, const CExoString& a0, CGOGFriendRichPresence* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CGOGInternalImpl*, const CExoString&, CGOGFriendRichPresence*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__UnpackMetadata);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CGOGInternalImpl__Update(CGOGInternalImpl* thisPtr, float a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternalImpl*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternalImpl__Update);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
