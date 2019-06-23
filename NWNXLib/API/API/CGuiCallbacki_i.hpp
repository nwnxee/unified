#pragma once
#include "nwn_api.hpp"

#include "int.hpp"
#include "CGuiCallbackr1<int.hpp"
#include "CGuiFni_i.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CGuiCallbacki_i)
#endif





struct CGuiCallbacki_i : CGuiCallbackr1<int, int>
{

    void SetCallbacki_i(CGuiFni_i HandlerFunction);


#ifdef NWN_CLASS_EXTENSION_CGuiCallbacki_i
    NWN_CLASS_EXTENSION_CGuiCallbacki_i
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CGuiCallbacki_i)
#endif

