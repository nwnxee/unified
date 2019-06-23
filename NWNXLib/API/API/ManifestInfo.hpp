#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "ManifestMetaData.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(ManifestInfo)
#endif





struct ManifestInfo
{
    CExoString m_sha1;
    CExoString m_originUrl;
    uint32_t m_createdAt;
    uint32_t m_lastUsedAt;
    bool m_pinned;
    uint64_t m_mappingCount;
    uint64_t m_totalbytes;
    ManifestMetaData m_metadata;



#ifdef NWN_CLASS_EXTENSION_ManifestInfo
    NWN_CLASS_EXTENSION_ManifestInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(ManifestInfo)
#endif

