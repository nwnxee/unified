#pragma once
#include "nwn_api.hpp"

#include "CGuiCallbackv1<void.hpp"
#include "CGuiFnS.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGuiCallbackS)
#endif





struct CGuiCallbackS : CGuiCallbackv1<void, CExoString>
{

    void SetCallbackS(CGuiFnS HandlerFunction);


#ifdef NWN_CLASS_EXTENSION_CGuiCallbackS
    NWN_CLASS_EXTENSION_CGuiCallbackS
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGuiCallbackS)
#endif

