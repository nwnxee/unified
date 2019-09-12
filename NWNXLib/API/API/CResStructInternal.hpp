#pragma once
#include "nwn_api.hpp"

#include "CExoLinkedList.hpp"
#include "CStringFieldIDType.hpp"
#include "CResStructHeader.hpp"
#include "List.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResStructInternal)
#endif

struct CResStructLookUp;
struct CResStructLookUp;
struct CStringFieldIDType;


typedef int BOOL;


struct CResStructInternal
{
    CResStructHeader m_Header;
    CResStructLookUp * m_pLookUp;
    void * m_pData;
    uint32_t m_nLocalDataSize;
    uint32_t m_nTotalDataSize;
    uint32_t m_nMaxDataSize;
    uint32_t m_nMaxLookUpID;
    CResStructInternal * m_pParent;
    uint32_t m_nParentIndex;
    BOOL m_bIncludeStringHashTable;
    List< CStringFieldIDType> m_listStringFieldIDs;
    int32_t m_nNumEmptyFields;
    int32_t m_nNumCopiedFields;
    CExoLinkedList<CResStructInternal> * m_pChildList;

    CResStructInternal(uint32_t nType);
    ~CResStructInternal();
    uint32_t WriteSideHashSearch(char * szFieldID);
    void HashSortStringTable(List< CResStructLookUp *> * pOutputLookupPointers, List< CStringFieldIDType *> * pOutputFieldIDPointers);


#ifdef NWN_CLASS_EXTENSION_CResStructInternal
    NWN_CLASS_EXTENSION_CResStructInternal
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResStructInternal)
#endif

