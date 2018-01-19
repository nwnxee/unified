#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFF;
struct CResStruct;

struct CServerAIEventNode
{
    uint32_t m_nCalendarDay;
    uint32_t m_nTimeOfDay;
    uint32_t m_nCallerObjectId;
    uint32_t m_nObjectId;
    uint32_t m_nEventId;
    void* m_pEventData;

    int32_t LoadNode(CResGFF*, CResStruct*);
    int32_t SaveNode(CResGFF*, CResStruct*);
};

int32_t CServerAIEventNode__LoadNode(CServerAIEventNode* thisPtr, CResGFF*, CResStruct*);
int32_t CServerAIEventNode__SaveNode(CServerAIEventNode* thisPtr, CResGFF*, CResStruct*);

}

}
