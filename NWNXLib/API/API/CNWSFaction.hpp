#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSFaction)
#endif

class CFactionManager;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSFaction
{
    CExoArrayList<OBJECT_ID> m_listFactionMembers;
    int32_t m_nFactionId;
    int32_t m_nParentFactionId;
    int32_t m_nMemberListArrayIndex;
    CExoString m_sFactionName;
    BOOL m_bGlobalReaction;

    CNWSFaction();
    CNWSFaction(OBJECT_ID oidLeaderID);
    ~CNWSFaction();
    void Initialise();
    void AddMember(OBJECT_ID oidNewMemberID, BOOL bInPostProcess = false);
    void AttemptJoin(OBJECT_ID oidNewMemberID);
    BOOL AttemptRemove(OBJECT_ID oidRemoveeID, OBJECT_ID oidRemoverID);
    uint32_t GetMemberList(OBJECT_ID * * pMemberIDs);
    BOOL InviteMember(OBJECT_ID oidNewMemberID, OBJECT_ID oidInviterPlayerID);
    BOOL GetIsInvited(OBJECT_ID oidCreatureID);
    void RemoveMember(OBJECT_ID oidMemberID);
    void ChangeMemberId(OBJECT_ID oidOld, OBJECT_ID oidNew);
    void SendChatMessage(OBJECT_ID oidSpeaker, CExoString sSpeakerMessage);
    void SendFactionUpdateList();
    void SendFactionUpdateAdd(OBJECT_ID oidAddedMemberID);
    void SendFactionUpdateRemove(OBJECT_ID oidRemovedMemberID);
    OBJECT_ID GetWeakestMember(OBJECT_ID oidReferenceFactionMember, BOOL bMustBeVisible = true);
    OBJECT_ID GetStrongestMember(OBJECT_ID oidReferenceFactionMember, BOOL bMustBeVisible = true);
    OBJECT_ID GetMostDamagedMember(OBJECT_ID oidReferenceFactionMember, BOOL bMustBeVisible = true);
    OBJECT_ID GetLeastDamagedMember(OBJECT_ID oidReferenceFactionMember, BOOL bMustBeVisible = true);
    int32_t GetGold();
    int32_t GetAverageReputation(OBJECT_ID oidSubject);
    int32_t GetAverageGoodEvilAlignment();
    int32_t GetAverageLawChaosAlignment();
    int32_t GetAverageLevel();
    int32_t GetAverageXP();
    int32_t GetMostFrequentClass();
    OBJECT_ID GetWorstAC(OBJECT_ID oidReferenceFactionMember, BOOL bMustBeVisible = true);
    OBJECT_ID GetBestAC(OBJECT_ID oidReferenceFactionMember, BOOL bMustBeVisible = true);
    BOOL GetCreatureInParty(OBJECT_ID oidCreature);
    BOOL GetSingletonParty();
    BOOL TransferLeadership(OBJECT_ID oidNewLeader, OBJECT_ID oidOldLeader);
    OBJECT_ID GetFactionMember(int32_t nStartPos, BOOL bPCOnly);
    void ClearAllReputationsTowards(OBJECT_ID oidCreature);
    OBJECT_ID GetLeader();
    CFactionManager * GetFactionManager();


#ifdef NWN_CLASS_EXTENSION_CNWSFaction
    NWN_CLASS_EXTENSION_CNWSFaction
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSFaction)
#endif

