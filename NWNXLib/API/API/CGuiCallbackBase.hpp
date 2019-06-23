#pragma once
#include "nwn_api.hpp"

#include "CCallbackHandlerBase.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGuiCallbackBase)
#endif





struct CGuiCallbackBase : CCallbackHandlerBase
{
    CCallbackHandlerBase * m_pHandlerObject;



#ifdef NWN_CLASS_EXTENSION_CGuiCallbackBase
    NWN_CLASS_EXTENSION_CGuiCallbackBase
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGuiCallbackBase)
#endif

