#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CObjectLookupTable
{
    uint32_t* m_pdwObjectTable;
    uint32_t m_dwStart;
    uint32_t m_dwEnd;
    int32_t m_bUpdateRequired;

    // The below are auto generated stubs.
    CObjectLookupTable(const CObjectLookupTable&) = default;
    CObjectLookupTable& operator=(const CObjectLookupTable&) = default;

    CObjectLookupTable();
    ~CObjectLookupTable();
    uint32_t AddID(uint32_t);
    uint32_t GetIDFromIndex(uint32_t);
    uint32_t GetIndexFromID(uint32_t);
    void GetUpdate(void*, uint32_t*);
    void Touch(uint32_t);
    void Update(void*, uint32_t);
};

void CObjectLookupTable__CObjectLookupTableCtor(CObjectLookupTable* thisPtr);
void CObjectLookupTable__CObjectLookupTableDtor(CObjectLookupTable* thisPtr);
uint32_t CObjectLookupTable__AddID(CObjectLookupTable* thisPtr, uint32_t);
uint32_t CObjectLookupTable__GetIDFromIndex(CObjectLookupTable* thisPtr, uint32_t);
uint32_t CObjectLookupTable__GetIndexFromID(CObjectLookupTable* thisPtr, uint32_t);
void CObjectLookupTable__GetUpdate(CObjectLookupTable* thisPtr, void*, uint32_t*);
void CObjectLookupTable__Touch(CObjectLookupTable* thisPtr, uint32_t);
void CObjectLookupTable__Update(CObjectLookupTable* thisPtr, void*, uint32_t);

}

}
