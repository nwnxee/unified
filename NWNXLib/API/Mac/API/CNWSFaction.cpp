#include "CNWSFaction.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CFactionManager.hpp"

namespace NWNXLib {

namespace API {

CNWSFaction::CNWSFaction()
{
    CNWSFaction__CNWSFactionCtor__0(this);
}

CNWSFaction::CNWSFaction(uint32_t a0)
{
    CNWSFaction__CNWSFactionCtor__2(this, a0);
}

CNWSFaction::~CNWSFaction()
{
    CNWSFaction__CNWSFactionDtor__0(this);
}

void CNWSFaction::AddMember(uint32_t a0, int32_t a1)
{
    return CNWSFaction__AddMember(this, a0, a1);
}

void CNWSFaction::AttemptJoin(uint32_t a0)
{
    return CNWSFaction__AttemptJoin(this, a0);
}

int32_t CNWSFaction::AttemptRemove(uint32_t a0, uint32_t a1)
{
    return CNWSFaction__AttemptRemove(this, a0, a1);
}

void CNWSFaction::ChangeMemberId(uint32_t a0, uint32_t a1)
{
    return CNWSFaction__ChangeMemberId(this, a0, a1);
}

void CNWSFaction::ClearAllReputationsTowards(uint32_t a0)
{
    return CNWSFaction__ClearAllReputationsTowards(this, a0);
}

int32_t CNWSFaction::GetAverageGoodEvilAlignment()
{
    return CNWSFaction__GetAverageGoodEvilAlignment(this);
}

int32_t CNWSFaction::GetAverageLawChaosAlignment()
{
    return CNWSFaction__GetAverageLawChaosAlignment(this);
}

int32_t CNWSFaction::GetAverageLevel()
{
    return CNWSFaction__GetAverageLevel(this);
}

int32_t CNWSFaction::GetAverageReputation(uint32_t a0)
{
    return CNWSFaction__GetAverageReputation(this, a0);
}

int32_t CNWSFaction::GetAverageXP()
{
    return CNWSFaction__GetAverageXP(this);
}

uint32_t CNWSFaction::GetBestAC(uint32_t a0, int32_t a1)
{
    return CNWSFaction__GetBestAC(this, a0, a1);
}

int32_t CNWSFaction::GetCreatureInParty(uint32_t a0)
{
    return CNWSFaction__GetCreatureInParty(this, a0);
}

CFactionManager* CNWSFaction::GetFactionManager()
{
    return CNWSFaction__GetFactionManager(this);
}

uint32_t CNWSFaction::GetFactionMember(int32_t a0, int32_t a1)
{
    return CNWSFaction__GetFactionMember(this, a0, a1);
}

int32_t CNWSFaction::GetGold()
{
    return CNWSFaction__GetGold(this);
}

int32_t CNWSFaction::GetIsInvited(uint32_t a0)
{
    return CNWSFaction__GetIsInvited(this, a0);
}

uint32_t CNWSFaction::GetLeader()
{
    return CNWSFaction__GetLeader(this);
}

uint32_t CNWSFaction::GetLeastDamagedMember(uint32_t a0, int32_t a1)
{
    return CNWSFaction__GetLeastDamagedMember(this, a0, a1);
}

uint32_t CNWSFaction::GetMemberList(uint32_t** a0)
{
    return CNWSFaction__GetMemberList(this, a0);
}

uint32_t CNWSFaction::GetMostDamagedMember(uint32_t a0, int32_t a1)
{
    return CNWSFaction__GetMostDamagedMember(this, a0, a1);
}

int32_t CNWSFaction::GetMostFrequentClass()
{
    return CNWSFaction__GetMostFrequentClass(this);
}

int32_t CNWSFaction::GetSingletonParty()
{
    return CNWSFaction__GetSingletonParty(this);
}

uint32_t CNWSFaction::GetStrongestMember(uint32_t a0, int32_t a1)
{
    return CNWSFaction__GetStrongestMember(this, a0, a1);
}

uint32_t CNWSFaction::GetWeakestMember(uint32_t a0, int32_t a1)
{
    return CNWSFaction__GetWeakestMember(this, a0, a1);
}

uint32_t CNWSFaction::GetWorstAC(uint32_t a0, int32_t a1)
{
    return CNWSFaction__GetWorstAC(this, a0, a1);
}

void CNWSFaction::Initialise()
{
    return CNWSFaction__Initialise(this);
}

int32_t CNWSFaction::InviteMember(uint32_t a0, uint32_t a1)
{
    return CNWSFaction__InviteMember(this, a0, a1);
}

void CNWSFaction::RemoveMember(uint32_t a0)
{
    return CNWSFaction__RemoveMember(this, a0);
}

void CNWSFaction::SendChatMessage(uint32_t a0, CExoString a1)
{
    return CNWSFaction__SendChatMessage(this, a0, a1);
}

void CNWSFaction::SendFactionUpdateAdd(uint32_t a0)
{
    return CNWSFaction__SendFactionUpdateAdd(this, a0);
}

void CNWSFaction::SendFactionUpdateList()
{
    return CNWSFaction__SendFactionUpdateList(this);
}

void CNWSFaction::SendFactionUpdateRemove(uint32_t a0)
{
    return CNWSFaction__SendFactionUpdateRemove(this, a0);
}

int32_t CNWSFaction::TransferLeadership(uint32_t a0, uint32_t a1)
{
    return CNWSFaction__TransferLeadership(this, a0, a1);
}

void CNWSFaction__CNWSFactionCtor__0(CNWSFaction* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSFaction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__CNWSFactionCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSFaction__CNWSFactionCtor__2(CNWSFaction* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__CNWSFactionCtor__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSFaction__CNWSFactionDtor__0(CNWSFaction* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSFaction*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__CNWSFactionDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSFaction__AddMember(CNWSFaction* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__AddMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSFaction__AttemptJoin(CNWSFaction* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__AttemptJoin);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSFaction__AttemptRemove(CNWSFaction* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__AttemptRemove);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSFaction__ChangeMemberId(CNWSFaction* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__ChangeMemberId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSFaction__ClearAllReputationsTowards(CNWSFaction* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__ClearAllReputationsTowards);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSFaction__GetAverageGoodEvilAlignment(CNWSFaction* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSFaction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetAverageGoodEvilAlignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSFaction__GetAverageLawChaosAlignment(CNWSFaction* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSFaction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetAverageLawChaosAlignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSFaction__GetAverageLevel(CNWSFaction* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSFaction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetAverageLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSFaction__GetAverageReputation(CNWSFaction* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetAverageReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSFaction__GetAverageXP(CNWSFaction* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSFaction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetAverageXP);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSFaction__GetBestAC(CNWSFaction* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetBestAC);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSFaction__GetCreatureInParty(CNWSFaction* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetCreatureInParty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CFactionManager* CNWSFaction__GetFactionManager(CNWSFaction* thisPtr)
{
    using FuncPtrType = CFactionManager*(__attribute__((cdecl)) *)(CNWSFaction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetFactionManager);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSFaction__GetFactionMember(CNWSFaction* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSFaction*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetFactionMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSFaction__GetGold(CNWSFaction* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSFaction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetGold);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSFaction__GetIsInvited(CNWSFaction* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetIsInvited);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSFaction__GetLeader(CNWSFaction* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSFaction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetLeader);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSFaction__GetLeastDamagedMember(CNWSFaction* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetLeastDamagedMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSFaction__GetMemberList(CNWSFaction* thisPtr, uint32_t** a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetMemberList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSFaction__GetMostDamagedMember(CNWSFaction* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetMostDamagedMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSFaction__GetMostFrequentClass(CNWSFaction* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSFaction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetMostFrequentClass);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSFaction__GetSingletonParty(CNWSFaction* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSFaction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetSingletonParty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSFaction__GetStrongestMember(CNWSFaction* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetStrongestMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSFaction__GetWeakestMember(CNWSFaction* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetWeakestMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSFaction__GetWorstAC(CNWSFaction* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__GetWorstAC);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSFaction__Initialise(CNWSFaction* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSFaction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__Initialise);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSFaction__InviteMember(CNWSFaction* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__InviteMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSFaction__RemoveMember(CNWSFaction* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__RemoveMember);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSFaction__SendChatMessage(CNWSFaction* thisPtr, uint32_t a0, CExoString a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__SendChatMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSFaction__SendFactionUpdateAdd(CNWSFaction* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__SendFactionUpdateAdd);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSFaction__SendFactionUpdateList(CNWSFaction* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSFaction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__SendFactionUpdateList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSFaction__SendFactionUpdateRemove(CNWSFaction* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__SendFactionUpdateRemove);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSFaction__TransferLeadership(CNWSFaction* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSFaction*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSFaction__TransferLeadership);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
