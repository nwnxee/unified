#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CServerAIBodyBagInfo)
#endif

class CResGFF;
class CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CServerAIBodyBagInfo
{
public:
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

