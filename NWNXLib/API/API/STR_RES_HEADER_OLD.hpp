#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(STR_RES_HEADER_OLD)
#endif



typedef uint8_t RESREF[16];


class STR_RES_HEADER_OLD
{
public:
    uint32_t wFlags;
    RESREF sndResRef;
    uint32_t volumeVariance;
    uint32_t pitchVariance;
    uint32_t offsetToStr;
    uint32_t strSize;



#ifdef NWN_CLASS_EXTENSION_STR_RES_HEADER_OLD
    NWN_CLASS_EXTENSION_STR_RES_HEADER_OLD
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(STR_RES_HEADER_OLD)
#endif

