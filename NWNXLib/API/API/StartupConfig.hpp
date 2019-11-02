#pragma once
#include "nwn_api.hpp"

#include "CompressionAlgorithm.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(StartupConfig)
#endif





struct StartupConfig
{
    CompressionAlgorithm m_compressionType;

    StartupConfig();


#ifdef NWN_CLASS_EXTENSION_StartupConfig
    NWN_CLASS_EXTENSION_StartupConfig
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(StartupConfig)
#endif

