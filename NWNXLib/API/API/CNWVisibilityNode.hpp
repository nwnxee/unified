#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWVisibilityNode)
#endif



typedef uint32_t OBJECT_ID;


class CNWVisibilityNode
{
    OBJECT_ID m_oidCreature;
    uint8_t m_bSeen : 1;
    uint8_t m_bHeard : 1;
    uint8_t m_nSanctuary : 2;
    uint8_t m_bInvisible : 1;



#ifdef NWN_CLASS_EXTENSION_CNWVisibilityNode
    NWN_CLASS_EXTENSION_CNWVisibilityNode
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWVisibilityNode)
#endif

