#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "DataBlockRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(ResRefBatchInsertEntry)
#endif



typedef uint16_t RESTYPE;


struct ResRefBatchInsertEntry
{
    CExoString m_resrefSha1;
    DataBlockRef m_data;
    RESTYPE m_resType;
    bool m_alreadyCompressed;



#ifdef NWN_CLASS_EXTENSION_ResRefBatchInsertEntry
    NWN_CLASS_EXTENSION_ResRefBatchInsertEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(ResRefBatchInsertEntry)
#endif

