#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLinkedList.hpp"
#include "CExoString.hpp"
#include "CServerAIEventNode.hpp"
#include "CServerAIList.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CServerAIMaster)
#endif

class CGameEffect;
class CGameEffectApplierRemover;
class CItemPropertyApplierRemover;
class CNWItemProperty;
class CNWSCreature;
class CNWSItem;
class CNWSObject;
class CResGFF;
class CResStruct;
class CServerExoAppInternal;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CServerAIMaster
{
public:
    CServerExoAppInternal * m_pExoAppInternal;
    CServerAIList m_apGameAIList[5];
    CExoLinkedList<CServerAIEventNode> m_lEventQueue;
    CGameEffectApplierRemover * m_pGameEffectApplierRemover;
    CItemPropertyApplierRemover * m_pItemPropertyApplierRemover;
    int32_t m_nScriptsRun;
    int32_t m_nScriptsRunSize;
    CExoString * m_psScriptsRun;
    BOOL m_bPlotPathRun;
    BOOL m_bGridPathRun;
    BOOL m_bUpdateVisibleListRun;
    BOOL m_bBroadcastAOORun;
    BOOL m_bTrapCheckRun;
    int32_t m_nLastActionRun;
    CExoArrayList<int32_t> * m_pAttackRepAdj;
    CExoArrayList<int32_t> * m_pTheftRepAdj;
    CExoArrayList<int32_t> * m_pKillRepAdj;
    CExoArrayList<int32_t> * m_pHelpRepAdj;

    CServerAIMaster();
    ~CServerAIMaster();
    void SetExoAppInternal(CServerExoAppInternal * pExoAppInternal);
    void UpdateState();
    void ClearEventQueue();
    BOOL AddObject(CNWSObject * pObject, int32_t nAILevel);
    BOOL RemoveObject(CNWSObject * pObject);
    BOOL SetAILevel(CNWSObject * pObject, int32_t nAILevel);
    BOOL AddEventDeltaTime(uint32_t nDaysFromNow, uint32_t nTimeFromNow, OBJECT_ID nCallerObjectId, OBJECT_ID nObjectId, uint32_t nEventId, void * pScript = nullptr);
    BOOL AddEventAbsoluteTime(uint32_t nCalendarDay, uint32_t nTimeOfDay, OBJECT_ID nCallerObjectId, OBJECT_ID nObjectId, uint32_t nEventId, void * pScript = nullptr);
    BOOL AddEventAbsoluteTimeViaTail(uint32_t nCalendarDay, uint32_t nTimeOfDay, OBJECT_ID nCallerObjectId, OBJECT_ID nObjectId, uint32_t nEventId, void * pScript = nullptr);
    BOOL EventPending(uint32_t nCalendarDay, uint32_t nTimeOfDay);
    BOOL GetPendingEvent(uint32_t * nCalendarDay, uint32_t * nTimeOfDay, OBJECT_ID * nCallerObjectId, OBJECT_ID * nObjectId, uint32_t * nEventId, void * * pScript);
    BOOL SaveEventQueue(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadEventQueue(CResGFF * pRes, CResStruct * pStruct);
    int32_t OnEffectApplied(CNWSObject * pObject, CGameEffect * effect, BOOL bLoadingGame = false);
    int32_t OnEffectRemoved(CNWSObject * pObject, CGameEffect * effect);
    int32_t OnItemPropertyApplied(CNWSItem * pItem, CNWItemProperty * pItemProperty, CNWSCreature * pTargetCreature, uint32_t nTargetInventorySlot, BOOL bLoadingGame);
    int32_t OnItemPropertyRemoved(CNWSItem * pItem, CNWItemProperty * pItemProperty, CNWSCreature * pTargetCreature, uint32_t nTargetInventorySlot);
    void AdjustTargetAndWitnessReputations(OBJECT_ID oidTarget, OBJECT_ID oidSource, int32_t nActionType);
    void LoadReputationAdjustments();
    void ClearScriptsRun();
    CExoString * GetScriptsRun();
    void AppendToScriptsRun(CExoString sScriptName);
    void DeleteEventData(uint32_t nEventId, void * pEventData);


#ifdef NWN_CLASS_EXTENSION_CServerAIMaster
    NWN_CLASS_EXTENSION_CServerAIMaster
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CServerAIMaster)
#endif

