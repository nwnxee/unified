#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSForcedAction)
#endif

class CResGFF;
class CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSForcedAction
{
public:
    uint32_t m_nActionId;
    uint16_t m_nGroupId;
    OBJECT_ID m_oidArea;
    Vector m_vTargetPosition;
    OBJECT_ID m_oidTarget;

    CNWSForcedAction();
    ~CNWSForcedAction();
    BOOL SaveForcedAction(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadForcedAction(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CNWSForcedAction
    NWN_CLASS_EXTENSION_CNWSForcedAction
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSForcedAction)
#endif

