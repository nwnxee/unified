#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CNWItem
{
    void** m_vtable;
    uint8_t m_nLayeredTextureColors[6];
    uint32_t m_nBaseItem;

    // The below are auto generated stubs.
    CNWItem(const CNWItem&);
    CNWItem& operator=(const CNWItem&);

    CNWItem();
    ~CNWItem();
};

void CNWItem__CNWItemCtor(CNWItem* thisPtr);
void CNWItem__CNWItemDtor__0(CNWItem* thisPtr);

}

}
