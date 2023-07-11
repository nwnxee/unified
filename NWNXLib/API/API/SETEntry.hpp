#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(SETEntry)
#endif





class SETEntry
{
    CExoString m_sEntry;
    CExoString m_sValue;



#ifdef NWN_CLASS_EXTENSION_SETEntry
    NWN_CLASS_EXTENSION_SETEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(SETEntry)
#endif

