#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(MappingBatchInsertEntry)
#endif



typedef uint16_t RESTYPE;


struct MappingBatchInsertEntry
{
    CExoString m_resrefSha1;
    CExoString m_resRef;
    RESTYPE m_resType;



#ifdef NWN_CLASS_EXTENSION_MappingBatchInsertEntry
    NWN_CLASS_EXTENSION_MappingBatchInsertEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(MappingBatchInsertEntry)
#endif

