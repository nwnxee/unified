#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(ENCAPSULATED_RESLISTENTRY_E1)
#endif





struct ENCAPSULATED_RESLISTENTRY_E1
{
    uint32_t nOffsetToResource;
    uint32_t nResourceSize;
    uint32_t nCompressionType;
    uint32_t nUncompressedSize;



#ifdef NWN_CLASS_EXTENSION_ENCAPSULATED_RESLISTENTRY_E1
    NWN_CLASS_EXTENSION_ENCAPSULATED_RESLISTENTRY_E1
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(ENCAPSULATED_RESLISTENTRY_E1)
#endif

