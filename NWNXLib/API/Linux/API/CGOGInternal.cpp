#include "CGOGInternal.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CGOGInternal::~CGOGInternal()
{
    CGOGInternal__CGOGInternalDtor__0(this);
}

void CGOGInternal::ClearPresenceData()
{
    return CGOGInternal__ClearPresenceData(this);
}

CExoArrayListTemplatedCGOGFriendRichPresencePtr& CGOGInternal::GetFriendList()
{
    return CGOGInternal__GetFriendList(this);
}

CExoString CGOGInternal::GetLanguage()
{
    return CGOGInternal__GetLanguage(this);
}

int32_t CGOGInternal::IsLoggedOn()
{
    return CGOGInternal__IsLoggedOn(this);
}

void CGOGInternal::RequestFriendsUpdate()
{
    return CGOGInternal__RequestFriendsUpdate(this);
}

void CGOGInternal::SetConnectedToModuleName(const CExoString& a0)
{
    return CGOGInternal__SetConnectedToModuleName(this, a0);
}

void CGOGInternal::SetConnectedToServerAddress(const CExoString& a0, int32_t a1)
{
    return CGOGInternal__SetConnectedToServerAddress(this, a0, a1);
}

void CGOGInternal::SetConnectedToServerName(const CExoString& a0)
{
    return CGOGInternal__SetConnectedToServerName(this, a0);
}

const char* CGOGInternal::ShowInviteOverlay()
{
    return CGOGInternal__ShowInviteOverlay(this);
}

void CGOGInternal::Update(float a0)
{
    return CGOGInternal__Update(this, a0);
}

void CGOGInternal__CGOGInternalDtor__0(CGOGInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternal*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternal__CGOGInternalDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CGOGInternal__ClearPresenceData(CGOGInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternal__ClearPresenceData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoArrayListTemplatedCGOGFriendRichPresencePtr& CGOGInternal__GetFriendList(CGOGInternal* thisPtr)
{
    using FuncPtrType = CExoArrayListTemplatedCGOGFriendRichPresencePtr&(__attribute__((cdecl)) *)(CGOGInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternal__GetFriendList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CGOGInternal__GetLanguage(CGOGInternal* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CGOGInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternal__GetLanguage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CGOGInternal__IsLoggedOn(CGOGInternal* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CGOGInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternal__IsLoggedOn);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGOGInternal__RequestFriendsUpdate(CGOGInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternal__RequestFriendsUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGOGInternal__SetConnectedToModuleName(CGOGInternal* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternal*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternal__SetConnectedToModuleName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGOGInternal__SetConnectedToServerAddress(CGOGInternal* thisPtr, const CExoString& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternal*, const CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternal__SetConnectedToServerAddress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CGOGInternal__SetConnectedToServerName(CGOGInternal* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternal*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternal__SetConnectedToServerName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

const char* CGOGInternal__ShowInviteOverlay(CGOGInternal* thisPtr)
{
    using FuncPtrType = const char*(__attribute__((cdecl)) *)(CGOGInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternal__ShowInviteOverlay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGOGInternal__Update(CGOGInternal* thisPtr, float a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGOGInternal*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGOGInternal__Update);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
