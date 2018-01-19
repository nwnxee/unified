#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWBaseItem;

struct CNWBaseItemArray
{
    int32_t m_nNumBaseItems;
    CNWBaseItem* m_pBaseItems;

    // The below are auto generated stubs.
    CNWBaseItemArray(const CNWBaseItemArray&) = default;
    CNWBaseItemArray& operator=(const CNWBaseItemArray&) = default;

    CNWBaseItemArray();
    ~CNWBaseItemArray();
    CNWBaseItem* GetBaseItem(int32_t);
    void Load();
};

void CNWBaseItemArray__CNWBaseItemArrayCtor__0(CNWBaseItemArray* thisPtr);
void CNWBaseItemArray__CNWBaseItemArrayDtor__0(CNWBaseItemArray* thisPtr);
CNWBaseItem* CNWBaseItemArray__GetBaseItem(CNWBaseItemArray* thisPtr, int32_t);
void CNWBaseItemArray__Load(CNWBaseItemArray* thisPtr);

}

}
