#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWSObjectActionNode
{
    uint32_t m_nActionId;
    uint32_t m_nParamType[12];
    void* m_pParameter[12];
    uint16_t m_nGroupActionId;
    uint16_t m_nParameters;
    int32_t m_bInterruptable;

    // The below are auto generated stubs.
    CNWSObjectActionNode(const CNWSObjectActionNode&) = default;
    CNWSObjectActionNode& operator=(const CNWSObjectActionNode&) = default;

    CNWSObjectActionNode();
    ~CNWSObjectActionNode();
};

void CNWSObjectActionNode__CNWSObjectActionNodeCtor__0(CNWSObjectActionNode* thisPtr);
void CNWSObjectActionNode__CNWSObjectActionNodeDtor__0(CNWSObjectActionNode* thisPtr);

}

}
