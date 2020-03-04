#pragma once
#include "nwn_api.hpp"

#include "AurList.hpp"
#include "CBaseExoApp.hpp"
#include "CExoArrayList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CServerExoApp)
#endif

struct CCampaignDB;
struct CConnectionLib;
struct CGameObject;
struct CGameObjectArray;
struct CNWSArea;
struct CNWSAreaOfEffectObject;
struct CNWSClient;
struct CNWSCreature;
struct CNWSDoor;
struct CNWSEncounter;
struct CNWSItem;
struct CNWSModule;
struct CNWSPlaceable;
struct CNWSPlayer;
struct CNWSSoundObject;
struct CNWSStore;
struct CNWSTrigger;
struct CNWSWaypoint;
struct CNetLayer;
struct CServerAIMaster;
struct CServerExoAppInternal;
struct CWorldTimer;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CServerExoApp : CBaseExoApp
{
    CServerExoAppInternal * m_pcExoAppInternal;

    CServerExoApp(void );
    virtual ~CServerExoApp();
    BOOL AdmitNetworkAddress(uint32_t nProtocol, CExoString sAddress);
    BOOL SetNetworkAddressBan(uint32_t nProtocol, CExoString sAddress, BOOL bBanPlayer);
    BOOL AdmitPlayerName(CExoString sPlayerName);
    void PlayerListChange(uint32_t nPlayerId, BOOL bEnter, BOOL bPrimaryPlayer = false);
    void VomitServerOptionsToLog();
    BOOL ContinueMessageProcessing();
    void RemovePCFromWorld(CNWSPlayer * pPlayer);
    void Shutdown(BOOL bWarnLocals, BOOL bFromMessage = false);
    void SetGameSpyReporting(BOOL bEnabled);
    BOOL GetIniFileName(CExoString & sName);
    class CServerInfo * GetServerInfo();
    CExoLocString GetModuleDescription();
    void GetExtendedServerInfo(class CExtendedServerInfo * pInfo);
    CNWSModule * GetModule();
    CExoString GetModuleName();
    BOOL LoadGame(uint32_t nSlot, CExoString & sSaveName, CExoString & sModuleName, CNWSPlayer * pPlayer = nullptr);
    BOOL StartNewModule(CExoString & sModuleName);
    void SetMoveToModulePending(BOOL bPending);
    BOOL GetMoveToModulePending();
    void SetEndGamePending(BOOL bPending);
    void SetEndGameString(CExoString & sMovieName);
    void SetMoveToModuleString(CExoString & sModName);
    CExoString GetMoveToModuleString();
    void SetLoadingModule(BOOL bLoading);
    BOOL GetLoadingModule();
    void SetImportingChar(BOOL bImporting);
    BOOL GetImportingChar();
    void SetAutoSavePending(BOOL bPending);
    BOOL GetAutoSavePending();
    BOOL ExportAllPlayers();
    BOOL GetExportCharacterPending();
    void SetExportCharacterPending(BOOL bPending);
    void AddExportPlayersCharacterRequest(OBJECT_ID oid);
    const CExoArrayList<OBJECT_ID> & GetExportPlayersCharacterRequests();
    void ClearExportPlayerCharacterRequests();
    BOOL LoadCharacterStart(uint8_t nType, CNWSPlayer * pPlayer, CResRef cResRef, void * pCharData = nullptr, uint32_t nSize = 0);
    BOOL LoadCharacterFinish(CNWSPlayer * pPlayer, BOOL bUseSaveGameCharacter = false, BOOL bUseStateDataInSaveGame = false);
    BOOL LoadPrimaryPlayer(CNWSPlayer * pPlayer);
    CGameObjectArray * GetObjectArray();
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
    CServerAIMaster * GetServerAIMaster();
    void * GetSysAdminList();
    void * GetPlayerList();
    void * GetNWSMessage();
    CNetLayer * GetNetLayer();
    class CNWPlaceMeshManager * GetPlaceMeshManager();
    int16_t GetServerMode();
    void SetDebugMode(BOOL bMode);
    BOOL GetDebugMode();
    CWorldTimer * GetActiveTimer(OBJECT_ID oid = 0x7f000000);
    CWorldTimer * GetWorldTimer();
    CWorldTimer * GetTimestopTimer();
    CWorldTimer * GetPauseTimer();
    BOOL HandleMessage(uint32_t nPlayerId, uint8_t * pData, uint32_t dwSize, BOOL bRawMessage);
    BOOL Initialize();
    void LoadAliases();
    BOOL UnloadModule();
    BOOL LoadModule(CExoString moduleResRef, BOOL bIsSaveGame = false, CNWSPlayer * pPlayer = nullptr, int32_t sourceType = 0);
    BOOL RunModule();
    CExoString GetPlayerListString();
    CExoString GetBannedListString();
    CExoString GetPortalListString();
    BOOL MainLoop();
    void OnCDChange();
    void OnExit();
    void OnGainFocus();
    void OnLostFocus();
    void OnVideoChange();
    void StartServices();
    void ShutdownNetLayer();
    void RestartNetLayer();
    void StopServices();
    void Uninitialize();
    void SetForceUpdate();
    BOOL SendCharacterQuery(CNWSPlayer * pPlayer);
    CNWSPlayer * GetClientObjectByObjectId(OBJECT_ID nObjectId);
    void TogglePauseState(uint8_t nState);
    BOOL GetPauseState(uint8_t nState);
    uint8_t GetActivePauseState();
    void SetPauseState(uint8_t nState, BOOL bPause);
    AurList<OBJECT_ID> * GetActiveExclusionList();
    void AddToExclusionList(OBJECT_ID oidExclude, uint8_t nList);
    void RemoveFromExclusionList(OBJECT_ID oidExclude, uint8_t nList);
    BOOL IsOnActiveExclusionList(OBJECT_ID oidExclude);
    BOOL GetIsControlledByPlayer(OBJECT_ID oidObject);
    CNWSClient * GetClientObjectByPlayerId(uint32_t nPlayerId, uint8_t nClientType = 0);
    BOOL ValidatePlayerLogin(void * pPlayer);
    void MovePlayerToArea(void * pPlayer);
    void InitiateModuleForPlayer(void * pPlayer);
    void HandleGameSpyToServerMessage(int32_t nKeyId, void * pOutBuf, int nIndex = - 1);
    CConnectionLib * GetConnectionLib();
    CCampaignDB * GetCampaignDB();
    BOOL GetPlayerAddressData(uint32_t nConnectionId, uint32_t * nProtocol, uint8_t * * pNetAddress1, uint8_t * * pNetAddress2, uint32_t * nPort);
    BOOL GetFactionOfObject(OBJECT_ID oObject, int32_t * nFaction);
    uint32_t ResolvePlayerByFirstName(const CExoString & sName);
    BOOL GetMultiplayerEnabled(void );
    void SetReloadModuleWhenEmpty(BOOL bReloadModuleWhenEmpty);
    BOOL GetReloadModuleWhenEmpty();
    int32_t GetDifficultyOption(int32_t nOption);
    void AddCharListRequest(uint32_t nPlayerId);
    uint32_t GetApplicationId();
    BOOL IsOnExclusionList(OBJECT_ID oidTarget);
    void AddIPToBannedList(CExoString sIP);
    void AddPlayerNameToBannedList(CExoString sPlayerName);
    void AddCDKeyToBannedList(CExoString sKey);
    void RemoveIPFromBannedList(CExoString sIP);
    void RemovePlayerNameFromBannedList(CExoString sPlayerName);
    void RemoveCDKeyFromBannedList(CExoString sKey);
    BOOL GetIsIPOnBannedList(CExoString sIP);
    BOOL GetIsPlayerNameOnBannedList(CExoString sPlayerName);
    BOOL GetIsCDKeyOnBannedList(CExoString sKey);
    void HandleOldServerVaultMigration(CExoString sClientCDKey, CExoString sClientLegacyCDKey, CExoString sPlayerName);
    BOOL IsPlayerNameSticky();
    BOOL CheckStickyPlayerNameReserved(CExoString sClientCDKey, CExoString sClientLegacyCDKey, CExoString sPlayerName, int32_t nConnectionType);
    OBJECT_ID GetFirstPCObject();
    OBJECT_ID GetNextPCObject();
    void PushMessageOverWall(uint8_t * pData, uint32_t nMsgLength);
    BOOL GetIsMultiPlayer();
    void SetGameSpyEnabled(BOOL b);
    BOOL GetGameSpyEnabled();
    BOOL StripColorTokens(CExoString & sInput);
    void AddSubNetProfileSendSize(uint32_t nPlayerID, uint32_t nSize);
    BOOL GetCreatureDeathLogging();
    void SetCreatureDeathLogging(BOOL );
    BOOL GetHeartBeatLogging();
    void SetHeartBeatLogging(BOOL );
    uint32_t GetClientsRequiredToDisableCPUSleep();
    BOOL GetStickyCombatModesEnabled();
    void SetStickyCombatModesEnabled(BOOL v);
    int32_t GetAttackBonusLimit();
    void SetAttackBonusLimit(int32_t newLimit, BOOL isModuleOverride = false);
    int32_t GetDamageBonusLimit();
    void SetDamageBonusLimit(int32_t newLimit, BOOL isModuleOverride = false);
    int32_t GetSavingThrowBonusLimit();
    void SetSavingThrowBonusLimit(int32_t newLimit, BOOL isModuleOverride = false);
    int32_t GetAbilityBonusLimit();
    void SetAbilityBonusLimit(int32_t newLimit, BOOL isModuleOverride = false);
    int32_t GetAbilityPenaltyLimit();
    void SetAbilityPenaltyLimit(int32_t newLimit, BOOL isModuleOverride = false);
    int32_t GetSkillBonusLimit();
    void SetSkillBonusLimit(int32_t newLimit, BOOL isModuleOverride = false);
    CExoString GetHostedPublicInternetAddressAndPort();
    BOOL SetDDCipherForModule(CExoString moduleName);


#ifdef NWN_CLASS_EXTENSION_CServerExoApp
    NWN_CLASS_EXTENSION_CServerExoApp
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CServerExoApp)
#endif

