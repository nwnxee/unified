#pragma once

#include <cstdint>

#include "CExoLinkedListTemplatedCServerAIEventNode.hpp"
#include "CExoString.hpp"
#include "CServerAIList.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoArrayListTemplatedint;
struct CGameEffect;
struct CGameEffectApplierRemover;
struct CItemPropertyApplierRemover;
struct CNWItemProperty;
struct CNWSCreature;
struct CNWSItem;
struct CNWSObject;
struct CResGFF;
struct CResStruct;
struct CServerExoAppInternal;

struct CServerAIMaster
{
    CServerExoAppInternal* m_pExoAppInternal;
    CServerAIList m_apGameAIList[5];
    CExoLinkedListTemplatedCServerAIEventNode m_lEventQueue;
    CGameEffectApplierRemover* m_pGameEffectApplierRemover;
    CItemPropertyApplierRemover* m_pItemPropertyApplierRemover;
    int32_t m_nScriptsRun;
    int32_t m_nScriptsRunSize;
    CExoString* m_psScriptsRun;
    int32_t m_bPlotPathRun;
    int32_t m_bGridPathRun;
    int32_t m_bUpdateVisibleListRun;
    int32_t m_bBroadcastAOORun;
    int32_t m_bTrapCheckRun;
    int32_t m_nLastActionRun;
    CExoArrayListTemplatedint* m_pAttackRepAdj;
    CExoArrayListTemplatedint* m_pTheftRepAdj;
    CExoArrayListTemplatedint* m_pKillRepAdj;
    CExoArrayListTemplatedint* m_pHelpRepAdj;

    // The below are auto generated stubs.
    CServerAIMaster(const CServerAIMaster&) = default;
    CServerAIMaster& operator=(const CServerAIMaster&) = default;

    CServerAIMaster();
    ~CServerAIMaster();
    int32_t AddEventAbsoluteTime(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void*);
    int32_t AddEventAbsoluteTimeViaTail(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void*);
    int32_t AddEventDeltaTime(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void*);
    int32_t AddObject(CNWSObject*, int32_t);
    void AdjustTargetAndWitnessReputations(uint32_t, uint32_t, int32_t);
    void AppendToScriptsRun(CExoString);
    void ClearEventQueue();
    void ClearScriptsRun();
    void DeleteEventData(uint32_t, void*);
    int32_t EventPending(uint32_t, uint32_t);
    int32_t GetPendingEvent(uint32_t*, uint32_t*, uint32_t*, uint32_t*, uint32_t*, void**);
    CExoString* GetScriptsRun();
    int32_t LoadEventQueue(CResGFF*, CResStruct*);
    void LoadReputationAdjustments();
    int32_t OnEffectApplied(CNWSObject*, CGameEffect*, int32_t);
    int32_t OnEffectRemoved(CNWSObject*, CGameEffect*);
    int32_t OnItemPropertyApplied(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    int32_t OnItemPropertyRemoved(CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);
    int32_t RemoveObject(CNWSObject*);
    int32_t SaveEventQueue(CResGFF*, CResStruct*);
    int32_t SetAILevel(CNWSObject*, int32_t);
    void SetExoAppInternal(CServerExoAppInternal*);
    void UpdateState();
};

void CServerAIMaster__CServerAIMasterCtor__0(CServerAIMaster* thisPtr);
void CServerAIMaster__CServerAIMasterDtor__0(CServerAIMaster* thisPtr);
int32_t CServerAIMaster__AddEventAbsoluteTime(CServerAIMaster* thisPtr, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void*);
int32_t CServerAIMaster__AddEventAbsoluteTimeViaTail(CServerAIMaster* thisPtr, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void*);
int32_t CServerAIMaster__AddEventDeltaTime(CServerAIMaster* thisPtr, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void*);
int32_t CServerAIMaster__AddObject(CServerAIMaster* thisPtr, CNWSObject*, int32_t);
void CServerAIMaster__AdjustTargetAndWitnessReputations(CServerAIMaster* thisPtr, uint32_t, uint32_t, int32_t);
void CServerAIMaster__AppendToScriptsRun(CServerAIMaster* thisPtr, CExoString);
void CServerAIMaster__ClearEventQueue(CServerAIMaster* thisPtr);
void CServerAIMaster__ClearScriptsRun(CServerAIMaster* thisPtr);
void CServerAIMaster__DeleteEventData(CServerAIMaster* thisPtr, uint32_t, void*);
int32_t CServerAIMaster__EventPending(CServerAIMaster* thisPtr, uint32_t, uint32_t);
int32_t CServerAIMaster__GetPendingEvent(CServerAIMaster* thisPtr, uint32_t*, uint32_t*, uint32_t*, uint32_t*, uint32_t*, void**);
CExoString* CServerAIMaster__GetScriptsRun(CServerAIMaster* thisPtr);
int32_t CServerAIMaster__LoadEventQueue(CServerAIMaster* thisPtr, CResGFF*, CResStruct*);
void CServerAIMaster__LoadReputationAdjustments(CServerAIMaster* thisPtr);
int32_t CServerAIMaster__OnEffectApplied(CServerAIMaster* thisPtr, CNWSObject*, CGameEffect*, int32_t);
int32_t CServerAIMaster__OnEffectRemoved(CServerAIMaster* thisPtr, CNWSObject*, CGameEffect*);
int32_t CServerAIMaster__OnItemPropertyApplied(CServerAIMaster* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
int32_t CServerAIMaster__OnItemPropertyRemoved(CServerAIMaster* thisPtr, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);
int32_t CServerAIMaster__RemoveObject(CServerAIMaster* thisPtr, CNWSObject*);
int32_t CServerAIMaster__SaveEventQueue(CServerAIMaster* thisPtr, CResGFF*, CResStruct*);
int32_t CServerAIMaster__SetAILevel(CServerAIMaster* thisPtr, CNWSObject*, int32_t);
void CServerAIMaster__SetExoAppInternal(CServerAIMaster* thisPtr, CServerExoAppInternal*);
void CServerAIMaster__UpdateState(CServerAIMaster* thisPtr);

}

}
