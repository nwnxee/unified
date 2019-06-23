#pragma once
#include "nwn_api.hpp"

#include "CGuiFnii.hpp"
#include "int.hpp"
#include "CGuiCallbackv2<void.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGuiCallbackii)
#endif





struct CGuiCallbackii : CGuiCallbackv2<void, int, int>
{

    void SetCallbackii(CGuiFnii HandlerFunction);


#ifdef NWN_CLASS_EXTENSION_CGuiCallbackii
    NWN_CLASS_EXTENSION_CGuiCallbackii
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGuiCallbackii)
#endif

