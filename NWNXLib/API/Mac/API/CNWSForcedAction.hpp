#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFF;
struct CResStruct;

struct CNWSForcedAction
{
    uint32_t m_nActionId;
    uint16_t m_nGroupId;
    uint32_t m_oidArea;
    Vector m_vTargetPosition;
    uint32_t m_oidTarget;

    // The below are auto generated stubs.
    CNWSForcedAction(const CNWSForcedAction&) = default;
    CNWSForcedAction& operator=(const CNWSForcedAction&) = default;

    CNWSForcedAction();
    ~CNWSForcedAction();
    int32_t LoadForcedAction(CResGFF*, CResStruct*);
    int32_t SaveForcedAction(CResGFF*, CResStruct*);
};

void CNWSForcedAction__CNWSForcedActionCtor__0(CNWSForcedAction* thisPtr);
void CNWSForcedAction__CNWSForcedActionDtor__0(CNWSForcedAction* thisPtr);
int32_t CNWSForcedAction__LoadForcedAction(CNWSForcedAction* thisPtr, CResGFF*, CResStruct*);
int32_t CNWSForcedAction__SaveForcedAction(CNWSForcedAction* thisPtr, CResGFF*, CResStruct*);

}

}
