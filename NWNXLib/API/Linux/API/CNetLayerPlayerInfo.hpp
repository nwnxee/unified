#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CNetLayerPlayerInfo
{
    int32_t m_bPlayerInUse;
    CExoString m_sPlayerName;
    int32_t m_nPlayerLanguage;
    uint32_t m_nSlidingWindowId;
    int32_t m_bPlayerPrivileges;
    int32_t m_bGameMasterPrivileges;
    int32_t m_bServerAdminPrivileges;
    CExoString m_szMstServerChallenge;
    uint64_t m_nMstServerTimeout;
    uint64_t m_nMstServerTimeStamp;
    CExoString m_sGamePasswordChallenge;
    CExoString m_sCDKeyChallenge;
    CExoString m_sMstPasswordChallenge;
    uint8_t m_nConnectionType;
    int32_t m_bIsPrimaryPlayer;
    CExoArrayListTemplatedCNetLayerPlayerCDKeyInfo m_lstKeys;
    CExoString m_sMstPasswordResponse;
    int32_t m_bCDKeyAuthorized;
    int32_t m_bMstPasswordAuthorized;
    uint16_t m_nExpansionPacks;

    // The below are auto generated stubs.
    CNetLayerPlayerInfo(const CNetLayerPlayerInfo&) = default;
    CNetLayerPlayerInfo& operator=(const CNetLayerPlayerInfo&) = default;

    CNetLayerPlayerInfo();
    ~CNetLayerPlayerInfo();
    void AddCDKey(const CExoString&, const CExoString&);
    int32_t AllKeysAuthed(uint32_t&);
    CExoString GetPublicCDKey(int32_t);
    void Initialize();
    void SetCDKey(int32_t, const CExoString&, const CExoString&);
    void StartMstTimer(uint64_t);
    int32_t UpdateMstTimer(uint64_t);
};

void CNetLayerPlayerInfo__CNetLayerPlayerInfoCtor(CNetLayerPlayerInfo* thisPtr);
void CNetLayerPlayerInfo__CNetLayerPlayerInfoDtor(CNetLayerPlayerInfo* thisPtr);
void CNetLayerPlayerInfo__AddCDKey(CNetLayerPlayerInfo* thisPtr, const CExoString&, const CExoString&);
int32_t CNetLayerPlayerInfo__AllKeysAuthed(CNetLayerPlayerInfo* thisPtr, uint32_t&);
CExoString CNetLayerPlayerInfo__GetPublicCDKey(CNetLayerPlayerInfo* thisPtr, int32_t);
void CNetLayerPlayerInfo__Initialize(CNetLayerPlayerInfo* thisPtr);
void CNetLayerPlayerInfo__SetCDKey(CNetLayerPlayerInfo* thisPtr, int32_t, const CExoString&, const CExoString&);
void CNetLayerPlayerInfo__StartMstTimer(CNetLayerPlayerInfo* thisPtr, uint64_t);
int32_t CNetLayerPlayerInfo__UpdateMstTimer(CNetLayerPlayerInfo* thisPtr, uint64_t);

}

}
