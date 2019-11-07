#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include <vector>
#include "NWSyncAdvertisementManifest.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(NWSyncAdvertisement)
#endif





struct NWSyncAdvertisement
{
    CExoString m_primary_manifest;
    std::vector<NWSyncAdvertisementManifest> m_additional_manifests;
    CExoString m_url;



#ifdef NWN_CLASS_EXTENSION_NWSyncAdvertisement
    NWN_CLASS_EXTENSION_NWSyncAdvertisement
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(NWSyncAdvertisement)
#endif

