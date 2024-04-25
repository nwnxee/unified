#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLinkedList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CGameObject.hpp"
#include "CNWSPlayerTURD.hpp"
#include "CNWSScriptVarTable.hpp"
#include "CNWSTagNode.hpp"
#include "CResHelper.hpp"
#include "CResIFO.hpp"
#include "CResRef.hpp"
#include "CWorldJournalEntry.hpp"
#include "NWMODULECUTSCENE.hpp"
#include "NWPLAYERLISTITEM.hpp"
#include "NWPlayerCharacterList_st.hpp"
#include "NWSyncAdvertisement.hpp"
#include "Vector.hpp"
#include "Database.hpp"
#include <memory>


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSModule)
#endif

struct CERFFile;
struct CGameEffect;
struct CNWSArea;
struct CNWSPlayer;
struct CPathfindInformation;
struct CResGFF;
struct CResStruct;
struct NWMODULEENTRYINFO;
struct NWMODULEHEADER;
struct NWPLAYERCHARACTERLISTITEM;

namespace NWSync {
struct Advertisement; // NWSyncAdvertisement
}

typedef int BOOL;
typedef uint32_t OBJECT_ID;
typedef uint16_t RESTYPE;
typedef uint32_t STRREF;


struct CNWSModule : CResHelper<CResIFO, 2014>, CGameObject
{
    CExoLinkedList<NWMODULECUTSCENE> m_lstModuleCutScene;
    CExoLinkedList<CResRef> m_lstModuleArea;
    CExoArrayList<OBJECT_ID> m_lstModuleAreaID;
    int32_t m_nLastAreaAIUpdatePos;
    CExoLinkedList<NWPLAYERLISTITEM> m_lstPlayerInfo;
    CExoLinkedList<CNWSPlayerTURD> m_lstTURDList;
    CExoLocString m_lsModuleDescription;
    CExoString m_sModuleAltTLKFile;
    NWSync::Advertisement m_nwsyncModuleSourceAdvert;
    NWMODULEHEADER * m_pModuleHeader;
    NWMODULEENTRYINFO * m_pModuleEntryInfo;
    CUUID m_cModUUID;
    CExoString m_sModuleResourceName;
    int32_t m_nSourceType;
    CExoLocString m_lsModuleName;
    CExoArrayList<CExoString> m_pHakFiles;
    CResRef m_cStartMovie;
    CNWSScriptVarTable m_ScriptVars;
    CExoString m_sScripts[22];
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    CExoArrayList<CNWSTagNode> m_aTagLookupTable;
    CExoArrayList<OBJECT_ID> m_pInvisibleCreaturesList;
    int32_t m_nCustomScriptEventId;
    OBJECT_ID m_oidLastEnter;
    OBJECT_ID m_oidLastExit;
    OBJECT_ID m_oidLastItemAcquired;
    OBJECT_ID m_oidLastItemAcquiredFrom;
    OBJECT_ID m_oidLastItemAcquiredBy;
    OBJECT_ID m_oidLastItemLost;
    OBJECT_ID m_oidLastItemLoser;
    int32_t m_nLastItemAcquiredSize;
    int32_t m_nLastItemLostSize;
    OBJECT_ID m_oidLastItemEquipped;
    OBJECT_ID m_oidLastItemEquippedBy;
    OBJECT_ID m_oidLastItemUnequipped;
    OBJECT_ID m_oidLastItemUnequippedBy;
    int32_t m_nLastItemEquippedSlot;
    int32_t m_nLastItemUnequippedSlot;
    OBJECT_ID m_oidLastRested;
    uint8_t m_nLastRestEventType;
    OBJECT_ID m_oidLastPlayerDied;
    OBJECT_ID m_oidLastPlayerDying;
    OBJECT_ID m_oidLastRespawnButtonPresser;
    OBJECT_ID m_oidLastItemActivated;
    OBJECT_ID m_oidLastItemActivator;
    OBJECT_ID m_oidLastItemActivatedArea;
    OBJECT_ID m_oidLastItemActivatedTarget;
    Vector m_vLastItemActivatedPosition;
    OBJECT_ID m_oidLastPCLevellingUp;
    OBJECT_ID m_oidLastPCCancelCutscene;
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
    BOOL m_bIsSaveGame;
    CExoArrayList<CWorldJournalEntry> m_pWorldJournal;
    BOOL m_bModuleLoadFinished;
    int32_t m_nMaxHenchmen;
    int32_t m_nPartyControlMode;
    CExoArrayList<OBJECT_ID> m_aGameObjectsLimbo;
    CERFFile * m_pOutFile;
    CResStruct * m_pStructIFO;
    CResGFF * m_pResIFO;
    CExoArrayList<OBJECT_ID> * m_apPlayers;
    CExoString m_sTag;
    BOOL m_bIsNWMFile;
    CExoString m_sNWMResName;
    int32_t m_nResourceCount;
    uint8_t m_nPlayerPathfindRule;
    uint8_t m_nEnableScriptDebugger;
    OBJECT_ID m_oidLastPlayerChatObjectId;
    CExoString m_sLastPlayerChatMessage;
    uint8_t m_nLastPlayerChatType;
    OBJECT_ID m_oidLastPlayerToSelectTarget;
    OBJECT_ID m_oidPlayerTargetObject;
    Vector m_vPlayerTargetPosition;
    CGameEffect * m_pLastRunScriptEffect;
    int32_t m_nLastRunScriptEffectScriptType;
    std::shared_ptr<NWSQLite::Database> m_sqlite3;
    OBJECT_ID m_oidLastGuiEventPlayer;
    int32_t m_nLastGuiEventType;
    int32_t m_nLastGuiEventInteger;
    OBJECT_ID m_oidLastGuiEventObject;
    Vector m_vLastGuiEventVector;
    OBJECT_ID m_oidLastPlayerToDoTileAction;
    int32_t m_nLastPlayerTileActionId;
    Vector m_vLastPlayerTileActionPosition;
    Nui::JSON::Event m_cCurrentNuiEvent;

    CNWSModule(CExoString sModuleFilename, CUUID cModUUID, BOOL bSetAutoRequest, BOOL bIsSaveGame = false, int32_t nSourceType = 0);
    ~CNWSModule();
    virtual CNWSModule * AsNWSModule();
    void DoUpdate();
    BOOL AIUpdate();
    BOOL ComputeInterAreaPath(CPathfindInformation * pcPathfindInformation);
    void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    uint32_t GenerateInterAreaDFSSuccessors(int32_t level, CPathfindInformation * pcPathfindInformation, OBJECT_ID * * pAreaSuccessors);
    CNWSArea * GetArea(CResRef refArea);
    CNWSArea * GetArea(OBJECT_ID oid);
    CNWSArea * GetAreaByName(CExoString & cAreaName);
    CNWSArea * GetAreaByTag(CExoString & sAreaTag);
    void ClearAreaVisitedFlags();
    BOOL InterAreaDFS(int32_t level, int32_t depth, CPathfindInformation * pcPathfindInformation);
    uint32_t LoadModuleStart(CExoString sModuleName, BOOL bIsSaveGame = false, int32_t nSourceType = 0, const NWSync::Advertisement & nwsyncModuleSourceAdvert = {});
    uint32_t LoadModuleInProgress(int32_t nAreasLoaded, int32_t nAreasToLoad);
    uint32_t LoadModuleFinish();
    void PackModuleResourcesIntoMessage();
    void PackModuleIntoMessage(uint32_t nPlayerId);
    uint32_t PlotPath(CPathfindInformation * pcPathfindInformation, uint32_t nTimeSlice);
    uint32_t PlotInterAreaPath(CPathfindInformation * pcPathfindInformation, uint32_t nTimeSlice);
    uint32_t PlotPathInArea(CPathfindInformation * pcPathfindInformation, uint32_t nTimeSlice);
    void SaveModuleStart(CExoString & sFilePath, CExoString & sFileName);
    BOOL SaveModuleInProgress();
    BOOL SaveModuleFinish(CExoString & sFilePath, CExoString & sFileName);
    uint32_t GetPlayerIndexInPlayerList(CNWSPlayer * pPlayer);
    uint32_t GetPrimaryPlayerIndex();
    void PackPlayerCharacterListIntoMessage(CNWSPlayer * pPlayer, CExoArrayList<NWPlayerCharacterList_st *> & lstChars);
    void SetIntraAreaGoal(CPathfindInformation * pcPathfindInformation);
    void UnloadModule();
    OBJECT_ID GetWaypoint(const CExoString & sTag);
    BOOL AddObjectToLookupTable(CExoString sTag, OBJECT_ID oidObject);
    BOOL RemoveObjectFromLookupTable(CExoString sTag, OBJECT_ID oidObject);
    OBJECT_ID FindObjectByTagOrdinal(const CExoString & sTag, uint32_t nNth = 0);
    OBJECT_ID FindObjectByTagTypeOrdinal(const CExoString & sTag, int32_t nObjectType, uint32_t nNth = 0);
    void GetTime(uint32_t * pYear, uint32_t * pMonth, uint32_t * pDay, uint32_t * pHour, uint8_t * pTimeOfDayState, uint32_t * pTimeIntoTransition);
    void UpdateTime(uint32_t nCalendarDay, uint32_t nTimeOfDay, uint32_t nUpdateDifference);
    void AddWorldJournalEntry(int32_t nIndex, CExoString szEntry, CExoString szTitle, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    void AddWorldJournalEntryStrref(STRREF strrefEntry, STRREF strrefTitle, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    void DeleteWorldJournalEntry(int32_t nIndex);
    void DeleteWorldJournalEntryStrref(STRREF strref);
    void DeleteWorldJournalAllEntries();
    uint32_t GetWorldJournalIndexUnique();
    void AddToTURDList(CNWSPlayerTURD * pTURD);
    void RemoveFromTURDList(CNWSPlayer * pPlayer);
    void SaveTURDList(CResGFF * pResIFO, CResStruct * pStructIFO);
    void LoadTURDList(CResGFF * pResIFO, CResStruct * pStructIFO);
    void AddTURDsToWorld();
    CNWSPlayerTURD * GetPlayerTURDFromList(CNWSPlayer * pPlayer);
    void AddObjectToLimbo(OBJECT_ID id);
    void RemoveObjectFromLimbo(OBJECT_ID id);
    BOOL IsObjectInLimbo(OBJECT_ID id);
    void CleanUpLimboList();
    uint8_t IsOfficialCampaign(void );
    void DestroyModuleSqliteDatabase();
    BOOL RunEventScript(int32_t nScript, CExoString * psOverrideScriptName = nullptr);
    BOOL GetPlayerPartyControl();
    void PostProcess();
    BOOL SaveModuleIFOStart(CResGFF * pRes, CResStruct * pTopLevelStruct);
    BOOL SaveModuleIFOFinish(CResGFF * pRes, CResStruct * pTopLevelStruct, CERFFile * cSaveFile, CExoString & sPath, CExoArrayList<OBJECT_ID> & aPlayers);
    void SaveLimboCreatures(CResGFF * pRes, CResStruct * pTopLevelStruct);
    BOOL LoadLimboCreatures(CResGFF * pRes, CResStruct * pStruct, BOOL bLoadStateInfo);
    BOOL SaveSqliteDatabase(CERFFile * cSaveFile);
    BOOL LoadSqliteDatabase();
    BOOL SaveModuleFAC(CERFFile * cSaveFile);
    BOOL SaveStatic(CERFFile * cSaveFile, CExoString sFileType, RESTYPE nResType, BOOL bIsGFF = true);
    BOOL SavePlayers(CResGFF * pResIFO, CResStruct * pStructIFO, CExoString & sPath, CExoArrayList<OBJECT_ID> & aPlayers);
    void TimeStopSanityCheck();
    int32_t FindTagPositionInTable(const char * szTag);


#ifdef NWN_CLASS_EXTENSION_CNWSModule
    NWN_CLASS_EXTENSION_CNWSModule
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSModule)
#endif

