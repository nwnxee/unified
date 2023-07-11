#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSObjectActionNode)
#endif



typedef int BOOL;


class CNWSObjectActionNode
{
    uint32_t m_nActionId;
    uint32_t m_nParamType[12];
    intptr_t m_pParameter[12];
    uint16_t m_nGroupActionId;
    uint16_t m_nParameters;
    BOOL m_bInterruptable;

    CNWSObjectActionNode();
    ~CNWSObjectActionNode();


#ifdef NWN_CLASS_EXTENSION_CNWSObjectActionNode
    NWN_CLASS_EXTENSION_CNWSObjectActionNode
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSObjectActionNode)
#endif

