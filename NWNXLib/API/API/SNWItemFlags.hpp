#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(SNWItemFlags)
#endif





class SNWItemFlags
{
    uint8_t m_nDropable;
    uint8_t m_nPickpocketable;



#ifdef NWN_CLASS_EXTENSION_SNWItemFlags
    NWN_CLASS_EXTENSION_SNWItemFlags
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(SNWItemFlags)
#endif

