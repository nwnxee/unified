#include "CFactionManager.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoArrayListTemplatedCNWSFactionPtr.hpp"
#include "CExoArrayListTemplatedint.hpp"
#include "CNWSFaction.hpp"
#include "CResGFF.hpp"
#include "CResList.hpp"

namespace NWNXLib {

namespace API {

CFactionManager::CFactionManager()
{
    CFactionManager__CFactionManagerCtor__0(this);
}

CFactionManager::~CFactionManager()
{
    CFactionManager__CFactionManagerDtor__0(this);
}

void CFactionManager::CreateDefaultFactions()
{
    return CFactionManager__CreateDefaultFactions(this);
}

void CFactionManager::DeleteFaction(int32_t a0)
{
    return CFactionManager__DeleteFaction(this, a0);
}

CExoArrayListTemplatedint* CFactionManager::GetDefaultPCReputation()
{
    return CFactionManager__GetDefaultPCReputation(this);
}

CNWSFaction* CFactionManager::GetFaction(int32_t a0)
{
    return CFactionManager__GetFaction(this, a0);
}

int32_t CFactionManager::GetFactionIdByName(const CExoString& a0)
{
    return CFactionManager__GetFactionIdByName(this, a0);
}

int32_t CFactionManager::GetIsNPCFaction(int32_t a0)
{
    return CFactionManager__GetIsNPCFaction(this, a0);
}

int32_t CFactionManager::GetNPCFactionReputation(int32_t a0, int32_t a1)
{
    return CFactionManager__GetNPCFactionReputation(this, a0, a1);
}

int32_t CFactionManager::LoadFactions(CResGFF* a0, CResList* a1)
{
    return CFactionManager__LoadFactions(this, a0, a1);
}

int32_t CFactionManager::LoadReputations(CResGFF* a0, CResList* a1)
{
    return CFactionManager__LoadReputations(this, a0, a1);
}

int32_t CFactionManager::SaveFactions(CResGFF* a0, CResList* a1)
{
    return CFactionManager__SaveFactions(this, a0, a1);
}

int32_t CFactionManager::SaveReputations(CResGFF* a0, CResList* a1)
{
    return CFactionManager__SaveReputations(this, a0, a1);
}

void CFactionManager::SetNPCFactionReputation(int32_t a0, int32_t a1, int32_t a2)
{
    return CFactionManager__SetNPCFactionReputation(this, a0, a1, a2);
}

void CFactionManager__CFactionManagerCtor__0(CFactionManager* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CFactionManager*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__CFactionManagerCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CFactionManager__CFactionManagerDtor__0(CFactionManager* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CFactionManager*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__CFactionManagerDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CFactionManager__CreateDefaultFactions(CFactionManager* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CFactionManager*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__CreateDefaultFactions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CFactionManager__DeleteFaction(CFactionManager* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CFactionManager*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__DeleteFaction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoArrayListTemplatedint* CFactionManager__GetDefaultPCReputation(CFactionManager* thisPtr)
{
    using FuncPtrType = CExoArrayListTemplatedint*(__attribute__((cdecl)) *)(CFactionManager*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__GetDefaultPCReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSFaction* CFactionManager__GetFaction(CFactionManager* thisPtr, int32_t a0)
{
    using FuncPtrType = CNWSFaction*(__attribute__((cdecl)) *)(CFactionManager*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__GetFaction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CFactionManager__GetFactionIdByName(CFactionManager* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CFactionManager*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__GetFactionIdByName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CFactionManager__GetIsNPCFaction(CFactionManager* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CFactionManager*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__GetIsNPCFaction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CFactionManager__GetNPCFactionReputation(CFactionManager* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CFactionManager*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__GetNPCFactionReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CFactionManager__LoadFactions(CFactionManager* thisPtr, CResGFF* a0, CResList* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CFactionManager*, CResGFF*, CResList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__LoadFactions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CFactionManager__LoadReputations(CFactionManager* thisPtr, CResGFF* a0, CResList* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CFactionManager*, CResGFF*, CResList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__LoadReputations);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CFactionManager__SaveFactions(CFactionManager* thisPtr, CResGFF* a0, CResList* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CFactionManager*, CResGFF*, CResList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__SaveFactions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CFactionManager__SaveReputations(CFactionManager* thisPtr, CResGFF* a0, CResList* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CFactionManager*, CResGFF*, CResList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__SaveReputations);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CFactionManager__SetNPCFactionReputation(CFactionManager* thisPtr, int32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CFactionManager*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CFactionManager__SetNPCFactionReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

}

}
