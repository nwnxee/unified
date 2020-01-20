#pragma once
#include "nwn_api.hpp"

#include "Definition.hpp"
#include "Identifier.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(StorageShardAllocParams)
#endif





struct StorageShardAllocParams
{
    Identifier m_id;
    Definition m_migrations;



#ifdef NWN_CLASS_EXTENSION_StorageShardAllocParams
    NWN_CLASS_EXTENSION_StorageShardAllocParams
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(StorageShardAllocParams)
#endif

