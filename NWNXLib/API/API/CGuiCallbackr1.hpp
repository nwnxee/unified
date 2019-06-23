#pragma once
#include "nwn_api.hpp"

#include "CGuiFnX.hpp"
#include "CGuiCallbackBase.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGuiCallbackr1)
#endif





template <class tReturn, class tParam0> struct CGuiCallbackr1 : CGuiCallbackBase
{
    CGuiFnX m_pfnHandlerFunction;



#ifdef NWN_CLASS_EXTENSION_CGuiCallbackr1
    NWN_CLASS_EXTENSION_CGuiCallbackr1
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGuiCallbackr1)
#endif

