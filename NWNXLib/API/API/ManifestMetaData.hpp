#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(ManifestMetaData)
#endif





struct ManifestMetaData
{
    CExoString m_sha1;
    uint32_t m_hashTreeDepth;
    CExoString m_moduleName;
    CExoString m_description;
    uint32_t m_groupId;
    bool m_includesModuleContents;
    uint32_t m_totalBytes;
    uint32_t m_totalFiles;
    uint32_t m_createdAt;



#ifdef NWN_CLASS_EXTENSION_ManifestMetaData
    NWN_CLASS_EXTENSION_ManifestMetaData
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(ManifestMetaData)
#endif

