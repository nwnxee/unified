#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoString.hpp"
#include "CNetLayerPlayerCDKeyInfo.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNetLayerPlayerInfo)
#endif



typedef int BOOL;


struct CNetLayerPlayerInfo
{
    BOOL m_bPlayerInUse;
    CExoString m_sPlayerName;
    int32_t m_nPlayerLanguage;
    uint32_t m_nSlidingWindowId;
    BOOL m_bPlayerPrivileges;
    BOOL m_bGameMasterPrivileges;
    BOOL m_bGameMasterIsPlayerLogin;
    BOOL m_bServerAdminPrivileges;
    CExoString m_szMstServerChallenge;
    uint64_t m_nMstServerTimeout;
    uint64_t m_nMstServerTimeStamp;
    CExoString m_sGamePasswordChallenge;
    CExoString m_sCDKeyChallenge;
    CExoString m_sMstPasswordChallenge;
    uint8_t m_nConnectionType;
    BOOL m_bIsPrimaryPlayer;
    CNetLayerPlayerCDKeyInfo m_cCDKey;
    CExoString m_sMstPasswordResponse;
    BOOL m_bCDKeyAuthorized;
    BOOL m_bMstPasswordAuthorized;
    CExoString m_sPSID;
    uint8_t m_nPlatformId;
    int32_t m_nBuildVersion;
    int32_t m_nPatchRevision;
    int32_t m_nPatchPostfix;
    CExoString m_sCommitHash;

    CNetLayerPlayerInfo();
    void Initialize();
    void StartMstTimer(uint64_t nTime);
    BOOL UpdateMstTimer(uint64_t nTime);
    void SetCDKey(const CExoString & sPublic, const CExoString & sResponse);
    bool SatisfiesBuild(int32_t nBuild, int32_t nRevision, int32_t nPostfix) const;


#ifdef NWN_CLASS_EXTENSION_CNetLayerPlayerInfo
    NWN_CLASS_EXTENSION_CNetLayerPlayerInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNetLayerPlayerInfo)
#endif

