#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CServerAIBodyBagInfo)
#endif

struct CResStruct;
struct CResGFF;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CServerAIBodyBagInfo
{
    OBJECT_ID m_oidBodyBag;
    Vector m_vPosition;

    BOOL SaveBodyBag(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadBodyBag(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CServerAIBodyBagInfo
    NWN_CLASS_EXTENSION_CServerAIBodyBagInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CServerAIBodyBagInfo)
#endif

