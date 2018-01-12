#include "CNetLayerPlayerInfo.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNetLayerPlayerInfo::CNetLayerPlayerInfo()
{
    CNetLayerPlayerInfo__CNetLayerPlayerInfoCtor__0(this);
}

CNetLayerPlayerInfo::~CNetLayerPlayerInfo()
{
    CNetLayerPlayerInfo__CNetLayerPlayerInfoDtor(this);
}

void CNetLayerPlayerInfo::AddCDKey(const CExoString& a0, const CExoString& a1)
{
    return CNetLayerPlayerInfo__AddCDKey(this, a0, a1);
}

int32_t CNetLayerPlayerInfo::AllKeysAuthed(uint32_t& a0)
{
    return CNetLayerPlayerInfo__AllKeysAuthed(this, a0);
}

void CNetLayerPlayerInfo::Initialize()
{
    return CNetLayerPlayerInfo__Initialize(this);
}

void CNetLayerPlayerInfo::SetCDKey(int32_t a0, const CExoString& a1, const CExoString& a2)
{
    return CNetLayerPlayerInfo__SetCDKey(this, a0, a1, a2);
}

void CNetLayerPlayerInfo::StartMstTimer(uint64_t a0)
{
    return CNetLayerPlayerInfo__StartMstTimer(this, a0);
}

int32_t CNetLayerPlayerInfo::UpdateMstTimer(uint64_t a0)
{
    return CNetLayerPlayerInfo__UpdateMstTimer(this, a0);
}

void CNetLayerPlayerInfo__CNetLayerPlayerInfoCtor__0(CNetLayerPlayerInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerPlayerInfo*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerPlayerInfo__CNetLayerPlayerInfoCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNetLayerPlayerInfo__CNetLayerPlayerInfoDtor(CNetLayerPlayerInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerPlayerInfo*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerPlayerInfo__CNetLayerPlayerInfoDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNetLayerPlayerInfo__AddCDKey(CNetLayerPlayerInfo* thisPtr, const CExoString& a0, const CExoString& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerPlayerInfo*, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerPlayerInfo__AddCDKey);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNetLayerPlayerInfo__AllKeysAuthed(CNetLayerPlayerInfo* thisPtr, uint32_t& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerPlayerInfo*, uint32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerPlayerInfo__AllKeysAuthed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNetLayerPlayerInfo__Initialize(CNetLayerPlayerInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerPlayerInfo*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerPlayerInfo__Initialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNetLayerPlayerInfo__SetCDKey(CNetLayerPlayerInfo* thisPtr, int32_t a0, const CExoString& a1, const CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerPlayerInfo*, int32_t, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerPlayerInfo__SetCDKey);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNetLayerPlayerInfo__StartMstTimer(CNetLayerPlayerInfo* thisPtr, uint64_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNetLayerPlayerInfo*, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerPlayerInfo__StartMstTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNetLayerPlayerInfo__UpdateMstTimer(CNetLayerPlayerInfo* thisPtr, uint64_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNetLayerPlayerInfo*, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNetLayerPlayerInfo__UpdateMstTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
