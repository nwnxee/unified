#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGameEffect)
#endif

struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CGameEffect
{
    uint64_t m_nID;
    uint16_t m_nType;
    uint16_t m_nSubType;
    float m_fDuration;
    uint32_t m_nExpiryCalendarDay;
    uint32_t m_nExpiryTimeOfDay;
    OBJECT_ID m_oidCreator;
    uint32_t m_nSpellId;
    BOOL m_bExpose;
    BOOL m_bShowIcon;
    int32_t m_nCasterLevel;
    CGameEffect * m_pLinkLeft;
    CGameEffect * m_pLinkRight;
    int32_t m_nNumIntegers;
    int32_t * m_nParamInteger;
    float m_nParamFloat[4];
    CExoString m_sParamString[6];
    OBJECT_ID m_oidParamObjectID[4];
    Vector m_vParamVector[2];
    BOOL m_bSkipOnLoad;
    uint64_t m_nItemPropertySourceId;
    CExoString m_sCustomTag;

    CGameEffect(BOOL bCreateNewID = true);
    CGameEffect(CGameEffect * pParent, BOOL bCopyIconVisibility = false);
    ~CGameEffect();
    CGameEffect & operator=(const CGameEffect & effect);
    int32_t GetScriptEffectType();
    void SetCreator(OBJECT_ID oidCreator);
    int32_t GetInteger(int32_t nStorageLocation);
    void SetInteger(int32_t nStorageLocation, int32_t nValue);
    void SetNumIntegers(int32_t nNumIntegers);
    void SetNumIntegersInitializeToNegativeOne(int32_t nNumIntegers);
    float GetFloat(int32_t nStorageLocation);
    void SetFloat(int32_t nStorageLocation, float fValue);
    OBJECT_ID GetObjectID(int32_t nStorageLocation);
    void SetObjectID(int32_t nStorageLocation, OBJECT_ID oidValue);
    CExoString GetString(int32_t nStorageLocation);
    void SetString(int32_t nStorageLocation, CExoString sString);
    Vector GetVector(int32_t nStorageLocation);
    void SetVector(int32_t nStorageLocation, Vector vVector);
    BOOL operator==(const CGameEffect & effect) const;
    BOOL operator!=(const CGameEffect & effect) const;
    void CopyEffect(CGameEffect * pEffect, BOOL bIgnoreArrayLists = false);
    void SetExpiryTime(uint32_t nCalendarDayExpiry, uint32_t nTimeOfDayExpiry);
    void GetExpiryTime(uint32_t * nCurrentCalendarDay, uint32_t * nCurrentTimeOfDay);
    CExoString GetCustomTag() const;
    void SetCustomTag(const CExoString & sTag);
    void SetLinked(CGameEffect * pLeft, CGameEffect * pRight);
    void UpdateLinked(BOOL bUpdateIconVisibility = false);
    void SaveGameEffect(CResGFF * pRes, CResStruct * pStruct);
    void LoadGameEffect(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CGameEffect
    NWN_CLASS_EXTENSION_CGameEffect
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGameEffect)
#endif

