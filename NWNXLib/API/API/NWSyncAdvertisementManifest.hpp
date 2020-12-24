#pragma once
#include "nwn_api.hpp"

#include "SHA1.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(NWSyncAdvertisementManifest)
#endif





struct NWSyncAdvertisementManifest
{
    SHA1 m_hash;
    uint8_t m_flags;
    uint8_t m_languageId;



#ifdef NWN_CLASS_EXTENSION_NWSyncAdvertisementManifest
    NWN_CLASS_EXTENSION_NWSyncAdvertisementManifest
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(NWSyncAdvertisementManifest)
#endif

