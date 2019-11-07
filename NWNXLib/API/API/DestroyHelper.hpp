#pragma once
#include "nwn_api.hpp"

#include "Identifier.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(DestroyHelper)
#endif





struct DestroyHelper
{
    bool m_do;
    Identifier m_id;

    ~DestroyHelper();


#ifdef NWN_CLASS_EXTENSION_DestroyHelper
    NWN_CLASS_EXTENSION_DestroyHelper
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(DestroyHelper)
#endif

