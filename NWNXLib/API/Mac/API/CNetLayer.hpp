#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CBaseExoApp;
struct CNetLayerInternal;
struct CNetLayerPlayerInfo;
struct CNetLayerSessionInfo;

struct CNetLayer
{
    CNetLayerInternal* m_pcNetLayerInternal;

    // The below are auto generated stubs.
    CNetLayer(const CNetLayer&) = default;
    CNetLayer& operator=(const CNetLayer&) = default;

    CNetLayer();
    ~CNetLayer();
    void CleanUpEnumerateSpecific();
    void ClearSessionInfoChanged(uint32_t);
    int32_t CloseStandardConnection(int32_t);
    int32_t DisconnectFromSession();
    int32_t DisconnectPlayer(uint32_t, uint32_t, int32_t);
    int32_t DropConnectionToServer();
    int32_t EndConnectToSession();
    int32_t EndEnumerateSessions();
    int32_t EndEnumerateSessionsSection(uint32_t);
    int32_t EndInternetAddressTranslation();
    int32_t EndPing(uint32_t);
    int32_t EndProtocol(uint32_t);
    int32_t EndServerMode();
    int32_t GetAnySessionsEnumerated();
    int32_t GetAnyWindowBehind();
    int32_t GetClientConnected();
    uint32_t GetConnectionError();
    int32_t GetConnectionsMustBeValidated();
    uint32_t GetDisconnectStrref();
    CBaseExoApp* GetExoApp();
    void GetExoNet();
    uint16_t GetExpansionPackReqd();
    CExoString GetGameMasterPassword();
    int32_t GetGameMasterPermision();
    uint32_t GetInternetAddressTranslationStatus(unsigned char*);
    int32_t GetIPBySessionId(uint32_t, CExoString*);
    CExoString GetLocalAdapterString(uint32_t, uint32_t);
    uint32_t GetLocalPrivileges(uint32_t);
    int32_t GetMessageFromStandardConnection(int32_t*, char**, int32_t*);
    int32_t GetNumberLocalAdapters(uint32_t);
    int32_t GetPasswordRequired();
    CExoString GetPlayerAddress(uint32_t);
    int32_t GetPlayerAddressData(uint32_t, uint32_t*, unsigned char**, unsigned char**, uint32_t*);
    CNetLayerPlayerInfo* GetPlayerInfo(uint32_t);
    CExoString GetPlayerPassword();
    uint32_t GetPortBySessionId(uint32_t);
    uint32_t GetSendUDPSocket();
    CExoString GetServerAdminPassword();
    int32_t GetServerConnected();
    CExoString GetServerNetworkAddress();
    CNetLayerSessionInfo* GetSessionInfo(uint32_t);
    int32_t GetSessionInfoChanged(uint32_t);
    uint32_t GetSessionMaxPlayers();
    CExoString GetSessionName();
    uint32_t GetUDPRecievePort();
    int32_t Initialize(CBaseExoApp*);
    int32_t IsConnectedToLocalhost();
    int32_t MessageArrived(uint32_t, uint32_t, uint32_t, int32_t);
    int32_t OpenStandardConnection(int32_t, CExoString, int32_t);
    int32_t PlayerIdToConnectionId(uint32_t, uint32_t*);
    void ProcessReceivedFrames(int32_t);
    int32_t RequestExtendedServerInfo(uint32_t, int32_t, int32_t);
    int32_t RequestServerDetails(uint32_t);
    int32_t SendMessageToAddress(uint32_t, unsigned char*, uint32_t);
    int32_t SendMessageToPlayer(uint32_t, unsigned char*, uint32_t, uint32_t);
    int32_t SendMessageToStandardConnection(int32_t, char*, int32_t);
    void SetConnectionsDisallowed(int32_t);
    void SetConnectionsMustBeValidated(int32_t);
    void SetDisconnectStrref(uint32_t);
    void SetExpansionPackReqd(uint16_t);
    int32_t SetGameMasterPassword(CExoString);
    void SetMasterServerInternetAddress(const unsigned char*, uint32_t);
    void SetMstServerPassword(CExoString);
    int32_t SetPlayerPassword(CExoString);
    int32_t SetServerAdminPassword(CExoString);
    void SetServerLanguage(int32_t);
    void SetSessionInfoChanged(uint32_t, int32_t);
    void SetSessionMaxPlayers(uint32_t);
    void SetSessionName(CExoString);
    void SetUpPlayBackConnection();
    int32_t ShutDown();
    void ShutDownClientInterfaceWithReason(uint32_t);
    int32_t StartConnectToSession(uint32_t, const CExoString&, int32_t, int32_t, const CExoString&, uint32_t, uint32_t, const CExoString&, const CExoString&);
    int32_t StartEnumerateSessions(uint32_t, int32_t, unsigned char*, uint16_t, int32_t, uint32_t);
    int32_t StartEnumerateSessionsSection(uint32_t, uint32_t, CExoString*);
    int32_t StartInternetAddressTranslation(CExoString, uint32_t, uint32_t);
    int32_t StartPing(uint32_t);
    int32_t StartProtocol(uint32_t, uint32_t, uint32_t, uint32_t);
    int32_t StartServerMode(CExoString, uint32_t);
    void StoreMessage(unsigned char*, uint32_t);
    int32_t TranslateAddressFromString(char*, uint32_t*, unsigned char*, unsigned char*, uint32_t*);
    int32_t UpdateStatusLoop(uint32_t);
};

void CNetLayer__CNetLayerCtor__0(CNetLayer* thisPtr);
void CNetLayer__CNetLayerDtor__0(CNetLayer* thisPtr);
void CNetLayer__CleanUpEnumerateSpecific(CNetLayer* thisPtr);
void CNetLayer__ClearSessionInfoChanged(CNetLayer* thisPtr, uint32_t);
int32_t CNetLayer__CloseStandardConnection(CNetLayer* thisPtr, int32_t);
int32_t CNetLayer__DisconnectFromSession(CNetLayer* thisPtr);
int32_t CNetLayer__DisconnectPlayer(CNetLayer* thisPtr, uint32_t, uint32_t, int32_t);
int32_t CNetLayer__DropConnectionToServer(CNetLayer* thisPtr);
int32_t CNetLayer__EndConnectToSession(CNetLayer* thisPtr);
int32_t CNetLayer__EndEnumerateSessions(CNetLayer* thisPtr);
int32_t CNetLayer__EndEnumerateSessionsSection(CNetLayer* thisPtr, uint32_t);
int32_t CNetLayer__EndInternetAddressTranslation(CNetLayer* thisPtr);
int32_t CNetLayer__EndPing(CNetLayer* thisPtr, uint32_t);
int32_t CNetLayer__EndProtocol(CNetLayer* thisPtr, uint32_t);
int32_t CNetLayer__EndServerMode(CNetLayer* thisPtr);
int32_t CNetLayer__GetAnySessionsEnumerated(CNetLayer* thisPtr);
int32_t CNetLayer__GetAnyWindowBehind(CNetLayer* thisPtr);
int32_t CNetLayer__GetClientConnected(CNetLayer* thisPtr);
uint32_t CNetLayer__GetConnectionError(CNetLayer* thisPtr);
int32_t CNetLayer__GetConnectionsMustBeValidated(CNetLayer* thisPtr);
uint32_t CNetLayer__GetDisconnectStrref(CNetLayer* thisPtr);
CBaseExoApp* CNetLayer__GetExoApp(CNetLayer* thisPtr);
void CNetLayer__GetExoNet(CNetLayer* thisPtr);
uint16_t CNetLayer__GetExpansionPackReqd(CNetLayer* thisPtr);
CExoString CNetLayer__GetGameMasterPassword(CNetLayer* thisPtr);
int32_t CNetLayer__GetGameMasterPermision(CNetLayer* thisPtr);
uint32_t CNetLayer__GetInternetAddressTranslationStatus(CNetLayer* thisPtr, unsigned char*);
int32_t CNetLayer__GetIPBySessionId(CNetLayer* thisPtr, uint32_t, CExoString*);
CExoString CNetLayer__GetLocalAdapterString(CNetLayer* thisPtr, uint32_t, uint32_t);
uint32_t CNetLayer__GetLocalPrivileges(CNetLayer* thisPtr, uint32_t);
int32_t CNetLayer__GetMessageFromStandardConnection(CNetLayer* thisPtr, int32_t*, char**, int32_t*);
int32_t CNetLayer__GetNumberLocalAdapters(CNetLayer* thisPtr, uint32_t);
int32_t CNetLayer__GetPasswordRequired(CNetLayer* thisPtr);
CExoString CNetLayer__GetPlayerAddress(CNetLayer* thisPtr, uint32_t);
int32_t CNetLayer__GetPlayerAddressData(CNetLayer* thisPtr, uint32_t, uint32_t*, unsigned char**, unsigned char**, uint32_t*);
CNetLayerPlayerInfo* CNetLayer__GetPlayerInfo(CNetLayer* thisPtr, uint32_t);
CExoString CNetLayer__GetPlayerPassword(CNetLayer* thisPtr);
uint32_t CNetLayer__GetPortBySessionId(CNetLayer* thisPtr, uint32_t);
uint32_t CNetLayer__GetSendUDPSocket(CNetLayer* thisPtr);
CExoString CNetLayer__GetServerAdminPassword(CNetLayer* thisPtr);
int32_t CNetLayer__GetServerConnected(CNetLayer* thisPtr);
CExoString CNetLayer__GetServerNetworkAddress(CNetLayer* thisPtr);
CNetLayerSessionInfo* CNetLayer__GetSessionInfo(CNetLayer* thisPtr, uint32_t);
int32_t CNetLayer__GetSessionInfoChanged(CNetLayer* thisPtr, uint32_t);
uint32_t CNetLayer__GetSessionMaxPlayers(CNetLayer* thisPtr);
CExoString CNetLayer__GetSessionName(CNetLayer* thisPtr);
uint32_t CNetLayer__GetUDPRecievePort(CNetLayer* thisPtr);
int32_t CNetLayer__Initialize(CNetLayer* thisPtr, CBaseExoApp*);
int32_t CNetLayer__IsConnectedToLocalhost(CNetLayer* thisPtr);
int32_t CNetLayer__MessageArrived(CNetLayer* thisPtr, uint32_t, uint32_t, uint32_t, int32_t);
int32_t CNetLayer__OpenStandardConnection(CNetLayer* thisPtr, int32_t, CExoString, int32_t);
int32_t CNetLayer__PlayerIdToConnectionId(CNetLayer* thisPtr, uint32_t, uint32_t*);
void CNetLayer__ProcessReceivedFrames(CNetLayer* thisPtr, int32_t);
int32_t CNetLayer__RequestExtendedServerInfo(CNetLayer* thisPtr, uint32_t, int32_t, int32_t);
int32_t CNetLayer__RequestServerDetails(CNetLayer* thisPtr, uint32_t);
int32_t CNetLayer__SendMessageToAddress(CNetLayer* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayer__SendMessageToPlayer(CNetLayer* thisPtr, uint32_t, unsigned char*, uint32_t, uint32_t);
int32_t CNetLayer__SendMessageToStandardConnection(CNetLayer* thisPtr, int32_t, char*, int32_t);
void CNetLayer__SetConnectionsDisallowed(CNetLayer* thisPtr, int32_t);
void CNetLayer__SetConnectionsMustBeValidated(CNetLayer* thisPtr, int32_t);
void CNetLayer__SetDisconnectStrref(CNetLayer* thisPtr, uint32_t);
void CNetLayer__SetExpansionPackReqd(CNetLayer* thisPtr, uint16_t);
int32_t CNetLayer__SetGameMasterPassword(CNetLayer* thisPtr, CExoString);
void CNetLayer__SetMasterServerInternetAddress(CNetLayer* thisPtr, const unsigned char*, uint32_t);
void CNetLayer__SetMstServerPassword(CNetLayer* thisPtr, CExoString);
int32_t CNetLayer__SetPlayerPassword(CNetLayer* thisPtr, CExoString);
int32_t CNetLayer__SetServerAdminPassword(CNetLayer* thisPtr, CExoString);
void CNetLayer__SetServerLanguage(CNetLayer* thisPtr, int32_t);
void CNetLayer__SetSessionInfoChanged(CNetLayer* thisPtr, uint32_t, int32_t);
void CNetLayer__SetSessionMaxPlayers(CNetLayer* thisPtr, uint32_t);
void CNetLayer__SetSessionName(CNetLayer* thisPtr, CExoString);
void CNetLayer__SetUpPlayBackConnection(CNetLayer* thisPtr);
int32_t CNetLayer__ShutDown(CNetLayer* thisPtr);
void CNetLayer__ShutDownClientInterfaceWithReason(CNetLayer* thisPtr, uint32_t);
int32_t CNetLayer__StartConnectToSession(CNetLayer* thisPtr, uint32_t, const CExoString&, int32_t, int32_t, const CExoString&, uint32_t, uint32_t, const CExoString&, const CExoString&);
int32_t CNetLayer__StartEnumerateSessions(CNetLayer* thisPtr, uint32_t, int32_t, unsigned char*, uint16_t, int32_t, uint32_t);
int32_t CNetLayer__StartEnumerateSessionsSection(CNetLayer* thisPtr, uint32_t, uint32_t, CExoString*);
int32_t CNetLayer__StartInternetAddressTranslation(CNetLayer* thisPtr, CExoString, uint32_t, uint32_t);
int32_t CNetLayer__StartPing(CNetLayer* thisPtr, uint32_t);
int32_t CNetLayer__StartProtocol(CNetLayer* thisPtr, uint32_t, uint32_t, uint32_t, uint32_t);
int32_t CNetLayer__StartServerMode(CNetLayer* thisPtr, CExoString, uint32_t);
void CNetLayer__StoreMessage(CNetLayer* thisPtr, unsigned char*, uint32_t);
int32_t CNetLayer__TranslateAddressFromString(CNetLayer* thisPtr, char*, uint32_t*, unsigned char*, unsigned char*, uint32_t*);
int32_t CNetLayer__UpdateStatusLoop(CNetLayer* thisPtr, uint32_t);

}

}
