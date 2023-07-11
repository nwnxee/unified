#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CServerAIEventNode)
#endif

class CResGFF;
class CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CServerAIEventNode
{
    uint32_t m_nCalendarDay;
    uint32_t m_nTimeOfDay;
    OBJECT_ID m_nCallerObjectId;
    OBJECT_ID m_nObjectId;
    uint32_t m_nEventId;
    void * m_pEventData;

    BOOL SaveNode(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadNode(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CServerAIEventNode
    NWN_CLASS_EXTENSION_CServerAIEventNode
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CServerAIEventNode)
#endif

