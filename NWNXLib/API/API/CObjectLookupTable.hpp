#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CObjectLookupTable)
#endif



typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CObjectLookupTable
{
public:
    OBJECT_ID * m_pdwObjectTable;
    uint32_t m_dwStart;
    uint32_t m_dwEnd;
    BOOL m_bUpdateRequired;

    CObjectLookupTable();
    ~CObjectLookupTable();
    uint32_t AddID(OBJECT_ID dwID);
    OBJECT_ID GetIDFromIndex(uint32_t dwSlot);
    void GetUpdate(uint8_t * pData, uint32_t * dwSize);
    void Update(uint8_t * pData, uint32_t dwSize);
    uint32_t GetIndexFromID(OBJECT_ID dwID);
    void Touch(uint32_t dwSlot);


#ifdef NWN_CLASS_EXTENSION_CObjectLookupTable
    NWN_CLASS_EXTENSION_CObjectLookupTable
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CObjectLookupTable)
#endif

