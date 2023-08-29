#pragma once
#include "nwn_api.hpp"

#include "CExoLocString.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CAppManager)
#endif

class CClientExoApp;
class CNWReentrantServerStats;
class CNWTileSetManager;
class CObjectTableManager;
class CServerExoApp;


typedef int BOOL;


class CAppManager
{
public:
    CClientExoApp * m_pClientExoApp;
    CServerExoApp * m_pServerExoApp;
    CNWTileSetManager * m_pNWTileSetManager;
    CObjectTableManager * m_pClientObjectTableManager;
    CObjectTableManager * m_pServerObjectTableManager;
    CNWReentrantServerStats * m_pReentrantServerStats;
    BOOL m_bDungeonMasterEXERunning;
    uint32_t m_nApplicationId;
    BOOL m_bMultiplayerEnabled;
    BOOL m_bWasPaused;
    BOOL m_bDigitalDistributionModule;
    uint8_t * m_pDDCipher;
    uint32_t m_nDDOffset;
    uint32_t m_nPlayerTimeout;
    BOOL m_bLogModelErrors;

    CAppManager();
    ~CAppManager();
    CObjectTableManager * GetObjectTableManager(uint32_t dwClientServer);
    void DoSaveGameScreenShot(CExoString & sFile);
    void ShowServerMem();
    NWNX_IMPORT void CreateServer(void );
    NWNX_IMPORT void DestroyServer();
    void SetDungeonMasterEXERunning(BOOL bDM);
    BOOL GetDungeonMasterEXERunning();
    void DisplayScriptDebuggerPopup();
    void DestroyScriptDebuggerPopup();
    BOOL SetDDCipherForModule(CExoString moduleName);
    uint8_t ReadProgressFromINI(uint8_t m_nCampaign);
    // CExoLocString GetHostedModuleDescription();
    // CExoString GetHostedPublicInternetAddressAndPort();
    void ConnectToServer(CExoString sAddress, BOOL bPasswordRequired);
    class CWorldTimer * GetWorldTimer();
    CExoString GetCryptoKxPublicKeyBase64();
    CExoString GetPublicCdKey();
    uint8_t GetPlatformId();
    uint8_t GetLanguageId();


#ifdef NWN_CLASS_EXTENSION_CAppManager
    NWN_CLASS_EXTENSION_CAppManager
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CAppManager)
#endif

