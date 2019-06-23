#pragma once
#include "nwn_api.hpp"

#include "CGuiFnX.hpp"
#include "CGuiCallbackBase.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGuiCallbackv1)
#endif





template <class tReturnVOID, class tParam0> struct CGuiCallbackv1 : CGuiCallbackBase
{
    CGuiFnX m_pfnHandlerFunction;



#ifdef NWN_CLASS_EXTENSION_CGuiCallbackv1
    NWN_CLASS_EXTENSION_CGuiCallbackv1
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGuiCallbackv1)
#endif

