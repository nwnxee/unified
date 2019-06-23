#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoApp)
#endif

struct CExoAppInternal;


typedef int BOOL;


struct CExoApp
{
    CExoAppInternal * m_pcExoAppInternal;

    CExoApp();
    ~CExoApp();
    BOOL AdmitNetworkAddress(uint32_t nProtocol, CExoString sAddress);
    BOOL SetNetworkAddressBan(uint32_t nProtocol, CExoString sAddress, BOOL bBanPlayer);
    BOOL AdmitPlayerName(CExoString sPlayerName);
    void PlayerListChange(uint32_t nPlayerId, BOOL bEnter, BOOL bPrimaryPlayer = false);
    BOOL GetIniFileName(CExoString & sName);
    BOOL HandleMessage(uint32_t nPlayerId, uint8_t * pData, uint32_t dwSize, BOOL bRawMessage);
    BOOL Initialize();
    void LoadAliases();
    BOOL MainLoop();
    void OnCDChange();
    void OnExit();
    void OnGainFocus();
    void OnLostFocus();
    void OnVideoChange();
    void StartServices();
    void StopServices();
    void Uninitialize();


#ifdef NWN_CLASS_EXTENSION_CExoApp
    NWN_CLASS_EXTENSION_CExoApp
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoApp)
#endif

