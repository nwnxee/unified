#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CObjectLookupTable;

struct CObjectTableManager
{
    CObjectLookupTable* m_pObjectTableArray[96];
    uint32_t m_dwMaxPlayerID;

    // The below are auto generated stubs.
    CObjectTableManager(const CObjectTableManager&) = default;
    CObjectTableManager& operator=(const CObjectTableManager&) = default;

    CObjectTableManager();
    ~CObjectTableManager();
    int32_t AddID(uint32_t, uint32_t*, uint32_t);
    void ClearAll();
    int32_t CreateNewPlayer(uint32_t);
    uint32_t GetIDFromIndex(uint32_t, uint32_t);
    uint32_t GetIndexFromID(uint32_t, uint32_t);
    int32_t RemovePlayer(uint32_t);
    int32_t Touch(uint32_t, uint32_t);
};

void CObjectTableManager__CObjectTableManagerCtor__0(CObjectTableManager* thisPtr);
void CObjectTableManager__CObjectTableManagerDtor__0(CObjectTableManager* thisPtr);
int32_t CObjectTableManager__AddID(CObjectTableManager* thisPtr, uint32_t, uint32_t*, uint32_t);
void CObjectTableManager__ClearAll(CObjectTableManager* thisPtr);
int32_t CObjectTableManager__CreateNewPlayer(CObjectTableManager* thisPtr, uint32_t);
uint32_t CObjectTableManager__GetIDFromIndex(CObjectTableManager* thisPtr, uint32_t, uint32_t);
uint32_t CObjectTableManager__GetIndexFromID(CObjectTableManager* thisPtr, uint32_t, uint32_t);
int32_t CObjectTableManager__RemovePlayer(CObjectTableManager* thisPtr, uint32_t);
int32_t CObjectTableManager__Touch(CObjectTableManager* thisPtr, uint32_t, uint32_t);

}

}
