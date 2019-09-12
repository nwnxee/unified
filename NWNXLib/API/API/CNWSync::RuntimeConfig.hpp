#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSync::RuntimeConfig)
#endif





struct CNWSync::RuntimeConfig
{
    bool m_autoDeleteDanglingData;

    RuntimeConfig();


#ifdef NWN_CLASS_EXTENSION_CNWSync::RuntimeConfig
    NWN_CLASS_EXTENSION_CNWSync::RuntimeConfig
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSync::RuntimeConfig)
#endif

