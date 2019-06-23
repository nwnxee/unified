#pragma once
#include "nwn_api.hpp"

#include "CGuiCallbackv1<void.hpp"
#include "CGuiFnf.hpp"
#include "float.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGuiCallbackf)
#endif





struct CGuiCallbackf : CGuiCallbackv1<void, float>
{

    void SetCallbackf(CGuiFnf HandlerFunction);


#ifdef NWN_CLASS_EXTENSION_CGuiCallbackf
    NWN_CLASS_EXTENSION_CGuiCallbackf
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGuiCallbackf)
#endif

