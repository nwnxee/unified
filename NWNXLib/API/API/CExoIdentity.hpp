#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoIdentity)
#endif



typedef uint32_t STRREF;
typedef int BOOL;


struct CExoIdentity
{

    void StartIdentityFetch();
    BOOL IsIdentityFetchComplete();
    BOOL GetIdentity(uint8_t * pIdentity, uint32_t * nIdentityLength, uint8_t * pToken, uint32_t * nTokenLength, STRREF * errorMessage);
    IdentityType GetIdentityType();


#ifdef NWN_CLASS_EXTENSION_CExoIdentity
    NWN_CLASS_EXTENSION_CExoIdentity
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoIdentity)
#endif

