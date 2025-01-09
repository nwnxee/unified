#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoString.hpp"
#include "CResRef.hpp"
#include "NWSyncAdvertisement.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CServerExoAppInternal)
#endif

struct C2DA;
struct CCampaignDB;
struct CConnectionLib;
struct CFactionManager;
struct CGameObject;
struct CGameObjectArray;
struct CNWPlaceMeshManager;
struct CNWSArea;
struct CNWSAreaOfEffectObject;
struct CNWSCreature;
struct CNWSDoor;
struct CNWSEncounter;
struct CNWSItem;
struct CNWSMessage;
struct CNWSModule;
struct CNWSObject;
struct CNWSPlaceable;
struct CNWSPlayer;
struct CNWSSoundObject;
struct CNWSStore;
struct CNWSTrigger;
struct CNWSWaypoint;
struct CNWSVirtualMachineCommands;
struct CNetLayer;
struct CServerAIMaster;
struct CServerInfo;
struct CWorldTimer;

namespace NWSync {
struct Advertisement; // NWSyncAdvertisement
}
struct AdvertLUT {
    std::unordered_map<CExoString, std::vector<void*>> m_map;
};

typedef int BOOL;
typedef uint32_t OBJECT_ID;
typedef uint16_t RESTYPE;
typedef uint32_t STRREF;


struct CServerExoAppInternal
{
    uint8_t ScratchMessageBuffer[65536];
    BOOL m_bMultiplayerEnabled;
    BOOL m_bGamePostedToInternet;
    BOOL m_bCDResponseReceived;
    CServerInfo * m_pServerInfo;
    int16_t m_nServerMode;
    CNWSVirtualMachineCommands * m_pVirtualMachineCommandImplementer;
    CNWSMessage * m_pMessage;
    BOOL m_bForceUpdate;
    uint32_t * m_pPendingAuthorization;
    CExoArrayList<OBJECT_ID> m_lstClientDisconnectPending;
    uint64_t m_nShutdownTimer;
    uint64_t m_nShutdownTimeStamp;
    uint64_t m_nShutdownMaxTimeLocalLogins;
    BOOL m_bReloadModuleWhenEmpty;
    CExoString m_sLastModuleLoadedFilename;
    BOOL m_bLastModuleLoadedWasSaveGame;
    BOOL m_bConnectionLoopFirstRun;
    CNetLayer * m_pNetLayer;
    CServerAIMaster * m_pServerAIMaster;
    CWorldTimer * m_pWorldTimer;
    CWorldTimer * m_pTimestopTimer;
    CWorldTimer * m_pPauseTimer;
    CFactionManager * m_pFactionManager;
    CConnectionLib * m_pConnectionLib;
    CCampaignDB * m_pCampaignDB;
    CGameObjectArray * m_pGameObjArray;
    OBJECT_ID m_oidModule;
    CExoArrayList<CNWSPlayer*> m_lstPlayerList;
    CNWPlaceMeshManager * m_pPlaceMeshManager;
    BOOL m_bDebugMode;
    CExoArrayList<OBJECT_ID> * m_lstPauseExclusionList;
    CExoArrayList<OBJECT_ID> * m_lstTimestopExclusionList;
    uint8_t m_nPauseState;
    BOOL m_bDoingStartNewModule;
    BOOL m_bMoveToModulePending;
    CExoString m_sMoveToModuleString;
    BOOL m_bEndGamePending;
    CExoString m_sEndGameMovie;
    BOOL m_bLoadingModule;
    BOOL m_bImportingChar;
    BOOL m_bAutoSavePending;
    BOOL m_bDisableAutoSave;
    BOOL m_bExportCharacterPending;
    CExoArrayList<OBJECT_ID> m_exportPlayerCharacterRequests;
    BOOL m_bNeedSinglePlayerCharacter;
    uint32_t m_nEstimatedSaveSize;
    CExoArrayList<uint32_t> m_nCharListRequests;
    CExoArrayList<CExoString> m_lstBannedListIP;
    CExoArrayList<CExoString> m_lstBannedListCDKey;
    CExoArrayList<CExoString> m_lstBannedListPlayerName;
    C2DA * m_pOldServerVault2DA;
    C2DA * m_pKnownServerNames2DA;
    uint32_t m_nBannedListsTimeStamp;
    int32_t m_nPosPCObject;
    int m_nGameObjectUpdateIntervalTarget;
    int m_nGameObjectUpdateIntervalTargetLoading;
    int m_nGameObjectUpdateMessageLimit;
    int m_nGameObjectUpdateMessageLimitLoading;
    uint64_t m_nLastGameObjectUpdateDuration = 0;
    uint64_t m_nAutoSaveTimer;
    BOOL m_bCreatureDeathLoggingEnabled;
    uint32_t m_nClientsRequiredToDisableCPUSleep;
    BOOL m_bStickyCombatModesEnabled;
    int32_t m_AttackBonusLimit;
    int32_t m_DamageBonusLimit;
    int32_t m_SavingThrowBonusLimit;
    int32_t m_AbilityBonusLimit;
    int32_t m_AbilityPenaltyLimit;
    int32_t m_SkillBonusLimit;
    int32_t m_AttackBonusLimitModule;
    int32_t m_DamageBonusLimitModule;
    int32_t m_SavingThrowBonusLimitModule;
    int32_t m_AbilityBonusLimitModule;
    int32_t m_AbilityPenaltyLimitModule;
    int32_t m_SkillBonusLimitModule;
    NWSync::Advertisement m_nwsyncModuleSourceAdvert;
    AdvertLUT m_nwsyncAdvertLUT;

    CServerExoAppInternal();
    ~CServerExoAppInternal();
    BOOL Initialize();
    BOOL MainLoop();
    void StartServices();
    void StopServices();
    void ShutdownNetLayer();
    void RestartNetLayer();
    void Uninitialize();
    BOOL AdmitNetworkAddress(CExoString sAddress);
    BOOL AdmitPlayerName(CExoString sPlayerName);
    void HandleMessage(uint32_t nPlayerId, uint8_t * pData, uint32_t dwSize);
    BOOL SetNetworkAddressBan(CExoString sAddress, BOOL bBanAddress);
    void PlayerListChange(uint32_t nPlayerId, BOOL bEnter, BOOL bPrimaryPlayer);
    BOOL ContinueMessageProcessing();
    void RemovePCFromWorld(CNWSPlayer * pPlayer);
    void Shutdown(BOOL bWarnLocals, BOOL bFromMessage = false);
    BOOL ValidatePlayerLogin(void * pPlayer);
    void OnCDChange();
    void OnExit();
    void OnGainFocus();
    void OnLostFocus();
    void OnVideoChange();
    CWorldTimer * GetActiveTimer(OBJECT_ID oid = 0x7f000000);
    CNWSPlayer * GetClientObjectByObjectId(OBJECT_ID nObjectId);
    CNWSPlayer * GetClientObjectByPlayerId(uint32_t nPlayerId);
    BOOL CopyModuleToCurrentGame(CExoString & sOldFilename, CExoString & sNewFilename, RESTYPE nResType);
    BOOL LoadGame(uint32_t nSlot, CExoString & sSaveName, CExoString & sModuleName, CNWSPlayer * pPlayer = nullptr);
    void SetEstimatedSaveSize(const CExoString & sFile, RESTYPE nResType);
    BOOL StartNewModule(CExoString & sModuleName);
    BOOL EndGame(const CExoString & sMovieName);
    STRREF ValidateCreateServerCharacter(CNWSPlayer * pPlayer, void * pCharData, uint32_t nSize);
    BOOL LoadCharacterStart(uint8_t nType, CNWSPlayer * pPlayer, CResRef cResRef, void * pCharData = nullptr, uint32_t nSize = 0);
    BOOL LoadCharacterFinish(CNWSPlayer * pPlayer, BOOL bUseSaveGameCharacter = false, BOOL bUseStateDataInSaveGame = false);
    BOOL LoadPrimaryPlayer(CNWSPlayer * pPlayer);
    BOOL ExportAllPlayers();
    BOOL ExportPlayer(CNWSPlayer * pPlayer);
    void DealWithLoadGameError(uint32_t nLoadErr);
    CNWSModule * GetModule();
    CExoString GetModuleName();
    CGameObject * GetGameObject(OBJECT_ID nObjectID);
    CNWSStore * GetStoreByGameObjectID(OBJECT_ID nObjectID);
    CNWSItem * GetItemByGameObjectID(OBJECT_ID nObjectID);
    CNWSCreature * GetCreatureByGameObjectID(OBJECT_ID nObjectID);
    CNWSModule * GetModuleByGameObjectID(OBJECT_ID nObjectID);
    CNWSArea * GetAreaByGameObjectID(OBJECT_ID nObjectID);
    CNWSTrigger * GetTriggerByGameObjectID(OBJECT_ID nObjectID);
    CNWSPlaceable * GetPlaceableByGameObjectID(OBJECT_ID nObjectID);
    CNWSDoor * GetDoorByGameObjectID(OBJECT_ID nObjectID);
    CNWSAreaOfEffectObject * GetAreaOfEffectByGameObjectID(OBJECT_ID nObjectID);
    CNWSWaypoint * GetWaypointByGameObjectID(OBJECT_ID nObjectID);
    CNWSEncounter * GetEncounterByGameObjectID(OBJECT_ID nObjectID);
    CNWSSoundObject * GetSoundObjectByGameObjectID(OBJECT_ID nObjectID);
    uint32_t GetPlayerIDByGameObjectID(OBJECT_ID nObjectID);
    int32_t GetPlayerLanguage(uint32_t nPlayerID);
    int32_t GetModuleLanguage();
    //CNetPeer GetPlayerAddressData(CNetConnectionId nConnectionId);
    void GetExtendedServerInfo(class CExtendedServerInfo * pInfo);
    void UpdateClientsForObject(OBJECT_ID oidObjectToUpdate);
    void MarkUpdateClientsForObject(OBJECT_ID oidObjectToUpdate);
    void UpdateClientGameObjectsForPlayer(CNWSPlayer * pPlayer, BOOL bForce, uint64_t nCurrentSystemTime = 0);
    BOOL UnloadModule();
    BOOL LoadModule(CExoString moduleResRef, CUUID uuidOverride, BOOL bIsSaveGame, CNWSPlayer * pPlayer, int32_t sourceType, const NWSync::Advertisement & nwsyncModuleSourceAdvert);
    BOOL GetModuleExists(const CExoString & sModuleResRef);
    BOOL RunModule();
    void VomitServerOptionsToLog();
    CExoString GetPlayerListString();
    CExoString GetBannedListString();
    CExoString GetPortalListString();
    void MovePlayerToArea(void * pPlayer);
    void InitiateModuleForPlayer(void * pPlayer);
    void UpdateWindowTitle();
    BOOL GetFactionOfObject(OBJECT_ID oObject, int32_t * nFaction);
    BOOL SendCharacterQuery(CNWSPlayer * pPlayer);
    BOOL SendStartStallEvent(uint32_t nStallEvent);
    void TogglePauseState(uint8_t nState);
    BOOL GetPauseState(uint8_t nState);
    uint8_t GetActivePauseState();
    void SetPauseState(uint8_t nState, BOOL bPause);
    CExoArrayList<OBJECT_ID> * GetActiveExclusionList();
    void AddToExclusionList(OBJECT_ID oidExclude, uint8_t nList);
    void RemoveFromExclusionList(OBJECT_ID oidExclude, uint8_t nList);
    BOOL IsOnActiveExclusionList(OBJECT_ID oidExclude);
    void ReprocessExclusionListActions(uint8_t nOldState);
    uint32_t ResolvePlayerByFirstName(const CExoString & sName);
    BOOL SendEnhancedHeartbeatToMasterServer();
    BOOL SendHeartbeatToRelay();
    int32_t GetDifficultyOption(int32_t nOption);
    void AddCharListRequest(uint32_t nPlayerId);
    BOOL IsOnExclusionList(OBJECT_ID oidToExamine);
    void AddIPToBannedList(CExoString sIP);
    void AddPlayerNameToBannedList(CExoString sPlayerName);
    void AddCDKeyToBannedList(CExoString sKey);
    void RemoveIPFromBannedList(CExoString sIP);
    void RemovePlayerNameFromBannedList(CExoString sPlayerName);
    void RemoveCDKeyFromBannedList(CExoString sKey);
    BOOL GetIsIPOnBannedList(CExoString sIP);
    BOOL GetIsPlayerNameOnBannedList(CExoString sPlayerName);
    BOOL GetIsCDKeyOnBannedList(CExoString sKey);
    void HandleOldServerVaultMigration(CExoString sClientCDKey, CExoString sLegacyCDKey, CExoString sPlayerName);
    BOOL IsPlayerNameSticky();
    BOOL CheckStickyPlayerNameReserved(CExoString sClientCDKey, CExoString sLegacyCDKey, CExoString sPlayerName, int32_t nConnectionType);
    OBJECT_ID GetFirstPCObject();
    OBJECT_ID GetNextPCObject();
    void StallEventSaveGame();
    void PushMessageOverWall(uint8_t * pData, uint32_t nMsgLength);
    void UnlockBiowareModule(CNWSModule * pModule);
    BOOL CreateServerVaultLostAndFound();
    BOOL StripColorTokens(CExoString & sInput);
    CExoString GetHostedPublicInternetAddressAndPort();
    int GetGameObjectUpdateInterval(CNWSObject * creature);
    int GetGameObjectUpdateMessageLimit(CNWSObject * creature);
    void SetGameObjectUpdateIntervalTarget(int target);
    void SetGameObjectUpdateIntervalTargetLoading(int target);
    void SetGameObjectUpdateMessageLimit(int target);
    void SetGameObjectUpdateMessageLimitLoading(int target);
    BOOL StorePlayerCharacters();
    BOOL SendEnteringStartNewModuleMessage();
    BOOL SendExitingStartNewModuleMessage(BOOL bSuccess);
    void QuarantineInvalidCharacter(void * pData, uint32_t nSize);
    void UpdateClientGameObjects(BOOL bForce);
    void InitializeNetLayer();
    void GetServerInfoFromIniFile();
    void ReadBannedLists();
    void WriteServerInfoToIniFile();
    BOOL AddPendingAuthorization(uint32_t nPlayerID);
    BOOL RemovePendingAuthorization(uint32_t nPlayerID);
    void ConnectionLibMainLoop();
    void StartShutdownTimer(uint64_t nTime, uint64_t nDelay);
    BOOL UpdateShutdownTimer(uint64_t nTime);
    BOOL UpdateAutoSaveTimer();


#ifdef NWN_CLASS_EXTENSION_CServerExoAppInternal
    NWN_CLASS_EXTENSION_CServerExoAppInternal
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CServerExoAppInternal)
#endif

