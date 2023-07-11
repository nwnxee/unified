#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptTalent)
#endif

class CResGFF;
class CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CScriptTalent
{
    int32_t m_nType;
    int32_t m_nID;
    uint8_t m_nMultiClass;
    OBJECT_ID m_oidItem;
    int32_t m_nItemPropertyIndex;
    uint8_t m_nCasterLevel;
    uint8_t m_nMetaType;

    CScriptTalent();
    ~CScriptTalent();
    void CopyScriptTalent(CScriptTalent * pTalent);
    BOOL Equals(CScriptTalent * pTalent);
    BOOL SaveTalent(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadTalent(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CScriptTalent
    NWN_CLASS_EXTENSION_CScriptTalent
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptTalent)
#endif

