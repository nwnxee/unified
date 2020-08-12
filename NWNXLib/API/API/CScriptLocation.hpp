#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptLocation)
#endif

struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CScriptLocation
{
    Vector m_vPosition;
    Vector m_vOrientation;
    OBJECT_ID m_oArea;

    void CopyScriptLocation(CScriptLocation * pLocation);
    BOOL SaveLocation(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadLocation(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CScriptLocation
    NWN_CLASS_EXTENSION_CScriptLocation
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptLocation)
#endif

