#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSync::StartupConfig)
#endif





struct CNWSync::StartupConfig
{
    CExoString m_path;
    StorageType m_storageType;
    NWCompressedBuffer::CompressionAlgorithm m_compressionType;
    size_t m_sqlShardCount;

    StartupConfig();


#ifdef NWN_CLASS_EXTENSION_CNWSync::StartupConfig
    NWN_CLASS_EXTENSION_CNWSync::StartupConfig
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSync::StartupConfig)
#endif

