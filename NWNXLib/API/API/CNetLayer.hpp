#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNetLayer)
#endif

struct CBaseExoApp;
struct CNetLayerInternal;
struct CNetLayerPlayerInfo;
struct CNetLayerSessionInfo;
struct NWSyncAdvertisement;


typedef int BOOL;


struct CNetLayer
{
    CNetLayerInternal * m_pcNetLayerInternal;

    CNetLayer();
    ~CNetLayer();
    BOOL Initialize(CBaseExoApp * pcExoApp);
    class CBaseExoApp * GetExoApp();
    BOOL ShutDown();
    BOOL StartProtocol(uint32_t nProtocol, uint32_t nSendingAddress, uint32_t nReceivingAddress, uint32_t nInstance);
    BOOL EndProtocol(uint32_t nProtocol);
    void SetServerLanguage(int32_t nLanguage);
    BOOL StartServerMode(CExoString sSessionName, uint32_t nMaxPlayers);
    BOOL GetPasswordRequired();
    CExoString GetPlayerPassword();
    BOOL SetPlayerPassword(CExoString sPlayerPassword);
    CExoString GetGameMasterPassword();
    BOOL SetGameMasterPassword(CExoString sGameMasterPassowrd);
    CExoString minPassword();
    BOOL SetServerAdminPassword(CExoString sServerAdminPassword);
    CExoString GetServerAdminPassword();
    BOOL EndServerMode();
    BOOL GetServerConnected();
    CNetLayerPlayerInfo * GetPlayerInfo(uint32_t nPlayerId);
    CExoString GetPlayerAddress(uint32_t nPlayerId, BOOL bIncludePort = false);
    BOOL GetPlayerAddressRelayed(uint32_t nPlayerId);
    BOOL DisconnectPlayer(uint32_t nPlayerId, uint32_t nStrRef = 5838, BOOL bCDAuthFail = true, const CExoString & reason = "");
    uint32_t GetDisconnectStrref();
    void SetDisconnectStrref(uint32_t nStrref);
    CExoString GetDisconnectReason();
    void SetDisconnectReason(const CExoString & sReason);
    void SetUpPlayBackConnection();
    void StartAddressTranslation(const CExoString & sInternetAddress);
    BOOL GetAddressTranslationResult(const CExoString & sInternetAddress, CExoArrayList<uint32_t> & nIPv4);
    void EndAddressTranslation(const CExoString & sInternetAddress);
    BOOL StartEnumerateSessionsSection(uint32_t nEnumerateSection, uint32_t nSize, CExoString * sServerListToEnumerate);
    BOOL EnumerateSessionsLoop();
    BOOL GetAnySessionsEnumerated();
    BOOL EndEnumerateSessionsSection(uint32_t nEnumerateSection);
    BOOL EndEnumerateSessions();
    void CleanUpEnumerateSpecific();
    uint32_t GetSessionSectionStart(uint32_t sectionSectionId);
    BOOL StartConnectToSession(uint32_t nSessionId, const CExoString & sPlayerName, int32_t nPlayerLanguage, const CExoString & sPassword, uint32_t nTimeOut, uint32_t nConnectionType, const CExoString & sCDKey, const CExoString & sLegacyCDKey, const CExoString & expectCryptoPublicKeyBase64 = "");
    BOOL RequestExtendedServerInfo(uint32_t nSessionId, BOOL bGetInfo = true, BOOL bGetPing = true);
    BOOL RequestServerDetails(uint32_t nConnectionId);
    BOOL StartPing(uint32_t nSessionId);
    BOOL EndPing(uint32_t nSessionId);
    int32_t GetNumberLocalAdapters(uint32_t nProtocol);
    CExoString GetLocalAdapterString(uint32_t nProtocol, uint32_t nAdapterNumber);
    void SetSessionInfoChanged(uint32_t nSessionId, BOOL bHasChanged);
    BOOL GetSessionInfoChanged(uint32_t nSessionSection);
    void ClearSessionInfoChanged(uint32_t nSessionSection);
    uint32_t GetSessionMaxPlayers();
    void SetSessionMaxPlayers(uint32_t nMaxPlayers);
    CExoString GetSessionName();
    void SetSessionName(CExoString sSessionName);
    uint32_t GetUDPRecievePort();
    uint32_t GetPortBySessionId(uint32_t nSessionId);
    CNetLayerSessionInfo * GetSessionInfo(uint32_t nSession);
    BOOL EndConnectToSession();
    uint32_t GetConnectionError();
    BOOL GetClientConnected();
    uint32_t GetLocalPrivileges(uint32_t nConnectType);
    BOOL DisconnectFromSession();
    BOOL DropConnectionToServer();
    BOOL IsConnectedToLocalhost();
    BOOL MessageArrived(uint32_t nProtocol, uint32_t nSocketId, uint32_t nErrorCode, BOOL bRemoveFromQueue = true);
    void ProcessReceivedFrames(BOOL bProcessReceivedMessage = true);
    BOOL SendMessageToPlayer(uint32_t nPlayerId, uint8_t * pData, uint32_t nSize, uint32_t nFlags);
    BOOL SendMessageToAddress(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL UpdateStatusLoop(uint32_t nApplicationType);
    BOOL GetPlayerAddressData(uint32_t nConnectionId, uint32_t * nProtocol, uint8_t * * pNetAddress1, uint8_t * * pNetAddress2, uint32_t * nPort);
    void StoreMessage(uint8_t * pData, uint32_t nMsgLength);
    BOOL GetGameMasterPermision();
    BOOL TranslateAddressFromString(char * szAddress, uint32_t * nProtocol, uint8_t * pNetAddress1, uint8_t * pNetAddress2, uint32_t * nWPort);
    class CExoNet * GetExoNet();
    CExoString GetServerNetworkAddress();
    void SetCurrentMasterServerInternetAddress(uint32_t nAddress, uint32_t nPort);
    uint32_t GetSendUDPSocket();
    void ShutDownClientInterfaceWithReason(uint32_t nReason, const CExoString & sReason = "");
    void SetMstServerPassword(CExoString szTemp);
    void SetExpansionPackReqd(uint16_t nExpansionPack);
    uint16_t GetExpansionPackReqd();
    BOOL PlayerIdToConnectionId(uint32_t nPlayerId, uint32_t * nConnectionId);
    BOOL GetAnyWindowBehind();
    BOOL OpenStandardConnection(int32_t nConnectionToUse, CExoString sHostName, int32_t nPort);
    int32_t GetMessageFromStandardConnection(int32_t * nConnectionFrom, char * * pMessage, int32_t * nSize);
    BOOL SendMessageToStandardConnection(int32_t nConnectionTo, char * pmessage, int32_t nSize);
    BOOL CloseStandardConnection(int32_t nConnectonToClose);
    BOOL GetIPBySessionId(uint32_t nSessionId, CExoString * sIPAddress);
    void SetConnectionsDisallowed(BOOL bDisallowLoginWhileMasterServerIsDown);
    BOOL GetConnectionsMustBeValidated();
    void SetConnectionsMustBeValidated(BOOL bValidateLoginWhileMasterServerIsNotResponding);
    BOOL GetEnumerateSpecificOverRelay();
    void SetEnumerateSpecificOverRelay(BOOL state, const char relayToken);
    CExoString GetRouterPortMapDescription();
    void SetNWSyncData(const NWSyncAdvertisement & datra);
    const NWSyncAdvertisement & GetNWSyncData();


#ifdef NWN_CLASS_EXTENSION_CNetLayer
    NWN_CLASS_EXTENSION_CNetLayer
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNetLayer)
#endif

