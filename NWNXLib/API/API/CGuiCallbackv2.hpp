#pragma once
#include "nwn_api.hpp"

#include "CGuiFnX.hpp"
#include "CGuiCallbackBase.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGuiCallbackv2)
#endif





template <class tReturnVOID, class tParam0, class tParam1> struct CGuiCallbackv2 : CGuiCallbackBase
{
    CGuiFnX m_pfnHandlerFunction;



#ifdef NWN_CLASS_EXTENSION_CGuiCallbackv2
    NWN_CLASS_EXTENSION_CGuiCallbackv2
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGuiCallbackv2)
#endif

