#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedlongunsignedint.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSObject;

struct CServerAIList
{
    CExoArrayListTemplatedlongunsignedint m_aoGameObjects;
    int32_t m_nPosition;

    // The below are auto generated stubs.
    CServerAIList(const CServerAIList&) = default;
    CServerAIList& operator=(const CServerAIList&) = default;

    CServerAIList();
    ~CServerAIList();
    int32_t AddObject(uint32_t);
    CNWSObject* GetNextObject();
    int32_t RemoveObject(uint32_t);
};

void CServerAIList__CServerAIListCtor(CServerAIList* thisPtr);
void CServerAIList__CServerAIListDtor(CServerAIList* thisPtr);
int32_t CServerAIList__AddObject(CServerAIList* thisPtr, uint32_t);
CNWSObject* CServerAIList__GetNextObject(CServerAIList* thisPtr);
int32_t CServerAIList__RemoveObject(CServerAIList* thisPtr, uint32_t);

}

}
