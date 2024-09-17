#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWCCMessageData)
#endif

struct CResGFF;
struct CResStruct;


typedef uint32_t OBJECT_ID;


struct CNWCCMessageData
{
    uint8_t m_nType = 0;
    CExoArrayList<int32_t> m_nParamInteger;
    CExoArrayList<float> m_nParamFloat;
    CExoArrayList<CExoString> m_sParamString;
    CExoArrayList<OBJECT_ID> m_oidParamObjectID;

    CNWCCMessageData() { }
    ~CNWCCMessageData() { }
    int32_t GetInteger(int32_t nStorageLocation);
    void SetInteger(int32_t nStorageLocation, int32_t nValue);
    float GetFloat(int32_t nStorageLocation);
    void SetFloat(int32_t nStorageLocation, float fValue);
    OBJECT_ID GetObjectID(int32_t nStorageLocation);
    void SetObjectID(int32_t nStorageLocation, OBJECT_ID oidValue);
    CExoString GetString(int32_t nStorageLocation);
    void SetString(int32_t nStorageLocation, CExoString sString);
    int32_t SaveData(CResGFF * pRes, CResStruct * pStruct);
    int32_t LoadData(CResGFF * pRes, CResStruct * pStruct);
    void CopyTo(CNWCCMessageData * pDestinationData);
    void ClearData();


#ifdef NWN_CLASS_EXTENSION_CNWCCMessageData
    NWN_CLASS_EXTENSION_CNWCCMessageData
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWCCMessageData)
#endif

