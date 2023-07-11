#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSSpellScriptData)
#endif

class CResGFF;
class CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSSpellScriptData
{
public:
    int32_t m_nSpellId;
    uint16_t m_nFeatId;
    OBJECT_ID m_oidCaster;
    OBJECT_ID m_oidTarget;
    OBJECT_ID m_oidItem;
    Vector m_vTargetPosition;
    CExoString m_sScript;
    OBJECT_ID m_oidArea;
    int32_t m_nItemCastLevel;

    BOOL SaveData(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadData(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CNWSSpellScriptData
    NWN_CLASS_EXTENSION_CNWSSpellScriptData
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSSpellScriptData)
#endif

