#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(KEYFILE_KEYENTRY)
#endif



typedef uint8_t RESREF[16];
typedef uint16_t RESTYPE;


class KEYFILE_KEYENTRY
{
    RESREF resRef;
    RESTYPE nType;
    uint32_t nID;



#ifdef NWN_CLASS_EXTENSION_KEYFILE_KEYENTRY
    NWN_CLASS_EXTENSION_KEYFILE_KEYENTRY
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(KEYFILE_KEYENTRY)
#endif

