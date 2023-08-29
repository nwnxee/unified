#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(EXOLOCSTRING)
#endif





class EXOLOCSTRING
{
public:
    int32_t nID;
    CExoString sString;



#ifdef NWN_CLASS_EXTENSION_EXOLOCSTRING
    NWN_CLASS_EXTENSION_EXOLOCSTRING
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(EXOLOCSTRING)
#endif

