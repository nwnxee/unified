#pragma once
#include "nwn_api.hpp"

#include "CGuiFnX.hpp"
#include "CGuiFn.hpp"
#include "CGuiCallbackBase.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGuiCallback)
#endif





struct CGuiCallback : CGuiCallbackBase
{
    CGuiFnX m_pfnHandlerFunction;

    void SetCallback(CGuiFn HandlerFunction);


#ifdef NWN_CLASS_EXTENSION_CGuiCallback
    NWN_CLASS_EXTENSION_CGuiCallback
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGuiCallback)
#endif

