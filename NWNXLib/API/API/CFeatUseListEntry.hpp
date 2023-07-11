#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CFeatUseListEntry)
#endif





class CFeatUseListEntry
{
    uint16_t m_nFeat;
    uint8_t m_nUsedToday;



#ifdef NWN_CLASS_EXTENSION_CFeatUseListEntry
    NWN_CLASS_EXTENSION_CFeatUseListEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CFeatUseListEntry)
#endif

