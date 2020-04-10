#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLinkedList.hpp"
#include "CExoString.hpp"
#include "CNetLayerPlayerInfo.hpp"
#include "CNetLayerWindow.hpp"
#include "IntendedConnectionData.hpp"
#include "KXPacket.hpp"
#include "NWSyncAdvertisement.hpp"
#include "RelayModeChange.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNetLayerInternal)
#endif

struct CBaseExoApp;
struct CExoNet;
struct CExoNetExtendableBuffer;
struct CNetLayerSessionInfo;


typedef int BOOL;


struct CNetLayerInternal
{
    IntendedConnectionData m_pConnectData;
    CExoString m_sConnectExpectCryptoPublicKeyBase64;
    CBaseExoApp * m_pcExoApp;
    CExoNet * m_pcExoNet;
    BOOL m_bInitialized;
    CNetLayerWindow m_aWindows[0xff];
    CNetLayerPlayerInfo m_pcPlayerInfo[0xff];
    CExoNetExtendableBuffer * m_pebFrameStorage;
    uint8_t m_pCompressBuffer[131072];
    uint8_t m_pUncompressBuffer[131072];
    uint32_t m_nCRC32[256];
    uint8_t m_pPacketizeBuffer[CEXONET_MAX_MESSAGE_LENGTH];
    BOOL m_bServerMode;
    CExoString m_sSessionName;
    CExoString m_sPlayerPassword;
    CExoString m_sGameMasterPassword;
    CExoString m_sServerAdminPassword;
    uint32_t m_nSessionMaxPlayers;
    NWSyncAdvertisement m_nwsyncData;
    BOOL m_bEnumerateSessions;
    BOOL m_bEnumerateSpecific;
    BOOL m_bEnumerateSpecificOverRelay;
    char m_pEnumerateSpecificOverRelayToken[RELAY_TOKEN_SIZE];
    BOOL m_bEnumerateLocal;
    uint32_t m_nLastEnumerateSessions;
    uint32_t m_nLastEnumerateSessionsList;
    uint32_t m_nLastPurgeConnections;
    BOOL m_bEnumerateSessionsPerFrame;
    CNetLayerSessionInfo * m_pcSessionInfo;
    uint32_t m_nMaxSessionCnt[5];
    uint32_t m_nSessionInfoSize;
    uint32_t m_nSessionInfoSectionSize[5];
    BOOL m_bSessionInfoChanged[5];
    BOOL m_bConnected;
    BOOL m_bConnectToSession;
    CExoString m_sConnectPassword;
    uint32_t m_nConnectType;
    BOOL m_bConnectReplyReceived;
    BOOL m_bConnectReplyValue;
    uint32_t m_nConnectReplyErrorCode;
    uint32_t m_nConnectConnectionId;
    uint32_t m_nConnectTimeout;
    uint32_t m_nServerWindow;
    uint32_t m_nClientPermittedPlayer;
    uint32_t m_nClientPermittedGameMaster;
    uint32_t m_nClientPermittedServerAdmin;
    CExoLinkedList<CExoString> m_lBadPasswordAttempts;
    uint32_t m_nDisconnectStrref;
    CExoString m_sDisconnectReason;
    uint32_t m_nFavListSize;
    CExoString * m_asFavList;
    uint32_t m_nFavListEnumerated;
    uint32_t m_nFavListFramesToNextEnumeration;
    uint32_t m_nHistListSize;
    CExoString * m_asHistList;
    uint32_t m_nHistListEnumerated;
    uint32_t m_nHistListFramesToNextEnumeration;
    uint32_t m_nBuddyListSize;
    CExoString * m_asBuddyList;
    uint32_t m_nBuddyListEnumerated;
    uint32_t m_nBuddyListFramesToNextEnumeration;
    uint32_t m_nInternetListSize;
    CExoString * m_asInternetList;
    uint32_t m_nInternetListEnumerated;
    uint32_t m_nInternetListFramesToNextEnumeration;
    uint32_t m_nMaxSlidingWindow;
    CExoString m_sMstServerPassword;
    uint16_t m_nExpansionPackReqd;
    uint32_t m_nSinglePlayerSlidingWindow;
    int32_t m_nLanguage;
    BOOL m_bAnyWindowHasQueuedMessages;
    BOOL m_bDisallowLoginWhileMasterServerIsNotResponding;
    BOOL m_bValidateLoginWhileMasterServerIsNotResponding;

    CNetLayerInternal();
    ~CNetLayerInternal();
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
    BOOL SetGameMasterPassword(CExoString sGameMasterPassword);
    CExoString GetServerAdminPassword();
    BOOL SetServerAdminPassword(CExoString sServerAdminPassword);
    BOOL EndServerMode();
    BOOL GetServerConnected();
    CExoString GetPlayerAddress(uint32_t nPlayerId, BOOL bIncludePort = false);
    BOOL GetPlayerAddressRelayed(uint32_t nPlayerId);
    BOOL DisconnectPlayer(uint32_t nPlayerId, uint32_t nStrRef = 5838, BOOL bSendBNDP = true, BOOL bCDAuthFail = true, const CExoString & reason = "");
    void StartAddressTranslation(const CExoString & sInternetAddress);
    BOOL GetAddressTranslationResult(const CExoString & sInternetAddress, CExoArrayList<uint32_t> & nIPv4);
    void EndAddressTranslation(const CExoString & sInternetAddress);
    BOOL StartEnumerateSessionsSection(uint32_t nEnumerateSection, uint32_t nSize, CExoString * sServerListToEnumerate);
    BOOL EndEnumerateSessionsSection(uint32_t nEnumerateSection);
    BOOL EnumerateSessionsLoop();
    uint32_t GetSessionSectionStart(uint32_t nSessionIndex);
    uint32_t GetSessionSection(uint32_t nSessionId);
    void ResetEnumerateSessionsList(uint8_t nEnumerateType);
    BOOL SendBNESDirectMessageToAddress(CExoString sAddress, uint8_t nEnumerateType);
    uint32_t EnumerateSessionsList(uint8_t nEnumerateType);
    BOOL EndEnumerateSessions();
    void CleanUpEnumerateSpecific();
    BOOL StartConnectToSession(uint32_t nSessionId, const CExoString & sPlayerName, int32_t nPlayerLanguage, const CExoString & sPassword, uint32_t nTimeout, uint32_t nConnectionType, const CExoString & sCDKey, const CExoString & sLegacyCDKey, const CExoString & expectCryptoPublicKeyBase64);
    BOOL RequestExtendedServerInfo(uint32_t nSessionId, BOOL bGetInfo = true, BOOL bGetPing = true);
    BOOL StartPing(uint32_t nSessionId);
    BOOL EndPing(uint32_t nSessionId);
    CNetLayerSessionInfo * GetSessionInfo(uint32_t nSession);
    BOOL EndConnectToSession();
    uint32_t GetConnectionError();
    uint32_t GetLocalPrivileges(uint32_t nConnectType);
    BOOL DisconnectFromSession();
    BOOL DropConnectionToServer();
    BOOL IsConnectedToLocalhost();
    void SetPlayerConnected(uint32_t nPlayerId);
    BOOL GetIPBySessionId(uint32_t nSessionId, CExoString * sIPAddress);
    BOOL MessageArrived(uint32_t nProtocol, uint32_t nSocketId, uint32_t nErrorCode, BOOL bRemoveFromQueue = true);
    BOOL SendMessageToPlayer(uint32_t nPlayerId, uint8_t * pData, uint32_t nSize, uint32_t nFlags);
    void ProcessReceivedFrames(BOOL bProcessReceivedMessages = true);
    BOOL UpdateStatusLoop(uint32_t nApplicationType);
    int32_t GetNumberLocalAdapters(uint32_t nProtocol);
    CExoString GetLocalAdapterString(uint32_t nProtocol, uint32_t nAdapterNumber);
    BOOL UncompressMessage(uint32_t nPlayerId, uint8_t * pData, uint32_t nSize);
    BOOL NonWindowMessages(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    void SendBNDMMessage(uint32_t nConnectionId = CExoNet : : CONNECTIONID_INVALIDID);
    void SendBNDPMessage(uint32_t nPlayerId, uint32_t nStrRef = 5838, const CExoString & reason = "");
    BOOL SendBNKAnyMessage(uint32_t nConnectionId, KXPacket nPacket, const uint8_t * pPacket);
    BOOL HandleBNK1Message(uint32_t nConnectionId, uint8_t * pData, size_t nSize);
    BOOL HandleBNK2Message(uint32_t nConnectionId, uint8_t * pData, size_t nSize);
    BOOL HandleBNK3Message(uint32_t nConnectionId, uint8_t * pData, size_t nSize);
    BOOL HandleBNK4Message(uint32_t nConnectionId, uint8_t * pData, size_t nSize);
    BOOL HandleBNK0Message(uint32_t nConnectionId, uint8_t * pData, size_t nSize);
    BOOL SendBNCSMessage(uint32_t nConnectionId, uint8_t nConnectionType, int32_t nPlayerLanguage, const CExoString & sPlayerName, const CExoString & sCDKey, const CExoString & sLegacyCDKey);
    BOOL HandleBNCSMessage(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL SendBNCRMessage(uint32_t nConnectionId, uint8_t nRejection, uint32_t nPlayerWindow = 0);
    BOOL HandleBNCRMessage(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL SendBNVSMessage(const CExoArrayList<CExoString> * lstCDKeyResponse, const CExoString & sMSTPasswordResponse, const CExoString & sGamePasswordResponse = "");
    BOOL HandleBNVSMessage(uint32_t nConnectionId, uint8_t * pMessage, uint32_t nSize);
    BOOL SendBNVRMessage(uint32_t nConnectionId, uint8_t nRejection);
    BOOL HandleBNVRMessage(uint32_t nConnectionId, uint8_t * pMessage, uint32_t nSize);
    BOOL HandleBNESMessage(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL HandleBNERMessage(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL HandleBNXIMessage(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL HandleBNXRMessage(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL SendBNLMMessage(uint32_t nSessionId, uint32_t nMessageNo);
    BOOL HandleBNLMMessage(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL HandleBNLRMessage(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL SendBNDSMessage(uint32_t nConnectionId);
    BOOL HandleBNDSMessage(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL HandleBNDRMessage(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL HandleBNDMMessage(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL HandleBNDPMessage(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL ConnectionIdToSlidingWindow(uint32_t nConnectionId, uint32_t * nSlidingWindow);
    BOOL PlayerIdToSlidingWindow(uint32_t nPlayerId, uint32_t * nSlidingWindow);
    BOOL PlayerIdToConnectionId(uint32_t nPlayerId, uint32_t * nConnectionId);
    BOOL SetSlidingWindow(uint32_t nConnectionId, uint32_t * nSlidingWindow);
    BOOL SendMessageToAddress(uint32_t nConnectionId, uint8_t * pData, uint32_t nSize);
    BOOL BroadcastMessageToAddress(uint32_t nProtocol, uint32_t nPort, uint8_t * pData, uint32_t nSize);
    BOOL PurgeConnections();
    CExoString GetServerNetworkAddress();
    uint32_t GetServerPlayerCount();
    BOOL FindPlayerName(CExoString sPlayerName, uint32_t nConnectionId);
    BOOL IsPlayerIpSameAsConnection(uint32_t nPlayerId, uint32_t nNewConnectionId);
    BOOL GetWindowSendIdByReceiveId(uint32_t nReceiveConnectionId, uint32_t * nSendConnectionId);
    void SetCurrentMasterServerInternetAddress(uint32_t nAddress, uint32_t nPort);
    uint32_t GetSendUDPSocket();
    void ShutDownClientInterfaceWithReason(uint32_t nReason, const CExoString & sReason = "");
    void CRCBuildTable();
    uint32_t CRCBlock(uint8_t * pData, uint32_t nSize);
    void CRCEncodeFrame(uint8_t * pData, uint32_t nSize);
    BOOL CRCVerifyFrame(uint8_t * pData, uint32_t nSize);
    BOOL PlacePacketInSendQueues(uint32_t nSlidingWindow, BOOL bHighPriority, uint8_t * pData, uint32_t nSize, BOOL bWindowHoldBuffer);
    uint32_t ConnectToSessionLoop();
    BOOL PacketizeSendMessageToPlayer(uint32_t nPlayerId, uint8_t * pData, uint32_t nSize, uint32_t nFlags);
    BOOL PacketizeSmallMessageToPlayer(uint32_t nPlayerId, uint8_t * pData, uint32_t nSize, uint32_t nFlags);
    void SetUpPlayBackConnection();
    void SetSessionInfoChanged(uint32_t nSessionId, BOOL bHasChanged);
    void ClearSessionInfoChanged(uint32_t nSessionSection);
    uint32_t GetSessionMaxPlayers();
    void SetSessionMaxPlayers(uint32_t nMaxPlayers);
    CExoString GetSessionName();
    void SetSessionName(CExoString sSessionName);
    uint32_t GetUDPRecievePort();
    uint32_t GetPortBySessionId(uint32_t nSessionId);
    BOOL GetPlayerAddressData(uint32_t nConnectionId, uint32_t * nProtocol, uint8_t * * pNetAddress1, uint8_t * * pNetAddress2, uint32_t * nPort);
    uint32_t SetNetworkAddressData(uint32_t nProtocol, uint8_t * pNetAddress1, uint8_t * pNetAddress2, uint32_t nPort, RelayModeChange relayMode = RelayModeNoChange, const char relayToken);
    BOOL SendDirectMessage(uint32_t nConnectionId, uint8_t * pData, uint32_t nMsgLength, uint32_t nProtocol, uint32_t nPort);
    void StoreMessage(uint8_t * pData, uint32_t nMsgLength);
    BOOL OpenStandardConnection(int32_t nConnectionToUse, CExoString sHostName, int32_t nPort);
    int32_t GetMessageFromStandardConnection(int32_t * nConnectionFrom, char * * pMessage, int32_t * nSize);
    BOOL SendMessageToStandardConnection(int32_t nConnectionTo, char * pmessage, int32_t nSize);
    BOOL CloseStandardConnection(int32_t nConnectonToClose);
    BOOL ValidatePlayerAgainstLastSuccessfulLogin(CExoString sPlayerName, CExoString sPublicCDKey);
    CExoString GetRouterPortMapDescription();
    void CheckMasterServerTimeouts();
    void SetSteamLobbyMetaData(int32_t nConnectionId);
    uint32_t GetSessionSectionSize(uint32_t sectionType);


#ifdef NWN_CLASS_EXTENSION_CNetLayerInternal
    NWN_CLASS_EXTENSION_CNetLayerInternal
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNetLayerInternal)
#endif

