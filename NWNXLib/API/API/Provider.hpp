#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(Provider)
#endif





struct Provider
{
    CExoString m_identity;



#ifdef NWN_CLASS_EXTENSION_Provider
    NWN_CLASS_EXTENSION_Provider
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(Provider)
#endif

