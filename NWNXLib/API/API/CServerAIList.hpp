#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CServerAIList)
#endif

class CNWSObject;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CServerAIList
{
    CExoArrayList<OBJECT_ID> m_aoGameObjects;
    int32_t m_nPosition;

    CServerAIList();
    ~CServerAIList();
    BOOL AddObject(OBJECT_ID oidObjectToAdd);
    BOOL RemoveObject(OBJECT_ID oidObjectToRemove);
    CNWSObject * GetNextObject();


#ifdef NWN_CLASS_EXTENSION_CServerAIList
    NWN_CLASS_EXTENSION_CServerAIList
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CServerAIList)
#endif

