#pragma once
#include "nwn_api.hpp"

#include "CResStructHeader.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResStruct)
#endif

struct CResStructInternal;
struct CResStructLookUp;
struct CStringFieldIDType;


typedef int BOOL;


struct CResStruct
{
    CResStructHeader m_cHeader;
    CResStructLookUp * m_pLookUp;
    void * m_pData;
    CResStructInternal * m_pWriteStructInternal;
    BOOL m_bIncludeStringHashTable;
    CStringFieldIDType * m_pStringFieldIDs;

    //void SetIncludeWrittenStringHashTable(BOOL bIncludeStringTable);
    //uint32_t HashSearch(char * szFieldID);


#ifdef NWN_CLASS_EXTENSION_CResStruct
    NWN_CLASS_EXTENSION_CResStruct
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResStruct)
#endif

