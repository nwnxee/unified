#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWActionNode)
#endif



typedef uint32_t OBJECT_ID;


class CNWActionNode
{
    uint16_t nGroupId;
    uint16_t nActionId;
    uint16_t nSpecialAttackId;
    uint32_t nSpellId;
    Vector vTargetPos;
    OBJECT_ID oidTarget;



#ifdef NWN_CLASS_EXTENSION_CNWActionNode
    NWN_CLASS_EXTENSION_CNWActionNode
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWActionNode)
#endif

