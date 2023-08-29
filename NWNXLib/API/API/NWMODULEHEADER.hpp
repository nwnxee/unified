#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(NWMODULEHEADER)
#endif





class NWMODULEHEADER
{
public:
    char pModuleID[32];
    int32_t nModuleCreatorID;
    uint32_t nModuleVersion;



#ifdef NWN_CLASS_EXTENSION_NWMODULEHEADER
    NWN_CLASS_EXTENSION_NWMODULEHEADER
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(NWMODULEHEADER)
#endif

