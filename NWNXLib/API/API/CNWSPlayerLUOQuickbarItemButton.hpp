#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlayerLUOQuickbarItemButton)
#endif



typedef uint32_t OBJECT_ID;


class CNWSPlayerLUOQuickbarItemButton
{
    OBJECT_ID m_oidItem;
    uint8_t m_nObjectType;
    int32_t m_nINTParam1;
    uint16_t m_nUseCount;



#ifdef NWN_CLASS_EXTENSION_CNWSPlayerLUOQuickbarItemButton
    NWN_CLASS_EXTENSION_CNWSPlayerLUOQuickbarItemButton
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlayerLUOQuickbarItemButton)
#endif

