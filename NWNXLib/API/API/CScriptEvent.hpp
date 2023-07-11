#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptEvent)
#endif

class CResGFF;
class CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CScriptEvent
{
public:
    uint16_t m_nType;
    CExoArrayList<int32_t> m_nParamInteger;
    CExoArrayList<float> m_fParamFloat;
    CExoArrayList<CExoString> m_sParamString;
    CExoArrayList<OBJECT_ID> m_oidParamObjectID;

    CScriptEvent();
    ~CScriptEvent();
    int32_t GetInteger(int32_t nStorageLocation);
    void SetInteger(int32_t nStorageLocation, int32_t nValue);
    float GetFloat(int32_t nStorageLocation);
    void SetFloat(int32_t nStorageLocation, float fValue);
    OBJECT_ID GetObjectID(int32_t nStorageLocation);
    void SetObjectID(int32_t nStorageLocation, OBJECT_ID oidValue);
    CExoString GetString(int32_t nStorageLocation);
    void SetString(int32_t nStorageLocation, CExoString sString);
    BOOL operator==(const CScriptEvent & scriptEvent) const;
    BOOL operator!=(const CScriptEvent & scriptEvent) const;
    void CopyScriptEvent(CScriptEvent * pScriptEvent);
    BOOL SaveEvent(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadEvent(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CScriptEvent
    NWN_CLASS_EXTENSION_CScriptEvent
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptEvent)
#endif

