#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CBaseExoApp)
#endif



typedef int BOOL;


struct CBaseExoApp
{

    virtual BOOL AdmitNetworkAddress(uint32_t nProtocol, CExoString sAddress);
    virtual BOOL AdmitPlayerName(CExoString sPlayerName);
    virtual BOOL SetNetworkAddressBan(uint32_t nProtocol, CExoString sAddress, BOOL bBanPlayer);
    virtual void PlayerListChange(uint32_t nPlayerId, BOOL bEnter, BOOL bPrimaryPlayer = false);
    virtual BOOL HandleMessage(uint32_t nPlayerId, uint8_t * pData, uint32_t dwSize, BOOL bRawMessage);
    virtual float GetFPS();
    virtual BOOL ContinueMessageProcessing();
    virtual class CNetLayer * GetNetLayer();
    virtual void ShutDownToMainMenu();
    virtual BOOL GetMultiplayerEnabled();
    virtual class CExtendedServerInfo * GetExtendedServerInfo();
    virtual void HandleGameSpyToServerMessage(int32_t nKeyId, void * pOutBuf, int nIndex = - 1);
    virtual class CConnectionLib * GetConnectionLib();
    virtual class CServerInfo * GetServerInfo();
    virtual void GetExtendedServerInfo(class CExtendedServerInfo * pInfo);
    virtual CExoLocString GetModuleDescription();
    virtual uint32_t GetApplicationId();
    virtual void SetApplicationIdsMatch(BOOL b);
    virtual BOOL GetIsIPOnBannedList(CExoString sIP);
    virtual BOOL GetIsPlayerNameOnBannedList(CExoString sPlayerName);
    virtual BOOL GetIsCDKeyOnBannedList(CExoString sKey);
    virtual void HandleOldServerVaultMigration(CExoString sClientCDKey, CExoString sClientLegacyCDKey, CExoString sPlayerName);
    virtual BOOL IsPlayerNameSticky();
    virtual BOOL CheckStickyPlayerNameReserved(CExoString sClientCDKey, CExoString sClientLegacyCDKey, CExoString sPlayerName, int32_t nConnectionType);
    virtual void PushMessageOverWall(uint8_t * pData, uint32_t nMsgLength);
    virtual BOOL GetIsMultiPlayer();
    virtual CExoString GetCDKey();
    virtual void SetWeGotDisconnected();


#ifdef NWN_CLASS_EXTENSION_CBaseExoApp
    NWN_CLASS_EXTENSION_CBaseExoApp
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CBaseExoApp)
#endif

