#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFF;
struct CResStruct;

struct CServerAIBodyBagInfo
{
    uint32_t m_oidBodyBag;
    Vector m_vPosition;

    int32_t LoadBodyBag(CResGFF*, CResStruct*);
    int32_t SaveBodyBag(CResGFF*, CResStruct*);
};

int32_t CServerAIBodyBagInfo__LoadBodyBag(CServerAIBodyBagInfo* thisPtr, CResGFF*, CResStruct*);
int32_t CServerAIBodyBagInfo__SaveBodyBag(CServerAIBodyBagInfo* thisPtr, CResGFF*, CResStruct*);

}

}
