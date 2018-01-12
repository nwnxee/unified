#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedlongunsignedint.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CFactionManager;

struct CNWSFaction
{
    CExoArrayListTemplatedlongunsignedint m_listFactionMembers;
    int32_t m_nFactionId;
    int32_t m_nParentFactionId;
    int32_t m_nMemberListArrayIndex;
    CExoString m_sFactionName;
    int32_t m_bGlobalReaction;

    // The below are auto generated stubs.
    CNWSFaction(const CNWSFaction&) = default;
    CNWSFaction& operator=(const CNWSFaction&) = default;

    CNWSFaction();
    CNWSFaction(uint32_t);
    ~CNWSFaction();
    void AddMember(uint32_t, int32_t);
    void AttemptJoin(uint32_t);
    int32_t AttemptRemove(uint32_t, uint32_t);
    void ChangeMemberId(uint32_t, uint32_t);
    void ClearAllReputationsTowards(uint32_t);
    int32_t GetAverageGoodEvilAlignment();
    int32_t GetAverageLawChaosAlignment();
    int32_t GetAverageLevel();
    int32_t GetAverageReputation(uint32_t);
    int32_t GetAverageXP();
    uint32_t GetBestAC(uint32_t, int32_t);
    int32_t GetCreatureInParty(uint32_t);
    CFactionManager* GetFactionManager();
    uint32_t GetFactionMember(int32_t, int32_t);
    int32_t GetGold();
    int32_t GetIsInvited(uint32_t);
    uint32_t GetLeader();
    uint32_t GetLeastDamagedMember(uint32_t, int32_t);
    uint32_t GetMemberList(uint32_t**);
    uint32_t GetMostDamagedMember(uint32_t, int32_t);
    int32_t GetMostFrequentClass();
    int32_t GetSingletonParty();
    uint32_t GetStrongestMember(uint32_t, int32_t);
    uint32_t GetWeakestMember(uint32_t, int32_t);
    uint32_t GetWorstAC(uint32_t, int32_t);
    void Initialise();
    int32_t InviteMember(uint32_t, uint32_t);
    void RemoveMember(uint32_t);
    void SendChatMessage(uint32_t, CExoString);
    void SendFactionUpdateAdd(uint32_t);
    void SendFactionUpdateList();
    void SendFactionUpdateRemove(uint32_t);
    int32_t TransferLeadership(uint32_t, uint32_t);
};

void CNWSFaction__CNWSFactionCtor__0(CNWSFaction* thisPtr);
void CNWSFaction__CNWSFactionCtor__2(CNWSFaction* thisPtr, uint32_t);
void CNWSFaction__CNWSFactionDtor__0(CNWSFaction* thisPtr);
void CNWSFaction__AddMember(CNWSFaction* thisPtr, uint32_t, int32_t);
void CNWSFaction__AttemptJoin(CNWSFaction* thisPtr, uint32_t);
int32_t CNWSFaction__AttemptRemove(CNWSFaction* thisPtr, uint32_t, uint32_t);
void CNWSFaction__ChangeMemberId(CNWSFaction* thisPtr, uint32_t, uint32_t);
void CNWSFaction__ClearAllReputationsTowards(CNWSFaction* thisPtr, uint32_t);
int32_t CNWSFaction__GetAverageGoodEvilAlignment(CNWSFaction* thisPtr);
int32_t CNWSFaction__GetAverageLawChaosAlignment(CNWSFaction* thisPtr);
int32_t CNWSFaction__GetAverageLevel(CNWSFaction* thisPtr);
int32_t CNWSFaction__GetAverageReputation(CNWSFaction* thisPtr, uint32_t);
int32_t CNWSFaction__GetAverageXP(CNWSFaction* thisPtr);
uint32_t CNWSFaction__GetBestAC(CNWSFaction* thisPtr, uint32_t, int32_t);
int32_t CNWSFaction__GetCreatureInParty(CNWSFaction* thisPtr, uint32_t);
CFactionManager* CNWSFaction__GetFactionManager(CNWSFaction* thisPtr);
uint32_t CNWSFaction__GetFactionMember(CNWSFaction* thisPtr, int32_t, int32_t);
int32_t CNWSFaction__GetGold(CNWSFaction* thisPtr);
int32_t CNWSFaction__GetIsInvited(CNWSFaction* thisPtr, uint32_t);
uint32_t CNWSFaction__GetLeader(CNWSFaction* thisPtr);
uint32_t CNWSFaction__GetLeastDamagedMember(CNWSFaction* thisPtr, uint32_t, int32_t);
uint32_t CNWSFaction__GetMemberList(CNWSFaction* thisPtr, uint32_t**);
uint32_t CNWSFaction__GetMostDamagedMember(CNWSFaction* thisPtr, uint32_t, int32_t);
int32_t CNWSFaction__GetMostFrequentClass(CNWSFaction* thisPtr);
int32_t CNWSFaction__GetSingletonParty(CNWSFaction* thisPtr);
uint32_t CNWSFaction__GetStrongestMember(CNWSFaction* thisPtr, uint32_t, int32_t);
uint32_t CNWSFaction__GetWeakestMember(CNWSFaction* thisPtr, uint32_t, int32_t);
uint32_t CNWSFaction__GetWorstAC(CNWSFaction* thisPtr, uint32_t, int32_t);
void CNWSFaction__Initialise(CNWSFaction* thisPtr);
int32_t CNWSFaction__InviteMember(CNWSFaction* thisPtr, uint32_t, uint32_t);
void CNWSFaction__RemoveMember(CNWSFaction* thisPtr, uint32_t);
void CNWSFaction__SendChatMessage(CNWSFaction* thisPtr, uint32_t, CExoString);
void CNWSFaction__SendFactionUpdateAdd(CNWSFaction* thisPtr, uint32_t);
void CNWSFaction__SendFactionUpdateList(CNWSFaction* thisPtr);
void CNWSFaction__SendFactionUpdateRemove(CNWSFaction* thisPtr, uint32_t);
int32_t CNWSFaction__TransferLeadership(CNWSFaction* thisPtr, uint32_t, uint32_t);

}

}
