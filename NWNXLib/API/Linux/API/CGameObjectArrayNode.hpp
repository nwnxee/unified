#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CGameObject;

struct CGameObjectArrayNode
{
    uint32_t m_objectId;
    CGameObject* m_objectPtr;
    CGameObjectArrayNode* m_nextNode;
};

}

}
