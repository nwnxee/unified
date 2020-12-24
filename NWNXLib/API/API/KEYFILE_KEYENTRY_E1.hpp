#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(KEYFILE_KEYENTRY_E1)
#endif



typedef uint8_t RESREF[16];
typedef uint16_t RESTYPE;


struct KEYFILE_KEYENTRY_E1
{
    RESREF resRef;
    RESTYPE nType;
    uint32_t nID;
    uint8_t sSha1[20];



#ifdef NWN_CLASS_EXTENSION_KEYFILE_KEYENTRY_E1
    NWN_CLASS_EXTENSION_KEYFILE_KEYENTRY_E1
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(KEYFILE_KEYENTRY_E1)
#endif

