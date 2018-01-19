#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFF;
struct CResStruct;

struct CGameEffect
{
    uint64_t m_nID;
    uint16_t m_nType;
    uint16_t m_nSubType;
    float m_fDuration;
    uint32_t m_nExpiryCalendarDay;
    uint32_t m_nExpiryTimeOfDay;
    uint32_t m_oidCreator;
    uint32_t m_nSpellId;
    int32_t m_bExpose;
    int32_t m_bShowIcon;
    int32_t m_nCasterLevel;
    CGameEffect* m_pLinkLeft;
    CGameEffect* m_pLinkRight;
    int32_t m_nNumIntegers;
    int32_t* m_nParamInteger;
    float m_nParamFloat[4];
    CExoString m_sParamString[6];
    uint32_t m_oidParamObjectID[4];
    int32_t m_bSkipOnLoad;
    uint64_t m_nItemPropertySourceId;
    CExoString m_sCustomTag;

    // The below are auto generated stubs.
    CGameEffect() = default;
    CGameEffect(const CGameEffect&) = default;

    CGameEffect(int32_t);
    CGameEffect(CGameEffect*, int32_t);
    ~CGameEffect();
    void CopyEffect(CGameEffect*, int32_t);
    CExoString GetCustomTag();
    void GetExpiryTime(uint32_t*, uint32_t*);
    float GetFloat(int32_t);
    int32_t GetInteger(int32_t);
    uint32_t GetObjectID(int32_t);
    int32_t GetScriptEffectType();
    CExoString GetString(int32_t);
    void LoadGameEffect(CResGFF*, CResStruct*);
    int32_t operator!=(const CGameEffect&);
    CGameEffect& operator=(const CGameEffect&);
    int32_t operator==(const CGameEffect&);
    void SaveGameEffect(CResGFF*, CResStruct*);
    void SetCreator(uint32_t);
    void SetCustomTag(const CExoString&);
    void SetExpiryTime(uint32_t, uint32_t);
    void SetFloat(int32_t, float);
    void SetInteger(int32_t, int32_t);
    void SetLinked(CGameEffect*, CGameEffect*);
    void SetNumIntegers(int32_t);
    void SetNumIntegersInitializeToNegativeOne(int32_t);
    void SetObjectID(int32_t, uint32_t);
    void SetString(int32_t, CExoString);
    void UpdateLinked();
};

void CGameEffect__CGameEffectCtor__0(CGameEffect* thisPtr, int32_t);
void CGameEffect__CGameEffectCtor__2(CGameEffect* thisPtr, CGameEffect*, int32_t);
void CGameEffect__CGameEffectDtor__0(CGameEffect* thisPtr);
void CGameEffect__CopyEffect(CGameEffect* thisPtr, CGameEffect*, int32_t);
CExoString CGameEffect__GetCustomTag(CGameEffect* thisPtr);
void CGameEffect__GetExpiryTime(CGameEffect* thisPtr, uint32_t*, uint32_t*);
float CGameEffect__GetFloat(CGameEffect* thisPtr, int32_t);
int32_t CGameEffect__GetInteger(CGameEffect* thisPtr, int32_t);
uint32_t CGameEffect__GetObjectID(CGameEffect* thisPtr, int32_t);
int32_t CGameEffect__GetScriptEffectType(CGameEffect* thisPtr);
CExoString CGameEffect__GetString(CGameEffect* thisPtr, int32_t);
void CGameEffect__LoadGameEffect(CGameEffect* thisPtr, CResGFF*, CResStruct*);
int32_t CGameEffect__OperatorNotEqualTo(CGameEffect* thisPtr, const CGameEffect&);
CGameEffect& CGameEffect__OperatorAssignment(CGameEffect* thisPtr, const CGameEffect&);
int32_t CGameEffect__OperatorEqualTo(CGameEffect* thisPtr, const CGameEffect&);
void CGameEffect__SaveGameEffect(CGameEffect* thisPtr, CResGFF*, CResStruct*);
void CGameEffect__SetCreator(CGameEffect* thisPtr, uint32_t);
void CGameEffect__SetCustomTag(CGameEffect* thisPtr, const CExoString&);
void CGameEffect__SetExpiryTime(CGameEffect* thisPtr, uint32_t, uint32_t);
void CGameEffect__SetFloat(CGameEffect* thisPtr, int32_t, float);
void CGameEffect__SetInteger(CGameEffect* thisPtr, int32_t, int32_t);
void CGameEffect__SetLinked(CGameEffect* thisPtr, CGameEffect*, CGameEffect*);
void CGameEffect__SetNumIntegers(CGameEffect* thisPtr, int32_t);
void CGameEffect__SetNumIntegersInitializeToNegativeOne(CGameEffect* thisPtr, int32_t);
void CGameEffect__SetObjectID(CGameEffect* thisPtr, int32_t, uint32_t);
void CGameEffect__SetString(CGameEffect* thisPtr, int32_t, CExoString);
void CGameEffect__UpdateLinked(CGameEffect* thisPtr);

}

}
