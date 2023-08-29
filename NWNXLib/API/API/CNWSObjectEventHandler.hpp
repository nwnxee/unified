#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSObjectEventHandler)
#endif





class CNWSObjectEventHandler
{
public:
    uint32_t m_nEventId;
    CExoString m_sScriptName;



#ifdef NWN_CLASS_EXTENSION_CNWSObjectEventHandler
    NWN_CLASS_EXTENSION_CNWSObjectEventHandler
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSObjectEventHandler)
#endif

