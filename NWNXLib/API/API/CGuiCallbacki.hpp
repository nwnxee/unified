#pragma once
#include "nwn_api.hpp"

#include "CGuiFni.hpp"
#include "int.hpp"
#include "CGuiCallbackv1<void.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGuiCallbacki)
#endif





struct CGuiCallbacki : CGuiCallbackv1<void, int>
{

    void SetCallbacki(CGuiFni HandlerFunction);


#ifdef NWN_CLASS_EXTENSION_CGuiCallbacki
    NWN_CLASS_EXTENSION_CGuiCallbacki
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGuiCallbacki)
#endif

