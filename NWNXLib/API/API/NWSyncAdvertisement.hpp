#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "NWSyncAdvertisementManifest.hpp"
#include "SHA1.hpp"
#include <vector>

namespace NWSync {

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(NWSyncAdvertisement)
#endif


struct Advertisement {
    Hash::SHA1 m_primary_manifest;
    std::vector<NWSync::AdvertisementManifest> m_additional_manifests;
    CExoString m_url;


#ifdef NWN_CLASS_EXTENSION_NWSyncAdvertisement
    NWN_CLASS_EXTENSION_NWSyncAdvertisement
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(NWSyncAdvertisement)
#endif

}
