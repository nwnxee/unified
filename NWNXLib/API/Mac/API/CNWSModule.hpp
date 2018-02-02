#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCExoString.hpp"
#include "CExoArrayListTemplatedCNWSTagNode.hpp"
#include "CExoArrayListTemplatedCWorldJournalEntry.hpp"
#include "CExoArrayListTemplatedlongunsignedint.hpp"
#include "CExoLinkedListTemplatedCNWSPlayerTURD.hpp"
#include "CExoLinkedListTemplatedCResRef.hpp"
#include "CExoLinkedListTemplatedNWModuleCutScene_st.hpp"
#include "CExoLinkedListTemplatedNWModuleExpansion_st.hpp"
#include "CExoLinkedListTemplatedNWPlayerListItem_st.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CGameObject.hpp"
#include "CNWSScriptVarTable.hpp"
#include "CResHelperTemplatedCResIFO2014u.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CERFFile;
struct CExoArrayListTemplatedNWPlayerCharacterList_stPtr;
struct CExoArrayListTemplatedunsignedlong;
struct CNWSArea;
struct CNWSPlayer;
struct CNWSPlayerTURD;
struct CPathfindInformation;
struct CResGFF;
struct CResStruct;
struct NWModuleEntryInfo_st;
struct NWModuleHeader_st;

struct CNWSModule
    : CResHelperTemplatedCResIFO2014u, CGameObject
{
    CExoLinkedListTemplatedNWModuleExpansion_st m_lstModuleExpansion;
    CExoLinkedListTemplatedNWModuleCutScene_st m_lstModuleCutScene;
    CExoLinkedListTemplatedCResRef m_lstModuleArea;
    CExoArrayListTemplatedlongunsignedint m_lstModuleAreaID;
    int32_t m_nLastAreaAIUpdatePos;
    CExoLinkedListTemplatedNWPlayerListItem_st m_lstPlayerInfo;
    CExoLinkedListTemplatedCNWSPlayerTURD m_lstTURDList;
    CExoLocString m_lsModuleDescription;
    CExoString m_sModuleAltTLKFile;
    NWModuleHeader_st* m_pModuleHeader;
    NWModuleEntryInfo_st* m_pModuleEntryInfo;
    CExoString m_sModuleResourceName;
    CExoString m_sDDResourceName;
    int32_t m_bIsDDModule;
    int32_t m_bIsDDDemoModule;
    int32_t m_bIsDDModuleLoaded;
    CExoLocString m_lsModuleName;
    CExoArrayListTemplatedCExoString m_pHakFiles;
    CResRef m_cStartMovie;
    CNWSScriptVarTable m_ScriptVars;
    CExoString m_sScripts[18];
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    CExoArrayListTemplatedCNWSTagNode m_aTagLookupTable;
    CExoArrayListTemplatedlongunsignedint m_pInvisibleCreaturesList;
    int32_t m_nCustomScriptEventId;
    uint32_t m_oidLastEnter;
    uint32_t m_oidLastExit;
    uint32_t m_oidLastItemAcquired;
    uint32_t m_oidLastItemAcquiredFrom;
    uint32_t m_oidLastItemAcquiredBy;
    uint32_t m_oidLastItemLost;
    uint32_t m_oidLastItemLoser;
    int32_t m_nLastItemAcquiredSize;
    int32_t m_nLastItemLostSize;
    uint32_t m_oidLastItemEquipped;
    uint32_t m_oidLastItemEquippedBy;
    uint32_t m_oidLastItemUnequipped;
    uint32_t m_oidLastItemUnequippedBy;
    uint32_t m_oidLastRested;
    uint8_t m_nLastRestEventType;
    uint32_t m_oidLastPlayerDied;
    uint32_t m_oidLastPlayerDying;
    uint32_t m_oidLastRespawnButtonPresser;
    uint32_t m_oidLastItemActivated;
    uint32_t m_oidLastItemActivator;
    uint32_t m_oidLastItemActivatedArea;
    uint32_t m_oidLastItemActivatedTarget;
    Vector m_vLastItemActivatedPosition;
    uint32_t m_oidLastPCLevellingUp;
    uint32_t m_oidLastPCCancelCutscene;
    uint8_t m_nMinutesPerHour;
    uint8_t m_nDawnHour;
    uint8_t m_nDuskHour;
    uint8_t m_nStartMonth;
    uint8_t m_nStartDay;
    uint8_t m_nStartHour;
    uint8_t m_nXPScale;
    uint32_t m_nCurrentYear;
    uint32_t m_nCurrentMonth;
    uint32_t m_nCurrentDay;
    uint32_t m_nCurrentHour;
    uint32_t m_nTimeIntoTransition;
    uint8_t m_nTimeOfDayState;
    uint32_t m_nLastUpdateCalendarDay;
    uint32_t m_nLastUpdateTimeOfDay;
    int32_t m_bIsSaveGame;
    CExoArrayListTemplatedCWorldJournalEntry m_pWorldJournal;
    int32_t m_bModuleLoadFinished;
    int32_t m_nMaxHenchmen;
    CExoArrayListTemplatedlongunsignedint m_aGameObjectsLimbo;
    CERFFile* m_pOutFile;
    CResStruct* m_pStructIFO;
    CResGFF* m_pResIFO;
    CExoArrayListTemplatedlongunsignedint* m_apPlayers;
    CExoString m_sTag;
    int32_t m_bIsNWMFile;
    CExoString m_sNWMResName;
    int32_t m_nResourceCount;
    uint8_t m_nPlayerPathfindRule;
    uint8_t m_nEnableScriptDebugger;
    uint32_t m_oidLastPlayerChatObjectId;
    CExoString m_sLastPlayerChatMessage;
    uint8_t m_nLastPlayerChatType;

    // The below are auto generated stubs.
    CNWSModule() = default;
    CNWSModule(const CNWSModule&) = default;
    CNWSModule& operator=(const CNWSModule&) = default;

    CNWSModule(CExoString, int32_t, int32_t);
    ~CNWSModule();
    void AddObjectToLimbo(uint32_t);
    int32_t AddObjectToLookupTable(CExoString, uint32_t);
    void AddToTURDList(CNWSPlayerTURD*);
    void AddTURDsToWorld();
    void AddWorldJournalEntry(int32_t, CExoString, CExoString, uint32_t, uint32_t);
    void AddWorldJournalEntryStrref(uint32_t, uint32_t, uint32_t, uint32_t);
    int32_t AIUpdate();
    CNWSModule* AsNWSModule();
    void CleanUpLimboList();
    void ClearAreaVisitedFlags();
    int32_t ComputeInterAreaPath(CPathfindInformation*);
    void DeleteWorldJournalAllEntries();
    void DeleteWorldJournalEntry(int32_t);
    void DeleteWorldJournalEntryStrref(uint32_t);
    void DoUpdate();
    void EventHandler(uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uint32_t FindObjectByTagOrdinal(const CExoString&, uint32_t);
    uint32_t FindObjectByTagTypeOrdinal(const CExoString&, int32_t, uint32_t);
    int32_t FindTagPositionInTable(char*);
    uint32_t GenerateInterAreaDFSSuccessors(int32_t, CPathfindInformation*, uint32_t**);
    CNWSArea* GetArea(uint32_t);
    CNWSArea* GetArea(CResRef);
    CNWSArea* GetAreaByName(CExoString&);
    CNWSArea* GetAreaByTag(CExoString&);
    unsigned char* GetFullCipher(CExoString);
    uint32_t GetPlayerIndexInPlayerList(CNWSPlayer*);
    CNWSPlayerTURD* GetPlayerTURDFromList(CNWSPlayer*);
    uint32_t GetPrimaryPlayerIndex();
    void GetTime(uint32_t*, uint32_t*, uint32_t*, uint32_t*, unsigned char*, uint32_t*);
    uint32_t GetWaypoint(const CExoString&);
    uint32_t GetWorldJournalIndexUnique();
    int32_t InterAreaDFS(int32_t, int32_t, CPathfindInformation*);
    int32_t IsObjectInLimbo(uint32_t);
    unsigned char IsOfficialCampaign();
    int32_t LoadLimboCreatures(CResGFF*, CResStruct*, int32_t);
    uint32_t LoadModuleFinish();
    uint32_t LoadModuleInProgress(int32_t, int32_t);
    uint32_t LoadModuleStart(CExoString, int32_t);
    void LoadTURDList(CResGFF*, CResStruct*);
    void PackModuleIntoMessage(uint32_t);
    void PackModuleResourcesIntoMessage();
    void PackPlayerCharacterListIntoMessage(CNWSPlayer*, CExoArrayListTemplatedNWPlayerCharacterList_stPtr&);
    uint32_t PlotInterAreaPath(CPathfindInformation*, uint32_t);
    uint32_t PlotPath(CPathfindInformation*, uint32_t);
    uint32_t PlotPathInArea(CPathfindInformation*, uint32_t);
    void PostProcess();
    void RemoveFromTURDList(CNWSPlayer*);
    void RemoveObjectFromLimbo(uint32_t);
    int32_t RemoveObjectFromLookupTable(CExoString, uint32_t);
    void SaveLimboCreatures(CResGFF*, CResStruct*);
    int32_t SaveModuleFAC(CERFFile*);
    int32_t SaveModuleFinish(CExoString&, CExoString&);
    int32_t SaveModuleIFOFinish(CResGFF*, CResStruct*, CERFFile*, CExoString&, CExoArrayListTemplatedunsignedlong&);
    int32_t SaveModuleIFOStart(CResGFF*, CResStruct*);
    int32_t SaveModuleInProgress();
    void SaveModuleStart(CExoString&, CExoString&);
    int32_t SavePlayers(CResGFF*, CResStruct*, CExoString&, CExoArrayListTemplatedunsignedlong&);
    int32_t SaveStatic(CERFFile*, CExoString, uint16_t, int32_t);
    void SaveTURDList(CResGFF*, CResStruct*);
    void SetIntraAreaGoal(CPathfindInformation*);
    void TimeStopSanityCheck();
    void UnloadModule();
    void UpdateTime(uint32_t, uint32_t, uint32_t);
};

void CNWSModule__CNWSModuleCtor__0(CNWSModule* thisPtr, CExoString, int32_t, int32_t);
void CNWSModule__CNWSModuleDtor__0(CNWSModule* thisPtr);
void CNWSModule__AddObjectToLimbo(CNWSModule* thisPtr, uint32_t);
int32_t CNWSModule__AddObjectToLookupTable(CNWSModule* thisPtr, CExoString, uint32_t);
void CNWSModule__AddToTURDList(CNWSModule* thisPtr, CNWSPlayerTURD*);
void CNWSModule__AddTURDsToWorld(CNWSModule* thisPtr);
void CNWSModule__AddWorldJournalEntry(CNWSModule* thisPtr, int32_t, CExoString, CExoString, uint32_t, uint32_t);
void CNWSModule__AddWorldJournalEntryStrref(CNWSModule* thisPtr, uint32_t, uint32_t, uint32_t, uint32_t);
int32_t CNWSModule__AIUpdate(CNWSModule* thisPtr);
CNWSModule* CNWSModule__AsNWSModule(CNWSModule* thisPtr);
void CNWSModule__CleanUpLimboList(CNWSModule* thisPtr);
void CNWSModule__ClearAreaVisitedFlags(CNWSModule* thisPtr);
int32_t CNWSModule__ComputeInterAreaPath(CNWSModule* thisPtr, CPathfindInformation*);
void CNWSModule__DeleteWorldJournalAllEntries(CNWSModule* thisPtr);
void CNWSModule__DeleteWorldJournalEntry(CNWSModule* thisPtr, int32_t);
void CNWSModule__DeleteWorldJournalEntryStrref(CNWSModule* thisPtr, uint32_t);
void CNWSModule__DoUpdate(CNWSModule* thisPtr);
void CNWSModule__EventHandler(CNWSModule* thisPtr, uint32_t, uint32_t, void*, uint32_t, uint32_t);
uint32_t CNWSModule__FindObjectByTagOrdinal(CNWSModule* thisPtr, const CExoString&, uint32_t);
uint32_t CNWSModule__FindObjectByTagTypeOrdinal(CNWSModule* thisPtr, const CExoString&, int32_t, uint32_t);
int32_t CNWSModule__FindTagPositionInTable(CNWSModule* thisPtr, char*);
uint32_t CNWSModule__GenerateInterAreaDFSSuccessors(CNWSModule* thisPtr, int32_t, CPathfindInformation*, uint32_t**);
CNWSArea* CNWSModule__GetArea__0(CNWSModule* thisPtr, uint32_t);
CNWSArea* CNWSModule__GetArea__1(CNWSModule* thisPtr, CResRef);
CNWSArea* CNWSModule__GetAreaByName(CNWSModule* thisPtr, CExoString&);
CNWSArea* CNWSModule__GetAreaByTag(CNWSModule* thisPtr, CExoString&);
unsigned char* CNWSModule__GetFullCipher(CNWSModule* thisPtr, CExoString);
uint32_t CNWSModule__GetPlayerIndexInPlayerList(CNWSModule* thisPtr, CNWSPlayer*);
CNWSPlayerTURD* CNWSModule__GetPlayerTURDFromList(CNWSModule* thisPtr, CNWSPlayer*);
uint32_t CNWSModule__GetPrimaryPlayerIndex(CNWSModule* thisPtr);
void CNWSModule__GetTime(CNWSModule* thisPtr, uint32_t*, uint32_t*, uint32_t*, uint32_t*, unsigned char*, uint32_t*);
uint32_t CNWSModule__GetWaypoint(CNWSModule* thisPtr, const CExoString&);
uint32_t CNWSModule__GetWorldJournalIndexUnique(CNWSModule* thisPtr);
int32_t CNWSModule__InterAreaDFS(CNWSModule* thisPtr, int32_t, int32_t, CPathfindInformation*);
int32_t CNWSModule__IsObjectInLimbo(CNWSModule* thisPtr, uint32_t);
unsigned char CNWSModule__IsOfficialCampaign(CNWSModule* thisPtr);
int32_t CNWSModule__LoadLimboCreatures(CNWSModule* thisPtr, CResGFF*, CResStruct*, int32_t);
uint32_t CNWSModule__LoadModuleFinish(CNWSModule* thisPtr);
uint32_t CNWSModule__LoadModuleInProgress(CNWSModule* thisPtr, int32_t, int32_t);
uint32_t CNWSModule__LoadModuleStart(CNWSModule* thisPtr, CExoString, int32_t);
void CNWSModule__LoadTURDList(CNWSModule* thisPtr, CResGFF*, CResStruct*);
void CNWSModule__PackModuleIntoMessage(CNWSModule* thisPtr, uint32_t);
void CNWSModule__PackModuleResourcesIntoMessage(CNWSModule* thisPtr);
void CNWSModule__PackPlayerCharacterListIntoMessage(CNWSModule* thisPtr, CNWSPlayer*, CExoArrayListTemplatedNWPlayerCharacterList_stPtr&);
uint32_t CNWSModule__PlotInterAreaPath(CNWSModule* thisPtr, CPathfindInformation*, uint32_t);
uint32_t CNWSModule__PlotPath(CNWSModule* thisPtr, CPathfindInformation*, uint32_t);
uint32_t CNWSModule__PlotPathInArea(CNWSModule* thisPtr, CPathfindInformation*, uint32_t);
void CNWSModule__PostProcess(CNWSModule* thisPtr);
void CNWSModule__RemoveFromTURDList(CNWSModule* thisPtr, CNWSPlayer*);
void CNWSModule__RemoveObjectFromLimbo(CNWSModule* thisPtr, uint32_t);
int32_t CNWSModule__RemoveObjectFromLookupTable(CNWSModule* thisPtr, CExoString, uint32_t);
void CNWSModule__SaveLimboCreatures(CNWSModule* thisPtr, CResGFF*, CResStruct*);
int32_t CNWSModule__SaveModuleFAC(CNWSModule* thisPtr, CERFFile*);
int32_t CNWSModule__SaveModuleFinish(CNWSModule* thisPtr, CExoString&, CExoString&);
int32_t CNWSModule__SaveModuleIFOFinish(CNWSModule* thisPtr, CResGFF*, CResStruct*, CERFFile*, CExoString&, CExoArrayListTemplatedunsignedlong&);
int32_t CNWSModule__SaveModuleIFOStart(CNWSModule* thisPtr, CResGFF*, CResStruct*);
int32_t CNWSModule__SaveModuleInProgress(CNWSModule* thisPtr);
void CNWSModule__SaveModuleStart(CNWSModule* thisPtr, CExoString&, CExoString&);
int32_t CNWSModule__SavePlayers(CNWSModule* thisPtr, CResGFF*, CResStruct*, CExoString&, CExoArrayListTemplatedunsignedlong&);
int32_t CNWSModule__SaveStatic(CNWSModule* thisPtr, CERFFile*, CExoString, uint16_t, int32_t);
void CNWSModule__SaveTURDList(CNWSModule* thisPtr, CResGFF*, CResStruct*);
void CNWSModule__SetIntraAreaGoal(CNWSModule* thisPtr, CPathfindInformation*);
void CNWSModule__TimeStopSanityCheck(CNWSModule* thisPtr);
void CNWSModule__UnloadModule(CNWSModule* thisPtr);
void CNWSModule__UpdateTime(CNWSModule* thisPtr, uint32_t, uint32_t, uint32_t);

}

}
